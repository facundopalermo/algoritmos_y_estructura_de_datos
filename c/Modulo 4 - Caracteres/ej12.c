//12. Ingrese un texto carácter a carácter terminado en PUNTO y repítalo agregando una ‘u’ entre cada letra ‘q’ seguida de ‘i’ o ‘e’.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void ingresar_dato();

void ingresar_dato(){
    char a,b,c;
    printf("Ingrese un texto terminado en punto: ");
    a=getchar();
    while (a!='.'){
        if (a=='q'){
            c=a;
            a=getchar();
            putchar(c);
            if (a=='i' || a=='e'){
                putchar('u');
            }
            putchar(a);
        }else{
            putchar(a);
        }
        a=getchar();
    }
}

int main(){
    ingresar_dato();
    return 1;
}