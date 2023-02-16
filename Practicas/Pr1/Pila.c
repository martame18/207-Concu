/*
* Descripción: Programa referente a la primera práctica de Programación Concurrente.
*              Consiste en implementar las funciones de la librería Pila.h 
* Autora: Marta Maleno Escudero
*/

#include "Pila.h"
#include <stdio.h>
#include <stdlib.h>

void crear(Pila *p){
    *p = NULL;
}
void mostrar(Pila p){
    printf("Pila: [ ");
    while (p!=NULL){
        printf("%d ",p->valor);
        p = p->sig;
    }
    printf("]\n");
}
int pilaVacia(Pila p){
    return p == NULL;
}
void insertar(Pila *p, int v){
    // malloc sirve para reservar memoria:
    //     el primer parámetro es un casting porque malloc devuelve void
    //     el segundo parámetro indica la cantidad de memoria que tiene que reservar
    Pila nuevo = (Pila)malloc(sizeof(struct Nodo));  
    if (nuevo == NULL){
        printf("Error en insertar - memoria insuficiente");
        return;
    } 
    nuevo->valor = v;
    nuevo->sig = *p;
    *p = nuevo;
}
int extraer(Pila *p){
    if (*p!=NULL){
        int valor = (*p)->valor;
        Pila aux = *p;
        *p = (*p)->sig;
        free(aux);
        return valor;
    }else{
        printf ("No se puede extraer de la pila vacía\n");
        return -1;
    }
}
void borrar(Pila *p){
    while(!pilaVacia(*p)){
        extraer(p);
    }
}
