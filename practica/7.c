//Diseñar un algoritmo recursivo que muestre el número menor de un vector
#include <stdio.h>
#include <stdlib.h>

int el_menor(int vector[], int min, int i);

int el_menor(int vector[], int min, int i){
    if(i<0){
        return min;
    }else{
        if (vector[i]<el_menor(vector, min, i-1)){
            return el_menor(vector, vector[i], i-1);
        }
    }
}


int main() {
    int n = 6;
    int vector[6]={1,7,9,10,5,6};
    printf("R: %d", el_menor(vector, vector[0], n));
}