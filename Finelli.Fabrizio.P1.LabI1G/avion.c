#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "inputs.h"
#include "avion.h"
#include "aerolinea.h"
#include "tipo.h"
#include "piloto.h"

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
    printf("10- Mostrar aviones de la misma aerolinea\n");
    printf("11- Mostrar aviones de un mismo tipo\n");
    printf("12- Mostrar porcentaje de aviones jet\n");
    printf("13- Mostrar todos los aviones por aerolinea\n");
    printf("14- Mostrar la aerolinea con mayor capacidad\n");
    printf("15- Mostrar la aerolinea con menor cantidad de aviones\n");
    printf("16- Salir\n");
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
    printf("3- Salir\n");
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

int altaAvion(eAvion lista[], int tamAv, eAerolinea aerolineas[], int tamAero, eTipo tipos[], int tamTipos, ePiloto pilotos[], int tamPil, int* pIdAv)
{
    int todoOk=0;
    int indice;
    eAvion auxAvion;
    if(lista!=NULL&&tamAv>0&&aerolineas!=NULL&&tamAero>0&&tipos!=NULL&&tamTipos>0&&pIdAv!=NULL&&pilotos!=NULL&&tamPil>0)
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

            if(!getEntero(&auxAvion.idAerolinea,1000,1004,3,"Ingrese id de la aerolinea: ","Error en la carga de la aerolinea\n\n"))
            {
                printf("Se excedio el limite de intentos\n\n");
            }
            printf("\n\n");
            mostrarTipos(tipos,tamTipos);

            if(!getEntero(&auxAvion.idTipo,5000,5003,3,"Ingrese id del tipo de avion: ","Error en la carga del tipo de avion\n\n"))
            {
                printf("Se excedio el limite de intentos\n\n");
            }
            printf("\n");

            mostrarPilotos(pilotos,tamPil);
            if(!getEntero(&auxAvion.idPiloto,3000,3009,3,"Ingrese id del piloto: ","Error, reingrese id del piloto:\n\n"))
            {
                printf("Se excedio el limite de intentos\n\n");
            }
            printf("\n");

            if(!getEntero(&auxAvion.capacidad,10,300,3,"Ingrese capacidad del avion: ","Error en la carga del tipo de avion\n\n"))
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

void mostrarAvion(eAvion unAvion, eAerolinea aerolineas[], int tamAero, eTipo tipos[], int tamTipos, ePiloto pilotos[], int tamPil)
{

    char descAerolinea[20];
    char descTipoAvion[20];
    char nombrePiloto[20];

    if((cargarDescripcionAerolinea(aerolineas,tamAero,unAvion.idAerolinea,descAerolinea))==1&&(cargarDescripcionTipo(tipos,tamTipos,unAvion.idTipo,descTipoAvion))==1&&(cargarDescripcionPiloto(pilotos,tamPil,unAvion.idPiloto,nombrePiloto))==1)
    {
        printf(" %d     %-10s     %-10s    %d       %10s\n"
           ,unAvion.id
           ,descAerolinea
           ,descTipoAvion
           ,unAvion.capacidad
           ,nombrePiloto);
    }
}

int mostrarAviones(eAvion lista[], int tamAv, eAerolinea aerolineas[], int tamAero, eTipo tipos[], int tamTipos, ePiloto pilotos[], int tamPil)
{
    int todoOk=0;
    int flag=1;


    if(lista!=NULL&&tamAv>0&&aerolineas!=NULL&&tamAero>0&&tipos!=NULL&&tamTipos>0&&pilotos!=NULL&&tamPil>0)
    {
        system("cls");
        printf("     *****  Lista de Aviones  *****\n");
        printf("-----------------------------------------------------------------\n");
        printf(" ID      Aerolinea       Tipo       Capacidad    Piloto  \n");
        printf("-----------------------------------------------------------------\n");
        for(int i=0;i<tamAv;i++)
        {
            if(!lista[i].isEmpty)
            {
                mostrarAvion(lista[i],aerolineas,tamAero,tipos,tamTipos,pilotos,tamPil);
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

int bajaAvion(eAvion lista[], int tamAv, eAerolinea aerolineas[], int tamAero, eTipo tipos[], int tamTipos, ePiloto pilotos[], int tamPil)
{
    int todoOk=0;
    int indice;
    int id;
    char confirma;

    if(lista!=NULL&&tamAv>0&&aerolineas!=NULL&&tamAero>0&&tipos!=NULL&&tamTipos>0&&pilotos!=NULL&&tamPil>0)
    {
        system("cls");
        printf("   ***Baja avion**** \n\n");
        mostrarAviones(lista,tamAv,aerolineas,tamAero,tipos,tamTipos,pilotos,tamPil);
        if(!getEntero(&id,100,149,3,"Ingrese id del avion a dar de baja: ","Error, reingrese id: \n\n"))
        {
            printf("Se excedio el limite de intentos\n\n");
        }

        indice=buscarAvionId(lista,tamAv,id); //llamo a la funcion buscar por id, y al indice encontrado en la lista de personas analizada por la fx, lo asigno a la variable indice de este scope
        if(indice==-1)
        {
            printf("El id: %d no existe en el sistema\n",id);

        }else
        {
            mostrarAvion(lista[indice],aerolineas,tamAero,tipos,tamTipos,pilotos,tamPil);
            printf("\n¿Confirma baja?: ");
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

int modificarAvion(eAvion lista[], int tamAv, eAerolinea aerolineas[], int tamAero, eTipo tipos[], int tamTipos, ePiloto pilotos[], int tamPil)
{
    int todoOk=0;
    int indice;
    int id;
    char confirma;
    char salirMenu;
    eAvion auxAvion;

    if(lista!=NULL&&tamAv>0&&aerolineas!=NULL&&tamAero>0&&tipos!=NULL&&tamTipos>0&&pilotos!=NULL&&tamPil>0)
    {
        system("cls");
        printf("   ***Modificar avion**** \n\n");
        mostrarAviones(lista,tamAv,aerolineas,tamAero,tipos,tamTipos,pilotos,tamPil);
        printf("\n\n");
        if(!getEntero(&id,100,149,3,"Ingrese id del avion a modificar: ","Error, reingrese id: \n\n"))
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
            mostrarAvion(lista[indice],aerolineas,tamAero,tipos,tamTipos,pilotos,tamPil);
            printf("\n");
            //submenu
            printf("¿Confirma modificacion? 's' para si, 'n' para no: ");
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
                        }else
                        {
                            lista[indice].idTipo=auxAvion.idTipo;
                        }
                        break;
                    case 2:
                        if(!getEntero(&auxAvion.capacidad,10,300,3,"Ingrese nueva capacidad del avion: ","Capacidad incorrecta\n\n"))
                        {
                            printf("Se excedio el limite de intentos\n\n");
                        }else
                        {
                            lista[indice].capacidad=auxAvion.capacidad;
                        }
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
                    todoOk=1;
                }while(salirMenu!='s');
            }
        }
    }

    return todoOk;
}

int buscarTipoYAerolineaAvion(eAvion lista[], int tamAv, int id, int* idAero, int* idTipo, int* idPiloto)
{
    int todoOk=0;
    if(lista!=NULL&&tamAv>0)
    {
        for(int i=0;i<tamAv;i++)
        {
            if(lista[i].id==id)
            {
                *idAero=lista[i].idAerolinea;
                *idTipo=lista[i].idTipo;
                *idPiloto=lista[i].idPiloto;
                todoOk=1;
            }
        }
    }

    return todoOk;
}

int ordenarAviones(eAvion lista[], int tamAv)
{
    int todoOk=0;
    eAvion auxAvion;
    if(lista!=NULL&&tamAv>0)
    {
        for(int i=0;i<tamAv-1;i++)
        {
                for(int j=i+1;j<tamAv; j++)
                {
                    if((lista[i].idAerolinea<lista[j].idAerolinea)||
                        (lista[i].idAerolinea==lista[j].idAerolinea && lista[i].capacidad<lista[j].capacidad))
                    {
                        auxAvion=lista[i];
                        lista[i]=lista[j];
                        lista[j]=auxAvion;
                    }
                }
            }
        todoOk = 1;

    }
    return todoOk;

}

int mostrarAvionesMismaAerolinea(eAvion lista[], int tamAv, eAerolinea aerolineas[], int tamAero, eTipo tipos[], int tamTipos, ePiloto pilotos[], int tamPil)
{
    int todoOk=0;
    int idAerolinea;
    if(lista!=NULL&&tamAv>0&&aerolineas!=NULL&&tamAero>0&&tipos!=NULL&&tamTipos>0&&pilotos!=NULL&&tamPil>0)
    {
        system("cls");
        printf("     *****  Aviones de una misma aerolinea  *****\n");
        printf("----------------------------------------------------------\n\n");
        mostrarAerolineas(aerolineas,tamAero);
        if(!getEntero(&idAerolinea,1000,1004,3,"Ingrese id de la aerolinea: ","Error reingrese id de la aerolinea: \n\n"))
        {
            printf("Se ha excedido el limite de intentos\n");
        }
        printf("-----------------------------------------------------------------\n");
        printf(" ID      Aerolinea       Tipo       Capacidad    Piloto  \n");
        printf("-----------------------------------------------------------------\n");

        mostrarAvionesIdAerolinea(lista,tamAv,aerolineas,tamAero,tipos,tamTipos,pilotos,tamPil,idAerolinea);
        todoOk=1;
    }

    return todoOk;
}

int mostrarAvionesIdAerolinea(eAvion lista[], int tamAv, eAerolinea aerolineas[], int tamAero, eTipo tipos[], int tamTipos, ePiloto pilotos[], int tamPil, int idAerolinea)
{
    int todoOk=0;
    char descAerolinea[20];
    int flag=1;
    if(lista!=NULL&&tamAv>0&&aerolineas!=NULL&&tamAero>0&&tipos!=NULL&&tamTipos>0&&pilotos!=NULL&&tamPil>0)
    {
        for(int i=0;i<tamAv;i++)
        {
            if(!lista[i].isEmpty&&lista[i].idAerolinea==idAerolinea)
            {
                mostrarAvion(lista[i],aerolineas,tamAero,tipos,tamTipos,pilotos,tamPil);
                flag=0;
            }
        }
        if(flag)
        {
            cargarDescripcionAerolinea(aerolineas,tamAero,idAerolinea,descAerolinea);
            printf("No hay aviones cargados de %s\n",descAerolinea);
        }
       todoOk=1;
    }


}

int mostrarAvionesMismoTipo(eAvion lista[], int tamAv, eAerolinea aerolineas[], int tamAero, eTipo tipos[], int tamTipos, ePiloto pilotos[], int tamPil)
{
    int todoOk=0;
    int idTipo;
    char descTipo[20];
    int flag=1;
    if(lista!=NULL&&tamAv>0&&aerolineas!=NULL&&tamAero>0&&tipos!=NULL&&tamTipos>0&&pilotos!=NULL&&tamPil>0)
    {
        system("cls");
        printf("     *****  Aviones de un mismo tipo  *****\n");
        printf("----------------------------------------------------------\n\n");
        mostrarTipos(tipos,tamTipos);
        if(!getEntero(&idTipo,5000,5003,3,"Ingrese id del tipo de avion: ","Error reingrese id del tipo de avion: \n\n"))
        {
            printf("Se ha excedido el limite de intentos\n");
        }
        printf("-----------------------------------------------------------------\n");
        printf(" ID      Aerolinea       Tipo       Capacidad    Piloto  \n");
        printf("-----------------------------------------------------------------\n");

        for(int i=0;i<tamAv;i++)
        {
            if(!lista[i].isEmpty&&lista[i].idTipo==idTipo)
            {
                mostrarAvion(lista[i],aerolineas,tamAero,tipos,tamTipos,pilotos,tamPil);
                flag=0;
            }
        }
        if(flag)
        {
            cargarDescripcionTipo(tipos,tamTipos,idTipo,descTipo);
            printf("No hay aviones del tipo %s cargados\n",descTipo);
        }
        todoOk=1;
    }

    return todoOk;
}

int mostrarTodosLosAvionesPorAerolinea(eAvion lista[], int tamAv, eAerolinea aerolineas[], int tamAero, eTipo tipos[], int tamTipos, ePiloto pilotos[], int tamPil)
{
    int todoOk=0;
    char descAerolinea[20];
    if(lista!=NULL&&tamAv>0&&aerolineas!=NULL&&tamAero>0&&tipos!=NULL&&tamTipos>0&&pilotos!=NULL&&tamPil>0)
    {
        system("cls");
        printf("******Aviones por aerolinea******\n\n");
        printf("--------------------------------------\n");
        for(int i=0;i<tamAero;i++)
        {
            printf("Aerolinea: %s\n\n",aerolineas[i].descripcion);
            printf("-----------------------------------------------------------------\n");
            printf(" ID      Aerolinea       Tipo       Capacidad    Piloto  \n");
            printf("-----------------------------------------------------------------\n");
            mostrarAvionesIdAerolinea(lista,tamAv,aerolineas,tamAero,tipos,tamTipos,pilotos,tamPil,aerolineas[i].id);
            printf("\n\n");

        }
        todoOk=1;
    }

    return todoOk;

}



int mostrarAerolineasMasOcupadas(eAvion lista[], int tamAv, eAerolinea aerolineas[], int tamAero, eTipo tipos[], int tamTipos, ePiloto pilotos[], int tamPil)
{
    int todoOk=0;
    int acumuladores[]={0,0,0,0,0};
    int aerolineaMayorCapacidad=0;
    if(lista!=NULL&&tamAv>0&&aerolineas!=NULL&&tamAero>0&&tipos!=NULL&&tamTipos>0&&pilotos!=NULL&&tamPil>0)
    {
        system("cls");
        printf("  ******Aerolinea mas ocupada******  \n");
        printf("-----------------------------------------\n");
        for(int i=0;i<tamAv;i++)
        {
            for(int j=0; j<tamAero;j++)
            {
                if(!lista[j].isEmpty&&lista[j].idAerolinea==aerolineas[i].id)
                {
                    acumuladores[j]=lista[i].capacidad+acumuladores[j];
                }
            }
        }
        //ya se la cantidad de habitantes
        //-
        //busco el minimo
        for(int i=0;i<tamAero;i++)
        {
            if(i==0||acumuladores[i]<aerolineaMayorCapacidad)
            {
                aerolineaMayorCapacidad=acumuladores[i];
            }
        }
        for(int i=0;i<tamAero;i++)
        {
            if(acumuladores[i]==aerolineaMayorCapacidad)
            {
                printf("%s es la de mayor capacidad \n",aerolineas[i].descripcion);
            }
        }

        todoOk=1;
    }
    return todoOk;

}

int mostrarAerolineaMenorCantidadAviones(eAvion lista[], int tamAv, eAerolinea aerolineas[], int tamAero, eTipo tipos[], int tamTipos, ePiloto pilotos[], int tamPil)
{
    int todoOk=0;
    int contadores[]={0,0,0,0,0};
    int aerolineaMenorCantidadAviones=0;
    if(lista!=NULL&&tamAv>0&&aerolineas!=NULL&&tamAero>0&&tipos!=NULL&&tamTipos>0&&pilotos!=NULL&&tamPil>0)
    {
        system("cls");
        printf("  ******Aerolinea con menos aviones******  \n\n");
        for(int i=0;i<tamAero;i++)
        {
            for(int j=0; j<tamAv;j++)
            {
                if(!lista[j].isEmpty&&lista[j].idAerolinea==aerolineas[i].id)
                {
                    contadores[i]++;
                }
            }
        }
        //ya se la cantidad de habitantes
        //-
        //busco el minimo
        for(int i=0;i<tamAero;i++)
        {
            if(i==0||contadores[i]<aerolineaMenorCantidadAviones)
            {
                aerolineaMenorCantidadAviones=contadores[i];
            }
        }
        for(int i=0;i<tamAero;i++)
        {
            if(contadores[i]==aerolineaMenorCantidadAviones)
            {
                printf("%s\n",aerolineas[i].descripcion);
            }
        }

        todoOk=1;
    }
    return todoOk;
}

/*int mostrarVuelosDeUnAvion(eAvion lista[], int tamAv, eAerolinea aerolineas[], int tamAero, eTipo tipos[], int tamTipos, ePiloto pilotos[], int tamPil, eVuelo vuelos[], int tamVuelos, eDestino destinos[], int tamDest)
{
    int todoOk=0;
    int idAvion;
    int flag=0;
    if(lista!=NULL&&tamAv>0&&aerolineas!=NULL&&tamAero>0&&tipos!=NULL&&tamTipos>0&&pilotos!=NULL&&tamPil>0&&vuelos!=NULL&&tamVuelos>0&&destinos!=NULL&&tamDest>0)
    {
        system("cls");
        printf("*** Vuelos realizados por el mismo avion ****\n\n");
        mostrarAviones(lista,tamAv,aerolineas,tamAero,tipos,tamTipos,pilotos,tamPil);
        printf("\n");

        if(!getEntero(&idAvion,100,149,3,"Ingrese id del avion: ","Error reingrese id del avion: \n\n"))
        {
            printf("Se ha excedido el limite de intentos\n");
        }

        printf("       **** Vuelos realizados por el avion  *****\n");
        printf("-------------------------------------------------------------------------\n");
        printf("  ID  Avion   Aerolinea     Destino    Fecha        Precio    Piloto\n");
        printf("-------------------------------------------------------------------------\n");

        for(int i=0;i<tamTipos;i++)
        {
            if(!vuelos[i].isEmpty&&vuelos[i].idAvion==idAvion)
            {
                mostrarVuelo(vuelos[i],lista,tamAv,destinos,tamDest,tipos,tamTipos,aerolineas,tamAero,pilotos,tamPil,idAvion);
                flag=1;
            }
            if(!flag)
            {
                printf("El avion ingresado no tiene vuelos\n");
            }
        }
        todoOk=0;
    }


}
*/

/*int calcularPorcentajeDeAvionesJet(eAvion lista[], int tamAv, eAerolinea aerolineas[], int tamAero, eTipo tipos[], int tamTipos, ePiloto pilotos[], int tamPil)
{
    int todoOk=0;
    int idAerolinea;
    int flag=0;
    int contadorJet=0;
    int acumuladorJet=0;
    float porcentajeJet=0;
    char desc[20];
    if(lista!=NULL&&tamAv>0&&aerolineas!=NULL&&tamAero>0&&tipos!=NULL&&tamTipos>0&&pilotos!=NULL&&tamPil>0)
    {
        system("cls");

        for(int i=0;i<tamAv;i++)
        {
            if(!lista[i].isEmpty && lista[i].idTipo==idLocalidad)
            {
                acumAlturas=lista[i].altura+acumAlturas;
                contador++;
            }
        }
        cargarDescripcionLocalidad(localidades,tamLoc,idLocalidad,descLocalidad);
        if(contador)
        {
            promedio=acumAlturas/contador;
            printf("Promedio altura en %s : %.2f\n",descLocalidad,promedio);
        }else
        {
            cargarDescripcionLocalidad(localidades,tamLoc,idLocalidad,descLocalidad);
            printf("No hay personas en %s\n",descLocalidad);
        }
        todoOk=1;
    }
    return todoOk;

}*/
