#ifndef QUEUELIB_H
#define QUEUELIB_H

queue creaQueue(int dim_max);

void eliminaQueue(queue *Q);

bool queueEmpty(queue Q);

bool queueFull(queue Q);

void enqueue(queue *Q, int da_inserire);

int dequeue(queue *Q);

void stampaQ(queue *Q);

#endif
