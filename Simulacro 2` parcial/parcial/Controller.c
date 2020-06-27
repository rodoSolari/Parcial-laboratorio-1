#include "Controller.h"

int controller_loadFromText(char* path, LinkedList* pArrayListVuelos)
{
    FILE *pFile;
    int respuesta;
    if(path != NULL || pArrayListVuelos != NULL){
        pFile = fopen(path,"r");
        if((parser_vueloFromText(pFile,pArrayListVuelos)==1)){
            respuesta = 1;
        }else{
            respuesta = 0;
        }
    }else{
        respuesta = -1;
    }
    return respuesta;
}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_printAllVuelos(LinkedList* LinkedListVuelos,LinkedList* LinkedListPilotos){
    int returnAux = -1;
    if(LinkedListVuelos!=NULL && LinkedListPilotos!=NULL){
        printAllVuelos(LinkedListVuelos,LinkedListPilotos);
        returnAux = 1;
    }
    return returnAux;
}

int controllerContarCantidadPasajeros(LinkedList* LinkedListVuelos){
    int cantidadPasajeros;
    cantidadPasajeros = ll_count(LinkedListVuelos,contarPasajeros);
    printf("cantidad de pasajeros : %d\n", cantidadPasajeros);
    return cantidadPasajeros;
}

int controllerContarCantidadPasajerosIrlanda(LinkedList* LinkedListVuelos){
    int cantidadPasajerosIrlanda;
    cantidadPasajerosIrlanda = ll_count(LinkedListVuelos,funcionContarPasajerosIrlanda);
    printf("cantidad de pasajeros a irlanda: %d\n", cantidadPasajerosIrlanda);
    return cantidadPasajerosIrlanda;
}

int controllerFiltrarVuelosCortos(LinkedList* LinkedListVuelos,LinkedList* LinkedListPilotos){
    int returnAux = -1;
    LinkedList* nuevo = ll_newLinkedList();
    nuevo = ll_filter(LinkedListVuelos,funcionFiltrarVuelosCortos);
    if(nuevo!=NULL){
        printAllVuelos(nuevo,LinkedListPilotos);
        returnAux = 1;
    }
    return returnAux;
}

int controllerListVuelosPortugal(LinkedList* LinkedListVuelos,LinkedList* LinkedListPilotos){
    int returnAux = -1;
    LinkedList* nuevo = ll_newLinkedList();
    nuevo = ll_filter(LinkedListVuelos,funcionFiltrarVuelosPortugal);
    if(nuevo!=NULL){
        printAllVuelos(nuevo,LinkedListPilotos);
        returnAux = 1;
    }
    return returnAux;
}

int controllerFiltrarAlexLifeson(LinkedList* LinkedListVuelos,LinkedList* LinkedListPilotos){
    int returnAux = -1;
    LinkedList* nuevo = ll_newLinkedList();

    nuevo = ll_filter(LinkedListVuelos,funcionFiltrarAlexLifeson);
    if(nuevo!=NULL){
        printAllVuelos(nuevo,LinkedListPilotos);
        returnAux = 1;
    }
    return returnAux;
}
