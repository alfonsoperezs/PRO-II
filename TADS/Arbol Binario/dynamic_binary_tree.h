#ifndef TAD_ARBOL_BINARIO_DYNAMIC_BINARY_TREE_H
#define TAD_ARBOL_BINARIO_DYNAMIC_BINARY_TREE_H

#include <stdbool.h>
#include <stdlib.h>

#define TNULL NULL

typedef char tItemT; //se define en funcion del problema
typedef struct tNodeT *tPosT;
struct tNodeT{
    tItemT data;
    tPosT left;
    tPosT right;
};
typedef tPosT tBinTree;

void createEmptyTree(tBinTree *T);
bool buildTree(tBinTree LTree, tItemT d, tBinTree RTree, tBinTree *T);
tBinTree leftChild(tBinTree T);
tBinTree rightChild(tBinTree T);
tItemT root(tBinTree T);
bool isEmptyTree(tBinTree T);

#endif //TAD_ARBOL_BINARIO_DYNAMIC_BINARY_TREE_H
