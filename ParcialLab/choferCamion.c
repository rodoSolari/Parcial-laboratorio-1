
#include "choferCamion.h"

void imprimirMenu(){
    printf("1. Mostrar listado de choferes:\n2. Mostrar listado de camiones\n");
    printf("3. Mostrar listado de choferes con sus respectivos camiones\n");
    printf("4. Alta de camiones\n5. Baja de camiones\n6. Modificar camiones\n7.Alta chofer\n");
    printf("8. Borrado de chofer en cascada\n9. Ordenar camiones por tipo\n");
    printf("10. Modificacion de chofer\n11. Listar choferes con mas de un camion\n");
    printf("12. Listar camiones con mas de 10 anios de antiguedad, y con sus respectivos choferes\n");
    printf("13. Pedir una marca y solo listas los camiones de esa marca\n");
    printf("14. Ordenar a los choferes por cantidades de camiones y mostrarlos\n");
    printf("15. Ordenar a los choferes por cantidades de camiones y por orden alfabético de los nombres y mostrarlos\n");
    printf("16. Promedio de edad entre los choferes\n");
    printf("17. Promedio de años de antigüedad de flota de camiones\n");
    printf("18. Promedio que tengo entre varones y mujeres de mis choferes\n19. Salir\n");
}


void mostrarChoferesDisponibles(eChofer listadoChoferes[],int tamChoferes,eCamion listadoCamiones[], int tamCamiones){
    int i;
    int j;
    int tieneCamion;  //FLAG para verificar si cada chofer tiene o no por lo menos un camion
    printf("Listado de choferes disponibles : \n");
    for(i=0;i<tamChoferes;i++){
        if(listadoChoferes[i].estado==OCUPADO){
            tieneCamion=0;
            for(j=0;j<tamCamiones;j++){
                if(listadoChoferes[i].id == listadoCamiones[j].idChofer){
                    tieneCamion++;
                }
                if(tieneCamion==0 && j==tamCamiones-1){
                    mostrarUnChofer(listadoChoferes[i]);
                }
            }
        }
    }
}

void mostrarTodosLosChoferesConCamiones(eChofer listadoChoferes[], int tamChoferes,eCamion listadoCamiones[], int tamCamiones){
    int i;
    int j;
    int tieneCamion;  //FLAG para verificar si cada chofer tiene o no por lo menos un camion
    for(i=0; i<tamChoferes; i++){
        if(listadoChoferes[i].estado==OCUPADO){
            tieneCamion=0;
            mostrarUnChofer(listadoChoferes[i]);
            for(j = 0;j<tamCamiones;j++){
                if(listadoChoferes[i].id == listadoCamiones[j].idChofer){
                    mostrarCamion(listadoCamiones[j]);
                    tieneCamion++;
                }
                if(tieneCamion==0 && j==tamCamiones-1){
                    printf("No tiene camiones al mando\n");
                }
            }
            printf("*************************************\n");
        }
   }
}

void modificarCamion(eCamion listaCamiones[],int tamCamiones,eChofer listaChoferes[],int tamChoferes){
    int indiceCamion;
    int indiceChofer;
    int id;
    int opcion;

    printf("Modificar camion\n");
    getInt(&id,"Ingrese el ID a modificar\n","Error : ingrese un numero valido\n",2000,2025);
    printf("1. Tipo de camion\n2. Chofer\n");
    getInt(&opcion,"Ingrese la opcion a modificar","Error : ingrese un numero valido\n",1,2);
    indiceCamion = buscarPosicionCamion(listaCamiones,tamCamiones,id);
    switch(opcion){
        case 1:
            getTipo(listaCamiones[indiceCamion].tipo,"Ingrese el tipo : ","Error, Ingrese un tipo valido\n");
            printf("Modificado con exito\n");
            mostrarCamion(listaCamiones[indiceCamion]);
            break;
        case 2:
            getInt(&id,"Ingrese el id del chofer : ","Error, Ingrese un tipo valido\n",1,18);
            indiceChofer = buscarPosicionChofer(listaChoferes,tamChoferes,id); //busco la posicion del chofer para verificar si existe
            if(indiceChofer!=-1){
                listaCamiones[indiceCamion].idChofer = id;
            }else{
                printf("Ha ingresado un id que no existe en la lista de choferes\n");
            }
            mostrarCamion(listaCamiones[indiceCamion]);
            break;
        default:
            printf("opcion incorrecta\n");
    }
}


