#ifndef AEROLINEA_H_INCLUDED
#define AEROLINEA_H_INCLUDED

typedef struct{
    int id;
    char descripcion[20];


}eAerolinea;

int cargarDescripcionAerolinea(eAerolinea aerolineas[], int tamAero, int idAero, char descripcion[]);
int mostrarAerolineas(eAerolinea aerolineas[], int tamAero);
#endif // AEROLINEA_H_INCLUDED
