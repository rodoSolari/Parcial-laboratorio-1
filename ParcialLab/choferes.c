#include "choferes.h"
#include "funcionesParaValidarDatos.h"

static int contadorId = 0;

void hardCodearChoferes(eChofer listado[],int tam){
    int id[TAM_HARDCODEO_CHOFERES]={1,2,3,4,5,6};
    char apellido[TAM_HARDCODEO_CHOFERES][TAM_STRING]={"Rodriguez","Hurtado","Alvarez","Bolsch","Vautier","Lopez"};
    char nombre[TAM_HARDCODEO_CHOFERES][TAM_STRING]={"Lucrecia","Jorge","Natalia","Matias","Geremias","Lautaro"};
    long dni[TAM_HARDCODEO_CHOFERES] = {11542154,45125454,20544487,44458784,44778469,10200548};
    int legajo[TAM_HARDCODEO_CHOFERES]={17780,17781,17782,17783,17784,17785};
    char nacionalidad[TAM_HARDCODEO_CHOFERES][TAM_STRING]={"Argentina","Argentina","Argentina","Canadiense","Aleman","Finlandes"};
    long telefono[TAM_HARDCODEO_CHOFERES] = {49845124,49784512,49875961,49887755,493268971,44124578};
    int edad[TAM_HARDCODEO_CHOFERES] = {40,55,21,46,27,40};
    char sexo[TAM_HARDCODEO_CHOFERES] = {'f','m','m','m','m','m'};
    for(int i=0; i<6;i++){
        listado[i].id = id[i];
        strcpy(listado[i].nombre,nombre[i]);
        strcpy(listado[i].apellido,apellido[i]);
        listado[i].dni=dni[i];
        listado[i].legajo = legajo[i];
        strcpy(listado[i].nacionalidad,nacionalidad[i]);
        listado[i].telefono=telefono[i];
        listado[i].edad = edad[i];
        listado[i].sexo = sexo[i];
        listado[i].estado = OCUPADO;
        contadorId++;
    }

}

void inicializarListadoChoferes(eChofer listado[],int tam){
    int i;
    for(i=0;i<tam;i++){
        listado[i].estado = LIBRE;
    }
}

void mostrarUnChofer(eChofer chofer)
{
    printf("__________Datos del chofer________\n");
    printf ("id : %1d  \nnombre: %s  apellido :%s \ndni : %li\t legajo: %d \nNacionalidad: %5s \nTelefono: %li \tedad: %d\tsexo: %c\n",chofer.id,chofer.nombre,
                                                            chofer.apellido,
                                                            chofer.dni,
                                                            chofer.legajo,
                                                            chofer.nacionalidad,
                                                            chofer.telefono,
                                                            chofer.edad,
                                                            chofer.sexo);
    printf("__________________________________\n");
}

int buscarPosicionLibreChofer(eChofer listado[],int tam){
    int respuesta=-1;
    int i;
    for(i=0;i<tam;i++){
        if(listado[i].estado==LIBRE){
            respuesta=i;
            break;
        }
    }
    return respuesta;
}

void cargarChofer(eChofer listado[],int tam){
    int indice;
    eChofer nuevoChofer;
    indice = buscarPosicionLibreChofer(listado,tam);
    if(indice!=-1){
        getString(nuevoChofer.nombre,"Nombre del chofer : ","Error, por favor ingrese un nombre valido\n");
        getString(nuevoChofer.apellido,"Apellido del chofer : ","Error, por favor ingrese un apellido valida\n");
        getLong(&nuevoChofer.dni,"DNI : ","Error, por favor ingrese una patente valida",0,99999999);
        getInt(&nuevoChofer.legajo,"Peso","Error, por favor ingrese un legajo valido",10000,25000);
        getInt(&nuevoChofer.edad,"Edad : ","Error : por favor ingreselo de nuevo\n",18,90);
        getString(nuevoChofer.nacionalidad,"Nacionalidad : ","Error, por favor ingrese un tipo valido\n");
        getLong(&nuevoChofer.telefono,"telefono : ","Error, por favor ingrese un telefono valido\n",0,99999999);
        nuevoChofer.sexo = getChar("Sexo : ","Error, por favor ingrese un sexo valido",'f','m');
        nuevoChofer.estado = OCUPADO;
        nuevoChofer.id = contadorId;
        contadorId++;
        listado[indice] = nuevoChofer;
    }else{
        printf("No hay espacio disponible para agregar otro chofer en el listado\n");
    }
}

