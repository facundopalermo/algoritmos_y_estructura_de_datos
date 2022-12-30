//4. Diseñar un algoritmo recursivo que permita multiplicar los elementos de un vector.
#include <stdio.h>
#include <stdlib.h>

int multiplica(int vector[5],int n);

int multiplica(int vector[5],int n){
    if(n<0) {
        return 1;
    }else{
        return multiplica(vector, n-1)*vector[n];
    }    
}

int main(){
    int vector[5], n=4,r=0,i;
    for(i=0;i<n+1;i++){
        printf("Ingrese un numero entero: ");
        scanf("%d",&vector[i]);
    }
    r=multiplica(vector,n);
    printf("%d",r);
}