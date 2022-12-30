/*5. Escribir un programa efectúe las siguientes operaciones:
    a) Declarar un arreglo de quince posiciones de tipo float. Cargar sus elementos y mostrarlo.
    b) Declarar un puntero a float.
    c) Asignar al puntero la dirección del arreglo.
    d) Recorrer con el puntero el arreglo, mostrando la dirección y el contenido de cada posición.*/

#include <stdio.h>
#include <stdlib.h>

void cargar_arreglo(float array[], int n);
void mostrar_arreglo(float array[], int n);
void recorre_x_puntero(float *p, int n);

//a)
void cargar_arreglo(float array[], int n){
    int i;
    for (i=0;i<n;i++){
        printf("Ingrese un numero: ");
        scanf("%f",&array[i]);
    }
}

void mostrar_arreglo(float array[], int n){
    int i;
    printf("[ ");
    for (i=0;i<n;i++){
        printf("%f ", array[i]);
    }    
    printf("]");
}

//d
void recorre_x_puntero(float *p, int n){
    int i;
    for (i=0;i<n;i++){
        printf("direccion: %x -> %f\n", p+i, *(p+i));
    }    
}

int main(){
    int n=15;
    float array[n], *puntero; //b
    cargar_arreglo(array,n); //a
    mostrar_arreglo(array,n); //a

    puntero=array; //c
    printf("\n\npunto d): \n\n");
    recorre_x_puntero(puntero,n);

    return 1;
}