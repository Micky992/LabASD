#include <stdio.h>
#include <stdlib.h>
#include <listlib.h>

typedef struct elem
{
    int info;
    struct elem *next;
}elem;

typedef elem* lista;

void stampaLista(lista top){

  if(top != NULL){
    printf("%d ", top->info);
    stampaLista(top->next);
  }

  return;
}

lista newElem(int k){

    lista E =(lista)malloc(sizeof(elem));
    E->info = k;
    E->next = NULL;
    return E;
}

lista aggiungiInTesta(lista top, int k){

    lista E = newElem(k);
    E->next = top;
    return E;
}

lista aggiungiInCoda(lista top, int k){

  if(top == NULL)
    top = newElem(k);
  else
    top->next = aggiungiInCoda(top->next, k);

  return top;
}

int lunghezzaLista(lista top){

  if(top == NULL)
    return 0;
  else
    return 1 + lunghezzaLista(top->next);
}

lista deallocaLista(lista top){

  if(top != NULL){
    deallocaLista(top->next);
    free(top);
  }

  return top;
}

lista eliminaTop(lista top){

  lista temp = NULL;

  if(top != NULL){

    temp = top;
    top = top->next;
    free(temp);
  }

  return top;
}

int controllaOrdine(lista top){

  int ret = 1;

  if(top != NULL && top->next != NULL){//se non ti trovi nel caso base implicito in cui la lista è vuota o contiene un solo elemento
    if(top->info > top->next->info || !controllaOrdine(top->next)){//se il top non è minore del successivo o il resto della lista non è ordinato
      ret = 0;
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

  if(seconda == NULL)
    return prima;
  else if(prima == NULL)
    return seconda;
  else{
    seconda->next = interleaving(prima->next, seconda->next);
    prima->next = seconda;
  }
  return prima;
}
