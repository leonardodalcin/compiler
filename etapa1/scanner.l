/*  ################      Trabalho Prático - Compiladores [PARTE 1]  ################    */
/*                      Rodolfo Viola Carvalho - 265043   (rvcarvalho)                   */
/*                      Leonardo Vogel Dalcin - 243654   (lvdalcin)                      */

%{
#include "tokens.h"
#include "hash.h"
#include <stdio.h>
#import "main.c"

int running = 1;
int numLines = 1;

%}

%x COMMENT



%%


        /* ################# Ignora comentários ################# */


"/*"                {BEGIN(COMMENT);}
<COMMENT>"*/"       {BEGIN(INITIAL);}
<COMMENT>.          {}
"//".*              {}
<COMMENT>\n		    {numLines++;}


        /* ################# Palavras Reservadas ################# */


"char"      {printf("[DEBUG] Found char ");     return KW_CHAR;}
"int"       {printf("[DEBUG] Found int ");      return KW_INT;}
"float"     {printf("[DEBUG] Found float ");    return KW_FLOAT;}
"if"        {printf("[DEBUG] Found if ");       return KW_IF;}
"then"      {printf("[DEBUG] Found then ");     return KW_THEN;}
"else"      {printf("[DEBUG] Found else ");     return KW_ELSE;}
"while"     {printf("[DEBUG] Found while ");    return KW_WHILE;}
"for"       {printf("[DEBUG] Found for ");      return KW_FOR;}
"read"      {printf("[DEBUG] Found read ");     return KW_READ;}
"print"     {printf("[DEBUG] Found print ");    return KW_PRINT;}
"return"    {printf("[DEBUG] Found return ");   return KW_RETURN;}


         /* ################# Caracteres especiais: Retorna o código ASCII ################# */

",;:()[]{}+-*/<>=!&$#" {printf("[DEBUG] Found , "); return yytext[0];}



         /*  ################# Operadores compostos ################# */


"<="	{ printf("[DEBUG] Found <= ");  return OPERATOR_LE;}
">="	{ printf("[DEBUG] Found >= "); return OPERATOR_GE;}
"=="	{ printf("[DEBUG] Found == "); return OPERATOR_EQ;}
"!="	{ printf("[DEBUG] Found != "); return OPERATOR_NE;}
"&&"	{ printf("[DEBUG] Found && "); return OPERATOR_AND;}
"||"	{ printf("[DEBUG] Found || "); return OPERATOR_OR;}

[A-Za-z_]{1}[A-Za-z_0-9]*   {printf("[DEBUG] Found identifier '%s' ", yytext);hashInsert(TK_IDENTIFIER, yytext);       return TK_IDENTIFIER;}
[0-9]+				    	{printf("[DEBUG] Found integer literal: '%s' ", yytext);hashInsert(LIT_INTEGER, yytext);   return LIT_INTEGER;}
[0-9]+[.][0-9]+		    	{printf("[DEBUG] Found real literal: '%s' ", yytext);hashInsert(LIT_REAL, yytext);         return LIT_REAL;}
['][^\n][']	                {printf("[DEBUG] Found char literal: '%s' ", yytext);hashInsert(LIT_CHAR, yytext);         return LIT_CHAR;}
\"([^\"\\\n]|\\[\"\\n])+\"	{printf("[DEBUG] Found string literal: '%s' ", yytext);hashInsert(LIT_STRING, yytext);     return LIT_STRING;}

[ \t]      {}
\n		{numLines++;}
.		{printf("[ERROR] %s", yytext); return TOKEN_ERROR;}

%%

         /* ################# Funções ################# */

int yywrap(void){
	running = 0;
	return 1;
}

int getLineNumber(void) {
	return numLines;
}

int isRunning(void) {
  return running;
}

void initMe(void) {
  hashInit();
  running = 1;
  numLines = 1;
}



