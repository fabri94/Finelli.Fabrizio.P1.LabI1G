#include <stdio.h>
#include <stdlib.h>
#include "avion.h"
#include "aerolinea.h"
#include "tipo.h"
#include "destino.h"
#include "vuelo.h"
#include "piloto.h"

#define TAM_AV 50
#define TAM_AERO 5
#define TAM_TIPOS 4
#define TAM_DEST 4
#define TAM_VUELOS 50
#define TAM_PIL 10

//PROFES NO LLEGUE A HACER EL ALTA DE VUELOS, NI MOSTRARLOS

int main()
{
    char seguir='s';
    int nextIdAvion=100;
    int nextIdVuelo=600;
    int flag=0;
    int flagVuelos=0;
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

    ePiloto pilotos[TAM_PIL]={
    {3000,"Camila",'f'},
    {3001,"Fabrizio",'m'},
    {3002,"Jesus",'m'},
    {3003,"Fernando",'m'},
    {3004,"Laura",'f'},
    {3005,"Gaspi",'m'},
    {3006,"Pepe",'m'},
    {3007,"Florencia",'f'},
    {3008,"Nicole",'f'},
    {3009,"Roberto",'m'},
    };

    inicializarAviones(lista,TAM_AV);

    inicializarVuelos(vuelos,TAM_AV);
    /*if(!inicializarVuelos(vuelos,TAM_VUELOS))
    {
        printf("Problema al inicializar almuerzos!\n");
    }*/

    //hardcodearPersonas(lista,TAM,7,&nextId);

    do{
        switch(menu())
        {
            case 1:
                if(!altaAvion(lista,TAM_AV,aerolineas,TAM_AERO,tipos,TAM_TIPOS,pilotos,TAM_PIL,&nextIdAvion))
                {
                    printf("No se pudo realizar el alta\n");
                }else
                {
                    printf("Alta realizada con exito!!!\n");
                    flag=1;
                }
                system("pause");
                break;
            case 2:
                if(flag)
                {
                    if(!modificarAvion(lista,TAM_AV,aerolineas,TAM_AERO,tipos,TAM_TIPOS,pilotos,TAM_PIL))
                    {
                        printf("No se pudo realizar la modificacion\n");
                    }else
                    {
                        printf("Modificacion realizada con exito!!!\n");
                    }
                }else
                {
                    printf("No se pueden modificar aviones si no hay ninguno cargado!\n");
                }
                system("pause");
                break;
            case 3:
                if(flag)
                {
                    if(!bajaAvion(lista,TAM_AV,aerolineas,TAM_AERO,tipos,TAM_TIPOS,pilotos,TAM_PIL))
                    {
                        printf("No se pudo realizar la baja\n");
                    }else
                    {
                        printf("Baja realizada con exito!!!\n");
                    }
                }else
                {
                    printf("No se pueden dar de baja aviones si no hay ninguno cargado!\n");
                }
                system("pause");
                break;
            case 4:
                ordenarAviones(lista,TAM_AV);
                if(!mostrarAviones(lista,TAM_AV,aerolineas,TAM_AERO,tipos,TAM_TIPOS,pilotos,TAM_PIL))
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
                    printf("No se pudieron mostrar los destinos\n");
                }
                system("pause");
                break;
            case 8:
                if(flag)
                {
                    if(!altaVuelos(vuelos,TAM_VUELOS,lista,TAM_AV,destinos,TAM_DEST,tipos,TAM_TIPOS,aerolineas,TAM_AERO,pilotos,TAM_PIL,&nextIdVuelo))
                    {
                        printf("No se pudo realizar el alta\n");
                    }else
                    {
                        printf("Alta realizada con exito!!!\n");
                        flagVuelos=1;
                    }
                }else
                {
                    printf("Primero debe dar de alta un avion para poder dar de alta un vuelo!!\n");
                }
                system("pause");
                break;
            case 9:
                if(flagVuelos)
                {
                    if(!mostrarVuelos(vuelos,TAM_VUELOS,lista,TAM_AV,destinos,TAM_DEST,tipos,TAM_TIPOS,aerolineas,TAM_AERO,pilotos,TAM_PIL))
                    {
                        printf("Hubo un error con los parametros y no se pueden mostrar los vuelos\n");
                    }
                }else
                {
                    printf("Para mostrar los vuelos, primero debe dar de alta alguno\n");
                }
                system("pause");
                break;
            case 10:
                if(!mostrarAvionesMismaAerolinea(lista,TAM_AV,aerolineas,TAM_AERO,tipos,TAM_TIPOS,pilotos,TAM_PIL))
                {
                    printf("No se pudieron mostrar los tipos de aviones\n");
                }
                system("pause");
                break;
            case 11:
                if(!mostrarAvionesMismoTipo(lista,TAM_AV,aerolineas,TAM_AERO,tipos,TAM_TIPOS,pilotos,TAM_PIL))
                {
                    printf("No se pudieron mostrar los tipos de aviones\n");
                }
                system("pause");
                break;
            case 13:
                if(!mostrarTodosLosAvionesPorAerolinea(lista,TAM_AV,aerolineas,TAM_AERO,tipos,TAM_TIPOS,pilotos,TAM_PIL))
                {
                    printf("No se pudieron mostrar los tipos de aviones\n");
                }
                system("pause");
                break;
            case 14:
                if(!mostrarAerolineasMasOcupadas(lista,TAM_AV,aerolineas,TAM_AERO,tipos,TAM_TIPOS,pilotos,TAM_PIL))
                {
                    printf("No se pudieron mostrar los tipos de aviones\n");
                }
                system("pause");
                break;
            case 15:
                if(!mostrarAerolineaMenorCantidadAviones(lista,TAM_AV,aerolineas,TAM_AERO,tipos,TAM_TIPOS,pilotos,TAM_PIL))
                {
                    printf("No se pudieron mostrar los tipos de aviones\n");
                }
                system("pause");
                break;

            case 16:
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


