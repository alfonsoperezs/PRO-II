/*
 * TITLE: PROGRAMMING II LABS
 * SUBTITLE: Practical 2
 * AUTHOR 1: Miguel García González
 * AUTHOR 2: Alfonso Pérez Sánchez
 * DATE: 13 / 04 / 2023
 */

#ifndef PARTICIPANT_LIST_H
#define PARTICIPANT_LIST_H

#include "types.h"
#include <stdbool.h>

#define NULLP NULL

typedef struct tNode * tPosP;
typedef tPosP tListP;
typedef struct tItemP {
    tParticipantName participantName;
    tNumVotes numVotes;
    tEUParticipant EUParticipant;
} tItemP;
struct tNode{
    tItemP data;
    tPosP next;
};

void createEmptyListP(tListP *L);
bool isEmptyListP(tListP L);
tPosP firstP(tListP L);
tPosP lastP(tListP L);
tPosP nextP(tPosP p, tListP L);
tPosP previousP(tPosP p, tListP L);
bool insertItemP(tItemP d, tListP *L);
void deleteAtPositionP(tPosP p, tListP *L);
tItemP getItemP(tPosP p, tListP L);
void updateItemP(tItemP d, tPosP p, tListP *L);
tPosP findItemP(tParticipantName n,tListP L);
tPosP findPositionP(tListP L, tItemP d);


#endif
