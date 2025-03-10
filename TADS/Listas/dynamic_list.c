#include "dynamic_list.h"
#include <stdlib.h>
#include <stdbool.h>

bool createNode(tPosL *p) {
    *p = (tPosL) malloc(sizeof(tNode));
    return *p != LNULL;
}

void createEmptyList(tList* L) {
    *L = LNULL;
}

bool insertItem(tItemL d, tPosL p, tList* L) {
    tPosL q;
    if (!createNode(&q)) {
        return false;
    }
    q->data = d;
    if (p == LNULL) {
        q->next = *L;
        *L = q;
    } else {
        q->next = p->next;
        p->next = q;
    }
    return true;
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
        } else {
            q->next = r;
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
    if (p == *L) {
        *L = (*L)->next;
    } else {
        tPosL q = *L;
        while (q != LNULL && q->next != p) {
            q = q->next;
        }
        q->next = p->next;
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

tPosL previous(tPosL p, tList L) {
    tPosL q = L;
    while (q != LNULL && q->next != p) {
        q = q->next;
    }
    return q;
}

tPosL next(tPosL p, tList L) {
    return p->next;
}

