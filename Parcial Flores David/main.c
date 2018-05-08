#include <stdio.h>
#include <stdlib.h>
#include "funciones.c"
#include "proveedores.h"
#include "menu.c"
#define TAM 10

int main()
{
    eProveedor proveedores[] = {{1, "David"},{2, "Jose"}, {3, "Micaela"}, {4, "Carolina"}};
    eProducto productos[TAM];

    inicializarProductos(productos);
    int opcion;

    opcion = menu();

    while (opcion != 0)
    {
        switch (opcion)
        {
            case 1:
                ingresarProducto(productos);
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
                break;
        }
        opcion = menu();
    }
}

