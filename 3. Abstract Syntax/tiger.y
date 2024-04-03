%{
	/*
#include <string>
#include <stdio>
#include "errormsg.h"
#include "util.h"*/

#include <iostream>
#include <ast.h>
#include <llvm/ADT/STLExtras.h>
using namespace AST;

int yylex( void);


std::unique_ptr<Root> root;

void tigererror(char *s)
{
  std::cerr<<s<<std::endl;
}




%}




%union {
	
	int 											ival;
	std::string 									*sval;
  	Var 											*var;
  	Expre 											*expre;
  	Dec 											*dec;
  	Root 											*root;
  	Fun_dec 										*fun_dec;
  	Type 											*ty;
  	Ty_field 										*ty_field;
  	FieldExpre 										*fieldExpre;
  	Ty_dec 											*ty_dec;

	std::vector<std::unique_ptr<Expre>>				*expre_list;
	std::vector<std::unique_ptr<Dec>>				*dec_list;
	std::vector<std::unique_ptr<Ty_field>>			*ty_field_list;
	std::vector<std::unique_ptr<FieldExpre>>		*field_expre_list;
  	std::vector<std::unique_ptr<Ty_name>> 			*ty_name_List;


	}
	
%token <sval>	ID STRING
%token <ival>	INT


%token COMMA COLON SEMICOLON LPAREN RPAREN LBRACK RBRACK LBRACE RBRACE DOT PLUS MINUS TIMES DIVIDE
%token EQ NEQ LT LE GT GE AND OR ASSIGN ARRAY IF THEN ELSE WHILE FOR TO DO LET IN END OF BREAK NIL
%token FUNCTION VAR TYPE SWITCH CASE DEFAULT




%type <sval> 				id  
%type <var>					lvalue 
%type <ty> 					ty
%type <root> 				root
%type <expre>				program expre var_swi op_swi ops_swi
%type <expre>				expre_opera expre_compa expre_let 
%type <expre>				expre_if expre_while expre_for expre_switch
%type <dec> 				dec var_dec
%type <ty_field> 			ty_field 
%type <fun_dec> 			fun_dec
%type <ty_dec> 				ty_dec
%type <expre_list> 			arg_list expre_list 
%type <dec_list> 			dec_list 
%type <ty_field_list> 		ty_field_list
%type <field_expre_list>	fieldExpre




%nonassoc ASSIGN LBRACK ELSE OF COMMA THEN DO TYPE FUNCTION 
%nonassoc EQ NEQ LE LT GT GE ID WHILE FOR TO SWITCH IF
%left TIMES DIVIDE UMINUS PLUS MINUS AND OR DOT


%start program
//%define parse.error verbose

%%
program: 		root								{root = std::unique_ptr<Root>($1);}


root: 												{$$ = NULL;}
			|	expre								{$$ = new Root(std::unique_ptr<Expre>(@1.first_line, @1.first_comumn, $1));};


