#ifndef PILOTO_H_INCLUDED
#define PILOTO_H_INCLUDED
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"

typedef struct{
    int idPiloto;
    char nombre[30];
} ePiloto;

void hardCodearDatosListaPilotos(LinkedList* linkedListPilotos);

ePiloto* ePiloto_new();

ePiloto* ePiloto_newParametros(char* idStr,char* nombreStr);

void ePiloto_delete(ePiloto* this);

int ePiloto_setNombre(ePiloto* this,char* nombre);
int ePiloto_getNombre(ePiloto* this,char* nombre);

int ePiloto_setIdPiloto(ePiloto* this,int id);
int ePiloto_getIdPiloto(ePiloto* this,int* id);

int funcionFiltrarVuelosSinPiloto(void* pElement,char cadena[]);
int funcionFiltrarVuelosPiloto(void* pElement,char cadena[]);

int getIndexOfPilotoByName(LinkedList* LinkedListPilotos,char* nombre);
//char* getIndexOfPilotoByName(LinkedList* LinkedListPilotos,char* cadena);

#endif // PILOTO_H_INCLUDED
