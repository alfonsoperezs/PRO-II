#ifndef DYNAMIC_LIST_DOUBLE_H
#define DYNAMIC_LIST_DOUBLE_H

#include <stdbool.h>

#define LNULL NULL //constante que representa posiciones nulas

typedef int tItemL; //se define en funcion del problema
typedef struct tNode *tPosL;
typedef tPosL tList;

typedef struct tNode {
    tItemL data;
    tPosL next;
    tPosL prev;
} tNode;

//GENERADORAS
void createEmptyList(tList* L);
bool insertItem(tItemL d, tPosL p, tList* L);

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

//AUX
bool createNode(tPosL *p);

#endif //DYNAMIC_LIST_DOUBLE_H
