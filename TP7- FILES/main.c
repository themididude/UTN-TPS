#include <stdio.h>
#include <stdlib.h>

#define DIM 10


typedef struct {
     int legajo;
     char nombre[30];
     int edad;
     int anio;

} Alumno;

int main()
{
    printf("Hello world!\n");

    ///-----------random variables-----------///
    int arrDim = 0;
    char namealumnos[] = "alumnos.dat";
    int arrDim2 = 0;
    int fileSize = 0;

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
    /*
    int array1[DIM] = {1,2,3,4,5,6,7,8,9,10}; //estatico
    int*a;
    arrDim = crearArregloDinamicoPares(array1, &a); //para este punto a es un arreglo normal
    printArray(a, arrDim);
    */
    ///---------------ejercicio 3-------------///


    Alumno*arrayFile;
    fileSize = cantRegistros(namealumnos);
    arrayFile = malloc(fileSize * sizeof(Alumno));
    printf("File size: %i registros, ", fileSize);
    fileToArray(namealumnos, arrayFile, fileSize);
    mostrarAlumnosArray(arrayFile3, fileSize);


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
    int j = 0; //no queremos ponerlos en las posiciones de i del estatico
    *a = malloc(pares * sizeof(int));

    printf("\nPares: %i", pares);

    for(int i = 0; i < DIM; i++)
    {
        if(array1[i] % 2 == 0)
        {
            (*a)[j] = array1[i];
            j++;
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


////////////////////////// alumnos y eso
Alumno cargarAlumno()
{
    Alumno a;

    fflush(stdin);
    printf("\nIngrese el nombre del alumno: ");
    gets(a.nombre);
    printf("\nIngrese la legajo de [ %s ]: ", a.nombre);
    scanf("%i", &a.legajo);
    printf("\nIngrese la edad de [ %s ]: ", a.nombre);
    scanf("%i", &a.edad);
    printf("\nIngrese el anio de [ %s ]: ", a.nombre);
    scanf("%i", &a.anio);

    return a;
}

void loadStudents(char nombre_archivo[])
{
    int count = 5;
    Alumno a;

    FILE *archivin;
    archivin = fopen(nombre_archivo, "rb");
    if(archivin != NULL)
    {
        printf("\nEl archivo ya existe");
        fclose(archivin);

    }
    else
    {
        printf("\nCreando el archivo . . . ");
        archivin = fopen(nombre_archivo, "wb");
        for(int i = 0; i < count; i++)
        {
            a = cargarAlumno();
            fwrite(&a,sizeof(Alumno),1,archivin);
        }
        fclose(archivin);
    }

}

void mostrarAlumno(Alumno a)
{
    printf("\n[ %i ] [ %s ] [ %i ] [ %i ]", a.legajo, a.nombre, a.edad, a.anio);
}

void mostrarAlumnos(char nombre_archivo[])
{
    Alumno a;

    FILE *archivin;
    archivin = fopen(nombre_archivo, "rb");

    printf("\n===------------------------===");
    printf("\nLEGAJO | NOMBRES | EDAD | ANIO");

    while(fread(&a, sizeof(Alumno), 1, archivin) )
    {
        mostrarAlumno(a);
    }
    fclose(archivin);
    printf("\n===------------------------===");
}

int cantRegistros(char nombre_archivo[])
{
    int cant = 0;

    FILE *archivin;
    archivin = fopen(nombre_archivo, "rb");
    if (archivin != NULL)
    {
        fseek(archivin, 0, SEEK_END);
        cant = ftell(archivin) / sizeof(Alumno);
        fclose(archivin);
    }

    return cant;
}

void fileToArray(char nombre_archivo[], Alumno array1[DIM], int validos)
{
    int i = 0;
    Alumno alumnito;
    FILE *archivin;
    archivin = fopen(nombre_archivo, "rb");

    if (archivin != NULL)
    {
        while(fread(&alumnito, sizeof(Alumno), 1, archivin) > 0)
        {
            array1[i] = alumnito;
            i++;
        }
        fclose(archivin);
    }

}

void mostrarAlumnosArray(Alumno array1[DIM], int validos)
{
    printf("\n===--------------------===");
    printf("\nLEGAJO | NOMBRES | EDAD | ANIO");

    for(int i = 0; i < validos; i++)
    {
        mostrarAlumno(array1[i]);
    }
}
