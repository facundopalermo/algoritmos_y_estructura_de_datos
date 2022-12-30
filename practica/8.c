//Diseñar un algoritmo recursivo que calcule el coeficiente binomial.
#include <stdio.h>
#include <stdlib.h>

int coef_bi(int n, int k);

int coef_bi(int n, int k){
    if(n==k || k==0){
        return 1;
    }else if (k>n){
        return 0;
    }else if(k > n/2){
        return coef_bi(n, n-k);
    }else{
        return coef_bi(n-1, k-1) + coef_bi(n-1, k);
    }
}

int main(){
    printf("%d", coef_bi(3,2));
}