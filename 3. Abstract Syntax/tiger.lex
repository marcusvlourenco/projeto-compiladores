/* Análisador  Léxico */

/*Declarações*/

/*includes*/
%{
#include <string>
#include <sstream>
#include "./ast.h"
#include <iostream>
#include <cstring>
#include <unistd.h>
using namespace AST;
//#include "tiger_yacc.h"



#define BUFSIZE 65535

std::stringstream strbuf;
char *strptr = NULL;
int 	nesting = 0;
int 	charPos=1;

int line = 1; 
int col = 0;


extern YYLTYPE yylloc;


extern "C" int yywrap(void)
{
 charPos=1;
 return 1;
}


/**/
void adjust(void)
{
	int k;

	yylloc.first_line = line;
	yylloc.first_column = col + 1;

	for( k = 0; yytext[k] != '\0'; k++){
		if (yytext[k] == '\n'){
		 	
		 	line++;
		 	col = 0;

		}

		else if ( yytext [k] == '\t'){

			col += 8 - (col % 8);
	
		}else 
			col ++;

	}

	yylloc.last_line = line;
	yylloc.last_column = col;
}






%}

/*Definição de grupos de expressões regulares*/
%x 	COMMENT
%x	STR



id     [a-zA-Z][a-zA-Z0-9_]*
digits [0-9]+




%%

"/*" {
	adjust();
	BEGIN(COMMENT);
	nesting++;
}

<COMMENT>
	{

		"/*" {
			adjust();
			nesting++;
		}
		"*/" {
			adjust();
			if ( --nesting == 0 )
				BEGIN(INITIAL);
		}
		[^\n] { 
			adjust();
		}
        (\n|\r\n)	{adjust(); }
		<<EOF>> {
			adjust();
			EM_error("comentário não terminado" );
		}
		. {
			adjust();
		}
	}

\" {
	adjust();
	BEGIN(STR);
}

<STR>
	{
	    \" {
			adjust();
			yylval.sval=new std::string(strbuf.str());
			strbuf.clear(); 
			strbuf.str(std::string());
			BEGIN(INITIAL);
			return STRING;
		}
		\n {
			adjust();
		}
		<<EOF>>	{ 
			adjust();
			std::cerr << "illegal token" << std::endl;
		}
		\\n {
			adjust();
			strbuf << "\n";;
		}
		\\t {
			adjust();
			strbuf << "\t";
		}
		\\\" {
			adjust();
			strbuf<<yytext;
		}
		\\[ \n\t\r\f]+\\ {
			adjust();
		}
		\\^[a-z]	{	
			adjust();
			strbuf << yytext;
		}
		\\{digits}{3} {
			adjust();
			strbuf<<yytext;
		}
		\\[\n\t ]+\\ {
			/* fazer nada */
		}
		\\(.|\n) {
			adjust();
			std::cerr << "illegal token" << std::endl;
		}
		(\n|\r\n) {
			adjust();
			std::cerr << "illegal token" << std::endl;
		}
		[^\"\\\n(\r\n)]+  {
			adjust();
			strbuf<<yytext;}
		}							
	}

(\n|\r\n)	{adjust(); continue;}
[ \t]+		{adjust(); continue;}
"array" 	{adjust(); return ARRAY; } 
"if" 	   	{adjust(); return IF; } 
"then" 		{adjust(); return THEN; } 
"else" 		{adjust(); return ELSE; } 
"do" 		{adjust(); return DO; }
"to" 		{adjust(); return TO; } 
"while" 	{adjust(); return WHILE; }
"for"  	 	{adjust(); return FOR;}
"let"  	 	{adjust(); return LET;}
"in"  	 	{adjust(); return IN;}
"end"  	 	{adjust(); return END;}
"break"   	{adjust(); return BREAK;}
"of"  	 	{adjust(); return OF;}
"nil"    	{adjust(); return NIL;}
"var"   	{adjust(); return VAR;}
"function"  {adjust(); return FUNCTION;}
"type"  	{adjust(); return TYPE;}
"id"  	 	{adjust(); return ID;}
"string" 	{adjust(); return STRING;}
"int" 	 	{adjust(); return INT;}
"switch"	{adjust(); return SWITCH; } 
"default"	{adjust(); return DEFAULT;}
"case"		{adjust(); return CASE;}




{digits} {
			
			adjust();

			
			yylval.ival = atoi(yytext);
			return INT;
}
{id}		{
			
			adjust(); 
			yylval.sval = new string(yytext); 
			return ID;
}

":="		{adjust(); return ASSIGN; }	
">="		{adjust(); return GE; }	
"<="		{adjust(); return LE; }	
"+"			{adjust(); return PLUS; }	
"-"			{adjust(); return MINUS; }	
"*"			{adjust(); return TIMES; }
"/"			{adjust(); return DIVIDE; }
"="			{adjust(); return EQ; }
"("			{adjust(); return LPAREN; }
")"			{adjust(); return RPAREN; }
"["			{adjust(); return LBRACK; }
"]"			{adjust(); return RBRACK; }
"<>"		{adjust(); return NEQ; }
"<"			{adjust(); return LT; }
">"			{adjust(); return GT; }
"{"			{adjust(); return LBRACE; }
"}"			{adjust(); return RBRACE; }
";"			{adjust(); return SEMICOLON; }
":"			{adjust(); return COLON; }
"."			{adjust(); return DOT; }
"&"			{adjust(); return AND; }
"|"			{adjust(); return OR; }
","	 		{adjust(); return COMMA;}

. {
	adjust();
	std::cerr << "illegal token" << std::endl;
}	

%%
