#include <stdio.h>
#import "lex.yy.c"

int main() {
    //FILE* testFile = fopen("/Users/leonardodalcin/CLionProjects/Compiladores/testFile.txt", "r");
    FILE* testFile = fopen("/Users/Rodolfo/Documents/Mega/UFRGS/Compiladores/compiler/testFile.txt", "r");
  int token;
  yyin = testFile;
  while( (token = yylex()) ) {
    printf("at line  %d \n", getLineNumber());

  }
  return 0;
}


