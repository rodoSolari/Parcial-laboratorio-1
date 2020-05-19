#include "choferes.h"
#include "funcionesParaValidarDatos.h"

static int contadorId = 0;

void hardCodearChoferes(eChofer listado[],int tam){
    int id[TAM_HARDCODEO_CHOFERES]={1,2,3,4,5,6};
    char apellido[TAM_HARDCODEO_CHOFERES][TAM_STRING]={"Rodriguez","Hurtado","Alvarez","Bolsch","Vautier","Lopez"};
    char nombre[TAM_HARDCODEO_CHOFERES][TAM_STRING]={"Lucrecia","Jorge","Natalia","Matias","Geremias","Lautaro"};
    //char dni[TAM_HARDCODEO_CHOFERES][TAM_DNI] = {"11542154","45125454","20544487","44458784","44778469","10200548"};
    long dni[TAM_HARDCODEO_CHOFERES] = {11542154,45125454,20544487,44458784,44778469,10200548};
    int legajo[TAM_HARDCODEO_CHOFERES]={17780,17781,17782,17783,17784,17785};
    char nacionalidad[TAM_HARDCODEO_CHOFERES][TAM_STRING]={"Argentina","Argentina","Argentina","Canadiense","Aleman","Finlandes"};
    //char telefono[TAM_HARDCODEO_CHOFERES][TAM_TELEFONO] = {"49845124","49784512","49875961","49887755","493268971","44124578"};
    long telefono[TAM_HARDCODEO_CHOFERES] = {49845124,49784512,49875961,49887755,493268971,44124578};
    int edad[TAM_HARDCODEO_CHOFERES] = {40,55,21,46,27,40};
    char sexo[TAM_HARDCODEO_CHOFERES] = {'f','m','m','m','m','m'};
    for(int i=0; i<6;i++){
        listado[i].id = id[i];
        strcpy(listado[i].nombre,nombre[i]);
        strcpy(listado[i].apellido,apellido[i]);
        //strcpy(listado[i].dni,dni[i]);
        listado[i].dni=dni[i];
        listado[i].legajo = legajo[i];
        strcpy(listado[i].nacionalidad,nacionalidad[i]);
        //strcpy(listado[i].telefono,telefono[i]);
        listado[i].telefono=telefono[i];
        listado[i].edad = edad[i];
        listado[i].sexo = sexo[i];
        listado[i].estado = OCUPADO;
        contadorId++;
    }

}

void mostrarUnChofer(eChofer chofer)
{
    printf("__________Datos del chofer________\n");
    printf ("id : %d \t nombre: %s \tapellido :%s \t dni : %li \tlegajo:%d \t nacionalidad: %s \nTelefono: %li \tedad: %d \tsexo: %c\n",chofer.id,chofer.nombre,
                                                            chofer.apellido,
                                                            chofer.dni,
                                                            chofer.legajo,
                                                            chofer.nacionalidad,
                                                            chofer.telefono,
                                                            chofer.edad,
                                                            chofer.sexo);
}

