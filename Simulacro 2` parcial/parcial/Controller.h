#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "parser.h"
#include "vuelo.h"
#include "ValidarDatos.h"

int controller_Solari_LoadVuelosFromText(char* path , LinkedList* pArrayListVuelos);

int controller_Solari_LoadPilotosFromText(char* path, LinkedList* pArrayListPilotos);
int controller_Solari_LoadPilotosToText(char* path, LinkedList* pArrayListPilotos);

int controller_Solari_PrintAllVuelos(LinkedList* LinkedListVuelos,LinkedList* LinkedListPilotos);
int controller_Solari_ContarCantidadPasajeros(LinkedList* LinkedListVuelos);
int controller_Solari_ContarCantidadPasajerosIrlanda(LinkedList* LinkedListVuelos);
int controller_Solari_FiltrarVuelosCortos(char* path,LinkedList* LinkedListVuelos,LinkedList* LinkedListPilotos);
int controller_Solari_SaveAsTextVuelos(char* path, LinkedList* LinkedListVuelos);
int controller_Solari_ListVuelosPortugal(LinkedList* LinkedListVuelos,LinkedList* LinkedListPilotos);
int controller_Solari_FiltrarAlexLifeson(LinkedList* LinkedListVuelos,LinkedList* LinkedListPilotos);
int controller_Solari_MostrarVuelosSinPiloto(LinkedList* LinkedListVuelos,LinkedList* LinkedListPilotos);
int controller_Solari_MostrarVuelosPiloto(LinkedList* LinkedListVuelos,LinkedList* LinkedListPilotos);
