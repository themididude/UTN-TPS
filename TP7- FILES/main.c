#include <stdio.h>
#include <stdlib.h>

typedef struct {
     int legajo;
     char nombreYapellido [30];
     int edad;
     int anio;

} alumno;


int main()
{
    char name[] = "file.dat";
    int yep = 0;
    addfile(name, yep);





    return 0;
}

void addfile(char nombre_archivo[], int yep)
{
    ///---- opening it
    FILE *archivin;
    archivin = fopen(nombre_archivo, "ab");

    if(archivin == NULL)
    {
        printf("\nNo se ha encontrado el archivo!");
    }

    printf("\nIngrese un int: ");
    scanf("%i", &yep);

    fwrite(yep, sizeof(int), 1, archivin);
    fclose(archivin);
}

void showfile(char nombre_archivo[])
{
    FILE *archivin;
    archivin = fopen(nombre_archivo, "rb");


}
