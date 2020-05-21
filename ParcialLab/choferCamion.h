#ifndef CHOFERCAMION_H_INCLUDED
#define CHOFERCAMION_H_INCLUDED
#define TAM_TIPOS 2
#include "choferes.h"
#include "funcionesParaValidarDatos.h"

typedef struct{      //Estructura para contar los camiones que tiene cada chofer
    int idChofer;
    int cantidadCamiones;

}eCamionesPorChofer;
/**
 * \brief Imprime por pantalla el menu inicial
 * \param -
 * \return -
 */
void imprimirMenu();

/**
 * \brief Muestra los choferes disponibles
 * \param listado de choferes
 * \param tamanio del listado de choferes
 * \param listado de camiones
 * \param tamanio del listado de camiones
 * \return -
 */
void mostrarChoferesDisponibles(eChofer listadoChoferes[],int tamChoferes,eCamion listadoCamiones[], int tamCamiones);

/**
 * \brief Verifica si la cadena ingresada es flotante
 * \param listado de choferes
 * \param tamanio del listado de choferes
 * \param listado de camiones
 * \param tamanio del listado de camiones
 * \return -
 */
void mostrarTodosLosChoferesConCamiones(eChofer listadoChoferes[], int tamChoferes,eCamion listadoCamiones[], int tamCamiones);

/**
 * \brief Verifica si la cadena ingresada es flotante
 * \param listado de choferes
 * \param tamanio del listado de choferes
 * \param listado de camiones
 * \param tamanio del listado de camiones
 * \return -
 */
void modificarCamion(eCamion listaCamiones[],int tamCamiones,eChofer listaChoferes[],int tamChoferes);

/**
 * \brief Verifica si la cadena ingresada es flotante
 * \param listado de choferes
 * \param tamanio del listado de choferes
 * \param listado de camiones
 * \param tamanio del listado de camiones
 * \return -
 */
void eliminarChoferConCamiones(eChofer listadoChoferes[],int tamChoferes,eCamion listadoCamiones[],int tamCamiones);

/**
 * \brief Verifica si la cadena ingresada es flotante
* \param listado de choferes
 * \param tamanio del listado de choferes
 * \param listado de camiones
 * \param tamanio del listado de camiones
 * \return -
 */
void mostrarChoferesPorTipoCamion(eChofer listadoChoferes[],int tamChoferes,eCamion listadoCamiones[],int tamCamiones, int tamTipos);

/**
 * \brief Verifica si la cadena ingresada es flotante
 * \param listado de choferes
 * \param tamanio del listado de choferes
 * \param listado de camiones
 * \param tamanio del listado de camiones
 * \return -
 */
void mostrarChoferesConMasDeUnCamion(eChofer listadoChoferes[],int tamChoferes,eCamion listadoCamiones[],int tamCamiones);

/**
 * \brief Lista los camiones con mas de 10 anios de antiguedad
* \param listado de choferes
 * \param tamanio del listado de choferes
 * \param listado de camiones
 * \param tamanio del listado de camiones
 * \return -
 */
void listarCamionesConDiezAniosAntiguedad(eChofer listadoChoferes[],int tamChoferes,eCamion listadoCamiones[],int tamCamiones);

/**
 * \brief Ordena a los choferes segun su cantidad de camiones a cargo
 * \param listado de choferes
 * \param tamanio del listado de choferes
 * \param listado de camiones
 * \param tamanio del listado de camiones
 * \return -
 */
void ordenarChoferesPorCantidadDeCamiones(eChofer listadoChoferes[],int tamChoferes,eCamion listadoCamiones[],int tamCamiones);

/**
 * \brief Ordena a los choferes por la cantidad de camiones y su nombre
 * \param listado de choferes
 * \param tamanio del listado de choferes
 * \param listado de camiones
 * \param tamanio del listado de camiones
 * \return -
 */
void ordenarChoferesPorCantidadDeCamionesNombre(eChofer listadoChoferes[],int tamChoferes,eCamion listadoCamiones[],int tamCamiones);

/**
 * \brief Cuenta los camiones que tiene cada chofer y los ingresa al listado de camiones por chofer
 * \param listado de camiones por chofer
 * \param listado de choferes
 * \param tamanio del listado de choferes
 * \param listado de camiones
 * \param tamanio del listado de camiones
 * \return -
 */
void contarCamionesPorChofer(eCamionesPorChofer listadoCamionesPorChofer[],eChofer listadoChoferes[],int tamChoferes,eCamion listadoCamiones[],int tamCamiones);

/**
 * \brief Muestra por pantalla la cantidad de camiones que tiene cada chofer
 * \param listado de camiones por chofer
 * \param listado de choferes
 * \param tamanio del listado de choferes
 * \return -
 */
void mostrarChoferesConCantidadCamiones(eCamionesPorChofer listadoCamionesPorChofer[],eChofer listadoChoferes[],int tamChoferes);
#endif // CHOFERCAMION_H_INCLUDED
