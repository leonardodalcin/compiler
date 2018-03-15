%{
#include "tokens.h"
#include "hash.h"

int running = 1;
int numLines = 1;

%}

%x COMM



%%
"char" {printf("[DEBUG] Found char "); return KW_CHAR;}
"int" {printf("[DEBUG] Found int "); return KW_INT;}
"float" {printf("[DEBUG] Found float "); return KW_FLOAT;}
"if" {printf("[DEBUG] Found if "); return KW_IF;}
"then" {printf("[DEBUG] Found then "); return KW_THEN;}
"else" {printf("[DEBUG] Found else "); return KW_ELSE;}
"while" {printf("[DEBUG] Found while "); return KW_WHILE;}
"for" {printf("[DEBUG] Found for "); return KW_FOR;}
"read" {printf("[DEBUG] Found read "); return KW_READ;}
"print" {printf("[DEBUG] Found print "); return KW_PRINT;}
"return" {printf("[DEBUG] Found return "); return KW_RETURN;}

"," {return printf("[DEBUG] Found , ");}
";" {return printf("[DEBUG] Found ; ");}
":" {return printf("[DEBUG] Found : ");}
"(" {return printf("[DEBUG] Found ( ");}
")" {return printf("[DEBUG] Found ) ");}
"[" {return printf("[DEBUG] Found [ ");}
"]" {return printf("[DEBUG] Found ] ");}
"{" {return printf("[DEBUG] Found { ");}
"}" {return printf("[DEBUG] Found } ");}
"+" {return printf("[DEBUG] Found + ");}
"-" {return printf("[DEBUG] Found - ");}
"*" {return printf("[DEBUG] Found * ");}
"/" {return printf("[DEBUG] Found / ");}
"<" {return printf("[DEBUG] Found < ");}
">" {return printf("[DEBUG] Found > ");}
"=" {return printf("[DEBUG] Found = ");}
"!" {return printf("[DEBUG] Found ! ");}
"&" {return printf("[DEBUG] Found & ");}
"$" {return printf("[DEBUG] Found $ ");}
"#" {return printf("[DEBUG] Found # ");}

"<="				{return printf("[DEBUG] Found <= ");}
">="				{return printf("[DEBUG] Found >= ");}
"=="				{return printf("[DEBUG] Found == ");}
"!="				{return printf("[DEBUG] Found != ");}
"&&"				{return printf("[DEBUG] Found && ");}
"||"				{return printf("[DEBUG] Found || ");}

[A-Za-z_][A-Za-z_0-9]+	{printf("[DEBUG] Found identifier '%s' ", yytext);hash_insert(TK_IDENTIFIER, yytext); return TK_IDENTIFIER;}
[0-9]+					{printf("[DEBUG] Found integer literal: '%s' ", yytext);hash_insert(LIT_INTEGER, yytext); return LIT_INTEGER;}
[0-9]+[.][0-9]+			{printf("[DEBUG] Found real literal: '%s' ", yytext);hash_insert(LIT_REAL, yytext); return TK_IDENTIFIER;}
["][A-Za-z0-9]["]	{printf("[DEBUG] Found char literal: '%s' ", yytext);hash_insert(LIT_CHAR, yytext); return TK_IDENTIFIER;}
["].*["]	{printf("[DEBUG] Found string literal: '%s' ", yytext);hash_insert(LIT_STRING, yytext); return TK_IDENTIFIER;}



\n								{numLines++;}
.								{printf("[ERROR] %s", yytext); return TOKEN_ERROR;}

%%

int yywrap(void){
	running = 0;
	return 1;
}

int getLineNumber(void) {
	return numLines;
}