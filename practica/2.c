//Diseñar un algoritmo recursivo que encuentre la suma de los enteros positivos pares desde N hasta 2. Si N es impar imprimir un mensaje de error.
#include <stdio.h>
#include <stdlib.h>


int suma_pares(int n){
    if(n==2){
        return 0;
    }else{
        if(n%2==0){
            return n + suma_pares(n - 2);
        }else{
            return 1;
        } 
    }
}

int main () {

    int res = suma_pares(11);

    if(res!=1){
        printf("%d", res);
    }else{
        printf("error");
    }
}