#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

typedef struct
{
    int idPropietario;
    char direccion[50];
    char nombre[50];
    char apellido[50];
    char tarjeta[50];
    int estado;

}ePropietario;


#endif // FUNCIONES_H_INCLUDED
int inicio(ePropietario lista[],int limite);

int lugarLibre(ePropietario lista[], int limite);

int autoIncrementar(ePropietario lista[],int limite);

int mostrarSolo(ePropietario lista);

int mostrarLista(ePropietario lista[],int limite);

int buscar(ePropietario lista[],int limite);


int alta(ePropietario lista[],int limite);

int modificacion(ePropietario lista[],int limite);

int baja(ePropietario lista[],int limite);

int numeroV(char num[]);

int letraV(char nom[]);

int letras(char nom[]);
