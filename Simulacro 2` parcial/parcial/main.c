#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "parser.h"
#include "piloto.h"
#include "vuelo.h"
#include "Controller.h"
#include "Menu.h"

int main()
{
    int opcion;
    int retorno;
    LinkedList* listaVuelos = ll_newLinkedList();
    LinkedList* listaPilotos = ll_newLinkedList();
    //hardCodearDatosListaPilotos(listaPilotos);
    //controller_Solari_LoadPilotosToText("pilotos.csv",listaPilotos);
    controller_Solari_LoadPilotosFromText("pilotos.csv",listaPilotos);

    do{
        imprimirMenuInicial();
        scanf("%d",&opcion);
        switch(opcion)
        {
            case 1:
                retorno = controller_Solari_LoadVuelosFromText("Vuelos.csv", listaVuelos);
                imprimirMensajeRetorno(retorno,"cargado con exito\n","Error, no existe el archivo o la lista\n");
                break;
            case 2:
                retorno = controller_Solari_PrintAllVuelos(listaVuelos,listaPilotos);
                imprimirMensajeRetorno(retorno,"Controlador realizado con exito\n","Error, la lista esta vacia o no existe\n");
                break;
            case 3:
                retorno = controller_Solari_ContarCantidadPasajeros(listaVuelos);
                imprimirMensajeRetorno(retorno,"Controlador realizado con exito\n","Error, la lista esta vacia o no existe\n");
                break;
            case 4:
                retorno = controller_Solari_ContarCantidadPasajerosIrlanda(listaVuelos);
                imprimirMensajeRetorno(retorno,"Controlador realizado con exito\n","Error, la lista esta vacia o no existe\n");
                break;
            case 5:
                retorno = controller_Solari_FiltrarVuelosCortos("NuevoArchivo.csv",listaVuelos,listaPilotos);
                imprimirMensajeRetorno(retorno,"Filtrado de vuelos cortos realizado con exito\n","Error, no existe el archivo o la lista\n");
                break;
            case 6:
                retorno = controller_Solari_ListVuelosPortugal(listaVuelos,listaPilotos);
                imprimirMensajeRetorno(retorno,"Listado con exito vuelos a portugal\n","Error, la lista esta vacia o no existe\n");
                break;
            case 7:
                retorno = controller_Solari_FiltrarAlexLifeson(listaVuelos,listaPilotos);
                imprimirMensajeRetorno(retorno,"filtrado piloto Alex Lifeson de la lista\n","Error, la lista esta vacia o no existe\n");
                break;
            case 8:
                retorno = controller_Solari_MostrarVuelosSinPiloto(listaVuelos,listaPilotos);
                imprimirMensajeRetorno(retorno,"filtrado lista por nombre ingresado\n","Error, la lista esta vacia o no existe\n");
                break;
            case 9:
                retorno = controller_Solari_MostrarVuelosPiloto(listaVuelos,listaPilotos);
                imprimirMensajeRetorno(retorno,"filtrado lista por nombre ingresado\n","Error, la lista esta vacia o no existe\n");
                break;
            default :
                if(opcion!=10){
                    printf("Opcion incorrecta, por favor vuelva a ingresar una opcion \n");
                }
                break;

        }
        system("pause");
        system("cls");
    }while(opcion != 10);
    return 0;
}
