#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "auto.h"
#define tam 10
#define ALPHA_ROMEO 1
#define FERRARI 2
#define AUDI 3
#define OTROS 4

int main()
{
    int opcion;
    char seguir;
    int valorAlta;
    int valorBaja;
    int valorModificacion;
    int valorAutoAlta;
    int listado;
    int valorAutoEgreso;
    int listadoA;
    int valorAutoLista;
    int orden;
    ePropietario listaPropietario[tam];
    inicio(listaPropietario,tam);///inicializa los valores

    eAuto listaAutos[tam];
    eAu_inicio(listaAutos,tam);

    eEgreso egresoAuto[tam];
    eEg_inicio(egresoAuto,tam);

    do
    {
        printf("1- alta del propietario\n");
        printf("2- modificacion del propietario\n");
        printf("3- baja del propietario\n");
        printf("4- mostar propietario\n");
        printf("5- alta auto del propietario\n");
        printf("6- egreso de auto\n");
        printf("7- mostrar autos\n");
        printf("8- mostrar recaudacion total\n");
        printf("9- mostrar recaudado por marca\n");
        printf("10- mostrar autos del propietario\n");
        printf("11- mostrar infor de audi\n");
        printf("12- mostrar autos por patente\n");
        printf("13- mostrar propietario por nombre\n");
        printf("14- mostrar por edad\n");
        printf("15- mostrar ticket maximo\n");
        printf("16- mostrar propietario mas de un estacionado\n");
        printf("17- Salir\n");
        scanf("%d",&opcion);

     switch(opcion)
        {
        case 1:
           valorAlta=alta(listaPropietario,tam);///llama a la funcion alta
           if(valorAlta>=0)///si todo esta correcto
           {
               printf("\ncompleto\n");
           }
           else
           {
                printf("\ninvalidado\n");
           }
        break;

        case 2:
            listado=mostrarLista(listaPropietario,tam);///si hay algo en la lista
            if(listado==0)
            {
                valorModificacion=modificacion(listaPropietario,tam);///pide la modificacion
                if(valorModificacion>=0)///si todo salio bien
                {
                    printf("\ncompleto\n");
                }
                else
                {
                    printf("\ninvalidado\n");
                }
            }
            else
            {
                printf("\ningrese algun dato primero\n");
            }
        break;

        case 3:
           listado=mostrarLista(listaPropietario,tam);
            if(listado==0)
            {
                valorBaja=baja(listaPropietario,tam);///pide la baja
                if(valorBaja>=0)
                {
                    printf("\ncompleto\n");
                }
                else
                {
                    printf("\ninvalidado\n");
                }
            }
            else
            {
                printf("\ningrese algun dato primero\n");
            }
        break;

        case 4:
            mostrarLista(listaPropietario,tam);
        break;

        case 5:
            listado=mostrarLista(listaPropietario,tam);
            if(listado==0)
            {
                valorAutoAlta=Aalta(listaAutos,egresoAuto,listaPropietario,tam,ALPHA_ROMEO,FERRARI,AUDI,OTROS);
                if(valorAutoAlta>=0)
                {
                    printf("\ncompleto\n");
                }
                else
                {
                    printf("\ninvalidado\n");
                }
            }
            else
            {
                printf("\ningrese algun dato primero\n");
            }
        break;

        case 6:
            listado=mostrarLista(listaPropietario,tam);
            listadoA=eAu_mostrarLista(listaAutos,tam);
            if(listado==0 && listadoA==0)
            {
                valorAutoEgreso=Aegreso(listaAutos,egresoAuto,tam,listaPropietario);
                if(valorAutoEgreso>=0)
                {
                    printf("\ncompleto\n");
                }
                else
                {
                    printf("\ninvalidado\n");
                }
            }
            else
            {
                printf("\ningrese algun dato primero\n");
            }
        break;

        case 7:
            eAu_mostrarLista(listaAutos,tam);
        break;

        case 8:
            eEg_recaudacionTotal(egresoAuto,tam);
        break;

        case 9:
            eEg_recaudacionTotalPorMarca(egresoAuto,tam);
        break;

        case 10:
            listado=mostrarLista(listaPropietario,tam);
            listadoA=eAu_mostrarLista(listaAutos,tam);
            if(listado==0 && listadoA==0)
            {
                valorAutoLista=eAu_propietarioDeAutos(listaAutos,tam,listaPropietario);
                if(valorAutoEgreso>=0)
                {
                    printf("\ncompleto\n");
                }
                else
                {
                    printf("\ninvalidado\n");
                }
            }
            else
            {
                printf("\ningrese algun dato primero\n");
            }
        break;

        case 11:
            eAu_mostrarListaDeAudi(listaAutos,tam,listaPropietario,egresoAuto);
        break;

        case 12:
            eAu_mostrarListaPorPatente(listaAutos,tam);
        break;

        case 13:
            printf("en que orden quiere la lista? 0=ascendente 1=descendente\n");
            scanf("%d",&orden);
            mostrarListaPorNombre(listaPropietario,tam,orden);
        break;

        case 14:
            mostrarListaPorEdad(listaPropietario,tam);
        break;

        case 15:
            eAu_max(listaAutos,tam,listaPropietario,egresoAuto);
        break;

        case 16:
            eAu_propientarioMasDeUno(listaAutos,tam,listaPropietario);
        break;

        case 17:
            //salir
            printf("Desea salir S/N? \n");
            fflush(stdin);
            seguir=getche();
            break;
        }

    }while(seguir!='s');
    return 0;
}
