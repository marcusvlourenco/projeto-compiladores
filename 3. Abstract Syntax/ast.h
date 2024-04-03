#ifndef AST_H
#define AST_H

//#include <llvm/IR/Function.h>
//#include <llvm/IR/Value.h>
#include "./codegencontext.h"
#include <algorithm>
#include <memory>
#include <set>
#include <string>
#include <vector>

class CodeGenContext;
namespace AST {
using llvm::Value;
using std::move;
using std::reverse;
using std::set;
using std::string;
using std::unique_ptr;
using std::vector;

class Var_dec;

class Node {
  size_t pos_;

 public:
  virtual ~Node() = default;
  virtual Value *codegen(CodeGenContext &context) = 0;
  void setPos(const size_t &pos) { pos_ = pos; }

  virtual llvm::Type *traverse(vector<Var_dec *> &, CodeGenContext &) = 0;
};

class Var : public Node {
};

class Expre : public Node {
};

class Root : public Node {
  unique_ptr<Expre> root_;
  vector<Var_dec *> mainVariableTable_;


 public:
  Root(unique_ptr<Expre> root) : root_(move(root)) {}
  Value *codegen(CodeGenContext &context) override;
  llvm::Type *traverse(vector<Var_dec *> &variableTable,
                       CodeGenContext &context) override;
};

class Dec : public Node {
 protected:
  string name_;

 public:
  Dec(string name) : name_(move(name)) {}
};

class Type {
 protected:
  string name_;

 public:
  Type() = default;
  void setName(string name) { name_ = move(name); }
  const string &getName() const { return name_; }
  virtual ~Type() = default;
  virtual llvm::Type *traverse(std::set<string> &parentName,
                               CodeGenContext &context) = 0;
};

class Var_simple : public Var {
  string name_;

 public:
  Var_simple(string name) : name_(move(name)) {}
  Value *codegen(CodeGenContext &context) override;
  llvm::Type *traverse(vector<Var_dec *> &variableTable,
                       CodeGenContext &context) override;
};

class Var_field : public Var {
  unique_ptr<Var> var_;
  string field_;
  llvm::Type *type_{nullptr};
  size_t idx_{0u};

 public:
  Var_field(unique_ptr<Var> var, string ty_field)
      : var_(move(var)), field_(move(ty_field)) {}
  Value *codegen(CodeGenContext &context) override;

  llvm::Type *traverse(vector<Var_dec *> &variableTable,
                       CodeGenContext &context) override;
};

class Var_subs : public Var {
  unique_ptr<Var> var_;
  unique_ptr<Expre> exp_;
  llvm::Type *type_{nullptr};

 public:
  Var_subs(unique_ptr<Var> var, unique_ptr<Expre> Expre)
      : var_(move(var)), exp_(move(Expre)) {}
  Value *codegen(CodeGenContext &context) override;

  llvm::Type *traverse(vector<Var_dec *> &variableTable,
                       CodeGenContext &context) override;
};

class VarExpre : public Expre {
  unique_ptr<Var> var_;

 public:
  VarExpre(unique_ptr<Var> var) : var_(move(var)) {}
  Value *codegen(CodeGenContext &context) override;

  llvm::Type *traverse(vector<Var_dec *> &variableTable,
                       CodeGenContext &context) override;
};

class NilExpre : public Expre {
  // dummy body
  llvm::Type *type_{nullptr};
 public:
  NilExpre() = default;
  Value *codegen(CodeGenContext &context) override;

  llvm::Type *traverse(vector<Var_dec *> &variableTable,
                       CodeGenContext &context) override;

  void setType(llvm::Type* type){type_ = type;}
};

class IntExpre : public Expre {
  int val_;

 public:
  IntExpre(int const &val) : val_(val) {}
  Value *codegen(CodeGenContext &context) override;

  llvm::Type *traverse(vector<Var_dec *> &variableTable,
                       CodeGenContext &context) override;
};

class StringExpre : public Expre {
  string val_;

 public:
  StringExpre(string val) : val_(move(val)) {}
  Value *codegen(CodeGenContext &context) override;

  llvm::Type *traverse(vector<Var_dec *> &variableTable,
                       CodeGenContext &context) override;
};

class CallExpre : public Expre {
  string func_;
  vector<unique_ptr<Expre>> args_;

 public:
  CallExpre(string func, vector<unique_ptr<Expre>> args)
      : func_(move(func)), args_(move(args)) {
    reverse(args_.begin(), args_.end());
  }
  Value *codegen(CodeGenContext &context) override;

  llvm::Type *traverse(vector<Var_dec *> &variableTable,
                       CodeGenContext &context) override;
};

// TODO: UnaryExp

class BinaryExpre : public Expre {
 public:
  enum Operator : char {
    ADD = '+',
    SUB = '-',
    MUL = '*',
    DIV = '/',
    LTH = '<',
    GTH = '>',
    EQU = '=',
    NEQU = '!',
    LEQ = '[',
    GEQ = ']',

