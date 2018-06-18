#ifndef HEADER_TAC
#define HEADER_TAC

#include <stdio.h>
#include <stdlib.h>
#include "hash.h"
#include "astree.h"

#define TAC_UNDEF 0
#define TAC_ADD   1
#define TAC_SUB   2
#define TAC_MULT   3
#define TAC_DIV  4
#define TAC_EQ 5
#define TAC_LE 6
#define TAC_GE 7
#define TAC_NE 8
#define TAC_AND 9
#define TAC_OR  10
#define TAC_SYMBOL 11
#define TAC_IFZ 13
#define TAC_IFNZ  14
#define TAC_LABEL  15
#define TAC_GOTO  16
#define TAC_VECTOR 17
#define TAC_VECTOR_ASS 18
#define TAC_CALL 19
#define TAC_PARAM 20
#define TAC_BEGINFUN 21
#define TAC_ENDFUN 22
#define TAC_RETURN 23
#define TAC_PRINT 24
#define TAC_READ 25
#define TAC_L 26
#define TAC_G 27
#define TAC_LITERAL 28
#define TAC_CALLPARAM 29
#define TAC_LESS 30
#define TAC_GRE 31

typedef struct tac_node {
    int type;
    HASH_ELEMENT* res;
    HASH_ELEMENT* op2;
    HASH_ELEMENT* op3;
    struct tac_node* ant;
    struct tac_node* prox;
} TAC;

TAC *tac_create (int type, HASH_ELEMENT* hashRes, HASH_ELEMENT* hashOp2, HASH_ELEMENT* hashOp3);
void tac_printALL (TAC* list);
void tac_print_one (TAC* element);
TAC * tac_join( TAC* first, TAC* second);
TAC *tac_invert(TAC* list);
TAC *generateTacCode(ASTREE *node);

#endif