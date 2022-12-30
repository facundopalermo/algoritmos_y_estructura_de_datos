//14. Leer un texto carácter por carácter terminando en PUNTO. Contar grupos "TA". Mostrar reemplazando por “TE”.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int ingresar_dato();

int ingresar_dato(){
    char a,b,c;
    int cont=0;
    printf("Ingrese un texto terminado en punto: ");
    a=getchar();
    while (a!='.'){
        if (a=='T'){
            c=a;
            a=getchar();
            putchar(c);
            if (a=='A'){
                putchar('E');
                cont++;
            }
        }else{
            putchar(a);
        }
        a=getchar();
    }
    return cont;
}

int main(){
    int a;
    a=ingresar_dato();
    if (a>0){
        printf("\nSe cambiaron %d TA por TE.",a);
    }else{
        printf("\nNo habia TA para remplazar por TE.");
    }
    return 1;
}