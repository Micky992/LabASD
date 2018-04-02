#ifndef LISTLIB_H
#define LISTLIB_H

typedef struct elem elem;
/*un elem e' un nodo, elemento costitutivo di una lista*/

typedef elem* lista;
/*un puntatore di tipo lista e' una lista di nodi
puo' contenere solo un indirizzo di nodo o il valore NULL*/

void stampaLista(lista top);
/*stampa tutti gli elementi di una lista di interi*/

lista newElem(int k);
/*alloca memoria per un nuovo elemento
ritorna un puntatore all'elemento*/

lista aggiungiInTesta(lista top, int k);
/*data una lista top e un intero k, inserisce un nuovo nodo con valore k in testa alla lista
ritorna la posizione della nuova testa della lista*/

lista aggiungiInCoda(lista top, int k);
/*data una lista e un intero, inserisce un nuovo nodo con valore k in coda alla lista
ritorna la posizione della nuova testa della lista*/

int lunghezzaLista(lista top);
/*data una lista, ritorna il numero di elementi*/

lista deallocaLista(lista top);
/*dealloca la memoria di tutti gli elementi della lista,
ritorna NULL se e' andata a buon fine*/

lista eliminaTop(lista top);
/*elimina la testa, dealloca la memoria
ritorna la nuova testa*/

int controllaOrdine(lista top);
/*data una lista verifica che gli elementi siano in ordine crescente in senso largo
ritorna 1 se lo sono, 0 se no*/

lista interleaving(lista prima, lista seconda);
/*date due liste costruisce una lista formata dagli elementi della prima alternati a quelli della seconda
ritorna il puntatore alla lista ottenuta da questa operazione
distrugge le liste originali*/

lista eliminaRipetizioni(lista top);
/*data una lista, elimina le eventuali ripetizioni consecutive dello stesso elemento lasciandone una sola occorrenza
ritorna il puntatore alla lista privata delle ripetizioni*/

#endif // LISTLIB_H
