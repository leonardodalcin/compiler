%{

#include<stdio.h>
#include<stdlib.h>
#include "scanner.h"
#include "hash.h"


extern FILE *yyin;
%}

%token KW_CHAR
%token KW_INT
%token KW_FLOAT
%token KW_IF
%token KW_THEN
%token KW_ELSE
%token KW_WHILE
%token KW_FOR
%token KW_TO
%token KW_READ
%token KW_RETURN
%token KW_PRINT

%token OPERATOR_LE
%token OPERATOR_GE
%token OPERATOR_EQ
%token OPERATOR_NE
%token OPERATOR_AND
%token OPERATOR_OR

%token TK_IDENTIFIER
%token LIT_INTEGER
%token LIT_REAL
%token LIT_CHAR
%token LIT_STRING
%token TOKEN_ERROR


%union
{
	struct hash_node *symbol;
}
%%

program: decl
;

decl: dec decl
|
;

dec: decvar
| decvetor
| decfunction
| decpointer
;

decvar: typevar TK_IDENTIFIER '=' literal ';'
;

decvetor: typevar TK_IDENTIFIER '[' LIT_INTEGER ']' ':' decv ';'
|typevar TK_IDENTIFIER '[' LIT_INTEGER ']' ';'
;

decfunction: typevar TK_IDENTIFIER '(' paramlist ')' body

        decpointer: typevar '#' TK_IDENTIFIER '=' literal ';'

decv:	LIT_INTEGER decv
| LIT_CHAR decv
| LIT_REAL decv
| ' ' decv
|
;

typevar: KW_CHAR
| KW_INT
| KW_FLOAT
;

literal: LIT_INTEGER
| LIT_CHAR
| LIT_REAL
;

paramlist: typevar TK_IDENTIFIER rest
| literal rest
| TK_IDENTIFIER rest
|
;

rest: ',' typevar TK_IDENTIFIER rest
| ',' literal rest
| ',' TK_IDENTIFIER rest
|
;


cmd: attribution
| flux_control
| inout
| body
|
;

body: '{' lcmd '}'
;

lcmd: cmd ';' lcmd
| dec lcmd
| cmd
;

attribution: TK_IDENTIFIER '=' exp
| TK_IDENTIFIER '[' exp ']' '=' exp
;

flux_control: KW_IF '(' exp ')' KW_THEN cmd
| KW_IF '(' exp ')' KW_THEN cmd KW_ELSE cmd
| KW_WHILE '(' exp ')' cmd
| KW_FOR '(' TK_IDENTIFIER '=' exp KW_TO exp')' cmd
;

inout: KW_PRINT print_elem
| KW_READ TK_IDENTIFIER
| KW_RETURN exp
;

print_elem: LIT_STRING
| LIT_STRING print_elem
| LIT_STRING ' ' print_elem
| exp
| exp print_elem
| exp ' ' print_elem
;

exp: TK_IDENTIFIER
| TK_IDENTIFIER '[' exp ']'
| '#'TK_IDENTIFIER
| '&'TK_IDENTIFIER
| LIT_INTEGER
| LIT_CHAR
| exp '+' exp
| exp '-' exp
| exp '*' exp
| exp '/' exp
| exp '<' exp
| exp '>' exp
| '!' exp
| '(' exp ')'
| exp OPERATOR_LE exp
| exp OPERATOR_GE exp
| exp OPERATOR_EQ exp
| exp OPERATOR_NE exp
| exp OPERATOR_AND exp
| exp OPERATOR_OR exp
| TK_IDENTIFIER '(' paramlist ')'
;


%%


int main(int argc, char* argv[])
{
  if (argc > 1 && (yyin = fopen(argv[1], "r")))
  {
  initMe();
 	 yydebug = 0;
    if(yyparse() == 0)
    {
      printf("Sucess, this is a program!\nLines: %d\n", getLineNumber());
        hashPrint();
        exit(0);
    }
  } else {
    printf("Usage: ./etapa2 input_filepath\n");
  }
}

  int yyerror(char *s)
  {
    fprintf(stderr, "line %d: %s\n", getLineNumber(), s);
//    hashPrint();
    exit(3);
  }