#include <stdio.h>
#include <stdlib.h>

int main(){
    int c;
    printf("ingrese la frase\n");
    c=getchar();
    putchar(c);
    while(c!='.'){
        while(c==' '){
            c=getchar();
            putchar(c);
        }
        while (c!=' ' && c!='.'){
            c=getchar();
            putchar(c);
        }
    }
    return 0;
}
/*
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int c, contador1=0, contador2=0;
    printf("Ingrese la frase\n");

    c = getchar();
    putchar(c);

    while (c != '.')
    {
        
        while (c == ' ')
        {
            contador1 = 0;
            c = getchar();
            putchar(c);
        }
        
        while (c != ' ' && c != '.')
        {
            contador1++;
            c = getchar();
            putchar(c);
        }

        if (contador1 > 3)
        {
            contador2++;
        }
    }

    printf("Hay %d palabras con mas de 3 letras\n", contador2);

    return 0;
}
*/