#include "static_queue.h"

tPosQ addOne(tPosQ i){
    if(i==QMAX-1)
        return 0;
    else
        return ++i;
}

void createEmptyQueue(tQueue *Q){
    Q->front = 0;
    Q->rear = QMAX - 1;
}
bool isEmptyQueue(tQueue Q){
    return (Q.front == addOne(Q.rear));
}
tItemQ front(tQueue Q){
    return Q.data[Q.front];
}
void dequeue(tQueue *Q){
    Q->front = addOne(Q->front);
}
bool enqueue(tItemQ d, tQueue *Q){
    if(Q->front == addOne(addOne(Q->rear)))
        return false;
    else{
        Q->rear = addOne(Q->rear);
        Q->data[Q->rear] = d;
        return true;
    }
}