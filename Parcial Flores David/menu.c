int menu()
{
    char sOpcion[1];
    int opcion;

    printf("\nIngrese la opcion que quiera utilizar.\n");
    printf("1) Ingresar producto.\n");
    printf("2) Modificar producto.\n");
    printf("3) Eliminar producto.\n");
    printf("4) Informar totales, promedios y stock.\n");
    printf("5) Listar.\n");
    printf("6) Salir.\n");

    scanf("%s", sOpcion);
    opcion = atoi(sOpcion);

    while (opcion < 1)
    {
        printf("Error, reingrese la opcion.\n\n");
        scanf("%s", sOpcion);
        opcion = atoi(sOpcion);
    }

    if(opcion == 6)
    {
        opcion = 0;
    }

    return opcion;
}
