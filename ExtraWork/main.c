//Luciano Garcia Boubee y Adrian Zappala
//////////////////////////////////////////////////////
#include <stdio.h>
#include <stdlib.h>
#include "pila.h"
#include <string.h>

#define DIM 20
#define DIMF 3
#define DIMC 3


void cargarPilaPar(Pila* pila1);
int loadArrayMultiplo5(Pila pila1, int array1[]);
void printArray(int array1[], int validos);
int findLowestPos(int array1[], int validos);
void loadMatrix(int matrix[DIMF][DIMC]);
void showMatrix(int matrix[DIMF][DIMC]);
int askArrayPos(int array1[], int validos);
void showArraypos(int array1[], int validos);

int main()
{
    ///variables and stuff

    int validos = 0;

    Pila* pilita;
    inicpila(&pilita);

    Pila multiplo5;
    inicpila(&multiplo5);
    //cargamos con valores random
    apilar(&multiplo5, 1);
    apilar(&multiplo5, 5);
    apilar(&multiplo5, 8);
    apilar(&multiplo5, 10);
    apilar(&multiplo5, 15);
    apilar(&multiplo5, 21);

    int arrayfr[DIM];
    int arrayrandom[6] = {4, 6, 2, 7, 1};

    int matrix[DIMF][DIMC];


    ///ejercicio1
    printf("\nEjercicio 1! \n");
    cargarPilaPar(&pilita);
    mostrar(&pilita);
    printf("\n");
    system("PAUSE");
    system("cls");

    ///ejercicio2
    printf("\nEjercicio 2! \n");
    printf("\nLa pila con elementos cargados: ");
    mostrar(&multiplo5);
    validos = loadArrayMultiplo5(multiplo5,arrayfr);
    printArray(arrayfr, validos);
    printf("\n");
    system("PAUSE");
    system("cls");

    ///ejercicio3
    printf("\nEjercicio 3! \n");
    printf("\nArray con el que se va a trabajar: ");
    printArray(arrayrandom, 5);
    int posmenor = findLowestPos(arrayrandom, 5);
    printf("\n");
    system("PAUSE");
    system("cls");

    ///ejercicio4
    printf("\nEjercicio 4! \n");
    printf("\nVamos a cargar esa matriz.");
    loadMatrix(matrix);
    showMatrix(matrix);
    printf("\n");
    system("PAUSE");
    system("cls");

    ///ejercicio5
    printf("\nEjercicio 5! \n");
    printf("\nArray con el que se va a trabajar: ");
    printArray(arrayrandom, 5);
    showArraypos(arrayrandom,5);
    printf("\n");
    system("PAUSE");
    system("cls");



    return 0;
}



//////////////////////////////////////////////////////////
void cargarPilaPar(Pila* pila1)    ///ejercicio 1
{
    int i = 0;
    char keepgoing = 'y';

    printf("\nVamos a cargar su pila! Recuerde ingresar un numero par de elementos.\n");

    while(keepgoing == 'y')
    {
        leer(pila1);
        printf("\nDesea ingresar mas elementos? (y/n)");
        scanf(" %c", &keepgoing);
        i++;
    }
    if (i%2 != 0)
    {
        printf("Error: Su pila no es par! Ingrese 1 elemento mas. Elementos: %i \n", i);
        leer(pila1);
    }
}

int loadArrayMultiplo5(Pila pila1, int array1[])
{
    Pila aux;
    inicpila(&aux);

    int validos = 0;

    //check si es multiplo de 5
    while(!pilavacia(&pila1))
    {
        if (tope(&pila1) % 5 == 0)
        {
            array1[validos] = tope(&pila1);
            validos++;
        }
        apilar(&aux, desapilar(&pila1));
    }

    /// como pasamos por copia, no necesitamos devolver de aux a su lugar.

    return validos; // del array
}

void printArray(int array1[], int validos)
{
    for(int i=0; i < validos; i++)
    {
        printf("\nArray[%i] = %i", i, array1[i]);
    }
}


int findLowestPos(int array1[], int validos)
{
    int i = 0;
    int menor = array1[i];
    int menorpos = 0;

    for(i = 0; i < validos; i++)
    {
        if(array1[i] < menor)
        {
            menor = array1[i];
            menorpos = i;
        }
    }

    printf("\nEl numero menor encontrado %i se encuentra en la posicion: [%i]", menor, menorpos);
    return menorpos;
}

void loadMatrix(int matrix[DIMF][DIMC])
{
    for(int i=0; i < DIMF; i++)
    {
        for(int j =0; j < DIMC; j++)
        {
            printf("\nIngrese un valor para matriz[%i][%i]: ", i, j);
            scanf("%i", &matrix[i][j]);
        }
    }
}

void showMatrix(int matrix[DIMF][DIMC])
{
    for(int i=0; i < DIMF; i++)
    {
        for(int j = 0; j < DIMC; j++)
        {
            printf("\nmatriz[%i][%i]: %i ", i, j, matrix[i][j]);
        }
    }
}

int askArrayPos(int array1[], int validos)
{
    ///we need tocheck the position exists
    int pos = 0;
    printf("\nIngrese una posicion a buscar (0 - 4): ", validos);
    scanf("%i", &pos);

    if (pos < validos)
    {
        return pos;
    } else {
        printf("\nError: posicion incorrecta! ingrese un valor menor o igual a %i", validos);
    }
}


void showArraypos(int array1[], int validos)
{
    int pos = askArrayPos(array1, validos);

    printf("\nArray[%i] = %i", pos, array1[pos]);
}

void selectionsortPila(Pila* pila1)
{
    Pila aux;
    inicpila(&aux);

    int menor = tope(pila1);

    while(!pilavacia(pila1))
    {




    }




}
