#include <stdio.h>
#include <stdlib.h>

void seleccion (int vector[], int n){

    int i, j;
    int min;
    int index;

    for( i=0; i < n; i++ ){
        min = vector[i];
        index = i;
        for (j = i+1; j < n; j++){
            if(vector[j] < min){
                min = vector[j];
                index = j;
            }
        }
        vector[index] = vector[i];
        vector[i] = min;
    }
}

int main(int argc, char const *argv[])
{
    int vector[]={5,9,8,7,6,3,2,1,4};
    int n = 9, i;

    seleccion(vector, n);

    for (i=0; i<n; i++){
        printf("%d ", vector[i]);
    }

    return 0;
}