expre:	    	INT      							{$$ = new IntExpre(@1.first_line, @1.first_column, $1);}
    		|   STRING    		 					{$$ = new StringExpre(@1.first_line, @1.first_column, *$1); delete $1}
    		|   NIL			       					{$$ = new NilExpre(@1.first_line, @1.first_column);}
    		|   BREAK     							{$$ = new BreakExpre(@1.first_line, @1.first_column);}
			|	LPAREN expre_list RPAREN      	    {$$ = new SeqExpre(std::move(@1.first_line, @1.first_column, *$2));}
			|	lvalue     							{$$ = new VarExpre(std::unique_ptr<Var>(@1.first_line, @1.first_column, $1));}
			| 	lvalue ASSIGN expre                 {$$ = new AssignExpre(std::unique_ptr<Var>(@1.first_line, @1.first_column, $1), std::unique_ptr<Expre>(@1.first_line, @1.first_column, $3));}
    		|   id LPAREN arg_list RPAREN    		{$$ = new CallExpre(@1.first_line, @1.first_column, *$1), std::move(@1.first_line, @1.first_column, *$3))); delete $1;}
			|	id LBRACE fieldExpre RBRACE 		{$$ = new RecordExpre((@1.first_line, @1.first_column, *$1), std::move((@1.first_line, @1.first_column, *$3))); delete $1;}
    		|   id LBRACK expre RBRACK OF expre		{$$ = new ArrayExpre((@1.first_line, @1.first_column, *$1), std::unique_ptr<Expre>(@1.first_line, @1.first_column, $3), std::unique_ptr<Expre>(@1.first_line, @1.first_column, $6)); delete $1;}
			| 	expre AND expre       				{$$ = new IfExpre(std::unique_ptr<Expre>(@1.first_line, @1.first_column, $1), std::unique_ptr<Expre>(@1.first_line, @1.first_column, $3), std::unique_ptr<Expre>(new IntExpre(0)));}		
			| 	expre OR expre       				{$$ = new IfExpre(std::unique_ptr<Expre>(@1.first_line, @1.first_column, $1), std::unique_ptr<Expre>(new IntExpre(1)), std::unique_ptr<Expre>(@1.first_line, @1.first_column, $3));}
    		|   expre_opera      					{$$ = $1;}
    		|   expre_compa      					{$$ = $1;}
    		|   expre_if       						{$$ = $1;}
    		|   expre_for    						{$$ = $1;}
    		|   expre_while      					{$$ = $1;}
    		|   expre_switch     					{$$ = $1;}
    		|   expre_let      						{$$ = $1;};		

id:             ID									{$$ = $1;};				

expre_opera:	expre PLUS expre 					{$$ = new BinaryExpre(BinaryExpre::ADD, std::unique_ptr<Expre>(@1.first_line, @1.first_column, $1), std::unique_ptr<Expre>(@1.first_line, @1.first_column, $3));}
    		| 	expre MINUS expre					{$$ = new BinaryExpre(BinaryExpre::SUB, std::unique_ptr<Expre>(@1.first_line, @1.first_column, $1), std::unique_ptr<Expre>(@1.first_line, @1.first_column, $3));}
    		|   MINUS expre %prec UMINUS 			{$$ = new BinaryExpre(BinaryExpre::SUB, std::unique_ptr<Expre>(new IntExpre(@1.first_line, @1.first_column, 0)), std::unique_ptr<Expre>(@1.first_line, @1.first_column, $2));}
    		|   expre TIMES expre 					{$$ = new BinaryExpre(BinaryExpre::MUL, std::unique_ptr<Expre>(@1.first_line, @1.first_column, $1), std::unique_ptr<Expre>(@1.first_line, @1.first_column, $3));}
    		|   expre DIVIDE expre 					{$$ = new BinaryExpre(BinaryExpre::DIV, std::unique_ptr<Expre>(@1.first_line, @1.first_column, $1), std::unique_ptr<Expre>(@1.first_line, @1.first_column, $3));};

expre_compa:	expre LT expre 						{$$ = new BinaryExpre(BinaryExpre::LTH, std::unique_ptr<Expre>(@1.first_line, @1.first_column, $1), std::unique_ptr<Expre>(@1.first_line, @1.first_column, $3));}
    		|   expre LE expre 						{$$ = new BinaryExpre(BinaryExpre::LEQ, std::unique_ptr<Expre>(@1.first_line, @1.first_column, $1), std::unique_ptr<Expre>(@1.first_line, @1.first_column, $3));}
    		|   expre GT expre 						{$$ = new BinaryExpre(BinaryExpre::GTH, std::unique_ptr<Expre>(@1.first_line, @1.first_column, $1), std::unique_ptr<Expre>(@1.first_line, @1.first_column, $3));}
    		|   expre GE expre 						{$$ = new BinaryExpre(BinaryExpre::GEQ, std::unique_ptr<Expre>(@1.first_line, @1.first_column, $1), std::unique_ptr<Expre>(@1.first_line, @1.first_column, $3));}
    		|   expre EQ expre 						{$$ = new BinaryExpre(BinaryExpre::EQU, std::unique_ptr<Expre>(@1.first_line, @1.first_column, $1), std::unique_ptr<Expre>(@1.first_line, @1.first_column, $3));}
    		|   expre NEQ expre 					{$$ = new BinaryExpre(BinaryExpre::NEQU, std::unique_ptr<Expre>(@1.first_line, @1.first_column, $1), std::unique_ptr<Expre>(@1.first_line, @1.first_column, $3));};

