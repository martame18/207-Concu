/*
 Descripción: Programa con los ejemplos de la clase del día 01-03-2023 
 1. Ejercicios de punteros
*/
#include <stdio.h>
#include <string.h>  //incluye strcpy

        // ------- 1. EJERCICIOS DE PUNTEROS -------

// Función que muestra un elemento en binario 
    void binario(unsigned char c, int tam){
        if (tam>0){
            binario(c/2, tam-1);
            printf("%u",c%2);
        } else{
            printf("%u",c%2);
        }
    }


int main(){

    // 1. Dadas las siguientes dos definiciones, cuál es correcta: <p=t;> o <t=p;>?
    int t[30];
    int *p;
    // Sol:
    p=t;

    // 2. ¿Tiene sentido una instrucción del tipo &var aparezca a la izquierda de una asignación? 
    // Sol: No

    // 3. ¿Qué imprime el siguiente código?
   char c1 = 'P';
   char c2 = 'Q';
   char *b,*q;
   b = &c1;
   q = &c2;
   *b = *q;
   printf("%c",c1);
    // Sol: Q

    // 4. ¿Es correcto el siguiente código? En caso positivo, ¿qué valor se imprime?
    float f[3];
    float *ctr;
    f[0] = 1.0;
    f[1] = 2.0;
    f[2] = 3.0;
    ctr = f;
    printf("%f",*ctr);
    // Sol: 1.000000

    // 5. Escribe instrucciones C que sucesivamente realicen las siguientes operaciones:
    // - Define e inicializa un puntero a char (str) con la dirección del primer carácter de la cadena "Empezamos una y otra vez"
    char *str = "Empezamos una y otra vez";
    // - Define un puntero a carácter (ptr)
    char *ptr;
    // - Define un array con 28 caracteres
    char a[28];
    // - Copia la dirección de la cadena "Empezamos una y otra vez" en ptr
    ptr = str;
    // - Copia la cadena "Empezamos una y otra vez" en a
    strcpy(a,str);
    // - Copia la dirección de la primera componente de a en str
    str = a;


    // -- Comprobaciones --
    unsigned char m = 25;
    unsigned char n = 37;
    printf("\n"); binario(m, 8); printf(" = m\n");
    m = ~m;  //Cambia todos los 0s por 1s y viceversa
    binario(m, 8); printf(" = ~m\n");
    binario(n, 8); printf(" = n\n");
    binario(m&n, 8); printf(" = m&n\n");
    binario(m|n, 8); printf(" = m|n\n");
    binario(m^n, 8); printf(" = m^n\n");
    binario(n<<3, 8); printf(" = n<<3\n");  // << y >> desplazan a derecha o izquierda (y rellena con 0s)
    binario(n>>2, 8); printf(" = n>>2\n");
    return 0;
}


    // 8. Implementa una función void elimina(char c,char *cadena) que elimina de la cadena de caracteres 'cadena' todas las apariciones del carácter 'c'.
    void elimina(char c, char* cadena){
        // suponemos que cadena es un string
        int i=0;
        int j=0;
        while (cadena[j]!='\0'){
            if (cadena[j]!=c){
                cadena[i] = cadena[j];
                i++;
            }
            j++;
        }
        cadena[i]='\0';
    }

    
