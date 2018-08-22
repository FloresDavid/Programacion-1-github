#include <stdio.h>
#include <stdlib.h>

int main()
{
    int numeroUno;
    int numeroDos;
    int numeroTres;
    int numeroDelMedio;
    int numeroMinimo;
    int numeroMaximo;
    int hayNumeroMedio = 0;

    printf("Ingrese el primer numero: ");
    scanf("%d", &numeroUno);
    numeroMinimo = numeroUno;
    numeroMaximo = numeroUno;

    printf("Ingrese el segundo numero: ");
    scanf("%d", &numeroDos);
    if (numeroMinimo > numeroDos)
    {
        numeroMinimo = numeroDos;
    }
    else if (numeroMaximo < numeroDos)
    {
        numeroMaximo = numeroDos;
    }

    printf("Ingrese el tercer numero: ");
    scanf("%d", &numeroTres);
    if (numeroMinimo > numeroTres)
    {
        numeroMinimo = numeroTres;
    }
    else if (numeroMaximo < numeroTres)
    {
        numeroMaximo = numeroTres;
    }

    if(numeroUno > numeroMinimo && numeroUno < numeroMaximo)
    {
        numeroDelMedio = numeroUno;
        hayNumeroMedio = 1;
    }
    else if(numeroDos > numeroMinimo && numeroDos < numeroMaximo)
    {
        numeroDelMedio = numeroDos;
        hayNumeroMedio = 1;
    }
    else if (numeroTres > numeroMinimo && numeroTres < numeroMaximo)
    {
        numeroDelMedio = numeroTres;
        hayNumeroMedio = 1;
    }

    if (hayNumeroMedio == 0)
    {
        printf("No existe un numero del medio.");
    }
    else
    {
        printf("El numero del medio es el numero: %d", numeroDelMedio);
    }
    return 0;
}
