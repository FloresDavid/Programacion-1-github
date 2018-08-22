#include <stdio.h>
#include <stdlib.h>
//ingresar 3 numeros y saber el del medio

int main()
{

    int numeroUno;
    int numeroDos;
    int numeroTres;

    printf("Ingrese el primer numero: ");
    scanf("%d", &numeroUno);
    printf("Ingrese el segundo numero: ");
    scanf("%d", &numeroDos);
    printf("Ingrese el tercer numero: ");
    scanf("%d", &numeroTres);

    if((numeroUno > numeroDos && numeroUno < numeroTres) || (numeroUno < numeroDos && numeroUno > numeroTres))
    {
        printf("El numero del medio es el numero: %d", numeroUno);
    }
    else
    {
        if((numeroDos > numeroUno && numeroDos < numeroTres) || (numeroDos < numeroUno && numeroDos > numeroTres))
        {
            printf("El numero del medio es el numero: %d", numeroDos);
        }
        else
        {
            printf("El numero del medio es el numero: %d", numeroTres);
        }
    }
    return 0;
}
