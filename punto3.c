// Escriba un programa que solicite 5 nombres, los cargue en un vector de punteros char y una
// vez cargados los liste por pantalla (Todo implementando reserva dinámica de memoria) (Lea
// las notas 1 y 2)

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    char *V[5],*nombre;
  nombre = (char *)malloc(sizeof(char) * 100);

    for (int i = 0; i < 5; i++)
    {
        printf("ingrese nombre %d:", i);
        gets(nombre);
        char longitud = strlen(nombre);
        V[i] = (char*)malloc(sizeof(char) * longitud + 1);
        strcpy(V[i] , nombre);
    }
    for (int j = 0; j < 5; j++)
    {
        puts(V[j]);
    }
    free(nombre);
    for (int i = 0; i < 5; i++)
    {
        free(V[i]);
    }
   

    return 0;
}
