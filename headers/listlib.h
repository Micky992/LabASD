#ifndef LISTLIB_H
#define LISTLIB_H

typedef struct elem elem;

typedef elem* lista;

void stampaLista(lista top);
/*stampa tutti gli elementi di una lista di interi*/

lista newElem(int k);
/*alloca memoria per un nuovo elemento, inizializza info a k,
next a NULL e ritorna un puntatore all'elemento*/

lista aggiungiInTesta(lista top, int k);
/*data una lista e un intero, inserisce un nuovo elemento di lista
con campo info l'intero in testa alla lista, ritorna la posizione della
nuova testa della lista*/

lista aggiungiInCoda(lista top, int k);
/*data una lista e un intero, inserisce un nuovo elemento di lista
con campo info l'intero in coda alla lista, ritorna la posizione della
nuova testa della lista*/

int lunghezzaLista(lista top);
/*data una lista, ritorna il numero di elementi*/

lista deallocaLista(lista top);
/*dealloca la memoria di tutti gli elementi della lista,
ritorna NULL se e' andata a buon fine*/

lista eliminaTop(lista top);
/*elimina la testa, dealloca la memoria e ritorna la nuova testa*/

int controllaOrdine(lista top);
/*data una lista verifica che gli elementi siano in ordine crescente in senso largo
ritorna 1 se lo sono, 0 se no*/

lista interleaving(lista prima, lista seconda);
/*date due liste ritorna gli elementi della prima lista alternati a quelli della seconda*/

lista eliminaRipetizioni(lista top);
/*data una lista, elimina le eventuali ripetizioni consecutive dello stesso elemento lasciandone una sola occorrenza*/

#endif // LISTLIB_H
