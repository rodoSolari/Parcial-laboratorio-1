#ifndef CAMIONES_H_INCLUDED
#define CAMIONES_H_INCLUDED
#define TAM_STRING 20
#define TAM_HARDCODEO 10
#include <string.h>
typedef struct{
    int id;
    char patente[TAM_STRING];
    char marca[TAM_STRING];//{ford ,fiat,wv}
    int anio;
    int peso;
    int cantidadDeRuedas;
    char tipo[TAM_STRING];
    int idChofer;
    int estado;
}eCamion;

void mostrarListadoCamiones(eCamion listado[],int tam);
void hardCodearCamiones(eCamion listado[],int tam);
void mostrarCamion(eCamion camion);
eCamion buscarCamion(eCamion listadoCamiones[],int tam, int id);
eCamion cargarCamion();
int buscarPosicionLibre(eCamion listado[],int tam);
int buscarPosicionCamion(eCamion listadoCamiones[],int tam, int id);
void eliminarCamion(eCamion listado[],int tam);

#endif // CAMIONES_H_INCLUDED
