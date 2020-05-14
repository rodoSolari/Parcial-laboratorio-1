#ifndef CHOFERES_H_INCLUDED
#define CHOFERES_H_INCLUDED
#define TAM_STRING 20
#define TAM_HARDCODEO_CHOFERES 6
#include <string.h>
#include <stdio.h>
#include "camiones.h"
/*1-Tenemos un listado de
Choferes(apellido,dni,legajo,nacionalidad,teléfono,edad,sexo) .
tenemos por ahora 6 choferes pero tengo lugar para 12.
*/
typedef struct{
    int id; //primary key
    char nombre[TAM_STRING];
    char apellido[TAM_STRING];
    int dni;
    int legajo;
    char nacionalidad[TAM_STRING];
    int telefono;
    int edad;
    char sexo;
    int idCamion;
}eChofer;

void hardCodearChoferes(eChofer listado[],int tam);
void mostrarTodosLosChoferes(eChofer listado[], int tamChoferes,eCamion listadoCamiones[], int tamCamiones);
void mostrarUnChofer(eChofer chofer , eCamion arrayCamiones[], int tam);
#endif // CHOFERES_H_INCLUDED
