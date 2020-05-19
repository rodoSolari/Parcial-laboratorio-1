#include "camiones.h"
#include "choferes.h"
#include "funcionesParaValidarDatos.h"

void hardCodearCamiones(eCamion listado[],int tam){
    int id[TAM_HARDCODEO]={2000,2001,2002,2003,2004,2005,2006,2007,2008,2009};
    char patente[TAM_HARDCODEO][TAM_STRING]={"AA10","FJ38","AM24","FL28","FJ01","LX38","AA38","XC38","BF38","LU38"};
    char marca[TAM_HARDCODEO][TAM_STRING]={"Ford","Ford","Fiat","Fiat","VW","Ford","Ford","Ford","Ford","Ford"};
    int anio[TAM_HARDCODEO]={2000,2000,2001,1998,2010,2005,2015,2006,2001,2001};
    int peso[TAM_HARDCODEO]={10000,10000,20302,20000,10000,14000,15000,17000,10000,8600};
    int cantidadDeRuedas[TAM_HARDCODEO]={8,8,8,12,12,12,6,6,6,10};
    char tipo[TAM_HARDCODEO][TAM_STRING] = {"Larga distancia","Larga distancia","Corta distancia","Larga distancia","corta distancia","Larga distancia","Larga distancia","Larga distancia","Larga distancia","Larga distancia"};
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
        listado[i].estado = OCUPADO;
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

eCamion cargarCamion(){
    eCamion nuevoCamion;
    getString(nuevoCamion.patente,"Patente : ","Error, por favor ingrese una patente valida\n");
    getString(nuevoCamion.marca,"Marca de auto : ","Error, por favor ingrese una patente valida\n");
    getInt(&nuevoCamion.anio,"Anio : ","Error, por favor ingrese una patente valida");
    getInt(&nuevoCamion.peso,"Peso","Error, por favor ingrese un peso valido");
    getInt(&nuevoCamion.cantidadDeRuedas,"Cantidad de ruedas","Error, por favor ingrese un valor valido\n");
    getString(nuevoCamion.tipo,"Tipo : ","Error, por favor ingrese un tipo valido\n");
    nuevoCamion.estado = OCUPADO;
    return nuevoCamion;
}

int buscarPosicionLibre(eCamion listado[],int tam){
    int respuesta=-1;
    int i;
    for(i=0;i<tam;i++){
        if(listado[i].estado==LIBRE){
            respuesta=i;
            break;
        }
    }
    return respuesta;
}

void agregarNuevoCamion(eCamion listado[],int tam){
    int indice = buscarPosicionLibre(listado,tam);
    if(indice!=-1){
        listado[indice]=cargarCamion();
    }
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


int buscarPosicionCamion(eCamion listadoCamiones[],int tam, int id){
    int respuesta = -1;
	int i;
    for(i=0;i<tam;i++){
        if(listadoCamiones[i].id == id){
            respuesta = i;
            break;
        }
    }
    return respuesta;
}


void eliminarCamion(eCamion listado[],int tam){
    int indice;
    int id;
    getInt(&id,"Ingrese el ID a eliminar","Error : ingrese un numero valido");
    indice = buscarPosicionCamion(listado,tam,id);
    if(indice>=0){
        mostrarCamion(listado[indice]);
        listado[indice].estado = LIBRE;
        printf("Eliminado\n");
    }else{
        printf("No existe\n");
    }
}

/*void eliminarCamion(eCamion listado[],int tam, int id){
    int indice;
    getInt(id,"Ingrese el ID a eliminar","Error : ingrese un numero valido");
    indice = buscarPosicionCamion(listado,tam,id);
    if(indice>=0){
        mostrarCamion(listado[indice]);
        listado[indice].estado = LIBRE;
        printf("Eliminado\n");
    }else{
        printf("No existe\n");
    }
}*/

void modificarCamion(eCamion listado[],int tam){
    int indice;
    int id;
    int opcion;
    printf("Modificar camion\n");
    getInt(&id,"Ingrese el ID a modificar","Error : ingrese un numero valido");
    printf("1. Tipo de camion\n2. Chofer");
    getInt(&opcion,"Ingrese la opcion a modificar","Error : ingrese un numero valido");
    indice = buscarPosicionCamion(listado,tam,id);
    switch(opcion){
        case 1:
            getString(listado[indice].tipo,"Ingrese el tipo : ","Error, Ingrese un tipo valido");
            break;
        case 2:
            getInt(&listado[indice].idChofer,"Ingrese el id del chofer : ","Error, Ingrese un tipo valido");
            break;
        default:
            printf("opcion incorrecta");
    }
}

void ordenarCamionesPorTipo(eCamion listadoCamiones[],int tamCamiones){
    int i;
    int j;
    eCamion auxCamion;

    for(i=0; i<tamCamiones-1;i++)
    {
        for(j=i+1; j<tamCamiones;j++)
        {
            if(stricmp(listadoCamiones[i].tipo,listadoCamiones[j].tipo)>0)
            {
                auxCamion = listadoCamiones[i];
                listadoCamiones[i] = listadoCamiones[j];
                listadoCamiones[j] = auxCamion;
            }
        }
    }
}

