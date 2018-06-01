#include <stdio.h>
#include <stdlib.h>
#include <graphlib.h>

typedef struct grafo{
  int n_vertici;
  int *adiacenti;
}grafo;

int grafoVuoto(grafo *g){
  return (g == NULL);
}

int nuovoGrafo(int vertici, grafo **g){   //Funzione che costruisce un grafo con matrice di adiacenza.

  grafo *nuovo;
  int ret = 0;
  int i;

  if(vertici > 0){//Se il numero di vertici nel grafo è maggiore di zero, tenta di allocare la memoria per il grafo.
    nuovo = (grafo*)malloc(sizeof(grafo));

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
        printf("ERRORE in nuovoGrafo: impossibile allocare memoria per matrice di adiacenza\n");
        free(nuovo);
      }
    }else {
      printf("ERRORE in nuovoGrafo: impossibile allocare memoria per grafo\n");
    }
  }else {
    printf("ERRORE in nuovoGrafo: impossibile creare grafo di 0 vertici\n");
  }

  return ret;     //Ritorna 1 se la costruzione del grafo è andata a buon fine, 0 altrimenti.
}

int numeroVertici(grafo *g){

  int ret;

  if(!grafoVuoto(g)){
    ret = g->n_vertici;
  }else{
    ret = 0;
  }

  return ret;
}

int numeroArchi(grafo *g){

  int ret = 0;
  int i;

  if(!grafoVuoto(g)){
    for(i = 0; i < g->n_vertici * g->n_vertici; i++){//scorre tutta la matrice di adiacenza

      if(g->adiacenti[i] == 1){
        ret = ret + 1;
      }

    }
  }
  return ret;
}

int modificaArco(grafo *g, int partenza, int arrivo, int op){

  int ret = 0;
  if(!grafoVuoto(g)){
    if(partenza < g->n_vertici && arrivo < g->n_vertici){
      g->adiacenti[(g->n_vertici * partenza) + arrivo] = op;
      ret = 1;
    }else{
      printf("ERRORE in modificaArco: vertice di partenza o arrivo non presenti\n");
    }
  }else{
    printf("ERRORE in modificaArco: grafo vuoto\n");
  }
  return ret;
}

int aggiungiArco(grafo *g, int partenza, int arrivo){

  int ret = 1;
  if(!modificaArco(g, partenza, arrivo, 1)){
    printf("Impossibile aggiungere arco.\n");
    ret = 0;
  }
  return ret;//Ritorna 1 se l'arco è stato aggiunto o è già presente, 0 altrimenti.
}

int rimuoviArco(grafo *g, int partenza, int arrivo){

    int ret = 1;
    if(!modificaArco(g, partenza, arrivo, 0)){
      printf("Impossibile rimuovere arco.\n");
      ret = 0;
    }
    return ret;//Ritorna 1 se l'arco è stato rimosso o è non era presente, 0 altrimenti.
}

int indice(grafo *g, int i, int j){//restituisce l'indice della locazione nella matrice di adiacenza con riga i e colonna j
  return (i * g->n_vertici) + j;
}

int esisteArco(grafo *g, int i, int j){//restituisce 1 se l'arco dal vertice i al vertice j esiste, 0 altrimenti
  int ret;
  ret = g->adiacenti[indice(g, i, j)];
  return ret;
}

int esisteVertice(grafo *g, int v){//restistuisce 1 se il vertice è presente nel grafo, 0 altrimenti
  return (v < g->n_vertici);
}

int aggiungiVertice(grafo *g){
  int ret = 0;
  int vertici;
  int i = 0, j = 0;
  int *matrice = NULL;

  if(!grafoVuoto(g)){
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
      printf("ERRORE: impossibile allocare nuova matrice di adiacenza.\n");
    }
  }else{
    printf("ERRORE: grafo vuoto.\n");
  }
  return ret;
}

int rimuoviVertice(grafo *g, int vertice){
  int i = 0, j = 0, ret = 0;
  int *matrice = NULL;
  int vertici;
  if(!grafoVuoto(g)){
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
      printf("ERRORE: impossibile allocare memoria per nuova matrie di adiacenza.\n");}
  }else{
    printf("ERRORE: grafo vuoto.\n");
  }
  return ret;
}
