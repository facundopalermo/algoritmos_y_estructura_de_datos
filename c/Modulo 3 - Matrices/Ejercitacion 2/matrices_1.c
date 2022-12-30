#include <stdio.h>
#include <stdlib.h>

void cargarMatriz(int matriz[][5],int n);
void mostrarMatriz(int matriz[][5],int n);
int sumatoriafila(int matriz[][5],int n,int xfila);
int mayorcolumna(int matriz[][5],int n,int xcol);
void promediomult5(int matriz[][5],int n);
int suma_diagonal_principal(int matriz[][5],int n);
void elementos_diagonal_secundaria(int matriz[][5],int n);
void elemento_minimo_x_fila(int matriz[][5],int n);
void elemenos_bajo_diag_princ(int matriz[][5], int n);

void cargarMatriz(int matriz[][5],int n){
    int fila,col;
    printf("Deber%c completar una matriz de %d x %d:\n",160,n,n);
    for (fila=0;fila<n;fila++){
        for (col=0;col<n;col++){
            printf("Ingrese un n%cmero entero para la ubicaci%cn fila %d columna %d: ",163,162,fila+1,col+1);
            scanf("%d",&matriz[fila][col]);
        }
    }
}

int sumatoriafila(int matriz[][5],int n,int xfila){
    int col,suma=0;
    for (col=0;col<n;col++){
        suma+=matriz[xfila][col];            
    }
    return suma;
}

int mayorcolumna(int matriz[][5],int n,int xcol){
    int fila,maximo;
    maximo=matriz[0][0];
    for (fila=0;fila<n;fila++){
        if(maximo<matriz[fila][xcol]){
            maximo=matriz[fila][xcol];
        }            
    }
    return maximo;
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

void promediomult5(int matriz[][5],int n){
    int fila,col,suma=0,cont=0;
    float promedio=0;
    for (fila=0;fila<n;fila++){
        for (col=0;col<n;col++){
            if(matriz[fila][col]%5==0){
                suma+=matriz[fila][col];
                cont++;
            }
        }
    }
    if (cont!=0){
        promedio=suma/cont;
        printf("c) El promedio de m%cltiplos de 5 es %f\n", 163,promedio);
    }else{
        printf("c) No hay m%cltiplos de 5 en la matriz\n",163);
    }
}

int suma_diagonal_principal(int matriz[][5],int n){
    int i,suma=0;
    for (i=0;i<n;i++){
        suma+=matriz[i][i];
    }
    return suma;
}

void elementos_diagonal_secundaria(int matriz[][5],int n){
    int i;
    printf("f) Los elementos de la diagonal secundaria son: ");
    for (i=0;i<n;i++){
        printf("[%d] ", matriz[i][n-1-i]);
    }
}

void elemento_minimo_x_fila(int matriz[][5],int n){
    int fila, col,min;
    printf("e) Los elementos m%cnimos de cada fila son:\n",161);
    for (fila=0;fila<n;fila++){
        min=matriz[fila][0];
        for (col=0;col<n;col++){
            if (min>matriz[fila][col]){
                min=min=matriz[fila][col];
            }
        }
        printf("\tFila %d:[%d]\n",fila+1,min);
    }
}

void elemenos_bajo_diag_princ(int matriz[][5], int n){
    int fila,col;
    printf("\ng) Elementos que se encuentran debajo de la diagonal principal:\n");
    for (fila=1;fila<n;fila++){
        for (col=0;col<(fila);col++){
            printf("[%d]\t",matriz[fila][col]);
        }
        printf("\n");
    }
}

void es_simetrica(int matriz[][5],int n){
    int i,j,cont=0;
    for (i=0;i<n;i++){
        for (j=0;j<n;j++){
            if (matriz[i][j]==matriz[j][i]){
                cont++;
            }
        }
    } 
    if (cont==n*n){
        printf("h) La matriz cargada ES sim%ctrica",130);
    }else{
        printf("h) La matriz cargada NO es sim%ctrica",130);
    }
}

int main(){
    int matriz[5][5], n=5;
    cargarMatriz(matriz,n);
    printf("\n");
    mostrarMatriz(matriz,n);
    printf("\n");
    printf("a) La sumatoria de los elementos de la 2da fila es: %d\n",sumatoriafila(matriz,n,1)); //1 <=> 2da fila
    printf("\n");
    printf("b) El mayor elemento de la 2da columna es: %d\n",mayorcolumna(matriz,n,1));//1 <=> 2da columna
    printf("\n");
    promediomult5(matriz,n);
    printf("\n");
    printf("d) La sumatoria de los elementos de la diagonal principal es %d\n",suma_diagonal_principal(matriz,n));
    printf("\n");
    elemento_minimo_x_fila(matriz,n);
    printf("\n");
    elementos_diagonal_secundaria(matriz,n);
    printf("\n");
    elemenos_bajo_diag_princ(matriz,n);
    printf("\n");
    es_simetrica(matriz,n);
    return 0;
}