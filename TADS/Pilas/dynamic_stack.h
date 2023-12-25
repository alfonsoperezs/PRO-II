#ifndef TAD_PILA_DYNAMIC_STACK_H
#define TAD_PILA_DYNAMIC_STACK_H

#include <stdbool.h>
#include <stdlib.h>

#define SNULL NULL
#define SMAX 100 //se define en función del problema

typedef int tItemS; //se define en función del problema
typedef struct tNodeS *tPosS;
struct tNodeS{
    tItemS data;
    tPosS next;
};
typedef tPosS tStack;

void createEmptyStack(tStack *stack);
bool push(tItemS d, tStack *stack);
void pop(tStack *stack);
tItemS peek(tStack stack);
bool isEmptyStack(tStack stack);

#endif //TAD_PILA_DYNAMIC_STACK_H
