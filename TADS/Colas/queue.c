#include "queue.h"


void createEmptyQueue(tQueue *Q){
    Q->front = QNULL;
    Q->rear = QNULL;
}
bool isEmptyQueue(tQueue Q){
    return (Q.front == QNULL);
}
tItemQ front(tQueue Q){
    return (Q.front->item);
}
bool newNode (tPosQ *p){
    *p = malloc(sizeof(struct tNodeQ));
    return (*p != QNULL);
}
bool enqueue(tItemQ d, tQueue *Q){
    tPosQ p;

    if(newNode(&p)){
        p->item = d;
        p->next = QNULL;
        if(Q->front == QNULL){
            Q->front = p;
            Q->rear = p;
        } else{
            Q->rear->next = p;
            Q->rear = p;
        }
        Q->rear = p;
        return true;
    } else
        return false;

}
void dequeue(tQueue *Q){
    tPosQ p = Q->front;

    Q->front = p->next;
    if(Q->front == QNULL)
        Q->rear = QNULL;
    free(p);

}
