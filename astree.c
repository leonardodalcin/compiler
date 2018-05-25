#include "astree.h"
#include <stdio.h>
#include <stdlib.h>
#include "hash.h"

int isFirst = 1;

ASTREE *astreeCreate(int type, HASH_ELEMENT *symbol, ASTREE *son0, ASTREE *son1, ASTREE *son2, ASTREE *son3) {
  ASTREE *newnode = 0;
  if (isFirst) {
    root = newnode;
    isFirst = 0;
  }

  newnode = calloc(1, sizeof(ASTREE));
  newnode->type = type;
  newnode->symbol = symbol;
  newnode->son[0] = son0;
  newnode->son[1] = son1;
  newnode->son[2] = son2;
  newnode->son[3] = son3;
  return newnode;
};

void astreePrint(ASTREE *node) {
  int i = 0;
  if (!node) {
    printf("NODE NULO\n");
    return;
  }

  nodeType(node);

  for (i = 0; i < MAX_SONS; i++)
    if (node->son[i]) { astreePrint(node->son[i]); }

};

void nodeType(ASTREE *node) {
  int i = 0;
  if (!node)
    return;
  if (node->verif)
    return;
  else
    node->verif = 1;
  switch (node->type)


/// erros: a = incn (a , 1 , )
/// a = a (b , c , d , a , a , )

  {
    case AST_SYMBOL:
      printf("AST_SYMBOL:\n");
      if (node->symbol) {
        if (node->symbol->yytext) {
          printf("AST_SYMBOL: %s\n", node->symbol->yytext);
          fprintf(FileTree, "%s ", node->symbol->yytext);
        }
      }

      break;

    case AST_DECL:
      printf("AST_DECL, NODE[0] %d\n", node->son[0]->type);
      nodeType(node->son[0]);

      break;

    case AST_DECLARACAO:
      printf("AST_DECLARACAO, NODE[0] %d\n", node->son[0]->type);
      nodeType(node->son[0]);

      break;

    case AST_VAR:
      printf("AST_VAR, NODE[0] %d - NODE[1] %d - NODE[2] %d \n", node->son[0]->type, node->son[1]->type,
             node->son[2]->type);
      nodeType(node->son[0]);
      nodeType(node->son[1]);
      fprintf(FileTree, "=");
      nodeType(node->son[2]);
      fprintf(FileTree, ";\n");

      break;

    case AST_VECTOR_INIT:
      printf("AST_VECTOR_INIT, NODE[0] %d - NODE[1] %d - NODE[2] %d \n", node->son[0]->type, node->son[1]->type);
      if (node->son[2]) {
        nodeType(node->son[0]);
        nodeType(node->son[1]);
        fprintf(FileTree, "[");
        nodeType(node->son[3]);
        fprintf(FileTree, "] :");
        nodeType(node->son[2]);
        fprintf(FileTree, ";\n");

      } else {
        nodeType(node->son[0]);
        nodeType(node->son[1]);
        fprintf(FileTree, "[");
        nodeType(node->son[3]);
        fprintf(FileTree, "]");
        fprintf(FileTree, ";\n");
      }

//          decvetor: typevar name '[' LIT_INTEGER ']' ':' decv ';'    {$$ = astreeCreate(AST_VECTOR_INIT, $4, $1, $2, $7, 0);}
//          | typevar name '[' LIT_INTEGER ']' ';'                     {$$ = astreeCreate(AST_VECTOR_INIT, $4, $1, $2, 0, 0);}

    case ASTREE_INIT_LIST:
      nodeType(node->son[0]);
      fprintf(FileTree, " ");
      nodeType(node->son[1]);
      break;

    case AST_INT:
      printf("AST_INT\n");
      fprintf(FileTree, "int ");
      break;

    case AST_CHAR:
      printf("AST_CHAR\n");
      fprintf(FileTree, "char ");
      break;

    case AST_FLOAT:
      printf("AST_FLOAT\n");
      fprintf(FileTree, "float ");
      break;

    case AST_DEC_POINTER:
      printf("AST_DEC_POINTER\n");
      nodeType(node->son[0]);
      fprintf(FileTree, "#");
      nodeType(node->son[1]);
      fprintf(FileTree, "=");
      nodeType(node->son[2]);
      fprintf(FileTree, ";\n");
//    decpointer: typevar '#' name '=' literal ';'    {$$ = astreeCreate(AST_DEC_POINTER, 0, $1, $3, $5, 0);}
      break;
    case AST_DEC_FUNC:
//    decfunction: typevar name '(' paramlist ')' body    {$$ = astreeCreate(AST_DEC_FUNC, 0, $1, $2, $4, $6);}
      printf("AST_DEC_FUNC\n");
      nodeType(node->son[0]);
      nodeType(node->son[1]);
      fprintf(FileTree, "(");
      nodeType(node->son[2]);
      fprintf(FileTree, ")");
      nodeType(node->son[3]);
      break;
    case AST_PARAML:
//    paramlist: typevar name rest  {$$ = astreeCreate(AST_PARAML, 0, $1, $2, $3, 0);}
//      | literal rest                         {$$ = astreeCreate(AST_PARAML, 0, $1, $2, 0, 0);}
//      | name rest                   {$$ = astreeCreate(AST_PARAML, 0, $1, $2, 0, 0);}
//      | {$$ = 0;}
      printf("AST_PARAML\n");
      nodeType(node->son[0]);
      nodeType(node->son[1]);
      if (node->son[2])nodeType(node->son[2]);
      nodeType(node->son[3]);
      break;
    case AST_REST:
      printf("AST_REST\n");
      fprintf(FileTree, ",");

      nodeType(node->son[0]);
      nodeType(node->son[1]);
      if (node->son[2]) nodeType(node->son[2]);
      break;
//        rest: ',' typevar name rest    {$$ = astreeCreate(AST_REST, 0, $2, $3, $4, 0);}
//      | ',' literal rest                      {$$ = astreeCreate(AST_REST, 0, $2, $3, 0, 0);}
//      | ',' name rest                {$$ = astreeCreate(AST_REST, 0, $2, $3, 0, 0);}
//      | {$$ = 0;}
//      ;
    case AST_CMD:
      printf("AST_CMD\n");

      nodeType(node->son[0]);

      break;
//    cmd: attribution  {$$ = astreeCreate(AST_CMD, 0, $1, 0, 0, 0);}
//      | flux_control    {$$ = astreeCreate(AST_CMD, 0, $1, 0, 0, 0);}
//      | inout           {$$ = astreeCreate(AST_CMD, 0, $1, 0, 0, 0);}
//      | body            {$$ = astreeCreate(AST_CMD, 0, $1, 0, 0, 0);}
//      | {$$ = 0;}
//      ;

    case AST_BLOCO:
      printf("AST_BLOCO\n");
      fprintf(FileTree, "{");

      nodeType(node->son[0]);
      fprintf(FileTree, "}");

      break;
//    body: '{' lcmd '}'  {$$ = astreeCreate(AST_BLOCO, 0, $2, 0, 0, 0);}
//      ;

    case AST_READ:
      fprintf(FileTree, "read ");
      nodeType(node->son[0]);
      break;


    case AST_RET:
      fprintf(FileTree, "return ");
      nodeType(node->son[0]);
      break;


    case AST_PRINT:
      fprintf(FileTree, "print ");
      nodeType(node->son[0]);
      break;


    case AST_CMDLIST:
      printf("AST_CMDLIST\n");
      if (node->son[2]) {
        nodeType(node->son[0]);
        fprintf(FileTree, ";\n");
        nodeType(node->son[2]);
      } else if (node->son[1]) {
        nodeType(node->son[0]);
        nodeType(node->son[1]);
      } else {
        nodeType(node->son[0]);
      }

      break;
//    inout: KW_PRINT print_elem         {$$ = astreeCreate(AST_CMDLIST, 0, 0, $2, 0, 0);}
//      | KW_READ name            {$$ = astreeCreate(AST_CMDLIST, 0, 0, 0, 0, $2);}
//      | KW_RETURN exp                    {$$ = astreeCreate(AST_CMDLIST, 0, 0, 0, $2, 0);}

//    lcmd: cmd ';' lcmd   {$$ = astreeCreate(AST_CMDLIST, 0, $1, 0, $3, 0);}
//
//      | dec lcmd            {$$ = astreeCreate(AST_CMDLIST, 0, $1, $2, 0, 0);}
//      | cmd                 {$$ = astreeCreate(AST_CMDLIST, 0, $1, 0, 0, 0);}
//      ;

    case AST_ATTRIBUTION:
      printf("AST_ATTRIBUTION\n");
      if (node->son[2]) {
        nodeType(node->son[0]);
        fprintf(FileTree, "[");
        nodeType(node->son[1]);
        fprintf(FileTree, "] =");
        nodeType(node->son[2]);
      } else {
        nodeType(node->son[0]);
        fprintf(FileTree, "=");
        nodeType(node->son[1]);
      }
      break;

//    attribution: name '=' exp           {$$ = astreeCreate(AST_ATTRIBUTION, 0, $1, $3, 0, 0);}
//      | name '[' exp ']' '=' exp           {$$ = astreeCreate(AST_ATTRIBUTION, 0, $1, $3, $6, 0);}
//      ;

    case AST_IF:
      printf("AST_IF\n");
      fprintf(FileTree, "if (");
      nodeType(node->son[0]);
      fprintf(FileTree, ") then ");
      nodeType(node->son[1]);

      break;
    case AST_ELSE:
      printf("AST_ELSE\n");
      fprintf(FileTree, "if (");
      nodeType(node->son[0]);
      fprintf(FileTree, ") then ");
      nodeType(node->son[1]);
      fprintf(FileTree, "else ");
      nodeType(node->son[2]);

      break;
    case AST_WHILE:
      printf("AST_WHILE\n");
      fprintf(FileTree, "while (");
      nodeType(node->son[0]);
      fprintf(FileTree, ") ");
      nodeType(node->son[1]);

      break;

    case AST_FOR:
      printf("AST_WHILE\n");
      fprintf(FileTree, "for (");
      nodeType(node->son[0]);
      fprintf(FileTree, " = ");
      nodeType(node->son[1]);
      fprintf(FileTree, " to ");
      nodeType(node->son[2]);
      fprintf(FileTree, ") ");
      nodeType(node->son[3]);
      break;
//    flux_control: KW_IF '(' exp ')' KW_THEN cmd           {$$ = astreeCreate(AST_IF, 0, $3, $6, 0, 0);}
//      | KW_IF '(' exp ')' KW_THEN cmd KW_ELSE cmd           {$$ = astreeCreate(AST_ELSE, 0, $3, $6, $8, 0);}
//      | KW_WHILE '(' exp ')' cmd                            {$$ = astreeCreate(AST_WHILE, 0, $3, $5, 0, 0);}
//      | KW_FOR '(' name '=' exp KW_TO exp')' cmd   {$$ = astreeCreate(AST_FOR, 0, $3, $5, $7, $9);}
//      ;

//    case AST_CMDLIST:
//      if(node->son[1]) {
//        fprintf(FileTree, "print ");
//        nodeType(node->son[1]);
//
//      } else  if(node->son[0]) {
//        fprintf(FileTree, "read ");
//        nodeType(node->son[0]);
//      }else{
//        fprintf(FileTree, "return ");
//        nodeType(node->son[2]);
//
//      }
//        break;
//    inout: KW_PRINT print_elem         {$$ = astreeCreate(AST_CMDLIST, 0, 0, $2, 0, 0);}
//      | KW_READ name            {$$ = astreeCreate(AST_CMDLIST, 0, $2, 0, 0, 0);}
//      | KW_RETURN exp                    {$$ = astreeCreate(AST_CMDLIST, 0, $2, 0, 0, 0);}
//      ;

    case AST_PRINTL:
      if (node->son[0]) nodeType(node->son[0]);
      if (node->son[1]) {
        fprintf(FileTree, " ");
        nodeType(node->son[1]);
      }

      break;
//    print_elem: LIT_STRING            {$$ = astreeCreate(AST_PRINT, 0, 0, 0, 0, 0);}
//      | LIT_STRING print_elem           {$$ = astreeCreate(AST_PRINT, 0, 0, $2, 0, 0);}
//      | LIT_STRING ' ' print_elem       {$$ = astreeCreate(AST_PRINT, 0, 0, $3, 0, 0);}
//      | exp                             {$$ = astreeCreate(AST_PRINT, 0, $1, 0, 0, 0);}
//      | exp print_elem                  {$$ = astreeCreate(AST_PRINT, 0, $1, $2, 0, 0);}
//      | exp ' ' print_elem              {$$ = astreeCreate(AST_PRINT, 0, $1, $3, 0, 0);}
//      ;

    case AST_EXPR_VECTOR:
      nodeType(node->son[0]);
      fprintf(FileTree, "[");
      nodeType(node->son[1]);
      fprintf(FileTree, "]");
      break;
    case AST_HASHTAG:
      fprintf(FileTree, "#");
      nodeType(node->son[0]);
      break;

    case AST_E:
      fprintf(FileTree, "&");

      nodeType(node->son[0]);
      break;
    case AST_ADD:
      nodeType(node->son[0]);
      fprintf(FileTree, "+");
      nodeType(node->son[1]);

      break;
    case AST_SUB:
      nodeType(node->son[0]);
      fprintf(FileTree, "-");
      nodeType(node->son[1]);
      break;
    case AST_MULT:
      nodeType(node->son[0]);
      fprintf(FileTree, "*");
      nodeType(node->son[1]);
      break;
    case AST_DIV:
      nodeType(node->son[0]);
      fprintf(FileTree, "/");
      nodeType(node->son[1]);
      break;
    case AST_LESS:
      nodeType(node->son[0]);
      fprintf(FileTree, "<");
      nodeType(node->son[1]);
      break;
    case AST_GREATER:
      nodeType(node->son[0]);
      fprintf(FileTree, ">");
      nodeType(node->son[1]);
      break;
    case AST_NEG:
      fprintf(FileTree, "!");
      nodeType(node->son[0]);
      break;
    case AST_EXPR:
      fprintf(FileTree, "(");
      nodeType(node->son[0]);
      fprintf(FileTree, ")");

      break;

    case AST_EXPR_FUNC:
      nodeType(node->son[0]);
      fprintf(FileTree, "(");

      nodeType(node->son[1]);
      fprintf(FileTree, ")");

    case AST_LE:
      nodeType(node->son[0]);
      nodeType(node->son[1]);

      break;
    case AST_GE:
      nodeType(node->son[0]);
      fprintf(FileTree, ">=");

      nodeType(node->son[1]);

      break;
    case AST_EQ:
      nodeType(node->son[0]);
      fprintf(FileTree, "==");

      nodeType(node->son[1]);

      break;
    case AST_NE:
      nodeType(node->son[0]);
      fprintf(FileTree, "!=");

      nodeType(node->son[1]);

      break;
    case AST_AND:
      nodeType(node->son[0]);
      fprintf(FileTree, "&&");

      nodeType(node->son[1]);

      break;
    case AST_OR:
      nodeType(node->son[0]);
      fprintf(FileTree, "||");

      nodeType(node->son[1]);

      break;
    default:

      break;

  }
};