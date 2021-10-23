#include <stdio.h>
#include <stdlib.h>
#include "avion.h"
#include "aerolinea.h"
#include "tipo.h"
#include "destino.h"
#include "vuelo.h"
#define TAM_AV 50
#define TAM_AERO 5
#define TAM_TIPOS 4
#define TAM_DEST 4
#define TAM_VUELOS 50

//PROFES NO LLEGUE A HACER EL ALTA DE VUELOS, NI MOSTRARLOS

int main()
{
    char seguir='s';
    int nextIdAvion=100;
    int nextIdVuelo=600;
    eAvion lista[TAM_AV];
    eVuelo vuelos[TAM_VUELOS];

    eAerolinea aerolineas[TAM_AERO]={
    {1000,"Lan"},
    {1001,"Iberian"},
    {1002,"Norwegian"},
    {1003,"American"},
    {1004,"Austral"}
    };

    eTipo tipos[TAM_TIPOS]={
    {5000,"Jet"},
    {5001,"Helice"},
    {5002,"Planeador"},
    {5003,"Carga"}
    };

    eDestino destinos[TAM_DEST]={
    {20000,"Calafate",22250},
    {20001,"Miami",100300},
    {20002,"Madrid",84400},
    {20003,"Amsterdam",95600}
    };


    if(!inicializarAviones(lista,TAM_AV))
    {
        printf("Problema al inicializar personas!\n");
    }

    //if(!inicializarVuelos(vuelos,TAM_VUELOS))
    {
        printf("Problema al inicializar almuerzos!\n");
    }

    //hardcodearPersonas(lista,TAM,7,&nextId);

    do{
        switch(menu())
        {
            case 1:
                if(!altaAvion(lista,TAM_AV,aerolineas,TAM_AERO,tipos,TAM_TIPOS,&nextIdAvion))
                {
                    printf("No se pudo realizar el alta\n");
                }else
                {
                    printf("Alta realizada con exito!!!\n");
                }
                system("pause");
                break;
            case 2:
                if(!modificarAvion(lista,TAM_AV,aerolineas,TAM_AERO,tipos,TAM_TIPOS))
                {
                    printf("No se pudo realizar la baja\n");
                }else
                {
                    printf("Baja realizada con exito!!!\n");
                }
                system("pause");
                break;
            case 3:
                if(!bajaAvion(lista,TAM_AV,aerolineas,TAM_AERO,tipos,TAM_TIPOS))
                {
                    printf("No se pudo realizar la modificacion\n");
                }else
                {
                    printf("Modificacion realizada con exito!!!\n");
                }
                system("pause");
                break;
            case 4:
                if(!mostrarAviones(lista,TAM_AV,aerolineas,TAM_AERO,tipos,TAM_TIPOS))
                {
                    printf("No se pudieron mostrar los aviones\n");
                }
                system("pause");
                break;
            case 5:
                    if(!mostrarAerolineas(aerolineas,TAM_AERO))
                    {
                    printf("No se pudieron mostrar las aerolineas\n");
                    }
                    system("pause");
                    break;
            case 6:
                if(!mostrarTipos(tipos,TAM_TIPOS))
                {
                    printf("No se pudieron mostrar los tipos de aviones\n");
                }
                system("pause");
                break;
            case 7:
                //system("cls");
                if(!mostrarDestinos(destinos,TAM_DEST))
                {
                    printf("No se pudieron mostrar los aviones\n");
                }
                system("pause");
                break;
            //case 8:
                //system("cls");

            case 10:
                printf("Ha seleccionado salir\n");
                system("pause");
                seguir='n';
                break;
            default:
                    printf("opcion invalida\n");
                    system("pause");
                    break;
        }
    }while(seguir=='s');



    return 0;
}


