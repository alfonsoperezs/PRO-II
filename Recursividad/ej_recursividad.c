#include "dynamic_list.h"
#include <stdio.h>

//Ejercicio 1: Imprimir el contenido de una lista
void showlist(tList L){
    if(L != LNULL){
        printf("%d ", L->data);
        showlist(L->next);
    } //si intercambio estas dos lineas, la función imprimiría la lista al revés
}

//Ejercicio 2: Imprimir el contenido de una lista. (recursividad por inmersión)
void printAux(tList L, tPosL pos){
    if(pos != LNULL){
        printf("%d ", getItem(pos,L));
        printAux(L, next(pos,L));
    }
}
void printList(tList L){
    if(!isEmptyList(L))
        printAux(L, first(L));
}

//Ejercicio 3: Calcular la división entera entre dos numeros
int division(int num, int den){
    if(num < den){
        return 0;
    } else{
        return 1 + division(num-den,den);
    }
}

//Ejercicio 4: Darle la vuelta a un número entero (int) (723 -> 327)
void printreverse(int numero){
    if(numero/10 == 0){
        printf("%d", numero);
    } else{
        printf("%d", numero % 10);
        printreverse(numero/10);
    }
}

//Ejercicio 5: Dado un vector de nums enteros y un numero, decir el num de veces que aparece ese num en el vector.
int ocurrences(int vector[30], int obj, int i, int j){ //i y j son posiciones
    if(i > j){
        return 0;
    } else{
        if(vector[i] == obj)
            return 1 + ocurrences(vector,obj,i+1,j);
        else
            return ocurrences(vector,obj,i+1,j);
    }
}

//Ejercicio 6: Convertir numero en binario
void binaryConversion(int n){
    if(n/2 == 0){
        printf("%d", n % 2);
    } else{
        binaryConversion(n/2);
        printf("%d", n % 2);
    }
}

//Ejercicio 7: Calcular triangulo de pascal
int pascal(int i, int j){
    if(j == 0 || i == j){
        return 1;
    } else{
        return pascal(i-1,j-1) + pascal(i-1, j);
    }
}

//Ejercicio 8: Dado un string, comprobar si es palindroma
int esPalindroma(char string[30], int i, int j){
    if(i > j){
        return 1;
    } else{
        if(string[i] == string[j])
            return 1 + esPalindroma(string,i+1,j-1);
        else
            return 0;
    }
}





