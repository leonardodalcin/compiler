#include <stdio.h>
#import "lex.yy.c"

int main() {
  FILE* testFile = fopen("/Users/leonardodalcin/CLionProjects/Compiladores/testFile.txt", "r");
  int token;
  yyin = testFile;
  while( (token = yylex()) ) {
    printf("line: %d, token: %d, buffer: %s\n",yylineno,token,yytext);
  }

  return 0;
}


