#include "Menu.h"

void imprimirMenuInicial(){
    printf(" 1. Cargar archivo\n");
    printf(" 2. Imprimir vuelos\n");
    printf(" 3. Cantidad de pasajeros totales\n");
    printf(" 4. Cantidad de pasajeros  a Irlanda\n");
    printf(" 5. Filtrar vuelos cortos(menores a 3 horas) y generar un archivo nuevo\n");
    printf(" 6. Listar vuelos a Portugal\n");
    printf(" 7. Filtrar a Alex Lifeson\n");
    printf(" 8. Filtrar vuelos por nombre excluyendolo\n");
    printf(" 9. Filtrar vuelos por nombre\n");
    printf(" 10. Salir\n");
}

void imprimirMensajeRetorno(int valor,char* primerMensaje,char* segundoMensaje){
    if(valor==1){
        printf("%s\n",primerMensaje);
    }else if(valor == -1){
        printf("%s\n",segundoMensaje);
    }else if(valor == 0){
        printf("No existe el nombre ingresado en la lista de pilotos\n");
    }else{
        printf("Error al ejecutar el controlador\n");
    }
}
