#ifndef TAD_PILA_STATIC_STACK_H
#define TAD_PILA_STATIC_STACK_H

#include <stdbool.h>

#define SNULL (-1)
#define SMAX 100 //se define en función del problema

typedef int tItemS; //se define en función del problema
typedef int tPosS;
typedef struct tStack{
    tItemS data[SMAX];
    void **top;
}tStack;

void createEmptyStack(tStack *stack);
bool push(tItemS d, tStack *stack);
void pop(tStack *stack);
tItemS peek(tStack stack);
bool isEmptyStack(tStack stack);

#endif //TAD_PILA_STATIC_STACK_H
