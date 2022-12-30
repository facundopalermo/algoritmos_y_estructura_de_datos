//2. Diseñar un algoritmo recursivo que permita invertir un número. Por ejemplo, Entrada: 123 Salida: 321.
#include <stdio.h>
#include <stdlib.h>

void invertido(int n);

void invertido(int n){
    if(n>0) {
        printf("%d", n%10);
        invertido(n/10);
    }    
}

int main(){
    int n;
    printf("Ingrese numero: ");
    scanf("%d",&n);
    
    printf("%d invertido: ", n);
    invertido(n);
}