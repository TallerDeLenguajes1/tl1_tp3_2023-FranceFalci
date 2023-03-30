//  Una empresa necesita simular la producción de los próximos 5 años para tal fin necesita
// generar una matriz (estática) de 5x12 donde cada fila corresponde a un año y cada columna
// es un mes. Ud. debe realizar las siguientes tareas:
// a. Cargue dicha matriz con valores aleatorios entre 10000 y 50000. 
// b. Muestre por pantalla los valores cargados
// c. Saque el promedio de ganancia por año y muestrelos por pantalla
// d. Obtenga el valor máximo y el valor mínimo obtenido informando el “año” y el “mes” de
// cuándo ocurrió.

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 5
#define M 12

void mostrarPromedio(int *mt,int n ,int m);
void valorMaximo(int *mt, int n, int m);

int main(){
    srand(time(NULL));
    int matriz[N][M];
    int *Pmatriz=&matriz[0][0];


    // cargo y muestro la matriz
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            *(Pmatriz + i * M + j) = rand() % (50000 - 10000 + 1) + 10000;
            printf("%4d ", *(Pmatriz + i * M + j));
        }
        printf("\n");
    }

mostrarPromedio(Pmatriz,N,M);
valorMaximo(Pmatriz, N, M);
valorMinimo(Pmatriz, N, M);

return 0;
}
void mostrarPromedio(int* mt, int n, int m){
   float prom =0;
  
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            prom += *(mt + i * m+j);
        }
        prom = prom/12;
        printf("promedio fila %d  = %10.2f \n", i, prom);
        prom = 0;
    }
     
}

void valorMaximo(int *mt, int n, int m){
    int fila , columna;
    int maximo = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (*(mt + i * M + j) > maximo){
                maximo = *(mt + i * M + j);
                fila = i;
                columna = j;
            }
        }
    }
    printf("maximo valor %d , fila: %d , columna: %d", maximo , fila , columna);
}

void valorMinimo(int *mt, int n, int m)
{
    int fila, columna;
    int minimo = 50000;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (*(mt + i * M + j) < minimo)
            {
                minimo = *(mt + i * M + j);
                fila = i;
                columna = j;
            }
        }
    }
    printf("maximo valor %d , fila: %d , columna: %d", minimo, fila, columna);
}