#include "static_list_ordenada.h"

void createEmptyList(tList* L) {
    L->lastPos = LNULL;
}
bool insertItem(tItemL d, tList* L) {
    tPosL i;
    if(L->lastPos == MAX_SIZE)
        return false;
    else{
        L->lastPos ++;
        for (i = L->lastPos; i>0 && d<L->data[i-1];--i)
            L->data[i] = L->data[i-1];
        L->data[i] = d;
    }
    return true;
} //mas eficiente
bool copyList(tList L, tList* M) {
    if (L.lastPos >= MAX_SIZE) {
        return false;
    } else {
        M->lastPos = L.lastPos;
        for (int i=0; i<=L.lastPos; i++) {
            M->data[i] = L.data[i];
        }
        return true;
    }
}
void updateItem(tItemL d, tPosL p, tList* L) {
    if (p >= 0 && p <= L->lastPos) {
        L->data[p] = d;
    }
}
void deleteAtPosition(tPosL p, tList* L) {
    if (p >= 0 && p <= L->lastPos) {
        for (int i=p; i<L->lastPos; i++) {
            L->data[i] = L->data[i+1];
        }
        L->lastPos--;
    }
}
void deleteList(tList* L) {
    L->lastPos = LNULL;
}
tPosL findItem(tItemL d, tList L) {
    tPosL p;
    if(L.lastPos == LNULL)
        return LNULL;
    else{
        for (p=0;(p<L.lastPos) && (L.data[p]<d); ++p);
        if((p<=L.lastPos) && (L.data[p] == d))
            return p;
        else
            return LNULL;
    }

} //mas eficiente
bool isEmptyList(tList L) {
    return L.lastPos == LNULL;
}
tItemL getItem(tPosL p, tList L) {
    if (p >= 0 && p <= L.lastPos) {
        return L.data[p];
    }
    return -1; // se asume que -1 no es un valor válido en el problema
}
tPosL first(tList L) {
    return 0;
}
tPosL last(tList L) {
    return L.lastPos;
}
tPosL previous(tPosL p, tList L) {
    if (p > 0 && p <= L.lastPos) {
        return p-1;
    }
    return LNULL;
}
tPosL next(tPosL p, tList L) {
    if (p >= 0 && p < L.lastPos) {
        return p+1;
    }
    return LNULL;
}
