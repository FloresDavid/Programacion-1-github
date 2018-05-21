#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "proveedores.h"
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

void ingresarProducto(eProducto produc[], eProveedor prov[], int tamProv)
{
    eProducto nuevoProducto;
    char sImporte[10];
    char sCantidad[10];
    char sCodigoProv[10];
    char sDescripcion[50];
    int esString;
    int esNumero;

    printf ("Ingrese la descripcion del producto. \n\n");
    gets(nuevoProducto.descripcion);
    esString = validarString(nuevoProducto.descripcion);

    while (esString == 1)
    {
        printf("Error. Descripcion incorrecta, reingrese la descripcion: ");
        gets(nuevoProducto.descripcion);
        esString = validarString(nuevoProducto.descripcion);
    }

    printf("Ingrese el importe.\n\n");
    gets(sImporte);
    esNumero = validarNumero(sImporte);
    nuevoProducto.importe = atoi(sImporte);

    while (esNumero == 1 || nuevoProducto.importe < 1)
    {
        printf("Error. Importe incorrecto, reingrese el Importe: ");
        gets(sImporte);
        esNumero = validarNumero(sImporte);
        nuevoProducto.importe = atoi(sImporte);
    }

    printf("Ingrese la cantidad.\n\n");
    gets(sCantidad);
    esNumero = validarNumero(sCantidad);
    nuevoProducto.cantidad = atoi(sCantidad);

    while (nuevoProducto.cantidad < 1 || esNumero == 1)
    {
        printf("Error, reingrese la cantidad.\n\n");
        gets(sCantidad);
        esNumero = validarNumero(sCantidad);
        nuevoProducto.cantidad = atoi(sCantidad);
    }
    for (int i = 0; i < tamProv; i++)
    {
        printf("Ingrese %d para seleccionar al proveedor %s.\n", prov[i].codProveedor, prov[i].descripcion);
    }

    printf("Ingrese el codigo del proveedor correspondiente.\n\n");
    gets(sCodigoProv);
    esNumero = validarNumero(sCodigoProv);
    nuevoProducto.codProveedor = atoi(sCodigoProv);

    while (nuevoProducto.codProveedor < 1 || nuevoProducto.codProveedor > tamProv || esNumero == 1)
    {
        printf("Error, reingrese el codigo del proveedor correspondiente.\n\n");
        gets(sCodigoProv);
        esNumero = validarNumero(sCodigoProv);
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
    char sCodProducto[10];
    int codProducto;
    char sOpcion[5];
    int opcion;
    int esNumero;

    printf("Ingrese el codigo del producto a eliminar. \n");
    gets(sCodProducto);
    esNumero = validarNumero(sCodProducto);
    codProducto = atoi(sCodProducto);

    while (codProducto < 1 || esNumero == 1)
    {
        printf("Error, reingrese el codigo del producto a eliminar. \n");
        gets(sCodProducto);
        esNumero = validarNumero(sCodProducto);
        codProducto = atoi(sCodProducto);
    }

    for (int i = 0; i < TAM; i++)
    {
        if (prod[i].flagProd == 0 && prod[i].codProducto == codProducto)
        {
            printf("El producto es: %s, esta seguro que desea eliminarlo?", prod[i].descripcion);
            printf("1) Si.");
            printf("2) No.");

            gets(sOpcion);
            esNumero = validarNumero(sOpcion);
            opcion = atoi(sOpcion);

            while (opcion < 1 || opcion > 2 || esNumero == 1)
            {
                printf("Error, reingrese la opcion. \n");
                gets(sOpcion);
                esNumero = validarNumero(sOpcion);
                opcion = atoi(sOpcion);
            }

            if (opcion == 1)
            {
                prod[i].flagProd = 1;
                printf("Baja exitosa!\n");
            }
            else
            {
                printf("Se ha cancelado la baja del producto.\n");
            }
            break;
        }
    }
}

void modificarProducto(eProducto prod[])
{
    char sCodProducto[10];
    int codProducto;
    char sOpcion[5];
    int opcion = -1;
    int indice;
    char sImporte[10];
    char sCantidad [10];
    char sCodigoProv[10];
    int esNumero;
    int esString;

    printf("Ingrese el codigo del producto a modificar. \n");
    gets(sCodProducto);
    esNumero = validarNumero(sCodProducto);
    codProducto = atoi(sCodProducto);

    while (codProducto < 1 || esNumero == 1)
    {
        printf("Error, reingrese el codigo del producto a modificar. \n");
        gets(sCodProducto);
        esNumero = validarNumero(sCodProducto);
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

        gets(sOpcion);
        esNumero = validarNumero(sOpcion);
        opcion = atoi(sOpcion);

        while (opcion < 1 || opcion > 5 || esNumero == 1)
        {
            printf("Error, reingrese la opcion.\n\n");
            gets(sOpcion);
            esNumero = validarNumero(sOpcion);
            opcion = atoi(sOpcion);
        }

        switch (opcion)
        {
            case 1:
                printf ("Ingrese la descripcion del producto. \n\n");
                fflush(stdin);
                gets(prod[indice].descripcion);
                esString = validarString(prod[indice].descripcion);

                while (esString == 1)
                {
                    printf ("Error. Reingrese la descripcion del producto. \n\n");
                    gets(prod[indice].descripcion);
                    esString = validarString(prod[indice].descripcion);
                }
                break;

            case 2:
                printf("Ingrese el importe.\n\n");
                gets(sImporte);
                esNumero = validarNumero(sImporte);
                prod[indice].importe = atoi(sImporte);

                while (prod[indice].importe < 1 || esNumero == 1)
                {
                    printf("Error, reingrese el importe.\n\n");
                    gets(sImporte);
                    esNumero = validarNumero(sImporte);
                    prod[indice].importe = atoi(sImporte);
                }
                break;

            case 3:
                printf("Ingrese la cantidad.\n\n");
                gets(sCantidad);
                esNumero = validarNumero(sCantidad);
                prod[indice].cantidad = atoi(sCantidad);

                while (prod[indice].cantidad < 1 || esNumero == 1)
                {
                    printf("Error, reingrese la cantidad.\n\n");
                    gets(sCantidad);
                    esNumero = validarNumero(sCantidad);
                    prod[indice].cantidad = atoi(sCantidad);
                }
                break;

            case 4:
                printf("Ingrese el codigo del proveedor correspondiente.\n\n");
                gets(sCodigoProv);
                esNumero = validarNumero(sCodigoProv);
                prod[indice].codProveedor = atoi(sCodigoProv);

                while (prod[indice].codProveedor < 1 || esNumero == 1)
                {
                    printf("Error, reingrese el codigo del proveedor correspondiente.\n\n");
                    getc(sCodigoProv);
                    esNumero = validarNumero(sCodigoProv);
                    prod[indice].codProveedor = atoi(sCodigoProv);
                }
                break;
            case 5:
                opcion = 0;
                break;
            default:
                printf("Opcion incorrecta!!\n\n");
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

void listar(eProducto produc[], eProveedor prov[], int tamProv)
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
    printf("|  Codigo de Producto  |  Descripcion  |  Importe  |  Cantidad  |  Proovedor  |\n");
    printf("|                      |               |           |            |             |\n");

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
        printf("\n\n\n PROOVEDORES\n");
        for (int i = 0; i < 4; i++)
        {
            printf("%d ) %s\n", prov[i].codProveedor, prov[i].descripcion);
        }
        printf("\n\n\n");
        if (produc[i].flagProd == 0)
        {
            printf("|         %4d         |%11s    |   %5d   |    %3d     |      %3d    |\n", produc[i].codProducto, produc[i].descripcion, produc[i].importe, produc[i].cantidad, produc[i].codProveedor);
        }
    }

    printf("\n\n\n-----Listado de todos los productos menores o iguales a 10.-----\n");
    printf("|  Codigo de Producto  |  Descripcion  |  Importe  |  Cantidad  |  Proovedor  |\n");
    printf("|                      |               |           |            |             |\n");

    for (int i = 0; i < TAM; i++)
    {
        if (produc[i].flagProd == 0 && produc[i].cantidad <= 10)
        {
            printf("|         %4d         |%11s    |   %5d   |    %3d     |      %3d    |\n", produc[i].codProducto, produc[i].descripcion, produc[i].importe, produc[i].cantidad, produc[i].codProveedor);
        }
    }

    printf("\n\n\n-----Listado de los productos mayores a 10.-----\n");
    printf("|  Codigo de Producto  |  Descripcion  |  Importe  |  Cantidad  |  Proovedor  |\n");
    printf("|                      |               |           |            |             |\n");

    for (int i = 0; i < TAM; i++)
    {
        if (produc[i].flagProd == 0 && produc[i].cantidad > 10)
        {
            printf("|         %4d         |%11s    |   %5d   |    %3d     |      %3d    |\n", produc[i].codProducto, produc[i].descripcion, produc[i].importe, produc[i].cantidad, produc[i].codProveedor);
        }
    }
    printf("\n\n\n-----Listado de los productos que superan el promedio de los importes.-----\n");
    printf("|  Codigo de Producto  |  Descripcion  |  Importe  |  Cantidad  |  Proovedor  |\n");
    printf("|                      |               |           |            |             |\n");

    for (int i = 0; i < TAM; i++)
    {
        if (produc[i].flagProd == 0 && produc[i].importe > promedioImportes)
        {
            printf("|         %4d         |%11s    |   %5d   |    %3d     |      %3d    |\n", produc[i].codProducto, produc[i].descripcion, produc[i].importe, produc[i].cantidad, produc[i].codProveedor);
        }
    }

    printf("\n\n\n-----Listado de los productos que no superan el promedio de los importes.-----\n");
    printf("|  Codigo de Producto  |  Descripcion  |  Importe  |  Cantidad  |  Proovedor  |\n");
    printf("|                      |               |           |            |             |\n");

    for (int i = 0; i < TAM; i++)
    {
        if (produc[i].flagProd == 0 && produc[i].importe < promedioImportes)
        {
            printf("|         %4d         |%11s    |   %5d   |    %3d     |      %3d    |\n", produc[i].codProducto, produc[i].descripcion, produc[i].importe, produc[i].cantidad, produc[i].codProveedor);
        }
    }

    proovedorMostrandoProductos(produc, prov, tamProv);

    productosPorUnProveedor(produc, prov, tamProv);

}

int validarString (char cadena[])
{
    int esNumero = 0;

    for (int i = 0; i < strlen(cadena); i++)
    {
        if (isalpha(cadena[i]) == 0)
        {
            esNumero = 1;
        }
    }
    return esNumero;
}

int validarNumero (char numero[])
{
    int esNumero = 0;
    int len;

    len = strlen(numero);

    for (int i = 0; i < len; i++)
    {
        if (isdigit(numero[i]) == 0)
        {
            esNumero = 1;
        }
    }
    return esNumero;
}


void proovedorMostrandoProductos ( eProducto productos[], eProveedor proveedores[], int tamProv)
{
    int codigo;
    int contador = 0;
    int maximo = 0;

    for (int i = 0; i < tamProv; i++)   //RECORRE VECTOR DE PROVEEDORES
    {
        for (int j = 0; j < TAM; j++)   //RECORRE VECTOR DE RODUCTOS
        {
            if(productos[j].codProveedor == proveedores[i].codProveedor && productos[j].flagProd == 0) //COMPARA EL CODIGO DE PROOVEDOR DEL VECTOR DE
            {                                                                                          //PROOVEDORES CON EL CODIGO DE PROOVEDOR DEL
                contador++;    //SI LA CONDICION ES VERDADERA, SUMA 1 AL CONTADOR                      // VECTOR DE PRODUCTOS SOLAMENTE SI ESTA EL
            }                                                                                          // PRODUCTO ESTA ACTIVO (EL FLAG ES = 0)
        }
        if (contador > maximo)          // SI EL CONTADOR ES MAYOR AL MAXIMO ENTRA AL IF
        {
            maximo = contador;                          //GUARDA EL NUEVO MAXIMO
            codigo = proveedores[i].codProveedor;       //Y GUARDA EL CODIGO DEL PROOVEDOR
        }
    }

    for (int i = 0; i < tamProv; i++)
    {
        if (proveedores[i].codProveedor == codigo)
        {
            printf("\n\n\n----------El proveedor que provee mas productos es: %s----------\n", proveedores[i].descripcion);
            break;
        }
    }

    for (int i = 0; i < TAM; i++)                   // VUELVE A RECORRER EL ARRAY DE RODUCTOS
    {
        if(productos[i].codProveedor == codigo && productos[i].flagProd == 0)  // SI EL CODIGO DE PROOVEDORES DEL PRODUCTO EN LA POSICION I COINCIDE
        {                                                                      // CON EL CODIGO GUARDADO(QUE ES EL QUE MAS PRODUCTOS VENDIO), ENTRA
            printf("Producto: %s\n", productos[i].descripcion);             //ACA MUESTRA EL NOMBRE DEL PRODUCTO, SIEMPRE Y CUANDO CUMPLA LA CONDICION
        }
    }
}


void productosPorUnProveedor(eProducto productos[], eProveedor proveedores[], int tamProv)
{
    char sProvElegido[10];
    int provElegido;

    printf("Indique el codigo del proveedor deseado.\n");

    for (int i = 0; i < tamProv; i++)
    {
        printf("%d ) %s\n", proveedores[i].codProveedor, proveedores[i].descripcion);
    }
    gets(sProvElegido);

    for (int i = 0; i < tamProv; i++)
    {
        if (proveedores[i].codProveedor == provElegido)
        {
            printf("---------- %d ----------\n", proveedores[i].descripcion);
            break;
        }
    }

    printf("Productos: \n");

    for (int j = 0; j < TAM; j++)
    {
        if (productos[j].codProveedor == provElegido && productos[j].flagProd == 0)
        {
            printf("%s\n", productos[j].descripcion);
        }
    }
}
