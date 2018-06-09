#include <stdio.h>
#include <stdlib.h>
#include "stacklib.h"

typedef struct stack{
 int *array;
 int dimensione;
}stack;
/*La struttura utilizzata e' uno stack implementato in una struct
array e' un puntatore all'array contenente lo stack, dimensione e' il numero massimo di elementi dello stack
l'array avra' spazio per un intero in piu' che servira' da indice al top dello stack
array[0] contiene l'indice del top, cioe' il primo posto occupato, o 0 se lo stack e' vuoto
*/

stack *creaStack(int dim_max){
  stack *S = (stack *)malloc(sizeof(stack));//alloca spazio per la struct
  S->array = (int *)malloc( (dim_max + 1) * (sizeof(int) ));//alloca spazio per l'array puntato da S->array di dimensione + 1 interi
  S->dimensione = dim_max;
  S->array[0] = 0;//imposta l'indice del top a 0, convenzione per indicare stack vuoto
  return S;
}

stack *eliminaStack(stack *S){
  if (S != NULL){
    free(S->array);
    free(S);
  }
  return NULL;
}

int stackEmpty(stack *S){
  return (S->array[0] == 0);//se l'indice del top e' posto a 0 lo stack e' vuoto
}

int stackFull(stack *S){
  return (S->array[0] == S->dimensione);//se l'indice del top e' uguale alla dimensione massima dello stack
}

void push(stack *S, int da_inserire){
  if(!stackFull(S)){//se lo stack non e' pieno
    S->array[0] = S->array[0] + 1;//aumenta l'indice del top
    S->array[S->array[0]] = da_inserire;//inserisce nel nuovo top
  }else{
    printf("Stack pieno!\n");//da sostituire con il settaggio di un errore
  }
  return;
}

int pop(stack *S){
  int x = 0;//per contenere temporaneamente il valore estratto dallo stack

  if(!stackEmpty(S)){//se lo stack non e' vuoto
    x = S->array[S->array[0]];//estrae l'elemento dal posto puntato dall'indice del top
    S->array[0] = S->array[0] - 1;//diminuisce l'indice del top
  }else{
    printf("Lo stack e' vuoto.\n");//come sopra
  }

  return x;
}

void stampaS(stack *S){

  int i;

  if(!stackEmpty(S)){
    i = pop(S);//estrae un elemento
    stampaStack(S);//stampa il resto dello stack
    printf("%d ", i);//stampa l'elemento
    push(S, i);//reinserisce l'elemento nello stack
  }

  return;
}

void stampaStack(stack *S){
  stampaS(S);//stampa lo stack
  printf("\n");//stampa newline
  return;
}
