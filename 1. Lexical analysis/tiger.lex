/* Análisador  Léxico */

/*Declarações*/

/*includes*/
%{
#include <string.h>
#include "util.h"
#include "y.tab.h"
/*#include "tokens.h"*/
#include "errormsg.h"


#define str_max  512


char 	string_buf[str_max];
char * 	string_buf_ptr;
int 	nesting = 0;
int 	charPos=0;

int line = 1; 
int col = 0;

/*estrutura para gerenciamento dos tokens*/
extern YYLTYPE yylloc;


int yywrap(void)
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
	EM_tokPos=charPos;
 	charPos+=yyleng;
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
	nesting = 1;
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
		\n  { 
			adjust();
		}
		<<EOF>> {
			adjust();
			EM_error(EM_tokPos, "comentário não terminado" );
		}
		. {
			adjust();
		}
	}

\" {
	adjust();
	BEGIN(STR);
	string_buf_ptr = string_buf;
}

<STR>
	{
	    \" {
			char * p;

			BEGIN(INITIAL);
			*string_buf_ptr = '\0';

			p = malloc( ( strlen( string_buf ) + 1 ) * sizeof( char ) );
			strcpy( p, string_buf );
			yylval.sval = p;

			adjust();

			return STRING;
		}
		\n {
			adjust();
			EM_error(EM_tokPos, "string constante indeterminada" ); 
		}
		<<EOF>>	{ 
			adjust();
			EM_error(EM_tokPos, "string constante indeterminada!" );
		}
		\\n {
			*string_buf_ptr++ = '\n';
		}
		\\t {
			*string_buf_ptr++ = '\t';
		}
		\\\" {
			*string_buf_ptr++ = '"';
		}
		\\\\ {
			*string_buf_ptr++ = '\\';
		}
		\\[a-z]	{	
			if ( strchr( "abcdefghijklmnopqrstuvwxyz", yytext[2] ) ){
				*string_buf_ptr++ = (yytext[2] - 'a' + 1 );
			}else{
				EM_error(EM_tokPos, "Saída ilegal" );
			}
		}
		\\{digits}{3} {
			int i = atoi( &yytext[1] );
			if ( i > 255 )
				EM_error(EM_tokPos, "Saída ilegal!" );
			*string_buf_ptr++ = (char)i;
		}
		\\[\n\t ]+\\ {
			/* fazer nada */
		}
		\\. {
			adjust();
			EM_error(EM_tokPos, "Saída ilegal." );
		}
		[\\\n\"]+ {
				char * p = yytext;
				while (*p)
					*string_buf_ptr++ = *p++;
		}						
	}

\n	 		{adjust(); }
[ \t]+		{adjust(); }
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
			yylval.sval = String(yytext); 
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


.	 		{adjust(); EM_error(EM_tokPos,"Token desconhecido!!!");}

%%
