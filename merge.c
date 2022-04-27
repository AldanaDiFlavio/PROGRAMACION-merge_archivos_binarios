#include "merge.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int actualizarProductos(const char* nombreProductos, const char* nombreMovimientos)
{
    FILE* archProductos = fopen(nombreProductos, "rb");
    FILE* archMovimientos = fopen(nombreMovimientos, "rb");
    FILE* archivoTmp = fopen("Productos.tmp", "wb");

    if(archProductos == NULL || archMovimientos == NULL || archivoTmp == NULL)
    {
        printf("Error al abrir los archivos");
        return ERR_ARCHIVO;
    }

    Producto producto, movimiento, productoNuevo;
    int comp;

    fread(&producto, sizeof(Producto), 1, archProductos);
    fread(&movimiento, sizeof(Producto), 1, archMovimientos);

    while(!feof(archProductos) && !feof(archMovimientos))
    {
        comp = producto.codigo - movimiento.codigo;

        if(comp == 0)
        {
            producto.cantidad += movimiento.cantidad;
            fread(&movimiento, sizeof(Producto),1, archMovimientos);
        }
        else if(comp<0)
        {
            fwrite(&producto, sizeof(Producto),1,archivoTmp);
            fread(&producto, sizeof(Producto), 1, archProductos);
        }
        else
        {
            productoNuevo = movimiento;
            fread(&movimiento, sizeof(Producto),1,archMovimientos);

            while(!feof(archMovimientos) && productoNuevo.codigo == movimiento.codigo)
            {
                productoNuevo.cantidad += movimiento.cantidad;
                fread(&movimiento, sizeof(Producto),1,archMovimientos);
            }
         fwrite(&productoNuevo, sizeof(Producto),1,archivoTmp);

        }
    }

    while(!feof(archProductos))
    {
        fwrite(&producto, sizeof(Producto),1,archivoTmp);
        fread(&producto, sizeof(Producto),1,archProductos);
    }

    while(!feof(archMovimientos))
    {
        productoNuevo = movimiento;
        fread(&movimiento, sizeof(Producto),1,archMovimientos);

        while(!feof(archMovimientos) && productoNuevo.codigo == movimiento.codigo)
        {
            productoNuevo.cantidad += movimiento.cantidad;
            fread(&movimiento, sizeof(Producto),1,archMovimientos);
        }
        fwrite(&productoNuevo, sizeof(Producto),1,archivoTmp);
    }

    fclose(archProductos);
    fclose(archMovimientos);
    fclose(archivoTmp);

    remove(nombreProductos);
    rename("Productos.tmp", nombreProductos);

    return 0;
}

int mostrarProductos(const char* nomArchivo)
{
    FILE* archProds = fopen(nomArchivo, "rb");

    if(archProds == NULL)
    {
        printf("Error al abrir el archivo\n");
        return ERR_ARCHIVO;
    }

    Producto prod;
    fread(&prod, sizeof(Producto),1, archProds);

    while(!feof(archProds))
    {
        printf("%d %s %d %.2f\n", prod.codigo, prod.descripcion, prod.cantidad, prod.precio);
        fread(&prod, sizeof(Producto),1,archProds);
    }

    fclose(archProds);

    return TODO_OK;
}

int generarProductos(const char* nomArchivoProds)
{
    FILE* archProds = fopen(nomArchivoProds, "wb");

    if(archProds == NULL)
    {
        printf("Error al abrir el archivo\n");
        return ERR_ARCHIVO;
    }

    Producto prod;

    prod.codigo = 1;
    strcpy(prod.descripcion, "Leche");
    prod.cantidad = 10;
    prod.precio = 2.5;
    fwrite(&prod, sizeof(Producto),1, archProds);

    prod.codigo = 2;
    strcpy(prod.descripcion, "Pan");
    prod.cantidad = 20;
    prod.precio = 1.5;
    fwrite(&prod, sizeof(Producto),1, archProds);

    prod.codigo = 3;
    strcpy(prod.descripcion, "Arroz");
    prod.cantidad = 30;
    prod.precio = 3.5;
    fwrite(&prod, sizeof(Producto),1, archProds);
    /*
    prod.codigo = 4;
    strcpy(prod.descripcion, "Aceite");
    prod.cantidad = 40;
    prod.precio = 4.5;
    fwrite(&prod, sizeof(Producto),1, archProds);
    */
    prod.codigo = 5;
    strcpy(prod.descripcion, "Sal");
    prod.cantidad = 50;
    prod.precio = 5.5;
    fwrite(&prod, sizeof(Producto),1, archProds);

    prod.codigo = 6;
    strcpy(prod.descripcion, "Azucar");
    prod.cantidad = 60;
    prod.precio = 6.5;
    fwrite(&prod, sizeof(Producto),1, archProds);

    fclose(archProds);

    return TODO_OK;
}

int generarMovimientos(const char* nomArchivoMovs)
{
    FILE* archMovs = fopen(nomArchivoMovs, "wb");

    if(archMovs == NULL)
    {
        printf("Error al abrir el archivo\n");
        return ERR_ARCHIVO;
    }

    Producto mov;

    mov.codigo = 1;
    strcpy(mov.descripcion, "Leche");
    mov.cantidad = 10;
    mov.precio = 2.5;
    fwrite(&mov, sizeof(Producto),1, archMovs);
    /*
    mov.codigo = 2;
    strcpy(mov.descripcion, "Pan");
    mov.cantidad = 20;
    mov.precio = 1.5;
    fwrite(&mov, sizeof(Producto),1, archMovs);
    */
    mov.codigo = 3;
    strcpy(mov.descripcion, "Arroz");
    mov.cantidad = 30;
    mov.precio = 3.5;
    fwrite(&mov, sizeof(Producto),1, archMovs);

    mov.codigo = 3;
    strcpy(mov.descripcion, "Arroz");
    mov.cantidad = 20;
    mov.precio = 3.5;
    fwrite(&mov, sizeof(Producto),1, archMovs);

    mov.codigo = 4;
    strcpy(mov.descripcion, "Aceite");
    mov.cantidad = 40;
    mov.precio = 4.5;
    fwrite(&mov, sizeof(Producto),1, archMovs);

    mov.codigo = 4;
    strcpy(mov.descripcion, "Aceite");
    mov.cantidad = 25;
    mov.precio = 4.5;
    fwrite(&mov, sizeof(Producto),1, archMovs);

    mov.codigo = 5;
    strcpy(mov.descripcion, "Sal");
    mov.cantidad = 50;
    mov.precio = 5.5;
    fwrite(&mov, sizeof(Producto),1, archMovs);

    mov.codigo = 7;
    strcpy(mov.descripcion, "Cafe");
    mov.cantidad = 60;
    mov.precio = 5.5;
    fwrite(&mov, sizeof(Producto),1, archMovs);

    mov.codigo = 7;
    strcpy(mov.descripcion, "Cafe");
    mov.cantidad = 30;
    mov.precio = 5.5;
    fwrite(&mov, sizeof(Producto),1, archMovs);

    fclose(archMovs);

    return TODO_OK;
}

/*int cambiarExtension(const char* nombreOrig, char* nombCambiado, const char* extension)
{
    strcpy(nombCambiado, nombreOrig);
    char* punto = strrchr(nombCambiado, '.');
    if(!punto)
        return ERR_PUNTO;

    strcpy(punto +1 , extension);
    return TODO_OK;
}

*/
