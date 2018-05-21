#include <stdio.h>
#include <stdlib.h>
#include "funciones.c"
#include "proveedores.h"
#include "menu.c"

int main()
{
    eProveedor proveedores[] = {{1, "David"}, {2, "Jose"}, {3, "Micaela"}, {4, "Matias"}};
    eProducto productos[TAM];

    int opcion;
    char sOpcion[1];
    int esNumero;
    char seguir = 's';

    inicializarProductos(productos);

    while(seguir == 's')
    {
        opcion = menu();
        switch (opcion)
        {
            case 1:
                ingresarProducto(productos, proveedores, 4);
                break;
            case 2:
                modificarProducto(productos);
                break;
            case 3:
                eliminarProducto(productos);
                break;
            case 4:
                informar(productos);
                break;
            case 5:
                listar(productos);
                listarConProveedores(productos, proveedores, 4);
                break;
            case 6:
                seguir = 'n';
                break;
        opcion = menu();
        }
    }
}

