#ifndef GRAPHLIB_H
#define GRAPHLIB_H

typedef struct arco arco;

typedef struct grafo grafo;

int grafoVuoto(grafo *g);
/*prende in ingresso un puntatore a grafo
*restituisce 0 o 1 a seconda che il grafo sia vuoto (puntatore uguale a NULL) o meno
*/
int nuovoGrafo(int vertici, grafo **g);
/*prende in ingresso un numero di vertici e un puntatore a puntatore a grafo
*restituisce 0 se non e' possibile allocare memoria per il grafo o se si cerca di creare un grafo con 0 vertici, 1 altrimenti
*il puntatore passato punta alla memoria allocata per il grafo
*/
int numeroVertici(grafo *g);
/*prende in ingresso un puntatore a grafo
*restituisce il numero di vertici, 0 se il grafo e' vuoto
*/
int numeroArchi(grafo *g);
/*prende in ingresso un puntatore a grafo
*restituisce il numero di archi, 0 se non sono presenti archi
*/
int aggiungiArco(grafo *g, int partenza, int arrivo);
/*prende un puntatore a grafo e due interi rappresentanti vertici del grafo
*se il grafo non e' vuoto, il vertice di partenza esiste e l'arco da partenza ad arrivo non e' gia' presente
*inserisce l'arco da partenza ad arrivo nel grafo
*ritorna 1 se l'arco e' stato inserito, 0 altrimenti
*/
int rimuoviArco(grafo *g, int partenza, int arrivo);
/*prende un puntatore a grafo e due interi rappresentanti vertici del grafo
*se il grafo non e' vuoto, il vertice di partenza esiste e l'arco da partenza ad arrivo e' presente nel grafo
*elimina l'arco da partenza ad arrivo dal grafo
*ritorna 1 se l'arco e' stato eliminato, 0 altrimenti
*/
#endif
