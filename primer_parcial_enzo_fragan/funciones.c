#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"
int inicio(ePropietario lista[],int limite)///inicia los valores
{
    int retorno=-1;
    int i;

    int id[5]= {1,2,3,4};
    char nombre[5][20]= {"Juan","Luis","Maria","Jose"};
    char tarjeta[5][20]= {"111-111","222-222","333-333","444-444"};
    char direccion[5][20]= {"mitre","urquiza","belgrano","alsina"};

    if(limite>0)
    {
        retorno=0;
        for(i=0; i<limite; i++)
        {
           lista[i].estado= 0;///1=libre  0=ocupado
           lista[i].idPropietario=id[i];
           strcpy(lista[i].nombre,nombre[i]);
            strcpy(lista[i].tarjeta,tarjeta[i]);
            strcpy(lista[i].direccion,direccion[i]);
           /*lista[i].idPropietario=0;
           strcpy(lista[i].direccion,"");
           lista[i].tarjeta=0;
           strcpy(lista[i].nombre,"");
           strcpy(lista[i].apellido,"");*/
        }
    }
    return retorno;
}

int lugarLibre(ePropietario lista[], int limite)///buscar un lugar libre entre los valores
{
    int retorno=-1;
    int i;
    if(limite>0)///mientras la lista inicie
    {
        retorno=-2;
        for(i=0;i<limite;i++)/// y no sobre pase la limite
        {
            if(lista[i].estado==1)///encontra un lugar libre
            {
                retorno=i;///retorna ese lugar
                break;
            }
        }
    }
    return retorno;
}

int autoIncrementar(ePropietario lista[],int limite)///id auto incrementable
{
    int retorno = 0;
    int i;
    if(limite > 0 && lista != NULL)///mientrar el limite sea mayor a 0 y haya algo
    {
        for(i=0; i<limite; i++)
        {
            if(lista[i].estado == 0)///si el anterior esta ocupado
            {
                    if(lista[i].idPropietario>retorno)///y esa id sea mayor al retorno
                    {
                         retorno=lista[i].idPropietario;///devuelve esa id
                    }

            }
        }
    }

    return retorno+1;///y retorna el lugar siguiente
}

int mostrarSolo(ePropietario lista)///muestra el usuario guardado
{
    printf("\n%d---%s---%s---%s---%s\n",lista.idPropietario,lista.nombre,lista.apellido,lista.direccion,lista.tarjeta);
}

int mostrarLista(ePropietario lista[],int limite)///mostra la lista de usuario
{
    int retorno = -1;
    int i;
    if(limite > 0 && lista != NULL)///si no obrepara el limite y halla algo en la lista
    {
        retorno = 0;

        for(i=0; i<limite; i++)
        {
            if(lista[i].estado==0 && lista[i].idPropietario>=1 && lista[i].idPropietario<=4)///si esta coupado lo muestra o contiene informacion
            {
                mostrarSolo(lista[i]);
            }
        }
    }
    return retorno;
}

int buscar(ePropietario lista[],int limite)///busca el usuario para la baja o modificacion
{
    int id;
    char auxTarj[50];
    int indice=-1;
    int i;
    char auxId[50];

    printf("ingrese el id del propietario: ");
    fflush(stdin);
    gets(auxId);///pide el numero com char
    while(numeroV(auxId)==0)///valida si es numero o no
    {
        printf("ingrese un id valido: ");
        fflush(stdin);
        gets(auxId);
    }
    id = atoi(auxId);///los combierte a numero (atoi)

    printf("ingrese la tarjeta: ");
    fflush(stdin);
    gets(auxTarj);

    for (i=0;i<limite;i++)
    {
        if(id==lista[i].idPropietario && strcmp(auxTarj,lista[i].tarjeta)==0)///si son iguales lo encontro
        {
            indice=id;///de vuelve el id encontrado
            break;
        }
        else
        {
            indice=-2;
        }
    }
    return indice;
}

int alta(ePropietario lista[],int limite)///pide un nuevo usuario
{
    int retorno=-1;
    int idPropietario;
    int i;
    if(limite>0 && lista != NULL)
    {
        retorno=-2;
        i=lugarLibre(lista,limite);///si encuentra un lugar libre
        if(i>=0)
        {
            printf("hoal");
            idPropietario=autoIncrementar(lista,limite);///pasa al id del siguiente al original

            printf("ingrese el nombre: ");///pide el nombre y valida
            fflush(stdin);
            gets(lista[i].nombre);
            while(letraV(lista[i].nombre)==0)
            {
                printf("ingrese un nombre valido: ");
                fflush(stdin);
                gets(lista[i].nombre);
            }

            printf("ingrese el apellido: ");///pide el apellido y valida
            fflush(stdin);
            gets(lista[i].apellido);
            while(letraV(lista[i].apellido)==0)
            {
                printf("ingrese un apellido valido: ");
                fflush(stdin);
                gets(lista[i].apellido);
            }

            printf("ingrese direccion: ");///pide la direccion
            fflush(stdin);
            gets(lista[i].direccion);

            printf("ingrese el numero de tarjeta:");///pide el numero de tarjeta
            fflush(stdin);
            gets(lista[i].tarjeta);

            lista[i].idPropietario=idPropietario;///la id que se guarda es la que devuelve la funcion anterio
            lista[i].estado=0;///cambiar el estado a ocupado
            mostrarSolo(lista[i]);///muestra lo ingresado
            retorno=0;
        }

    }
    return retorno;///si todo salio bien retorna
}

