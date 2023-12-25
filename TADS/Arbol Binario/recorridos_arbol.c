#include <stdio.h>
#include "dynamic_binary_tree.h" // incluir tad arbol binario
#include "queue.h" // incluir tad cola

void modelTree(tBinTree *T){
    //Crea un árbol modelo para posteriormente probar las funciones de busqueda
    tBinTree leftTree, rightTree, leftNode, rightNode;

    createEmptyTree(&leftNode);
    createEmptyTree(&rightNode);
    //node CLT
    buildTree(TNULL,'L',TNULL,&leftNode);
    buildTree(TNULL,'T',TNULL,&rightNode);
    buildTree(leftNode,'C',rightNode,&leftTree);
    //node FXZ
    buildTree(TNULL,'X',TNULL,&leftNode);
    buildTree(TNULL,'Z',TNULL,&rightNode);
    buildTree(leftNode,'F',rightNode,&rightTree);
    //full tree
    buildTree(leftTree,'A',rightTree,T);
}

//RECORRIDOS EN PROFUNDIDAD
void preorden(tBinTree T){
    if(!isEmptyTree(T)){
        printf("%c ", root(T));
        preorden(leftChild(T));
        preorden(rightChild(T));
    }
}
void inorden(tBinTree T){
    if(!isEmptyTree(T)){
        inorden(leftChild(T));
        printf("%c ", root(T));
        inorden(rightChild(T));
    }
}
void posorden(tBinTree T){
    if(!isEmptyTree(T)){
        posorden(leftChild(T));
        posorden(rightChild(T));
        printf("%c ", root(T));
    }
}

//RECORRIDO EN ANCHURA (necesitamos TAD COLA)
void breath(tBinTree T){
    tQueue queue; //tItemQ = tBinTree
    tBinTree subTree;

    createEmptyQueue(&queue);
    if (!isEmptyTree(T))
        enqueue(T,&queue); //insertamos el árbol en la cola
    while (!isEmptyQueue(queue)){
        //extraemos de la cola el árbol del frente
        subTree = front(queue);
        dequeue(&queue);
        printf("%c ", root(subTree));
        //insertar los subárboles siempre y cuando no estén vacíos
        if(!isEmptyTree(leftChild(subTree)))
            enqueue(leftChild(subTree),&queue);
        if(!isEmptyTree(rightChild(subTree)))
            enqueue(rightChild(subTree),&queue);
    }
}

int main(){
    tBinTree tree;

    createEmptyTree(&tree);
    modelTree(&tree);
    breath(tree);
}
