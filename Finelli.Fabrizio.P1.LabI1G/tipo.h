#ifndef TIPO_H_INCLUDED
#define TIPO_H_INCLUDED

typedef struct{
    int id;
    char descripcion[20];


}eTipo;

int cargarDescripcionTipo(eTipo tipos[], int tamTipos, int idTipo, char descripcion[]);
int mostrarTipos(eTipo tipos[], int tamTipos);

#endif // TIPO_H_INCLUDED
