#include <stdio.h>
#include <stdlib.h>

void burbuja (int vector[], int n){

    int i, j, aux;

    for( i=0; i < n; i++ ){
        for (j = 0; j < n; j++){
            if(vector[j] > vector[j+1]){
                aux = vector[j+1];
                vector[j+1] = vector[j];
                vector[j] = aux;
            }
        }
    }
}

void burbuja_mejorado (int vector[], int n){

    int i, j, aux, hubo_cambio = 1;

    for( i=0; i < n-1 && hubo_cambio==1; i++ ){
        hubo_cambio = 0;
        for (j = 0; j < n-i-1; j++){
            if(vector[j] > vector[j+1]){
                hubo_cambio = 1;
                aux = vector[j+1];
                vector[j+1] = vector[j];
                vector[j] = aux;
            }
        }
    }
}

int main(int argc, char const *argv[])
{
    int vector[]={5,9,8,7,6,3,2,1,4};
    int vector2[]={5,9,8,7,6,3,2,1,4};
    int n = 9, i;

    burbuja(vector, n);

    for (i=0; i<n; i++){
        printf("%d ", vector[i]);
    }
    printf("\n");

    burbuja_mejorado(vector2, n);

    for (i=0; i<n; i++){
        printf("%d ", vector2[i]);
    }
    return 0;
}
