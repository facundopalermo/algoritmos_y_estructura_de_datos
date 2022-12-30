#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define CANT 10

typedef struct tiponodo
{
	int num;

    struct tiponodo *siguiente;
}nodo;

void mostrar (nodo aux, int *cont, int *sum);
nodo* crear_nodo(int dato);
void acolar(nodo** p,nodo** u, nodo *q);
nodo desacolar(nodo** inicio);

void mostrar (nodo aux, int *cont, int *sum)
{
  	//printf("%d \n", aux.num);
   if (aux.num>6){
      (*cont)++;
      *sum+=aux.num;
   }
}

nodo* crear_nodo(int dato)
{
   nodo* u;
   u = (nodo *)malloc(sizeof(nodo));

   u->num = dato;

   u->siguiente = NULL;

   return u;
}

void acolar(nodo** p,nodo** u, nodo *q)
{
   printf("acolar_nodo\n");
	if(*p==NULL)
    *p = *u = q; /*porque hay uno solo*/
   else
   {
    	(*u)->siguiente = q;
    	(*u) = q;
   }
  	printf("%02d p=%X u=%X\n", q->num, *p, *u);
}

nodo desacolar(nodo** inicio)
{
	nodo* aux;
   nodo datos;

	datos=**inicio;

	aux=*inicio;

	*inicio=(*inicio)->siguiente;
	free(aux);

    return datos;
}

int main()
{
   int i,num,cont=0,sum=0;
   nodo* p=NULL;
   nodo* u=NULL;

   for(i=0; i<CANT; i++)
   {
       printf("Ingrese un numero");
       scanf("%d",&num);
        acolar(&p, &u, crear_nodo(num));

   }

   printf("\nVamos a desacolar todo\n");
	while(p!=NULL)
   {
    	mostrar(desacolar(&p),&cont,&sum);
   }

   if (cont>0){
      printf("el promedio de los numeros menores a 6: %d",sum/cont);
   }else{
      printf("no hay numero menores a 6");
   }
   return 0;
}
