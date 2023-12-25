/*
 * TITLE: PROGRAMMING II LABS
 * SUBTITLE: Practical 1
 * AUTHOR 1: Miguel García González
 * AUTHOR 2: Alfonso Pérez Sánchez
 * DATE: 03/03/2023
 */

#include "static_list.h"
#include <string.h>

void createEmptyList(tList *L){
    /*
    * Objetivo:Crear una lista vacia.
    * Postcondiciones:La lista queda inicializada y no contiene elementos.
    */

    L->lastPos = LNULL;
}
bool isEmptyList(tList L){
    /*
    * Objetivo:Determina si una lista esta vacía.
    */

    return (L.lastPos == LNULL);
}
tPosL first(tList L){
    /*
    * Objetivo: Devuelve la posicion del primer elemento de la lista.
    * Precondiciones:La lista no esta vacia.
    */


    return 0;
}
tPosL last(tList L){
    /*
    * Objetivo: Devuelve la posicion del ultimo elemento de la lista.
    * Precondiciones:La lista no está vacia.
    */

    return L.lastPos;
}
tPosL next(tPosL p, tList L){
    /*
    * Objetivo:Devuelve la posicion del elemento siguiente al indicado o LNULL en caso de que no haya siguiente.
    * Precondiciones:La posición indicada es una posición valida.
    */

    if(p==L.lastPos) return LNULL;
    else return ++p;
}
tPosL previous(tPosL p, tList L){
    /*
     * Objetivo:Devuelve la posicion del elemento anterior al indicado o LNULL en caso de que no haya anterior.
     * Precondiciones:La posición indicada es una posición valida.
     */

    return (p-1);
}
bool insertItem(tItemL d,tPosL p, tList *L){
    /*
     * Objetivo:Inserta un elemento en la lista antes de la posición indicada. Si la posicion es LNULL se
     añade al final. Devuelve un valor true si el elemento fue insertado, false en caso contrario.
     * Precondiciones:La posicion indicada es una posicion valida en la lista o nula (LNULL).
     * Postcondiciones: Las posiciones de los elementos posteriores a la del elemento añadido pueden haber variado.
     */

    tPosL i;
    if(L->lastPos == MAX-1){
        return false;
    } else{
        L->lastPos++;
        if(p==LNULL){
            L->data[L->lastPos]=d;
        } else{
            for (i=L->lastPos; i>= p+1; --i) L->data[i]=L->data[i-1];
            L->data[p]=d;
        }
        return true;
    }
}
void deleteAtPosition(tPosL p, tList *L){
    /*
     * Objetivo:Borra un elemento de la lista antes de la posición indicada.
     * Precondiciones:La posicion indicada es una poscion valida en la lista o nula (LNULL).
     * Postcondiciones: Las posiciones de los elementos posteriores a la del elemento borrado pueden haber variado.
     */

    tPosL x;

    L->lastPos --;
    for (x=p; x<=L->lastPos ; ++x) {
        L->data[x]=L->data[x+1];
    }
}
tItemL getItem(tPosL p, tList L){
    /*
     * Objetivo: Devuelve el contenido del elemento de la lista indicado.
     * Precondiciones: La posicion es una posicion valida en la lista.
     */

    return L.data[p];
}
void updateItem(tItemL d, tPosL p, tList *L){
    /*
     * Objetivo:Modifica el contenido del elemento indicado.
     * Precondiciones:La posicion es una posicion valida en la lista.
     * Postcondiciones: El orden de los elementos de la lista no se modifica.
     */

    L->data[p] = d;
}
tPosL findItem(tParticipantName n,tList L){
    /*
     * Objetivo: Devuelve la posición del primer elemento de la lista cuyo nombre de participante se corresponda
     * con el indicado (o LNULL si no existe tal elemento).
     */

    tPosL i;
    if(L.lastPos==LNULL) return LNULL;
    else{
        for (i=0;(i<L.lastPos) && (strcmp(L.data[i].participantName,n)!=0); ++i);
        if(strcmp(L.data[i].participantName,n)==0) return i;
        else return LNULL;
    }
}
