#ifndef VUELO_H_INCLUDED
#define VUELO_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "LinkedList.h"
#include "piloto.h"
typedef struct{
    int idVuelo;
    int idAvion;
    int idPiloto;
    char fecha[20];
    char destino[30];
    int cantPasajeros;
    int horaDespegue;
    int horaLlegada;
} eVuelo;

eVuelo* eVuelo_new();
eVuelo* eVuelo_newParametros(char* idStr,char* idStr2,char*idStr3,char* fecha,char* destino,char* cantPasajeros,char* horaDespegueStr,char* horaLlegadaStr);

void eVuelo_delete(eVuelo* this);

int eVuelo_setFecha(eVuelo* this,char* fecha);
int eVuelo_getFecha(eVuelo* this,char* fecha);

int eVuelo_setDestino(eVuelo* this,char* destino);
int eVuelo_getDestino(eVuelo* this,char* destino);

int eVuelo_setIdAvion(eVuelo* this,int id);
int eVuelo_getIdAvion(eVuelo* this,int* id);

int eVuelo_setIdVuelo(eVuelo* this,int id);
int eVuelo_getIdVuelo(eVuelo* this,int* id);

int eVuelo_setIdPiloto(eVuelo* this,int id);
int eVuelo_getIdPiloto(eVuelo* this,int* id);

int eVuelo_sethoraLlegada(eVuelo* this,int horaLlegada);
int eVuelo_gethoraLlegada(eVuelo* this,int* horaLlegada);

int eVuelo_sethoraDespegue(eVuelo* this,int horaDespegue);
int eVuelo_gethoraDespegue(eVuelo* this,int* horaDespegue);

int eVuelo_setCantPasajeros(eVuelo* this,int cantPasajeros);
int eVuelo_getCantPasajeros(eVuelo* this,int* cantPasajeros);

//para 2 listas
void printVuelo(eVuelo* vuelo,LinkedList* linkedListPilotos);
void printAllVuelos(LinkedList* LinkedListVuelos,LinkedList* LinkedListPilotos);

int getIndexOfVueloById(LinkedList* LinkedListPilotos,int id);
int contarPasajeros(void* pasajeros);

int funcionContarPasajerosIrlanda(void* pElement);

int funcionFiltrarVuelosCortos(void* pElement);

int funcionFiltrarVuelosPortugal(void* pElement);

int funcionFiltrarAlexLifeson(void* pElement);

#endif // VUELO_H_INCLUDED
