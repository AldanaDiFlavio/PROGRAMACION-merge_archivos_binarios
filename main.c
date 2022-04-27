#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "merge.h"

//PARA QUE FUNCIONE HAY QUE CARGAR LOS NOMBRE DE LOS ARCHIVOS
//HAY QUE IR A:
//PROJECT -> SET PROGRAMS' ARGUMENTS
//Y ESCRIBIR EN PROGRAM ARGUMENTS:
//Productos.dat Movimientos.dat (dejar espacio entre cada nombre)

int main(int argc, char* argv[])
{
    generarProductos(argv[PARAM_PROD]);
    generarMovimientos(argv[PARAM_MOV]);

    puts("**Productos*******************\n");
    mostrarProductos(argv[PARAM_PROD]);

    puts("\n\n**Movimientos*******************\n");
    mostrarProductos(argv[PARAM_MOV]);

    actualizarProductos(argv[PARAM_PROD], argv[PARAM_MOV]);

    puts("\n\n**Productos actualizados*******************\n");
    mostrarProductos(argv[PARAM_PROD]);

    return 0;
}

