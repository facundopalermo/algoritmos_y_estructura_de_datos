//10. Leer un texto carácter por carácter terminando en PUNTO. Contar cuántas palabras con 2 letras seguidas iguales hay.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int ingresar_dato();

int ingresar_dato(){
    char a,b,c;
    int cont=0,res=0;
    printf("Ingrese un texto terminado en punto: ");
    a=getchar();
    while (a!='.'){
        b=a;
        a=getchar();
        if(a==b){
            cont++;
        }
        if (cont>0 && (a==' ' || a=='.')){
            res++;
            cont=0;
        }
    }
    return res;
}

int main(){
    printf("result: %d", ingresar_dato());
    return 1;
}