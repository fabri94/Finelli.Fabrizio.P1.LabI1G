#include <stdio.h>
#include <stdlib.h>
#include "vuelo.h"


int inicializarVuelos(eVuelo vuelos[], int tamVue)
{
    int todoOk = 0;
    if(vuelos!=NULL && tamVue> 0)
    {
        for(int i=0; i < tamVue; i++)
        {
            vuelos[i].isEmpty = 1;
            todoOk = 1;
        }
    }
    return todoOk;

}

int buscarLibreVuelo(eVuelo vuelos[], int tamVue)
{
    int indice=-1;
    if(vuelos!=NULL && tamVue > 0)
    {
        for(int i = 0; i < tamVue; i++)
        {
            if(vuelos[i].isEmpty)
            {
                indice = i;
                break;
            }
        }
    }
    return indice;

}
