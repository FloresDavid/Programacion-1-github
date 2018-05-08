#include <stdio.h>
#include <stdlib.h>
#define TAM 10

typedef struct
{
    int codProducto;
    char descripcion[50];
    int importe;
    int cantidad;
    int codProveedor;
    int flagProd;

}eProducto;

void inicializarProductos(eProducto produc[])
{
    for(int i = 0; i < TAM; i++)
    {
        produc[i].flagProd = 1;
    }
}

void ingresarProducto(eProducto produc[])
{
    eProducto nuevoProducto;
    char sImporte[10];
    char sCantidad[10];
    char sCodigoProv[2];


    printf ("Ingrese la descripcion del producto. \n\n");
    scanf("%s", nuevoProducto.descripcion);

    printf("Ingrese el importe.\n\n");
    scanf("%s", sImporte);
    nuevoProducto.importe = atoi(sImporte);

    while (nuevoProducto.importe < 1)
    {
        printf("Error, reingrese el importe.\n\n");
        scanf("%s", sImporte);
        nuevoProducto.importe = atoi(sImporte);
    }

    printf("Ingrese la cantidad.\n\n");
    scanf("%s", sCantidad);
    nuevoProducto.cantidad = atoi(sCantidad);

    while (nuevoProducto.cantidad < 1)
    {
        printf("Error, reingrese la cantidad.\n\n");
        scanf("%s", sCantidad);
        nuevoProducto.cantidad = atoi(sCantidad);
    }

    printf("Ingrese el codigo del proveedor correspondiente.\n\n");
    scanf("%s", sCodigoProv);
    nuevoProducto.codProveedor = atoi(sCodigoProv);

    while (nuevoProducto.codProveedor < 1)
    {
        printf("Error, reingrese el codigo del proveedor correspondiente.\n\n");
        scanf("%s", sCodigoProv);
        nuevoProducto.codProveedor = atoi(sCodigoProv);
    }
    nuevoProducto.flagProd = 0;
    for (int i = 0; i < TAM; i++)
    {
        if (produc[i].flagProd == 1)
        {
            nuevoProducto.codProducto = i + 1;
            produc[i] = nuevoProducto;
            break;
        }
    }
}

void eliminarProducto(eProducto prod[])
{
    char sCodProducto[2];
    int codProducto;

    printf("Ingrese el codigo del producto a eliminar. \n");
    scanf("%s", sCodProducto);
    codProducto = atoi(sCodProducto);

    while (codProducto < 1)
    {
        printf("Error, reingrese el codigo del producto a eliminar. \n");
        scanf("%s", sCodProducto);
        codProducto = atoi(sCodProducto);
    }

    for (int i = 0; i < TAM; i++)
    {
        if (prod[i].flagProd == 0 && prod[i].codProducto == codProducto)
        {
            prod[i].flagProd = 1;
            printf("Baja exitosa!\n");
            break;
        }
    }
}

void modificarProducto(eProducto prod[])
{
    char sCodProducto[2];
    int codProducto;
    char sOpcion[1];
    int opcion = -1;
    int indice;
    char sImporte[10];
    char sCantidad [10];
    char sCodigoProv[2];

    printf("Ingrese el codigo del producto a modificar. \n");
    scanf("%s", sCodProducto);
    codProducto = atoi(sCodProducto);

    while (codProducto < 1)
    {
        printf("Error, reingrese el codigo del producto a modificar. \n");
        scanf("%s", sCodProducto);
        codProducto = atoi(sCodProducto);
    }

    for (int i = 0; i < TAM; i++)
    {
        if (prod[i].flagProd == 0 && prod[i].codProducto == codProducto)
        {
            indice = i;
        }
    }
    while (opcion < 0)
    {
        printf("\nIngrese la opcion que quiera utilizar.\n");
        printf("1) Modificar Descripcion.\n");
        printf("2) Modificar Importe.\n");
        printf("3) Modificar Cantidad.\n");
        printf("4) Modificar codigo de proveedor.\n");
        printf("5) Salir.\n");

        scanf("%s", sOpcion);
        opcion = atoi(sOpcion);

        while (opcion < 1)
        {
            printf("Error, reingrese la opcion.\n\n");
            scanf("%s", sOpcion);
            opcion = atoi(sOpcion);
        }

        switch (opcion)
        {
            case 1:
                printf ("Ingrese la descripcion del producto. \n\n");
                fflush(prod[indice].descripcion);
                scanf("%s", prod[indice].descripcion);
                break;

            case 2:
                printf("Ingrese el importe.\n\n");
                scanf("%s", sImporte);
                prod[indice].importe = atoi(sImporte);

                while (prod[indice].importe < 1)
                {
                    printf("Error, reingrese el importe.\n\n");
                    scanf("%s", sImporte);
                    prod[indice].importe = atoi(sImporte);
                }
                break;

            case 3:
                printf("Ingrese la cantidad.\n\n");
                scanf("%s", sCantidad);
                prod[indice].cantidad = atoi(sCantidad);

                while (prod[indice].cantidad < 1)
                {
                    printf("Error, reingrese la cantidad.\n\n");
                    scanf("%s", sCantidad);
                    prod[indice].cantidad = atoi(sCantidad);
                }
                break;

            case 4:
                printf("Ingrese el codigo del proveedor correspondiente.\n\n");
                scanf("%s", sCodigoProv);
                prod[indice].codProveedor = atoi(sCodigoProv);

                while (prod[indice].codProveedor < 1)
                {
                    printf("Error, reingrese el codigo del proveedor correspondiente.\n\n");
                    scanf("%s", sCodigoProv);
                    prod[indice].codProveedor = atoi(sCodigoProv);
                }
                break;
            case 5:
                opcion = 0;
                break;
            default:
                printf("Opcion incorrecta!!  \n\n");
        }
    }
}

