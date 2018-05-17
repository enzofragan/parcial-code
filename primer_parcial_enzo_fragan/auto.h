#ifndef AUTO_H_INCLUDED
#define AUTO_H_INCLUDED
#include "funciones.h"

typedef struct
{
    int idAuto;
    char patente[50];
    int marca;
    int propietario;
    int estado;

}eAuto;

typedef struct
{
    int cont;
    char patente[100];
    int marca;
    int propietario;
    int tiempo;
    float importe;
    int estado;

}eEgreso;

#endif // AUTO_H_INCLUDED
int eAu_inicio(eAuto listaA[],int limite);

int eAu_lugarLibre(eAuto listaA[], int limite);

int eAu_autoIncrementar(eAuto listaA[],int limite);

int eAu_mostrarSolo(eAuto listaA);

int eAu_mostrarLista(eAuto listaA[],int limite);

int Aalta(eAuto listaA[],eEgreso egreso[],ePropietario listaP[],int limite,int ALPHA_ROMEO,int FERRARI,int AUDI,int OTROS);

int eEg_inicio(eEgreso egreso[],int limite);

void eEg_trans(eEgreso egreso[],eAuto listaA[],int limite);

int eEg_lugarLibre(eEgreso egreso[], int limite);
