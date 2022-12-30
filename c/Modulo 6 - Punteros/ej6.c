/*6. Escribir un programa efectúe las siguientes operaciones:
    a) Declarar una matriz de 3x4 de tipo int. Cargar sus elementos y mostrarla.
    b) Declarar un puntero a entero.
    c) Asignar al puntero la dirección de la matriz.
    d) Recorrer con el puntero la matriz, mostrando la dirección y el contenido de cada posición.*/

#include <stdio.h>
#include <stdlib.h>

void cargarMatriz(int matriz[3][4],int f,int c);
void mostrarMatriz(int matriz[3][4],int f,int c);
void recorre_x_puntero(int *p,int f,int c);

//a
void cargarMatriz(int matriz[3][4],int f,int c){
    int fila,col;
    printf("Deber%c completar una matriz de %d x %d:\n",160,f,c);
    for (fila=0;fila<f;fila++){
        for (col=0;col<c;col++){
            printf("Ingrese un n%cmero entero para la ubicaci%cn fila %d columna %d: ",163,162,fila+1,col+1);
            scanf("%d",&matriz[fila][col]);
        }
    }
}

void mostrarMatriz(int matriz[3][4],int f,int c){
    int fila,col;
    printf("\nMatriz cargada:\n");
    for (fila=0;fila<f;fila++){
        for (col=0;col<c;col++){
            printf("[%d]\t",matriz[fila][col]);
        }
        printf("\n");
    }
}

void recorre_x_puntero(int *p,int f,int c){
    int fila,col;
    printf("\nMatriz cargada:\n");
    for (fila=0;fila<f;fila++){
        for (col=0;col<c;col++){
            printf("[%x::%d]\t",p+(fila*c)+col,*(p+(fila*c)+col));
        }
        printf("\n");
    }
}

int main(){
    int matriz[3][4],f=3,c=4, *puntero;
    cargarMatriz(matriz,f,c);
    mostrarMatriz(matriz,f,c);

    puntero=matriz;
    printf("\n\npunto d): \n\n");
    recorre_x_puntero(puntero,f,c);
    return 1;
}