#include <stdio.h>
#include <queuelib.h>
#include <stacklib.h>
#define ERR "Qualcosa e' andato storto\n"

int main(void){

  int scelta, stackoda = 0, temp;
  stack *stackPtr = NULL;
  queue *codaPtr = NULL;

  while (1){
    printf("Esercizio su stack e code.\nScegliere l'operazione da effettuare.\n");
    printf("1 = Crea stack e coda\n");
    if(stackoda){
      printf("2 = push\n3 = enqueue\n4 = pop\n5 = dequeue\n");
      printf("6 = stampa stack\n7 = stampa coda\n");
    }
    scanf("%d", &scelta);

    switch (scelta) {
      case 1:
        printf("Inserire la dimensione dello stack.\n");
        scanf("%d", &temp);
        eliminaStack(stackPtr);
        stackPtr = creaStack(temp);
        printf("Inserire la dimensione della coda.\n");
        scanf("%d", &temp);
        eliminaQueue(codaPtr);
        codaPtr = creaQueue(temp);
        stackoda = 1;
        break;
      case 2:
        if(stackoda){
          printf("Inserire valore da pushare sullo stack.\n");
          scanf("%d", &temp);
          push(stackPtr, temp);
        }else printf(ERR);
        break;
      case 3:
          if(stackoda){
            printf("Inserire valore da accodare.\n");
            scanf("%d", &temp);
            enqueue(codaPtr, temp);
          }else printf(ERR);
        break;
      case 4:
        if(stackoda)
        {
          temp = pop(stackPtr);
          printf("Poppato valore %d dallo stack.\n", temp);
        }else printf(ERR);
        break;
      case 5:
        if(stackoda){
            temp = dequeue(codaPtr);
            printf("Preso valore %d dalla coda\n", temp);
          }else printf (ERR);
        break;
      case 6:
        if(stackoda){
          printf("stack: ");
          stampaStack(stackPtr);
          printf("\n");
        }else printf(ERR);
        break;
      case 7:
        if(stackoda){
          printf("Coda: ");
          stampaQueue(codaPtr);
      }else printf(ERR);
        break;
      default:
        printf(ERR);
    }
  }

return 0;
}
