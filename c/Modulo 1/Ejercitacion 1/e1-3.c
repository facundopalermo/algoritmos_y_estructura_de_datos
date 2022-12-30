#include <stdio.h>
#include <stdlib.h>
//Ejercicio 3
int main()
{
    int ano,max_ano=0,autos=0,max_auto=0,total=0;
    for(ano=2011;ano<2020;ano++)
    {
        printf("Ingrese la cantidad de autos vendidos en el a�o %d: ",ano);
        scanf("%d",&autos);
        total+=autos;
        if(ano==2011)
        {
            max_ano=ano;
            max_auto=autos;
        }else{
            if (max_auto<autos)
            {
                max_ano=ano;
                max_auto=autos;
            }
        }
    }
    printf("El a�o que se vendieron la mayor cantidad de autos fue en el %d\n",max_ano);
    printf("La cantidad total de autos vendidos es de %d autos",total);
    return 0;
}