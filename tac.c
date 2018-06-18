#include "tac.h"
#include "astree.h"

TAC *tac_create(int type, HASH_ELEMENT *hashRes, HASH_ELEMENT *hashOp2, HASH_ELEMENT *hashOp3) {
  TAC *new = NULL;
  new = (TAC *) malloc(sizeof(TAC));
  new->type = type;
  new->res = hashRes;
  new->op2 = hashOp2;
  new->op3 = hashOp3;
  new->prox = NULL;
  new->ant = NULL;
  return new;

}

void tac_printALL(TAC *list) {
  TAC *aux = NULL;
  for (aux = list; aux != NULL; aux = aux->prox)
    tac_print_one(aux);
}

void tac_print_one(TAC *element) {
  printf("TAC ");
  switch (element->type) {
    case TAC_UNDEF:
      printf("UNDEFINED ");
      break;
    case TAC_ADD:
      printf("ADD ");
      break;
    case TAC_SUB:
      printf("SUB ");
      break;
    case TAC_MULT:
      printf("MUL ");
      break;
    case TAC_DIV:
      printf("DIV ");
      break;
    case TAC_G:
      printf("G ");
      break;
    case TAC_L:
      printf("L ");
      break;
    case TAC_EQ:
      printf("EQ ");
      break;
    case TAC_LE:
      printf("LE ");
      break;
    case TAC_GE:
      printf("GE ");
      break;
    case TAC_NE:
      printf("NE ");
      break;
    case TAC_AND:
      printf("AND ");
      break;
    case TAC_OR:
      printf("OR ");
      break;
    case TAC_SYMBOL:
      printf("SYMBOL ");
      break;
  }

  if (element->res)
    printf("*res: %s ", element->res->yytext);

  if (element->op2)
    printf("*op2: %s ", element->op2->yytext);

  if (element->op3)
    printf("*op3: %s ", element->op3->yytext);


  printf("\n");


}

TAC *makeBinOp(int type, TAC *code0, TAC *code1) {
  TAC *newTac = tac_create(type, makeTemp(), code0 ? code0->res : 0,
                           code1 ? code1->res : 0);
  return tac_join(code0, tac_join(code1, newTac));
}

TAC *makeIfThen(TAC *code0, TAC *code1) {
  TAC *newIfTac = 0;
  TAC *newLabelTac = 0;
  HASH_ELEMENT *newLabel = makeLabel();
  newIfTac = tac_create(TAC_IFZ, newLabel, code0 ? code0->res : 0, 0);
  newLabelTac = tac_create(TAC_LABEL, newLabel, 0, 0);
  return tac_join(tac_join(tac_join(code0, newIfTac), code1), newLabelTac);


}


TAC *tac_join(TAC *first, TAC *second) {
  TAC *new = NULL;
  if (!first)
    return second;
  if (!second)
    return first;

  new = second;
  while (new->ant)
    new = new->ant;
  new->ant = first;

  return second;
}


TAC *tac_invert(TAC *list) {
  TAC *aux = list;
  if (aux)
    for (aux = list; aux->ant != 0; aux = aux->ant)
      aux->ant->prox = aux;


  return aux;
}

TAC *generateTacCode(ASTREE *node) {
  TAC *result = 0;
  TAC *code[MAX_SONS];
  if (!node) return 0;
  for (int i = 0; i < MAX_SONS; ++i) {
    code[i] = generateTacCode(node->son[i]);
  }

  switch (node->type) {
    case AST_SYMBOL:
      result = tac_create(TAC_SYMBOL, node->symbol, 0, 0);
      break;
    case AST_ADD:
      result = makeBinOp(TAC_ADD, code[0], code[1]);
      break;
    case AST_MULT:
      result = makeBinOp(TAC_MULT, code[0], code[1]);
      break;
    case AST_SUB:
      result = makeBinOp(TAC_SUB, code[0], code[1]);
      break;
    case AST_DIV:
      result = makeBinOp(TAC_DIV, code[0], code[1]);
      break;
    case AST_LESS:
      result = makeBinOp(TAC_LESS, code[0], code[1]);
      break;
    case AST_GREATER:
      result = makeBinOp(TAC_GRE, code[0], code[1]);
      break;
    case AST_LE:
      result = makeBinOp(TAC_LE, code[0], code[1]);
      break;
    case AST_GE:
      result = makeBinOp(TAC_GE, code[0], code[1]);
      break;
    case AST_EQ:
      result = makeBinOp(TAC_EQ, code[0], code[1]);
      break;
    case AST_NE:
      result = makeBinOp(TAC_NE, code[0], code[1]);
      break;
    case AST_AND:
      result = makeBinOp(TAC_AND, code[0], code[1]);
      break;
    case AST_OR:
      result = makeBinOp(TAC_OR, code[0], code[1]);
      break;
    default:
      result = tac_join(tac_join(tac_join(code[0], code[1]), code[2]), code[3]);
      break;
  }
  return result;
}

