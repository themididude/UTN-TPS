//Luciano Garcia Boubee
//////////////////////////////////////////////////////
#include <stdio.h>
#include <stdlib.h>
#include "pila.h"
#include <string.h>

#define DIM 20
#define DIMF 3
#define DIMC 3

#define DIM2F 5   //para char
#define DIM2C 10   //para char




void cargarPilaPar(Pila* pila1);
int loadArrayMultiplo5(Pila pila1, int array1[]);
void printArray(int array1[], int validos);
int findLowestPos(int array1[], int validos);
void loadMatrix(int matrix[DIMF][DIMC]);
void showMatrix(int matrix[DIMF][DIMC]);
int askArrayPos(int array1[], int validos);
void showArraypos(int array1[], int validos);
float averageMatrix(int matrix[DIMF][DIMC]);
void loadMatrixChar(char matrix[DIM2F][DIM2C]);
void showMatrixChar(char matrix[DIM2F][DIM2C]);
void showWord(char array1[DIM2F][DIM2C], int validos);
int returnCoincidences(char array1[DIM2F][DIM2C], char array2[DIM2F][DIM2C]);

int main()
{
    ///variables and stuff

    int validos = 0;

    Pila pilita;
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

    Pila Ordenar;
    inicpila(&Ordenar);
    //cargamos con valores random
    apilar(&Ordenar, 3);
    apilar(&Ordenar, 7);
    apilar(&Ordenar, 1);
    apilar(&Ordenar, 8);
    apilar(&Ordenar, 9);
    apilar(&Ordenar, 13);

    Pila ordenada;
    inicpila(&ordenada);

    int arrayfr[DIM];
    int arrayrandom[6] = {4, 6, 2, 7, 1};

    int matrix[DIMF][DIMC];
    char matrix2[DIM2F][DIM2C];

    char string1[DIM2F][DIM2C] = {"agustin","baltazar","camilo"};
    char string2[DIM2F][DIM2C] = {"baltazar","benjamin", "baltazar"};

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
    printf("\nArray con los multiplos de 5: \n");
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


    ///ejercicio6
    printf("\nEjercicio 6! \n");
    printf("\nPila con la que se va a trabajar: ");
    mostrar(&Ordenar);
    selectionsortPila(&Ordenar, &ordenada);
    printf("\nPilaOrdenada: ");
    mostrar(&ordenada);
    printf("\n");
    system("PAUSE");
    system("cls");

    ///ejercicio7
    printf("\nEjercicio 7! \n");
    printf("\nTrabajaremos con la matriz que previamente cargaste!(3x3) Vamos a sacar el promedio de los elementos.");
    float promedio = averageMatrix(matrix);
    printf("\nEl promedio de su matriz es %.2f", promedio);
    printf("\n");
    system("PAUSE");
    system("cls");


    ///ejercicio8
    printf("\nEjercicio 8! \n");
    printf("\nVamos a cargar su matriz char! ");
    loadMatrixChar(matrix2);
    showMatrixChar(matrix2);
    printf("\n");
    system("PAUSE");
    system("cls");


    ///ejercicio9
    printf("\nEjercicio 9! \n");
    printf("\nArreglos de palabras con los que vamos a trabajar: ");
    printf("\nArray 1: ");
    showWord(string1, 3);
    printf("\nArray 2: ");
    showWord(string2, 3);
    printf("\n");
    system("PAUSE");
    int coincidences = returnCoincidences(string1, string2);
    printf("\nLa cantidad de coincidencias ha sido de %i", coincidences);
    printf("\n");
    system("PAUSE");
    system("cls");

    printf("\nthanks for using my software yippie <3 \n\n");


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
            printf(" [ %i ] ", matrix[i][j]);
        }
        printf("\n");
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


int findLowestPila(Pila* A)            ///---- necesario para el selection sort
{
    if (pilavacia(A)) {
        printf("Error: pila vacía.\n");
        return -1;  // Return an invalid value instead of crashing
    }


    int menor = tope(A);

    Pila descartable;
    inicpila(&descartable);

    while (!pilavacia(A))
    {
        if(tope(A) < menor)
        {
            menor = tope(A);
        }
        apilar(&descartable, desapilar(A));
    }

    int removed = 0;
    while (!pilavacia(&descartable)) {
        if (tope(&descartable) == menor && removed == 0) {
            desapilar(&descartable);  // Remove only one occurrence
            removed = 1;
        } else {
            apilar(A, desapilar(&descartable));
        }
    }
    return menor;
}

void selectionsortPila(Pila* A, Pila* Destino)    //LESSGOOO
{

    while(!pilavacia(A))
    {
        int menor = findLowestPila(A);
        apilar(Destino, menor);
    }

}

float averageMatrix(int matrix[DIMF][DIMC])
{
    int suma = 0;
    int ammount = DIMF * DIMC; //cuantos elementos (es un 3x3)
    float promedio = 0.0;

    for(int i=0; i < DIMF; i++)
    {
        for(int j=0; j < DIMC; j++)
        {
            suma += matrix[i][j];
        }
    }
    promedio = (float)suma / ammount;

    return promedio;
}

void loadMatrixChar(char matrix[DIM2F][DIM2C])
{
    for(int i = 0; i < DIM2F; i++)
    {
        for(int j = 0; j < DIM2C; j++)
        {
            printf("\nIngrese un caracter para matrix[%i][%i]: ", i, j);
            scanf(" %c", &matrix[i][j]);
        }
    }
}

void showMatrixChar(char matrix[DIM2F][DIM2C])
{
    for(int i=0; i < DIM2F; i++)
    {
        for(int j = 0; j < DIM2C; j++)
        {
            printf(" [ %c ] ", matrix[i][j]);
        }
        printf("\n");
    }
}

void showWord(char array1[DIM2F][DIM2C], int validos)
{
    for(int i=0; i < validos; i++)
    {
        printf("\n [%s]", array1[i]);
    }
}


int returnCoincidences(char array1[DIM2F][DIM2C], char array2[DIM2F][DIM2C])
{
    int counter = 0;

    for(int i=0;  i < DIM2F; i++)
    {
        if(strcmp(array1[i], array2[i]) == 0)
        {
            counter ++;
        }
    }

    return counter;
}


