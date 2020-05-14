#include "camiones.h"
#include "choferes.h"
void hardCodearCamiones(eCamion listado[],int tam){
    int id[TAM_HARDCODEO]={2000,2001,2002,2003,2004,2005,2006,2007,2008,2009};
    char patente[TAM_HARDCODEO][MAX_STRING]={"AA10","FJ38","AM24","FL28","FJ01","LX38","AA38","XC38","BF38","LU38"};
    char marca[TAM_HARDCODEO][MAX_STRING]={"Ford","Ford","Fiat","Fiat","VW","Ford","Ford","Ford","Ford","Ford"};
    int anio[TAM_HARDCODEO]={2000,2000,2001,1998,2010,2005,2015,2006,2001,2001};
    int peso[TAM_HARDCODEO]={10000,10000,20302,20000,10000,14000,15000,17000,10000,8600};
    int cantidadDeRuedas[TAM_HARDCODEO]={8,8,8,12,12,12,6,6,6,10};
    char tipo[TAM_HARDCODEO][MAX_STRING] = {"Larga distancia","Larga distancia","Corta distancia","Larga distancia","corta distancia","Larga distancia","Larga distancia","Larga distancia","Larga distancia","Larga distancia"};
    int i;
    int idChofer[TAM_HARDCODEO]={1,1,2,2,3,4,4,5,5,5};
    for(i=0; i<10;i++){
        listado[i].id = id[i];
        strcpy(listado[i].patente,patente[i]);
        strcpy(listado[i].marca,marca[i]);
        listado[i].anio = anio[i];
        listado[i].peso = peso[i];
        listado[i].cantidadDeRuedas = cantidadDeRuedas[i];
        strcpy(listado[i].tipo,tipo[i]);
        listado[i].idChofer = idChofer[i];
    }
}

void mostrarCamion(eCamion camion){
    printf("~~~Datos del camion : ~~~\n");
    printf("id:%d\n patente : %s \tmarca:%s\tanio:%d\tpeso:%d cantidad de ruedas:%d\ntipo:%s\n",camion.id,
                                                                                            camion.patente,
                                                                                            camion.marca,
                                                                                            camion.anio,
                                                                                            camion.peso,
                                                                                            camion.cantidadDeRuedas,
                                                                                            camion.tipo);

}

void mostrarListadoCamiones(eCamion listado[],int tam){
    int i;
    printf("LISTADO DE CAMIONES\n");
    for(i=0;i<tam;i++){
        mostrarCamion(listado[i]);
    }
    printf("_____________________________________\n");
}

eCamion buscarCamion(eCamion listadoCamiones[],int tam, int id){
    int i;
    eCamion auxCamion={0,"no existe","no existe",0,0,0,"no existe"};
    for(i=0;i<tam;i++)
    {
        if(listadoCamiones[i].id==id)
        {
            auxCamion=listadoCamiones[i];
            break;
        }
    }
    return auxCamion;
}
