#include <stdio.h>
#include <abrlib.h>

int main (void){

  albero tree = NULL;
  int i;

  InserisciInABR(&tree, 24);
  InserisciInABR(&tree, 28);
  InserisciInABR(&tree, 13);
  InserisciInABR(&tree, 2);
  InserisciInABR(&tree, 17);
  InserisciInABR(&tree, 34);
  InserisciInABR(&tree, 31);
  InserisciInABR(&tree, 4);
  InserisciInABR(&tree, 15);
  InserisciInABR(&tree, 8);

  i = 8;
  printf("Il numero %d%se' presente nell'ABR\n", i, ricercaInABR(tree, i)?" ":" non ");
  i = 16;
  printf("Il numero %d%se' presente nell'ABR\n", i, ricercaInABR(tree, i)?" ":" non ");

  if(valoreRadice(tree, &i)){
    printf("Il valore della radice dell'ABR e' %d\n", i);
  }

  printf("La visita in order dell'ABR e':\n");
  visitaInOrder(tree);
  i = 28;
  eliminaInABR(&tree, i);
  printf("\nDopo aver eliminato %d la visita e'\n", i);
  visitaInOrder(tree);

  i = minimoABR(tree);
  printf("\nIl minimo dell'ABR e' %d\n", i);
  eliminaInABR(&tree, i);
  i = minimoABR(tree);
  printf("Dopo aver eliminato il minimo il nuovo minimo e' %d\n", i);

  return 0;
}
