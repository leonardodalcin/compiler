#include "semantic.h"
#include "symbols.h"
//Se debug for definido como 1, printa todos os debugs
#define DEBUG 0

void setDeclarations(ASTREE *node){

    int i;
    //Caso nodo seja nulo.
    if(!node){
        return;
    }


    //Se for declaração de variavel INT
    if(node->type == AST_CHAR){
        //|KW_INT TK_IDENTIFIER '=' exp ';' {$$ = astCreate(AST_VARIABLE_DEC_INT,$2,$4,0,0,0);}
        if(DEBUG)
            fprintf(stderr,"ANTES:%d\n",node->symbol->type);
        if(node->symbol->type != SYMBOL_IDENTIFIER){
            fprintf(stderr,"Semantic error: Symbol %s already declared.\n", node->symbol->yytext);
        }else{
            if(DEBUG)
                printf("Symbol:%s\n",node->symbol->yytext);
            node->symbol->type = SYMBOL_LIT_INT;
            if(DEBUG)
                printf("DEPOIS:%d\n",node->symbol->type);
            if(node->son[0]->type == SYMBOL_INTEGER)
                node->symbol->dataType = DATATYPE_INT;
            if(node->son[0]->type == SYMBOL_REAL)
                node->symbol->dataType =  DATATYPE_FLOAT;
        }
    }

    if(node->type == AST_FLOAT){
        if(DEBUG)
            fprintf(stderr,"ANTES:%d\n",node->symbol->type);
        if(node->symbol->type != SYMBOL_IDENTIFIER){
            fprintf(stderr,"Semantic error: Symbol %s already declared.\n", node->symbol->yytext);
        }else{
            if(DEBUG)
                printf("Symbol:%s\n",node->symbol->yytext);
            node->symbol->type = SYMBOL_REAL;
            if(DEBUG)
                printf("DEPOIS:%d\n",node->symbol->type);
            if(node->son[0]->type == SYMBOL_INTEGER)
                node->symbol->dataType = DATATYPE_INT;
            if(node->son[0]->type == SYMBOL_REAL)
                node->symbol->dataType =  DATATYPE_FLOAT;
        }
    }

    if(node->type == AST_INT){
        if(DEBUG)
            fprintf(stderr,"ANTES:%d\n",node->symbol->type);
        if(node->symbol->type != SYMBOL_IDENTIFIER){
            fprintf(stderr,"Semantic error: Symbol %s already declared.\n", node->symbol->yytext);
        }else{
            if(DEBUG)
                printf("Symbol:%s\n",node->symbol->yytext);
            node->symbol->type = SYMBOL_REAL;
            if(DEBUG)
                printf("DEPOIS:%d\n",node->symbol->type);
            if(node->son[0]->type == SYMBOL_INTEGER)
                node->symbol->dataType = DATATYPE_INT;
            if(node->son[0]->type == SYMBOL_REAL)
                node->symbol->dataType =  DATATYPE_FLOAT;
        }
    }

//    //Para os dois tipos de declaração de vetor
//    if(node->type == AST_VARIABLE_VEC_1_INT || node->type == AST_VARIABLE_VEC_2_INT){
//        if(node->symbol->type != SYMBOL_IDENTIFIER){
//            fprintf(stderr,"Semantic error: Symbol %s already declared.\n", node->symbol->yytext);
//        }else{
//            node->symbol->type = SYMBOL_INTEGER;
//            if(node->son[0]->type == SYMBOL_INTEGER)
//                node->symbol->dataType = DATATYPE_INT;
//            if(node->son[0]->type == SYMBOL_REAL)
//                node->symbol->dataType =  DATATYPE_FLOAT;
//        }
//    }

//    if(node->type == AST_VARIABLE_VEC_2_FLOAT || node->type == AST_VARIABLE_VEC_1_FLOAT){
//        if(node->symbol->type != SYMBOL_IDENTIFIER){
//            fprintf(stderr,"Semantic error: Symbol %s already declared.\n", node->symbol->yytext);
//        }else{
//            node->symbol->type = SYMBOL_REAL;
//            if(node->son[0]->type == SYMBOL_INTEGER)
//                node->symbol->dataType = DATATYPE_INT;
//            if(node->son[0]->type == SYMBOL_REAL)
//                node->symbol->dataType =  DATATYPE_FLOAT;
//        }
//    }
//
//    if(node->type == AST_VARIABLE_DEC_CHAR){
//        if(node->symbol->type != SYMBOL_IDENTIFIER){
//            fprintf(stderr,"Semantic error: Symbol %s already declared.\n", node->symbol->yytext);
//        }else{
//            node->symbol->type = SYMBOL_CHAR;
//            if(node->son[0]->type == SYMBOL_INTEGER)
//                node->symbol->dataType = DATATYPE_INT;
//            if(node->son[0]->type == SYMBOL_REAL)
//                node->symbol->dataType =  DATATYPE_FLOAT;
//            if(node->son[0]->type == SYMBOL_CHAR)
//                node->symbol->dataType =  DATATYPE_CHAR;
//        }
//    }
//
//    if(node->type == AST_VARIABLE_VEC_1_CHAR || node->type == AST_VARIABLE_VEC_2_CHAR){
//        if(node->symbol->type != SYMBOL_IDENTIFIER){
//            fprintf(stderr,"Semantic error: Symbol %s already declared.\n", node->symbol->yytext);
//        }else{
//            node->symbol->type = SYMBOL_CHAR;
//            if(node->son[0]->type == SYMBOL_INTEGER)
//                node->symbol->dataType = DATATYPE_INT;
//            if(node->son[0]->type == SYMBOL_REAL)
//                node->symbol->dataType =  DATATYPE_FLOAT;
//            if(node->son[0]->type == SYMBOL_CHAR)
//                node->symbol->dataType =  DATATYPE_CHAR;
//        }
//    }
//
//    if(node->type == AST_VARIABLE_PTR_INT){
//        if(node->symbol->type != SYMBOL_IDENTIFIER){
//            fprintf(stderr,"Semantic error: Symbol %s already declared.\n", node->symbol->yytext);
//        }else{
//            node->symbol->type = SYMBOL_INT_PTR;
//            if(node->son[0]->type == SYMBOL_INTEGER)
//                node->symbol->dataType = DATATYPE_INT;
//            if(node->son[0]->type == SYMBOL_REAL)
//                node->symbol->dataType =  DATATYPE_FLOAT;
//            if(node->son[0]->type == SYMBOL_CHAR)
//                node->symbol->dataType =  DATATYPE_CHAR;
//        }
//    }
//
//    if(node->type == AST_VARIABLE_PTR_CHAR){
//        if(node->symbol->type != SYMBOL_IDENTIFIER){
//            fprintf(stderr,"Semantic error: Symbol %s already declared.\n", node->symbol->yytext);
//        }else{
//            node->symbol->type = SYMBOL_CHAR_PTR;
//            if(node->son[0]->type == SYMBOL_INTEGER)
//                node->symbol->dataType = DATATYPE_INT;
//            if(node->son[0]->type == SYMBOL_REAL)
//                node->symbol->dataType =  DATATYPE_FLOAT;
//            if(node->son[0]->type == SYMBOL_CHAR)
//                node->symbol->dataType =  DATATYPE_CHAR;
//        }
//    }
//
//    if(node->type == AST_VARIABLE_PTR_FLOAT){
//        if(node->symbol->type != SYMBOL_IDENTIFIER){
//            fprintf(stderr,"Semantic error: Symbol %s already declared.\n", node->symbol->yytext);
//        }else{
//            node->symbol->type = SYMBOL_FLOAT_PTR;
//            if(node->son[0]->type == SYMBOL_INTEGER)
//                node->symbol->dataType == DATATYPE_INT;
//            if(node->son[0]->type == SYMBOL_REAL)
//                node->symbol->dataType ==  DATATYPE_FLOAT;
//            if(node->son[0]->type == SYMBOL_CHAR)
//                node->symbol->dataType ==  DATATYPE_CHAR;
//        }
//    }
//
//    if(node->type == AST_FUNC_HEADER_INT ){
//        if(node->symbol->type != SYMBOL_IDENTIFIER){
//            fprintf(stderr,"Semantic error: Symbol %s already declared.\n", node->symbol->yytext);
//        }else{
//            node->symbol->type = SYMBOL_FUNC_INT;
//        }
//    }
//
//    if(node->type == AST_FUNC_HEADER_CHAR ){
//        if(node->symbol->type != SYMBOL_IDENTIFIER){
//            fprintf(stderr,"Semantic error: Symbol %s already declared.\n", node->symbol->yytext);
//        }else{
//            node->symbol->type = SYMBOL_FUNC_CHAR;
//        }
//    }
//
//    if(node->type == AST_FUNC_HEADER_FLOAT ){
//        if(node->symbol->type != SYMBOL_IDENTIFIER){
//            fprintf(stderr,"Semantic error: Symbol %s already declared.\n", node->symbol->yytext);
//        }else{
//            node->symbol->type = SYMBOL_FUNC_FLOAT;
//        }
//    }
//    //Percorrer todos filhos e declarar.
//    for (i = 0; i < MAX_SONS; i++){
//        setDeclarations(node->son[i]);
//    }



}
// void checkOperands(AST *node);

//void checkUndeclared(void);
