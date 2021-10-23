#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "inputs.h"
#include "avion.h"
#include "aerolinea.h"
#include "tipo.h"

int menu()
{
    int opcion;
    system("cls");
    printf("     *** Menu de opciones ***\n\n");
    printf("1- Alta avion\n");
    printf("2- Modificar avion\n");
    printf("3- Baja avion\n");
    printf("4- Listar aviones\n");
    printf("5- Listar aerolineas\n");
    printf("6- Listar tipos\n");
    printf("7- Listar destinos\n");
    printf("8- Alta vuelos\n");
    printf("9- Listar vuelos\n");
    printf("10- Salir\n");
    printf("Ingrese opcion: ");
    scanf("%d",&opcion);

    return opcion;
}

int menuModificacion()
{
    int opcion;
    printf("\n");
    printf("1- Modificar tipo de avion\n");
    printf("2- Modificar capacidad del avion\n");
    printf("Ingrese opcion: ");
    scanf("%d",&opcion);

    return opcion;
}

int inicializarAviones(eAvion lista[], int tamAv)
{
    int todoOk=0;
    if(lista!=NULL&&tamAv>0)
    {
        for(int i=0;i<tamAv;i++)
        {
            lista[i].isEmpty=1;
        }
        todoOk=1;
    }
    return todoOk;
}

int buscarLibreAvion(eAvion lista[], int tamAv)
{
    int posicionLibre=-1; //me devuelve -1 si no encuentra posicion libre. sino devuelve el indice de la posicion libre

    if(lista!=NULL&&tamAv>0)
    {
        for(int i=0;i<tamAv;i++)
        {
            if(lista[i].isEmpty)
            {
                posicionLibre=i;
                break;
            }
        }
    }
    return posicionLibre;

}

int buscarAvionId(eAvion lista[], int tamAv, int id)
{
    int posicionAvion=-1;

        for(int i=0;i<tamAv;i++)
        {
            if(lista[i].id==id&&!lista[i].isEmpty)//si el id que le paso coincide con uno que ya este cargado y ademas me cercioro de que esa posicion no este libre, entonces entro
            {
                posicionAvion=i;
                break;
            }

        }

    return posicionAvion;

}

int altaAvion(eAvion lista[], int tamAv, eAerolinea aerolineas[], int tamAero, eTipo tipos[], int tamTipos, int* pIdAv)
{
    int todoOk=0;
    int indice;
    eAvion auxAvion;
    if(lista!=NULL&&tamAv>0&&aerolineas!=NULL&&tamAero>0&&tipos!=NULL&&tamTipos>0&&pIdAv!=NULL)
    {
        system("cls");
        printf("   **** Alta avion ****\n\n");
        indice=buscarLibreAvion(lista,tamAv);
        if(indice==-1)
        {
            printf("No hay lugar\n");
        }else
        {
            auxAvion.id=*pIdAv;
            (*pIdAv)++;

            mostrarAerolineas(aerolineas,tamAero);

            if(!getEntero(&lista[indice].idAerolinea,1000,1004,3,"Ingrese id de la aerolinea: ","Error en la carga de la aerolinea\n\n"))
            {
                printf("Se excedio el limite de intentos\n\n");
            }

            mostrarTipos(tipos,tamTipos);

            if(!getEntero(&lista[indice].idTipo,5000,5003,3,"Ingrese id del tipo de avion: ","Error en la carga del tipo de avion\n\n"))
            {
                printf("Se excedio el limite de intentos\n\n");
            }

            if(!getEntero(&lista[indice].capacidad,10,300,3,"Ingrese capacidad del avion: ","Error en la carga del tipo de avion\n\n"))
            {
                printf("Se excedio el limite de intentos\n\n");
            }

            auxAvion.isEmpty=0;//se cargo la estructura, entonces 'ta ocupada
            lista[indice]=auxAvion;

            todoOk=1;
        }
    }

    return todoOk;

}

void mostrarAvion(eAvion unAvion, eAerolinea aerolineas[], int tamAero, eTipo tipos[], int tamTipos)
{

    char descAerolinea[20];
    char descTipoAvion[20];

    if((cargarDescripcionAerolinea(aerolineas,tamAero,unAvion.idAerolinea,descAerolinea))==1&&(cargarDescripcionTipo(tipos,tamTipos,unAvion.idTipo,descTipoAvion))==1)
    {
        printf(" %d   %10s       %10s    %d\n"
           ,unAvion.id
           ,descAerolinea
           ,descTipoAvion
           ,unAvion.capacidad);
    }
}

