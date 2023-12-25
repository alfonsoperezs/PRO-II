#ifndef STATIC_LIST_H
#define STATIC_LIST_H

#include <stdbool.h>

#define LNULL (-1)  //constante que representa posiciones nulas
#define MAX_SIZE 1000 //tamaño máximo de la lista

typedef int tItemL; //se define en función del problema
typedef int tPosL;
typedef struct {
    tItemL data[MAX_SIZE];
    int lastPos;
} tList;

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

#endif //STATIC_LIST_H
