//recursividad (funciones que se llaman a si mismas)
#include <stdio.h>
#include <stdlib.h>

int factorial(int n){
    if(n==0){
        return 1; //para que cuando sea 0, multiplique por 1
    }else{
        if (n>=1){
            printf("%d",n);
        }
        if (n>1){
            printf("*");
        }
        if (n==1){
            printf("=");
        }
        return n*factorial(n-1);
    }
}

/*int division(int dividendo, int divisor){
    if (dividendo<divisor){
        printf("\nResto: %d\nEntero: ",dividendo);
        return 0;
    }else{
        printf("%d - %d = %d + 1\n",dividendo,divisor,dividendo-divisor);
        return division(dividendo-divisor,divisor)+1;
    }
}*/


/*
int main(){
    int a,b;
    printf("Ingrese un numero para dividendo: ");
    scanf("%d",&a);
    printf("Ingrese un numero para divisor: ");
    scanf("%d",&b);
    printf("\n");

    printf("%d",division(a,b));
}
*/
int main(){
    int n;
    
    printf("Ingrese un numero: ");
    scanf("%d", &n);
    
    printf("%d",factorial(n));

    return 0;
}
/*
void invertir(int n){
    if(n>0) {
        printf("%d", n%10);
        invertir(n/10);
    }
}
*/


