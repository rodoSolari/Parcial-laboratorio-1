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
    char tipo[TAM_STRING]; //{larga distancia,corta distancia}
    int idChofer;
    int estado;
}eCamion;

/**
 * \brief Verifica si la cadena ingresada es flotante
 * \param listado de camiones
 * \param tamanio del listado de camiones
 * \return -
 */
void inicializarListadoCamiones(eCamion listado[],int tam);

/**
 * \brief Verifica si la cadena ingresada es flotante
 * \param listado de camiones
 * \param tamanio del listado de camiones
 * \return -
 */
void mostrarListadoCamiones(eCamion listado[],int tam);

/**
 * \brief Verifica si la cadena ingresada es flotante
 * \param listado de camiones
 * \param tamanio del listado de camiones
 * \return -
 */
void hardCodearCamiones(eCamion listado[],int tam);

/**
 * \brief Verifica si la cadena ingresada es flotante
 * \param estructura de tipo camion
 * \return -
 */
void mostrarCamion(eCamion camion);

/**
 * \brief Verifica si la cadena ingresada es flotante
 * \param listado de camiones
 * \param tamanio del listado de camiones
 * \return Devuelve el camion a buscar
 */
eCamion buscarCamion(eCamion listadoCamiones[],int tam, int id);

/**
 * \brief Verifica si la cadena ingresada es flotante
 * \param listado de camiones
 * \param tamanio del listado de camiones
 * \return -
 */
void cargarCamion(eCamion listado[], int tam);

/**
 * \brief Verifica si la cadena ingresada es flotante
 * \param Cadena de caracteres a ser verificada
 * \return devuelve la posicion libre del listado de camiones
 */
int buscarPosicionLibreCamion(eCamion listado[],int tam);

/**
 * \brief Verifica si la cadena ingresada es flotante
 * \param Cadena de caracteres a ser verificada
 * \return -
 */
int buscarPosicionCamion(eCamion listadoCamiones[],int tam, int id);

/**
 * \brief Verifica si la cadena ingresada es flotante
 * \param Cadena de caracteres a ser verificada
 * \return -
 */
void mostrarCamionesPorMarca(eCamion listado[],int tam);

/**
 * \brief Verifica si la cadena ingresada es flotante
 * \param Cadena de caracteres a ser verificada
 * \return -
 */
void eliminarCamion(eCamion listado[],int tam);

/**
 * \brief Verifica si la cadena ingresada es flotante
 * \param Cadena de caracteres a ser verificada
 * \return -
 */
void ordenarCamionesPorTipo(eCamion listadoCamiones[],int tamCamiones);

/**
 * \brief Verifica si la cadena ingresada es flotante
 * \param Cadena de caracteres a ser verificada
 * \return -
 */
void calcularPromedioAntiguedadCamiones(eCamion listadoCamiones[],int tamCamiones);
#endif // CAMIONES_H_INCLUDED
