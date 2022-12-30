//aronisim@gmail.com Adrian Nisim
//panani@palermo.edu Pablo Anania

#include <stdio.h> //librerias, esta va siempre
#define DIM 10 //constante

//se puede declarar fuera de las funciones variables, y serían globales, pero NO USARLO

int main()
{
    int numero=10, num=0; //las instrucciones terminan con ;*/
    char letra='a';
    
    int vector[10], i; //no importa si son vec o var
    /*int i
    printf("numero es igual a %d %c \n",numero,letra);
    numero=5;
    Para pedir el ingreso de un dato, primero el printf para mostrar mensaje en consola
    printf("Ingree un valor: "); 
    sacanf("%d",&numero); es el input en C requiere tipo y variable

    */
    for(i=0;i<10;i++)
    {
        printf("Ingrese el %02d ° valor: ",i+1); //%02d para mostrar los enteros(d) con dos digitos, 1 --> 01, 10 -->10
        scanf("%d",&vector[i]);
    }

    /*for(i=0;i<10;i++)
    {
        printf("el %02d ° valor: %d \t",i+1,vector[i]);
    }*/

    i=0; //porque lo voy a usar a continuación
    while(i<10 && i>=0){ // && and , || or , != distinto, ==, etc
        printf("%d \n", vector[i]);
        i++;
    }
    printf("Continuar...");
    scanf("");

    return 0;


}


/*
int --> %d
char--> %c
char cadena[20]-->%s 
float --> %f


\n--> salto de linea
\t--> tabulacion

printf("%x",&i) muestra en hexa la posicion de la momoria de i
*/