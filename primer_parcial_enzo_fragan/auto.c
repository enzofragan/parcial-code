#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "auto.h"

int eAu_inicio(eAuto listaA[],int limite)
{
    int retorno=-1;
    int i;


    if(limite>0)
    {
        retorno=0;
        for(i=0; i<limite; i++)
        {
            listaA[i].estado=0;
            strcpy(listaA[i].patente,"");
            listaA[i].marca=0;
            listaA[i].propietario=0;
        }
    }
    return retorno;
}

int eAu_lugarLibre(eAuto listaA[], int limite)
{
    int retorno=-1;
    int i;
    if(limite>0)///mientras la lista inicie
    {
        retorno=-2;
        for(i=0;i<limite;i++)/// y no sobre pase la limite
        {
            if(listaA[i].estado==1)///encontra un lugar libre
            {
                retorno=i;///retorna ese lugar
                break;
            }
        }
    }
    return retorno;
}

int eAu_autoIncrementar(eAuto listaA[],int limite)
{
    int retorno = 0;
    int i;
    if(limite > 0 && listaA != NULL)///mientrar el limite sea mayor a 0 y haya algo
    {
        for(i=0; i<limite; i++)
        {
            if(listaA[i].estado == 0)///si el anterior esta ocupado
            {
                    if(listaA[i].idAuto>retorno)///y esa id sea mayor al retorno
                    {
                         retorno=listaA[i].idAuto;///devuelve esa id
                    }

            }
        }
    }

    return retorno+1;///y retorna el lugar siguiente
}

int eAu_mostrarSolo(eAuto listaA)
{
    printf("\n%d---%s---%d---%d\n",listaA.idAuto,listaA.patente,listaA.marca,listaA.propietario);
}

int eAu_mostrarLista(eAuto listaA[],int limite)
{
    int retorno = -1;
    int i;
    if(limite > 0 && listaA != NULL)///si no obrepara el limite y halla algo en la listaA
    {
        retorno = 0;

        for(i=0; i<limite; i++)
        {
            if(listaA[i].estado==0)///si esta coupado lo muestra o contiene informacion
            {
                mostrarSolo(listaA[i]);
            }
        }
    }
    return retorno;
}
