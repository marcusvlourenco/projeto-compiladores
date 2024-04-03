#include "./ast.h"
#include <llvm/IR/DerivedTypes.h>
#include "./symboltable.h"
#include <iostream>

using namespace AST;
using namespace std;
static void blank(int n) {
  for (int i = 0; i < n; i++) {
    cout << "___";
  }
}

llvm::Type *Root::traverse(vector<Var_dec *> &, CodeGenContext &context) {
  context.typeDecs.reset();                //**************************
  return root_->traverse(mainVariableTable_, context);
}

llvm::Type *AST::Var_field::traverse(vector<Var_dec *> &variableTable, CodeGenContext &context) {
  //
  auto var = var_->traverse(variableTable, context);
  if (!var) return nullptr;
  if (!context.isRecord(var))
    return context.logErrorT("field reference is only for struct type.");
  llvm::StructType *eleType = llvm::cast<llvm::StructType>(context.getElementType(var));

  auto ty_dec = dynamic_cast<Ty_record *>(context.typeDecs[eleType->getStructName()]);
  assert(ty_dec);
  idx_ = 0u;
  for (auto &ty_field : ty_dec->fields_)
    if (ty_field->getName() == field_)
      break;
    else
      ++idx_;
  type_ = ty_dec->fields_[idx_]->getType();
  return type_;
}

llvm::Type *AST::Var_subs::traverse(vector<Var_dec *> &variableTable, CodeGenContext &context) {
  auto var = var_->traverse(variableTable, context);
  if (!var) return nullptr;
  if (!var->isPointerTy() || context.getElementType(var)->isStructTy())
    return context.logErrorT("Subscript is only for array type.");
  // Ptr to element type
  type_ = context.getElementType(var);
  auto expre = exp_->traverse(variableTable, context);
  if (!expre) return nullptr;
  if (!expre->isIntegerTy())
    return context.logErrorT("Subscript should be integer");
  return type_;
}

llvm::Type *AST::VarExpre::traverse(vector<Var_dec *> &variableTable, CodeGenContext &context) {
  return var_->traverse(variableTable, context);
}

llvm::Type *AST::NilExpre::traverse(vector<Var_dec *> &, CodeGenContext &context) {
    return context.nilType;
}

llvm::Type *AST::IntExpre::traverse(vector<Var_dec *> &, CodeGenContext &context) {
  return context.intType;
}

llvm::Type *AST::StringExpre::traverse(vector<Var_dec *> &, CodeGenContext &context) {
  return context.stringType;
}


llvm::Type *CallExpre::traverse(vector<Var_dec *> &variableTable, CodeGenContext &context) {
  auto function = context.functions[func_];
  if (!function) return context.logErrorT("Function " + func_ + "undeclared");
  auto functionType = function->getFunctionType();
  size_t i = 0u;
  if (function->getLinkage() == llvm::Function::ExternalLinkage)
    i = 0u;
  else
    i = 1u;
  if (args_.size() != functionType->getNumParams() - i)
    return context.logErrorT("Incorrect # arguments passed");

  for (auto &expre : args_) {
    auto type = expre->traverse(variableTable, context);
    auto arg = functionType->getParamType(i++);
    if (arg != type) return context.logErrorT("Params type not match");
  }
  return function->getReturnType();
}

llvm::Type *BinaryExpre::traverse(vector<Var_dec *> &variableTable, CodeGenContext &context) {
  auto left = left_->traverse(variableTable, context);
  auto right = right_->traverse(variableTable, context);
  if (!left || !right) return nullptr;
  switch (this->op_) {
    case ADD:
    case SUB:
    case MUL:
    case DIV:
    case LTH:
    case GTH:
    case LEQ:
    case GEQ: {
      if (left->isIntegerTy() && right->isIntegerTy())
        return context.intType;
      else
        return context.logErrorT("Binary expression require integers");
    }
    case EQU:
    case NEQU: {
      if (context.isMatch(left, right)) {
        if (context.isNil(left) && context.isNil(right))
          return context.logErrorT("Nil cannot compaire to nil");
        else
          return context.intType;
      } else
        return context.logErrorT("Binary comparasion type not match");
    }
    default:
      return nullptr;
  }
  return nullptr;
}

