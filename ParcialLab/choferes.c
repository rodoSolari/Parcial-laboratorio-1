#include "choferes.h"
#include "funcionesParaValidarDatos.h"

void hardCodearChoferes(eChofer listado[],int tam){
    int id[TAM_HARDCODEO_CHOFERES]={1,2,3,4,5,6};
    char apellido[TAM_HARDCODEO_CHOFERES][TAM_STRING]={"Rodriguez","Hurtado","Alvarez","Bolsch","Vautier","Lopez"};
    char nombre[TAM_HARDCODEO_CHOFERES][TAM_STRING]={"Lucrecia","Jorge","Natalia","Matias","Geremias","Lautaro"};
    double dni[TAM_HARDCODEO_CHOFERES] = {11542154,45125454,20544487,44458784,44778469,10200548};
    int legajo[TAM_HARDCODEO_CHOFERES]={17780,17781,17782,17783,17784,17785};
    char nacionalidad[TAM_HARDCODEO_CHOFERES][TAM_STRING]={"Argentina","Argentina","Argentina","Canadiense","Aleman","Finlandes"};
    double telefono[TAM_HARDCODEO_CHOFERES] = {49845124,49784512,49875961,49887755,493268971,44124578};
    int edad[TAM_HARDCODEO_CHOFERES] = {40,55,21,46,27,40};
    char sexo[TAM_HARDCODEO_CHOFERES] = {'f','m','m','m','m','m'};
    for(int i=0; i<6;i++){
        listado[i].id = id[i];
        strcpy(listado[i].nombre,nombre[i]);
        strcpy(listado[i].apellido,apellido[i]);
        listado[i].dni = dni[i];
        listado[i].legajo = legajo[i];
        strcpy(listado[i].nacionalidad,nacionalidad[i]);
        listado[i].telefono = telefono[i];
        listado[i].edad = edad[i];
        listado[i].sexo = sexo[i];
        listado[i].estado = OCUPADO;
    }

}

void mostrarUnChofer(eChofer chofer)
{
    printf("__________Datos del chofer________\n");
    printf ("id : %d \t nombre: %s \tapellido :%s \t dni : %d \tlegajo:%d \t nacionalidad: %s \nTelefono: %d \tedad: %d \tsexo: %c\n",chofer.id,chofer.nombre,
                                                            chofer.apellido,
                                                            chofer.dni,
                                                            chofer.legajo,
                                                            chofer.nacionalidad,
                                                            chofer.telefono,
                                                            chofer.edad,
                                                            chofer.sexo);
}

void mostrarListadoChoferes(eChofer listado[], int tam){
    int i;
    printf("LISTADO DE CHOFERES\n");
    for(i=0;i<tam;i++){
        mostrarUnChofer(listado[i]);
    }
    printf("_____________________________________\n");
}

void mostrarChoferesDisponibles(eChofer listado[],int tam){
    int i;
    printf("Listado de choferes disponibles");
    for(i=0;i<tam;i++){
        if(listado[i].estado == LIBRE){
            mostrarUnChofer(listado[i]);
        }
    }
}

void mostrarTodosLosChoferes(eChofer listado[], int tamChoferes,eCamion listadoCamiones[], int tamCamiones)
{
    int i;
    int j;
    int tieneCamion;
    for(i=0; i<tamChoferes; i++)
    {
        tieneCamion=0;
        mostrarUnChofer(listado[i]);
        for(j = 0;j<tamCamiones;j++){
            if(listado[i].id == listadoCamiones[j].idChofer){
                mostrarCamion(listadoCamiones[j]);
                tieneCamion++;
            }
            if(tieneCamion==0 && j==tamCamiones-1){
                printf("No tiene camiones al mando\n");
            }
        }
   }
}

