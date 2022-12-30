//Diseñar un algoritmo recursivo que permita multiplicar los elementos de un vector.

#include <stdio.h>
#include <stdlib.h>


int multiplica_vector (int vector[], int i);

int multiplica_vector (int vector[], int i){
    if(i==0){
        return 1;
    }else{
        return vector[i-1]*multiplica_vector(vector, i-1);
    }
}

int main () {
    int n = 6;
    int vector[6]={2,2,3,4,5,6};
    printf("R: %d", multiplica_vector(vector, n));
}