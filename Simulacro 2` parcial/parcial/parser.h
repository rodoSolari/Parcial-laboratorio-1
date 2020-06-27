#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Vuelo.h"



/** \brief Lee los registros del archivo de texto y los agrega a la lista de empleados
 *
 *  \param FILE* pFile archivo donde contiene los datos
 *  \param LinkedList* pArrayListEmployee puntero a la lista en donde se guardaran los datos del archivo
 *  \return int Retorna  (-1) Error: si puntero a la lista es NULL o no existe el archivo
 *                       ( 1) Si se pudo guardar los datos de la lista al archivo en formato texto
 */

int parser_vueloFromText(FILE* pFile, LinkedList* pArrayListVuelos);
