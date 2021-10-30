#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "piloto.h"

int cargarDescripcionPiloto(ePiloto pilotos[], int tamPil, int idPil, char nombre[])
{
    int todoOk=0;
    int flag=1;
    if(pilotos!=NULL&&tamPil>0&&nombre!=NULL)
    {
        todoOk=1;
        for(int i=0;i<tamPil;i++)
        {
            if(pilotos[i].id==idPil)
            {
                strcpy(nombre, pilotos[i].nombre);

                flag=0;
                break;
            }
        }
        if(flag)
        {
            todoOk=-1;
        }
    }

    return todoOk;
}

int mostrarPilotos(ePiloto pilotos[], int tamPil)
{
    int todoOk=0;
    if(pilotos!=NULL&&tamPil>0)
    {
        printf("    ***Lista de Pilotos ***\n");
        printf("-------------------------------\n");
        printf(" ID         Nombre   Sexo\n");
        printf("-------------------------------\n");
        for(int i=0;i<tamPil;i++)
        {
            printf(" %d:  %10s    %c\n",pilotos[i].id, pilotos[i].nombre, pilotos[i].sexo);
        }
        printf("\n\n");

        todoOk=1;
    }
    return todoOk;

}
