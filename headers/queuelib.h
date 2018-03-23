#ifndef QUEUELIB_H
#define QUEUELIB_H

typedef struct queue queue;

queue *creaQueue(int dim_max);

void eliminaQueue(queue *Q);

int queueEmpty(queue *Q);

int queueFull(queue *Q);

void enqueue(queue *Q, int da_inserire);

int dequeue(queue *Q);

void stampaQueue(queue *Q);

#endif
