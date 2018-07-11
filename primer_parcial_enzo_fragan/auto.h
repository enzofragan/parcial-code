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
    int marca;
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

void eEg_trans(eEgreso egreso[],eAuto listaA[],int indice,int limite);

int eEg_lugarLibre(eEgreso egreso[], int limite);

int eEg_mostrarSolo(eEgreso egreso);

int eEg_mostrarLista(eEgreso egreso[],int limite);

int devolverHorasEstadia();

int mostrarListaAmbos(eAuto listaA[],eEgreso egreso[],int limite);

int Aegreso(eAuto listaA[],eEgreso egreso[],int limite,ePropietario listaP[]);

int eAu_buscarId(eAuto listaA[],int limite);

int eEg_recaudacionTotal(eEgreso egreso[],int limite);

int eEg_recaudacionTotalPorMarca(eEgreso egreso[],int limite);

int eAu_propietarioDeAutos(eAuto listaA[],int limite,ePropietario listaP[]);

int eAu_mostrarListaDeAudi(eAuto listaA[],int limite,ePropietario listaP[],eEgreso egreso[]);

int eAu_mostrarListaPorPatente(eAuto listaA[],int limite);

int eAu_max(eAuto listaA[],int limite,ePropietario listaP[],eEgreso egreso[]);

int eAu_propientarioMasDeUno(eAuto listaA[],int limite,ePropietario listaP[]);

int eAu_propientarioMasDeUnoDistinto(eAuto listaA[],int limite,ePropietario listaP[]);
