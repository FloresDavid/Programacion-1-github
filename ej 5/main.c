#include <stdio.h>
#include <stdlib.h>

int main()
{
    int nota;

    printf ("Ingrese una nota: ");
    scanf("%d", &nota);

    switch (nota)
    {
    case 0:
    case 1:
    case 2:
    case 3:
        printf ("La proxima se puede.");
        break;
    case 4:
    case 5:
    case 6:
        printf ("Raspando.");
        if (nota < 5)
        {
            printf (" Debes preocuparte mas.");
        }
        break;
    case 7:
    case 8:
    case 9:
    case 10:
        printf ("Aprobo.");
        if (nota > 8)
        {
         printf (" Muy bien!");
        }
        break;
    default:
        printf ("La nota no es valida.");
    }
    return 0;
}
