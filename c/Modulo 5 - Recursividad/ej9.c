#include <stdio.h>
#include <stdlib.h>
//Cargar un vector con n elementos enteros y calcular el promedio de sus elementos
//en forma recursiva.
void cargar(int v[], int n);
float prom(int v[], int n, int su);


int main(){
int v[6];
int n=0;
int su=0;
cargar(v,n);
for(int i =0; i<6;i++){
    printf("%d  ", v[i]);
}
printf("\n prom:: \n");

printf("\n fin: %f",prom(v,n, su));
}

void cargar(int v[], int n){
    if(n==6){
        return;
    }else{
        printf("Ingrese un numero\n");
        scanf("%d", &v[n]);
        printf("aaaa %d\n",v[n]);
        cargar(v, n+1);
    }
}
float prom(int v[], int n, int su){
    if(n==6){
        return su/(6);
    }else{
        su+=v[n];
        prom(v,n+1,su);

    }
}