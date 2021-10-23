#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "destino.h"

int mostrarDestinos(eDestino destinos[], int tamDest)
{
    int todoOk=0;
    if(destinos!=NULL && tamDest>0)
    {
        printf(" ***Listado de destinos ***\n");
        printf("---------------------\n");
        printf(" ID Destino  Precio\n");
        printf("---------------------\n");
        for(int i=0;i<tamDest;i++)
        {
            printf("%d %10s  %d\n",destinos[i].id,destinos[i].descripcion,destinos[i].precio);
        }
        printf("\n\n");

        todoOk=1;
    }

    return todoOk;


}
