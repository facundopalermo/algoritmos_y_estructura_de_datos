//2. Leer un texto carácter a carácter, terminado en PUNTO. Mostrar el texto con un blanco y eliminando las palabras de 1 letra.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void ingresar_dato();

void ingresar_dato(){
    char c,aux;
    int cont=0;
    printf("Ingrese un texto y terminelo con un punto: ");
    c=getchar();
    while (c!='.'){
        if (c!=' '){
            cont++;
        }     
        if (cont>1){
            putchar(aux);
            printf(" ");
        }
        if (c==' '){
            cont=0;
        }   
        aux=c;
        c=getchar();
    }
    if (c=='.' && cont>1){
        putchar(aux);
    }
}

int main(){
    ingresar_dato();
    return 1;
}