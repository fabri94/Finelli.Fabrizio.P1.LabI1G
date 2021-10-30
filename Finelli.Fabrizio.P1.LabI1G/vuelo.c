#include <stdio.h>
#include <stdlib.h>
#include "vuelo.h"
#include "inputs.h"


int inicializarVuelos(eVuelo vuelos[], int tamVue)
{
    int todoOk=0;
    if(vuelos!=NULL&&tamVue>0)
    {
        for(int i=0;i<tamVue;i++)
        {
            vuelos[i].isEmpty=1;
            todoOk=1;
        }
    }
    return todoOk;

}

int buscarLibreVuelo(eVuelo vuelos[], int tamVue)
{
    int indice=-1;
    if(vuelos!=NULL&&tamVue>0)
    {
        for(int i=0;i<tamVue;i++)
        {
            if(vuelos[i].isEmpty)
            {
                indice=i;
                break;
            }
        }
    }
    return indice;

}

void mostrarVuelo(eVuelo unVuelo, eAvion lista[], int tamAv, eDestino destinos[], int tamDest, eTipo tipos[], int tamTipos, eAerolinea aerolineas[], int tamAero, ePiloto pilotos[], int tamPil, int idAv)
{
    char descDestino[20];
    char descTipo[20];
    char descAerolinea[20];
    char nombrePiloto[20];
    int idTipo;
    int idAerolinea;
    int idPiloto;
    int precio;

    buscarTipoYAerolineaAvion(lista,tamAv,idAv,&idAerolinea,&idTipo,&idPiloto);


    if((cargarDescripcionDestinos(destinos,tamDest,unVuelo.idDestino,descDestino,&precio)==1)
       &&(cargarDescripcionAerolinea(aerolineas,tamAero,idAerolinea,descAerolinea)==1)
       &&(cargarDescripcionTipo(tipos,tamTipos,idTipo,descTipo)==1)
       &&(cargarDescripcionPiloto(pilotos,tamPil,idPiloto,nombrePiloto))==1)//&&cargarNombrePersona(lista,tam,unAlmuerzo.idPersona,nombre)==1)
    {
        printf(" %3d  %-10s %-10s %-10s %02d/%02d/%d   $%d    %s\n"
           ,unVuelo.id
           ,descTipo
           ,descAerolinea
           ,descDestino
           ,unVuelo.fecha.dia
           ,unVuelo.fecha.mes
           ,unVuelo.fecha.anio
           ,precio
           ,nombrePiloto);
    }


}


int mostrarVuelos(eVuelo vuelos[], int tamVue, eAvion lista[], int tamAv, eDestino destinos[], int tamDest, eTipo tipos[], int tamTipos, eAerolinea aerolineas[], int tamAero, ePiloto pilotos[], int tamPil)
{
    int todoOk=0;
    int flag=1;


    if(vuelos!=NULL&&tamVue>0&&lista!=NULL&&tamAv>0&&destinos!=NULL&&tamDest>0&&tipos!=NULL)
    {
        system("cls");
        printf("             *****  Lista de Vuelos  *****\n");
        printf("-------------------------------------------------------------------------\n");
        printf("  ID  Avion   Aerolinea     Destino    Fecha        Precio    Piloto\n");
        printf("-------------------------------------------------------------------------\n");
        for(int i=0;i<tamVue;i++)
        {
            if(!vuelos[i].isEmpty)
            {
                mostrarVuelo(vuelos[i],lista,tamAv,destinos,tamDest,tipos,tamTipos,aerolineas,tamAero,pilotos,tamPil,vuelos[i].idAvion);
                flag=0;
            }
        }
        if(flag)
        {
            printf("El listado esta vacio...\n");
        }
        todoOk=1;
    }

    return todoOk;


}


int altaVuelos(eVuelo vuelos[], int tamVue, eAvion lista[], int tamAv, eDestino destinos[], int tamDest, eTipo tipos[], int tamTipos, eAerolinea aerolineas[], int tamAero, ePiloto pilotos[], int tamPil, int* pIdVue)
{
    int todoOk=0;
    int indice;
    eVuelo auxVuelo;
    if(vuelos!=NULL&&pIdVue!=NULL&&tamVue>0&&lista!=NULL&&tamAv>0&&destinos!=NULL&&tamDest>0&&tipos!=NULL&&tamTipos>0&&aerolineas!=NULL&&tamAero>0)
    {
        system("cls");
        printf("   **** Alta vuelo ****\n\n");
        indice=buscarLibreVuelo(vuelos,tamVue);
        if(indice==-1)
        {
            printf("No hay lugar\n");
        }else
        {
            auxVuelo.id=*pIdVue;
            (*pIdVue)++;

            mostrarAviones(lista,tamAv,aerolineas,tamAero,tipos,tamTipos,pilotos,tamPil);
            if(!getEntero(&auxVuelo.idAvion,100,149,3,"Ingrese id del avion: ","Error, reingrese id del avion: \n\n"))
            {
                printf("Se excedio el limite de intentos\n\n");
            }
            printf("\n\n");

            mostrarDestinos(destinos,tamDest);
            if(!getEntero(&auxVuelo.idDestino,20000,20003,3,"Ingrese id del destino: ","Error reingrese id del destino: \n\n"))
            {
                printf("Se excedio el limite de intentos\n\n");
            }
            printf("\n\n");

            printf("Ingrese fecha del vuelo dd/mm/aaaa: ");
            scanf("%d/%d/%d",&auxVuelo.fecha.dia,&auxVuelo.fecha.mes,&auxVuelo.fecha.anio);
            while((auxVuelo.fecha.dia<1||auxVuelo.fecha.dia>31)||(auxVuelo.fecha.mes<1||auxVuelo.fecha.mes>12)||(auxVuelo.fecha.anio<1980||auxVuelo.fecha.anio>2060))
            {
                printf("Error, reingrese fecha del vuelo dd/mm/aaaa: ");
                scanf("%d/%d/%d",&auxVuelo.fecha.dia,&auxVuelo.fecha.mes,&auxVuelo.fecha.anio);
            }

            auxVuelo.isEmpty=0;

            vuelos[indice]=auxVuelo;

            todoOk=1;
        }
    }

    return todoOk;


}
