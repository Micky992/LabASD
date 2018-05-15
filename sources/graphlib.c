#include <stdio.h>
#include <stdlib.h>
#include <graphlib.h>

typedef struct arco{
  int key;
  struct arco *next;
}arco;

typedef struct grafo{
  int n_vertici;
  arco **adiacenti;
}grafo;

int grafoVuoto(grafo *g){
    return (g == NULL);
}

int nuovoGrafo(int vertici, grafo **g){

  grafo *nuovo;
  int ret = 0;//inizializzata a 0 per gestire implicitamente i casi in cui non fosse possibile allocare memoria
  int i;

  if(vertici > 0){//alloca memoria solo se vertici e' maggiore di 0
    nuovo = (grafo*)malloc(sizeof(grafo));//alloca memoria per un nuovo grafo

    if(nuovo != NULL){//se ha allocato memoria per il grafo
      nuovo->n_vertici = vertici;
      nuovo->adiacenti = (arco**)malloc(sizeof(arco*) * vertici);//alloca memoria per il vettore di liste

      if(nuovo->adiacenti != NULL){//se ha allocato il vettore di liste
        for(i = 0; i < vertici; i++){//pone tutte le liste a NULL
          nuovo->adiacenti[i] = NULL;
        }

        *g = nuovo;//pone il valore del puntatore parametro alla posizione del grafo allocato
        ret = 1;

      }else{//se la malloc del vettore e' fallita
        free(nuovo);//dealloca la memoria del grafo
      }
    }//caso memoria per grafo non allocata gestito implicitamente
  }//caso vertici <= 0 gestito implicitamente
  return ret;//ritorna 1 o 0 a seconda che la creazione sia andata a buon fine o meno
}

arco *nuovoArco(int destinazione){

  arco *nuovo = NULL;

  nuovo = (arco*)malloc(sizeof(arco));
  nuovo->key = destinazione;
  nuovo->next = NULL;

  return nuovo;
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
  arco *curr;

  if(!grafoVuoto(g)){
    for(i = 0; i < g->n_vertici; i++){//per tutte le liste di adiacenza del vettore

      curr = g->adiacenti[i];//partendo dall'inizio

      while(curr != NULL){//scorre la lista e conta gli elementi, potenzialmente 0
        ret = ret + 1;
        curr = curr->next;
      }
    }
  }
  return ret;
}

int aggiungiArco(grafo *g, int partenza, int arrivo){

  arco *curr;
  int ret = 0;

  if(!grafoVuoto(g)){

    if(partenza < g->n_vertici){

      curr = g->adiacenti[partenza];//imposta curr al primo arco uscente da partenza
      while(curr != NULL && curr->next != NULL && curr->key != arrivo){
        /*arriva alla fine della lista di adiacenza di partenza
        o si ferma prima se l'arco con arrivo uguale e' gia' presente*/
        curr = curr->next;
      }

      if(curr == NULL){//se la lista di adiacenza era vuota
        g->adiacenti[partenza] = nuovoArco(arrivo);//crea un arco e modifica il puntatore nell'array perche' punti a questo
        ret = 1;
      }else if(curr->next == NULL){//se e' arrivato alla fine della lista
        curr->next = nuovoArco(arrivo);//crea un arco e lo imposta come successivo dell'ultimo
        ret = 1;
      }else{//l'arco era gia' presente
        printf("L'arco e' gia' presente nel grafo\n");
      }
    }else{
      printf("Non esiste il vertice di partenza\n");
    }
  }else{
    printf("Il grafo e' vuoto");
  }
  return ret;
}

int rimuoviArco(grafo *g, int partenza, int arrivo){


  arco *curr, *prev;
  int ret = 0;

  if(!grafoVuoto(g)){

    if(partenza < g->n_vertici){

      curr = g->adiacenti[partenza];

      while(curr != NULL && curr->key != arrivo){
        prev = curr;
        curr = curr->next;
      }

      if(curr != NULL){//controlla sia il caso in cui la lista fosse vuota, sia il caso in cui sia stata esplorata tutta senza trovare l'elemento

        if(curr == g->adiacenti[partenza]){//se il nodo da eliminare e' il primo bisogna modificare il puntatore nel vettore delle liste
          g->adiacenti[partenza] = g->adiacenti[partenza]->next;
          free(curr);
          ret = 1;
        }else{//altrimenti l'eliminazione e' uguale sia se l'elemento e' centrale sia se e' l'ultimo della lista
          prev->next = curr->next;
          free(curr);
          ret = 1;
        }

      }else{
        printf("L'arco non e' presente nel grafo\n");
      }
    }else{
      printf("Non esiste il vertice di partenza\n");
    }
  }else{
    printf("Il grafo e' vuoto\n");
  }
  return ret;
}

int aggiungiVertice(grafo *g){

  arco **nuovo = NULL;
  int ret = 0;

  if(!grafoVuoto(g)){

    nuovo = (arco**)realloc(g->adiacenti, g->n_vertici + 1);

    if(nuovo != NULL){
      g->adiacenti = nuovo;
      g->n_vertici = g->n_vertici + 1;
      ret = 1;
    }else{
      printf("Impossibile allocare memoria per nuovo vertice\n");
    }
  }else{
    printf("Grafo vuoto\n");
  }

  return ret;
}

int eliminaVertice(grafo *g, int vertice){

  int ret = 0;
  int i;
  arco **nuovo = NULL;
  arco *prev = NULL, *curr = NULL;

  if(!grafoVuoto(g)){

    if(vertice < g->n_vertici){

      nuovo = (arco**)malloc(sizeof(arco*) * (g->n_vertici - 1));
      if(nuovo != NULL){

        ret = 1;

        for(i = 0; i < g->n_vertici; i++){

          if(i < vertice || i > vertice){
            curr = g->adiacenti[i];
            prev = curr;

            while(curr != NULL){

              if(curr->key == vertice){

                if(curr == g->adiacenti[i]){
                  g->adiacenti[i] = g->adiacenti[i]->next;
                  free(curr);
                  curr = g->adiacenti[i];

                }else{
                  prev->next = curr->next;
                  free(curr);
                  curr = prev->next;
                }

              }else{

                if(curr->key > vertice){
                  curr->key = curr->key - 1;

                }
                prev = curr;
                curr = curr->next;
              }
            }

            if(i < vertice){
              nuovo[i] = g->adiacenti[i];
            }else{
              nuovo[i-1] = g->adiacenti[i];
            }

          }else if(i == vertice){

            prev = g->adiacenti[i];

            while(prev != NULL){
              curr = prev->next;
              free(prev);
              prev = curr;
            }
          }
        }

        free(g->adiacenti);
        g->adiacenti = nuovo;
        g->n_vertici = g->n_vertici - 1;

      }else{
        printf("ERRORE in eliminaVertice: Impossibile allocare memoria per nuovo vettore delle adiacenze\n");
      }
    }else{
      printf("ERRORE in eliminaVertice: Vertice da eliminare fuori dal range del grafo\n");
    }
  }else{
    printf("ERRORE in eliminaVertice: Il grafo e' vuoto\n");
  }
}
