/*  ################      Trabalho Prático - Compiladores [PARTE 1]  ################    */
/*                      Rodolfo Viola Carvalho - 265043   (rvcarvalho)                   */
/*                      Leonardo Vogel Dalcin - 243654   (lvdalcin)                      */

#include <stdio.h>
#import "lex.yy.c"


int main() {
//    FILE* testFile = fopen("/Users/leonardodalcin/CLionProjects/compiler/testFile.txt", "r");
    FILE* testFile = fopen("/Users/Rodolfo/Documents/Mega/UFRGS/Compiladores/compiler/testFile.txt", "r");
  int token;
  yyin = testFile;
  while( (token = yylex()) ) {
    printf("at line  %d \n", getLineNumber());

  }
  hashPrint();
  return 0;
}



