#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"
#include "utn.h"

int obtenerEspacioLibre(EPersona lista[]){
    int i;
    int retorno = -1;
    for(i=0 ; i<CANT ; i++){
            if(lista[i].estado == 0){
                retorno = i;
                break;
            }
    }
    return retorno;
}

int buscarPorDni(EPersona lista[], float dni){
    int i;
    int retorno = -1;
    for(i=0 ; i<CANT ; i++){
            if(lista[i].dni == dni){
                retorno = i;
                break;
            }
    }
    return retorno;
}

int agregarPersona(EPersona lista[]){
    int edad, aux, espacioLibre;
    float dni;
    char nombre[50];

    espacioLibre = obtenerEspacioLibre(lista);
    if(espacioLibre == -1){
            printf("La lista esta llena!");
            return 0;
    }

    aux = getStringValidado("Ingrese nombre: \n", "ERROR: Solo letras", "ERROR: Ingrese a lo sumo 50 caracteres", nombre, 50);
    if(aux == 0){

            //scanf("%c", &c);
            return 0;
    }else{
        printf("Datos cargados..");
    }

    aux = getFloatValidado("Ingrese DNI: ", "ERROR: Solo numeros", "ERROR: Fuera de rango numerico", &dni, 1, 40000000);
    if(aux == 0){
        return 0;
    }else{
        printf("Datos cargados..");
    }

    aux = buscarPorDni(lista,dni);
    if(aux != -1 && lista[aux].estado){
        printf("El dni ya existe");
        return 0;
    }

    aux = getIntValidado("Ingrese edad: ", "ERROR: Solo numeros", "ERROR: Fuera de rango numerico", &edad, 0, 200);
    if(aux == 0){
        return 0;
    }else{
        printf("Datos cargados..");
    }

    lista[espacioLibre].dni = dni;
    lista[espacioLibre].edad = edad;
    strcpy(lista[espacioLibre].nombre, nombre);
    lista[espacioLibre].estado = 1;
    return 1;

}

int borrarPersona(EPersona lista[]){
    int aux;
    float dniUsuario;
    aux = getFloatValidado("Ingrese DNI del usuario a borrar: ", "ERROR: Solo numeros", "ERROR: Fuera de rango numerico", &dniUsuario, 1, 50000000);
    if(aux == 0){
        printf("Error al cargar datos");
        return 0;
    }
    aux = buscarPorDni(lista, dniUsuario);
    if(aux == -1){
        printf("El usuario no existe");
        return 0;
    }
    lista[aux].estado = 0;
    return 1;

}

void ordenarArray(EPersona lista[]){
    int i, j;
    EPersona aux;
    for(i=0 ; i<CANT ; i++){
        for(j=i+1 ; j < CANT ; j++){
            if(strcmp(lista[i].nombre,lista[j].nombre)){
                aux = lista[i];
                lista[i] = lista[j];
                lista[j] = aux;
            }
        }
    }
}

void imprimir(EPersona lista[]){
    int i;
    printf("%-25s%-15s%-10s\n", "Nombre", "DNI", "Edad");
    for(i=0 ; i<CANT ; i++){
        if(lista[i].estado){
            printf("%-25s%-15.0f%-10d\n", lista[i].nombre, lista[i].dni, lista[i].edad);
        }
    }
}

void imprimirGrafico(EPersona lista[]){
    int rangoUno, rangoDos, rangoTres;
    rangoUno = cantidadEnRango(lista, 0, 18);
    rangoDos = cantidadEnRango(lista, 19, 35);
    rangoTres = cantidadEnRango(lista, 36, 200);
    printf("\n%-6s%-7s%-6s", " <18","19-35",">35");

    while(rangoUno > 0 || rangoDos > 0 || rangoTres > 0 ){
        if(rangoUno>0){
            printf("\n%s","  *  ");
            rangoUno--;
        }else{
            printf("\n%s", "     ");
        }
        if(rangoDos>0){
            printf("%s","   *   ");
            rangoDos--;
        }else{
            printf("%s", "       ");
        }
        if(rangoTres>0){
            printf("%s","  *  ");
            rangoTres--;
        }else{
            printf("%s", "     ");
        }
    }


}

int cantidadEnRango(EPersona lista[], int minimaEdad, int maximaEdad){
    int i;
    int acumulador = 0;
    for(i=0 ; i<CANT ; i++){
        if(lista[i].edad>=minimaEdad && lista[i].edad<=maximaEdad && lista[i].estado){
            acumulador++;
        }
    }
    return acumulador;
}
