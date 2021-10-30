#include "fecha.h"
#include "avion.h"
#include "destino.h"
#include "piloto.h"
#ifndef VUELO_H_INCLUDED
#define VUELO_H_INCLUDED

typedef struct{
    int id;
    int idAvion;
    int idDestino;
    eFecha fecha;
    int isEmpty;

}eVuelo;

int inicializarVuelos(eVuelo vuelos[], int tamVue);
int buscarLibreVuelo(eVuelo vuelos[], int tamVue);
void mostrarVuelo(eVuelo unVuelo, eAvion lista[], int tamAv, eDestino destinos[], int tamDest, eTipo tipos[], int tamTipos, eAerolinea aerolineas[], int tamAero, ePiloto pilotos[], int tamPil, int idAv);
int mostrarVuelos(eVuelo vuelos[], int tamVue, eAvion lista[], int tamAv, eDestino destinos[], int tamDest, eTipo tipos[], int tamTipos, eAerolinea aerolineas[], int tamAero, ePiloto pilotos[], int tamPil);
int altaVuelos(eVuelo vuelos[], int tamVue, eAvion lista[], int tamAv, eDestino destinos[], int tamDest, eTipo tipos[], int tamTipos, eAerolinea aerolineas[], int tamAero, ePiloto pilotos[], int tamPil, int* pIdVue);



#endif // VUELO_H_INCLUDED