void informar(eProducto produc[])
{
    int totalImportes = 0;
    int cantidadImportes = 0;
    float promedioImportes = 0;
    int cantidadImportesSuperiores = 0;
    int cantidadImportesInferiores = 0;
    int cantidadProductosMenoresOIgualesADiez = 0;
    int cantidadProductosMayoresADiez = 0;


    for (int i = 0; i < TAM; i++)
    {
        if (produc[i].flagProd == 0)
        {
            totalImportes += produc[i].importe;
            cantidadImportes++;
        }
    }

    promedioImportes = (float) totalImportes / cantidadImportes;

    for (int i = 0; i < TAM; i++)
    {
        if (produc[i].flagProd == 0)
        {
            if(produc[i].importe > promedioImportes)
            {
                cantidadImportesSuperiores++;
            }
            else
            {
                cantidadImportesInferiores++;
            }
        }
    }

    for (int i = 0; i < TAM; i++)
    {
        if (produc[i].flagProd == 0)
        {
            if(produc[i].cantidad > 10)
            {
                cantidadProductosMayoresADiez++;
            }
            else
            {
                cantidadProductosMenoresOIgualesADiez++;
            }
        }
    }

    printf("----------Total de importes.----------\n");
    printf("%d\n\n", totalImportes);
    printf("----------Promedio de importes.----------\n");
    printf("%.02f\n\n", promedioImportes);
    printf("----------Cantidad de importes que superan el promedio.----------\n");
    printf("%d\n\n", cantidadImportesSuperiores);
    printf("----------Cantidad de importes que no superan el promedio.----------\n");
    printf("%d\n\n", cantidadImportesInferiores);
    printf("----------Cantidad de productos cuyo stock es menor o igual a 10.----------\n");
    printf("%d\n\n", cantidadProductosMenoresOIgualesADiez);
    printf("----------Cantidad de productos cuyo stock es menor o igual a 10.----------\n");
    printf("%d\n\n", cantidadProductosMayoresADiez);




}
void listar(eProducto produc[])
{
    eProducto auxProduc;
    int totalImportes = 0;
    int cantidadImportes = 0;
    float promedioImportes;

    for (int i = 0; i < TAM; i++)
    {
        if (produc[i].flagProd == 0)
        {
            totalImportes += produc[i].importe;
            cantidadImportes++;
        }
    }

    promedioImportes = (float) totalImportes / cantidadImportes;


    printf("-----Listado de todos los productos.-----\n");

    for (int i = 0; i < TAM; i++)
    {
        for (int j = i+1; j < TAM+1; j++)
        {
            if (produc[i].importe < produc[j].importe)
            {
                auxProduc = produc[i];
                produc[i] = produc[j];
                produc[j] = auxProduc;
            }
        }
        if (produc[i].flagProd == 0)
        {
            printf("%d  %s  %d  %d  %d\n", produc[i].codProducto, produc[i].descripcion, produc[i].importe, produc[i].cantidad, produc[i].codProveedor);
        }
    }

    printf("-----Listado de todos los productos menores o iguales a 10.-----\n");

    for (int i = 0; i < TAM; i++)
    {
        if (produc[i].flagProd == 0 && produc[i].cantidad <= 10)
        {
            printf("%d  %s  %d  %d  %d\n", produc[i].codProducto, produc[i].descripcion, produc[i].importe, produc[i].cantidad, produc[i].codProveedor);
        }
    }

    printf("-----Listado de los productos mayores a 10.-----\n");

    for (int i = 0; i < TAM; i++)
    {
        if (produc[i].flagProd == 0 && produc[i].cantidad > 10)
        {
            printf("%d  %s  %d  %d  %d\n", produc[i].codProducto, produc[i].descripcion, produc[i].importe, produc[i].cantidad, produc[i].codProveedor);
        }
    }
    printf("-----Listado de los productos que superan el promedio de los importes.-----\n");

    for (int i = 0; i < TAM; i++)
    {
        if (produc[i].flagProd == 0 && produc[i].importe > promedioImportes)
        {
            printf("%d  %s  %d  %d  %d\n", produc[i].codProducto, produc[i].descripcion, produc[i].importe, produc[i].cantidad, produc[i].codProveedor);
        }
    }

    printf("-----Listado de los productos que no superan el promedio de los importes.-----\n");

    for (int i = 0; i < TAM; i++)
    {
        if (produc[i].flagProd == 0 && produc[i].importe < promedioImportes)
        {
            printf("%d  %s  %d  %d  %d\n", produc[i].codProducto, produc[i].descripcion, produc[i].importe, produc[i].cantidad, produc[i].codProveedor);
        }
    }
}