    AND_ = '&',
    OR_ = '|',
    //    AND = '&',
    //    OR = '|',
    XOR = '^',
  };

 private:
  Operator op_;  // TODO: use enum
  unique_ptr<Expre> left_;
  unique_ptr<Expre> right_;

 public:
  BinaryExpre(Operator const &op, unique_ptr<Expre> left, unique_ptr<Expre> right)
      : op_(op), left_(move(left)), right_(move(right)) {}
  Value *codegen(CodeGenContext &context) override;

  llvm::Type *traverse(vector<Var_dec *> &variableTable,
                       CodeGenContext &context) override;
};

class Ty_field {
  friend class Ty_record;

  string name_;
  string typeName_;
  llvm::Type *type_{nullptr};
  Var_dec *varDec_{nullptr};

 public:
  Ty_field(string name, string type) : name_(move(name)), typeName_(move(type)) {}

  llvm::Type *traverse(vector<Var_dec *> &variableTable,
                       CodeGenContext &context);
  llvm::Type *getType() const { return type_; }
  const string &getName() const { return name_; }
  Var_dec *getVar() const { return varDec_; }
};

class FieldExpre : public Expre {
  friend class RecordExpre;
  string name_;
  unique_ptr<Expre> exp_;
  llvm::Type *type_;

 public:
  FieldExpre(string name, unique_ptr<Expre> Expre)
      : name_(move(name)), exp_(move(Expre)) {}

  const string &getName() const { return name_; }

  Value *codegen(CodeGenContext &context) override;

  llvm::Type *traverse(vector<Var_dec *> &variableTable,
                       CodeGenContext &context) override;
};

class RecordExpre : public Expre {
  friend class Ty_record;
  string typeName_;
  vector<unique_ptr<FieldExpre>> fieldExps_;
  llvm::Type *type_{nullptr};

 public:
  RecordExpre(string type, vector<unique_ptr<FieldExpre>> fieldExps)
      : typeName_(move(type)), fieldExps_(move(fieldExps)) {
    reverse(fieldExps_.begin(), fieldExps_.end());
  }
  Value *codegen(CodeGenContext &context) override;

  llvm::Type *traverse(vector<Var_dec *> &variableTable,
                       CodeGenContext &context) override;
};

class SeqExpre : public Expre {
  vector<unique_ptr<Expre>> exps_;

 public:
  SeqExpre(vector<unique_ptr<Expre>> exps) : exps_(move(exps)) {
    reverse(exps_.begin(), exps_.end());
  }
  Value *codegen(CodeGenContext &context) override;

  llvm::Type *traverse(vector<Var_dec *> &variableTable,
                       CodeGenContext &context) override;
};

class AssignExpre : public Expre {
  unique_ptr<Var> var_;
  unique_ptr<Expre> exp_;

 public:
  AssignExpre(unique_ptr<Var> var, unique_ptr<Expre> Expre)
      : var_(move(var)), exp_(move(Expre)) {}
  Value *codegen(CodeGenContext &context) override;

  llvm::Type *traverse(vector<Var_dec *> &variableTable,
                       CodeGenContext &context) override;
};

class IfExpre : public Expre {
  unique_ptr<Expre> test_;
  unique_ptr<Expre> then_;
  unique_ptr<Expre> else_;

 public:
  IfExpre(unique_ptr<Expre> test, unique_ptr<Expre> then, unique_ptr<Expre> elsee)
      : test_(move(test)), then_(move(then)), else_(move(elsee)) {}
  Value *codegen(CodeGenContext &context) override;

  llvm::Type *traverse(vector<Var_dec *> &variableTable,
                       CodeGenContext &context) override;
};

class WhileExpre : public Expre {
  unique_ptr<Expre> test_;
  unique_ptr<Expre> body_;

 public:
  WhileExpre(unique_ptr<Expre> test, unique_ptr<Expre> body)
      : test_(move(test)), body_(move(body)) {}
  Value *codegen(CodeGenContext &context) override;

  llvm::Type *traverse(vector<Var_dec *> &variableTable,
                       CodeGenContext &context) override;
};

class ForExpre : public Expre {
  string var_;
  unique_ptr<Expre> low_;
  unique_ptr<Expre> high_;
  unique_ptr<Expre> body_;
  // bool escape;
  Var_dec *varDec_{nullptr};

 public:
  ForExpre(string var, unique_ptr<Expre> low, unique_ptr<Expre> high,
         unique_ptr<Expre> body)
      : var_(move(var)),
        low_(move(low)),
        high_(move(high)),
        body_(move(body)) {}
  Value *codegen(CodeGenContext &context) override;

  llvm::Type *traverse(vector<Var_dec *> &variableTable,
                       CodeGenContext &context) override;
};

class BreakExpre : public Expre {
  // dummpy body
 public:
  BreakExpre() = default;
  Value *codegen(CodeGenContext &context) override;
  llvm::Type *traverse(vector<Var_dec *> &variableTable,
                       CodeGenContext &context) override;

};

class LetExpre : public Expre {
  vector<unique_ptr<Dec>> decs_;
  unique_ptr<Expre> body_;

