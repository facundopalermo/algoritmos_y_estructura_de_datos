#include <stdio.h>
#include <stdlib.h>

#include <string.h>  // ←← 

int main(){
    
    char c,b,a,aux;
    int cont=0;

    printf("Ingresa un texto: ");
    c=getchar();
    b=getchar();
    a=getchar();

    /*while (c!='.'){
        
        if(c==' '){

        }
        c=getchar();

    }*/

    putchar(c);
    putchar(b);
    putchar(a);
    aux=c;
    putchar(aux);
    return 1;

}

