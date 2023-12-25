#ifndef TAD_LISTA_DYNAMIC_LIST_ORDENADA_H
#define TAD_LISTA_DYNAMIC_LIST_ORDENADA_H

#include <stdbool.h>

#define LNULL NULL //constante que representa posiciones nulas

typedef int tItemL; //se define en funcion del problema
typedef struct tNode *tPosL;
typedef tPosL tList;

typedef struct tNode {
    tItemL data;
    tPosL next;
} tNode;

//GENERADORAS
void createEmptyList(tList* L);
bool insertItem(tItemL d, tList* L);

//MODIFICADORAS
bool copyList(tList L, tList* M);
void updateItem(tItemL d , tPosL p, tList* L);

//DESTRUCTORAS
void deleteAtPosition(tPosL p, tList* L);
void deleteList(tList* L);

//OBSERVADORAS
tPosL findItem(tItemL d, tList L);
bool isEmptyList(tList L);
tItemL getItem(tPosL p, tList L);
tPosL first(tList L) ;
tPosL last(tList L);
tPosL previous(tPosL p, tList L);
tPosL next(tPosL p, tList L);
tPosL findPosition(tList L, tItemL d);

//AUX
bool createNode(tPosL *p);

#endif //TAD_LISTA_DYNAMIC_LIST_ORDENADA_H
