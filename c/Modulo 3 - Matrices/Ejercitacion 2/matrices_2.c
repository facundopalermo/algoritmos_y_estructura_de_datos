#include <stdio.h>
#include <stdlib.h>

void cargarMatriz(int matriz[][5],int n);
void mostrarMatriz(int matriz[][5],int n);
void genera_traspuesta(int matriz_original[][5], int matriz_traspuesta[][5], int n);
int suma_diagonal_principal(int matriz[][5],int n);
int suma_diagonal_secundaria(int matriz[][5],int n);
float promedio_diagonales(int matriz[][5],int n);
void producto_traspuesta(int matriz[][5], int traspuesta[][5], int matriz_x_traspuesta[][5], int n);
void matriz_primos(int matriz[][5], int n);
int primo(int n);


void cargarMatriz(int matriz[][5],int n){
    int fila,col;
    for (fila=0;fila<n;fila++){
        for (col=0;col<n;col++){
            printf("Ingrese un n%cmero entero para la ubicaci%cn fila %d columna %d: ",163,162,fila+1,col+1);
            scanf("%d",&matriz[fila][col]);
        }
    }
}

void mostrarMatriz(int matriz[][5],int n){
    int fila,col;
    for (fila=0;fila<n;fila++){
        for (col=0;col<n;col++){
            printf("[%d]\t",matriz[fila][col]);
        }
        printf("\n");
    }
}

void genera_traspuesta(int matriz_original[][5], int matriz_traspuesta[][5], int n){
    int i,j;
    for (i=0;i<n;i++){
        for (j=0;j<n;j++){
            matriz_traspuesta[j][i]=matriz_original[i][j];
        }
    }    
}

int suma_diagonal_principal(int matriz[][5],int n){
    int i,suma=0;
    for (i=0;i<n;i++){
        suma+=matriz[i][i];
    }
    return suma;
}

int suma_diagonal_secundaria(int matriz[][5],int n){
    int i,suma=0;
    for (i=0;i<n;i++){
        suma+=matriz[i][n-1-i];
    }
    return suma;
}

float promedio_diagonales(int matriz[][5],int n){
    //supuse que el promedio solo de la matriz original
    int suma=0;
    float promedio;
    suma=suma_diagonal_principal(matriz,n)+suma_diagonal_secundaria(matriz,n);
    promedio=suma/(n*2); //entendí que el promedio sobre todos los elementos, por eso n*2 (dos diagonales). Si fuera el promedio entre ambas diagonales solo sería dividido 2
    return promedio;
}

void producto_traspuesta(int matriz[][5], int traspuesta[][5], int matriz_x_traspuesta[][5], int n){
    int i,j,k,suma;
    for(i=0;i<n;i++){
        for (j=0;j<n;j++){
            suma=0;
            for (k=0;k<n;k++){
                suma+=matriz[i][k]*traspuesta[k][j];
            }
            matriz_x_traspuesta[i][j]=suma;
        }
    }
}

void matriz_primos(int matriz[][5], int n){
    int m=25, aux[25]={0},fila,col,cont=0,i;
    for (fila=0;fila<n;fila++){
        for (col=0;col<n;col++){
            if(primo(matriz[fila][col])==1){
                aux[cont]=matriz[fila][col];
                cont+=1;
            }
        }
    }
    printf("\nd) Hay %d n%cmeros primos hay en la matriz: ",cont,163);
    for(i=0;i<m;i++){
        if (aux[i]>0){
            if(i>0){
                printf(", ");
            }
            printf("%d",aux[i]);
        }
    }
}

int primo(int n){
    int i,cont=0;
    for(i=2;i<n;i++)
        if(n%i==0){
            cont+=1;
        }
    if(cont==0 && n>1){
        return 1;
    }else{
        return 0;
    }
}

int main(){
    int matriz[5][5], matriz_traspuesta[5][5],matriz_x_traspuesta[5][5], n=5;
    cargarMatriz(matriz,n);
    printf("\n\nMatriz cargada:\n");
    mostrarMatriz(matriz,n);
    printf("\n\na) Matriz traspuesta:\n");
    genera_traspuesta(matriz,matriz_traspuesta,n);
    mostrarMatriz(matriz_traspuesta,n);
    printf("\n\nb) El promedio de los elementos de las dos diagonales (principal y secundaria) es: %f",promedio_diagonales(matriz,n));
    producto_traspuesta(matriz,matriz_traspuesta,matriz_x_traspuesta,n);
    printf("\n\nc) Producto Matriz original x traspuesta:\n");
    mostrarMatriz(matriz_x_traspuesta,n);
    matriz_primos(matriz,n);
    return 0;
}