llvm::Type *Ty_field::traverse(vector<Var_dec *> &variableTable, CodeGenContext &context) {
  type_ = context.typeOf(typeName_);
  varDec_ = new Var_dec(name_, type_, variableTable.size(), context.currentLevel);
  context.valueDecs.push(name_, varDec_);
  variableTable.push_back(varDec_);
  return type_;
}

llvm::Type *FieldExpre::traverse(vector<Var_dec *> &variableTable, CodeGenContext &context) {
  type_ = exp_->traverse(variableTable, context);
  return type_;
}

llvm::Type *RecordExpre::traverse(vector<Var_dec *> &variableTable, CodeGenContext &context) {
  type_ = context.typeOf(typeName_);
  if (!type_->isPointerTy()) return context.logErrorT("Require a struct type");
  auto eleType = context.getElementType(type_);
  if (!eleType->isStructTy()) return context.logErrorT("Require a struct type");
  auto ty_dec = dynamic_cast<Ty_record *>(context.typeDecs[typeName_]);
  assert(ty_dec);
  if (ty_dec->fields_.size() != fieldExps_.size())
    return context.logErrorT("Wrong number of fields");
  size_t idx = 0u;
  for (auto &fieldDec : ty_dec->fields_) {
    auto &ty_field = fieldExps_[idx];
    if (ty_field->getName() != fieldDec->getName())
      return context.logErrorT(
          ty_field->getName() +
          " is not a field or not on the right position of " + typeName_);
    auto expre = ty_field->traverse(variableTable, context);
    if (!context.isMatch(expre, fieldDec->getType()))
      return context.logErrorT("Field type not match");
    ++idx;
  }
  // CHECK NIL
  return type_;
}


llvm::Type *SeqExpre::traverse(vector<Var_dec *> &variableTable, CodeGenContext &context) {
  llvm::Type *last;
  for (auto &expre : exps_) {
    last = expre->traverse(variableTable, context);
  }
  return last;
}


llvm::Type *AssignExpre::traverse(vector<Var_dec *> &variableTable, CodeGenContext &context) {
  auto var = var_->traverse(variableTable, context);
  if (!var) return nullptr;
  auto expre = exp_->traverse(variableTable, context);
  if (!expre) return nullptr;
  if (context.isMatch(var, expre))
    return expre;
  else
    return context.logErrorT("Assign types do not match");
}

llvm::Type *IfExpre::traverse(vector<Var_dec *> &variableTable, CodeGenContext &context) {
  auto test = test_->traverse(variableTable, context);
  if (!test) return nullptr;
  auto then = then_->traverse(variableTable, context);
  if (!then) return nullptr;
  if (!test->isIntegerTy()) return context.logErrorT("Require integer in test");
  if (else_) {
    auto elsee = else_->traverse(variableTable, context);
    if (!elsee) return nullptr;
    if (!context.isMatch(then, elsee))
      return context.logErrorT("Require same type in both branch");
  } else {
    return context.voidType;
  }
  return then;
}

llvm::Type *WhileExpre::traverse(vector<Var_dec *> &variableTable, CodeGenContext &context) {
  auto test = test_->traverse(variableTable, context);
  if (!test) return nullptr;
  if (!test->isIntegerTy()) return context.logErrorT("Rquire integer");
  body_->traverse(variableTable, context);
  return context.voidType;
}

