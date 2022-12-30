//3. Diseñar un algoritmo recursivo que permita sumar los dígitos de un número. Por ejemplo, Entrada: 123 Resultado: 6.
#include <stdio.h>
#include <stdlib.h>

int sma_digito(int n);

int suma_digito(int n){
    if(n==0) {
        return 0;
    }else{
        return n%10 + suma_digito(n/10);
    }    
}

int main(){
    int n;
    printf("Ingrese numero: ");
    scanf("%d",&n);
    
    printf("la suma de los digitos de %d es: %d", n, suma_digito(n));
}