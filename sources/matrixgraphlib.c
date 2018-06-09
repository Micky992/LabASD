#include <stdio.h>
#include <stdlib.h>
#include "matrixgraphlib.h"

typedef struct grafomat{
  int n_vertici;
  int *adiacenti;
}grafomat;

int grafoVuotoMatrix(grafomat *g){
  return (g == NULL);
}

int nuovoGrafoMatrix(int vertici, grafomat **g){   //Funzione che costruisce un grafo con matrice di adiacenza.

  grafomat *nuovo;
  int ret = 0;
  int i;

  if(vertici > 0){//Se il numero di vertici nel grafo è maggiore di zero, tenta di allocare la memoria per il grafo.
    nuovo = (grafomat*)malloc(sizeof(grafomat));

    if(nuovo != NULL){//Se la memoria per il grafo è stata allocata con successo
      nuovo->n_vertici = vertici;
      nuovo->adiacenti = (int*)malloc( (vertici * vertici) * sizeof(int));//alloca memoria per la matrice di adiacenza.

      if(nuovo->adiacenti != NULL) {//se la matrice e' stata allocata con successo
        for(i = 0; i < vertici*vertici; i++){//ne azzera il contenuto
          nuovo->adiacenti[i] = 0;
        }

        *g = nuovo;//il puntatore parametro viene fatto puntare al grafo allocato
        ret = 1;//aggiorna il valore che segnala l'esito della funzione
      }
      else{
        printf("ERRORE in nuovoGrafoMatrix: impossibile allocare memoria per matrice di adiacenza\n");
        free(nuovo);
      }
    }else {
      printf("ERRORE in nuovoGrafoMatrix: impossibile allocare memoria per grafo\n");
    }
  }else {
    printf("ERRORE in nuovoGrafoMatrix: impossibile creare grafo di 0 vertici\n");
  }

  return ret;     //Ritorna 1 se la costruzione del grafo è andata a buon fine, 0 altrimenti.
}

int numeroVerticiMatrix(grafomat *g){

  int ret;

  if(!grafoVuotoMatrix(g)){
    ret = g->n_vertici;
  }else{
    ret = 0;
  }

  return ret;
}

void stampaGrafoMatrix(grafomat *g){
  int i, j;

  if(!grafoVuotoMatrix(g)){
    for(i = 0; i < numeroVerticiMatrix(g); i++){
      for(j = 0; j < numeroVerticiMatrix(g) ; j++){
        if(g->adiacenti[(i * numeroVerticiMatrix(g)) + j]){
          printf("%d -> %d\n", i, j);
        }
      }
    }
  }
  return;
}

int numeroArchiMatrix(grafomat *g){

  int ret = 0;
  int i;

  if(!grafoVuotoMatrix(g)){
    for(i = 0; i < g->n_vertici * g->n_vertici; i++){//scorre tutta la matrice di adiacenza

      if(g->adiacenti[i] == 1){
        ret = ret + 1;
      }

    }
  }
  return ret;
}

int modificaArcoMatrix(grafomat *g, int partenza, int arrivo, int op){

  int ret = 0;
  if(!grafoVuotoMatrix(g)){
    if(partenza < g->n_vertici && arrivo < g->n_vertici){
      g->adiacenti[(g->n_vertici * partenza) + arrivo] = op;
      ret = 1;
    }else{
      printf("ERRORE in modificaArcoMatrix: vertice di partenza o arrivo non presenti\n");
    }
  }else{
    printf("ERRORE in modificaArcoMatrix: grafo vuoto\n");
  }
  return ret;
}

int aggiungiArcoMatrix(grafomat *g, int partenza, int arrivo){

  int ret = 1;
  if(!modificaArcoMatrix(g, partenza, arrivo, 1)){
    printf("Impossibile aggiungere arco.\n");
    ret = 0;
  }
  return ret;//Ritorna 1 se l'arco è stato aggiunto o è già presente, 0 altrimenti.
}

int rimuoviArcoMatrix(grafomat *g, int partenza, int arrivo){

    int ret = 1;
    if(!modificaArcoMatrix(g, partenza, arrivo, 0)){
      printf("Impossibile rimuovere arco.\n");
      ret = 0;
    }
    return ret;//Ritorna 1 se l'arco è stato rimosso o è non era presente, 0 altrimenti.
}

int indiceMatrix(grafomat *g, int i, int j){//restituisce l'indice della locazione nella matrice di adiacenza con riga i e colonna j
  return (i * g->n_vertici) + j;
}

int esisteArco(grafomat *g, int i, int j){//restituisce 1 se l'arco dal vertice i al vertice j esiste, 0 altrimenti
  int ret;
  ret = g->adiacenti[indiceMatrix(g, i, j)];
  return ret;
}

int esisteVerticeMatrix(grafomat *g, int v){//restistuisce 1 se il vertice è presente nel grafo, 0 altrimenti
  return (v < g->n_vertici);
}

int aggiungiVerticeMatrix(grafomat *g){
  int ret = 0;
  int vertici;
  int i = 0, j = 0;
  int *matrice = NULL;

  if(!grafoVuotoMatrix(g)){
    vertici = g->n_vertici + 1;
    matrice = (int *)calloc(vertici*vertici, sizeof(int));

    if (matrice!=NULL){

      while(j < g->n_vertici * g->n_vertici){
        if(i == 0 || (i % vertici) != 0){
          matrice[i] = g->adiacenti[j];
          j++;
          i++;
        }else{
          matrice[i] = 0;
          i++;
        }
      }
      free(g->adiacenti);
      g->adiacenti = matrice;
      g->n_vertici = vertici;
      ret = 1;
    }else{
      printf("ERRORE in aggiungiVerticeMatrix: impossibile allocare nuova matrice di adiacenza.\n");
    }
  }else{
    printf("ERRORE in aggiungiArcoMatrix: grafo vuoto.\n");
  }
  return ret;
}

int rimuoviVerticeMatrix(grafomat *g, int vertice){
  int i = 0, j = 0, ret = 0;
  int *matrice = NULL;
  int vertici;
  if(!grafoVuotoMatrix(g)){
    vertici = g->n_vertici - 1;
    matrice = (int *)malloc(vertici * vertici * sizeof(int));
    if(matrice != NULL){
      while(j < vertici * vertici){
        if(i % g->n_vertici == vertice){ //tutti gli archi che va nel vertice da eliminare
          i++;
        }
        else if(i == vertice * g->n_vertici){ //primo arco del vertice da eliminare
          i += g->n_vertici;
        }else{
          matrice[j] = g->adiacenti[i];
          j++;
          i++;
        }
      }
      ret = 1;
    }
    else{
      printf("ERRORE in rimuoviVerticeMatrix: impossibile allocare memoria per nuova matrice di adiacenza.\n");}
  }else{
    printf("ERRORE in rimuoviVerticeMatrix: grafo vuoto.\n");
  }
  return ret;
}

void randomizzaGrafoMatrix(grafomat *g){
  int j, z;
  srand(time(0));
  if(!grafoVuotoMatrix(g)){

    for(j = 0; j < numeroVerticiMatrix(g); j++){
      for(z = 0; z < numeroVerticiMatrix(g); z++){
        if(rand() % 2 == 1){
          aggiungiArcoMatrix(g, j, z);
        }
      }
    }
  }else{
    printf("ERRORE in randomizzaGrafoMatrix: grafo vuoto.\n");
  }
  return;
}
