#include <stdio.h>
#include <stdlib.h>
#include <queuelib.h>

typedef struct queue{
  int *array;
  int dimensione;
}queue;

queue *creaQueue(int dim_max){
  queue *Q = (queue *)malloc(sizeof(queue));
  Q->array = (int *)malloc( (dim_max + 2) * (sizeof(int)) );
  Q->dimensione = dim_max;
  Q->array[0] = 0;
  Q->array[Q->dimensione + 1] = 1;
  return Q;
}

void eliminaQueue(queue *Q){
  if(Q != NULL){
    free(Q->array);
    free(Q);
  }
  return;
}

int queueEmpty(queue *Q){
  return (Q->array[0] == 0);
}

int queueFull(queue *Q){
  return (Q->array[0] == Q->array[Q->dimensione + 1]);
}

void enqueue(queue *Q, int da_inserire){
  if(!queueFull(Q)){
    Q->array[Q->array[Q->dimensione+1]] = da_inserire;
    if (Q->array[0] == 0)
      Q->array[0] = 1;
    Q->array[Q->dimensione+1] = (Q->array[Q->dimensione + 1] % Q->dimensione) + 1 ;
  }else{
    printf("Queue piena!\n");//sostituire con il settaggio di un errore
  }
  return;
}

int dequeue(queue *Q){
  int x = 0;

  if (!queueEmpty(Q)){
    x = Q->array[Q->array[0]];
    Q->array[0] = (Q->array[0] % Q->dimensione) + 1;

    if (Q->array[0] == Q->array[Q->dimensione + 1]){
      Q->array[0] = 0;
      Q->array[Q->dimensione + 1] = 1;
    }
  }else{
    printf("La queue e' vuota.\n");
  }

  return x;
}

void stampaQ(queue *Q){

  int x;

  if (!queueEmpty(Q)){
    x = dequeue(Q);
    stampaQ(Q);
    printf("%d ", x);
    enqueue(Q, x);
  }

  return;
}

void reverse(queue *Q){
  if(!queueEmpty(Q)){
   int x = dequeue(Q);
   reverse(Q);
   enqueue(Q, x);
  }
  return;
}

void stampaQueue(queue *Q){
  stampaQ(Q);
  reverse(Q);
  printf("\n");
  return;
}