void eliminarChoferConCamiones(eChofer listadoChoferes[],int tamChoferes,eCamion listadoCamiones[],int tamCamiones){
    int indice;
    int id;
    int i;

    getInt(&id,"Ingrese el ID a eliminar","Error : ingrese un numero valido\n",1,18);
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
    int i;  //cantidad de choferes
    int j;  //cantidad de camiones
    int k;  //tipos de camiones
    for(k=0;k<tamTipos;k++){
        printf("<<<<<CHOFERES CON TIPO DE CAMION : %s>>>>>>\n",tipoCamion[k]);
        for(i=0; i<tamChoferes; i++){
            if(listadoChoferes[i].estado==OCUPADO){
                for(j = 0;j<tamCamiones;j++){
                     if(listadoCamiones[j].estado==OCUPADO){
                        if((listadoChoferes[i].id == listadoCamiones[j].idChofer)&&(stricmp(listadoCamiones[j].tipo,tipoCamion[k])==0)){
                            printf("CHOFER : \n");
                            mostrarUnChofer(listadoChoferes[i]);
                            printf("CAMION A CARGO : \n");
                            mostrarCamion(listadoCamiones[j]);
                        }
                     }
                }
            }
        }
        printf("*********************************************\n");
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

void listarCamionesConDiezAniosAntiguedad(eChofer listadoChoferes[],int tamChoferes,eCamion listadoCamiones[],int tamCamiones){
    int i;
    int j;
    int encontreDuenio; //FLAG para verificar si el camion tiene o no chofer a cargo
    printf("Camiones con mas de 10 anios de antiguedad\n");
    for(i = 0;i<tamCamiones;i++){
        if(listadoCamiones[i].estado==OCUPADO){
            if(listadoCamiones[i].anio < 2010){
                encontreDuenio=0;
                mostrarCamion(listadoCamiones[i]);
                printf("Chofer que lo conduce : \n");
                for(j=0;j<tamChoferes;j++){
                    if(listadoChoferes[j].estado==OCUPADO){
                        if(listadoCamiones[i].idChofer == listadoChoferes[j].id){
                            encontreDuenio=1;
                            mostrarUnChofer(listadoChoferes[j]);
                        }
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

    eChofer auxChofer; //Aux para hacer el ordenamiento de la lista de choferes

    eCamionesPorChofer listadoCamionesPorChofer[tamChoferes];
    eCamionesPorChofer auxCamionesPorChofer; //Aux para hacer el ordenamiento del listado de camiones por chofer

    //mando el listado de camiones por chofer(vacio) con el listado de choferes y asi tener la cantidad de camiones de cada chofer
    contarCamionesPorChofer(listadoCamionesPorChofer,listadoChoferes,tamChoferes,listadoCamiones,tamCamiones);

    for(i=0; i<tamChoferes-1;i++){
        if(listadoChoferes[i].estado==OCUPADO){
            for(j=i+1; j<tamChoferes;j++){
                if(listadoCamionesPorChofer[i].cantidadCamiones>listadoCamionesPorChofer[j].cantidadCamiones){

                    auxCamionesPorChofer = listadoCamionesPorChofer[i];
                    listadoCamionesPorChofer[i] = listadoCamionesPorChofer[j];
                    listadoCamionesPorChofer[j] = auxCamionesPorChofer;

                    auxChofer = listadoChoferes[i];
                    listadoChoferes[i] = listadoChoferes[j];
                    listadoChoferes[j] = auxChofer;
                }
            }
        }
    }
    mostrarChoferesConCantidadCamiones(listadoCamionesPorChofer,listadoChoferes,tamChoferes);
}

void mostrarChoferesConCantidadCamiones(eCamionesPorChofer listadoCamionesPorChofer[],eChofer listadoChoferes[],int tamChoferes){
    int i;
    for(i=0;i<tamChoferes;i++){
        if(listadoChoferes[i].estado == OCUPADO){
            mostrarUnChofer(listadoChoferes[i]);
            printf("Cantidad de camiones : %d\n",listadoCamionesPorChofer[i].cantidadCamiones);
            printf("\n");
        }
    }
}

void contarCamionesPorChofer(eCamionesPorChofer listadoCamionesPorChofer[],eChofer listadoChoferes[],int tamChoferes,eCamion listadoCamiones[],int tamCamiones){
    int i;
    int j;
    //inicializo primero el listado de camiones por chofer con los id de cada chofer y el contador en cero
    for(i=0;i<tamChoferes;i++){
        if(listadoChoferes[i].estado==OCUPADO){
            listadoCamionesPorChofer[i].cantidadCamiones=0;
            listadoCamionesPorChofer[i].idChofer=listadoChoferes[i].id;
        }
    }
    for(i=0;i<tamChoferes;i++){
        if(listadoChoferes[i].estado==OCUPADO){
            for(j=0;j<tamCamiones;j++){  //Por cada chofer reviso el listado de camiones para contar cuantos camiones tiene a cargo
                if(listadoCamiones[j].estado == OCUPADO){
                    if(listadoCamiones[j].idChofer==listadoChoferes[i].id){
                        listadoCamionesPorChofer[i].cantidadCamiones++;
                    }
                }
            }
        }
    }
}


void ordenarChoferesPorCantidadDeCamionesNombre(eChofer listadoChoferes[],int tamChoferes,eCamion listadoCamiones[],int tamCamiones){
    int i;
    int j;

    eChofer auxChofer; //Aux de camion para realizar el ordenamiento

    eCamionesPorChofer listadoCamionesPorChofer[tamChoferes];
    eCamionesPorChofer auxCamionesPorChofer; //Aux para hacer el ordenamiento del listado de camiones por chofer

    //mando el listado de camiones por chofer(vacio) con el listado de choferes y asi tener la cantidad de camiones de cada chofer
    contarCamionesPorChofer(listadoCamionesPorChofer,listadoChoferes,tamChoferes,listadoCamiones,tamCamiones);

    for(i=0; i<tamChoferes-1;i++){
        for(j=i+1; j<tamChoferes;j++){
            if(listadoCamionesPorChofer[i].cantidadCamiones>listadoCamionesPorChofer[j].cantidadCamiones || stricmp(listadoChoferes[i].nombre,listadoChoferes[j].nombre)>0){
                auxCamionesPorChofer = listadoCamionesPorChofer[i];
                listadoCamionesPorChofer[i] = listadoCamionesPorChofer[j];
                listadoCamionesPorChofer[j] = auxCamionesPorChofer;

                auxChofer = listadoChoferes[i];
                listadoChoferes[i] = listadoChoferes[j];
                listadoChoferes[j] = auxChofer;
            }
        }
    }
    mostrarChoferesConCantidadCamiones(listadoCamionesPorChofer,listadoChoferes,tamChoferes);

}
