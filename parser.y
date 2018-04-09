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

    	program: cmdList program
    	|
    	;

		declaration:
			type TK_IDENTIFIER '=' value
			| type '#' TK_IDENTIFIER '=' value
			| vector
			;

    	atr:
    	 | TK_IDENTIFIER '=' exp
    	 | TK_IDENTIFIER '[' aritExp ']' '=' TK_IDENTIFIER '[' aritExp ']'

    	fCall:
    		TK_IDENTIFIER '('paramListCall')'

    	paramListCall:
    	fParamCall
    	| fParamCall ',' paramListCall
    	|
    	;

    	fParamCall:
    		TK_IDENTIFIER
    		|'&' TK_IDENTIFIER
    		|'#' TK_IDENTIFIER
    		| value

    	aritExp: TK_IDENTIFIER
        			| 	TK_IDENTIFIER '[' aritExp ']'
        			| 	LIT_INTEGER
        			|	LIT_CHAR
        			|   '#' TK_IDENTIFIER
        			|   '&' TK_IDENTIFIER
        			| 	'(' aritExp ')'
        			| 	'-' aritExp
        			| 	aritExp '+' aritExp
        			| 	aritExp '-' aritExp
        			| 	aritExp '*' aritExp
        			| 	aritExp '/' aritExp
        			;
    	boolExp:
    				TK_IDENTIFIER
    				| 	LIT_INTEGER
    				| 	LIT_REAL
    				|	LIT_CHAR
    				|	LIT_STRING
    				| 	'!' boolExp
    				| 	aritExp '<' aritExp
    				| 	aritExp '>' aritExp
    				| 	aritExp OPERATOR_LE aritExp
    				| 	aritExp OPERATOR_GE aritExp
    				| 	exp OPERATOR_EQ exp
    				| 	exp OPERATOR_NE exp
    				| 	boolExp OPERATOR_AND boolExp
    				| 	boolExp OPERATOR_OR boolExp
    				;

    		exp:  aritExp
    			| 	boolExp
    			| fCall
          		;


    	fluxControl:
        	KW_IF '(' exp ')' KW_THEN cmd
        	| KW_IF '(' exp ')' KW_THEN cmd KW_ELSE cmd
        	| KW_WHILE '(' exp ')' cmdList
        	| KW_FOR '(' TK_IDENTIFIER '=' exp KW_TO exp ')' cmd
        	;

    	listOutput: aritExp
        			| 	LIT_STRING
        			| 	listOutput aritExp
        			| 	listOutput LIT_STRING
        			;

    	cmd:
    	| cmdBlock
    	| 	KW_READ TK_IDENTIFIER
    	| 	KW_PRINT listOutput
    	| 	KW_RETURN exp
    	| fluxControl
    	| 	atr
    	| declaration
    	| func
    	| fCall
    	;

    	cmdList:
    	cmd ';' cmdList
    	| cmd
    	;

    	cmdBlock:
    	'{' cmdList '}'
    	;


    	vector:
    	type TK_IDENTIFIER '[' LIT_INTEGER ']'
    	| vector ':' vectorValueList ';'
    	;

    	vectorValueList:
    	value vectorValueList
    	|
    	;

    	type:
    	KW_CHAR
        | KW_INT
        | KW_FLOAT
        ;

        value:
        LIT_INTEGER
        | LIT_REAL
        | LIT_STRING
        | LIT_CHAR
        ;

        func:
        fHeader fBody
        ;

        fBody:
        	cmdBlock

        fHeader:
        type TK_IDENTIFIER '(' paramList ')'

        paramList:
        fParam
        | fParam ',' paramList
        |
        ;

        fParam:
        type TK_IDENTIFIER
        |
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
    }
  } else {
    printf("Usage: ./etapa2 input_filepath\n");
  }
}

  int yyerror(char *s)
  {

    fprintf(stderr, "line %d: %s\n", getLineNumber(), s);
  }