#ifndef CHOFERCAMION_H_INCLUDED
#define CHOFERCAMION_H_INCLUDED
#define TAM_TIPOS 2
#include "choferes.h"
#include "funcionesParaValidarDatos.h"

void eliminarChoferConCamiones(eChofer listadoChoferes[],int tamChoferes,eCamion listadoCamiones[],int tamCamiones);
void mostrarChoferesPorTipoCamion(eChofer listadoChoferes[],int tamChoferes,eCamion listadoCamiones[],int tamCamiones, int tamTipos);
void mostrarChoferesConMasDeUnCamion(eChofer listadoChoferes[],int tamChoferes,eCamion listadoCamiones[],int tamCamiones);
void listarCamionesConDiezAniosAntiguedad(eChofer listadoChoferes[],int tamChoferes,eCamion listadoCamiones[],int tamCamiones);
void ordenarChoferesPorCantidadDeCamiones(eChofer listadoChoferes[],int tamChoferes,eCamion listadoCamiones[],int tamCamiones);
#endif // CHOFERCAMION_H_INCLUDED
