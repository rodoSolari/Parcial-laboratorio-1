#include <stdio.h>
#include <stdlib.h>
#include "choferes.h"
#define CANT_CHOFERES 6
#define MAX_CHOFERES 18
#define CANT_CAMIONES 10
#define MAX_CAMIONES 25

int main()
{
    eChofer listaChoferes[MAX_CHOFERES];
    eCamion listaCamiones[MAX_CAMIONES];
    hardCodearChoferes(listaChoferes,CANT_CHOFERES);
    hardCodearCamiones(listaCamiones,CANT_CAMIONES);
    mostrarListadoChoferes(listaChoferes, CANT_CHOFERES);
    mostrarListadoCamiones(listaCamiones, CANT_CAMIONES);
    mostrarTodosLosChoferes(listaChoferes,CANT_CHOFERES,listaCamiones,CANT_CAMIONES);
    return 0;
}
