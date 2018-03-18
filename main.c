//
// Created by Leonardo Dalcin on 3/18/18.
//

int main(int argc, char** argv) {
  hashInit();
  FILE* testFile = fopen(argv[1], "r");
  int token;
  yyin = testFile;
  while( (token = yylex()) ) {
    printf("at line  %d \n", getLineNumber());

  }
  hashPrint();
  return 0;
}