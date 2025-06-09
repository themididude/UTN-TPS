#include <stdio.h>
#include <stdlib.h>


typedef struct{
    int idRegistro;
    int idPaciente;
    int idEspecialidadMedica;
    char nombrePaciente[30];
    char apellidoPaciente[30];
    char diagnostico[100];
    char fechaAtencion[11];   /// formato: AAAA-mm-DD
    char especialidadMedica[30];
    char nombreDoctor[30];
    float precioAtencion;
}RegistroMedico;

int main()
{
    ///some variables n stuff
    char fname[] = "archivofr";




    return 0;
}

void makefile(char filename[])
{
    FILE* archivin;
    archivin = fopen(filename, "rb");

}


int fileToArray(char filename[], RegistroMedico array1[])
{
    RegistroMedico a;
    int validos = 0;
    int i = 0;

    FILE* archivin;
    archivin = fopen(filename, "wb");

    if(archivin!=NULL)
    {
        fclose(archivin);
        printf("\nError: el archivo ya existe");
    } else {
        //fr!!
    }
    fclose(archivin);

}
    if(archivin!=NULL)
    {
        while(fread(&a, sizeof(RegistroMedico), 1, archivin > 0))
        {
            array1[i] = a;
            i++;
        }
        fclose(archivin);
    }else
        {
            fclose(archivin);
            printf("\nError: archivo inexistente!");
        }
        fclose(archivin);
    return i; //validos
}


