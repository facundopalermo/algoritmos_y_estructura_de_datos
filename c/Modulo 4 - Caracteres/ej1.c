//1. Leer un texto carácter a carácter, terminado en PUNTO. Mostrar cuántas palabras tienen más de 3 letras.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void ingresar_dato();

void ingresar_dato(){
    char c;
    int cont1=0,cont2=0;

    printf("Ingrese un texto y terminelo con un punto: ");
    c=getchar();
    while (c!='.'){
        cont1++;
        if (c==' '){
            if (cont1>4){
                cont2++;
            }
            cont1=0;
        }
        c=getchar();
    }
    if (cont1>3 && c=='.'){
        cont2++;
    }
    printf("Hay %d palabras con mas de 3 letras",cont2);
}

int main(){
    ingresar_dato();
    return 1;
}