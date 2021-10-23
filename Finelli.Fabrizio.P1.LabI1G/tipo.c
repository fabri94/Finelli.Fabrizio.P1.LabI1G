#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tipo.h"

int cargarDescripcionTipo(eTipo tipos[], int tamTipos, int idTipo, char descripcion[])
{
    int todoOk=0;
    int flag=1;
    if(tipos!=NULL&&tamTipos>0&&descripcion!=NULL)
    {
        todoOk=1;
        for(int i=0; i<tamTipos; i++)
        {
            if(tipos[i].id==idTipo)
            {
                strcpy(descripcion, tipos[i].descripcion);
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

int mostrarTipos(eTipo tipos[], int tamTipos)
{
    int todoOk=0;
    if(tipos!=NULL && tamTipos>0)
    {
        printf(" ***Tipos de Aviones ***\n");
        printf("---------------------\n");
        printf(" ID     Descripcion\n");
        printf("---------------------\n");
        for(int i=0;i<tamTipos;i++)
        {
            printf(" %d:  %10s\n",tipos[i].id, tipos[i].descripcion);
        }
        printf("\n\n");

        todoOk=1;
    }


    return todoOk;
}
