#include "camiones.h"
#include "choferes.h"
#include "funcionesParaValidarDatos.h"

static int contadorIdCamion = 2000;

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
        contadorIdCamion++;
    }
}

void inicializarListadoCamiones(eCamion listado[],int tam){
    int i;
    for(i=0;i<tam;i++){
        listado[i].estado = LIBRE;
    }

}

void mostrarCamion(eCamion camion){
    printf("~~~Datos del camion : ~~~\n");
    printf("id:%d\nPatente : %s \tMarca:%s\tAnio:%d\nPeso:%d \tcantidad de ruedas : %d\ntipo:%s\n",camion.id,
                                                                                            camion.patente,
                                                                                            camion.marca,
                                                                                            camion.anio,
                                                                                            camion.peso,
                                                                                            camion.cantidadDeRuedas,
                                                                                            camion.tipo);


}

void cargarCamion(eCamion listado[], int tam){
    eCamion nuevoCamion;
    int indice = buscarPosicionLibreCamion(listado,tam);
    if(indice!=-1){
        getPatente(nuevoCamion.patente,"Patente : ","Error, por favor ingrese una patente valida\n");
        getMarca(nuevoCamion.marca,"Marca de auto : ","Error, por favor ingrese una patente valida\n");
        getInt(&nuevoCamion.anio,"Anio : ","Error, por favor ingrese una patente valida\n",1950,2020);
        getInt(&nuevoCamion.peso,"Peso : ","Error, por favor ingrese un peso valido\n",500,30000);
        getInt(&nuevoCamion.cantidadDeRuedas,"Cantidad de ruedas : ","Error, por favor ingrese un valor valido\n",4,40);
        getTipo(nuevoCamion.tipo,"Tipo : ","Error, por favor ingrese un tipo valido\n");
        nuevoCamion.estado = OCUPADO;
        nuevoCamion.id = contadorIdCamion;
        contadorIdCamion++;
        listado[indice] = nuevoCamion;

        printf("Agregado nuevo camion al listado\n");

    }else{
        printf("no hay espacio en la lista para agregar otro camion\n");
    }
}

int buscarPosicionLibreCamion(eCamion listado[],int tam){
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


void mostrarListadoCamiones(eCamion listado[],int tam){
    int i;
    printf("LISTADO DE CAMIONES\n");
    for(i=0;i<tam;i++){
        if(listado[i].estado==OCUPADO){
            mostrarCamion(listado[i]);
            printf("__________________________\n");
        }
    }
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
    getInt(&id,"Ingrese el ID a eliminar\n","Error : ingrese un numero valido",2000,2025);
    indice = buscarPosicionCamion(listado,tam,id);
    if(indice>=0){
        mostrarCamion(listado[indice]);
        listado[indice].estado = LIBRE;
        printf("Eliminado\n");
    }else{
        printf("No existe\n");
    }
}

void mostrarCamionesPorMarca(eCamion listado[],int tam){
    int i;
    char marca[MAX_STRING];
    int contarCantidadPorMarca=0;
    getMarca(marca,"Ingrese la marca que desea mostrar : ","error, por favor ingrese una marca valida : ");
    printf("Lista de camiones de la marca %s :\n",marca);
    for(i=0;i<tam;i++){
        if(stricmp(listado[i].marca,marca)==0){
            mostrarCamion(listado[i]);
            contarCantidadPorMarca++;
            printf("***************************\n");
        }
    }
    if(contarCantidadPorMarca==0){
        printf("No hay camiones de la marca %s \n",marca);
    }
}

void ordenarCamionesPorTipo(eCamion listadoCamiones[],int tamCamiones){
    int i;
    int j;
    eCamion auxCamion; //Aux de camion para realizar el ordenamiento

    for(i=0; i<tamCamiones-1;i++){
        if(listadoCamiones[i].estado==OCUPADO){
            for(j=i+1; j<tamCamiones;j++){
                if(listadoCamiones[i].estado==OCUPADO){
                    if(stricmp(listadoCamiones[i].tipo,listadoCamiones[j].tipo)>0){
                        auxCamion = listadoCamiones[i];
                        listadoCamiones[i] = listadoCamiones[j];
                        listadoCamiones[j] = auxCamion;
                    }
                }
            }
        }
    }

}

void calcularPromedioAntiguedadCamiones(eCamion listadoCamiones[],int tamCamiones){
    int i;
    int cantidadCamiones = 0;
    int totalAntiguedad = 0;
    float promedioAntiguedad;
    int antiguedadCamion;
    for(i=0; i<tamCamiones;i++){
        if(listadoCamiones[i].estado == OCUPADO){
            antiguedadCamion=2020-listadoCamiones[i].anio;
            totalAntiguedad+=antiguedadCamion;
            cantidadCamiones++;
        }
    }
    promedioAntiguedad = ((float)totalAntiguedad/cantidadCamiones);
    printf("Promedio de antiguedad de los camiones : %.2f\n",(float)promedioAntiguedad);
}

