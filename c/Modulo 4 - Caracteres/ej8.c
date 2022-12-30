//8. Ingresar un texto carácter a carácter terminado en PUNTO. Contar cuantas palabras empiezan con la anteúltima letra de la palabra anterior. 
//En palabras de 1 sola letra deberá tomar esta única letra como anteúltima.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int ingresar_dato();

int ingresar_dato(){
    char a,b,c;
    int cont=0;
    printf("Ingrese un texto terminado en punto: ");
    a=getchar();
    b=' ';
    while (a!='.'){
        c=b;
        b=a;
        a=getchar();
        if (c==' ' && a==' '){
            c=b;
        }
        if (a==' '){
            b=a;
            a=getchar();
        }
        if (c==a){
            cont++;
        }
    }
    return cont;
}

int main(){
    printf("%d palabras empiezan con la anteúltima letra de la palabra anterior", ingresar_dato());
    return 1;
}