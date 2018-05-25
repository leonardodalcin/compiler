/*  ################      Trabalho Prático - Compiladores [PARTE 1]  ################    */
/*                      Rodolfo Viola Carvalho - 265043   (rvcarvalho)                   */
/*                      Leonardo Vogel Dalcin - 243654   (lvdalcin)                      */

#ifndef COMPILADORES_HASH_H
#define COMPILADORES_HASH_H
#define DATATYPE_INT 1000
#define DATATYPE_FLOAT 1001
#define DATATYPE_CHAR 1002
#define SYMBOL_LIT_INT 500

#include <stdio.h>
#define HASH_SIZE 997
#define SYMBOL_VAR 6
#define SYMBOL_VECTOR 7
#define SYMBOL_FUNC 8
#define SYMBOL_POINT 9
#define SYMBOL_PARAM 10
typedef struct hash_node {
    int type;
    int datatype;
    char *yytext;
    struct hash_node *next;
} HASH_ELEMENT;

void hashInit(void);
int hashAddress(char *text);
HASH_ELEMENT* hashInsert(int type, char *text);
void hashPrint(void);

//funcoes adicionadas
HASH_ELEMENT* alreadyInHash(char *text);
void checkUndeclared(void);

#endif //COMPILADORES_HASH_H
