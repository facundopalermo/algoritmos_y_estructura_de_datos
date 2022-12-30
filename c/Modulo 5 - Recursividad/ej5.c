//5. Diseñar un algoritmo recursivo que permita sumar los elementos de una matriz.
#include <stdio.h>
#include <stdlib.h>

void cargarMatriz(int matriz[][5],int n);
void mostrarMatriz(int matriz[][5],int n);
int suma_matriz(int matriz[][5],int fila, int col, int n);

void cargarMatriz(int matriz[][5],int n){
    int fila,col;
    printf("Deberá completar una matriz de %d x %d:\n",160,n,n);
    for (fila=0;fila<n;fila++){
        for (col=0;col<n;col++){
            printf("Ingrese un n%cmero entero para la ubicaci%cn fila %d columna %d: ",163,162,fila+1,col+1);
            scanf("%d",&matriz[fila][col]);
        }
    }
}

void mostrarMatriz(int matriz[][5],int n){
    int fila,col;
    printf("\nMatriz cargada:\n");
    for (fila=0;fila<n;fila++){
        for (col=0;col<n;col++){
            printf("[%d]\t",matriz[fila][col]);
        }
        printf("\n");
    }
}

// funcion recursiva
int suma_matriz(int matriz[][5],int fila, int col, int n){
    if (fila<0){
        return 0;
    }else if(col==0){
        return matriz[fila][col]+suma_matriz(matriz,fila-1,n,n);
    }else if (col>0){
        return matriz[fila][col]+suma_matriz(matriz,fila,col-1,n);
    }
}

int main(){
    int matriz[5][5], n=5;
    cargarMatriz(matriz,n);
    printf("\n");
    mostrarMatriz(matriz,n);
    printf("\n");
    printf("\nLa suma de los elemnetos de la Matriz es %d",suma_matriz(matriz,n-1,n-1,n-1));
}