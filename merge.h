#ifndef MERGE_H_INCLUDED
#define MERGE_H_INCLUDED



#define PARAM_PROD 1
#define PARAM_MOV 2
#define ERR_ARCHIVO 1
#define TODO_OK 0

typedef struct {
    int codigo;
    char descripcion[51];
    int cantidad;
    float precio;
}
Producto;

int actualizarProductos(const char* nombreProductos, const char* nombreMovimientos);
int mostrarProductos(const char* nomArchivo);
int generarProductos(const char* nomArchivoProds);
int generarMovimientos(const char* nomArchivoProds);
int cambiarExtension(const char* nombreOrig, char* nombCambiado, const char* extension);



#endif // MERGE_H_INCLUDED
