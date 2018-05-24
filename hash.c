#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hash.h"

HASH* Table[HASH_SIZE];

void hashInit(void){
  int i;
  for (i = 0; i < HASH_SIZE; i++){
    Table[i] = 0;
  }
}

HASH* hashInsert(int type, char *text){
  int address;
  int achou=0;

  address = hashAddress(text);
  HASH *newnode = 0;
  newnode=hashSearch(address,text,&achou);

  if(achou==1){
    return newnode;
  }
    //return NULL;
  else {
    newnode = (HASH*) calloc(1,sizeof(HASH));
    newnode->text = calloc(strlen(text)+1,sizeof(char));
    strcpy(newnode->text,text);
    newnode->next = Table[address];
    newnode->type = type;
    Table[address] = newnode;
  }
  return newnode;
}

void hashPrint(void){
  int i;
  HASH *node;

  for(i = 0; i < HASH_SIZE; i++){
    for(node = Table[i]; node; node = node->next){
      printf("Table[%d] Type:%d - Text: %s\n", i, node->type ,node->text);
    }
  }

}

int hashAddress(char *text){
  int address = 1;
  int i;

  for(i = 0; i < strlen(text); i++){
    address = (address *text[i])%HASH_SIZE + 1;
  }

  return address-1;
}

HASH *hashSearch(int address, char *text,int *achou){
  HASH *h;
  for(h = Table[address]; h != NULL; h=h->next)
    if(strcmp(h->text,text) == 0)
      break;
  if(h != NULL){
    *achou=1;
    return h;
  }else
    return h;
}