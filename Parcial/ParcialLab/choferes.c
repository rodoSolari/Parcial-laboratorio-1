#include "choferes.h"
void hardCodearChoferes(eChofer listado[],int tam){
    int id[TAM_HARDCODEO_CHOFERES]={1,2,3,4,5,6};
    char apellido[TAM_HARDCODEO_CHOFERES][TAM_STRING]={"Lucrecia","Jorge","Natalia","Matias","Geremias","Lopez"};
    double dni[TAM_HARDCODEO_CHOFERES] = {11542154,45125454,20544487,44458784,44778469,10200548};
    int legajo[TAM_HARDCODEO_CHOFERES]={17780,17781,17782,17783,17784,17785};
    char nacionalidad[TAM_HARDCODEO_CHOFERES][TAM_STRING]={"Argentina","Argentina","Argentina","Canadiense","Aleman","Finlandes"};
    double telefono[TAM_HARDCODEO_CHOFERES] = {49845124,49784512,49875961,49887755,493268971,44124578};
    int edad[TAM_HARDCODEO_CHOFERES] = {40,55,21,46,27,40};
    char sexo[TAM_HARDCODEO_CHOFERES] = {'f','m','m','m','m','m'};
    for(int i=0; i<6;i++){
        listado[i].id = id[i];
        strcpy(listado[i].apellido,apellido[i]);
        listado[i].dni = dni[i];
        listado[i].legajo = legajo[i];
        strcpy(listado[i].nacionalidad,nacionalidad[i]);
        listado[i].telefono = telefono[i];
        listado[i].edad = edad[i];
        listado[i].sexo = sexo[i];
    }

}

void mostrarUnChofer(eChofer chofer , eCamion listadoCamiones[], int tam)
{
    eCamion camionAux;

    camionAux=buscarCamion(listadoCamiones, tam, chofer.idCamion);
    printf("__________Datos del chofer________\n");
    printf ("id : %d\t apellido :%s \t dni : %d \tlegajo:%d \t nacionalidad: %s \nTelefono: %d \tedad: %d \tsexo: %c\n",chofer.id,
                                                            chofer.apellido,
                                                            chofer.dni,
                                                            chofer.legajo,
                                                            chofer.nacionalidad,
                                                            chofer.telefono,
                                                            chofer.edad,
                                                            chofer.sexo);
}

void mostrarTodosLosChoferes(eChofer listado[], int tamChoferes,eCamion listadoCamiones[], int tamCamiones)
{
    int i;
    int j;
    int tieneCamion;
    for(i=0; i<tamChoferes; i++)
    {
        tieneCamion=0;
        mostrarUnChofer(listado[i],listadoCamiones,tamChoferes);
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

