#include "semantic.h"
#include "symbols.h"
#include "hash.h"

//Se debug for definido como 1, printa todos os debugs
#define DEBUG 0



void testDeclarations(ASTREE *node) {

  if (!node) {
    printf("No more nodes\n");
    return;
  }

  //Se for declaração de variavel INT
  if (node->type == AST_DECLARACAO) {
    printf("%d\n", countInHash(node->son[0]->son[0]->son[1]->symbol->yytext));
    if (countInHash(node->son[0]->son[0]->son[1]->symbol->yytext) != 1) {
      printf("Symbol already declared\n");
      exit(4);
    };
    //    decvar: typevar name '=' literal ';'       {$$ = astreeCreate(AST_VAR, 0, $1, $2, $4, 0);}
//    ;
//
//    decvetor: typevar name '[' LIT_INTEGER ']' ':' decvl ';'    {$$ = astreeCreate(AST_VECTOR_INIT, $4, $1, $2, $7, astreeCreate(AST_SYMBOL, $4, 0, 0, 0, 0));}
//    | typevar name '[' LIT_INTEGER ']' ';'                     {$$ = astreeCreate(AST_VECTOR_INIT, $4, $1, $2, 0, astreeCreate(AST_SYMBOL, $4, 0, 0, 0, 0));}
//    ;
//
//    decfunction: typevar name '(' paramlist ')' body    {$$ = astreeCreate(AST_DEC_FUNC, 0, $1, $2, $4, $6);}
//
//    decpointer: typevar '#' name '=' literal ';'    {$$ = astreeCreate(AST_DEC_POINTER, 0, $1, $3, $5, 0);}
  }

  for (int i = 1; i < MAX_SONS; i++) {
    testDeclarations(node->son[i]);
  }
}

void insertDataType(ASTREE *node) {

  switch(node->type) {
    case AST_INT:
      node->dataType = DATATYPE_INT;
      break;
    case AST_FLOAT:
      node->dataType = DATATYPE_FLOAT;
      break;
    case AST_CHAR:
      node->dataType = DATATYPE_CHAR;
      break;
    default:      break;

  };

  for (int i = 1; i < MAX_SONS; i++) {
    insertDataType(node->son[i]);
  }
}

void testCorrectUse(ASTREE *node) {

  switch(node->type) {
    case AST_INT:
      node->dataType = DATATYPE_INT;
      break;
    case AST_FLOAT:
      node->dataType = DATATYPE_FLOAT;
      break;
    case AST_CHAR:
      node->dataType = DATATYPE_CHAR;
      break;
    default:      break;

  };

  for (int i = 1; i < MAX_SONS; i++) {
    testCorrectUse(node->son[i]);
  }
}
// void checkOperands(AST *node);

void semanticTest(ASTREE *node) {
  insertDataType(node);
  testDeclarations(node);
};
