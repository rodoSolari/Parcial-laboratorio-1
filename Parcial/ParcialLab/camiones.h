#ifndef CAMIONES_H_INCLUDED
#define CAMIONES_H_INCLUDED
#define MAX_STRING 20
#define TAM_HARDCODEO 10
#include <string.h>
typedef struct{
    int id;
    char patente[MAX_STRING];
    char marca[MAX_STRING];//{ford ,fiat,wv}
    int anio;
    int peso;
    int cantidadDeRuedas;
    char tipo[MAX_STRING];
   // int idChofer;
}eCamion;

void hardCodearCamiones(eCamion listado[],int tam);
eCamion buscarCamion(eCamion listadoCamiones[],int tam, int id);
void mostrarCamion(eCamion camion);
#endif // CAMIONES_H_INCLUDED
