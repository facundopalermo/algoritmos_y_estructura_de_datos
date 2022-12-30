//6. Diseñar un algoritmo recursivo que muestre el número menor de un vector.
#include <stdio.h>
#include <stdlib.h>

int el_menor(int vector[5],int n, int menor);

int el_menor(int vector[5],int n, int menor){
    if(n<0) {
        return menor;
    }else if(vector[n]<el_menor(vector, n-1, menor)){
        return el_menor(vector, n-1, vector[n]);
    }    
}

int main(){
    int vector[5], n=4,i,r;
    for(i=0;i<n+1;i++){
        printf("Ingrese un numero entero: ");
        scanf("%d",&vector[i]);
    }
    r=el_menor(vector,n, vector[n]);
    printf("El menor numero del vector cargado es: %d",r);
}