#include <stdio.h>
#include <stdlib.h>

int main()
{
    int nota;
    char sexo;
    int edad;
    float promedio;
    int acumuladorNotas = 0;
    int notaMasBaja;
    char sexoNotaMasBaja;
    int cantidadDeVarones = 0;
    int menorEdad;
    int notaDelMenor;
    char menorSexo;
    int hayMujeres = 0;
    int edadPrimerMujer;
    int notaPrimerMujer;

    for (int i=0; i<5; i++)
    {
        printf ("\nIngrese la nota del alumno: ");
        scanf ("%d", &nota);

        while (nota < 0 || nota > 10)
        {
            printf ("\nError, ingrese la nota del alumno: ");
            scanf ("%d", &nota);
        }

        printf ("\nIngrese el sexo del alumno: ");
        scanf ("%c", &sexo);
        sexo = tolower(sexo);

        while (sexo != 'f' && sexo != 'm')
        {
            printf ("\nError, ingrese el sexo del alumno: ");
            scanf ("%c", &sexo);
            sexo = tolower(sexo);
        }
        printf ("\nIngrese la edad del alumno: ");
        scanf ("%d", &edad);

        if (nota < notaMasBaja || i == 0)
        {
            notaMasBaja = nota;
            sexoNotaMasBaja = sexo;
        }
        if (edad >= 18 && sexo == 'm' && nota > 5)
        {
            cantidadDeVarones += 1;
        }
        if (menorEdad > edad || i == 0)
        {
            menorEdad = edad;
            menorSexo = sexo;
            notaDelMenor = nota;
        }
        if (sexo == 'f' && hayMujeres == 0)
        {
            hayMujeres = 1;
            edadPrimerMujer = edad;
            notaPrimerMujer = nota;
        }

        acumuladorNotas += nota;
    }

    promedio = (float) acumuladorNotas / 5;

    printf("\n\nEl promedio es: %.2f", promedio);

    printf ("\n\nLa nota mas baja es %d", notaMasBaja);
    printf (", el sexo de la persona es: %c", sexoNotaMasBaja);

    printf ("\n\nLa cantidad de varones mayores a 18 años con nota mayor a 6 es: %d", cantidadDeVarones);

    printf ("\n\nEl sexo del mas joven es: %c", menorSexo);
    printf (", y la nota es: %d", notaDelMenor);

    if (hayMujeres == 0)
    {
        printf ("No hubo mujeres.");
    }
    else
    {
        printf ("\n\nLa edad de la primer mujer es: %d", edadPrimerMujer);
        printf (", y la nota es: %d", notaPrimerMujer);
    }

    return 0;
}
