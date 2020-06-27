#include "parser.h"

int parser_vueloFromText(FILE* pFile, LinkedList* pArrayListVuelos)
{
    int r,i=0;
    int respuesta;
    ll_clear(pArrayListVuelos); //Por si ya habia cargado datos desde otro archivo
    char var1[50],var2[50],var3[50],var4[50],var5[50],var6[50],var7[50],var8[50];
    eVuelo* auxVuelo;
    if(pFile == NULL || pArrayListVuelos == NULL){
        respuesta = -1;
    }else{
        do{
            if(i==0){
                fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",var1,var2,var3,var4,var5,var6,var7,var8);
            }
            r = fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",var1,var2,var3,var4,var5,var6,var7,var8);
            if(r==8){
                auxVuelo = eVuelo_newParametros(var1,var2,var3,var4,var5,var6,var7,var8);
                ll_add(pArrayListVuelos,auxVuelo);
                i++;
            }
            else{
                break;
            }
        }while(!feof(pFile));
        respuesta = 1;
    }
    fclose(pFile);
    return respuesta;
}

