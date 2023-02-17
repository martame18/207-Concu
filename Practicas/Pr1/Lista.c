/*
* Descripción: Programa referente a la primera práctica de Programación Concurrente.
*              Consiste en implementar las funciones de la librería Lista.h 
* Autora: Marta Maleno Escudero
*/

#include "Lista.h"
#include <stdio.h>
#include <stdlib.h>

// --- DONE ---
void crearLista(Lista *l){ //crea una lista vacía
    *l = NULL;
}
int listaVacia(Lista l){ //devuelve 0 sii la lista está vacía
    return l == NULL;
}
void insertarLista(Lista *l,int elem){ // inserta el elemento elem en la lista l de forma que quede ordenada de forma creciente
    
    Lista nuevo = (Lista)malloc(sizeof(struct NodoLista));
    if(nuevo==NULL){
        printf("Insertar error  -  no hay memoria\n");
    }
    nuevo->elem = elem;
    Lista actual = *l;
    Lista anterior = NULL;
    //recorro la lista mientras el elemento que trato en actual es mayor que el que voy a insertar
    //acaba si ya he recorrido toda la lista o si ya he encontrado el hueco donde va el elemento
    while(actual != NULL && actual->elem < elem){ 
        anterior = actual;
        actual = actual->sig;
    }
    //Una vez encontrada la posición en la que va el elemento pongo detrás todo lo que sea mayor
    nuevo->sig = actual;
    if (anterior == NULL){
        //inserción en primera posición (es el elemento más pequeño)
        *l = nuevo;
    } else{
        //inserción intermedia o final
        anterior->sig = nuevo;
    }
}
void recorrerLista(Lista l){ //escribe en la pantalla los elementos de la lista
    if(l == NULL) printf("La lista está vacía");
    else{
        Lista aux = l;
        while(aux != NULL){
            printf("%d ", aux->elem);
            aux = aux->sig;
        }
    }
    printf("\n");
}
void recorrerListaR(Lista l){
    Lista aux = l;
    if(aux != NULL){
        printf("%d ", l->elem);
        recorrerListaR(aux->sig);
    }
    printf("\n");
}
int extraerLista(Lista *l,int elem){ // elimina de la lista el elemento elem. Devuelve 1 si se ha podido eliminar y 0, si elem no estaba en la lista.
    // la función devuelve 0 si el elemento no está en la lista y 1 en caso contrario, después de extraerlo
    Lista act = *l;
    Lista ant = NULL;

    //Buscamos la posición en la que debería estar el elemento
    while(act != NULL && act->elem < elem){
        ant = act;
        act = act->sig;
    }

    if(act == NULL || act->elem > elem){
        //Si la lista está vacía, recorremos toda la lista o si 
        //el elemento actual es mayor que el que buscamos.
        //Por tanto el elem no está.
        return 0;
    }else{      
        if(ant == NULL){
            //Este es el caso en el que extraemos el primer elemento,
            //por esa razón tenemos que asignar una nueva primera dirección
            //de la lista al puntero
            *l = act->sig;
        }else{
            ant->sig = act->sig;
        }

        //Liberamos el espacio en memoria de elem y devolvemos 1 porque el 
        //elem estaba en la lista.
        free(act);
        return 1;
    }
}
void borrarLista(Lista *l){ //elimina todos los nodos de la lista y la deja vacía
    Lista act;
    while(*l != NULL){
        act = *l;
        *l = act->sig;
        free(act);
    }
}


// --- TODO ---
void borrarListaR(Lista *l){
    //TODO
}
void insertarListaR(Lista *l,int elem){
    //TODO
}
int extraerListaR(Lista *l,int elem){
    //TODO
    return 0;
}
