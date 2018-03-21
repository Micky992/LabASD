#include <stdio.h>
#include <heaplib.h>

void heapify(int albero[], int radice, int dimensione){

  int figlio_sx, figlio_dx, massimo;
  figlio_sx = leftSon(radice);
  figlio_dx = rightSon(radice);

  if(figlio_sx < dimensione && albero[radice] < albero[figlio_sx]){//se il figlio sinistro è presente nell'array ed è maggiore della radice
    massimo = figlio_sx;//figlio_sx diventa candidato a essere nuova radice
  }else{//se non ha figlio sinistro o non è maggiore della radice
    massimo = radice;
  }

  if(figlio_dx < dimensione && albero[massimo] < albero[figlio_dx]){//se figlio destro è presente ed è maggiore del massimo fra radice e sinistro (quindi il massimo fra tutti e tre)
    massimo = figlio_dx;
  }

  if(massimo != radice){//solo se il massimo non è in radice
    swap(albero, radice, massimo);
    heapify(albero, massimo, dimensione);//mandare giù la radice richiede di ripristinare l'heap fra questa e i suoi nuovi figli
  }

  return;
}

int leftSon(int radice){
  return (2 * radice) + 1;
}

int rightSon(int radice){
  return (2 * radice) + 2;
}

void swap(int array[], int elem1, int elem2){

  int temp;

  temp = array[elem1];
  array[elem1] = array[elem2];
  array[elem2] = temp;

  return;
}

void buildHeap(int albero[], int dimensione){
  int i;

  for (i = (dimensione / 2); i >= 0 ; i--){//heapify chiamato su tutti i nodi interni a partire dal basso costruidce l'heap
    heapify(albero, i, dimensione);
  }

  return;
}

void heapSort(int heap[], int dimensione){

  int i;

  for(i = dimensione-1; i>=1; i--){
    swap(heap, 0, i);//porta l'elemento massimo dal primo all'ultimo posto
    dimensione--;//escludi l'ultimo elemento dell'array, nel quale rimane il massimo
    heapify(heap, 0, dimensione);//ripristina l'heap portando il massimo in radice
  }

  return;
}

void riempi(int array[], int dimensione){

  int i;

  for (i = 0; i < dimensione; i++){

    printf("Inserire elemento %d: ", i);
    scanf("%d", array + i);
  }

  return;
}

int eliminaInHeap(int heap[], int target, int *dimensione){

  int i = 0, ret = 0;

  if(target <= heap[0]){//se il numero è maggiore della radice del maxheap non può essere presente nell'heap

    while(i < *dimensione && ret == 0){//cerca il numero nell'heap
      if(heap[i] == target){//se trovi il numero
        heap[i] = heap[*dimensione - 1];//sostituisci ad esso l'ultimo numero dell'heap
        ret = 1;//imposta di aver cancellato il numero
        *dimensione = *dimensione - 1;//diminuisci la dimensione dell'heap, perché ora ha un numero in meno

      }else{//vai avanti finché non trovi il numero o finisci l'array
        i++;
      }
    }

    if(ret){//se avevi eliminato il numero adesso devi ribilanciare l'heap

      if(heap[i] > heap[(i - 1) / 2]){//se il nodo che hai spostato al posto di quello eliminato è maggiore del nuovo padre
        while(i > 0 && heap[i] > heap[(i - 1) / 2]){//lo devi far salire finché non trova il suo posto

          swap(heap, i, (i-1)/2);
          i = (i-1)/2;
        }
      }else{//altrimenti lo devi far scendere
        heapify(heap, i, *dimensione);//e heapify è fatta proprio per quello
      }
    }
  }
  return ret;
}

void stampa(int array[], int dimensione){

  int i;

  for(i = 0; i < dimensione; i++){
    printf("%d ", array[i]);
  }
  printf("\n");

  return;
}
