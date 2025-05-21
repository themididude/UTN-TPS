#include <stdio.h>
#include <stdlib.h>

#define DIM 10

int main()
{
    printf("Hello world!\n");

    ///-----------random variables-----------///
    int arrDim = 0;



    ///------------simple thingy (1)---------///

    /*
    printf("\nSimple Print:");
    int valor = 10;
    int * pint = &valor;
    int ** ppint = &pint;
    showMemory(&valor, &pint, &ppint);
    system("PAUSE");
    */

    ///---------------frfrfrfr2---------------///

    int array1[DIM] = {1,2,3,4,5,6,7,8,9,10}; //estatico
    int*a;
    arrDim = crearArregloDinamicoPares(array1, &a); //para este punto a es un arreglo normal
    printArray(a, arrDim);




    return 0;
}

void showMemory(int valor, int * pint, int ** ppint)
{

    printf("\ndire de valor: %p", &valor);
    printf("\ndire de pint: %p", &pint);
    printf("\ndire de ppint: %p", ppint);
}


int contarPares(int array1[], int validos)
{
    int count = 0;
    for(int i = 0; i < validos; i++)
    {
        if(array1[i] % 2 == 0)
        {
            count++;
        }
    }
    return count;
}

int crearArregloDinamicoPares(int array1[], int**a)      //array1 es el estatico
{
    int pares = contarPares(array1, DIM);

    *a = malloc(pares * sizeof(int));

    printf("\nPares: %i", pares);

    for(int i = 0; i < DIM; i++)
    {
        if(array1[i] % 2 == 0)
        {
            (*a)[i] = array1[i];
            printf("\narraynuevo [%i]: %i", i, (*a)[i]);
        }
    }

    return pares; ///dimension final del dinamico
}

void printArray(int array1[], int validos)
{
    for(int i = 0; i < validos; i++)
    {
        printf("\narray[%i] = %i", i, array1[i]);
    }
}
