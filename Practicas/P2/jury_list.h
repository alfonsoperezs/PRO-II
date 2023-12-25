/*
 * TITLE: PROGRAMMING II LABS
 * SUBTITLE: Practical 2
 * AUTHOR 1: Miguel García González
 * AUTHOR 2: Alfonso Pérez Sánchez
 * DATE: 13 / 04 / 2023
 */

#ifndef JURY_LIST_H
#define JURY_LIST_H

#include "types.h"
#include "participant_list.h"

#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define MAX 100
#define NULLJ (-1)

typedef int tPosJ;
typedef struct tItemJ{
    tJuryName juryName;
    tNumVotes totalVoters;
    tNumVotes validVotes;
    tNumVotes nullVotes;
    tListP participantList;
} tItemJ;

typedef struct tListJ{
    tItemJ data[MAX];
    tPosJ lastPos;
} tListJ;

void createEmptyListJ(tListJ *J);
bool isEmptyListJ(tListJ J);
tPosJ firstJ(tListJ J);
tPosJ lastJ(tListJ J);
tPosJ nextJ(tPosJ p, tListJ J);
tPosJ previousJ(tPosJ p, tListJ J);
bool insertItemJ(tItemJ d, tListJ *J);
void deleteAtPositionJ(tPosJ p, tListJ *J);
tItemJ getItemJ(tPosJ p, tListJ J);
void updateItemJ(tItemJ d, tPosJ p, tListJ *J);
tPosJ findItemJ(tJuryName n,tListJ J);

#endif
