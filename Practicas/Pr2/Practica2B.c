/*
 ============================================================================
 Name        : Practica2B.c
 Author      : Marta Maleno
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "arbolbb.h"

/**
 * Pide un n�mero "tam" al usuario, y
 * crea un fichero binario para escritura con el nombre "nfichero"
 * en que escribe "tam" numeros (unsigned int) aleatorios
 * Se utiliza srand(time(NULL)) para establecer la semilla (de la libreria time.h)
 * y rand()%100 para crear un n�mero aleatorio entre 0 y 99.
 */
void creafichero(char* nfichero){
	FILE *f = fopen(nfichero, "wb"); //permiso de escritura
	if(f==NULL) perror("No se ha podido abrir el fichero");
	else{
		srand(time(NULL));
		unsigned tam = ram()%100;
		unsigned num = 0;
		for(int i=0; i<tam; i++){
			num = rand()%100;
			fwrite(&num,sizeof(unsigned),1,f);
		}
		fclose(f);
	}
	/*
	int tam, i, num;
	printf("Introduce cuantos n�meros quieres generar:\n");
	scanf("%d", &tam);
	//asumimos que tam >0
	srand(time(NULL));
	FILE *f = fopen(nfichero, "wb");
	if(f==NULL){
		perror("Error al crear fichero de n�meros aleatorios");
	}else{
		for(i = 0; i < tam;i++){
			num = rand()%tam;
			fwrite(&num,sizeof(int),1,f);
		}
		fclose(f);
	}*/
}
/**
 * Muestra por pantalla la lista de n�meros (unsigned int) almacenada
 * en el fichero binario "nfichero"
 */
void muestrafichero(char* nfichero){
	FILE *f = fopen(nfichero, "rb");
	if(f == NULL){
		perror("Error al mostrar el fichero");
	}else{
		int num;
		while(fread(&num,sizeof(int), 1, f)){
			printf("%d ", num);
		}
		printf("\n");
		fclose(f);
	}

}

/**
 * Guarda en el arbol "*miarbol" los n�meros almacenados en el fichero binario "nfichero"
 */

void cargaFichero(char* nfichero, T_Arbol* miarbol){
	FILE *f = fopen(nfichero, "rb");  //permiso de lectura
	if (f==NULL) perror("No se ha podido abrir el fichero");
	else{
		unsigned num=0;
		while (fread(&num, sizeof(unsigned),1,f)==1){
			Insertar(miarbol,num);
		}
	}
}

int main(void) {
	char nfichero[50];

	setvbuf(stdout, NULL, _IONBF, 0);

	printf ("Introduce el nombre del fichero binario:\n");
	fflush(stdout);
	scanf ("%s",nfichero);
	fflush(stdin);
	creafichero(nfichero);
	printf("\n Ahora lo leemos y mostramos\n");
	muestrafichero(nfichero);
	fflush(stdout);

	printf ("\n Ahora lo cargamos en el arbol\n");
	T_Arbol miarbol;
	Crear (&miarbol);
	cargaFichero(nfichero,&miarbol);
	printf ("\n Y lo mostramos ordenado\n");
	Mostrar(miarbol);
	fflush(stdout);
	printf("\n Ahora lo guardamos ordenado\n");
	FILE * fich;
	fich = fopen (nfichero, "wb");
	Salvar (miarbol, fich);
	fclose (fich);
	printf("\n Y lo mostramos ordenado\n");
	muestrafichero(nfichero);
	Destruir (&miarbol);

	return EXIT_SUCCESS;
}