int modificacion(ePropietario lista[],int limite)///modificar el usuario
{
    int busquedaM;
    char respuesta;
    char respuestaM;
    char auxTarjeta[50];
    int tarjeta;
    int indice=0;
    int i;

    busquedaM=buscar(lista,limite);///busca el usuario

    for(i=0;i<limite;i++)
    {
        if(busquedaM>=0 && lista[i].idPropietario==busquedaM)///si esta y el id es el mismo que el original
        {
            mostrarSolo(lista[i]);///muestra el usuario

            printf("desea modificar a este usuario? s/n: ");///pregunta si lo modificara
            fflush(stdin);
            respuesta=getche();

            while(respuesta!='s' && respuesta!='n')///valida la recpuesta
            {
                printf("\ningrese un valor valido s/n: ");
                fflush(stdin);
                respuesta=getche();
            }

            if(respuesta=='s')///si es si pide el numero de tarjeta de nuevo
            {

                printf("\ningrese el numero de tarjeta:");///pide el numero de tarjeta
                fflush(stdin);
                gets(auxTarjeta);

                printf("el nuevo numero de tarjeta es: %s\n",auxTarjeta);///muestra la nueva tarjeta

                printf("\ndesea aplicar estos cambios? s/n: ");///pregunta si desea aplicar los cambios
                fflush(stdin);
                respuestaM=getche();

                while(respuestaM!='s' && respuestaM!='n')///valida la respuesta
                {
                    printf("\ningrese un valor valido s/n: ");
                    fflush(stdin);
                    respuestaM=getche();
                }

                if(respuestaM=='s')/// si es que si los aplica y muetra
                {
                    strcpy(lista[i].tarjeta,auxTarjeta);
                    mostrarSolo(lista[i]);
                }
                else if(respuestaM=='n')///si no lo cancela
                {
                    indice=-2;
                }
            }
            else if(respuesta=='n')
            {
                indice=-1;
            }
        }
    }
    return indice;
}

int baja(ePropietario lista[],int limite)///pide se desea dar de baja un usuario
{
    int busquedaB;
    char respuesta;
    int indice=0;
    int i;

    busquedaB=buscar(lista,limite);///busca el usuario

    for(i=0;i<limite;i++)
    {
        if(busquedaB>=0 && lista[i].idPropietario==busquedaB)///si esta y el id es el mismo que el original
        {
            mostrarSolo(lista[i]);///muestra el usuario
            printf("dara de baja a este usuario? s/n: ");///pregunta si lo dara de baja
            fflush(stdin);
            respuesta=getche();
            while(respuesta!='s' && respuesta!='n')///valida
            {
                printf("\ningrese un valor valido s/n: ");
                fflush(stdin);
                respuesta=getche();
            }
            if(respuesta=='s')///si es si devuelve es valor al inicio y despues muestra
            {
                lista[i].estado=1;
                lista[i].idPropietario=0;
                strcpy(lista[i].nombre,"");
                strcpy(lista[i].apellido,"");
                strcpy(lista[i].direccion,"");
                strcpy(lista[i].tarjeta,"");

                mostrarLista(lista,limite);
            }
            else if(respuesta=='n')
            {
                indice=-1;
            }
        }
    }
    return indice;
}

int Aalta(eAuto listaA[],ePropietario listaP[],int limite)
{
    int busquedaB;
    int indice=0;
    int idAuto;
    int i;

    busquedaB=buscar(lista,limite);///busca el usuario

     for(i=0;i<limite;i++)
    {
        if(busquedaB>=0 && lista[i].idPropietario==busquedaB)///si esta y el id es el mismo que el original
        {
            i=lugarLibre(lista,limite);///si encuentra un lugar libre
                if(i>=0)
                {
                    idAuto=autoIncrementar(listaA,limite);///pasa al id del siguiente al original

                    printf("ingrese el nombre: ");///pide el nombre y valida
                    fflush(stdin);
                    gets(lista[i].nombre);
                    while(letraV(listaA[i].patente)==0)
                    {
                        printf("ingrese un nombre valido: ");
                        fflush(stdin);
                        gets(listaA[i].patente);
                    }

                    printf("ingrese el apellido: ");///pide el apellido y valida
                    fflush(stdin);
                    scanf("%d",&listaA[i].marca);


                    listaA[i].propietario=busquedaB;///la id que se guarda es la que devuelve la funcion anterio
                    lista[i].estado=0;///cambiar el estado a ocupado
                    mostrarSolo(lista[i]);///muestra lo ingresado
                    retorno=0;
                }

            }
            return retorno;
        }
    }
}

int numeroV(char num[])///valida el numero con un char
{
    int i=0;
    while(num[i] != '\0')
    {
        if(!(isdigit(num[i])))///si el char no es un digito
        {
            return 0;///es letra
        }
        i++;
    }
    return 1;
}

int letraV(char nom[])///valida el nombre y apellido
{
    int i=0;
    while(nom[i] != '\0')///mientras no sea /0 osea alla algo
    {
        if((nom[i] != ' ') && (nom[i] < 'a' || nom[i] > 'z') && (nom[i] < 'A' || nom[i] > 'Z'))///si tiene espacio y no esta entre a y z
        {
            return 0;///es numero
        }
        i++;
    }
    return 1;
}