#include "static_stack.h"

void createEmptyStack(tStack *stack){
    /*
     * Objetivo: Crea una pila vacia
     * Salida: Una pila vaciaa
     * Poscondicion: La pila sin datos
     */
    stack->top = SNULL;
}
bool push(tItemS d, tStack *stack){
    /*
     * Objetivo: Mete un elemento en la pila quedando en la cima
     * Entrada: Item: Contenido del elemento a meter; Stack: Pila donde vamos a meter
     * Salida: Stack: Pila con el elemento Item en la cima y verdadero si se ha podido meter, falso en caso contrario
     */
    if(stack->top == SMAX - 1)
        return false;
    else{
        stack->top ++;
        stack->data[stack->top] = d;
        return true;
    }
}
void pop(tStack *stack){
    /*
     * Objetivo: Saca el elemento de la cima de la pila
     * Entrada: Stack: Pila de donde vamos a sacar
     * Salida: Stack: Pila sin el elemento de su cima
     * Precondicion: La pila no esta vacia
     */
    stack->top --;
}
tItemS peek(tStack stack){
    /*
     * Objetivo: Recupera el contenido del elemento de la cima de la pila
     * Entrada: Stack: Pila donde obtener el dato
     * Salida: Item: Contenido del elemento de la cima de la pila
     * Precondicion: La pila no esta vacia
     */
    return (stack.data[stack.top]);
}
bool isEmptyStack(tStack stack){
    /*
     * Objetivo: Determina si una pila esta vacia
     * Entrada: Stack: Pila a comprobar
     * Salida: Verdadero si la pila esta vacia, falso en caso contrario
     */
    return (stack.top == SNULL);
}