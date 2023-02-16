/*
* Descripción: Programa referente a la primera práctica de Programación Concurrente.
*              Consiste en implementar las funciones de la librería Lista.h 
* Autora: Marta Maleno Escudero
*/

#include "Lista.h"
#include <stdio.h>
#include <stdlib.h>

//DONE
void crearLista(Lista *l){ //crea una lista vacía
    *l = NULL;
}
int listaVacia(Lista l){ //devuelve 0 sii la lista está vacía
    return l == NULL;
}


//DOING
void insertarLista(Lista *l,int elem){ // inserta el elemento elem en la lista l de forma que quede ordenada de forma creciente
    
    Lista nuevo = (Lista)malloc(sizeof(struct NodoLista));
    if(nuevo==NULL){
        printf("Insertar error  -  no hay memoria\n");
    }
    nuevo->elem = elem;
    Lista actual = *l;
    Lista anterior = NULL;
    //recorro la lista mientras el elemento que trato en actual es mayor que el que voy a insertar
    while(actual != NULL && actual->elem > elem){ 
        anterior = actual;
        actual = actual->sig;
    }
    if (anterior == NULL){
        //inserción en primera posición
        
    } else{
        //inserción intermedia o final
    }
}


//TODO
void recorrerLista(Lista l){ //escribe en la pantalla los elementos de la lista
    //TODO
}
void recorrerListaR(Lista l){
    //TODO
}
void insertarListaR(Lista *l,int elem){
    //TODO
}
int extraerLista(Lista *l,int elem){ // elimina de la lista el elemento elem. Devuelve 1 si se ha podido eliminar y 0, si elem no estaba en la lista.
    //TODO
}
int extraerListaR(Lista *l,int elem){
    //TODO
}
void borrarLista(Lista *l){ //elimina todos los nodos de la lista y la deja vacía
    //TODO
}
void borrarListaR(Lista *l){
    //TODO
}