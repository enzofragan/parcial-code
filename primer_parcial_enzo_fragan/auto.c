#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "auto.h"

int eAu_inicio(eAuto listaA[],int limite)
{
    int retorno=-1;
    int i;

    int id[10]= {1,2,3,4,5,6,7,8,9,10};
    char patente[10][20]= {"AAA","CCC","DDD","BBB","ZZZ","III","HHH","EEE","FFF","GGG"};
    int marca[10]= {1,3,3,2,2,3,3,4,3,1};
    int propietario[10]= {2,1,2,1,3,3,4,1,4,3};

    if(limite>0)
    {
        retorno=0;
        for(i=0; i<limite; i++)
        {
            listaA[i].estado=0;
            strcpy(listaA[i].patente,patente[i]);
            listaA[i].marca=marca[i];
            listaA[i].propietario=propietario[i];
            listaA[i].idAuto=id[i];
            /*strcpy(listaA[i].patente,"");
            listaA[i].marca=0;
            listaA[i].propietario=0;*/
        }
    }
    return retorno;
}

int eEg_inicio(eEgreso egreso[],int limite)
{
    int retorno=-1;
    int i;

    int marca[10]= {1,1,2,3,2,2,3,4,1,1};
    float importe[10]= {100,200,100,300,100,100,200,200,100,100};

    if(limite>0)
    {
        retorno=0;
        for(i=0; i<10; i++)
        {
            egreso[i].estado=0;
            egreso[i].importe=importe[i];
            egreso[i].marca=marca[i];
            /*egreso[i].importe=0;
            egreso[i].marca=0;*/
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

int eEg_lugarLibre(eEgreso egreso[], int limite)
{
    int retorno=-1;
    int i;
    if(limite>0)///mientras la lista inicie
    {
        retorno=-2;
        for(i=0;i<limite;i++)/// y no sobre pase la limite
        {
            if(egreso[i].estado==1)///encontra un lugar libre
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
            if(listaA[i].estado==0 && listaA[i].idAuto>=1 && listaA[i].idAuto<=10 && listaA[i].marca>=1 && listaA[i].marca<=4)///si esta coupado lo muestra o contiene informacion
            {
                eAu_mostrarSolo(listaA[i]);
            }
        }
    }
    return retorno;
}

int eEg_mostrarSolo(eEgreso egreso)
{
    printf("\n%d---%.0f\n",egreso.marca,egreso.importe);
}

int eEg_mostrarLista(eEgreso egreso[],int limite)
{
    int retorno = -1;
    int i;
    if(limite > 0 && egreso != NULL)///si no obrepara el limite y halla algo en la listaA
    {
        retorno = 0;

        for(i=0; i<limite; i++)
        {
            if(egreso[i].estado==0)///si esta coupado lo muestra o contiene informacion
            {
                eEg_mostrarSolo(egreso[i]);
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
                eEg_trans(egreso,listaA,i,limite);
                retorno=0;
            }

        }
        return retorno;
    }
}

void eEg_trans(eEgreso egreso[],eAuto listaA[],int indice,int limite)
{
    int i;
    int marca;

    i=eEg_lugarLibre(egreso,limite);

    if(i>=0)
    {
        marca=listaA[i].marca;

        egreso[i].estado=0;
        egreso[i].marca=marca;
    }
}

int devolverHorasEstadia()
{
    int horas;

    srand(time(NULL));

    horas = (rand()%24)+1;

    return horas ;

}

int mostrarListaAmbos(eAuto listaA[],eEgreso egreso[],int limite)
{
    int retorno = -1;
    int i;
    if(limite > 0 && listaA != NULL && egreso != NULL)///si no obrepara el limite y halla algo en la listaA
    {
        retorno = 0;

        for(i=0; i<limite; i++)
        {
            if(listaA[i].estado==0 && egreso[i].estado==0 && listaA[i].idAuto>=1 && listaA[i].idAuto<=10 && listaA[i].marca>=1 && listaA[i].marca<=4)///si esta coupado lo muestra o contiene informacion
            {
                printf("\n%d---%s---%d---%d---%.0f\n",listaA[i].idAuto,listaA[i].patente,listaA[i].propietario,egreso[i].marca,egreso[i].importe);
            }
        }
    }
    return retorno;
}

int Aegreso(eAuto listaA[],eEgreso egreso[],int limite,ePropietario listaP[])
{
    int busquedaB;
    int busquedaP;
    char respuesta;
    int hora;
    int importe;
    int valorH;
    int indice=0;
    int i;
    int j;

    busquedaP=buscar(listaP,limite);

    busquedaB=eAu_buscarId(listaA,limite);///busca el usuario

    for(i=0;i<limite;i++)
    {
        if(busquedaB>=0 && listaA[i].idAuto==busquedaB && busquedaP>=0 && listaA[i].propietario==busquedaP)///si esta y el id es el mismo que el original
        {
            eAu_mostrarSolo(listaA[i]);///muestra el usuario
            hora=devolverHorasEstadia();
            switch(listaA[i].marca)
            {
                case 1:
                    valorH=150;
                    break;
                case 2:
                    valorH=175;
                    break;
                case 3:
                    valorH=200;
                    break;
                case 4:
                    valorH=250;
                    break;
            }
            importe=valorH*hora;
            printf("desea egresar este auto? s/n: \n");///pregunta si lo dara de baja
            fflush(stdin);
            respuesta=getche();
            while(respuesta!='s' && respuesta!='n')///valida
            {
                printf("\ningrese un valor valido s/n: \n");
                fflush(stdin);
                respuesta=getche();
            }
            if(respuesta=='s')///si es si devuelve es valor al inicio y despues muestra
            {
                printf("nombre del propietario: %s\npatente del auto: %s\nmarca: %d\nvalor de estadia: %d\n",listaP[i].nombre,listaA[i].patente,listaA[i].marca,importe);

                j=eEg_lugarLibre(egreso,limite);

                egreso[j].marca=listaA[i].marca;
                egreso[j].importe=importe;
                egreso[j].estado=0;

                listaA[i].estado=1;
                listaA[i].idAuto=0;
                strcpy(listaA[i].patente,"");
                listaA[i].marca=0;
                listaA[i].propietario=0;

                eEg_mostrarSolo(egreso[j]);
            }
            else if(respuesta=='n')
            {
                indice=-1;
            }
        }
    }
    return indice;
}

int eEg_recaudacionTotal(eEgreso egreso[],int limite)
{
    int retorno = -2;
    int i;
    float total=0;

    printf("\ntotal recaudado\n");

    for (i=0;i<limite;i++)
    {
        total = total+egreso[i].importe;
    }
    retorno = -1;

    printf("\nEl total es de: $%.2f\n", total);

    retorno = 0;
    return retorno;
}

int eEg_recaudacionTotalPorMarca(eEgreso egreso[],int limite)
{
    int retorno = -2;
    int i;
    int contAlphaRomeo=0;
    int contFerrari=0;
    int contAudi=0;
    int contOtro=0;
    float AlphaRomeo=0;
    float Ferrari=0;
    float Audi=0;
    float Otro=0;

    printf("\nRECAUDACION POR MARCA\n");

    for (i=0;i<limite;i++)
    {
        switch(egreso[i].marca)
        {
            case 1:
                AlphaRomeo = AlphaRomeo + egreso[i].importe;
                contAlphaRomeo++;
                break;
            case 2:
                Ferrari = Ferrari + egreso[i].importe;
                contFerrari++;
                break;
            case 3:
                Audi = Audi + egreso[i].importe;
                contAudi++;
                break;
            case 4:
                Otro = Otro + egreso[i].importe;
                contOtro++;
                break;
        }
    }
    retorno = -1;

    printf("\nrecaudacion por marca\n");
    printf("\nALPHA ROMEO\t $ %.2f\tcantidad de autos: %d\n", AlphaRomeo,contAlphaRomeo);
    printf("\nFERRARI\t\t $ %.2f\tcantidad de autos: %d\n", Ferrari,contFerrari);
    printf("\nAUDI\t\t $ %.2f\tcantidad de autos: %d\n", Audi,contAudi);
    printf("\nOTRO\t\t $ %.2f\tcantidad de autos: %d\n", Otro,contOtro);

    retorno = 0;
    return retorno;
}

int eAu_propietarioDeAutos(eAuto listaA[],int limite,ePropietario listaP[])
{
    int retorno = -1;
    int i;
    int id;
    int flag=0;

    id = buscar(listaP,limite);

    for(i=0;i<limite;i++)
    {
        if(listaA[i].propietario == listaP[id-1].idPropietario)
        {
            if(flag == 0)
            {
                printf("\nid patente cliente marca\n");
                flag = 1;
            }

            eAu_mostrarSolo(listaA[i]);

        }
    }
    retorno = 0;

    if(flag == 0)
    {
        printf("\nEL PROPIETARIO NO TIENE AUTOS ESTACIONADOS EN ESTE MOMENTO.\n");
        retorno = 1;
    }

    return retorno;
}

int eAu_mostrarListaDeAudi(eAuto listaA[],int limite,ePropietario listaP[],eEgreso egreso[])
{
    int i;

    for(i=0;i<limite;i++)
    {
        if(listaA[i].marca==3 && listaP[i].idPropietario>0 && listaP[i].idPropietario<=4)
        {
            printf("\n%d---%s---%s---%s---%s---%s---%d---%.0f\n",listaP[i].idPropietario,listaP[i].nombre,listaP[i].apellido,listaP[i].direccion,listaP[i].tarjeta,listaA[i].patente,listaA[i].marca,egreso[i].importe);
        }
    }

    return 0;
}

int eAu_mostrarListaPorPatente(eAuto listaA[],int limite)
{
    int retorno = -3;

    int i;
    int j;
    eAuto aux;

    retorno = -2;

    for(i=0;i<limite-1;i++)
    {
        if(listaA[i].estado == 0)
        {
            for(j=i+1;j<limite;j++)
            {
                if(listaA[j].estado == 0)
                {
                    if ( strcmp(listaA[i].patente, listaA[j].patente) > 0 )
                    {
                        aux = listaA[i];
                        listaA[i] = listaA[j];
                        listaA[j] = aux;

                        retorno = -1;
                    }
                }

            }

        }
    }


    for(i=0;i<limite;i++)
    {
        if(listaA[i].estado == 0)
        {
            retorno = 0;
            eAu_mostrarSolo(listaA[i]);
        }
    }

    return retorno;
}

int eAu_buscarId(eAuto listaA[],int limite)
{
    int id;
    int indice=-1;
    int i;
    char auxId[50];

    printf("ingrese el id del auto: ");
    fflush(stdin);
    gets(auxId);///pide el numero com char
    while(numeroV(auxId)==0)///valida si es numero o no
    {
        printf("ingrese un id valido: ");
        fflush(stdin);
        gets(auxId);
    }
    id = atoi(auxId);///los combierte a numero (atoi)

    for (i=0;i<limite;i++)
    {
        if(id==listaA[i].idAuto)///si son iguales lo encontro
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

int eAu_max(eAuto listaA[],int limite,ePropietario listaP[],eEgreso egreso[])
{
    int i;
    int j;
    int max=0;
    int hora;

    for(i=0;i<limite;i++)
    {
        if(egreso[i].importe>max)
        {
            max=egreso[i].importe;
        }
    }

    for(j=0;j<limite;j++)
    {
        if(egreso[j].estado==0 && egreso[j].importe==max)
        {
            hora=devolverHorasEstadia();
            printf("\n%d---%s---%s---%s---%s---%s---%d---%.0f---%d\n",listaP[j].idPropietario,listaP[j].nombre,listaP[j].apellido,listaP[j].direccion,listaP[j].tarjeta,listaA[j].patente,listaA[j].marca,egreso[j].importe,hora);
        }
    }

}

int eAu_propientarioMasDeUno(eAuto listaA[],int limite,ePropietario listaP[])
{
    int retorno = -2;
    int i;
    int contAlphaRomeo=0;
    int contFerrari=0;
    int contAudi=0;
    int contOtro=0;

    for (i=0;i<limite;i++)
    {
        if(listaP[i].estado==0 && listaP[i].edad>0 && listaP[i].edad<100)
        {
           switch(listaA[i].propietario)
            {
                case 1:
                    contAlphaRomeo++;
                    if(contAlphaRomeo>=2)
                    {
                        printf("\n%d---%s---%s---%s---%s---%d---%s\n",listaP[i].idPropietario,listaP[i].nombre,listaP[i].apellido,listaP[i].direccion,listaP[i].tarjeta,listaP[i].edad,listaA[i].patente);
                    }
                    break;
                case 2:
                    contFerrari++;
                    if(contFerrari>=2)
                    {
                        printf("\n%d---%s---%s---%s---%s---%d---%s\n",listaP[i].idPropietario,listaP[i].nombre,listaP[i].apellido,listaP[i].direccion,listaP[i].tarjeta,listaP[i].edad,listaA[i].patente);
                    }
                    break;
                case 3:
                    contAudi++;
                    if(contAudi>=2)
                    {
                        printf("\n%d---%s---%s---%s---%s---%d---%s\n",listaP[i].idPropietario,listaP[i].nombre,listaP[i].apellido,listaP[i].direccion,listaP[i].tarjeta,listaP[i].edad,listaA[i].patente);
                    }
                    break;
                case 4:
                    contOtro++;
                    if(contOtro>=2)
                    {
                        printf("\n%d---%s---%s---%s---%s---%d---%s\n",listaP[i].idPropietario,listaP[i].nombre,listaP[i].apellido,listaP[i].direccion,listaP[i].tarjeta,listaP[i].edad,listaA[i].patente);
                    }
                    break;
            }
        }
    }
    retorno = 0;
    return retorno;
}
