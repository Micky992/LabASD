#include <stdio.h>
#include <stdlib.h>
#include "listlib.h"

typedef struct elem
{
    int info;
    struct elem *next;
}elem;
/*La struttura utilizzata e' una lista singolarmente puntata i cui nodi sono implementati come struct
info contiene un intero, next e' un puntatore al prossimo nodo della lista
il typedef permette di sostituire la dicitura "struct elem" con il piu' snello "elem" */

typedef elem* lista;
/*un puntatore ad elem e' a tutti gli effetti una lista, quindi viene rinominato "lista"
un dato di tipo lista per essere coerente deve alternativamente puntare a un nodo di lista o essere NULL*/

void stampaLista(lista top){

  if(top != NULL){
    printf("%d ", top->info);//stampa il campo info del top della lista
    stampaLista(top->next);//richiama sul resto della lista
  }

  return;
}

lista successivo (lista nodo){
  lista ret = NULL;
  if (nodo != NULL) {
    ret = nodo->next;
  }
  return ret;
}

int elemento(lista nodo)
{
  int ret = 0;
  if(nodo != NULL){
    ret = nodo->info;
  }
  return ret;
}

lista newElem(int k){

    lista E =(lista)malloc(sizeof(elem));//alloca dinamicamente spazio per un elem, E diventa un puntatore a questo spazio
    E->info = k;//inizializza il nuovo elemento con il valore passato in ingresso
    E->next = NULL;//imposta a NULL il next, il next se non punta a un nodo deve essere sempre NULL
    return E;
}

lista aggiungiInTesta(lista top, int k){

    lista E = newElem(k);//crea un nodo
    E->next = top;//inserisci la lista dopo il nodo creato
    return E;//ritorna la lista aggiornata, il valore ritornato dovra' essere assegnato a un puntatore lista per poter essere utilizzato
}

lista aggiungiInCoda(lista top, int k){

  if(top == NULL)
    top = newElem(k);
  else
    top->next = aggiungiInCoda(top->next, k);

  return top;
}

int lunghezzaLista(lista top){

  if(top == NULL)//se la lista e' vuota
    return 0;
  else
    return 1 + lunghezzaLista(top->next);//ritorna la lunghezza del top (1) + la lunghezza del resto della lista
}

lista deallocaLista(lista top){

  if(top != NULL){//se la lista non e' vuota (caso base gestito implicitamente)
    deallocaLista(top->next);//dealloca il resto della lista
    free(top);//dealloca il top
    top = NULL;//il top non punta piu' a uno spazio di memoria allocato, e' diventato una lista vuota
  }

  return top;
}

lista eliminaTop(lista top){

  lista temp = NULL;//per conservare il valore di top

  if(top != NULL){

    temp = top;//temp punta all'elemento da eliminare
    top = top->next;//eliminando il top il nuovo top sara' il successivo
    free(temp);
  }

  return top;
}

int controllaOrdine(lista top){

  int ret = 1;

  if(top != NULL && top->next != NULL){//se non si trova nel caso base implicito in cui la lista è vuota o contiene un solo elemento (in tal caso e' sempre ordinata)
    if(top->info > top->next->info || !controllaOrdine(top->next)){//controlla se il top non è minore del successivo o il resto della lista non è ordinato
      ret = 0;//solo se una delle condizioni e' vera la lista non e' ordinata
    }
  }

  return ret;
}

lista eliminaRipetizioni(lista top){

  lista temp;

  if(top != NULL && top->next != NULL){//se la lista e' formata da almeno due elementi

    temp = eliminaRipetizioni(top->next);//elimina ripetizioni nel resto della lista
    top->next = temp;//concatena il top al resto con ripetizioni eliminate

    if(top->info == top->next->info){//se c'e' ripetizione fra il top e il successivo
      free(top);//elimina il top
      top = temp;//imposta il suo successivo come nuovo top
    }
  }
  return top;
}

lista interleaving(lista prima, lista seconda){

  if(seconda == NULL)//se una delle due liste e' vuota ritorna l'altra
    return prima;
  else if(prima == NULL)
    return seconda;
  else{//se nessuna delle due e' vuota
    seconda->next = interleaving(prima->next, seconda->next);//dopo il top di seconda andra' l'interleaving fra il resto delle due liste
    prima->next = seconda;//dopo il top di prima andra' il top di seconda
  }
  return prima;
}
