/*
 Descripción: Programa con los ejemplos de la clase del día 10-02-2023 
 Tipos de datos
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_VALUE 10 //Esto cambia el valor de MAX_VALUE para todo el código, no es una variable localizada en el código

int main(){
int array[] = {1,2,3};
int matrix[4][4] = {{1,2}, {3,4}, {5,6}};

//Cadenas de caracteres
char string1[9] = "Caracola"; // "Caracola" tiene longitud 9 (8+ '\0)

//scanf("%d", &var)
 scanf("%s", &string1[0]);
 scanf("%s", string1);
 printf("Longitud de string2 con strlen: %lu\n", strlen(string1));

typedef struct SPersona{
    char nombre[20];
    char apellido[20];
    int telefono;
} Persona;

Persona p1={"Marta", "Maleno", 651397};
strcpy(p1.nombre, "Salva"); //strcpy sirve para darle un valor a la primera variable
}

// la union sirve para almacenar datos de diferentes tipos en la misma localización de memoria
// sirve para optimizar el uso de la memoria cuando no se necesitan almacenar todos los datos a la vez
union Data{
    int i;
    float f;
    char str[20];
} data;

enum panas { Salva, Sara, Adri, Manu, Marta, Lucia, Sergio };