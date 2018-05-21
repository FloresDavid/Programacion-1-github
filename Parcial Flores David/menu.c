int menu()
{
    char sOpcion[1];
    int opcion;
    int esNumero;

    printf("\nIngrese la opcion que quiera utilizar.\n");
    printf("1) Ingresar producto.\n");
    printf("2) Modificar producto.\n");
    printf("3) Eliminar producto.\n");
    printf("4) Informar totales, promedios y stock.\n");
    printf("5) Listar.\n");
    printf("6) Salir.\n");

    fflush(stdin);
    gets(sOpcion);
    esNumero = validarNumero(sOpcion);
    opcion = atoi(sOpcion);

    while (esNumero == 1 || opcion < 1 || opcion > 6)
    {
        printf("Error. Opcion incorrecto, reingrese la opcion deseada: ");
        gets(sOpcion);
        esNumero = validarNumero(sOpcion);
        opcion = atoi(sOpcion);
    }
    return opcion;
}
