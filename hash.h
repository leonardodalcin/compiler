//
// Created by Leonardo Dalcin on 3/15/18.
//

#ifndef COMPILADORES_HASH_H
#define COMPILADORES_HASH_H
#include <stdio.h>
#define HASH_SIZE 997
typedef struct hash_node {
    int type;
    char *yytext;
    struct hash_node *next;
} HASH_ELEMENT;

void hashInit(void);
int hashAddress(char *text);
HASH_ELEMENT* hashInsert(int type, char *text);
void hashPrint(void);

#endif //COMPILADORES_HASH_H
