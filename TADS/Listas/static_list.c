#include "static_list.h"

void createEmptyList(tList* L) {
    L->lastPos = LNULL;
}

bool insertItem(tItemL d, tPosL p, tList* L) {
    if (L->lastPos >= MAX_SIZE-1 || p > L->lastPos+1 || p < 0) {
        return false;
    } else {
        for (int i=L->lastPos; i>=p; i--) {
            L->data[i+1] = L->data[i];
        }
        L->data[p] = d;
        L->lastPos++;
        return true;
    }
}

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
    for (int i=0; i<=L.lastPos; i++) {
        if (L.data[i] == d) {
            return i;
        }
    }
    return LNULL;
}

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
