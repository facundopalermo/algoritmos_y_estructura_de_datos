#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
//Ejercicio 4
int main()
{
    setlocale(LC_CTYPE, "latin");
    float promedio=0;
    int e_4y25=0,cont=0,num,menor,suma6=0;

    printf("Ingrese un numero: ");
    scanf("%d",&num);
    menor=num;
    while (num>=0)
    {
        if (num>4 && num<25)
        {
            e_4y25++;
        }
        if (num%6==0)
        {
            suma6+=num;
            cont++;
        }
        if(menor>num)
        {
            menor=num;
        }
        printf("Ingrese un numero: ");
        scanf("%d",&num);
    }
    printf("Cantidad de n\xA3meros mayores a 4 y menores a 25: %d\n",e_4y25);
    if (cont>0)
    {
        promedio=suma6/cont;
        printf("Promedio de aquellos números múltiplos de 6: %.2f\n",promedio);
    }else{
        printf("No se ingresaron numeros multiplos de 6\n");
    }
    printf("El menor numero leido: %d",menor);
    return 0;
}