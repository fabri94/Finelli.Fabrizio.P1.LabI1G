#ifndef DESTINO_H_INCLUDED
#define DESTINO_H_INCLUDED

typedef struct{
    int id;
    char descripcion[20];
    int precio;

}eDestino;

int mostrarDestinos(eDestino destinos[], int tamDest);
int cargarDescripcionDestinos(eDestino destinos[], int tamDest, int idDestino, char descripcion[], int* precio);

#endif // DESTINO_H_INCLUDED
