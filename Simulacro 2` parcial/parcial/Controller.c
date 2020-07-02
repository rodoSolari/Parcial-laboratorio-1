#include "Controller.h"


int controller_Solari_LoadVuelosFromText(char* path, LinkedList* pArrayListVuelos)
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

int controller_Solari_LoadPilotosFromText(char* path, LinkedList* pArrayListPilotos)
{
    FILE *pFile;
    int respuesta;
    if(path != NULL || pArrayListPilotos != NULL){
        pFile = fopen(path,"r");
        if((parser_pilotoFromText(pFile,pArrayListPilotos)==1)){
            respuesta = 1;
        }else{
            respuesta = 0;
        }
    }else{
        respuesta = -1;
    }
    return respuesta;
}

int controller_Solari_LoadPilotosToText(char* path, LinkedList* pArrayListPilotos)
{
    int i=0;
    int respuesta;

    int idPiloto;
    char nombre[30];

    FILE* pFile;
    if(path==NULL){
        respuesta = -1;
    }else{
        pFile = fopen(path,"w");
        ePiloto* piloto;

        if(pFile == NULL || pArrayListPilotos == NULL){
            respuesta = -1;
        }
        else{
            fprintf(pFile,"idPiloto,nombre\n"); //imprimo la cabecera en el nuevo archivo
            do{
                piloto = ll_get(pArrayListPilotos,i);
                if(ePiloto_getIdPiloto(piloto,&idPiloto) == 1 && ePiloto_getNombre(piloto,nombre) == 1){
                    fprintf(pFile,"%d,%s\n",idPiloto,nombre);
                    i++;
                }
            }while(i<ll_len(pArrayListPilotos));
            respuesta = 1;
        }
        fclose(pFile);
    }
    return respuesta;
}

int controller_Solari_PrintAllVuelos(LinkedList* LinkedListVuelos,LinkedList* LinkedListPilotos){
    int returnAux = -1;
    if(LinkedListVuelos!=NULL && LinkedListPilotos!=NULL && !ll_isEmpty(LinkedListVuelos) && !ll_isEmpty(LinkedListPilotos)){
        printAllVuelos(LinkedListVuelos,LinkedListPilotos);
        returnAux = 1;
    }
    return returnAux;
}

int controller_Solari_ContarCantidadPasajeros(LinkedList* LinkedListVuelos){
    int respuesta = -1;
    int cantidadPasajeros;
    if(LinkedListVuelos!=NULL && !ll_isEmpty(LinkedListVuelos)){
        cantidadPasajeros = ll_count(LinkedListVuelos,contarPasajeros);
        printf("cantidad de pasajeros : %d\n", cantidadPasajeros);
        respuesta = 1;
    }
    return respuesta;
}

int controller_Solari_ContarCantidadPasajerosIrlanda(LinkedList* LinkedListVuelos){
    int respuesta = -1;
    int cantidadPasajerosIrlanda;
    if(LinkedListVuelos!=NULL && !ll_isEmpty(LinkedListVuelos)){
        cantidadPasajerosIrlanda = ll_count(LinkedListVuelos,funcionContarPasajerosIrlanda);
        printf("cantidad de pasajeros a irlanda: %d\n", cantidadPasajerosIrlanda);
        respuesta = 1;
    }
    return respuesta;
}

int controller_Solari_FiltrarVuelosCortos(char* path,LinkedList* LinkedListVuelos,LinkedList* LinkedListPilotos){
    int returnAux = -1;
    LinkedList* nuevo;
    if(path!=NULL && LinkedListVuelos!=NULL && LinkedListPilotos!=NULL && !ll_isEmpty(LinkedListVuelos) && !ll_isEmpty(LinkedListPilotos)){
        nuevo = ll_newLinkedList();
        nuevo = ll_filter(LinkedListVuelos,funcionFiltrarVuelosCortos);
        if(nuevo!=NULL){
            printAllVuelos(nuevo,LinkedListPilotos);
            controller_Solari_SaveAsTextVuelos(path,nuevo);
            returnAux = 1;
        }
    }
    return returnAux;
}

int controller_Solari_SaveAsTextVuelos(char* path, LinkedList* LinkedListVuelos)
{
    int i=0;
    int respuesta;

    int idVuelo;
    int idPiloto;
    int idAvion;
    char fecha[20];
    char destino[30];
    int cantPasajeros;
    int horaDespegue;
    int horaLlegada;

    FILE* pFile;
    if(path==NULL){
        respuesta = -1;
    }else{
        pFile = fopen(path,"w");
        eVuelo* vuelo;

        if(pFile == NULL || LinkedListVuelos == NULL){
            respuesta = -1;
        }
        else{
            fprintf(pFile,"idVuelo,idAvion,idPiloto,fecha,destino,cantPasajeros,horaDespegue,horaLlegada\n"); //imprimo la cabecera en el nuevo archivo
            do{
                vuelo = ll_get(LinkedListVuelos,i);
                if(eVuelo_getIdVuelo(vuelo,&idVuelo) == 1 &&
                eVuelo_getIdAvion(vuelo,&idAvion) == 1 &&
                eVuelo_getIdPiloto(vuelo,&idPiloto) == 1 &&
                eVuelo_getFecha(vuelo,fecha) == 1 &&
                eVuelo_getDestino(vuelo,destino) == 1 &&
                eVuelo_getCantPasajeros(vuelo,&cantPasajeros) == 1 &&
                eVuelo_gethoraDespegue(vuelo,&horaDespegue) == 1 &&
                eVuelo_gethoraLlegada(vuelo,&horaLlegada) ==1){
                fprintf(pFile,"%d,%d,%d,%s,%s,%d,%d,%d\n",idVuelo,
                                                              idAvion,
                                                              idPiloto,
                                                              fecha,
                                                              destino,
                                                              cantPasajeros,
                                                              horaDespegue,
                                                              horaLlegada);
                i++;
                }
            }while(i<ll_len(LinkedListVuelos));
            respuesta = 1;
        }
        fclose(pFile);
    }
    return respuesta;
}

int controller_Solari_ListVuelosPortugal(LinkedList* LinkedListVuelos,LinkedList* LinkedListPilotos){
    int returnAux = -1;
    LinkedList* nuevo;
    if(LinkedListVuelos!=NULL && LinkedListPilotos!=NULL && !ll_isEmpty(LinkedListVuelos) && !ll_isEmpty(LinkedListPilotos)){
        nuevo = ll_newLinkedList();
        nuevo = ll_filter(LinkedListVuelos,funcionFiltrarVuelosPortugal);
        if(nuevo!=NULL){
            printAllVuelos(nuevo,LinkedListPilotos);
            returnAux = 1;
        }
    }
    return returnAux;
}

int controller_Solari_FiltrarAlexLifeson(LinkedList* LinkedListVuelos,LinkedList* LinkedListPilotos){
    int returnAux = -1;
    LinkedList* nuevo;
    if(LinkedListVuelos!=NULL && LinkedListPilotos!=NULL && !ll_isEmpty(LinkedListVuelos) && !ll_isEmpty(LinkedListPilotos)){
        nuevo = ll_newLinkedList();
        nuevo = ll_filter(LinkedListVuelos,funcionFiltrarAlexLifeson);
        if(nuevo!=NULL){
            printAllVuelos(nuevo,LinkedListPilotos);
            returnAux = 1;
        }
    }
    return returnAux;
}


int controller_Solari_MostrarVuelosSinPiloto(LinkedList* LinkedListVuelos,LinkedList* LinkedListPilotos){
    int respuesta = -1;
    char nombre[30];
    int indice;
    LinkedList* nuevo;

    getString(nombre,"Ingrese un nombre : ","Error, ingrese un nombre valido : ");
    nombre[strlen(nombre)-1] = '\0';

    indice = getIndexOfPilotoByName(LinkedListPilotos,nombre);
    if(indice!=-1){
        if(LinkedListVuelos!=NULL && LinkedListPilotos!=NULL && !ll_isEmpty(LinkedListVuelos) && !ll_isEmpty(LinkedListPilotos)){
            nuevo = ll_newLinkedList();
            nuevo = ll_filter_parametro(LinkedListPilotos,funcionFiltrarVuelosSinPiloto,nombre);
            if(nuevo!=NULL && !ll_isEmpty(nuevo)){
                printAllVuelos(LinkedListVuelos,nuevo);
                respuesta = 1;
            }else{
                respuesta = 0;
            }
        }
    }else{
        respuesta = 0;
    }
    return respuesta;
}

int controller_Solari_MostrarVuelosPiloto(LinkedList* LinkedListVuelos,LinkedList* LinkedListPilotos){
    int respuesta = -1;
    char nombre[30];
    int indice;
    LinkedList* nuevo;

    getString(nombre,"Ingrese un nombre : ","Error, ingrese un nombre valido : ");
    nombre[strlen(nombre)-1] = '\0';

    indice = getIndexOfPilotoByName(LinkedListPilotos,nombre);
    if(indice!=-1){
        if(LinkedListVuelos!=NULL && LinkedListPilotos!=NULL && !ll_isEmpty(LinkedListVuelos) && !ll_isEmpty(LinkedListPilotos)){
            nuevo = ll_newLinkedList();
            nuevo = ll_filter_parametro(LinkedListPilotos,funcionFiltrarVuelosPiloto,nombre);
            if(nuevo!=NULL && !ll_isEmpty(nuevo)){
                printAllVuelos(LinkedListVuelos,nuevo);
                respuesta = 1;
            }else{
                respuesta = 0;
            }
        }else{
            respuesta = 0;
        }
    }
    return respuesta;
}
