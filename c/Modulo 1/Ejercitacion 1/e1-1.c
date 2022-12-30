#include <stdio.h>
#include <stdlib.h>
//Ejercicio 1
int main()
{
    float peso, estatura, imc;

    printf("Ingrese el peso en kg: ");
    scanf("%f",&peso);
    while (peso<=0)
    {
        printf("El peso debe ser mayor a 0. Ingrese el peso en kg: ");
        scanf("%f",&peso);
    }
    printf("Ingrese la estatura en mts: ");
    scanf("%f",&estatura);
    while (estatura<0.35)
    {
        printf("La estatura debe ser superior a 0.35mts. Ingrese una estatura v�lida: ");
        scanf("%f",&estatura);
    }
    imc=peso/(estatura*estatura);
    printf("El IMC es: %f",imc);
    return 0;
}