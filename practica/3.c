//Diseñar un algoritmo recursivo e iterativo que permita hacer la división por restas sucesivas.

#include <stdio.h>
#include <stdlib.h>

int div_rec(int dividendo, int divisor);
int div_ite(int dividendo, int divisor);

int div_rec(int dividendo, int divisor){
    if(dividendo<divisor){
        return 0;
    }else{
        return div_rec(dividendo - divisor, divisor)+1;
    }
}

int div_ite(int dividendo, int divisor){
    int c=0;

    while (dividendo < divisor){
        dividendo = - divisor;
        c++;
    }
    return c;
}

int main(){
    printf("%d\n", div_rec(10,2));
    printf("%d", div_rec(10,2));
}