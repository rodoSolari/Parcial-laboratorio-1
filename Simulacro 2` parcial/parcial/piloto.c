#include "piloto.h"


void hardCodearDatosListaPilotos(LinkedList* linkedListPilotos){
    int idPiloto[5] = {1,2,3,4,5};
    char nombre[5][30] = {"Alex lifeson","Richard bach","John kerry","Erwin rommel","Stephen coonts"};
    ePiloto* piloto;
    int i;
    for(i=0;i<5;i++){
        piloto = ePiloto_new();
        ePiloto_setIdPiloto(piloto,idPiloto[i]);
        ePiloto_setNombre(piloto,nombre[i]);
        ll_add(linkedListPilotos,piloto);
    }
}


ePiloto* ePiloto_new()
{
    return (ePiloto*) malloc(sizeof(ePiloto));
}

/*ePiloto* ePiloto_newParametros(char* idStr,char* idStr2)
{
    ePiloto* this = ePiloto_new();
    int idVuelo;

    if(this!=NULL){
        idPiloto = atoi(idStr3);
        cantPasajeros = atoi(cantPasajerosStr);
        horaDespegue = atoi(horaDespegueStr);
        horaLlegada = atoi(horaLlegadaStr);

        ePiloto_setIdVuelo(this,idVuelo);
        ePiloto_setIdAvion(this,idAvion);
        ePiloto_setIdPiloto(this,idPiloto);
        ePiloto_setFecha(this,fechaStr);
        ePiloto_setDestino(this,destinoStr);
        ePiloto_setCantPasajeros(this,cantPasajeros);
        ePiloto_sethoraDespegue(this,horaDespegue);
        ePiloto_sethoraLlegada(this,horaLlegada);

    }else{
        ePiloto_delete(this);
    }
    return this;
}*/

void ePiloto_delete(ePiloto* this){
    free(this);
}

int ePiloto_setNombre(ePiloto* this,char* nombre)
{
    int retorno = 0;
	if(this != NULL && nombre != NULL)
	{
        retorno = 1;
        strncpy(this->nombre,nombre,30);
	}
	return retorno;
}

int ePiloto_getNombre(ePiloto* this,char* nombre)
{
    int retorno = 0;
	if(this != NULL && nombre != NULL)
	{
		retorno = 1;
		strncpy(nombre,this->nombre,30);
	}
	return retorno;
}

int ePiloto_setIdPiloto(ePiloto* this,int id)
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
int ePiloto_getIdPiloto(ePiloto* this,int* id)
{
    int retorno = 0;
	if(this != NULL && id != NULL)
	{
		retorno = 1;
		*id = this->idPiloto;
	}
	return retorno;
}
