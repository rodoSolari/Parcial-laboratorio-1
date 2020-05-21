#include <stdio.h>
#include <stdlib.h>
#include "choferes.h"
#include "choferCamion.h"
#include "choferCamion.h"
#include "choferCamion.h"
#define CANT_CHOFERES 6
#define CANT_CAMIONES 10
#define MAX_CAMIONES 25

int main()
{
    eChofer listaChoferes[MAX_CHOFERES];
    eCamion listaCamiones[MAX_CAMIONES];
    inicializarListadoChoferes(listaChoferes,MAX_CHOFERES);
    inicializarListadoCamiones(listaCamiones,CANT_CAMIONES);
    hardCodearChoferes(listaChoferes,CANT_CHOFERES);
    hardCodearCamiones(listaCamiones,CANT_CAMIONES);

    int opcion;

    do{
        imprimirMenu();
        scanf("%d",&opcion);
        switch(opcion){
            case 1:
                mostrarListadoChoferes(listaChoferes, MAX_CHOFERES);//punto 1
                break;
            case 2:
                mostrarListadoCamiones(listaCamiones, MAX_CAMIONES);
                break;
            case 3:
                mostrarTodosLosChoferesConCamiones(listaChoferes,CANT_CHOFERES,listaCamiones,CANT_CAMIONES);
                break;
            case 4:
                cargarCamion(listaCamiones,MAX_CAMIONES);
                mostrarChoferesDisponibles(listaChoferes,MAX_CHOFERES,listaCamiones,CANT_CAMIONES);
                break;
            case 5:
                eliminarCamion(listaCamiones,MAX_CAMIONES);
                break;
            case 6:
                modificarCamion(listaCamiones,MAX_CAMIONES,listaChoferes,MAX_CHOFERES);
                break;
            case 7:
                cargarChofer(listaChoferes,MAX_CHOFERES);
                break;
            case 8:
                eliminarChoferConCamiones(listaChoferes,MAX_CHOFERES,listaCamiones,MAX_CAMIONES);
                break;
            case 9:
                mostrarChoferesPorTipoCamion(listaChoferes,MAX_CHOFERES,listaCamiones,MAX_CAMIONES,TAM_TIPOS);
                break;
            case 10:
                modificarChofer(listaChoferes,MAX_CHOFERES);
                break;
            case 11:
                mostrarChoferesConMasDeUnCamion(listaChoferes,MAX_CHOFERES,listaCamiones,MAX_CAMIONES);
                break;
            case 12:
                listarCamionesConDiezAniosAntiguedad(listaChoferes,MAX_CHOFERES,listaCamiones,MAX_CAMIONES);
                break;
            case 13:
                mostrarCamionesPorMarca(listaCamiones,MAX_CAMIONES);
                break;
            case 14:
                ordenarChoferesPorCantidadDeCamiones(listaChoferes,MAX_CHOFERES,listaCamiones,MAX_CAMIONES);
                break;
            case 15:
                ordenarChoferesPorCantidadDeCamionesNombre(listaChoferes,MAX_CHOFERES,listaCamiones,MAX_CAMIONES);
                break;
            case 16:
                calcularPromedioEdad(listaChoferes,MAX_CHOFERES);
                break;
            case 17:
                calcularPromedioAntiguedadCamiones(listaCamiones,MAX_CAMIONES);
                break;
            case 18:
                calcularPromedioVaronesMujeres(listaChoferes,MAX_CHOFERES);
                break;
            default:
                if(opcion!=19){
                    printf("Opcion incorrecta, por favor ingrese un numero valido\n");
                }
        }
        system("pause");
        system("cls");
    }while(opcion!=19);
    return 0;
}
