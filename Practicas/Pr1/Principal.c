/*
* Descripción: Programa referente a la primera práctica de Programación Concurrente.
*              Consiste en implementar las funciones de la librería Pila.h 
* Autora: Marta Maleno Escudero
*/

#include "Pila.h"
#include <stdio.h>

int main(){
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
}