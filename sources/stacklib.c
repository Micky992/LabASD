#include <stdio.h>
#include <stdlib.h>
#include "stacklib.h"

stack *creaStack(int dim_max){

  stack *S = (stack *)malloc(sizeof(stack));//alloca spazio per la struct

  if(S != NULL){

    S->array = (int *)malloc( (dim_max + 1) * (sizeof(int) ));//alloca spazio per l'array puntato da S->array di dimensione + 1 interi

    if(S->array != NULL){

      S->dimensione = dim_max;
      S->array[0] = 0;//imposta l'indice del top a 0, convenzione per indicare stack vuoto

    }else{
      free(S);
      printf("Impossibile allocare memoria\n");
    }
  }else{
    printf("Impossibile allocare memoria\n");
  }

  return S;
}

void riempiStack(stack *S){

  int scelta = -1;
  int x;
  int i = 0;

  if(S != NULL){

    do{
      printf("Quanti elementi inserire nello stack?: ");
      scanf("%d", &scelta);
    }while(scelta < 0);

    while(i < scelta && !stackFull(S)){
      printf("inserire elemento %d: ", i+1);
      scanf("%d", &x);

      push(S, x);
    }

  }else{
    printf("ERRORE in riempiStack: puntatore NULL\n");
  }

  return;
}

stack *eliminaStack(stack *S){

  if (S != NULL){
    free(S->array);
    free(S);
  }else{
    printf("ERRORE in eliminaStack: puntatore NULL\n");
  }

  return NULL;
}

int stackEmpty(stack *S){

  int ret;

  if(S != NULL){

    if(S->array[0] == 0){
      ret = 1;
    }else{
      ret = 0;
    }

  }else{
    printf("ERRORE in stackEmpty: puntatore NULL\n");
  }

  return ret;
}

int stackFull(stack *S){

  int ret;

  if(S != NULL){

    if(S->array[0] == S->dimensione){
      ret = 1;
    }else{
      ret = 0;
    }

  }else{
    printf("ERRORE in stackFull: puntatore NULL\n");
  }

  return ret;
}

void push(stack *S, int da_inserire){

  if(S != NULL){

    if(!stackFull(S)){//se lo stack non e' pieno
      S->array[0] = S->array[0] + 1;//aumenta l'indice del top
      S->array[S->array[0]] = da_inserire;//inserisce nel nuovo top
    }else{
      printf("Stack pieno!\n");//da sostituire con il settaggio di un errore
    }

  }else{
    printf("ERRORE in push: puntatore NULL\n");
  }

  return;
}

int pop(stack *S){

  int x = 0;//per contenere temporaneamente il valore estratto dallo stack

  if(S != NULL){

    if(!stackEmpty(S)){//se lo stack non e' vuoto
      x = S->array[S->array[0]];//estrae l'elemento dal posto puntato dall'indice del top
      S->array[0] = S->array[0] - 1;//diminuisce l'indice del top
    }else{
      printf("Lo stack e' vuoto.\n");//come sopra
    }

  }else{
    printf("ERRORE in pop: puntatore NULL\n");
  }

  return x;
}

int top(stack *S){

  int ret = 0;

  if(S != NULL){

    if(!stackEmpty(S)){
      ret = S->array[S->array[0]];
    }else{
      printf("Lo stack e' vuoto.\n");
    }

  }else{
    printf("ERRORE in top: puntatore NULL\n");
  }

  return ret;
}

void stampaStack(stack *S) {
  if (stackEmpty(S)){
    printf("\n");
    return;
  }
  else {
    int valore=pop(S);
    printf("%d   ", valore);
    stampaStack(S);
    push(S, valore);
  }
}

void randomizzaStack(stack *S, int numeroElementi, int valoreMax){

  int i = 0;

  if(S != NULL){

    while(i < numeroElementi && !stackFull(S)){
      push(S, ( rand() % valoreMax ) + 1);
      i++;
    }

  }else{
    printf("ERRORE in randomizzaStack: puntatore NULL\n");
  }

  return;
}
