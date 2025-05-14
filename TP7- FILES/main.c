#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int legajo;
    char nombre[30];
    int edad;
    int anio;

} Alumno;


Alumno cargarAlumno();
void loadStudents(char nombre_archivo[]);

int main()
{
    char name[] = "file.dat";
    char namealumnos[] = "alumnos.dat";
    int validos = 0;

    //addfile(name);
    //showfile(name);
    //puts("\n-----------------------");

    //int ammount = howmany(name);
    //printf("\nAmmount of elements: %i", ammount);
    //puts("\n-----------------------");

    loadStudents(namealumnos);
    mostrarAlumnos(namealumnos);
    puts("\nAgreguemos un alumno mas!");
    addAStudent(namealumnos);
    mostrarAlumnos(namealumnos);



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
