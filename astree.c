#include "astree.h"
#include <stdio.h>
#include <stdlib.h>
#include "hash.h"

ASTREE* astreeCreate(int type, HASH_ELEMENT *symbol, ASTREE* son0, ASTREE* son1, ASTREE* son2, ASTREE* son3)
{
	ASTREE *newnode = 0;

	newnode = calloc(1,sizeof(ASTREE));
	newnode->type = type;
	newnode->symbol = symbol;
	newnode->son[0] = son0;
	newnode->son[1] = son1;
	newnode->son[2] = son2;
	newnode->son[3] = son3;
	return newnode;
};

void astreePrint(ASTREE *node)
{
	int i=0;
	if(!node){
		printf("NODE NULO\n");
		return;
	}

	nodeType(node);

	for(i=0; i<MAX_SONS; i++)
		if(node->son[i]) {astreePrint(node->son[i]);}

};

void nodeType(ASTREE *node)
{
  printf("NODE TYPE: %d\n", node->type);
  int i = 0;
	if(!node)
		return;
	if(node->verif)
		return;
	else
		node -> verif = 1;
  printf("NODE TYPE: %d\n", node->type);
switch(node->type)


/// erros: a = incn (a , 1 , )
/// a = a (b , c , d , a , a , )

	{
		case AST_SYMBOL:
		if (node->symbol)
			if(node->symbol->yytext)
				fprintf(FileTree, "%s ", node->symbol->yytext);
 		break;

		case AST_DECLARACAO:
      printf("AST_DECLARACAO, NODE[0] %d\n", node->son[0]->type);
			nodeType(node->son[0]);
		break;

    case AST_VAR:
      printf("AST_VAR, NODE[0] %d - NODE[1] %d - NODE[2] %d \n", node->son[0]->type, node->son[1]->type, node->son[2]->type);
      nodeType(node->son[0]);
      nodeType(node->son[1]);
      fprintf(FileTree,"=");
      nodeType(node->son[2]);
      fprintf(FileTree,";");
      break;

    case AST_VECTOR_INIT:
      printf("AST_VECTOR_INIT, NODE[0] %d - NODE[1] %d - NODE[2] %d \n", node->son[0]->type, node->son[1]->type);
      if(node->son[2]) {
        nodeType(node->son[0]);
        nodeType(node->son[1]);
        fprintf(FileTree,"[");
        fprintf(FileTree,"] :");
        nodeType(node->son[2]);
        fprintf(FileTree,";");

      } else {
        nodeType(node->son[0]);
        nodeType(node->son[1]);
        fprintf(FileTree,"[");
        fprintf(FileTree,"]");
        fprintf(FileTree,";");
      }


    case AST_INT:
      printf("AST_INT");
      fprintf(FileTree, "int ");
      break;

    case AST_CHAR:
      printf("AST_CHAR");
      fprintf(FileTree, "char ");
      break;

    case AST_FLOAT:
      printf("AST_FLOAT");
      fprintf(FileTree, "float ");
      break;

    case AST_DEC_POINTER:
      printf("AST_DEC_POINTER");
      nodeType(node->son[0]);
      fprintf(FileTree, "#");
      nodeType(node->son[1]);
      fprintf(FileTree, "=");
      nodeType(node->son[2]);
      fprintf(FileTree, ";");
//    decpointer: typevar '#' name '=' literal ';'    {$$ = astreeCreate(AST_DEC_POINTER, 0, $1, $3, $5, 0);}
      break;
    case AST_DEC_FUNC:
//    decfunction: typevar name '(' paramlist ')' body    {$$ = astreeCreate(AST_DEC_FUNC, 0, $1, $2, $4, $6);}
      printf("AST_DEC_FUNC");
      nodeType(node->son[0]);
      nodeType(node->son[1]);
      fprintf(FileTree, "(");
      nodeType(node->son[2]);
      fprintf(FileTree, ")");
      nodeType(node->son[3]);
      break;

    default:
      printf("DEFAULT: %d\n", node->type);

  }
};