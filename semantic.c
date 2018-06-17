#include <stdio.h>
#include <stdlib.h>
#include "semantic.h"
#include "hash.h"
#include "astree.h"
#include "tokens.h"
#include "symbols.h"

void set_declarations(ASTREE *node)
{
    if(!node) return;
    if(node->type == AST_VAR)
    {
        if(node->son[1]->symbol->type != TK_IDENTIFIER){
            exit(4);
        }
        node->son[1]->symbol->type = SYMBOL_INTEGER;
        if(node->son[1]->symbol->type == KW_INT) {
            if(node->son[2]->type == LIT_INTEGER) node->datatype = DATATYPE_INT;

        }
        if(node->son[1]->symbol->type == KW_FLOAT) {
            if(node->son[2]->type == LIT_INTEGER) node->datatype = DATATYPE_INT;

        }
        if(node->son[1]->symbol->type == KW_CHAR) {
            if(node->son[2]->type == LIT_INTEGER) node->datatype = DATATYPE_INT;
        }
    }



  for (int i=0;i<MAX_SONS; ++i){
      set_declarations(node->son[i]);
  }
}