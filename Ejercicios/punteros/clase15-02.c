/*
 Descripción: Programa con los ejemplos de la clase del día 15-02-2023 
    1. Uso de tipos de datos en scanf y printf
    2. Punteros
*/

#include <stdio.h>
#include <stdlib.h>  //tiene todo lo referente a punteros
#include <string.h>

//   IMPORTANTE:
//para cambiar el valor de una variable global desde una función es necesario referenciar al puntero (*p = (...))

// Función que intercambia los dos valores pasados por parámetro
void intercambiar(int * pa, int * pb){
    int aux = *pa;
    *pa = *pb;
    *pb = aux;
}
int main(){
    /* ------- 1. USO DE TIPOS DE DATOS EN SCANF Y PRINTF-------
    int c[3] = {2,3,4};
    char car;
    char nombre[10];
    printf("%u %u", &c[0], c);
    scanf("%c", &car);
    scanf("%s", nombre);
    printf("hola %s\n", nombre);
    */

    typedef struct Persona Persona;  //sirve para evitar tener que poner struct cada vez que defina una variable
    struct Persona{
        char nombre[20];
        int edad;
    };
    //struct Persona p;  //sería necesario poner struct cada vez que definamos una variable si falta el typedef
    /* 
    Persona p;
    scanf("%s", p.nombre);
    scanf("%d", &p.edad);
    printf("El nombre es %s\n", p.nombre);
    printf("La edad es %d\n", p.edad);
    */

    /*
    Persona listaP[25];
    int l=0;
    printf("Introduce los datos de a lo sumo 25 personas\n");
    
    while (scanf("%d %s", &listaP[l].edad, listaP[l].nombre) !=0){
        l++;
    }
    
    printf("longitud de la lista %d\n", l);
    for (int i=0; i<l; i++){
        printf("Nombre: %s, Edad:%d\n", listaP[i].nombre, listaP[i].edad);
    }
    */

    // -------------- 2. PUNTEROS -------------
    // las variables punteros siempre ocupan 4bytes
    int a = 25;  
    int *pa = &a; 
    char c = 'A';
    char *pc = &c;
    *pa = 8; //cambia el valor de a desde 25 a 8
    /*
    Nombre | Dirección | Valor
    -------|-----------|-------
       a   | 1000-1003 |  8
       pa  | 1004-1007 | 1000
       c   |   1008    | 'A'
       pc  | 1009-1012 | 1008
    */

    int x=18;
    int y=28;
    intercambiar(&x,&y);
    printf("x=%d\ny=%d\n", x, y);

    double *pd;
    pd = (double *)malloc(sizeof(double));
    free(pd);
    return 0;
}