#ifndef TAD_COLA_STATIC_QUEUE_H
#define TAD_COLA_STATIC_QUEUE_H

#include <stdbool.h>

#define QMAX 25 //definir segun el problema

typedef int tItemQ; //definir segun el problema
typedef int tPosQ;
typedef struct queue{
    tItemQ data[QMAX];
    tPosQ front;
    tPosQ rear;
}tQueue;

void createEmptyQueue(tQueue *Q);
bool isEmptyQueue(tQueue Q);
tItemQ front(tQueue Q);
void dequeue(tQueue *Q);
bool enqueue(tItemQ d, tQueue *Q);


#endif //TAD_COLA_STATIC_QUEUE_H
