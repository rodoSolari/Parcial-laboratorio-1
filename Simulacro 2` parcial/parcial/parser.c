#include "parser.h"


int parser_vueloFromText(FILE* pFile, LinkedList* pArrayListVuelos)
{
    int r,i=0;
    int respuesta;
    ll_clear(pArrayListVuelos); //Por si ya habia cargado datos desde otro archivo
    char idVuelo[50],idAvion[50],idPiloto[50],fecha[50],destino[50],cantPasajeros[50],horaDespegue[50],horaLlegada[50];
    eVuelo* auxVuelo;
    if(pFile == NULL || pArrayListVuelos == NULL){
        respuesta = -1;
    }else{
        do{
            if(i==0){
                fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",idVuelo,idAvion,idPiloto,fecha,destino,cantPasajeros,horaDespegue,horaLlegada);
            }
            r = fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",idVuelo,idAvion,idPiloto,fecha,destino,cantPasajeros,horaDespegue,horaLlegada);
            if(r==8){
                auxVuelo = eVuelo_newParametros(idVuelo,idAvion,idPiloto,fecha,destino,cantPasajeros,horaDespegue,horaLlegada);
                ll_add(pArrayListVuelos,auxVuelo);
                i++;
            }
            else{
                break;
            }
        }while(!feof(pFile));
        respuesta = 1;
    }
    fclose(pFile);
    return respuesta;
}

int parser_pilotoFromText(FILE* pFile, LinkedList* pArrayListPilotos)
{
    int r,i=0;
    int respuesta;
    ll_clear(pArrayListPilotos); //Por si ya habia cargado datos desde otro archivo
    char idPiloto[50],nombre[50];
    ePiloto* auxPiloto;
    if(pFile == NULL || pArrayListPilotos == NULL){
        respuesta = -1;
    }else{
        do{
            if(i==0){
                fscanf(pFile,"%[^,],%[^\n]\n",idPiloto,nombre);
            }
            r = fscanf(pFile,"%[^,],%[^\n]\n",idPiloto,nombre);
            if(r==2){
                auxPiloto = ePiloto_newParametros(idPiloto,nombre);
                ll_add(pArrayListPilotos,auxPiloto);
                i++;
            }
            else{
                break;
            }
        }while(!feof(pFile));
        respuesta = 1;
    }
    fclose(pFile);
    return respuesta;
}