eChofer cargarChofer(){
    eChofer nuevoChofer;
    char sexo;
    getString(nuevoChofer.nombre,"Nombre del chofer : ","Error, por favor ingrese un nombre valido\n");
    getString(nuevoChofer.apellido,"Apellido del chofer : ","Error, por favor ingrese un apellido valida\n");
    getLong(&nuevoChofer.dni,"DNI : ","Error, por favor ingrese una patente valida");
    getInt(&nuevoChofer.legajo,"Peso","Error, por favor ingrese un legajo valido");
    getString(nuevoChofer.nacionalidad,"Nacionalidad : ","Error, por favor ingrese un tipo valido\n");
    getLong(&nuevoChofer.telefono,"telefono : ","Error, por favor ingrese un telefono valido\n");
    printf("ingrese el sexo: f/m : ");
    scanf("%c",&sexo);
    while(sexo!= 'f' && sexo!= 'm'){
        printf("Error, ingrese un sexo valido\n");
        scanf("%c",&sexo);
    }
    nuevoChofer.estado = OCUPADO;
    nuevoChofer.id = contadorId + 1;
    return nuevoChofer;
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

void mostrarTodosLosChoferes(eChofer listado[], int tamChoferes,eCamion listadoCamiones[], int tamCamiones){
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

int buscarPosicionChofer(eChofer listado[],int tam, int id){
    int respuesta = -1;
	int i;
    for(i=0;i<tam;i++){
        if(listado[i].id == id){
            respuesta = i;
            break;
        }
    }
    return respuesta;
}

/*void eliminarChofer(eChofer listadoChoferes[],int tamChoferes,eCamion listadoCamiones[],int tamCamiones){
    int indice;
    int id;
    int i;
    getInt(&id,"Ingrese el ID a eliminar","Error : ingrese un numero valido");
    indice = buscarPosicionChofer(listadoChoferes,tamChoferes,id);
    if(indice>=0){
        mostrarUnChofer(listadoChoferes[indice]);
        for(i=0;i<tamCamiones;i++){
            if(listadoChoferes[indice].idCamion == listadoCamiones[i].idChofer){
                listadoCamiones[i].estado = LIBRE;
            }
        }
        listadoChoferes[indice].estado = LIBRE;
        printf("Eliminado\n");
    }else{
        printf("No existe\n");
    }

}*/

void modificarChofer(eChofer listado[],int tam){
    int indice;
    int id;
    int opcion;
    eChofer auxChofer;
    printf("Modificar chofer\n");
    getInt(&id,"Ingrese el ID a modificar","Error : ingrese un numero valido");
    indice=buscarPosicionChofer(listado, tam, id);
    do{
        printf("1. Nombre:\n2.Apellido\n3.Dni\n4.Legajo\n5.Nacionalidad\n");
        printf("6. Telefono:\n7.edad\n8.Sexo\n9.Salir\n");
        printf("Ingrese la opcion que quiera modificar del empleado: \n");
        scanf("%d",&opcion);
        switch(opcion){
            case 1:
                getString(auxChofer.nombre,"Nombre : ","Error : por favor ingreselo de nuevo\n");
                strcpy(listado[indice].nombre,auxChofer.nombre);
                break;
            case 2:
                getString(auxChofer.apellido,"Apellido : ","Error : por favor ingreselo de nuevo\n");
                strcpy(listado[indice].apellido,auxChofer.apellido);
                break;
            case 3:
                getLong(&auxChofer.dni,"Dni : ","Error : por favor ingreselo de nuevo\n");
                listado[indice].dni = auxChofer.dni;
                break;
            case 4:
                getInt(&auxChofer.legajo,"legajo : ","Error : por favor ingreselo de nuevo\n");
                listado[indice].legajo = auxChofer.legajo;
                break;
            case 5:
                getString(auxChofer.nacionalidad,"Nacionalidad : ","Error : por favor ingreselo de nuevo\n");
                strcpy(listado[indice].nacionalidad,auxChofer.nacionalidad);
                break;
            case 6:
                getLong(&auxChofer.telefono,"telefono : ","Error : por favor ingreselo de nuevo\n");
                listado[indice].telefono = auxChofer.telefono;
                break;
            case 7:
                getInt(&auxChofer.edad,"Edad : ","Error : por favor ingreselo de nuevo\n");
                listado[indice].edad = auxChofer.edad;
                break;
            case 8:
                printf("Sexo: ");
                scanf("%c",&auxChofer.sexo);
                while(auxChofer.sexo!='m' && auxChofer.sexo!='f'){
                    printf("Error : por favor ingreselo de nuevo\n");
                }
                listado[indice].sexo = auxChofer.sexo;
                break;
        }
    }while(opcion!=9);
    printf("Modificado con exito!\n");
    mostrarListadoChoferes(listado,MAX_CHOFERES);

}


void mostrarCamionesPorMarca(eCamion listado[],int tam,char* marca){
    int i;
    printf("Lista de camiones de la marca %s",marca);
    for(i=0;i<tam;i++){
        if(stricmp(listado[i].marca,marca)==0){
            mostrarCamion(listado[i]);
        }
    }
}







void calcularPromedioEdad(eChofer listado[],int tam){
    int i;
    int promedioEdad = 0;
    for(i=0;i<tam;i++){
        promedioEdad+=listado[i].edad;
    }
    printf("Promedio general de edad de choferes : %d",promedioEdad);
}
