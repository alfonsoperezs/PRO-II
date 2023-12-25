#include "dynamic_list_double.h"
#include <stdlib.h>
#include <stdbool.h>

bool createNode(tPosL *p) {
    *p = (tPosL) malloc(sizeof(tNode));
    return *p != LNULL;
}
void createEmptyList(tList* L) {
    *L = LNULL;
}
bool insertItem(tItemL d, tPosL p, tList* L){
    tPosL q,r;

    if(!createNode(&q)) return false;
    else{
        q->data=d;
        q->next=LNULL;
        q->prev=LNULL;
        if(*L == LNULL) *L = q;
        else{
            if(p==LNULL){
                for(r=*L; r->next != LNULL; r= r->next);
                r->next = q;
                q->prev=r;
            }else if(p==*L){
                q->next=*L;
                (*L)->prev=q;
                (*L)=q;
                q->next=p;
                p->prev=q;
            }else{
                q->data= p->data;
                p->data=d;
                if(p->next!=LNULL) p->next->prev =q;
                q->next = p->next;
                p->next = q;
                q->prev = p;
            }
        }
        return true;
    }
}
bool copyList(tList L, tList* M) {
    tPosL p = L;
    tPosL q = LNULL;
    while (p != LNULL) {
        tPosL r;
        if (!createNode(&r)) {
            deleteList(M);
            return false;
        }
        r->data = p->data;
        r->next = LNULL;
        if (q == LNULL) {
            *M = r;
            r->prev = LNULL;
        } else {
            q->next = r;
            r->prev = q;
        }
        q = r;
        p = p->next;
    }
    return true;
}
void updateItem(tItemL d , tPosL p, tList* L) {
    p->data = d;
}
void deleteAtPosition(tPosL p, tList* L) {
    tPosL q;
    if (p == *L) {
        *L = (*L)->next;
        if (*L != LNULL)
            (*L)->prev = LNULL;
    } else {
        q = p->prev;
        q->next = p->next;
        if (p->next != LNULL)
            p->next->prev = q;
    }
    free(p);
}
void deleteList(tList* L) {
    while (*L != LNULL) {
        tPosL p = *L;
        *L = (*L)->next;
        free(p);
    }
}
tPosL findItem(tItemL d, tList L) {
    tPosL p = L;
    while (p != LNULL && p->data != d) {
        p = p->next;
    }
    return p;
}
bool isEmptyList(tList L) {
    return L == LNULL;
}
tItemL getItem(tPosL p, tList L) {
    return p->data;
}
tPosL first(tList L) {
    return L;
}
tPosL last(tList L) {
    tPosL p = L;
    while (p != LNULL && p->next != LNULL) {
        p = p->next;
    }
    return p;
}
tPosL previous(tPosL p, tList L){
    return p->prev;
}
tPosL next(tPosL p, tList L) {
    return p->next;
}
