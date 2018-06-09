#ifndef DOUBLE_LIST_LIB_H
#define DOUBLE_LIST_LIB_H

typedef struct delem delem;

typedef delem* dlista;

void stampaListaDop(dlista top);
/*Stampa la lista doppiamente concatenata.
*/
dlista newElemDop(int k);
/*Crea un nuovo nodo di lista doppiamente concatenata e inserisce l'intero k nel campo info.
*/
dlista precedente(dlista nodo);
/*Prende un puntatore a nodo di una lista doppaimente concatenata e restituisce il puntatore contenuto nell'elemento prev del nodo.
*/
dlista successivo(dlista nodo);
/*restituisce il next del nodo puntato dal puntatore "nodo"*/

int elemento(dlista nodo);
/*restituisce l'elemento contenuto nel nodo*/

dlista aggiungiInTestaDop(dlista top, int k);

dlista aggiungiInCodaDop(dlista top, int k);

dlista eliminaTopDop(dlista top);
/*Elimina il top della lista puntata da "top". Restituisce il nuovo top.
*/
#endif DOUBLE_LIST_LIB_H
