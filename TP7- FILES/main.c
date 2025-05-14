#include <stdio.h>
#include <stdlib.h>
#include "pila.h"

typedef struct
{
    int legajo;
    char nombre[30];
    int edad;
    int anio;

} Alumno;


Alumno cargarAlumno();
void loadStudents(char nombre_archivo[]);
void insanePila(Pila* A, char nombre_archivo[]);

int main()
{

    ///-----------variables------------//
    int ejercicio = 0;
    char name[] = "file.dat";
    char namealumnos[] = "alumnos.dat";
    int ammount;
    Pila pilovich;
    inicpila(&pilovich);

    ///--------------------------------//

    puts("\n--------OPCIONES---------");
    puts("\n1.Ejercicio 1, 2, y 3: Cargar un archivo, mostrarlo, contar los elementos");
    puts("\n2.Ejercicio 4 y 5: Cargar y mostrar un registro de alumnos");
    puts("\n3.Ejercicio 6: Agregar un alumno extra al archivo de alumnos");
    puts("\n4.Ejercicio 7: Pasar el legajo de los mayores de edad a una pila");
    puts("\n\nIngrese una opcion (primer numero): ");
    scanf("%i", &ejercicio);

    switch(ejercicio)
    {
    case 1:
        addfile(name);
        showfile(name);
        ammount = howmany(name);
        printf("\nAmmount of elements: %i", ammount);
        break;
    case 2:
        loadStudents(namealumnos);
        mostrarAlumnos(namealumnos);
        break;
    case 3:
        puts("\nAgreguemos un alumno mas!");
        addAStudent(namealumnos);
        mostrarAlumnos(namealumnos);
        break;
    case 4:
        insanePila(&pilovich, namealumnos);
        printf("\nLegajo de los alumnos mayores de edad: ");
        mostrar(&pilovich);
        break;

    default:
        printf("\nError FATAL........1.1..1.: opcion invalida");
        break;
    }

    return 0;
}

void addfile(char nombre_archivo[])
{
    int yep = 0;
    ///---- opening it
    FILE *archivin;
    archivin = fopen(nombre_archivo, "ab");

    if(archivin != NULL)
    {
        printf("\nIngrese un int: ");
        scanf("%i", &yep);

        fwrite(&yep, sizeof(int), 1, archivin);
        fclose(archivin);

    }
    else
    {
        printf("\nNo se ha encontrado el archivo!");
    }
}

void showfile(char nombre_archivo[])
{
    int yep = 0;

    FILE *archivin;
    archivin = fopen(nombre_archivo, "rb");

    if(archivin != NULL)
    {
        while(fread(&yep, sizeof(int),1, archivin) > 0)
        {
            printf("\nINT: %i", yep);
        }
        fclose(archivin);
    }
    else
    {
        printf("\nNo se ha encontrado el archivo!");
    }
}

int howmany(char nombre_archivo[])
{
    int count = 0;
    int yep = 0; //idk why

    FILE *archivin;
    archivin = fopen(nombre_archivo, "rb");

    if(archivin != NULL)
    {
        printf("\nbeep beep starting count . . . . .");
        while(!feof(archivin))
        {
            fread(&yep, sizeof(int),1, archivin);
            if (!feof(archivin))
            {
                printf("\nCOUNTED!");
                count++;
            }
        }
        fclose(archivin);
    }
    else
    {
        printf("\nNo se ha encontrado el archivo!");
    }
    return count;
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
Alumno cargarAlumno()
{
    Alumno a;

    printf("\nIngrese el nombre del alumno: ");
    scanf(" %s", &a.nombre);
    printf("\nIngrese la legajo de [ %s ]: ", a.nombre);
    scanf("%i", &a.legajo);
    printf("\nIngrese la edad de [ %s ]: ", a.nombre);
    scanf("%i", &a.edad);
    printf("\nIngrese el anio de [ %s ]: ", a.nombre);
    scanf(" %c", &a.anio);
    fflush(stdin);
    return a;
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

void addAStudent(char nombre_archivo[])
{
    Alumno a;

    FILE *archivin;
    archivin = fopen(nombre_archivo, "rb");

    if(archivin != NULL)
    {
        archivin = fopen(nombre_archivo, "ab");
        a = cargarAlumno();
        fwrite(&a,sizeof(Alumno),1,archivin);
        fclose(archivin);
    }
    else
    {
        printf("\nEl archivo no existe");
        fclose(archivin);
    }
}

void insanePila(Pila* A, char nombre_archivo[])
{
    Alumno alumnito;
    int integer = 0;

    FILE *archivin;
    archivin = fopen(nombre_archivo, "rb");

    while(fread(&alumnito, sizeof(Alumno), 1, archivin) > 0)
    {
        if(alumnito.anio >= 18)
        {
            apilar(A, alumnito.legajo);
        }
    }

    fclose(archivin);
}
