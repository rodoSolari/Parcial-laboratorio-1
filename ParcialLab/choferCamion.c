
#include "choferCamion.h"

void imprimirMenu(){
    printf("1. Mostrar listado de choferes:\n2. Mostrar listado de camiones\n3. Mostrar listado de choferes con sus respectivos camiones\n");
    printf("4. Alta de camiones\n5.Baja de camiones\n6.Modificar camiones\n7.Alta chofer\n");
    printf("8. Borrado de chofer en cascada\n9.Ordenar camiones por tipo\n");
    printf("10. Modificacion de chofer\n11.Listar choferes con mas de un camion\n");
    printf("12. Listar camiones con mas de 10 anios de antiguedad, y con sus respectivos choferes\n");
    printf("13. Pedir una marca y solo listas los CAMIONES de esa marca\n");
    printf("14. Ordenar a los CHOFERES por cantidades de CAMIONES y mostrarlos\n");
    printf("15. Ordenar a los CHOFERES por cantidades de CAMIONES y por orden alfabético de los nombres y mostrarlos\n");
    printf("16. Promedio de edad entre los CHOFERES\n");
    printf("17. Promedio de años de antigüedad de flota de CAMIONES\n");
    printf("18. Promedio que tengo entre varones y mujeres de mis CHOFERES\n19. Salir\n");
}


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
            if(listadoChoferes[i].estado==OCUPADO){
                for(j = 0;j<tamCamiones;j++){
                     if(listadoCamiones[j].estado==OCUPADO){
                        if((listadoChoferes[i].id == listadoCamiones[j].idChofer)&&(stricmp(listadoCamiones[j].tipo,tipoCamion[k])==0)){
                            mostrarUnChofer(listadoChoferes[i]);
                        }
                     }
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
        if(listadoChoferes[i].estado == OCUPADO){
            contadorCamionPorChofer=0;
            for(j = 0;j<tamCamiones;j++){
                if(listadoCamiones[j].estado == OCUPADO){
                    if(listadoChoferes[i].id == listadoCamiones[j].idChofer){
                        contadorCamionPorChofer++;
                        if(contadorCamionPorChofer>1){
                            mostrarUnChofer(listadoChoferes[i]);
                        }
                    }
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
        if(listadoCamiones[i].estado==OCUPADO){
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
}


void ordenarChoferesPorCantidadDeCamiones(eChofer listadoChoferes[],int tamChoferes,eCamion listadoCamiones[],int tamCamiones){
    int i;
    int j;

    eChofer auxChofer[tamChoferes];
    eCamionesPorChofer listadoCamionesPorChofer[tamChoferes];
    eCamionesPorChofer auxCamionesPorChofer[tamChoferes];
    contarCamionesPorChofer(listadoCamionesPorChofer,listadoChoferes,tamChoferes,listadoCamiones,tamCamiones);

    for(i=0; i<tamChoferes-1;i++){
        if(listadoChoferes[i].estado==OCUPADO){
            for(j=i+1; j<tamChoferes;j++){
                if(listadoCamionesPorChofer[i].cantidadCamiones>listadoCamionesPorChofer[j].cantidadCamiones){
                    auxCamionesPorChofer[i] = listadoCamionesPorChofer[i];
                    listadoCamionesPorChofer[i] = listadoCamionesPorChofer[j];
                    listadoCamionesPorChofer[j] = auxCamionesPorChofer[i];

                    auxChofer[i] = listadoChoferes[i];
                    listadoChoferes[i] = listadoChoferes[j];
                    listadoChoferes[j] = auxChofer[i];
                }
            }
        }
    }
    mostrarChoferesConCantidadCamiones(auxCamionesPorChofer,listadoChoferes,tamChoferes);
}

void mostrarChoferesConCantidadCamiones(eCamionesPorChofer listadoCamionesPorChofer[],eChofer listadoChoferes[],int tamChoferes){
    int i;
    for(i=0;i<tamChoferes;i++){
        if(listadoChoferes[i].estado == OCUPADO){
            mostrarUnChofer(listadoChoferes[i]);
            printf("Cantidad de camiones : %d\n",listadoCamionesPorChofer[i].cantidadCamiones);
        }
    }
}

void contarCamionesPorChofer(eCamionesPorChofer auxCamionesPorChofer[],eChofer listadoChoferes[],int tamChoferes,eCamion listadoCamiones[],int tamCamiones){
    int i;
    int j;
    for(i=0;i<tamChoferes;i++){
        if(listadoChoferes[i].estado==OCUPADO){
            auxCamionesPorChofer[i].cantidadCamiones=0;
            auxCamionesPorChofer[i].idChofer=listadoChoferes[i].id;
        }
    }
    for(i=0;i<tamChoferes;i++){
        if(listadoChoferes[i].estado==OCUPADO){
            for(j=0;j<tamCamiones;j++){
                if(listadoCamiones[j].estado == OCUPADO){
                    if(listadoCamiones[j].idChofer==listadoChoferes[i].id){
                        auxCamionesPorChofer[i].cantidadCamiones++;
                    }
                }
            }
        }
    }
}


void ordenarChoferesPorCantidadDeCamionesNombre(eChofer listadoChoferes[],int tamChoferes,eCamion listadoCamiones[],int tamCamiones){
    int i;
    int j;

    eChofer auxChofer[tamChoferes];
    eCamionesPorChofer listadoCamionesPorChofer[tamChoferes];
    eCamionesPorChofer auxCamionesPorChofer[tamChoferes];
    contarCamionesPorChofer(listadoCamionesPorChofer,listadoChoferes,tamChoferes,listadoCamiones,tamCamiones);

    for(i=0; i<tamChoferes-1;i++){
        for(j=i+1; j<tamChoferes;j++){
            if(listadoCamionesPorChofer[i].cantidadCamiones>listadoCamionesPorChofer[j].cantidadCamiones || stricmp(listadoChoferes[i].nombre,listadoChoferes[j].nombre)>0){
                auxCamionesPorChofer[i] = listadoCamionesPorChofer[i];
                listadoCamionesPorChofer[i] = listadoCamionesPorChofer[j];
                listadoCamionesPorChofer[j] = auxCamionesPorChofer[i];

                auxChofer[i] = listadoChoferes[i];
                listadoChoferes[i] = listadoChoferes[j];
                listadoChoferes[j] = auxChofer[i];
            }
        }
    }
    mostrarChoferesConCantidadCamiones(auxCamionesPorChofer,listadoChoferes,tamChoferes);

}
