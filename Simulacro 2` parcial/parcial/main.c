#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "parser.h"
#include "piloto.h"
#include "vuelo.h"
#include "Controller.h"

int main()
{
    int opcion;
    //int retorno;
    LinkedList* listaVuelos = ll_newLinkedList();
    LinkedList* listaPilotos = ll_newLinkedList();
    hardCodearDatosListaPilotos(listaPilotos);
    do{
        printf(" 1. Cargar archivo\n");
        printf(" 2. Imprimir vuelos\n");
        printf(" 3. Cantidad de pasajeros totales\n");
        printf(" 4. Cantidad de pasajeros  a Irlanda\n");
        printf(" 5. Filtrar vuelos cortos(menores a 3 horas)\n");
        printf(" 6. Listar vuelos a Portugal\n");
        printf(" 7. Filtrar a Alex Lifeson\n");
        printf(" 8. Filtrar vuelos de irlanda");
        printf(" 8. Salir\n");
        scanf("%d",&opcion);

        switch(opcion)
        {
            case 1:
                controller_loadFromText("Vuelos.csv", listaVuelos);
                break;
            case 2:
                controller_printAllVuelos(listaVuelos,listaPilotos);
                break;
            case 3:
                controllerContarCantidadPasajeros(listaVuelos);
                break;
            case 4:
                controllerContarCantidadPasajerosIrlanda(listaVuelos);
                break;
            case 5:
                controllerFiltrarVuelosCortos(listaVuelos,listaPilotos);
                break;
            case 6:
                controllerListVuelosPortugal(listaVuelos,listaPilotos);
                break;
            case 7:
                controllerFiltrarAlexLifeson(listaVuelos,listaPilotos);
                break;
            case 8:
                filtrarVuelosIrlanda(listaVuelos,listaPilotos);
                break;

        }
        system("pause");
        system("cls");
    }while(opcion != 10);
    return 0;
}
