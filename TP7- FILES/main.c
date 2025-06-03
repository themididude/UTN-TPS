#include <stdio.h>
#include <stdlib.h>
#define MAXALUMNOS 10
/*
-Hacer una función que agregue un elemento al final de un archivo.
-Hacer una función que muestre por pantalla el contenido de un archivo.
-Hacer una función que retorne la cantidad de registros que contiene un archivo.
-Crear una función que cargue un archivo de alumnos. Abrirlo de manera tal de verificar si el archivo ya está creado previamente. Cargar el archivo con 5 datos. Cerrarlo dentro de la función
-Carear una función que muestre por pantalla los registros de un archivo de alumnos. Modularizar.
-Crear una función que permita agregar de a un elemento al final del archivo. O sea, se debe abrir el archivo, se piden los datos (se llena una variable de tipo struct alumno), se escribe en el archivo y se cierra.
-Crear una función que pase a una pila los números de legajo de los alumnos mayores de edad.
-Dado un archivo de alumnos, hacer una función que cuente la cantidad de alumnos mayores a edad específica que se envía por parámetro.
-Dado un archivo de alumnos, mostrar por pantalla el nombre de todos los alumnos entre un rango de edades específico (por ejemplo, entre 17 y 25 años). Dicho rango debe recibirse por parámetro. Modularizar

*/

typedef struct {
     int legajo;
     char nombre[30];
     int edad;
     int anio;
//año que cursa, recordar que no podemos utilizar la ñ para definir variables
} Alumno;

void addElement(char filename[], int element);
void addingLoop(char filename[]);
void showFile(char filename[]);
int countRegisters(char filename[]);

int main()
{
    ///variables and stuff///
    char fname[] = "ourfile";
    int registros = 0;
    Alumno alumnos[MAXALUMNOS];


    //PUNTO 1, 2, 3 - TESTING
    printf("\nPrimero, llenemos el archivo.");
    //addingLoop(fname);
    printf("\nDebug answer: we already did lol");
    showFile(fname);
    registros = countRegisters(fname);
    printf("\nCantidad de registros: %i", registros);



    printf("\nUNA MALNASIDA W EN EL CHAT papus");
    return 0;
}


/////////////////////////// first part///////////////////////////////////////////////
void addElement(char filename[], int element)
{

    FILE *archivin;
    archivin = fopen(filename,  "ab"); //ab pone el indicador al final

    if (archivin != NULL)
    {
        fwrite(&element, sizeof(int),1, archivin);

    } else {

        printf("\nError: the file doesnt exist dude");
    }
    fclose(archivin);
}

void addingLoop(char filename[])
{
    int continuee = 1;

    while(continuee == 1)
    {
        int value = 0 ;
        printf("\nIngrese un elemento:");
        scanf("%i", &value);
        addElement(filename, value);

        printf("\nIngrese 1 para agregar mas valores: ");
        scanf("%i", &continuee);
    }
}

void showFile(char filename[])
{
    int value;

    FILE* archivin;
    archivin = fopen(filename, "rb"); //we only need to read it

    if(archivin!=NULL)
    {
        while(fread(&value, sizeof(int),1, archivin) > 0) //so while theres things left to count
        {
            printf("\nINT = %i", value);
        }

    } else {
        printf("\nError: the file doesnt exist dude");
    }
    fclose(archivin);
}

int countRegisters(char filename[])
{
    FILE* archivin;
    archivin = fopen(filename, "rb"); //we only need to read it

    if(archivin==NULL) return -1;

    fseek(archivin, 0, SEEK_END);      //vamos al final
    long size = ftell(archivin);       //get the size
    fclose(archivin);

    return size / sizeof(int);           //return, divide by sizeof typefile
}


/////// new section /// alumnos // if yk yk ////////

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

void cargarArchivoAlumnos(char filename[])
{
    int count = 5; // cargar 5 alumnos
    Alumno a;

    FILE *archivin;
    archivin = fopen(filename, "wb");

    if(archivin != NULL)
    {
        printf("\nError: el archivo ya existe bludi");
    } else {
        for(int i=0; i < count; i++)
        {
            a = cargarAlumno();
            fwrite(&a, sizeof(Alumno), 1, archivin);
        }
    }
    fclose(archivin);
}

void mostrarAlumno(Alumno a)
{
    printf("\n[ %i ] [ %s ] [ %i ] [ %i ]", a.legajo, a.nombre, a.edad, a.anio);
}

void mostrarAlumnos(char filename[])
{
    Alumno a;

    FILE *archivin;
    archivin = fopen(filename, "rb");

    printf("\n===------------------------===");
    printf("\nLEGAJO | NOMBRES | EDAD | ANIO");

    while(fread(&a, sizeof(Alumno), 1, archivin) > 0) //so its not over
    {
        mostrarAlumno(a);
    }
    fclose(archivin);
    printf("\n===------------------------===");
}
