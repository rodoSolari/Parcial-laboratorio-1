#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "parser.h"
#include "vuelo.h"

int controller_loadFromText(char* path , LinkedList* pArrayListEmployee);
int controller_printAllVuelos(LinkedList* LinkedListVuelos,LinkedList* LinkedListPilotos);
int controllerContarCantidadPasajeros(LinkedList* LinkedListVuelos);
int controllerContarCantidadPasajerosIrlanda(LinkedList* LinkedListVuelos);
int controllerFiltrarVuelosCortos(LinkedList* LinkedListVuelos,LinkedList* LinkedListPilotos);
int controllerListVuelosPortugal(LinkedList* LinkedListVuelos,LinkedList* LinkedListPilotos);
int controllerFiltrarAlexLifeson(LinkedList* LinkedListVuelos,LinkedList* LinkedListPilotos);
