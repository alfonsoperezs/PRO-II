#include "dynamic_stack.h"

bool createNode(tPosS *p) {
    *p = malloc(sizeof(struct tNodeS));
    return (*p != SNULL);
}

void createEmptyStack(tStack *stack){
    *stack = SNULL;
}
bool push(tItemS d, tStack *stack){
    tPosS aux;

    if(!createNode(&aux))
        return false;
    else{
        aux->data = d;
        aux->next = *stack;
        *stack = aux;
        return true;
    }
}
void pop(tStack *stack){
    tPosS aux;

    aux = *stack;
    *stack = (*stack)->next;
    free(aux);

}
tItemS peek(tStack stack){
    return (stack->data);
}
bool isEmptyStack(tStack stack){
    return (stack == SNULL);
}

