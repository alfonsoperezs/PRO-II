/*
 * TITLE: PROGRAMMING II LABS
 * SUBTITLE: Practical 1
 * AUTHOR 1: Miguel García González
 * AUTHOR 2: Alfonso Pérez Sánchez
 * DATE: 03/03/2023
 */

#ifndef STATIC_LIST_H
#define STATIC_LIST_H

#include "types.h"
#include <stdbool.h>

#define MAX 25
#define LNULL (-1)

typedef int tPosL;
typedef struct tList{
    tItemL data[MAX];
    tPosL lastPos;
} tList;

void createEmptyList(tList *L);
bool isEmptyList(tList L);
tPosL first(tList L);
tPosL last(tList L);
tPosL next(tPosL p, tList L);
tPosL previous(tPosL p, tList L);
bool insertItem(tItemL d,tPosL p, tList *L);
void deleteAtPosition(tPosL p, tList *L);
tItemL getItem(tPosL p, tList L);
void updateItem(tItemL d, tPosL p, tList *L);
tPosL findItem(tParticipantName n,tList L);

#endif
