#include <stdio.h>
#include <stdlib.h>

void insercion (int vector[], int n){

    int x, i, k;

    for (k = 1; k < n; k++) {
        x = vector[k];
        i = k - 1;

        while (i >= 0 && x < vector[i]) {
            vector[i+1] = vector[i];
            i--;
        }
        vector[i+1] = x;
    }
}

int main(int argc, char const *argv[])
{
    int vector[]={5,9,8,7,6,3,2,1,4};
    int n = 9, i;

    insercion(vector, n);

    for (i=0; i<n; i++){
        printf("%d ", vector[i]);
    }

    return 0;
}
