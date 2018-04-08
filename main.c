//
// Created by Leonardo Dalcin on 3/18/18.
//
#include "stdio.h"
extern FILE *yyin;

int main(int argc, char* argv[])
{
  if (argc > 1 && (yyin = fopen(argv[1], "r")))
  {
    hashInit();
    if(yyparse() == 0)
    {
      printf("Sucess, this is a program!\nLines: %d\n", getLineNumber());
      hashPrint();
    }
  } else {
    printf("Usage: ./etapa2 input_filepath\n");
  }
  exit(0);
}