////---------------------
//TAC* do_funTac(node* funName, TAC* params, TAC* function)
//{
//
//    TAC* beginFun=tac_create(TAC_BEGINFUN, funName, 0, 0);
//    TAC* endFun=tac_create(TAC_ENDFUN, funName, 0, 0);
//
//    TAC* final=tac_join(beginFun, function);
//    final=tac_join(final, endFun);
//    final=tac_join(params, final);
//    return final;
//}
//
////------------------
//TAC *do_returnTac(TAC *expr) {
//    TAC *new=NULL;
//
//    if (expr->type == TAC_VECTOR_ASS) {
//        new= tac_create(TAC_RETURN, expr->res, expr->op2, NULL);
//        new= tac_join(expr->ant, new);
//    } else {
//        new=  tac_create(TAC_RETURN, expr->res, NULL, NULL);
//        new=tac_join(expr,new);
//    }
//
//    return new;
//}
////----------------------
//
//
//TAC* do_ifTac(TAC* expr, TAC * code)
//{
//    TAC* iftac;
//    node* label = make_label();
//    TAC* final=NULL;
//    if(expr)
//        iftac = tac_create(TAC_IFZ, label,expr->res,0);
//    TAC* labelTac=tac_create(TAC_LABEL, label, 0, 0);
//
//    final=tac_join(expr, iftac);
//    final=tac_join(final, code);
//    final=tac_join(final, labelTac);
//    return final;
//
//}
////---------------
//TAC *do_vectorAssignTac(TAC* ident, TAC* index) {
//    TAC* final=NULL;
//    final = tac_create(TAC_VECTOR_ASS, ident->res, index->res, NULL);
//
//    final= tac_join(index, final);
//    return final;
//}
////---------------------
//
//TAC *do_ifElseTac(TAC* exp, TAC* ifCode, TAC* elseCode) {
//
//    node* labelElse;
//    node* labelFim;
//
//    TAC* tacJz;
//    TAC* tacLabelElse;
//    TAC* tacLabelFim;
//    TAC* tacGoto;
//    TAC* final=NULL;
//
//    labelElse = make_label();
//    labelFim = make_label();
//
//    tacLabelElse = tac_create(TAC_LABEL, labelElse, NULL, NULL);
//    tacLabelFim = tac_create(TAC_LABEL, labelFim, NULL, NULL);
//    tacJz = tac_create(TAC_IFZ, labelElse, exp->res, NULL);
//    tacGoto = tac_create(TAC_GOTO, labelFim, NULL, NULL);
//
//    final = tac_join(exp, tacJz);
//    final = tac_join(final, ifCode);
//    final = tac_join(final, tacGoto);
//    final = tac_join(final, tacLabelElse);
//    final = tac_join(final, elseCode);
//    final = tac_join(final, tacLabelFim);
//
//    return final;
//}
////---------------------------
//
//TAC *do_whileTac(TAC* exp, TAC* whileCode) {
//
//    node* labelIni=make_label();
//    node* labelFim=make_label();
//
//    TAC* tacLabelIni;
//    TAC* tacLabelFim;
//    TAC* tacGoto;
//    TAC* tacJz;
//    TAC* temp=NULL;
//
//
//    tacLabelIni = tac_create(TAC_LABEL, labelIni, NULL, NULL);
//    tacLabelFim = tac_create(TAC_LABEL, labelFim, NULL, NULL);
//    tacGoto = tac_create(TAC_GOTO, labelIni, NULL, NULL);
//    tacJz = tac_create(TAC_IFZ, labelFim, exp->res, NULL);
//
//
//    temp = tac_join(tacLabelIni, exp);
//    temp = tac_join(temp, tacJz);
//    temp = tac_join(temp, whileCode);
//    temp = tac_join(temp, tacGoto);
//    temp = tac_join(temp, tacLabelFim);
//
//    return temp;
//}
//
//
////---------------------------
//
//TAC *do_funCallTac(TAC* funcall, TAC* params) {
//    TAC* new=NULL;
//    node* result = NULL;
//    node* ident;
//
//    if (funcall == NULL) {
//        printf("Invalid funcall\n");
//        exit(0);
//    }
//
//    result = make_temp();
//
//    ident = funcall->res;
//    new = tac_create(TAC_CALL, result, ident, NULL);
//
//    new= tac_join(params,new);
//    return new;
//}
////-------------------
//
//TAC* do_callParamsTac(TAC* exp, TAC* param)
//{
//    if(!exp)
//    {
//        printf("y u no exist?");
//        getc(stdin);}
//    TAC* new=NULL;
//
//    new= tac_create(TAC_CALLPARAM, exp->res, NULL, NULL);
//    new=tac_join(param, new);
//    return new;
//}
//
//TAC* do_oneCallParamsTac(node* param)
//{
//    TAC* new=NULL;
//    new=tac_create(TAC_CALLPARAM, param, NULL, NULL);
//    return new;
//}
////-------------------
////-----------------------
//
//TAC* do_funParamTac(node* param_id)
//{
//
//    TAC* param = tac_create(TAC_PARAM, param_id, 0, 0);
//
//    return param;
//}
