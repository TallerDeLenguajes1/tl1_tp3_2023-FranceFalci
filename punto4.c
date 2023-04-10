// Considere la siguiente situación: En una distribuidora necesita implementar la carga de
// productos de sus preventistas, los cuales recolectan los productos que sus clientes van
// necesitando. El sistema que se utiliza en la empresa es desarrollado por equipos de
// programadores donde cada equipo se encarga de una tarea específica. Usted forma parte del
// equipo de programación que se encargará de hacer el módulo para los preventistas:
// Tareas:
// Cada preventista puede visitar hasta 5 clientes, los cuales por cuestiones operativas solo
// puede pedir hasta 10 productos
// Las estructuras de datos necesarias son las siguientes:
// i) Desarrollar una interfaz por consola donde se solicite al usuario la cantidad de
// clientes.
// iv) Implemente una función que calcule el costo total de un producto. Esta función debe
// recibir como parámetro el producto y devolver el resultado de calcular la Cantidad por
// el PrecioUnitario.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// consultar uso del AUX
struct {
int ProductoID; //Numerado en ciclo iterativo
int Cantidad; // entre 1 y 10
char *TipoProducto; // Algún valor del arreglo TiposProductos
float PrecioUnitario; // entre 10 - 100
}typedef Producto;

struct Cliente {
int ClienteID; // Numerado en el ciclo iterativo
char *NombreCliente; // Ingresado por usuario
int CantidadProductosAPedir; // (aleatorio entre 1 y 5)
Producto *Productos; //El tamaño de este arreglo depende de la variable
// “CantidadProductosAPedir”
};
int costoProducto(struct Cliente *clientes,char producto[],int id);
void totalAPagar(struct Cliente *clientes,int id);
int main()
{
srand(time(NULL));
char *TiposProductos[]={"Galletas","Snach","Cigarrillos","Caramelos","Bebidas"};
int nroClientes;
struct Cliente *clientes;
char *aux , *nombreCliente;
aux = malloc(sizeof(char) * 100);


printf("ingrese numero de clientes");
scanf("%d", &nroClientes);
fflush(stdin);

if(nroClientes <= 5){

clientes = malloc(sizeof(struct Cliente) * nroClientes);

for (int i = 0; i < nroClientes; i++)
{
    printf("ingrese nombre del cliente %d",i);
    gets(aux);
    fflush(stdin);
    clientes[i].NombreCliente = malloc(sizeof(char) * strlen(aux) + 1);
    strcpy(clientes[i].NombreCliente, aux);
    puts(clientes[i].NombreCliente);
        clientes[i]
            .ClienteID = i;
    // printf("cantidad de productos a pedir");
    // scanf("%d",&(clientes[i].CantidadProductosAPedir));
    // fflush(stdin);

    clientes[i].CantidadProductosAPedir = rand() %  (5-1+1) +1;
    clientes[i].Productos = malloc(sizeof(Producto) * clientes[i].CantidadProductosAPedir);

    for (int j = 0; j <= clientes[i].CantidadProductosAPedir; j++)
    {
        clientes[i].Productos[j].ProductoID = j;
        clientes[i].Productos[j].Cantidad = rand() % (10-1+1)+1;
        clientes[i].Productos[j].PrecioUnitario = rand() % (100-10+1)+10;
        clientes[i].Productos[j].TipoProducto = TiposProductos[rand() % 5];
    }
    
   
}
}else{
    // corregir 
    while (nroClientes> 5)
    {
    fflush(stdin);
    printf("ingrese numero de clientes");
    scanf("%d", &nroClientes);
    fflush(stdin);
    }
    
}

// mostrar 
// for (int k = 0; k < nroClientes; k++){
//     fflush(stdin);

//     puts(clientes[k].NombreCliente);
//     printf("cantidad prod: %d \n", clientes[k].CantidadProductosAPedir);


//     for (int j = 0; j < clientes[k].CantidadProductosAPedir; j++){
//     printf("tipo producto : %s \n", clientes[k].Productos[j].TipoProducto);
//     printf("precio producto : $%f \n", clientes[k].Productos[j].PrecioUnitario);
//     printf("cantidad producto : $%d \n", clientes[k].Productos[j].Cantidad);
//     }
// }

int totalSnac = costoProducto(clientes,"Galletas",0);
printf("total funcion : %d", totalSnac);
totalAPagar(clientes, 0);


// falta hacer free
}

int costoProducto(struct Cliente *clientes, char producto[], int id)
{
    int cant = clientes[id].CantidadProductosAPedir;
    printf("parametro producto %s , %d \n" ,producto,cant);
    for (int i = 0; i < cant; i++)
    {
    printf("%s \n",clientes[id].Productos[i].TipoProducto);
    if (clientes[id].Productos[i].TipoProducto == producto){
     int total = clientes[id].Productos[i].Cantidad * clientes[id].Productos[i].PrecioUnitario;
    return total;
    }

    }
    printf("fin");
    return(2);
}

void totalAPagar(struct Cliente *clientes, int id){
    int total =0 ;
    printf("id:%d \n nombre: %s \n cant productos a pedir : %d \n" , clientes[id].ClienteID, clientes[id].NombreCliente, clientes[id].CantidadProductosAPedir);

    for (int j = 0; j < clientes[id].CantidadProductosAPedir; j++)
    {
    printf("tipo producto : %s \n", clientes[id].Productos[j].TipoProducto);
    printf("precio producto : $%.2f \n", clientes[id].Productos[j].PrecioUnitario);
    printf("cantidad producto : $%d \n", clientes[id].Productos[j].Cantidad);
    total += clientes[id].Productos[j].Cantidad * clientes[id].Productos[j].PrecioUnitario;
    }

    printf("Total a Pagar : $%d", total);
}