#ifndef CHOFERES_H_INCLUDED
#define CHOFERES_H_INCLUDED
#define TAM_STRING 20
#define TAM_HARDCODEO_CHOFERES 6
#define TAM_DNI 10
#define TAM_TELEFONO 10
#define MAX_CHOFERES 18
#include <string.h>
#include <stdio.h>
#include "camiones.h"
#define OCUPADO 1
#define LIBRE 0
/*1-Tenemos un listado de
Choferes(apellido,dni,legajo,nacionalidad,teléfono,edad,sexo) .
tenemos por ahora 6 choferes pero tengo lugar para 12.
*/
typedef struct{
    int id; //primary key
    char nombre[TAM_STRING];
    char apellido[TAM_STRING];
    //char dni[TAM_DNI];
    long dni;
    int legajo;
    char nacionalidad[TAM_STRING];
    //char telefono[TAM_TELEFONO];
    long telefono;
    int edad;
    char sexo;
    int estado;
}eChofer;

void inicializarListadoChoferes(eChofer listado[],int tam);
void hardCodearChoferes(eChofer listado[],int tam);
void mostrarListadoChoferes(eChofer listado[], int tam);
void mostrarUnChofer(eChofer chofer);
int buscarPosicionChofer(eChofer listado[],int tam, int id);
int buscarPosicionLibreChofer(eChofer listado[],int tam);
void modificarChofer(eChofer listado[],int tam);
void calcularPromedioEdad(eChofer listado[],int tam);
void calcularPromedioVaronesMujeres(eChofer listado[],int tam);
void cargarChofer(eChofer listado[],int tam);
#endif // CHOFERES_H_INCLUDED
