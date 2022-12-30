//7. Diseñar un algoritmo recursivo que nos permita obtener el determinante de una matriz cuadrada de dimensión n.

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void cargarMatriz(int matriz[][5],int n);
void mostrarMatriz(int matriz[][5],int n);
int determinante(int matriz[][5], int col, int orden);
int cofactor(int matriz[][5], int orden, int fila, int columna);

void cargarMatriz(int matriz[][5],int n){
    int fila,col,cont=1;
    printf("Deber%c completar una matriz de %d x %d:\n",160,n,n);
    for (fila=0;fila<n;fila++){
        for (col=0;col<n;col++){
            //printf("Ingrese un n%cmero entero para la ubicaci%cn fila %d columna %d: ",163,162,fila+1,col+1);
            //scanf("%d",&matriz[fila][col]);
            matriz[fila][col]=cont;
            cont++;
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

int cofactor(int matriz[][5], int orden, int fila, int columna)
{
   int submatriz[5][5];
   int n = orden - 1;
   int i, j;
   
   int x = 0;
   int y = 0;
   int r;
   for (i = 0; i < orden; i++) {
      for (j = 0; j < orden; j++) {
         if (i != fila && j != columna) {
            submatriz[x][y] = matriz[i][j];
            y++;
            if (y >= n) {
               x++;
               y = 0;
            }
         }
      }
   }
   r=determinante(submatriz,0,orden);
   printf("%d\n",r);
   return pow(-1.0, fila + columna) * r;
}
// funcion recursiva
int determinante(int matriz[][5], int col, int orden){
    if (col>orden-1){
        return 1;
    }else{
        return ((matriz[0][col])*cofactor(matriz,orden,0,col))+determinante(matriz,col+1,orden)-1;
    }
}

int main(){
    int matriz[5][5], n=5;
    cargarMatriz(matriz,n);
    printf("\n");
    mostrarMatriz(matriz,n);
    printf("\n");
    printf("\nLa suma de los elemnetos de la Matriz es %d",determinante(matriz,0,n));
}