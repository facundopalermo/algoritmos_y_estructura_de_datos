#include <stdio.h>
#include <stdlib.h>

int main(){
    /*float array[15], *puntero;
    int i,d=15;
    for (i=0;i<d;i++){
        printf("Ingrese un numero: ");
        scanf("%f",&array[i]);
    }
    printf("{ ");
    for(i=0;i<d;i++){
        printf("%.2f",array[i]);
        if (i<(d-1)){
            printf(", ");
        }
    }
    printf(" }\n\n");
    puntero=&array;

    for(i=0;i<d;i++){
        printf("%f = %.2f",puntero[i],*puntero[i]);
        if (i<(d-1)){
            printf(", ");
        }
    }*/
    int A[10]={12,15,17,21,34,45};
    
    int *B;
    B=A; 
    *B=A[4];
    printf("%d",*(B+0));
    return 0;
}