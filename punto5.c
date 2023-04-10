// 5) Modifique el ejercicio nro 3 para que, en lugar de ingresar un número fijo de nombres, el
// usuario pueda indicar previamente la cantidad de nombres que ingresará a continuación

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char **V, *nombre;
    int cantidadNombres;
    nombre = (char *)malloc(sizeof(char) * 100);

    printf("ingrese cantidad de nombres");
    scanf("%d", &cantidadNombres);
    fflush(stdin);

    V = (char **)malloc(sizeof(char) * cantidadNombres);
    for (int i = 0; i < cantidadNombres; i++)
    {
        printf("ingrese nombre %d:", i);
        gets(nombre);
        fflush(stdin);

        char longitud = strlen(nombre);
        V[i] = (char *)malloc(sizeof(char) * longitud + 1);
        strcpy(V[i], nombre);
    }
    for (int j = 0; j < cantidadNombres; j++)
    {
        puts(V[j]);
    }
    // free(nombre);
    // for (int i = 0; i < ; i++)
    // {
    //     free(V[i]);
    // }

    return 0;
}