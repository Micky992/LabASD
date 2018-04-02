#ifndef QUEUELIB_H
#define QUEUELIB_H

typedef struct queue queue;
/*la queue e' una struttura dati FIFO, il primo intero inserito sara' il primo estratto
gestita attraverso un puntatore a queue*/

queue *creaQueue(int dim_max);
/*alloca memoria per una nuova queue di massimo dim_max elementi
ritorna un puntatore all'area di memoria*/

queue *eliminaQueue(queue *Q);
/*dato un puntatore a queue libera la memoria occupata dalla queue
ritorna NULL se l'operazione e' andata a buon fine*/

int queueEmpty(queue *Q);
/*dato un puntatore a queue
ritorna un intero diverso da 0 se la queue e' vuota, 0 se e' presente almeno un elemento
l'utilizzo su puntatori NULL e' WIP*/

int queueFull(queue *Q);
/*dato un puntatore a queue
ritorna un intero diverso da 0 se la queue e' piena, 0 se ha almeno un posto vuoto
l'utilizzo su puntatori NULL e' WIP*/

void enqueue(queue *Q, int da_inserire);
/*dato un puntatore a queue e un intero da_inserire inserisce l'intero nella queue
l'utilizzo su puntatori NULL e' WIP*/

int dequeue(queue *Q);
/*dato un puntatore a queue, estrae il prossimo intero
restituisce l'intero estratto
l'utilizzo su puntatori NULL e' WIP*/

void stampaQueue(queue *Q);
/*dato un puntatore a queue stampa gli elementi separati da uno spazio
l'utilizzo su puntatori NULL e' WIP*/

#endif
