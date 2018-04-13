#include <stdio.h>
#include <stdlib.h>

typedef struct delem
{
    int info;
    struct delem *prev;
    struct delem *next;
}delem;

typedef delem* dlista;

void stampaListaDop(dlista top){

  if(top != NULL){
    printf("%d ", top->info);//stampa il campo info del top della lista
    stampaListaDop(top->next);//richiama sul resto della lista
  }

  return;
}

dlista newElemDop(int k){

    dlista E =(dlista)malloc(sizeof(delem));//alloca dinamicamente spazio per un elem, E diventa un puntatore a questo spazio
    E->info = k;//inizializza il nuovo elemento con il valore passato in ingresso
    E->prev = NULL;
    E->next = NULL;//imposta a NULL il next, il next se non punta a un nodo deve essere sempre NULL
    return E;
}

dlista aggiungiInTestaDop(dlista top, int k){

    dlista E = newElemDop(k);//crea un nodo
    E->next = top;//inserisci la lista dopo il nodo creato
    E->next->prev = E;
    return E; //ritorna la lista aggiornata, il valore ritornato dovra' essere assegnato a un puntatore lista per poter essere utilizzato
}

dlista aggiungiInCodaDopHelper(dlista top, dlista prev, int k){

  if(top == NULL){
    top = newElemDop(k);
    top->prev = prev;
  }else
  top->next = aggiungiInCodaDopHelper(top->next, top, k);

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
    if(top != NULL)
      top->prev = NULL;
  }

  return top;
}
