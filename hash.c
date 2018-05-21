/*  ################      Trabalho Prático - Compiladores [PARTE 1]  ################    */
/*                      Rodolfo Viola Carvalho - 265043   (rvcarvalho)                   */
/*                      Leonardo Vogel Dalcin - 243654   (lvdalcin)                      */

#include <memory.h>
#include "stdlib.h"
#include "hash.h"
#include "y.tab.h"
#include "symbols.h"


HASH_ELEMENT *Table[HASH_SIZE];

int countInHash(char* text) {
  HASH_ELEMENT *node;
  int count = 0;
  for (int i = 0; i < HASH_SIZE; i++) {
    for (node = Table[i]; node; node = node->next)
      switch (node->type) {
        case TK_IDENTIFIER:
          if(strcmp(node->yytext, text) == 0) {
            count++;
          };
          break;
        default:
          printf("No duplicates\n");
          break;
      }
  }
  return count;
}

void checkUndeclared(void){
  HASH_ELEMENT* aux;

  int i = 0;
  for(i = 0 ; i<HASH_SIZE; i++){
    for(aux = Table[i]; aux ; aux=aux->next){
      if(aux->type == SYMBOL_IDENTIFIER){
        fprintf(stderr,"Symbol %s is undeclared!\n",aux->yytext);
        exit(4);
      }
    }
  }
}

//Acha se já tem na HASH
HASH_ELEMENT* alreadyInHash(char *text){
  int endereco = hashAddress(text);
  HASH_ELEMENT* aux;
  //percorrer toda hash até achar
  for(aux = Table[endereco] ; aux ; aux = aux->next){
    if(strcmp(text,aux->yytext) == 0){
      return 1;
    }
  }
  return 0;
}


void hashInit(void) {
  puts("init");
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

  printf("%d", type);
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