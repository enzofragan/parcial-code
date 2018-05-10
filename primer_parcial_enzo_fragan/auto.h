#ifndef AUTO_H_INCLUDED
#define AUTO_H_INCLUDED

typedef struct
{
    int idAuto;
    char patente[50];
    int marca;
    int propietario;
    int estado;

}eAuto;

#endif // AUTO_H_INCLUDED
int eAu_inicio(eAuto listaA[],int limite);

int eAu_lugarLibre(eAuto listaA[], int limite);

int eAu_autoIncrementar(eAuto listaA[],int limite);

int eAu_mostrarSolo(eAuto listaA);

int eAu_mostrarLista(eAuto listaA[],int limite);
