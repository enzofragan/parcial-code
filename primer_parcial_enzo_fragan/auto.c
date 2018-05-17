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
            listaA[i].estado=1;
            strcpy(listaA[i].patente,"");
            listaA[i].marca=0;
            listaA[i].propietario=0;
        }
    }
    return retorno;
}

int eEg_inicio(eEgreso egreso[],int limite)
{
    int retorno=-1;
    int i;


    if(limite>0)
    {
        retorno=0;
        for(i=0; i<10; i++)
        {
            egreso[i].estado=1;
            egreso[i].cont=0;
            strcpy(egreso[i].patente,"");
            egreso[i].importe=0;
            egreso[i].marca=0;
            egreso[i].tiempo=0;
            egreso[i].propietario=0;
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
                eAu_mostrarSolo(listaA[i]);
            }
        }
    }
    return retorno;
}

int Aalta(eAuto listaA[],eEgreso egreso[],ePropietario listaP[],int limite,int ALPHA_ROMEO,int FERRARI,int AUDI,int OTROS)
{
    int busquedaB;
    int idAuto;
    int indice;
    int marca;
    int retorno;
    int i;

    busquedaB=buscar(listaP,limite);///busca el usuario

    for(i=0;i<limite;i++)
    {
        if(busquedaB>=0)//&& listaP[i].idPropietario==busquedaB)///si esta y el id es el mismo que el original
        {
            i=eAu_lugarLibre(listaA,limite);///si encuentra un lugar libre
            if(i>=0)
            {
                idAuto=eAu_autoIncrementar(listaA,limite);///pasa al id del siguiente al original

                printf("ingrese la patente del auto: ");///pide el nombre y valida
                fflush(stdin);
                gets(listaA[i].patente);
                while(letraV(listaA[i].patente)==0)
                {
                    printf("ingrese una patente valida: ");
                    fflush(stdin);
                    gets(listaA[i].patente);
                }

                printf("que marca es?\n");
                printf("1- ALPHA_ROMEO\n");
                printf("2- FERRARI\n");
                printf("3- AUDI\n");
                printf("4- OTROS\n");
                scanf("%d",&indice);

                switch(indice)
                {
                    case 1:
                        marca=ALPHA_ROMEO;
                        break;

                    case 2:
                        marca=FERRARI;
                        break;

                    case 3:
                        marca=AUDI;
                        break;

                    case 4:
                        marca=OTROS;
                        break;

                    default:
                        printf("ingrese un valor valido");
                        break;
                }
                while (indice>4)
                {
                    printf("que marca es?\n");
                    printf("1- ALPHA_ROMEO\n");
                    printf("2- FERRARI\n");
                    printf("3- AUDI\n");
                    printf("4- OTROS\n");
                    scanf("%d",&indice);

                    switch(indice)
                    {
                        case 1:
                            marca=ALPHA_ROMEO;
                            break;

                        case 2:
                            marca=FERRARI;
                            break;

                        case 3:
                            marca=AUDI;
                            break;

                        case 4:
                            marca=OTROS;
                            break;

                        default:
                            printf("ingrese un valor valido");
                            break;
                    }
                }
                listaA[i].marca=marca;
                listaA[i].idAuto=idAuto;
                listaA[i].propietario=busquedaB;///la id que se guarda es la que devuelve la funcion anterio
                listaA[i].estado=0;///cambiar el estado a ocupado
                eAu_mostrarSolo(listaA[i]);///muestra lo ingresado
                eEg_trans(egreso,listaA,limite);
                retorno=0;
            }

        }
        return retorno;
    }
}

void eEg_trans(eEgreso egreso[],eAuto listaA[],int limite)
{
    int i;

    for(i=0;i<limite;i++)
    {
        egreso[i].estado=0;
        strcpy(egreso[i].patente,listaA[i].patente);
        egreso[i].marca=listaA[i].marca;
        printf("%d",egreso[i].marca);
        egreso[i].propietario=listaA[i].propietario;
    }
        printf("%s----------%d-----------%d",egreso[i].patente,egreso[i].marca,egreso[i].propietario);

}