arg_list:    										{$$ = new std::vector<std::unique_ptr<Expre>>();}
			|	expre                   			{$$ = new std::vector<std::unique_ptr<Expre>>(); $$->push_back(std::unique_ptr<Expre>(@1.first_line, @1.first_column, $1));}
    		|   expre COMMA arg_list     			{$$ = (@1.first_line, @1.first_column, $3); $3->push_back(std::unique_ptr<Expre>(@1.first_line, @1.first_column, $1));};

lvalue:     	id                       			{$$ = new Var_simple(@1.first_line, @1.first_column, *$1); delete $1;}
            | 	id LBRACK expre RBRACK 				{$$ = new Var_subs(llvm::make_unique<Var_simple>(@1.first_line, @1.first_column, *$1), std::unique_ptr<Expre>(@1.first_line, @1.first_column, $3)); delete $1;}
    		|   lvalue DOT id             			{$$ = new Var_field(std::unique_ptr<Var>(@1.first_line, @1.first_column, $1), (@1.first_line, @1.first_column, $3)); delete $3;}
    		|   lvalue LBRACK expre RBRACK     		{$$ = new Var_subs(std::unique_ptr<Var>(@1.first_line, @1.first_column, $1), std::unique_ptr<Expre>(@1.first_line, @1.first_column, $3));};


fieldExpre: 										{$$ = new std::vector<std::unique_ptr<FieldExpre>>();}
			|	id EQ expre              			{$$ = new std::vector<std::unique_ptr<FieldExpre>>(); $$->push_back(llvm::make_unique<FieldExpre>(*$1, std::unique_ptr<Expre>(@1.first_line, @1.first_column, $3))); delete $1;}
    		|	id EQ expre COMMA fieldExpre 		{$$ = (@1.first_line, @1.first_column, $5); $5->push_back(llvm::make_unique<FieldExpre>((@1.first_line, @1.first_column, *$1), std::unique_ptr<Expre>(@1.first_line, @1.first_column, $3))); delete $1;};


expre_list: 										{$$ = new std::vector<std::unique_ptr<Expre>>();}
			|	expre   	                		{$$ = new std::vector<std::unique_ptr<Expre>>(); $$->push_back(std::unique_ptr<Expre>(@1.first_line, @1.first_column, $1));}
    		| 	expre SEMICOLON expre_list			{$$ = (@1.first_line, @1.first_column, $3); $3->push_back(std::unique_ptr<Expre>(@1.first_line, @1.first_column, $1));};

expre_if:    	IF expre THEN expre  				{$$ = new IfExpre(std::unique_ptr<Expre>(@1.first_line, @1.first_column, $2), std::unique_ptr<Expre>(@1.first_line, @1.first_column, $4), NULL);};
			|	expre_if ELSE expre					{$$ = new IfExpre(std::unique_ptr<Expre>(@1.first_line, @1.first_column, $1), std::unique_ptr<Expre>(@1.first_line, @1.first_column, $3));}

expre_for:  	FOR id ASSIGN expre TO expre DO expre {$$ = new ForExpre((@1.first_line, @1.first_column, *$2), std::unique_ptr<Expre>(@1.first_line, @1.first_column, $4), std::unique_ptr<Expre>(@1.first_line, @1.first_column, $6), std::unique_ptr<Expre>(@1.first_line, @1.first_column, $8)); delete $2;};

expre_while: 	WHILE expre DO expre 				{$$ = new WhileExpre(std::unique_ptr<Expre>(@1.first_line, @1.first_column, $2), std::unique_ptr<Expre>(@1.first_line, @1.first_column, $4));};

expre_switch: 	SWITCH op_swi 						{$$ = new SwitchExpre(std::unique_ptr<Expre>(@1.first_line, @1.first_column, $2));};

op_swi:			LPAREN var_swi RPAREN LBRACE ops_swi RBRACE {$$ = new SwitchExpre(std::unique_ptr<Expre>(@1.first_line, @1.first_column, $2), std::unique_ptr<Expre>(@1.first_line, @1.first_column, $5));};

