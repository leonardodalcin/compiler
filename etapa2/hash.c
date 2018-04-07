/*  ################      Trabalho Prático - Compiladores [PARTE 1]  ################    */
/*                      Rodolfo Viola Carvalho - 265043   (rvcarvalho)                   */
/*                      Leonardo Vogel Dalcin - 243654   (lvdalcin)                      */

#include <memory.h>
#include "stdlib.h"
#include "hash.h"
#include "tokens.h"

HASH_ELEMENT *Table[HASH_SIZE];

void hashInit(void) {
  for (int i = 0; i < HASH_SIZE; ++i) {
    Table[i] = 0;
  }
}

int hashAddress(char *text) {
  int address = 1;
  for (int i = 0; i < strlen(text); ++i) {
    address = (address * text[i]) % HASH_SIZE + 1;
  }
  return address - 1;
}

HASH_ELEMENT *hashInsert(int type, char *text) {
  int address;
  HASH_ELEMENT *newnode = 0;
  address = hashAddress(text);
  newnode = (HASH_ELEMENT *) calloc(1, sizeof(HASH_ELEMENT));
  newnode->yytext = calloc(strlen(text) + 1, sizeof(char));
  newnode->type = type;

  strcpy(newnode->yytext, text);
  newnode->next = Table[address];
  Table[address] = newnode;
  return newnode;
}

void hashPrint()
{
  HASH_ELEMENT *node;
  for(int i=0; i<HASH_SIZE; i++)
    for(node = Table[i]; node; node=node->next)
      switch (node->type) {
        case TK_IDENTIFIER:
          printf("Table[%d] = %s is SYMBOL_IDENTIFIER\n", i, node->yytext);
          break;
        case LIT_CHAR:
          printf("Table[%d] = %s is SYMBOL_LITERAL_CHAR\n", i, node->yytext);
          break;
        case LIT_STRING:
          printf("Table[%d] = %s is SYMBOL_LITERAL_STRING\n", i, node->yytext);
          break;
        case LIT_INTEGER:
          printf("Table[%d] = %s is SYMBOL_LITERAL_INT\n", i, node->yytext);
          break;
        default:
          printf("Table[%d]. Type not identified\n", i);
      }
}