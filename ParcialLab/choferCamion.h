#ifndef CHOFERCAMION_H_INCLUDED
#define CHOFERCAMION_H_INCLUDED
#define TAM_TIPOS 2
#include "choferes.h"
#include "funcionesParaValidarDatos.h"

typedef struct{
    int idChofer;
    int cantidadCamiones;

}eCamionesPorChofer;

void imprimirMenu();

void eliminarChoferConCamiones(eChofer listadoChoferes[],int tamChoferes,eCamion listadoCamiones[],int tamCamiones);


void mostrarChoferesPorTipoCamion(eChofer listadoChoferes[],int tamChoferes,eCamion listadoCamiones[],int tamCamiones, int tamTipos);


void mostrarChoferesConMasDeUnCamion(eChofer listadoChoferes[],int tamChoferes,eCamion listadoCamiones[],int tamCamiones);


void listarCamionesConDiezAniosAntiguedad(eChofer listadoChoferes[],int tamChoferes,eCamion listadoCamiones[],int tamCamiones);


void ordenarChoferesPorCantidadDeCamiones(eChofer listadoChoferes[],int tamChoferes,eCamion listadoCamiones[],int tamCamiones);


void ordenarChoferesPorCantidadDeCamionesNombre(eChofer listadoChoferes[],int tamChoferes,eCamion listadoCamiones[],int tamCamiones);

/*Agrega en un listado aparte el id del chofer con la cantidad de camiones que conduce*/
void contarCamionesPorChofer(eCamionesPorChofer auxCamionesPorChofer[],eChofer listadoChoferes[],int tamChoferes,eCamion listadoCamiones[],int tamCamiones);

/**/
void mostrarChoferesConCantidadCamiones(eCamionesPorChofer listadoCamionesPorChofer[],eChofer listadoChoferes[],int tamChoferes);
#endif // CHOFERCAMION_H_INCLUDED
