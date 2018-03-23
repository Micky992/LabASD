#ifndef STACKLIB_H
#define STACKLIB_H

typedef struct stack stack;

stack *creaStack(int dim_max);

void eliminaStack(stack *S);

int stackEmpty(stack *S);

int stackFull(stack *S);

void push(stack *S, int da_inserire);

int pop(stack *S);

void stampaStack(stack *S);

#endif
