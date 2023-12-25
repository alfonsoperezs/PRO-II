#ifndef TAD_COLA_QUEUE_H
#define TAD_COLA_QUEUE_H

#include <stdbool.h>
#include <stdlib.h>

#define QNULL NULL

typedef int tItemQ; //modificar segun el problema
typedef struct tNodeQ *tPosQ;
struct tNodeQ{
    tItemQ item;
    tPosQ next;
};
typedef struct Queue{
    tPosQ front;
    tPosQ rear;
}tQueue;

void createEmptyQueue(tQueue *Q);
bool enqueue(tItemQ d, tQueue *Q);
void dequeue(tQueue *Q);
tItemQ front(tQueue Q);
bool isEmptyQueue(tQueue Q);
bool newNode (tPosQ *p);

#endif //TAD_COLA_QUEUE_H
