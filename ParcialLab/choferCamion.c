
#include "choferCamion.h"
void eliminarChoferConCamiones(eChofer listadoChoferes[],int tamChoferes,eCamion listadoCamiones[],int tamCamiones){
    int indice;
    int id;
    int i;
    getInt(&id,"Ingrese el ID a eliminar","Error : ingrese un numero valido");
    indice = buscarPosicionChofer(listadoChoferes,tamChoferes,id);
    if(indice>=0){
        mostrarUnChofer(listadoChoferes[indice]);
        listadoChoferes[indice].estado = LIBRE;
        for(i=0;i<tamCamiones;i++){
            if(listadoChoferes[indice].id == listadoCamiones[i].idChofer){
                listadoCamiones[i].estado = LIBRE;
            }
        }
        printf("Eliminado\n");
    }else{
        printf("No existe\n");
    }

}

void mostrarChoferesPorTipoCamion(eChofer listadoChoferes[],int tamChoferes,eCamion listadoCamiones[],int tamCamiones, int tamTipos){
    ordenarCamionesPorTipo(listadoCamiones,tamCamiones);
    char tipoCamion[TAM_TIPOS][TAM_STRING]={"Corta distancia","Larga distancia"};
    int i;
    int j;
    int k;
    for(k=0;k<tamTipos;k++){
        printf("Choferes con tipo de camion %s\n",tipoCamion[k]);
        for(i=0; i<tamChoferes; i++){
            for(j = 0;j<tamCamiones;j++){
                if((listadoChoferes[i].id == listadoCamiones[j].idChofer)&&(stricmp(listadoCamiones[j].tipo,tipoCamion[k])==0)){
                    mostrarUnChofer(listadoChoferes[i]);
                }
            }
        }
   }
}


void mostrarChoferesConMasDeUnCamion(eChofer listadoChoferes[],int tamChoferes,eCamion listadoCamiones[],int tamCamiones){
    int i;
    int j;
    int contadorCamionPorChofer;
    printf("Choferes con mas de un camion \n");
    for(i=0; i<tamChoferes; i++){
        contadorCamionPorChofer=0;
        for(j = 0;j<tamCamiones;j++){
            if(listadoChoferes[i].id == listadoCamiones[j].idChofer){
                contadorCamionPorChofer++;
                if(contadorCamionPorChofer>1){
                    mostrarUnChofer(listadoChoferes[i]);
                }
            }
        }
    }

}

/*eChofer buscarDuenioCamion(eChofer listadoChoferes[],int tamChoferes,eCamion listadoCamiones[],int tamCamiones){
    int i;
    int j;
    eChofer aux
    for(){
        for()
    }
}
*/
void listarCamionesConDiezAniosAntiguedad(eChofer listadoChoferes[],int tamChoferes,eCamion listadoCamiones[],int tamCamiones){
    int i;
    int j;
    int encontreDuenio;
    printf("Camiones con mas de 10 anios de antiguedad\n");
    for(i = 0;i<tamCamiones;i++){
        if(listadoCamiones[i].anio < 2010){
            encontreDuenio=0;
            mostrarCamion(listadoCamiones[i]);
            printf("Chofer que lo conduce : \n");
            for(j=0;j<tamChoferes;j++){
                if(listadoCamiones[i].idChofer == listadoChoferes[j].id){
                    encontreDuenio=1;
                    mostrarUnChofer(listadoChoferes[i]);
                }
            }
        }
        if(encontreDuenio==0){
            printf("Este camion no tiene chofer asignado \n");
        }
    }
}

//punto 14
void ordenarChoferesPorCantidadDeCamiones(eChofer listadoChoferes[],int tamChoferes,eCamion listadoCamiones[],int tamCamiones){


}