 public:
  LetExpre(vector<unique_ptr<Dec>> decs, unique_ptr<Expre> body)
      : decs_(move(decs)), body_(move(body)) {
    reverse(decs_.begin(), decs_.end());
  }
  Value *codegen(CodeGenContext &context) override;

  llvm::Type *traverse(vector<Var_dec *> &variableTable,
                       CodeGenContext &context) override;
};

class ArrayExpre : public Expre {
  string typeName_;
  unique_ptr<Expre> size_;
  unique_ptr<Expre> init_;
  llvm::Type *type_{nullptr};

 public:
  ArrayExpre(string type, unique_ptr<Expre> size, unique_ptr<Expre> init)
      : typeName_(move(type)), size_(move(size)), init_(move(init)) {}
  Value *codegen(CodeGenContext &context) override;

  llvm::Type *traverse(vector<Var_dec *> &variableTable,
                       CodeGenContext &context) override;
};

class Prototype {
  string name_;
  vector<unique_ptr<Ty_field>> params_;
  string result_;
  llvm::Type *resultType_{nullptr};
  llvm::Function *function_{nullptr};
  Var_dec *staticLink_{nullptr};
  llvm::StructType *frame{nullptr};

 public:
  Prototype(string name, vector<unique_ptr<Ty_field>> params, string result)
      : name_(move(name)), params_(move(params)), result_(move(result)) {
    reverse(params_.begin(), params_.end());
  }
  llvm::Function *codegen(CodeGenContext &context);

  const string &getName() const { return name_; }

  void rename(string name) { name_ = move(name); }

  const vector<unique_ptr<Ty_field>> &getParams() const { return params_; }

  llvm::Type *getResultType() const { return resultType_; }

  llvm::FunctionType *traverse(vector<Var_dec *> &variableTable,
                               CodeGenContext &context);
  llvm::StructType *getFrame() const { return frame; }

  llvm::Function *getFunction() const { return function_; }
  Var_dec *getStaticLink() const { return staticLink_; }
};

class Fun_dec : public Dec {
  unique_ptr<Prototype> proto_;
  unique_ptr<Expre> body_;
  vector<Var_dec *> variableTable_;
  size_t level_{0u};

 public:
  Fun_dec(string name, unique_ptr<Prototype> proto, unique_ptr<Expre> body)
      : Dec(move(name)), proto_(move(proto)), body_(move(body)) {}
  Value *codegen(CodeGenContext &context) override;

  llvm::Type *traverse(vector<Var_dec *> &variableTable,
                       CodeGenContext &context) override;
  Prototype &getProto() const { return *proto_; }
  size_t getLevel() const { return level_; }
};

class Var_dec : public Dec {
  string typeName_;
  unique_ptr<Expre> init_{nullptr};
  // bool escape;
  size_t offset_;
  size_t level_;
  llvm::Type *type_{nullptr};

 public:
  Var_dec(string name, string type, unique_ptr<Expre> init)
      : Dec(move(name)), typeName_(move(type)), init_(move(init)) {}
  Var_dec(string name, llvm::Type *type, size_t const &offset,
         size_t const &level)
      : Dec(move(name)), offset_(offset), level_(level), type_(type) {}
  Value *codegen(CodeGenContext &context) override;

  llvm::Type *getType() const { return type_; }
  const string &getName() const { return name_; }

  llvm::Value *read(CodeGenContext &context) const;
  llvm::Type *traverse(vector<Var_dec *> &variableTable,
                       CodeGenContext &context) override;
};

class Ty_dec : public Dec {
  unique_ptr<Type> type_;

 public:
  Ty_dec(string name, unique_ptr<Type> type)
      : Dec(move(name)), type_(move(type)) {}
  Value *codegen(CodeGenContext &context) override;

  llvm::Type *traverse(vector<Var_dec *> &variableTable,
                       CodeGenContext &context) override;
};

class Ty_name : public Type {
  string type_;

 public:
  llvm::Type *traverse(std::set<string> &parentName,
                       CodeGenContext &context) override;
  Ty_name(string type) : type_(move(type)) {}
};

class Ty_record : public Type {
  friend class RecordExpre;
  friend class Var_field;
  vector<unique_ptr<Ty_field>> fields_;

 public:
  Ty_record(vector<unique_ptr<Ty_field>> fields) : fields_(move(fields)) {
    reverse(fields_.begin(), fields_.end());
  }
  llvm::Type *traverse(std::set<string> &parentName,
                       CodeGenContext &context) override;
};

class Ty_array : public Type {
  string type_;

 protected:
 public:
  Ty_array(string type) : type_(move(type)) {}
  llvm::Type *traverse(std::set<string> &parentName,
                       CodeGenContext &context) override;
};

}  // namespace AST

#endif  // AST_H
