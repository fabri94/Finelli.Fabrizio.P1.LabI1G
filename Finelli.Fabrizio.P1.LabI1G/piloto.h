#ifndef PILOTO_H_INCLUDED
#define PILOTO_H_INCLUDED
typedef struct{
    int id;
    char nombre[20];
    char sexo;

}ePiloto;

int cargarDescripcionPiloto(ePiloto pilotos[], int tamPil, int idPil, char nombre[]);
int mostrarPilotos(ePiloto pilotos[], int tamPil);

#endif // PILOTO_H_INCLUDED
