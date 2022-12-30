//Diseñar un algoritmo recursivo que permita invertir un número.

#include <stdio.h>
#include <stdlib.h>

void invertido (int n);

void invertido (int n){
    if (n<=0){
        return;
    }else{
        printf("%d", n%10);
        return invertido(n/10);
    }
}

int main () {
    invertido(123456789);
}