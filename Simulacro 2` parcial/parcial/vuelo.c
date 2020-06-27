#include "vuelo.h"

eVuelo* eVuelo_new()
{
    return (eVuelo*) malloc(sizeof(eVuelo));
}

eVuelo* eVuelo_newParametros(char* idStr,char* idStr2,char*idStr3,char* fechaStr,char* destinoStr,char* cantPasajerosStr,char* horaDespegueStr,char* horaLlegadaStr)
{
    eVuelo* this = eVuelo_new();
    int idVuelo;
    int idAvion;
    int idPiloto;
    int cantPasajeros;
    int horaDespegue;
    int horaLlegada;

    if(this!=NULL){
        idVuelo = atoi(idStr);
        idAvion = atoi(idStr2);
        idPiloto = atoi(idStr3);
        cantPasajeros = atoi(cantPasajerosStr);
        horaDespegue = atoi(horaDespegueStr);
        horaLlegada = atoi(horaLlegadaStr);

        eVuelo_setIdVuelo(this,idVuelo);
        eVuelo_setIdAvion(this,idAvion);
        eVuelo_setIdPiloto(this,idPiloto);
        eVuelo_setFecha(this,fechaStr);
        eVuelo_setDestino(this,destinoStr);
        eVuelo_setCantPasajeros(this,cantPasajeros);
        eVuelo_sethoraDespegue(this,horaDespegue);
        eVuelo_sethoraLlegada(this,horaLlegada);

    }else{
        eVuelo_delete(this);
    }
    return this;
}

void eVuelo_delete(eVuelo* this){
    free(this);
}

int eVuelo_setFecha(eVuelo* this,char* fecha)
{
    int retorno = 0;
	if(this != NULL && fecha != NULL)
	{
        retorno = 1;
        strncpy(this->fecha,fecha,20);
	}
	return retorno;
}

int eVuelo_getFecha(eVuelo* this,char* fecha)
{
    int retorno = 0;
	if(this != NULL && fecha != NULL)
	{
		retorno = 1;
		strncpy(fecha,this->fecha,20);
	}
	return retorno;
}

int eVuelo_setDestino(eVuelo* this,char* destino)
{
    int retorno = 0;
	if(this != NULL && destino != NULL)
	{
        retorno = 1;
        strncpy(this->destino,destino,30);
	}
	return retorno;
}

int eVuelo_getDestino(eVuelo* this,char* destino)
{
    int retorno = 0;
	if(this != NULL && destino != NULL)
	{
		retorno = 1;
		strncpy(destino,this->destino,30);
	}
	return retorno;
}


int eVuelo_setIdAvion(eVuelo* this,int id)
{
    int retorno = 0;
    static int maximoId = -1;
    if(this!=NULL){
        retorno = 1;
        if(id<0){
            maximoId++;
            this->idAvion = maximoId;
        }else{
            if(id>maximoId){
                maximoId = id;
            }
            this->idAvion = id;
        }
    }
    return retorno;
}
int eVuelo_getIdAvion(eVuelo* this,int* id)
{
    int retorno = 0;
	if(this != NULL && id != NULL)
	{
		retorno = 1;
		*id = this->idAvion;
	}
	return retorno;
}

int eVuelo_setIdVuelo(eVuelo* this,int id)
{
    int retorno = 0;
    static int maximoId = -1;
    if(this!=NULL){
        retorno = 1;
        if(id<0){
            maximoId++;
            this->idVuelo = maximoId;
        }else{
            if(id>maximoId){
                maximoId = id;
            }
            this->idVuelo = id;
        }
    }
    return retorno;
}
int eVuelo_getIdVuelo(eVuelo* this,int* id)
{
    int retorno = 0;
	if(this != NULL && id != NULL)
	{
		retorno = 1;
		*id = this->idVuelo;
	}
	return retorno;
}

int eVuelo_setIdPiloto(eVuelo* this,int id)
{
    int retorno = 0;
    static int maximoId = -1;
    if(this!=NULL){
        retorno = 1;
        if(id<0){
            maximoId++;
            this->idPiloto = maximoId;
        }else{
            if(id>maximoId){
                maximoId = id;
            }
            this->idPiloto = id;
        }
    }
    return retorno;
}
int eVuelo_getIdPiloto(eVuelo* this,int* id)
{
    int retorno = 0;
	if(this != NULL && id != NULL)
	{
		retorno = 1;
		*id = this->idPiloto;
	}
	return retorno;
}

int eVuelo_sethoraLlegada(eVuelo* this,int horaLlegada)
{
    int retorno = 0;
    if(this!=NULL){
        this->horaLlegada = horaLlegada;
        retorno = 1;
    }
    return retorno;
}
int eVuelo_gethoraLlegada(eVuelo* this,int* horaLlegada)
{
    int retorno = 0;
	if(this != NULL && horaLlegada != NULL)
	{
		retorno = 1;
		*horaLlegada = this->horaLlegada;
	}
	return retorno;
}

int eVuelo_setCantPasajeros(eVuelo* this,int cantPasajeros)
{
    int retorno = 0;
    if(this!=NULL){
        this->cantPasajeros = cantPasajeros;
        retorno = 1;
    }
    return retorno;
}
int eVuelo_getCantPasajeros(eVuelo* this,int* cantPasajeros)
{
    int retorno = 0;
	if(this != NULL && cantPasajeros != NULL)
	{
		retorno = 1;
		*cantPasajeros = this->cantPasajeros;
	}
	return retorno;
}

int eVuelo_sethoraDespegue(eVuelo* this,int horaDespegue)
{
    int retorno = 0;
    if(this!=NULL){
        this->horaDespegue = horaDespegue;
        retorno = 1;
    }
    return retorno;
}
int eVuelo_gethoraDespegue(eVuelo* this,int* horaDespegue)
{
    int retorno = 0;
	if(this != NULL && horaDespegue != NULL)
	{
		retorno = 1;
		*horaDespegue = this->horaDespegue;
	}
	return retorno;
}

/*
int eVuelo_CompareByName(void* e1, void* e2)
{
    int respuesta = 0;
    char nombrePrimereVuelo[50];
    char nombreSegundoeVuelo[50];
    eVuelo_getNombre(e1,nombrePrimereVuelo);
    eVuelo_getNombre(e2,nombreSegundoeVuelo);
    if(stricmp(nombrePrimereVuelo, nombreSegundoeVuelo)>0){
        respuesta = 1;
    }
    return respuesta;
}

int eVuelo_CompareById(void* e1, void* e2)
{
    int idPrimereVuelo, idSegundoeVuelo;
    eVuelo_getId(e1,&idPrimereVuelo);
    eVuelo_getId(e2,&idSegundoeVuelo);

    if(idPrimereVuelo > idSegundoeVuelo)
    {
        return 1;
    }
    else
    {
        if(idPrimereVuelo < idSegundoeVuelo)
        {
            return -1;
        }
        else
        {
            return 0;
        }
    }
}

int eVuelo_CompareBySueldo(void* e1, void* e2){
    float sueldoPrimereVuelo, sueldoSegundoeVuelo;
    eVuelo_getSueldo(e1,&sueldoPrimereVuelo);
    eVuelo_getSueldo(e2,&sueldoSegundoeVuelo);

    if(sueldoPrimereVuelo > sueldoSegundoeVuelo)
    {
        return 1;
    }
    else
    {
        if(sueldoPrimereVuelo < sueldoSegundoeVuelo)
        {
            return -1;
        }
        else
        {
            return 0;
        }
    }
}

int eVuelo_CompareByhoraDespegue(void* e1, void* e2)
{
    int horaDespeguePrimereVuelo, horaDespegueSegundoeVuelo;
    eVuelo_gethoraDespegue(e1,&horaDespeguePrimereVuelo);
    eVuelo_gethoraDespegue(e2,&horaDespegueSegundoeVuelo);

    if(horaDespeguePrimereVuelo > horaDespegueSegundoeVuelo)
    {
        return 1;
    }
    else
    {
        if(horaDespeguePrimereVuelo < horaDespegueSegundoeVuelo)
        {
            return -1;
        }
        else
        {
            return 0;
        }
    }
}
*/

//2 LISTAS
void printVuelo(eVuelo* vuelo,LinkedList* linkedListPilotos){
    int indicePiloto = getIndexOfVueloById(linkedListPilotos,vuelo->idPiloto);
    ePiloto* piloto = ll_get(linkedListPilotos,indicePiloto);

    printf("%5d%9d%18s%15s%12s%12d%15d%15d   \n",vuelo->idVuelo,
                                                 vuelo->idAvion,
                                                 piloto->nombre,
                                                 vuelo->fecha,
                                                 vuelo->destino,
                                                 vuelo->cantPasajeros,
                                                 vuelo->horaDespegue,
                                                 vuelo->horaLlegada);
    printf("\n");
}

void printAllVuelos(LinkedList* LinkedListVuelos,LinkedList* LinkedListPilotos){
    int i;
    printf("ID vuelo|ID avion|  Nombre Piloto  |    fecha    |  destino  |Cantidad Pasajeros|hora Despegue|hora Llegada\n");
    for(i=0;i<ll_len(LinkedListVuelos);i++){
        printVuelo(ll_get(LinkedListVuelos,i),LinkedListPilotos);
    }
}

int getIndexOfVueloById(LinkedList* LinkedListPilotos,int id){
    int i;
    int indice = -1;
    ePiloto* piloto;
    for(i=0;i<ll_len(LinkedListPilotos);i++){

        piloto = ll_get(LinkedListPilotos,i);

        if(piloto->idPiloto==id){
            indice = i;
            break;

        }
    }
    return indice;

}


int contarPasajeros(void* pasajeros){
    int returnAux = -1;
    eVuelo* vuelo;
    int cantPasajeros;
    if(pasajeros!=NULL){
        vuelo = (eVuelo*) pasajeros;
        if(eVuelo_getCantPasajeros(vuelo,&cantPasajeros)==1){
            returnAux = cantPasajeros;
        }
    }
    return returnAux;
}

int filtrarVuelosIrlanda(LinkedList* LinkedListVuelos,LinkedList* LinkedListPilotos){
    int returnAux = -1;
    printf("Cantidad de viajes : %d\n",ll_len(LinkedListVuelos));
    LinkedList* nuevo = ll_newLinkedList();
    nuevo = ll_filter(LinkedListVuelos,funcionFiltrarIrlanda);
    if(nuevo!=NULL){

        printAllVuelos(nuevo,LinkedListPilotos);
        returnAux = 1;
    }
    return returnAux;
}

int funcionFiltrarIrlanda(void* pElement){
    int returnAux = -1;
    eVuelo* vuelo;
    if(pElement!=NULL){
        vuelo = (eVuelo*) pElement;
        if(strcmp(vuelo->destino,"Irlanda")==0){
            returnAux = 1;
        }
    }
    return returnAux;
}

int funcionContarPasajerosIrlanda(void* pElement){
    int returnAux = -1;
    eVuelo* vuelo;
    if(pElement!=NULL){
        vuelo = (eVuelo*) pElement;
        if(strcmp(vuelo->destino,"Irlanda")==0){
            returnAux = vuelo->cantPasajeros;
        }
    }
    return returnAux;
}

int funcionFiltrarVuelosCortos(void* pElement){
    int returnAux = -1;
    int totalHorasViaje;
    eVuelo* vuelo;
    if(pElement!=NULL){
        vuelo = (eVuelo*) pElement;
        totalHorasViaje = vuelo->horaLlegada - vuelo->horaDespegue;
        if(totalHorasViaje>=0 && totalHorasViaje<=3){
            returnAux = 1;
        }
    }
    return returnAux;
}

int funcionFiltrarVuelosPortugal(void* pElement){
    int returnAux = -1;
    eVuelo* vuelo;
    if(pElement!=NULL){
        vuelo = (eVuelo*) pElement;
        if(strcmp(vuelo->destino,"Portugal")==0){
            returnAux = 1;
        }
    }
    return returnAux;
}


int funcionFiltrarAlexLifeson(void* pElement){
    int returnAux = -1;
    eVuelo* vuelo;
    int id;
    if(pElement!=NULL){
        vuelo = (eVuelo*) pElement;
        if(eVuelo_getIdPiloto(vuelo,&id)==1 && id!=-1){
            returnAux = 1;
        }
    }
    return returnAux;
}
