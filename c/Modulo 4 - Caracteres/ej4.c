// 4. Leer un texto carácter a carácter, terminado en PUNTO y repetirlo reemplazando los grupos ‘vl’ por ‘bl’.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void ingresar_datos();

void ingresar_datos(){
    char c,d; 
    printf("Ingrese un texto terminado en punto: ");
    c=getchar();
    while(c!='.'){
        if(c=='v'){
            d=getchar();
            if (d=='l'){
                putchar('b');
                putchar(d);
            }else{
                putchar(c);
                putchar(d);
            }
        }else{
            putchar(c);
        }

        c=getchar();
    }
}

int main(){
    ingresar_datos();
    return 1;
}