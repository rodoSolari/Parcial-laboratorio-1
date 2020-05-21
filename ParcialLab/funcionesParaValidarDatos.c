#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "funcionesParaValidarDatos.h"

int isNumeric(char stringNumber[]){
    int respuesta=1;
    int i;

    for(i=0;stringNumber[i]!='\0';i++){
        if(stringNumber[i]<'0' || stringNumber[i]>'9'){
            respuesta=0;
            break;
        }
    }
    return respuesta;
}

int isFloat(char stringNumber[]){
    int i=0;
	int retorno = 1;
	int contadorPuntos=0;

	if(stringNumber != NULL && strlen(stringNumber) > 0){
		for(i=0 ; stringNumber[i] != '\0'; i++){
			if(stringNumber[i] < '0' || stringNumber[i] > '9' ){
				if(stringNumber[i] == '.' && contadorPuntos == 0){
					contadorPuntos++;
				}else{
					retorno = 0;
					break;
				}
			}
		}
	}
	return retorno;
}

void getFloat(float* number, char* message, char* errorMessage){
    char string[MAX_STRING];

    printf("%s", message);
    fflush(stdin);
    gets(string);
    *number=atof(string);

    while(isFloat(string)==0){
        printf("%s", errorMessage);
        fflush(stdin);
        gets(string);
        *number=atof(string);
    }
}

void getInt(int* number, char* message, char* errorMessage){
    char string[MAX_STRING];
    printf("%s", message);
    fflush(stdin);
    gets(string);
    *number=atoi(string);
    while(isNumeric(string)==0){
        printf("%s", errorMessage);
        fflush(stdin);
        gets(string);
        *number=atoi(string);
    }
}


int esString(char arrayString[]){
    int respuesta=0;
    for(int i=0; arrayString[i]!='\0'; i++){
        if((arrayString[i]<'a' || arrayString[i]>'z') && (arrayString[i]<'A' || arrayString[i]>'Z')){
            respuesta=1;
            break;
        }
    }
    return respuesta;
}

void getString(char* arrayString, char* message, char* errorMessage)
{
    printf("%s", message);
    fflush(stdin);
    gets(arrayString);

    while(esString(arrayString)==1){
        printf("%s", errorMessage);
        fflush(stdin);
        gets(arrayString);
    }
}

int esTipo(char arrayString[]){
    int respuesta=0;
    char tipos[2][MAX_STRING]={"Larga distancia","Corta distancia"};
    for(int i=0; i<2; i++){
        if(stricmp(tipos[i],arrayString)==0){
            respuesta=1;
            break;
        }
    }
    return respuesta;
}

void getTipo(char* arrayString, char* message, char* errorMessage)
{
    printf("%s", message);
    fflush(stdin);
    gets(arrayString);

    while(esTipo(arrayString)==0){
        printf("%s", errorMessage);
        fflush(stdin);
        gets(arrayString);
    }
}


int esMarca(char arrayString[]){
    int respuesta=0;
    char marcas[3][MAX_STRING]={"ford","fiat","wv"};
    for(int i=0; i<3; i++){
        if(stricmp(marcas[i],arrayString)==0){
            respuesta=1;
            break;
        }
    }
    return respuesta;
}

void getMarca(char* arrayString, char* message, char* errorMessage)
{
    printf("%s", message);
    fflush(stdin);
    gets(arrayString);

    while(esString(arrayString)==1 && esMarca(arrayString)==1){
        printf("%s", errorMessage);
        fflush(stdin);
        gets(arrayString);
    }
}

void getDni(char* arrayString, char* message, char* errorMessage){
    printf("%s", message);
    fflush(stdin);
    gets(arrayString);
    int number=atoi(arrayString);
    while(isNumeric(arrayString)==0 && number>0){  //OJO, probar si funciona
        printf("%s", errorMessage);
        fflush(stdin);
        gets(arrayString);
        number=atoi(arrayString);
    }

}

void getChar(char character, char* message, char* errorMessage,char primerValor,char segundoValor){
    printf("%s", message);
    fflush(stdin);
    scanf("%c",&character);
    while(character!=primerValor && character!=segundoValor){
        printf("%s", errorMessage);
        fflush(stdin);
        scanf("%c",&character);
    }
}

void getLong(long* number, char* message, char* errorMessage){
    char string[MAX_STRING];
    printf("%s", message);
    fflush(stdin);
    gets(string);
    *number=atol(string);
    while(isNumeric(string)==0){
        printf("%s", errorMessage);
        fflush(stdin);
        gets(string);
        *number=atoi(string);
    }
}
