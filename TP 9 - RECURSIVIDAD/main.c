#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define DIM 5

/*
1. Calcular el factorial de un número en forma recursiva.
2. Calcular la potencia de un número en forma recursiva.
3. Recorrer un arreglo y mostrar sus elementos en forma recursiva.
4. Recorrer un arreglo comenzando desde la posición 0 y mostrar sus elementos en
forma invertida (recursivo).
5. Determinar en forma recursiva si un arreglo es capicúa.
6. Sumar en forma recursiva los elementos de un arreglo de enteros y retornar el total de la suma.
7. Buscar el menor elemento de un arreglo en forma recursiva.
8. Buscar el menor elemento de un archivo de números enteros de forma recursiva. (desde el mismo archivo)
9. Invertir los elementos de un archivo de números enteros de forma recursiva.  (si no te sale, primero proba con invertir los elementos de un arreglo de int)
10. Recorrer un archivo y mostrar sus elementos en forma invertida de forma recursiva.
11. Ingresar valores a una variable de tipo char (por teclado) y mostrarlo en el orden inverso (hasta ingresar un ‘*’) de forma recursiva. NO usar arreglos.
12. Determinar si un arreglo contiene un determinado elemento de forma recursiva. (Pueden intentarlo también con una función void)(Tener en cuenta para un arreglo desordenado y el caso para un arreglo ordenado)

*/

bool esCapicua(int array1[], int i, int j, int validos);
int main()
{
    ///------ some simple variables ------//
    int array1[DIM] = {1,2,3,4,5};
    int arrayCapicua[6] = {1,2,3,3,2,1};
    int numToFact = 0;
    int numFactorial = 0;
    int base = 0;
    int exponente = 0;
    int potencia = 0;

    int validos = 6;
    int i=0;
    int j= validos-1;
    int suma = 0;
    char filename[] = "file";
    int menor = INT_MAX;
    ///------ the actual exercises -----//


    //punto1 ------------
    //creatingFileRandom(filename);
    printf("\nFactorial de un numero!");
    printf("\nIngrese un numero: ");
    scanf("%i", &numToFact);
    numFactorial = factorial(numToFact);
    printf("\nFactorial de %i: %i", numToFact, numFactorial);
    //system("PAUSE");
    //system("cls");
    printf("\n------------------------------------");
    //punto2 ------------
    printf("\nPotencia de un numero!");
    printf("\nIngrese un numero base: ");
    scanf("%i", &base);
    printf("\nIngrese un exponente: ");
    scanf("%i", &exponente);
    potencia = potenciaF(base, exponente);
    printf("\nPotencia: %i", potencia);
    //system("PAUSE");
    //system("cls");
    printf("\n------------------------------------");
    //punto 3
    printf("\nImprimiendo un arreglo recursivamente.... beep...beeeeeep...bep...");
    recorrerYmostrar(array1, 0, DIM);
    //system("PAUSE");
    //system("cls");
    printf("\n------------------------------------");
    //punto 4
    printf("\nImprimiendo un arreglo recursivamente...but backwards.. beep...beeeeeep...bep...");
    recorrerYmostrarInvertido(array1, 0, DIM);
    printf("\n------------------------------------");
    //punto 5
    printf("\nEs el array capicua? ");
    if(esCapicua(arrayCapicua, i, j, validos) == true)
    {
        printf("\nSi.");
    }
    else{
        printf("\nNo.");
    }
    printf("\n------------------------------------");
    //punto 6
    printf("\nSumando los elementos de un arreglo de forma recursiva.....");
    i = 0;
    suma = sumaRecursiva(array1, i, 5);
    printf("\nLa suma de los elementos del array = %i", suma);
    printf("\n------------------------------------");
    //punto 7
    i = 0;
    printf("\nBuscando el menor en un arreglo de forma recursiva");
    menor = menorArray(array1,i, validos, menor);
    printf("\nMenor elemento encontrado: %i", menor);
    printf("\n------------------------------------");
    //punto 8
    ("\nBuscando el menor en un archivo de forma recursiva");
    archivoMenor(filename);
    printf("\n------------------------------------");
    return 0;
}

int factorial(int x)
{
    int rta;

    if (x == 0)
    {
        rta = 1;
    }
    else
    {
        rta = x * factorial(x-1);
    }
    return rta;
}

int potenciaF(int x, int exponente)
{
    if (exponente == 0) return 1;

    else{
        return x * potenciaF(x, exponente -1);
    }
}

void recorrerYmostrar(int array1[], int i, int validos)
{
    if (i < validos)
    {
        printf("\nArray[ %i ] = %i", i, array1[i]);
        recorrerYmostrar(array1, i+1, validos);
    }
}

void recorrerYmostrarInvertido(int array1[], int i, int validos)
{
    int newValidos = validos-1;
    if(i < validos)
    {
        printf("\nArray[ %i ] = %i ", newValidos-i ,array1[newValidos - i]);
        recorrerYmostrarInvertido(array1, i+1, validos);
    }
}

bool esCapicua(int array1[], int i, int j, int validos)
{
   // int j = validos-1;  hay que hacer esto en el main.

    if(i < validos / 2)
    {
        if(array1[i] != array1[j])
        {
            return false;
        } else {
            esCapicua(array1, i+1, j-1, validos);
        }
        return true;
    }
}
int sumaRecursiva(int array1[], int i, int validos)
{
    if(i == validos)
    {
        return 0;
    }

    return array1[i] + sumaRecursiva(array1, i+1, validos);
}

int menorArray(int array1[], int i, int validos, int menor)
{
    if (i == validos)
    {
        return menor;
    }

    if(array1[i] < menor)
    {
        menor = array1[i];
    }

    return menorArray(array1, i+1, validos, menor);
}

int RecursivoMenor(FILE *file, int menor)
{
    int num;

    if (fscanf(file, "%i", &num) == 1) {
        printf("Leido: %d\n", num);
        if(num < menor)
        {
            menor = num;
        }
        return RecursivoMenor(file, menor);
    } else {
        if (feof(file)) {
            printf("Fin del archivo.\n");
        } else {
            perror("Error de lectura del archivo");
        }
        return menor;
    }
}


int archivoMenor(char filename[])
{
    int menor = INT_MAX;
    int num;

    FILE *archivin;
    archivin = fopen(filename, "rb");
    if(archivin != NULL)
    {
        menor = RecursivoMenor(archivin, menor);
        printf("\nMenor encontrado: %i", menor);

    } else
    {
        printf("Error: el Archivo no existe");
    }


    fclose(archivin);
}

void creatingFileRandom(char filename[])
{

    FILE *archivin;
    archivin = fopen(filename, "rb");
    if(archivin != NULL)
    {
        printf("\nEl archivo ya existe");
        fclose(archivin);
    }
    else
    {
        printf("\nCreando el archivo . . . ");
        archivin = fopen(filename, "wb");
        fprintf(archivin, "%d\n", 1);
        fprintf(archivin, "%d\n", 2);
        fprintf(archivin, "%d\n", 3);
        fprintf(archivin, "%d\n", 4);
        fprintf(archivin, "%d\n", 5);
    }
    fclose(archivin);
}
