#include <stdio.h>
#include <stdlib.h>
#include "abrlib.h"

typedef struct nodo{
  int info;
  struct nodo *sx;
  struct nodo *dx;
}nodo;

typedef struct nodo* albero;

int alberoVuoto(albero radice){

  return (radice == NULL);
}

int valoreRadice(albero radice, int *val){
  int ret = 0;

  if(!alberoVuoto(radice)){
    *val = radice->info;
    ret = 1;
  }
  return ret;
}

albero figlioSx(albero radice){

  albero ret = NULL;

  if(!alberoVuoto(radice)){
    ret = radice->sx;
  }

  return ret;
}

albero figlioDx(albero radice){

  albero ret = NULL;

  if(!alberoVuoto(radice)){
    ret = radice->dx;
  }

  return ret;
}

albero costruisciAlbero(int e, albero s, albero d){

  albero temp;

  temp = (albero)malloc(sizeof(nodo));

  if(temp != NULL){
    temp->info = e;
    temp->dx = d;
    temp->sx = s;
  }

  return temp;
}

albero deallocaNodo(albero radice){
  if(!alberoVuoto(radice)){
    free(radice);
  }
  return NULL;
}

void visitaPreOrder(albero radice){

  int temp;

  if(valoreRadice(radice, &temp)){
    printf("%d ", temp);
    visitaPreOrder(figlioSx(radice));
    visitaPreOrder(figlioDx(radice));
  }
  return;
}

void visitaInOrder(albero radice){

  int temp;

  if(valoreRadice(radice, &temp)){
    visitaInOrder(figlioSx(radice));
    printf("%d ", temp);
    visitaInOrder(figlioDx(radice));
  }
  return;
}

void visitaPostOrder(albero radice){

  int temp;

  if(valoreRadice(radice, &temp)){
    visitaPostOrder(figlioSx(radice));
    visitaPostOrder(figlioDx(radice));
    printf("%d ", temp);
  }
  return;
}

int ricercaInABR(albero radice, int key){

  int ret = 0;
  int temp;

  if(valoreRadice(radice, &temp)){
    if(temp == key){
      ret = 1;
    }else if(temp > key){
      ret = ricercaInABR(figlioSx(radice), key);
    }else{
      ret = ricercaInABR(figlioDx(radice), key);
    }
  }

  return ret;
}

void InserisciInABR(albero *radice, int e){

  int temp;
  albero x;

  if(!valoreRadice(*radice, &temp)){
    x = costruisciAlbero(e, NULL, NULL);
    if(x != NULL){
      *radice = x;
  /*}else{
      TODO aggiungi un qualche tipo di gestione dell'errore di memoria non allocata
  */}
  }else if(e < temp){
    InserisciInABR(&((*radice)->sx), e);
  }else if(e > temp){
    InserisciInABR(&((*radice)->dx), e);
  }else{
    printf("Elemento gia' presente\n");
  }

  return;
}

int minimoABR(albero radice){

  int temp, ret = -1;//ritorna -1 se la radice era nulla

  if(valoreRadice(radice, &temp)){

    if(figlioSx(radice) == NULL){
      ret = temp;
    }else{
      ret = minimoABR(figlioSx(radice));
    }
  }

  return ret;
}

void eliminaInABR(albero *radice, int e){

  int temp, minimo;
  albero swap;

  if(valoreRadice(*radice, &temp)){
    if(e < temp){
      eliminaInABR(&((*radice)->sx), e);
    }else if(e > temp){
      eliminaInABR(&((*radice)->dx), e);
    }else{//e == temp
      if(figlioSx(*radice) == NULL && figlioDx(*radice) == NULL){
        *radice = deallocaNodo(*radice);
      }else if(figlioSx(*radice) == NULL){
        swap = *radice;
        *radice = figlioDx(*radice);
        swap = deallocaNodo(swap);
      }else if(figlioDx(*radice) == NULL){
        swap = *radice;
        *radice = figlioSx(*radice);
        swap = deallocaNodo(swap);
      }else{
        minimo = minimoABR(figlioDx(*radice));
        (*radice)->info = minimo;
        eliminaInABR(&((*radice)->dx), minimo);
      }
    }
  }

  return;
}
