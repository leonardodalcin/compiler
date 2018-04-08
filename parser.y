%{
#include<stdio.h>
#include<stdlib.h>
#include "hash.h"
#include "scanner.h"

%}

%union
{
	struct hash_node *symbol;
}


/*Tokens e declaração de tipos*/
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

%%

	name:
    	TK_IDENTIFIER
    	;

	global: program
	;

	program: declar ';' program
	|
	;

	declar:
	var
	| func
	| vector
	| '#' name
	|
	;

	atr:
	 | var '=' exp
	 | vector '[' exp ']' '=' exp

	fCall:
		name '('paramListCall')'

	paramListCall:
	fParamCall
	| fParamCall ',' paramListCall
	|
	;

	fParamCall:
		name
		|'&' name
		|'#' name

	aritExp: TK_IDENTIFIER
    			| 	TK_IDENTIFIER '[' aritExp ']'
    			| 	LIT_INTEGER
    			|	LIT_CHAR
    			| 	'(' aritExp ')'
    			| 	'-' aritExp
    			| 	aritExp '+' aritExp
    			| 	aritExp '-' aritExp
    			| 	aritExp '*' aritExp
    			| 	aritExp '/' aritExp
    			;
	boolExp:
				|	TK_IDENTIFIER
				| 	LIT_INTEGER
				| 	LIT_REAL
				|	LIT_CHAR
				|	LIT_STRING
				| 	'!' boolExp
				| 	aritExp '<' aritExp
				| 	aritExp '>' aritExp
				| 	aritExp OPERATOR_LE aritExp
				| 	aritExp OPERATOR_GE aritExp
				| 	aritExp OPERATOR_EQ aritExp
				| 	aritExp OPERATOR_NE aritExp
				| 	boolExp OPERATOR_AND boolExp
				| 	boolExp OPERATOR_OR boolExp
				;

		exp: aritExp
			| 	boolExp
      		;


	fluxControl:
    	KW_IF '(' exp ')' KW_THEN cmd
    	| KW_IF '(' exp ')' KW_THEN cmd KW_ELSE cmd
    	| KW_WHILE '(' exp ')' cmd
    	| KW_FOR '(' TK_IDENTIFIER '=' exp KW_TO exp ')' cmd
    	;

    cmd:
     atr
     | fluxControl
     | KW_READ var
     | KW_RETURN
     | KW_PRINT
     |

	listOutput: aritExp
    			| 	LIT_STRING
    			| 	listOutput ' ' aritExp
    			| 	listOutput ' ' LIT_STRING
    			;

	cmd: ';' /*Comando vazio*/
	| 	KW_READ var
	| 	KW_PRINT listOutput
	| 	KW_RETURN exp
	| fluxControl
	| 	TK_IDENTIFIER '=' exp
	| 	TK_IDENTIFIER '[' exp ']' '=' exp
	;

	cmdList:
	cmd ';' cmdList
	| cmd
	;

	cmdBlock:
	'{' cmdList '}'
	;

	var:
	type name '=' value
	;

	size:
    	LIT_INTEGER
    	;

	vector:
	type name '[' size ']'
	| vector ':' vectorValueList
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
    ;

    func:
    fHeader fBody
    ;

    fBody:
    	cmdBlock

    fHeader:
    type name '(' paramList ')'

    paramList:
    fParam
    | fParam ',' paramList
    |
    ;

    fParam:
    type name
    |
    ;

%%

  int yyerror(char *s)
  {
  	puts(s);
    fprintf(stderr, "line %d: %s\n", getLineNumber(), s);
    hashPrint();
    exit(3);
  }