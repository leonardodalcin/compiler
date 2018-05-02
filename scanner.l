/*  ################      Trabalho Prático - Compiladores [PARTE 1]  ################    */
/*                      Rodolfo Viola Carvalho - 265043   (rvcarvalho)                   */
/*                      Leonardo Vogel Dalcin - 243654   (lvdalcin)                      */

%{
#include "hash.h"
#include "astree.h"
#include "y.tab.h"
#include <stdio.h>

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


"char"      {printf("\n[DEBUG] Found char ");     return KW_CHAR;}
"int"       {printf("\n[DEBUG] Found int ");      return KW_INT;}
"float"     {printf("\n[DEBUG] Found float ");    return KW_FLOAT;}
"if"        {printf("\n[DEBUG] Found if ");       return KW_IF;}
"then"      {printf("\n[DEBUG] Found then ");     return KW_THEN;}
"else"      {printf("\n[DEBUG] Found else ");     return KW_ELSE;}
"while"     {printf("\n[DEBUG] Found while ");    return KW_WHILE;}
"for"       {printf("\n[DEBUG] Found for ");      return KW_FOR;}
"to"       {printf("\n[DEBUG] Found for ");      return KW_TO;}
"read"      {printf("\n[DEBUG] Found read ");     return KW_READ;}
"print"     {printf("\n[DEBUG] Found print ");    return KW_PRINT;}
"return"    {printf("\n[DEBUG] Found return ");   return KW_RETURN;}


         /* ################# Caracteres especiais: Retorna o código ASCII ################# */

"," {printf("\n[DEBUG] Found , "); return yytext[0];}
";" {printf("\n[DEBUG] Found ; "); return yytext[0];}
":" {printf("\n[DEBUG] Found : "); return yytext[0];}
"(" {printf("\n[DEBUG] Found ( "); return yytext[0];}
")" {printf("\n[DEBUG] Found ) "); return yytext[0];}
"[" {printf("\n[DEBUG] Found [ "); return yytext[0];}
"]" {printf("\n[DEBUG] Found ] "); return yytext[0];}
"{" {printf("\n[DEBUG] Found { "); return yytext[0];}
"}" {printf("\n[DEBUG] Found } "); return yytext[0];}
"+" {printf("\n[DEBUG] Found + "); return yytext[0];}
"-" {printf("\n[DEBUG] Found - "); return yytext[0];}
"*" {printf("\n[DEBUG] Found * "); return yytext[0];}
"/" {printf("\n[DEBUG] Found / "); return yytext[0];}
"<" {printf("\n[DEBUG] Found < "); return yytext[0];}
">" {printf("\n[DEBUG] Found > "); return yytext[0];}
"=" {printf("\n[DEBUG] Found = "); return yytext[0];}
"!" {printf("\n[DEBUG] Found ! "); return yytext[0];}
"&" {printf("\n[DEBUG] Found & "); return yytext[0];}
"$" {printf("\n[DEBUG] Found $ "); return yytext[0];}
"#" {printf("\n[DEBUG] Found # "); return yytext[0];}



         /*  ################# Operadores compostos ################# */


"<="	{ printf("\n[DEBUG] Found <= ");  return OPERATOR_LE;}
">="	{ printf("\n[DEBUG] Found >= "); return OPERATOR_GE;}
"=="	{ printf("\n[DEBUG] Found == "); return OPERATOR_EQ;}
"!="	{ printf("\n[DEBUG] Found != "); return OPERATOR_NE;}
"&&"	{ printf("\n[DEBUG] Found && "); return OPERATOR_AND;}
"||"	{ printf("\n[DEBUG] Found || "); return OPERATOR_OR;}

[A-Za-z_]{1}[A-Za-z_0-9]*   {printf("\n[DEBUG] Found identifier '%s' ", yytext); yylval.symbol = hashInsert(TK_IDENTIFIER, yytext);       return TK_IDENTIFIER;}
[0-9]+				    	{printf("\n[DEBUG] Found integer literal: '%s' ", yytext); yylval.symbol = hashInsert(LIT_INTEGER, yytext);   return LIT_INTEGER;}
[0-9]+[.][0-9]+		    	{printf("\n[DEBUG] Found real literal: '%s' ", yytext);yylval.symbol = hashInsert(LIT_REAL, yytext);         return LIT_REAL;}
['][^\n][']	                {printf("\n[DEBUG] Found char literal: '%s' ", yytext);yylval.symbol = hashInsert(LIT_CHAR, yytext);         return LIT_CHAR;}
\"([^\"\\\n]|\\[\"\\n])+\"	{printf("\n[DEBUG] Found string literal: '%s' ", yytext);yylval.symbol = hashInsert(LIT_STRING, yytext);     return LIT_STRING;}

[ \t]      {}
\n		{numLines++;}
.		{printf("\n[ERROR] %s", yytext); return TOKEN_ERROR;}

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



