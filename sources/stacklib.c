#include <stdio.h>
#include <stdbool.h>
#include <stacklib.h>

typedef struct stack{
 int * array;
 int dimensione;
}stack;

stack *creaStack(int dim_max){
  stack *S = (stack *)malloc(sizeof(stack));
  S->array = (int *)malloc( (dim_max + 1) * (sizeof(int) ));
  S->dimensione = dim_max;
  S->array[0] = 0;
  return S;
}

void eliminaStack(stack *S){
  free(S->array);
  free(S);
  return;
}

bool stackEmpty(stack *S){
  return (S->array[0] == 0); //Accedo ad S[0], che è la locazione contenente l'indice del array dello stack.
}

bool stackFull(stack *S){
  return (S->array[0] == S->dimensione);
}

void push(stack *S, int da_inserire){
  if(!stackFull(S)){
    S->array[0] = S->array[0] + 1;
    S->array[S->array[0]] = da_inserire;
  }else{
    printf("Stack pieno!\n");//da sostituire con il settaggio di un errore
  }
  return;
}

int pop(stack *S){
  int x = 0;

  if(!stackEmpty(S)){
    x = S->array[S->array[0]];
    S->array[0] -= 1;
  }else{
    printf("Lo stack e' vuoto.\n");//come sopra
  }

  return x;
}

void stampaStack(stack *S){

  int i;

  if(!stackEmpty(S)){
    stampaStack(S);
    i = Pop(S);
    printf("%d ", i);
    push(S, i);
  }

  return;
}
