#include "piloto.h"


void hardCodearDatosListaPilotos(LinkedList* linkedListPilotos){
    int idPiloto[10] = {1,2,3,4,5,6,7,8,9,10};
    char nombre[10][30] = {"Alex lifeson","Richard bach","John kerry","Erwin rommel","Stephen coonts","Marcelo torneli","Gerardo corsa","Luis maraz","ignacio juarez","lorenzo roselli"};
    ePiloto* piloto;
    int i;
    for(i=0;i<10;i++){
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

ePiloto* ePiloto_newParametros(char* idStr,char* nombreStr)
{
    ePiloto* this = ePiloto_new();
    int idPiloto;

    if(this!=NULL){
        idPiloto = atoi(idStr);

        ePiloto_setIdPiloto(this,idPiloto);
        ePiloto_setNombre(this,nombreStr);

    }else{
        ePiloto_delete(this);
    }
    return this;
}

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

int getIndexOfPilotoByName(LinkedList* LinkedListPilotos,char* nombre){
    int i;
    int indice = -1;
    ePiloto* piloto;
    char nombrePiloto[30];
    for(i=0;i<ll_len(LinkedListPilotos);i++){

        piloto = ll_get(LinkedListPilotos,i);
        ePiloto_getNombre(piloto,nombrePiloto);
        if(strcmp(nombre,nombrePiloto)==0){
            indice = i;
            break;

        }
    }
    return indice;

}


int funcionFiltrarVuelosSinPiloto(void* pElement,char cadena[]){
    int returnAux = -1;
    ePiloto* piloto;
    char nombre[30];
    if(pElement!=NULL){

        piloto = (ePiloto*)pElement;

        ePiloto_getNombre(piloto,nombre);

        if(stricmp(nombre,cadena)!= 0){
            returnAux = 1;
        }
    }
    return returnAux;
}

int funcionFiltrarVuelosPiloto(void* pElement,char cadena[]){
    int returnAux = -1;
    ePiloto* piloto;
    char nombre[30];
    if(pElement!=NULL){

        piloto = (ePiloto*)pElement;

        ePiloto_getNombre(piloto,nombre);

        if(stricmp(nombre,cadena) == 0){
            returnAux = 1;
        }
    }
    return returnAux;
}
