#include "dynamic_binary_tree.h"

void createEmptyTree(tBinTree *T){
    *T = TNULL;
}
bool isEmptyTree(tBinTree T){
    return (T == TNULL);
}
tBinTree leftChild(tBinTree T){
    return T->left;
}
tBinTree rightChild(tBinTree T){
    return T->right;
}
tItemT root(tBinTree T){
    return T->data;
}
bool createNode(tBinTree *T){
    *T = malloc(sizeof(**T));
    return (*T != TNULL);
}
bool buildTree(tBinTree LTree, tItemT d, tBinTree RTree, tBinTree *T){
    if(!createNode(T))
        return false;
    else{
        (*T)->data = d;
        (*T)->left = LTree;
        (*T)->right = RTree;
        return true;
    }
}