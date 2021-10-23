#ifndef AVION_H_INCLUDED
#define AVION_H_INCLUDED

#include "aerolinea.h"
#include "tipo.h"

typedef struct{
    int id;
    int idAerolinea;
    int idTipo;
    int capacidad;
    int isEmpty; //1 cuando esta vacio, 0 cuando esta ocupado
}eAvion;

int menu();
int menuModificacion();
int inicializarAviones(eAvion lista[], int tamAv);
int buscarLibreAvion(eAvion lista[], int tamAv);
int altaAvion(eAvion lista[], int tamAv, eAerolinea aerolineas[], int tamAero, eTipo tipos[], int tamTipos, int* pIdAv);
void mostrarAvion(eAvion unAvion, eAerolinea aerolineas[], int tamAero, eTipo tipos[], int tamTipos);
int mostrarAviones(eAvion lista[], int tamAv, eAerolinea aerolineas[], int tamAero, eTipo tipos[], int tamTipos);
int bajaAvion(eAvion lista[], int tamAv, eAerolinea aerolineas[], int tamAero, eTipo tipos[], int tamTipos);
int buscarAvionId(eAvion lista[], int tamAv, int id);
int modificarAvion(eAvion lista[], int tamAv, eAerolinea aerolineas[], int tamAero, eTipo tipos[], int tamTipos);

#endif // AVION_H_INCLUDED
