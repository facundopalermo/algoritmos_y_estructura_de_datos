//Diseñar un algoritmo recursivo que permita calcular convertir un número decimal en su valor hexadecimal (base 16).
#include <stdio.h>
#include <stdlib.h>


void toHexa (int num, int array[], int i);

void toHexa (int num, int array[], int i){
    if (num < 16){
        array[i]=num;
    } else {
        array[i]=num % 16;
        return toHexa (num/16, array, i-1);
    }
}

/*
void aHexadecimal(int n){
    if (n > 15){
        aHexadecimal(n/16);
    }
    printf("%X", n%16);
}
*/

int main (){
    int array[20];
    for(int i=0;i<20;i++){
        array[i] = 17; 
    }

    toHexa ( 65029, array, 19 );

    for (int i=0; i<20; i++){
        if (array[i]!=17){
            printf("%X", array[i]);
        }
    }
}
