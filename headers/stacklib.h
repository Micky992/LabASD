#ifndef STACKLIB_H
#define STACKLIB_H

stack *creaStack(int dim_max);

void eliminaStack(stack *S);

bool stackEmpty(stack *S);

bool stackFull(stack *S);

void push(stack *S, int da_inserire);

int pop(stack *S);

void stampaStack(stack *S);

#endif
