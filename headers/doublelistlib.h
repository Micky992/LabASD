#ifndef DOUBLE_LIST_LIB_H
#define DOUBLE_LIST_LIB_H

typedef struct delem delem;

typedef delem* dlista;

void stampaListaDop(dlista top);

dlista newElemDop(int k);

dlista aggiungiInTestaDop(dlista top, int k);

dlista aggiungiInCodaDop(dlista top, int k);

dlista eliminaTopDop(dlista top);

#endif DOUBLE_LIST_LIB_H
