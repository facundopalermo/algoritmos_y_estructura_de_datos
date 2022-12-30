//16. Leer un texto carácter por carácter terminando en punto. Reemplazar grupos “y” por “ll”.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int ingresar_dato();

int ingresar_dato(){
    char a,b,c;
    printf("Ingrese un texto terminado en punto: ");
    a=getchar();
    while (a!='.'){
        if (a=='y'){
            putchar('l');
            putchar('l');
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