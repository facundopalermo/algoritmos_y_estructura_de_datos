#include <stdio.h>
#include <stdlib.h>
//Ejercicio 2
int main()
{
    int dia_max,i;
    float cotizacion,cot_max;
    for(i=1;i<31;i++) //para 30 d�as
    {
        printf("Ingrese el valor del dolar para el d�a %d: ",i);
        scanf("%f",&cotizacion);
        if (i==1)
        {
            dia_max=i;
            cot_max=cotizacion;
        }else{
            if (cotizacion>cot_max)
            {
                cot_max=cotizacion;
                dia_max=i;
            }
        }
    }
    printf("El dia %d fue el de mayor cotizacion (%f)",dia_max,cot_max);
    return 0;
}