// 3. Leer un texto carácter a carácter, terminado en PUNTO. Mostrar cuántas palabras tienen más de 2 letras y terminan con “s”.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void ingresar_dato();

void ingresar_dato(){
    char c,aux;
    int cont=0,cont2=0;

    printf("Ingrese un texto y terminelo con un punto: ");
    c=getchar();

    while (c!='.'){
        if (c!=' '){
            cont++;
            aux=c;
        }else{
            if (cont>2 && aux=='s'){
                cont2++;
            }
            cont=0;
        }
        c=getchar();
    }
    if (c=='.' && cont>2 && aux=='s'){
        cont2++;
    }
    printf("Hay %d palabras con mas de 2 letras y terminadas en s",cont2);
}

int main (){
    ingresar_dato();
    return 1;
}