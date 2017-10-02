#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED
#define CANT 20

typedef struct {

    char nombre[50];
    int edad;
    int estado;
    float dni;

}EPersona;

/**
 * Obtiene el primer indice libre del array.
 * @param lista el array se pasa como parametro.
 * @return el primer indice disponible
 */
int obtenerEspacioLibre(EPersona lista[]);

/**
 * Obtiene el indice que coincide con el dni pasado por parametro.
 * @param lista el array se pasa como parametro.
 * @param dni el dni a ser buscado en el array.
 * @return el indice en donde se encuentra el elemento que coincide con el parametro dni
 */
int buscarPorDni(EPersona lista[], float dni);

int agregarPersona(EPersona lista[]);

int borrarPersona(EPersona lista[]);

void ordenarArray(EPersona lista[]);

void imprimir(EPersona lista[]);

void imprimirGrafico(EPersona lista[]);

int cantidadEnRango(EPersona lista[], int minimaEdad, int maximaEdad);

#endif // FUNCIONES_H_INCLUDED
