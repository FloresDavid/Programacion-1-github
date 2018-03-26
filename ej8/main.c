#include <stdio.h>
#include <stdlib.h>

int main()
{
//    char cadenaNombre[]="";
    int cantidadDePaginas;
    int cantidadDeVentas;
    int tema;
    int seguirIngresando = 1;
    int cantidadLibrosConPaginasPares = 0;
    int cantidadLibrosConPaginasImpares = 0;
    int cantidadDeCeroVentas = 0;
    int acumuladorDeVentas = 0;
    int contadorDeVentas = 0;
    int acumuladorDePaginasDeProgramacion = 0;

    //scanf("%d", &seguirIngresando);
    //printf("%d", seguirIngresando);

    while (seguirIngresando == 1)
    {
  /*      printf("Ingrese el nombre del libro. ");
        scanf ("%d", &cadenaNombre);
        printf ("%s", cadenaNombre);
*/
        printf ("Ingrese la cantidad de paginas. ");
        scanf ("%d", &cantidadDePaginas);

        printf("Ingrese la cantidad de ventas. ");
        scanf("%d", &cantidadDeVentas);

        while (cantidadDeVentas <= 0)
        {
            printf("Error, vuelva a ingresar la cantidad de ventas. ");
            scanf("%d", &cantidadDeVentas);
        }

        printf ("Ingrese el numero correspondiente segun el tema:\n 1. Robotica.\n 2. Programacion.\n 3. Patrones.\n 4. Base de datos. ");
        scanf ("%d", &tema);

        while (tema < 1 || tema > 4)
        {
            printf ("Error, ingrese el numero correspondiente segun el tema:\n 1. Robotica.\n 2. Programacion.\n 3. Patrones.\n 4. Base de datos. ");
            scanf ("%d", &tema);

        }


        if (cantidadDePaginas %2 == 0)
        {
            cantidadLibrosConPaginasPares += 1;
        }
        else
        {
            cantidadLibrosConPaginasImpares += 1;
        }
        if (cantidadDeVentas == 0)
        {
            cantidadDeCeroVentas += 1;
        }

        acumuladorDeVentas += cantidadDeVentas;
        contadorDeVentas += 1;

        if (tema == 2)
        {
            acumuladorDePaginasDeProgramacion += cantidadDePaginas;
        }


        printf ("Ingrese 1 para seguir ingresando libros, 0 para salir. ");
        scanf ("%d", &seguirIngresando);

    }

    printf("Hello world!\n");
    return 0;
}