void mostrarListadoChoferes(eChofer listado[], int tam){
    int i;
    printf("LISTADO DE CHOFERES\n");
    for(i=0;i<tam;i++){
        if(listado[i].estado == OCUPADO){
            mostrarUnChofer(listado[i]);
        }
    }
    printf("_____________________________________\n");
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

void modificarChofer(eChofer listado[],int tam){
    int indice;
    int id;
    int opcion;
    eChofer auxChofer;
    printf("Modificar chofer\n");
    getInt(&id,"Ingrese el ID a modificar : ","Error : ingrese un numero valido : ",1,18);
    indice=buscarPosicionChofer(listado, tam, id);
    do{
        mostrarUnChofer(listado[indice]);
        printf("1. Nombre:\n2.Apellido\n3.Dni\n4.Legajo\n5.Nacionalidad\n");
        printf("6. Telefono:\n7.edad\n8.Sexo\n9.Salir\n");
        printf("Ingrese la opcion que quiera modificar del empleado: \n");
        scanf("%d",&opcion);
        switch(opcion){
            case 1:
                getString(auxChofer.nombre,"Nombre : ","Error : por favor ingreselo de nuevo : ");
                strcpy(listado[indice].nombre,auxChofer.nombre);
                break;
            case 2:
                getString(auxChofer.apellido,"Apellido : ","Error : por favor ingreselo de nuevo : ");
                strcpy(listado[indice].apellido,auxChofer.apellido);
                break;
            case 3:
                getLong(&auxChofer.dni,"Dni : ","Error : por favor ingreselo de nuevo : ",0,99999999);
                listado[indice].dni = auxChofer.dni;
                break;
            case 4:
                getInt(&auxChofer.legajo,"legajo : ","Error : por favor ingreselo de nuevo : ",10000,25000);
                listado[indice].legajo = auxChofer.legajo;
                break;
            case 5:
                getString(auxChofer.nacionalidad,"Nacionalidad : ","Error : por favor ingreselo de nuevo : ");
                strcpy(listado[indice].nacionalidad,auxChofer.nacionalidad);
                break;
            case 6:
                getLong(&auxChofer.telefono,"telefono : ","Error : por favor ingreselo de nuevo : ",0,99999999);
                listado[indice].telefono = auxChofer.telefono;
                break;
            case 7:
                getInt(&auxChofer.edad,"Edad : ","Error : por favor ingreselo de nuevo : ",18,99);
                listado[indice].edad = auxChofer.edad;
                break;
            case 8:
                auxChofer.sexo = getChar("Sexo : ","Error, por favor ingrese un sexo valido : ",'f','m');
                listado[indice].sexo = auxChofer.sexo;
                break;
            default:
                printf("Opcion incorrecta\n");
        }
    }while(opcion!=9);
    mostrarUnChofer(listado[indice]);
    printf("Modificado con exito!\n");
}


void calcularPromedioEdad(eChofer listado[],int tam){
    int i;
    int totalEdad = 0;
    int contadorChoferes = 0;
    float promedioEdad;
    for(i=0;i<tam;i++){
        if(listado[i].estado==OCUPADO){
            totalEdad+=listado[i].edad;
            contadorChoferes++;
        }
    }
    promedioEdad = (float)totalEdad/contadorChoferes;

    printf("Promedio general de edad de choferes : %.2f\n",promedioEdad);
}

void calcularPromedioVaronesMujeres(eChofer listado[],int tam){
    int i;
    float promedioHombres;
    float promedioMujeres;
    int contadorHombres = 0;
    int contadorMujeres = 0;
    int totalChoferes = 0;
    for(i=0;i<tam;i++){
        if(listado[i].estado == OCUPADO){
            if(listado[i].sexo=='f'){
                contadorMujeres++;
            }else if(listado[i].sexo=='m'){
                contadorHombres++;
            }
            totalChoferes++;
        }
    }
    promedioHombres = ((float)contadorHombres/totalChoferes)*100;
    promedioMujeres = ((float)contadorMujeres/totalChoferes)*100;
    printf("Promedio de hombres en total de choferes :  %.2f \n",(float)promedioHombres);
    printf("Promedio de mujeres en total de choferes :  %.2f \n",(float)promedioMujeres);
}