var_swi:		INT									{$$ = new SwitchExpre(std::unique_ptr<Expre>(@1.first_line, @1.first_column, $1));}
			|	STRING								{$$ = new SwitchExpre(std::unique_ptr<Expre>(@1.first_line, @1.first_column, $1));};

ops_swi:		CASE var_swi COLON expre BREAK COLON {$$ = new SwitchExpre(std::unique_ptr<Expre>(@1.first_line, @1.first_column, $2), std::unique_ptr<Expre>(@1.first_line, @1.first_column, $4));}
			|	DEFAULT COLON expre SEMICOLON		{$$ = new SwitchExpre(std::unique_ptr<Expre>(@1.first_line, @1.first_column, $3));};

expre_let:		LET dec_list IN expre_list END 		{$$ = new LetExpre(std::move(@1.first_line, @1.first_column, *$2), llvm::make_unique<SeqExpre>(std::move(@1.first_line, @1.first_column, *$4)));};

dec_list:    										{$$ = new std::vector<std::unique_ptr<Dec>>();}
			|	dec dec_list       					{$$ = (@1.first_line, @1.first_column, $2); $2->push_back(std::unique_ptr<Dec>(@1.first_line, @1.first_column, $1));};

dec:        	fun_dec    							{$$ = new $1;}
    		|  	var_dec          					{$$ = new $1;}
    		|  	ty_dec		         				{$$ = new $1;};


fun_dec:     	FUNCTION id LPAREN ty_field_list RPAREN EQ expre {$$ = new Fun_dec((@1.first_line, @1.first_column, *$2), llvm::make_unique<Prototype>((@1.first_line, @1.first_column, *$2), std::move(@1.first_line, @1.first_column, *$4), ""), std::unique_ptr<Expre>(@1.first_line, @1.first_column, $7)); delete $2;}
    		|  	FUNCTION id LPAREN ty_field_list RPAREN COLON id EQ expre {$$ = new Fun_dec((@1.first_line, @1.first_column, *$2), llvm::make_unique<Prototype>((@1.first_line, @1.first_column, *$2), std::move(@1.first_line, @1.first_column, *$4), (@1.first_line, @1.first_column, *$7)), std::unique_ptr<Expre>(@1.first_line, @1.first_column, $9)); delete $2;};

ty_field_list:  									{$$ = new std::vector<std::unique_ptr<Ty_field>>();}
			|	ty_field           					{$$ = new std::vector<std::unique_ptr<Ty_field>>(); $$->push_back(std::unique_ptr<Ty_field>(@1.first_line, @1.first_column, $1));}
    		|  	ty_field COMMA ty_field_list		{$$ = (@1.first_line, @1.first_column, $3); $3->push_back(std::unique_ptr<Ty_field>(@1.first_line, @1.first_column, $1));};

ty_field:      	id COLON id   						{$$ = new Ty_field((@1.first_line, @1.first_column, *$1), (@1.first_line, @1.first_column, *$3)); delete $1; delete $3;};

var_dec:     	VAR id ASSIGN expre        			{$$ = new Var_dec((@1.first_line, @1.first_column, *$2), "", std::unique_ptr<Expre>(@1.first_line, @1.first_column, $4)); delete $2;}
    		|   VAR id COLON id ASSIGN expre 		{$$ = new Var_dec((@1.first_line, @1.first_column, *$2), (@1.first_line, @1.first_column, *$4), std::unique_ptr<Expre>(@1.first_line, @1.first_column, $6)); delete $2; delete $4;};

ty_dec:   	 	TYPE id EQ ty 						{$$ = new Ty_dec((@1.first_line, @1.first_column, *$2), std::unique_ptr<Type>(@1.first_line, @1.first_column, $4)); delete $2;};

ty:         	id     								{$$ = new Ty_name(@1.first_line, @1.first_column, *$1); delete $1;}
    		| 	LBRACE ty_field_list RBRACE   		{$$ = new Ty_record(std::move(@1.first_line, @1.first_column, *$2));}
    		|   ARRAY OF id   						{$$ = new Ty_array(@1.first_line, @1.first_column, *$3); delete $3;};



%%
