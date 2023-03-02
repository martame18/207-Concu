/*
 * Mprocesos.c
 *  Implementación de la librería Mprocesos.h
 *  Created on: 02/03/2023
 *      Author: Marta Maleno
 */
#include <stdlib.h>
#include "Mprocesos.h"

void Crear(LProc *lroundrobin){
    *lroundrobin = NULL;
}

void AnadirProceso(LProc *lroundrobin, int idproc){
    if(*lroundrobin == NULL){
        *lroundrobin = (LProc)malloc(sizeof(struct T_Nodo));
        if(*lroundrobin == NULL){
            perror("...");
        }else{
            (*lroundrobin)->pid = idproc;
            (*lroundrobin)->sig = *lroundrobin;
        }
    }else{
        LProc nuevo = (LProc)malloc(sizeof(struct T_Nodo));
        if(nuevo == NULL){
            perror("...");
        }else{
            nuevo->pid = idproc;
            nuevo->sig = (*lroundrobin)->sig;
            (*lroundrobin)->sig = nuevo;
            (*lroundrobin) = nuevo;
        }
    }
}

void EjecutarProcesos(LProc lroundrobin){
    if(lroundrobin == NULL){
        printf("Lista vacía\n");
    }else{
        LProc actual = lroundrobin->sig;
        do{
            printf("Proceso %d en ejecución\n", actual->pid);
            actual = actual->sig;
        }while(actual != lroundrobin->sig);
    }
}

void EliminarProceso(int id, LProc *lista);

void EscribirFichero (char * nomf, LProc *lista);