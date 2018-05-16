#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "auto.h"
#define tam 20
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
    ePropietario listaPropietario[tam];
    inicio(listaPropietario,tam);///inicializa los valores
    eAuto listaAutos[tam];
    eAu_inicio(listaAutos,tam);

    do
    {
        printf("1- alta del propietario\n");
        printf("2- modificacion del propietario\n");
        printf("3- baja del propietario\n");
        printf("4- mostar propietario\n");
        printf("5- alta auto del propietario\n");
       // printf("6- \n");
        //printf("7- \n");
        printf("8- mostrar autos\n");
        printf("9- Salir\n");
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
                valorAutoAlta=Aalta(listaAutos,listaPropietario,tam,ALPHA_ROMEO,FERRARI,AUDI,OTROS);
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

        case 8:
            eAu_mostrarLista(listaAutos,tam);
        break;

        case 9:
            //salir
            printf("Desea salir S/N? \n");
            fflush(stdin);
            seguir=getche();
            break;
        }

    }while(seguir!='s');
    return 0;
}
