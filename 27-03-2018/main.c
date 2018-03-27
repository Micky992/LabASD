#include <stdio.h>
#include <listlib.h>

int main(void){

  int i, num;
  lista uno = NULL;
  lista due = NULL;

  for(i = 0; i < 10; i++){
    printf("metto in prima: ");
    scanf("%d", &num);
    uno = aggiungiInTesta(uno, num);
    printf("metto in seconda: ");
    scanf("%d", &num);
    due = aggiungiInTesta(due, num);
  }

  printf("La lista 1: ");
  stampaLista(uno);
  putchar('\n');
  printf("La lista 2: ");
  stampaLista(due);
  putchar('\n');

  printf("La lista 1 e'%sordinata\n", controllaOrdine(uno)?" ":" non ");
  printf("La lista 2 e'%sordinata\n", controllaOrdine(due)?" ":" non ");

  uno = eliminaRipetizioni(uno);
  due = eliminaRipetizioni(due);

  printf("La lista uno senza ripetizioni: ");
  stampaLista(uno);
  printf("\n");
  printf("La lista due senza ripetizioni: ");
  stampaLista(due);
  printf("\n");

  uno = interleaving(uno, due);//dopo di questo non potro' più utilizzare due
  printf("Interleaving delle due liste: ");
  stampaLista(uno);
  printf("\n");

  return 0;
}
