//Diseñar un algoritmo recursivo que permita sumar los dígitos de un número.

#include <stdio.h>
#include <stdlib.h>

int suma_digitos (int n);

int suma_digitos (int n){
    if(n<=0){
        return 0;
    }else{
        return ( n%10 ) + suma_digitos(n/10);
    }
}

int main(){
    printf("%d", suma_digitos(1234));
}