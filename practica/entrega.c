/*
1) Desarrollar un algoritmo que permita:
a) Dados dos números enteros, A y B, calcular su potencia (A^B) en forma iterativa y recursiva.
b) Cargar una matriz de nxn elementos enteros. Mostrarla. Calcular la suma de los elementos de la diagonal principal en forma iterativa y recursiva.*/

#include <stdio.h>
#include <stdlib.h>

float potencia_rec (float A, int B);
float potencia_ite (float A, int B);
void cargar_matriz (int matriz[][100], int n);
void mostrar_matriz (int matriz[][100], int n);
int suma_diag_rec(int matriz[][100], int n);
int suma_diag_ite(int matriz[][100], int n);

/**
 * @param A es float para 1/A, ya que B puede ser negativo
 * @param B 
 * @return float 
 */
float potencia_rec (float A, int B) {
    if (B==0){
        return 1;
    }else if(B>0){
        return A * potencia_rec (A, B - 1);
    }else{
        int nB = B * ( -1 );
        float nA = 1 / A;
        return potencia_rec (nA, nB);
    }
}

float potencia_ite (float A, int B){
    float nA = A;
    int nB = B;
    float resultado = 1;

    if ( B < 0){
        nA = 1 / A;
        nB = (-1) * B; 
    }

    for (int i=0; i<nB; i++){
        resultado = resultado * nA;
    }

    return resultado;
}
/***********************************************************/

void cargar_matriz (int matriz[][100], int n){
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            printf("Ingrese valor para F%d - C%d: ", i+1,j+1);
            scanf("%d", &matriz[i][j]);
        }
    }
}

void mostrar_matriz (int matriz[][100], int n){
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            printf("%d\t", matriz[i][j]);
        }
        printf("\n");
    }
}

int suma_diag_rec(int matriz[][100], int n){
    if ((n-1) < 0){
        return 0;
    }else{
        return matriz[n-1][n-1] + suma_diag_rec(matriz, n-1);
    }
}

int suma_diag_ite(int matriz[][100], int n){
    int resultado = 0;
    for (int i=0; i < n; i++){
        resultado += matriz [i][i];
    }
    return resultado;
}

int main () {
    int matriz[100][100];
    int n=1;

    printf("Potencias de 2 desde -5 a 5 (recursivamente)\n");
    for (int i=-5; i<=5; i++){
        printf("%f  ", potencia_rec (2, i));
    }

    printf("\n\n");

    printf("Potencias de 2 desde -5 a 5 (iterativamente)\n");
    for (int i=-5; i<=5; i++){
        printf("%f  ", potencia_ite (2, i));
    }

    printf("\n\n");

    printf("Matriz\n");
    printf("Tamanio de la matriz nxn?: ");
    scanf("%d", &n);
    while (n<=0){
        printf("Tamanio de la matriz nxn debe ser positivo: ");
        scanf("%d", &n); 
    }
    
    cargar_matriz(matriz, n);
    printf("\n\n");
    mostrar_matriz(matriz, n);
    printf("Suma de la diag. principal mediante recursividad: %d",suma_diag_rec(matriz,n));
    printf("\n");
    printf("Suma de la diag. principal mediante iteracion: %d",suma_diag_ite(matriz,n));
}