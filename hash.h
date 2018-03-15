//
// Created by Leonardo Dalcin on 3/15/18.
//

#ifndef COMPILADORES_HASH_H
#define COMPILADORES_HASH_H
#include <stdio.h>

typedef struct hash_t {
    int token;
    char *text;
    struct hash_t *next;
} HASH_ELEMENT;

void hash_init();
HASH_ELEMENT* hash_insert(int token, char *text);
int hash_address(char *text);
HASH_ELEMENT* hash_find(char *text);
void hash_print();

#endif //COMPILADORES_HASH_H
