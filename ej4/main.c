#include <stdio.h>
#include <stdlib.h>

int main()
{
    int numero1;
    int numero2;
    float resultado;

    printf("Ingrese un numero: ");
    scanf("%d", &numero1);

    printf("Ingrese otro numero: ");
    scanf("%d", &numero2);

    if (numero1 == numero2)
    {
        printf ("%d%d", numero1, numero2);
    }
    else
    {
        if (numero1 > numero2)
        {
           resultado = (float) numero1/numero2;
            printf ("El resultado es: %.2f", resultado);
        }
        else
        {
            resultado = (numero1 + numero2);
            printf ("La suma es: %.0f", resultado);
            if (resultado < 50)
            {
                printf (" y es menor a 50.");
            }
        }
    }



    return 0;
}