llvm::Type *ForExpre::traverse(vector<Var_dec *> &variableTable, CodeGenContext &context) {
  auto low = low_->traverse(variableTable, context);
  if (!low) return nullptr;
  auto high = high_->traverse(variableTable, context);
  if (!high) return nullptr;
  if (!low->isIntegerTy() || !high->isIntegerTy())
    return context.logErrorT("For bounds require integer");
  varDec_ = new Var_dec(var_, context.intType, variableTable.size(), context.currentLevel);
  variableTable.push_back(varDec_);
  context.valueDecs.push(var_, varDec_);
  auto body = body_->traverse(variableTable, context);
  if (!body) return nullptr;
  return context.voidType;
}

llvm::Type *SwitchExpre::traverse(vector<Var_dec *> &variableTable, CodeGenContext &context) {
  /*auto low = low_->traverse(variableTable, context);
  if (!low) return nullptr;
  auto high = high_->traverse(variableTable, context);
  if (!high) return nullptr;
  if (!low->isIntegerTy() || !high->isIntegerTy())
    return context.logErrorT("For bounds require integer");
  varDec_ = new Var_dec(var_, context.intType, variableTable.size(),
                       context.currentLevel);
  variableTable.push_back(varDec_);
  context.valueDecs.push(var_, varDec_);
  auto body = body_->traverse(variableTable, context);
  if (!body) return nullptr;
  return context.voidType;
}*/


llvm::Type *AST::BreakExpre::traverse(vector<Var_dec *> &, CodeGenContext &context) {
  return context.voidType;
}


llvm::Type *LetExpre::traverse(vector<Var_dec *> &variableTable, CodeGenContext &context) {
  context.types.enter();
  context.typeDecs.enter();
  context.valueDecs.enter();
  context.functions.enter();
  for (auto &dec : decs_) {
    dec->traverse(variableTable, context);
  }
  auto body = body_->traverse(variableTable, context);
  context.functions.exit();
  context.valueDecs.exit();
  context.types.exit();
  context.typeDecs.exit();
  return body;
}

llvm::Type *Ty_dec::traverse(vector<Var_dec *> &, CodeGenContext &context) {
  type_->setName(name_);
  context.typeDecs[name_] = type_.get();
  return context.voidType;
}

llvm::Type *ArrayExpre::traverse(vector<Var_dec *> &variableTable, CodeGenContext &context) {
  type_ = context.typeOf(typeName_);
  if (!type_) return nullptr;
  if (!type_->isPointerTy()) return context.logErrorT("Array type required");
  auto eleType = context.getElementType(type_);
  auto init = init_->traverse(variableTable, context);
  if (!init) return nullptr;
  auto size = size_->traverse(variableTable, context);
  if (!size) return nullptr;
  if (!size->isIntegerTy()) return context.logErrorT("Size should be integer");
  if (eleType != init) return context.logErrorT("Initial type not matches");
  return type_;
}



llvm::FunctionType *Prototype::traverse(vector<Var_dec *> &variableTable,
                                        CodeGenContext &context) {
  std::vector<llvm::Type *> args;
  auto linkType = llvm::PointerType::getUnqual(context.staticLink.front());
  args.push_back(linkType);
  frame = llvm::StructType::create(context.context, name_ + "Frame");
  staticLink_ = new Var_dec("staticLink", linkType, variableTable.size(),
                           context.currentLevel);
  variableTable.push_back(staticLink_);
  for (auto &ty_field : params_) {
    args.push_back(ty_field->traverse(variableTable, context));
    if (!args.back()) return nullptr;
  }
  if (result_.empty()) {
    resultType_ = llvm::Type::getVoidTy(context.context);
  } else {
    resultType_ = context.typeOf(result_);
  }
  if (!resultType_) return nullptr;
  auto functionType = llvm::FunctionType::get(resultType_, args, false);
  function_ =
      llvm::Function::Create(functionType, llvm::Function::InternalLinkage,
                             name_, context.module.get());
  return functionType;
}

llvm::Type *Fun_dec::traverse(vector<Var_dec *> &, CodeGenContext &context) {
  if (context.functions.lookupOne(name_))
    return context.logErrorT("Function " + name_ +
                             " is already defined in same scope.");
  context.valueDecs.enter();
  level_ = ++context.currentLevel;
  auto proto = proto_->traverse(variableTable_, context);
  if (!proto) return nullptr;
  context.staticLink.push_front(proto_->getFrame());
  context.functions.push(name_, proto_->getFunction());
  auto body = body_->traverse(variableTable_, context);
  context.staticLink.pop_front();
  if (!body) return nullptr;
  context.valueDecs.exit();
  --context.currentLevel;
  auto retType = proto_->getResultType();
  if (!retType->isVoidTy() && retType != body)
    return context.logErrorT("Function retrun type not match");
  return context.voidType;
}

llvm::Type *Var_simple::traverse(vector<Var_dec *> &, CodeGenContext &context) {
  // TODO: check
  auto type = context.valueDecs[name_];
  if (!type) return context.logErrorT(name_ + " is not defined");
  return type->getType();
}

llvm::Type *Var_dec::traverse(vector<Var_dec *> &variableTable,
                             CodeGenContext &context) {
  if (context.valueDecs.lookupOne(name_))
    return context.logErrorT(name_ + " is already defined in this function.");
  offset_ = variableTable.size();
  level_ = context.currentLevel;
  variableTable.push_back(this);
  auto init = init_->traverse(variableTable, context);
  if (typeName_.empty()) {
    type_ = init;
  } else {
    type_ = context.typeOf(typeName_);
    if (!context.isMatch(type_, init))
      return context.logErrorT("Type not match");
  }
  if (!type_) return nullptr;
  context.valueDecs.push(name_, this);
  return context.voidType;
}

llvm::Type *AST::Ty_array::traverse(std::set<std::string> &parentName,
                                     CodeGenContext &context) {
  if (context.types[name_]) return context.types[name_];
  if (parentName.find(name_) != parentName.end())
    return context.logErrorT(name_ + " has an endless loop of type define");
  parentName.insert(name_);
  auto type = context.typeOf(type_, parentName);
  parentName.erase(name_);
  if (!type) return nullptr;
  type = llvm::PointerType::getUnqual(type);
  context.types.push(name_, type);
  return type;
}

llvm::Type *AST::Ty_name::traverse(std::set<std::string> &parentName,
                                    CodeGenContext &context) {
  if (auto type = context.types[name_]) return type;
  if (auto type = context.types[type_]) {
    context.types.push(name_, type);
    return type;
  }
  if (parentName.find(name_) != parentName.end())
    return context.logErrorT(name_ + " has an endless loop of type define");
  parentName.insert(name_);
  auto type = context.typeOf(type_, parentName);
  parentName.erase(name_);
  return type;
}

llvm::Type *AST::Ty_record::traverse(std::set<std::string> &parentName,
                                      CodeGenContext &context) {
  if (context.types[name_]) return context.types[name_];
  std::vector<llvm::Type *> types;
  if (parentName.find(name_) != parentName.end()) {
    auto type = llvm::PointerType::getUnqual(
        llvm::StructType::create(context.context, name_));
    context.types.push(name_, type);
    return type;
  }
  parentName.insert(name_);
  for (auto &ty_field : fields_) {
    auto type = context.typeOf(ty_field->typeName_, parentName);
    if (!type) return nullptr;
    ty_field->type_ = type;
    types.push_back(type);
  }
  parentName.erase(name_);
  if (auto type = context.types[name_]) {
    if (!type->isPointerTy()) return nullptr;
    auto eleType = context.getElementType(type);
    if (!eleType->isStructTy()) return nullptr;
    llvm::cast<llvm::StructType>(eleType)->setBody(types);
    return type;
  } else {
    type = llvm::PointerType::getUnqual(
        llvm::StructType::create(context.context, types, name_));
    if (!type) return nullptr;
    context.types.push(name_, type);
    return type;
  }
}