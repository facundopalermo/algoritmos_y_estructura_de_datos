// 6. Leer un texto carácter a carácter, terminado en PUNTO. Mostrar el texto intercambiando la última letra con la anteúltima de las palabras de 2 o más letras.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void ingresar_dato();

void ingresar_dato(){
    char a,b,c;

    int j=0;
    printf("Ingrese un texto terminado en punto: ");
    a=getchar();
    b=NULL;
    while (a!='.'){
        c=b;
        b=a;
        a=getchar();
        if (a==' ' && c==' '){
            putchar(c);
        }else if(a==' ' || a=='.'){
            putchar(b);
            putchar(c);
            j=1;

        }else{
            if (j!=1){
                putchar(c);
            }else{
                j=0;
            }
        }
    }    
}

int main(){
    ingresar_dato();
    return 1;
}