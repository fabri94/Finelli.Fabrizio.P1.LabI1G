#include "dataWarehouse.h"
#include <string.h>

char nombres[10][20]={
    "gaspi",
    "elpepe",
    "fabri",
    "pollo",
    "luigi",
    "maria",
    "julieta",
    "nicole",
    "christian",
    "fiumba"
};

char apellidos[10][20]={
    "gutierrez",
    "salvador",
    "finelli",
    "gallina",
    "bros",
    "laferrre",
    "larralde",
    "diaz",
    "baus",
    "chumba"
};

float salarios[10]={80000,65000,72985,85000,60000,30000,45000,58000,120000,430000};

int sectores[10]={104,100,100,100,103,104,104,103,105,100};


int hardcodearEmpleados(Employee lst[], int len, int cant, int* pId)
{
    int contador=-1;
    if(lst!=NULL&&len>0&& cant>=0 && cant <=len && pId!=NULL)
    {
        contador=0;
        for(int i=0; i<cant ; i++)
        {
            lst[i].id= *pId;
            (*pId)++;
            strcpy(lst[i].name, nombres[i]);
            strcpy(lst[i].lastName, apellidos[i]);
            lst[i].salary=salarios[i];
            lst[i].sector=sectores[i];
            lst[i].isEmpty=0;
            contador++;
        }
    }
    return contador;
}
