/*
* Descripción: Programa referente a la primera práctica de Programación Concurrente.
*              Consiste en implementar las funciones de la librería Pila.h 
* Autora: Marta Maleno Escudero
*/

#include "Pila.h"
#include "Lista.h"
#include <stdio.h>

int main(){
    /* --- Comprobación de Pila.c ---
    Pila p1;
    crear(&p1);

    printf("Mostrando pila vacia:\n");
    mostrar(p1);

    insertar(&p1,1);
    insertar(&p1,3);
    insertar(&p1,7);
    insertar(&p1,2);
    mostrar(p1);

    int valor = extraer(&p1);
    printf("Pila despues de extraer el %d\n", valor);
    mostrar(p1);

    borrar(&p1);
    printf("Borrando pila ...\n");
    mostrar(p1);
    */
    
    // --- Comprobación de Lista.c ---
    Lista l1;
    crearLista(&l1);

    printf("Mostrando lista vacia:\n");
    recorrerLista(l1);
    insertarLista(&l1,1);
    insertarLista(&l1,3);
    insertarLista(&l1,7);
    insertarLista(&l1,2);
    recorrerLista(l1);
    borrarListaR(&l1);
    recorrerLista(l1);

    // --- Explicación hiper chula de punteros ---
    /*
    Para cambiar el valor de un puntero (la dirección a la que apunta):
        - al inicializarlo (ej: int *p = direccion)
        - sin el asterisco (ej: p = direccion)

    Para cambiar el valor de la variable a la que apunta el puntero:
        - con el asterisco (ej: *p = valor)

    int c = 0;
    int *p = &c;
    printf("%d\n", *p);
    printf("%p\n", p);
    int a = 5;
    *p = a;
    printf("%d\n", *p);
    printf("%p\n", p);
    int matriz[5] = {1,2,3,4,5};
    int *pm = &matriz[0];
    printf("%d\n", *pm);
    pm++;
    printf("%d\n", *pm);
    
    */
}