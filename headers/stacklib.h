#ifndef STACK_LIB_H
#define STACK_LIB_H

/*prima di utilizzare un puntatore a stack, inizializzarlo con un puntatore ritornato da una chiamata a creaStack*/

typedef struct stack stack;

stack *creaStack(int dim_max);
/*dato un intero
*alloca memoria per un nuovo stack di massimo dim_max elementi
*ritorna un puntatore all'area di memoria
*/
void riempiStack(stack *S);
/*dato un puntatore a stack
*se il puntatore non e' NULL e lo stack non si riempie
*chiede all'utente quanti elementi desidera inserire e nel caso in cui siano piu' di 0 li inserisce
*/
stack *eliminaStack(stack *S);
/*dato un puntatore a stack
*se il puntatore non e' NULL
*libera la memoria occupata dallo stack
*ritorna NULL se l'operazione e' andata a buon fine
*/
int stackEmpty(stack *S);
/*dato un puntatore a stack
*se il puntatore non e' NULL
*ritorna 1 se lo stack e' vuoto, 0 se e' presente almeno un elemento
*/
int stackFull(stack *S);
/*dato un puntatore a stack
*se il puntatore non e' NULL
*ritorna 1 se lo stack e' pieno, 0 se ha almeno un posto vuoto
*/
void push(stack *S, int da_inserire);
/*dato un puntatore a stack e un intero da_inserire
*se il puntatore non e' NULL
*inserisce l'intero in testa allo stack
*/
int pop(stack *S);
/*dato un puntatore a stack,
*se il puntatore non e' NULL
*estrae il prossimo intero dallo stack
*restituisce l'intero estratto
*/
int top(stack *S);
/*dato un puntatore a stack
*se il puntatore non e' NULL
*restituisce il top dello stack senza rimuoverlo
*/
void stampaStack(stack *S);
/*dato un puntatore a stack
*se il puntatore non e' NULL
*stampa gli elementi a partire dal basso separati da uno spazio
*/
void randomizzaStack(stack *S, int numeroElementi, int valoreMax);
/*dato un puntatore a stack e due interi
*se il puntatore non e' NULL
*inserisce nello stack numeroElementi interi compresi fra 1 e valoreMax, oppure si ferma quando lo stack si riempie
*/
#endif
