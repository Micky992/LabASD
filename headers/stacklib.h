#ifndef STACKLIB_H
#define STACKLIB_H

typedef struct stack stack;
/*lo stack e' una struttura dati LIFO, l'ultimo intero inserito sara' il primo estratto
gestito attraverso un puntatore a stack*/

stack *creaStack(int dim_max);
/*alloca memoria per un nuovo stack di massimo dim_max elementi
ritorna un puntatore all'area di memoria*/

stack *eliminaStack(stack *S);
/*dato un puntatore a stack libera la memoria occupata dalo stack
ritorna NULL se l'operazine e' andata a buon fine*/

int stackEmpty(stack *S);
/*dato un puntatore a stack
ritorna un intero diverso da 0 se lo stack e' vuoto, 0 se e' presente almeno un elemento
l'utilizzo su puntatori NULL e' WIP*/

int stackFull(stack *S);
/*dato un puntatore a stack
ritorna un intero diverso da 0 se lo stack e' pieno, 0 se ha almeno un posto vuoto
l'utilizzo su puntatori NULL e' WIP*/

void push(stack *S, int da_inserire);
/*dato un puntatore a stack e un intero da_inserire inserisce l'intero nello stack
l'utilizzo su puntatori NULL e' WIP*/

int pop(stack *S);
/*dato un puntatore a stack, estrae il prossimo intero
restituisce l'intero estratto
l'utilizzo su puntatori NULL e' WIP*/

void stampaStack(stack *S);
/*dato un puntatore a stack stampa gli elementi a partire dal basso separati da uno spazio
l'utilizzo su puntatori NULL e' WIP*/

#endif
