#ifndef MATRIX_GRAPH_LIB_H
#define MATRIX_GRAPH_LIB_H

typedef struct grafomat grafomat;

int grafoVuotoMatrix(grafomat *g);
/*prende in ingresso un puntatore a grafo
*restituisce 0 o 1 a seconda che il grafo sia vuoto Matrix(puntatore uguale a NULL) o meno
*/
int nuovoGrafoMatrix(int vertici, grafomat **g);
/*prende in ingresso un numero di vertici e un puntatore a puntatore a grafo
*restituisce 0 se non e' possibile allocare memoria per il grafo o se si cerca di creare un grafo con 0 vertici, 1 altrimenti
*il puntatore passato punta alla memoria allocata per il grafo
*/
void stampaGrafoMatrix(grafomat *g);
/*stampa il grafo puntato dal puntatore g*/
int numeroVerticiMatrix(grafomat *g);
/*prende in ingresso un puntatore a grafo
*restituisce il numero di vertici, 0 se il grafo e' vuoto
*/
int numeroArchiMatrix(grafomat *g);
/*prende in ingresso un puntatore a grafo
*restituisce il numero di archi, 0 se non sono presenti archi
*/
int aggiungiArcoMatrix(grafomat *g, int partenza, int arrivo);
/*prende un puntatore a grafo e due interi rappresentanti vertici del grafo
*se il grafo non e' vuoto, il vertice di partenza esiste e l'arco da partenza ad arrivo non e' gia' presente
*inserisce l'arco da partenza ad arrivo nel grafo
*ritorna 1 se l'arco e' stato inserito oppure è già presente, 0 altrimenti
*/
int rimuoviArcoMatrix(grafomat *g, int partenza, int arrivo);
/*prende un puntatore a grafo e due interi rappresentanti vertici del grafo
*se il grafo non e' vuoto, il vertice di partenza esiste e l'arco da partenza ad arrivo e' presente nel grafo
*elimina l'arco da partenza ad arrivo dal grafo
*ritorna 1 se l'arco e' stato eliminato oppure non era presente, 0 altrimenti
*/
int esisteArcoMatrix(grafomat *g, int i, int j);
/*prende un puntatore a grafo e due interi rappresentanti due vertici del grafo e controlla se è presente un arco che va dal vertice i al vertice j, in tal caso restituisce 1, altrimenti 0*/
int esisteVerticeMatrix(grafomat *g, int v);
/*prende un puntatore a grafo e un intero rappresentante un vertice
*se il grafo non e' vuoto
*ritorna 1 se il vertice e' presente nel grafo, 0 altrimenti
*/
/*prende un puntatore a grafo
*se il grafo non e' vuoto, aggiunge un vertice
*ritorna 1 se il vertice e' stato inserito, 0 altrimenti
*/
int rimuoviVerticeMatrix(grafomat *g, int vertice);
/*prende un puntatore a grafo e un intero rappresentante un vertice
*elimina dal grafo il vertice e tutti gli archi uscenti o entranti da questo, i vertici successivi hanno il loro numero ridotto di conseguenza
*ritorna 1 se il vertice e' stato eliminato, 0 altrimenti
*/
void randomizzaGrafoMatrix(grafomat *g);
/*Aggiunge archi pseudo-randomicamente nel grafo puntato da "g", se viene passato un puntatore NULL viene stampato un messaggio di errore.*/
#endif
