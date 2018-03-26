#include <stdio.h>
#include <stdlib.h>

int main()
{
    float precio;
    int porcentajeDeDescuento;
    float descuento;
    float iva;
    float precioConDescuento;
    float precioFinal;

    printf("Ingrese el precio: ");
    scanf ("%f", &precio);

    printf ("Ingrese el descuento: ");
    scanf("%d", &porcentajeDeDescuento);

    descuento = precio * porcentajeDeDescuento / 100;

    precioConDescuento = precio - descuento;

    iva = precioConDescuento * 21 / 100;

    precioFinal = precioConDescuento + iva;

    printf("El descuento es: %.2f", descuento);
    printf("\n\nEl precio con el descuento es: %.2f", precioConDescuento);
    printf("\n\nEl iva es: %.2f", iva);
    printf("\n\nEl precio con descuento mas IVA es: %.2f", precioFinal);

    return 0;
}
