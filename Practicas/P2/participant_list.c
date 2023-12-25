/*
 * TITLE: PROGRAMMING II LABS
 * SUBTITLE: Practical 2
 * AUTHOR 1: Miguel García González
 * AUTHOR 2: Alfonso Pérez Sánchez
 * DATE: 13 / 04 / 2023
 */

#include "participant_list.h"
#include <stdlib.h>
#include <string.h>

void createEmptyListP(tListP *L){
    /*
    * Objetivo:Crear una lista vacia.
    * Postcondiciones:La lista queda inicializada y no contiene elementos.
    */
    *L=NULLP;
}
bool isEmptyListP(tListP L){
    /*
    * Objetivo:Determina si una lista esta vacía.
    */
    return (L==NULLP);
}
tPosP firstP(tListP L){
    /*
    * Objetivo: Devuelve la posicion del primer elemento de la lista.
    * Precondiciones:La lista no esta vacia.
    */
    return L;
}
tPosP lastP(tListP L){
    /*
     * Objetivo: Devuelve la posicion del ultimo elemento de la lista.
     * Precondiciones:La lista no está vacia.
     */
    tPosP p;

    for(p = L; p->next!=NULLP ;p=p->next);
    return p;
}
tPosP nextP(tPosP p, tListP L){
    /*
    * Objetivo:Devuelve la posicion del elemento siguiente al indicado o NULLP en caso de que no haya siguiente.
    * Precondiciones:La posición indicada es una posición valida.
    */
    return p->next;
}
tPosP previousP(tPosP p, tListP L){
    /*
     * Objetivo:Devuelve la posicion del elemento anterior al indicado o NULLP en caso de que no haya anterior.
     * Precondiciones:La posición indicada es una posición valida.
     */
    tPosP q;
    if (p == L) return NULLP;
    else{
        for (q=L ; q->next != p; q=q->next);
        return q;
    }
}
bool createNodeP(tPosP *p){
    //Crea un nuevo nodo y devuelve true si fue creado y false si no fue creado.

    *p = malloc(sizeof(**p));
    return *p != NULLP;
}
tPosP findPositionP(tListP L, tItemP d) {
    tPosP p = L;
    while ((p->next != NULLP) && (strcmp(p->next->data.participantName,d.participantName) < 0))
        p = p->next;
    return p;
}
bool insertItemP(tItemP d, tListP * L) {
    /*
     * Objetivo:Inserta un elemento de forma ordenada en función del campo participantName.
     *          Devuelve un valor true si el elemento fue insertado; false en caso contrario.
     * Postcondiciones: Las posiciones de los elementos de la lista posteriores a la del elemento
     *                  insertado pueden haber variado.
     */
    tPosP p,q;

    if(!createNodeP(&q))
        return false;
    q->data = d;
    q->next = NULLP;
    if(isEmptyListP(*L))
        *L = q;
    else{
        if(strcmp(d.participantName,(*L)->data.participantName) < 0){
            q->next = *L;
            *L = q;
        } else{
            p= findPositionP(*L,d);
            q->next = p->next;
            p->next = q;
        }
    }
    return true;

}
void deleteAtPositionP(tPosP p, tListP *L){
    /*
     * Objetivo:Borra un elemento de la lista antes de la posición indicada.
     * Precondiciones:La posicion indicada es una poscion valida en la lista o nula (NULLP).
     * Postcondiciones: Las posiciones de los elementos posteriores a la del elemento borrado pueden haber variado.
     */
    tPosP q;
    if(p== firstP(*L))
        *L=(*L)->next;
    else {
        if(p->next == NULLP){
            for (q=*L;q->next != p; q=q->next);
            q->next = NULLP;
        } else{
            q = p->next;
            p->data = q->data;
            p->next = q->next;
            p = q;
        }
    }
    free(p);
}
tItemP getItemP(tPosP p, tListP L){
    /*
     * Objetivo: Devuelve el contenido del elemento de la lista indicado.
     * Precondiciones: La posicion es una posicion valida en la lista.
     */
    return p->data;
}
void updateItemP(tItemP d, tPosP p, tListP *L){
    /*
     * Objetivo:Modifica el contenido del elemento indicado.
     * Precondiciones:La posicion es una posicion valida en la lista.
     * Postcondiciones: El orden de los elementos de la lista no se modifica.
     */
    p->data = d;
}
tPosP findItemP(tParticipantName n,tListP L){
    /*
     * Objetivo: Devuelve la posición del primer elemento de la lista cuyo nombre de participante se corresponda
     * con el indicado (o NULLP si no existe tal elemento).
     */
    tPosP p;
    for(p = L; (p != NULLP) && (strcmp(p->data.participantName,n) < 0); p = p -> next);
    if(p != NULLP && strcmp(p->data.participantName,n)==0) {
        return p;
    } else {
        return NULLP;
    }

}
