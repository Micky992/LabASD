#ifndef ABRLIB_H
#define ABRLIB_H

typedef struct nodo nodo;

typedef nodo* albero;

int alberoVuoto(albero radice);
/*prende come argomento un albero
*ritorna 1 se l'albero e' vuoto, 0 altrimenti
*/
int valoreRadice(albero radice, int *val);
/*prende come argomento un albero e un intero passato per riferimento
*ritorna 1 se il valore della radice e' stato recuperato, 0 altrimenti
*il valore della radice e' posto nella variabile var
*/
albero figlioSx(albero radice);
/*ritorna il sottoalbero sinistro di radice
*/
albero figlioDx(albero radice);
/*ritorna il sottoalbero destro di radice
*/
albero costruisciAlbero(int e, albero s, albero d);
/*dati un intero e due alberi
*alloca spazio per un nuovo nodo, contenente l'intero e i due alberi come figli
*ritorna l'albero cosi' creato
*/
albero deallocaNodo(albero radice);
/*elimina la radice dell'albero passato come argomento
*ritorna NULL se il nodo e' stato deallocato con successo
*/
void visitaPreOrder(albero radice);
/*stampa a standard output la visita pre order dell'albero
*/
void visitaInOrder(albero radice);
/*stampa a standard output la visita in order dell'albero
*/
void visitaPostOrder(albero radice);
/*stampa a standard output la visita post order dell'albero
*/
int ricercaInABR(albero radice, int key);
/*prende in ingresso un ABR e un intero
*ritorna 1 se key e' presente nell'ABR, 0 altrimenti
*/
void InserisciInABR(albero *radice, int e);
/*prende in ingresso un puntatore ad un ABR e un intero
*inserisce l'intero nell'ABR preservandone le proprieta'
*/
int minimoABR(albero radice);
/*dato un ABR ritorna il minimo intero contenuto
*/
void eliminaInABR(albero *radice, int e);
/*dato un puntatore ad ABR e un intero
*elimina l'intero dall'ABR se presente
*/
#endif
