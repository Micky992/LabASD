#include <stdio.h>
#include <heaplib.h>
#define MAX 100
#define ERR_WRONGCOMM "Comando non disponibile.\n"


int main()
{
  int scelta, array[MAX] = {0}, dimensione = 0, heapato = 0;
  int daEliminare;//ha il solo scopo di conservare il valore da inviare alla funzione eliminaInHeap

  do{
    printf("Effettuare una scelta.\n");
    printf("1 = riempire l'array\n");
    printf("2 = stampare l'array\n");
    if (!heapato){
      printf("3 = costruire l'heap\n");
    }
    if (heapato){
      printf("4 = heapsort\n");
      printf("5 = elimina un elemento nell'heap\n");
    }

    scanf("%d", &scelta);
    printf("\n");

    if(ferror(stdin) || feof(stdin)){
      printf("Errore in lettura\n");
      clearerr(stdin);
    }else{

      switch(scelta){

        case 1:
          do{
            if(dimensione>100) printf("Troppo grande.\n");
            printf("Scegliere la dimensione dell'array. (Massimo 100.)\n");
            scanf("%d", &dimensione);
          }while(dimensione>100);
          riempi(array, dimensione);
          heapato = 0;
          printf("\n");
          break;
        case 2:
          printf("array: ");
          stampa(array, dimensione);
          printf("\n");
          break;
        case 3:
          if(!heapato){
            buildHeap(array, dimensione);
            heapato = 1;
          }else{
            printf(ERR_WRONGCOMM);
            printf("\n");
          }
          break;
        case 4:
          if(heapato){
            heapSort(array, dimensione);
            heapato = 0;
          }else{
            printf(ERR_WRONGCOMM);
            printf("\n");
          }
          break;
        case 5:
          if(heapato){
            printf("inserire l'intero da eliminare\n");
            scanf("%d", &daEliminare);

            if(eliminaInHeap(array, daEliminare, &dimensione)){
              printf("Eliminazione effettuata\n");
            }else{
              printf("Elemento non presente\n");
            }
          }else{
            printf(ERR_WRONGCOMM);
          }
          printf("\n");
          break;
        case 42:
          printf("achievement unlocked: Easter egg\n");
          printf("\n");
          break;
        default:
          printf(ERR_WRONGCOMM);
          printf("\n");
          break;
      }
    }
  }while(1);

  return 0;
}
