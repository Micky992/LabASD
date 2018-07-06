#include <stdio.h>
#include <stdlib.h>
#include "doublelistlib.h"

typedef struct delem{
    int info;
    struct delem *prev;
    struct delem *next;
}delem;

typedef delem* dlista;

void stampaListaDop(dlista top){

  if(top != NULL){
    printf("%d -> ", top->info);//stampa il campo info del top della lista
    stampaListaDop(top->next);//richiama sul resto della lista
  }else{
    printf("//");
  }

  return;
}

dlista precedenteDop(dlista nodo){

  dlista ret = NULL;

  if(nodo != NULL){
    ret = nodo->prev;
  }else{
    printf("ERRORE in precedenteDop: lista vuota\n");
  }

  return ret;
}

dlista successivoDop(dlista nodo){

  dlista ret = NULL;

  if(nodo != NULL){
    ret = nodo->next;
  }else{
    printf("ERRORE in successivoDop: lista vuota\n");
  }

  return ret;
}

int valoreDiDop(dlista nodo){

  int ret = 0;

  if(nodo !=NULL){
    ret = nodo->info;
  }else{
    printf("ERRORE in valoreDiDop: lista vuota\n");
  }

  return ret;
}

dlista newElemDop(int k){

    dlista E = NULL;

    E = (dlista)malloc(sizeof(delem));//alloca dinamicamente spazio per un elem

    if(E != NULL){
      E->info = k;//inizializza il nuovo elemento con il valore passato in ingresso
      E->prev = NULL;
      E->next = NULL;//imposta a NULL il next, il next se non punta a un nodo deve essere sempre NULL
    }else{
      printf("ERRORE in newElemDop: impossibile allocare memoria\n");
    }

    return E;
}

dlista aggiungiInTestaDop(dlista top, int k){

    dlista E = NULL;

    E = newElemDop(k);//crea un nodo

    if(E != NULL){
      E->next = top;//inserisce la lista dopo il nodo creato
      E->next->prev = E;
    }

    return E; //ritorna la lista aggiornata, il valore ritornato dovra' essere assegnato a un puntatore lista per poter essere utilizzato
}

dlista aggiungiInCodaDopHelper(dlista top, dlista prev, int k){

  if(top == NULL){
    top = newElemDop(k);
    top->prev = prev;
  }else{
    top->next = aggiungiInCodaDopHelper(top->next, top, k);
  }

  return top;
}

dlista aggiungiInCodaDop(dlista top, int k){

  if(top == NULL)
    top = newElemDop(k);
  else
    top->next = aggiungiInCodaDopHelper(top->next, top, k);

  return top;
}

dlista eliminaTopDop(dlista top){

  dlista temp;

  if(top != NULL){

    temp = top;
    top = top->next;
    free(temp);
    if(top != NULL){
      top->prev = NULL;
    }
  }

  return top;
}
