#include <stdio.h>
#include <stdlib.h>
#include "queuelib.h"

typedef struct queue{
  int *array;
  int dimensione;
}queue;
/*La struttura utilizzata e' una coda implementata in una struct
array e' un puntatore all'array contenente la coda, dimensione e' il numero massimo di elementi della coda
l'array avra' spazio per due interi in piu' che serviranno da indici alla testa e alla coda
array[0] contiene l'indice della testa, cioe' il primo posto occupato, o 0 se la queue e' vuota
array[dimensione+1] contiene l'indice della coda, cioe' il primo posto libero*/

queue *creaQueue(int dim_max){
  queue *Q = (queue *)malloc(sizeof(queue));//alloca spazio per la struct
  Q->array = (int *)malloc( (dim_max + 2) * (sizeof(int)) );//alloca spazio per l'array puntato da Q->array di dimensione + 2 interi
  Q->dimensione = dim_max;
  Q->array[0] = 0;//l'indice della testa (in posizione array[0]) viene posto uguale a 0, indica l'elemento da prelevare
  Q->array[Q->dimensione + 1] = 1;//l'indice della coda viene posto uguale a 1, indica il primo posto disponibile per inserire
  return Q;
}

queue *eliminaQueue(queue *Q){
  if(Q != NULL){
    free(Q->array);
    free(Q);
  }
  return NULL;
}

int queueEmpty(queue *Q){
  return (Q->array[0] == 0);//l'indice al primo posto occupato sara' sempre a 0 se la queue e' vuota
}

int queueFull(queue *Q){
  return (Q->array[0] == Q->array[Q->dimensione + 1]);//se il primo posto libero e il primo occupato coincidono
}

void enqueue(queue *Q, int da_inserire){
  if(!queueFull(Q)){//se la queue non e' piena
    Q->array[Q->array[Q->dimensione+1]] = da_inserire;//inserisce nel primo posto vuoto
    if (Q->array[0] == 0)//se la queue era vuota
      Q->array[0] = 1;//imposta il primo posto occupato a quello appena riempito
    Q->array[Q->dimensione+1] = (Q->array[Q->dimensione + 1] % Q->dimensione) + 1 ;//imposta il primo posto libero al prossimo
  }else{
    printf("Queue piena!\n");//sostituire con il settaggio di un errore
  }
  return;
}

int dequeue(queue *Q){
  int x = 0;//per contenere temporaneamente il valore estratto dalla queue

  if (!queueEmpty(Q)){//se la queue non e' vuota
    x = Q->array[Q->array[0]];//estrai l'elemento dal primo posto occupato
    Q->array[0] = (Q->array[0] % Q->dimensione) + 1;//imposta il primo posto occupato a prossimo

    if (Q->array[0] == Q->array[Q->dimensione + 1]){//se a questo punto l'array si e' svuotato
      Q->array[0] = 0;//reimposta l'indice del primo posto occupato al valore speciale 0
      Q->array[Q->dimensione + 1] = 1;//reimposta l'indice del primo libero a 1
    }
  }else{
    printf("La queue e' vuota.\n");
  }

  return x;
}

void stampaQ(queue *Q){

  int x;

  if (!queueEmpty(Q)){
    x = dequeue(Q);//estrae un valore dalla queue
    stampaQ(Q);//stampa il resto della queue
    printf("%d ", x);//stampa il valore estratto
    enqueue(Q, x);//reinserisce il valore nella queue
  }
  //la queue sara' invertita all'uscita dalla funzione
  return;
}

void reverse(queue *Q){

  int x;

  if(!queueEmpty(Q)){
    x = dequeue(Q);//estrae un elemento
    reverse(Q);//inverte il resto della queue
    enqueue(Q, x);//reinserisce l'elemento estratto
  }
  return;
}

void stampaQueue(queue *Q){
  stampaQ(Q);//stampa la queue e la inverte come effetto collaterale
  reverse(Q);//inverte la queue per ripristinare l'ordine iniziale
  printf("\n");
  return;
}
