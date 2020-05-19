#include <stdio.h>
#include <stdlib.h>
#include "choferes.h"
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



    //calcularPromedioEdad(listaChoferes,MAX_CHOFERES) //PUNTO 16
    return 0;
}
