//1. Diseñar un algoritmo recursivo que permita hacer la división por restas sucesivas.

#include <stdio.h>
#include <stdlib.h>

/*int division(int dividendo, int divisor);

int division(int dividendo, int divisor){
    if (dividendo<divisor){
        return 0;
    }else{
        return division(dividendo-divisor,divisor)+1;
    }
}

int main(){
    int dividendo, divisor;
    printf("Ingrese el dividendo: ");
    scanf("%d",&dividendo);
    printf("Ingrese el divisor: ");
    scanf("%d",&divisor);
    
    printf("%d dividido %d es %d", dividendo, divisor, division(dividendo,divisor));


}*/

int productoria(int n);

int productoria(int n){
    if (n==0){
        return 1;
    }else{
        return n*productoria(n-1);
    }
}

int main(){
    int n,s=1;
    printf("Ingrese el numero: ");
    scanf("%d",&n);
    
    printf("la productoria (recursiva)es: %d\n",productoria(n));

    for (int i=1; i<=n;i++){
	    s=s*i;
    }
    printf("la productoria es: %d",s);


}