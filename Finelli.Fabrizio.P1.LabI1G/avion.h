#ifndef AVION_H_INCLUDED
#define AVION_H_INCLUDED

#include "aerolinea.h"
#include "tipo.h"

#include "piloto.h"

typedef struct{
    int id;
    int idAerolinea;
    int idTipo;
    int idPiloto;
    int capacidad;
    int isEmpty; //1 cuando esta vacio, 0 cuando esta ocupado
}eAvion;

int menu();
int menuModificacion();
int inicializarAviones(eAvion lista[], int tamAv);
int buscarLibreAvion(eAvion lista[], int tamAv);
int altaAvion(eAvion lista[], int tamAv, eAerolinea aerolineas[], int tamAero, eTipo tipos[], int tamTipos, ePiloto pilotos[], int tamPil, int* pIdAv);
void mostrarAvion(eAvion unAvion, eAerolinea aerolineas[], int tamAero, eTipo tipos[], int tamTipos, ePiloto pilotos[], int tamPil);
int mostrarAviones(eAvion lista[], int tamAv, eAerolinea aerolineas[], int tamAero, eTipo tipos[], int tamTipos, ePiloto pilotos[], int tamPil);
int bajaAvion(eAvion lista[], int tamAv, eAerolinea aerolineas[], int tamAero, eTipo tipos[], int tamTipos, ePiloto pilotos[], int tamPil);
int buscarAvionId(eAvion lista[], int tamAv, int id);
int modificarAvion(eAvion lista[], int tamAv, eAerolinea aerolineas[], int tamAero, eTipo tipos[], int tamTipos, ePiloto pilotos[], int tamPil);
int buscarTipoYAerolineaAvion(eAvion lista[], int tamAv, int id, int* idAero, int* idTipo, int* idPiloto);
int ordenarAviones(eAvion lista[], int tamAv);

//INFORMES
int mostrarAvionesMismaAerolinea(eAvion lista[], int tamAv, eAerolinea aerolineas[], int tamAero, eTipo tipos[], int tamTipos, ePiloto pilotos[], int tamPil);
int mostrarAvionesIdAerolinea(eAvion lista[], int tamAv, eAerolinea aerolineas[], int tamAero, eTipo tipos[], int tamTipos, ePiloto pilotos[], int tamPil, int idAerolinea);
int mostrarAvionesMismoTipo(eAvion lista[], int tamAv, eAerolinea aerolineas[], int tamAero, eTipo tipos[], int tamTipos, ePiloto pilotos[], int tamPil);
int mostrarTodosLosAvionesPorAerolinea(eAvion lista[], int tamAv, eAerolinea aerolineas[], int tamAero, eTipo tipos[], int tamTipos, ePiloto pilotos[], int tamPil);
int calcularPorcentajeDeAvionesJet(eAvion lista[], int tamAv, eAerolinea aerolineas[], int tamAero, eTipo tipos[], int tamTipos, ePiloto pilotos[], int tamPil);
int mostrarAerolineasMasOcupadas(eAvion lista[], int tamAv, eAerolinea aerolineas[], int tamAero, eTipo tipos[], int tamTipos, ePiloto pilotos[], int tamPil);
int mostrarAerolineaMenorCantidadAviones(eAvion lista[], int tamAv, eAerolinea aerolineas[], int tamAero, eTipo tipos[], int tamTipos, ePiloto pilotos[], int tamPil);
//int mostrarVuelosDeUnAvion(eAvion lista[], int tamAv, eAerolinea aerolineas[], int tamAero, eTipo tipos[], int tamTipos, ePiloto pilotos[], int tamPil, eVuelo vuelos[], int tamVuelos, eDestino destinos[], int tamDest);

//int mostrarAvionesDeUnaAerolinea(eAvion lista[], int tamAv, eAerolinea aerolineas[], int tamAero, eTipo tipos[], int tamTipos)
#endif // AVION_H_INCLUDED