int mostrarAviones(eAvion lista[], int tamAv, eAerolinea aerolineas[], int tamAero, eTipo tipos[], int tamTipos)
{
    int todoOk=0;
    int flag=1;


    if(lista!=NULL&&tamAv>0&&aerolineas!=NULL&&tamAero>0&&tipos!=NULL&&tamTipos>0)
    {
        system("cls");
        printf("     *****  Lista de Aviones  *****\n");
        printf("----------------------------------------------------------\n");
        printf("   ID    Aerolinea  Tipo   Capacidad\n");
        printf("----------------------------------------------------------\n");
        for(int i=0;i<tamAv;i++)
        {
            if(!lista[i].isEmpty)
            {
                mostrarAviones(lista,tamAv,aerolineas,tamAero,tipos,tamTipos);
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

int bajaAvion(eAvion lista[], int tamAv, eAerolinea aerolineas[], int tamAero, eTipo tipos[], int tamTipos)
{
    int todoOk=0;
    int indice;
    int id;
    char confirma;

    if(lista!=NULL&&tamAv>0&&aerolineas!=NULL&&tamAero>0&&tipos!=NULL&&tamTipos>0)
    {
        system("cls");
        printf("   ***Baja avion**** \n\n");
        printf("Ingrese id: ");
        scanf("%d",&id);

        indice=buscarAvionId(lista,tamAv,id); //llamo a la funcion buscar por id, y al indice encontrado en la lista de personas analizada por la fx, lo asigno a la variable indice de este scope
        if(indice==-1)
        {
            printf("El id: %d no existe en el sistema\n",id);

        }else
        {
            mostrarAvion(lista[indice],aerolineas,tamAero,tipos,tamTipos);
            printf("Confirma baja?: ");
            fflush(stdin);
            scanf("%c",&confirma);
            if(confirma=='s'||confirma=='S')
            {
                lista[indice].isEmpty=1;
                todoOk=1;

            }else
            {
                printf("Baja cancelada por el usuario\n");
            }

        }


    }

    return todoOk;
}

int modificarAvion(eAvion lista[], int tamAv, eAerolinea aerolineas[], int tamAero, eTipo tipos[], int tamTipos)
{
    int todoOk=0;
    int indice;
    int id;
    char confirma;
    char salirMenu;
    char confirmarModificaciones;
    int flag;
    eAvion auxAvion;

    if(lista!=NULL&&tamAv>0&&aerolineas!=NULL&&tamAero>0&&tipos!=NULL&&tamTipos>0)
    {
        system("cls");
        printf("   ***Modificar avion**** \n\n");
        mostrarAviones(lista,tamAv,aerolineas,tamAero,tipos,tamTipos);
        printf("Ingrese id del avion a modificar: ");
        if(!getEntero(&id,3000,3049,3,"Ingrese id del avion a modificar: ","ID inexistente\n\n"))
        {
            printf("Se excedio el limite de intentos\n\n");
        }
        indice=buscarAvionId(lista,tamAv,id); //llamo a la funcion buscar por id, y al indice encontrado en la lista de personas analizada por la fx, lo asigno a la variable indice de este scope
        if(indice==-1)
        {
            printf("El id: %d no existe en el sistema\n",id);
        }else
        {
            printf("\n");
            mostrarAvion(lista[indice],aerolineas,tamAero,tipos,tamTipos);
            printf("\n");
            //submenu
            printf("¿Confirma modificacion?: ");
            fflush(stdin);
            scanf("%c",&confirma);

            if(confirma=='s')
            {
                do
                {
                    switch(menuModificacion())
                    {
                    case 1:
                        mostrarTipos(tipos,tamTipos);
                        if(!getEntero(&auxAvion.idTipo,5000,5003,3,"Ingrese id del nuevo tipo de avion: ","ID inexistente\n\n"))
                        {
                            printf("Se excedio el limite de intentos\n\n");
                        }
                        flag=1;
                        break;
                    case 2:
                        if(!getEntero(&auxAvion.capacidad,10,300,3,"Ingrese nueva capacidad del avion: ","Capacidad incorrecta\n\n"))
                        {
                            printf("Se excedio el limite de intentos\n\n");
                        }
                        flag=1;
                        break;
                    case 3:
                        printf("¿Desea salir? 's' para si, 'n' para no: ");
                        fflush(stdin);
                        scanf("%c",&salirMenu);
                        break;
                    default:
                        printf("Opcion invalida!!!");
                        system("pause");
                        break;
                    }
                    if(flag)
                    {
                        printf("¿Confirma las modificaciones?: ");
                        fflush(stdin);
                        scanf("%c",&confirmarModificaciones);
                        if(confirmarModificaciones=='s')
                        {
                            lista[indice]=auxAvion;
                            printf("--- Avion modificado ----\n");
                            mostrarAvion(lista[indice],aerolineas,tamAero,tipos,tamTipos);
                            printf("-------------\n\n");
                            todoOk = 1;
                        }
                        else
                        {
                            printf("El usuario cancelo las modificaciones\n\n");
                        }
                        system("pause");
                    }
                    todoOk=1;
                }while(salirMenu!='s');
            }else
            {
                printf("Modificacion cancelada\n");
            }
        }
    }
}
