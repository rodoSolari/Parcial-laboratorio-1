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

/**
 * \brief Inicializo el listado con estado LIBRE
 * \param listado de choferes
 * \param tamanio del listado de choferes
 * \return -
 */
void inicializarListadoChoferes(eChofer listado[],int tam);

/**
 * \brief Ingresa luego de inicializar el listado vacio, datos de choferes
 * \param listado de choferes
 * \param tamanio del listado de choferes
 * \return -
 */
void hardCodearChoferes(eChofer listado[],int tam);

/**
 * \brief Muestra la lista de choferes
 * \param listado de choferes
 * \param tamanio del listado de choferes
 * \return -
 */
void mostrarListadoChoferes(eChofer listado[], int tam);

/**
 * \brief Muestra un registro de chofer
 * \param listado de choferes
 * \param tamanio del listado de choferes
 * \return -
 */
void mostrarUnChofer(eChofer chofer);

/**
 * \brief Busca la posicion del chofer a buscar a traves de su id
 * \param listado de choferes
 * \param tamanio del listado de choferes
 * \param id del chofer a buscar
 * \return -
 */
int buscarPosicionChofer(eChofer listado[],int tam, int id);

/**
 * \brief buscar la primer posicion libre que encuentra del listado de choferes
 * \param listado de choferes
 * \param tamanio del listado de choferes
 * \return -
 */
int buscarPosicionLibreChofer(eChofer listado[],int tam);

/**
 * \brief Modifica un dato de un chofer existente
 * \param listado de choferes
 * \param tamanio del listado de choferes
 * \return -
 */
void modificarChofer(eChofer listado[],int tam);

/**
 * \brief Calcula el promedio de edad de todos los choferes del listado
 * \param listado de choferes
 * \param tamanio del listado de choferes
 * \return -
 */
void calcularPromedioEdad(eChofer listado[],int tam);

/**
 * \brief calcula el promedio de cantidad de mujeres y varones
 * \param listado de choferes
 * \param tamanio del listado de choferes
 * \return -
 */
void calcularPromedioVaronesMujeres(eChofer listado[],int tam);

/**
 * \brief Cargar un nuevo chofer e ingresarlo en el listado de choferes
 * \param listado de choferes
 * \param tamanio del listado de choferes
 * \return -
 */
void cargarChofer(eChofer listado[],int tam);
#endif // CHOFERES_H_INCLUDED
