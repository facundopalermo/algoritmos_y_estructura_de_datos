// 5. Leer un texto carácter a carácter terminado en PUNTO. Contar cuantas palabras empiezan y terminan con la misma letra.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void ingresar_dato();

void ingresar_dato(){
    char c,p,u;
    int cont=0;
    printf("ingrese un texto terminado en punto: ");
    c=getchar();
    if(c!=' ' && c!='.'){
        p=c;
    }
    while (c!='.'){
        if (c==' '){
            if (p==u){
                cont++;
            }
            p=getchar();
        }else{
            u=c;
        }
        c=getchar();
    }
    if (c=='.' && p==u){
        cont++;
    }
    printf("La cantidad de palabras que empiezan y terminan con la misma letra es %d palabras",cont);
}

int main(){
    ingresar_dato();
    return 1;
}