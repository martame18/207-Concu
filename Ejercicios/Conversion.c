/*
* Descripción: Programa de ejemplo para ver las variables de conversión
*/

#include <stdio.h>
#include <stdlib.h>

int main(void){
    int s = 10;
    printf("El valor de la variable de s es = %d\n", s);

    char cadena[10] = "hola";
    printf("El valor de cadena es = %s\n", cadena);
    
    return EXIT_SUCCESS; //Definida en stdlib.h
}