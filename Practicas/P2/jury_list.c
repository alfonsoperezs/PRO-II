/*
 * TITLE: PROGRAMMING II LABS
 * SUBTITLE: Practical 2
 * AUTHOR 1: Miguel García González
 * AUTHOR 2: Alfonso Pérez Sánchez
 * DATE: 13 / 04 / 2023
 */

#include "jury_list.h"
#include "participant_list.h"

void createEmptyListJ(tListJ *J){
    /*
    * Objetivo:Crear una lista vacia.
    * Postcondiciones:La lista queda inicializada y no contiene elementos.
    */

    J->lastPos = NULLJ;
}
bool isEmptyListJ(tListJ J){
    /*
    * Objetivo:Determina si una lista esta vacía.
    */

    return (J.lastPos == NULLJ);
}
tPosJ firstJ(tListJ J){
    /*
    * Objetivo: Devuelve la posicion del primer elemento de la lista.
    * Precondiciones:La lista no esta vacia.
    */


    return 0;
}
tPosJ lastJ(tListJ J){
    /*
    * Objetivo: Devuelve la posicion del ultimo elemento de la lista.
    * Precondiciones:La lista no está vacia.
    */

    return J.lastPos;
}
tPosJ nextJ(tPosJ p, tListJ J){
    /*
    * Objetivo:Devuelve la posicion del elemento siguiente al indicado o LNULL en caso de que no haya siguiente.
    * Precondiciones:La posición indicada es una posición valida.
    */

    if(p==J.lastPos) return NULLJ;
    else return ++p;
}
tPosJ previousJ(tPosJ p, tListJ J){
    /*
     * Objetivo:Devuelve la posicion del elemento anterior al indicado o LNULL en caso de que no haya anterior.
     * Precondiciones:La posición indicada es una posición valida.
     */

    return (p-1);
}
bool insertItemJ(tItemJ d, tListJ *J){
 /*
     * Objetivo:Inserta un elemento en la lista antes de la posición indicada. Si la posicion es LNULL se
     añade al final. Devuelve un valor true si el elemento fue insertado, false en caso contrario.
     * Precondiciones:La posicion indicada es una posicion valida en la lista o nula (LNULL).
     * Postcondiciones: Las posiciones de los elementos posteriores a la del elemento añadido pueden haber variado.
     */
    tPosJ i;
    if(J->lastPos == MAX-1){
        return false;
    }

    else{
        if(J->lastPos==NULLJ || strcmp(d.juryName, J->data[J->lastPos].juryName) > 0)
        {
            J->lastPos++;
            J->data[J->lastPos] = d;

        }
        else
        {
            for(i=0;(i <= J->lastPos) && (strcmp(d.juryName, J->data[i].juryName) > 0);i++);
            J->lastPos++;
            for (tPosJ x=J->lastPos; x>i; x--){
                J->data[x] = J->data[x-1];
            }
            J->data[i] = d;

        }
        return true;
    }
}

void deleteAtPositionJ(tPosJ p, tListJ *J){
    /*
     * Objetivo:Borra un elemento de la lista antes de la posición indicada.
     * Precondiciones:La posicion indicada es una poscion valida en la lista o nula (LNULL).
     * Postcondiciones: Las posiciones de los elementos posteriores a la del elemento borrado pueden haber variado.
     */
    tPosJ x;

    for (x=p; x<=J->lastPos ; ++x) {
        J->data[x]=J->data[x+1];
    }
    J->lastPos --;

}
tItemJ getItemJ(tPosJ p, tListJ L){
    /*
     * Objetivo: Devuelve el contenido del elemento de la lista indicado.
     * Precondiciones: La posicion es una posicion valida en la lista.
     */

    return L.data[p];
}
void updateItemJ(tItemJ d, tPosJ p, tListJ *J){
    /*
     * Objetivo:Modifica el contenido del elemento indicado.
     * Precondiciones:La posicion es una posicion valida en la lista.
     * Postcondiciones: El orden de los elementos de la lista no se modifica.
     */

    J->data[p] = d;
}
tPosJ findItemJ(tJuryName n,tListJ J){
    /*
     * Objetivo: Devuelve la posición del primer elemento de la lista cuyo nombre de participante se corresponda
     * con el indicado (o LNULL si no existe tal elemento).
     */

    tPosJ i;
    if(J.lastPos==NULLJ) return NULLJ;
    else{
        for (i=0;(i<J.lastPos) && (strcmp(J.data[i].juryName,n)!=0); ++i);
        if(strcmp(J.data[i].juryName,n)==0) return i;
        else return NULLJ;
    }
}
