#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "aerolinea.h"

int cargarDescripcionAerolinea(eAerolinea aerolineas[], int tamAero, int idAero, char descripcion[])
{
    int todoOk=0;
    int flag=1;
    if(aerolineas!=NULL&&tamAero>0&&descripcion!=NULL)
    {
        todoOk=1;
        for(int i=0; i<tamAero; i++)
        {
            if(aerolineas[i].id==idAero)
            {
                strcpy(descripcion, aerolineas[i].descripcion);
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

int mostrarAerolineas(eAerolinea aerolineas[], int tamAero)
{
    int todoOk=0;
    if(aerolineas!=NULL && tamAero>0)
    {
        printf(" ***Listado de aerolineas de Aviones ***\n");
        printf("---------------------\n");
        printf(" ID     Descripcion\n");
        printf("---------------------\n");
        for(int i=0;i<tamAero;i++)
        {
            printf(" %d:  %10s\n",aerolineas[i].id, aerolineas[i].descripcion);
        }
        printf("\n\n");

        todoOk=1;
    }

    return todoOk;

}
