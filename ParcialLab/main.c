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
    hardCodearChoferes(listaChoferes,CANT_CHOFERES);
    hardCodearCamiones(listaCamiones,CANT_CAMIONES);
    mostrarListadoChoferes(listaChoferes, CANT_CHOFERES);//punto 1
    mostrarListadoCamiones(listaCamiones, CANT_CAMIONES);// punto 2
    mostrarTodosLosChoferes(listaChoferes,CANT_CHOFERES,listaCamiones,CANT_CAMIONES); //punto 3
/*__________________________________________________________________________________________*/
    //ALTA DE CAMION
    //cargarCamion(listaCamiones,MAX_CAMIONES);
    //mostrarChoferesDisponibles(listaChoferes,MAX_CHOFERES); //PUNTO 4

    //BAJA DE CAMION
    //eliminarCamion(listaCamiones,MAX_CAMIONES); //PUNTO 5

    //modificarCamion(listaCamiones,MAX_CAMIONES); //PUNTO 6
/*__________________________________________________________________________________________*/
    //ALTA DE CHOFER
    //eChofer cargarChofer(); //OPCION 7
    //eliminarChoferConCamiones(listaChoferes,MAX_CHOFERES,listaCamiones,MAX_CAMIONES); //PUNTO 8
    //mostrarChoferesPorTipoCamion(listaChoferes,MAX_CHOFERES,listaCamiones,MAX_CAMIONES,TAM_TIPOS); //PUNTO 9
/*___________________________________________________________________________________________*/
    //modificarChofer(listaChoferes,MAX_CHOFERES); //PUNTO 10
    //mostrarChoferesConMasDeUnCamion(listaChoferes,MAX_CHOFERES,listaCamiones,MAX_CAMIONES); //PUNTO 11
    //listarCamionesConDiezAniosAntiguedad(listaChoferes,MAX_CHOFERES,listaCamiones,MAX_CAMIONES); //PUNTO 12
/*___________________________________________________________________________________________*/
    //mostrarCamionesPorMarca(listaCamiones,MAX_CAMIONES,"fiat"); //PUNTO 13
    //ordenarChoferesPorCantidadDeCamiones(listaChoferes,MAX_CHOFERES,listaCamiones,MAX_CAMIONES); //PUNTO  14


    //calcularPromedioEdad(listaChoferes,MAX_CHOFERES) //PUNTO 16

    /*int indice;
    int id;
    int opcion;
    eChofer auxChofer;
    printf("Modificar chofer\n");
    getInt(&id,"Ingrese el ID a modificar","Error : ingrese un numero valido");
    indice=buscarPosicionChofer(listado, tam, id);
    do{
        imprimirMenu();
        scanf("%d",&opcion);
        switch(opcion){
            case 1:
                mostrarListadoChoferes(listaChoferes, CANT_CHOFERES);//punto 1
                break;
            case 2:
                mostrarListadoCamiones(listaCamiones, CANT_CAMIONES);
                break;
            case 3:
                mostrarTodosLosChoferes(listaChoferes,CANT_CHOFERES,listaCamiones,CANT_CAMIONES);
                break;
            case 4:
                cargarCamion(listaCamiones,MAX_CAMIONES);
                mostrarChoferesDisponibles(listaChoferes,MAX_CHOFERES);
                break;
            case 5:
                eliminarCamion(listaCamiones,MAX_CAMIONES);
                break;
            case 6:
                modificarCamion(listaCamiones,MAX_CAMIONES);
                break;
            case 7:
                cargarChofer();
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
                //getMarca()
                mostrarCamionesPorMarca(listaCamiones,MAX_CAMIONES,"fiat");
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

        }
    }while(opcion!=9);
    printf("Modificado con exito!\n");
    mostrarListadoChoferes(listado,MAX_CHOFERES);

}
*/

    return 0;
}
