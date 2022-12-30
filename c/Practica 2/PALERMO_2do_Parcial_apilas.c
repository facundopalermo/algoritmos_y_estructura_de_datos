#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define CANT 4

typedef struct tiponodo
{
	int num;

    struct tiponodo *siguiente;
}nodo;


void mostrar (nodo aux, int primero, int *productoria, int *cont);
nodo* crear_nodo(int dato );
void apilar(nodo** p, nodo* u);
nodo desapilar(nodo** p);

void mostrar (nodo aux, int primero, int *productoria, int *cont)
{
    //printf("%d \n", aux.num);
    if (aux.num%primero==0){
        (*productoria)*=aux.num;
        (*cont)++;
    }
}

nodo* crear_nodo(int dato )
{
   nodo* u;
   u = (nodo *)malloc(sizeof(nodo));
   u->num = dato;

   u->siguiente = NULL;

   return u;
}

void apilar(nodo** p, nodo* u)
{
    printf("apilar_nodo\n");

  	u->siguiente = *p;
  	printf("%02d p=%X u=%X\n", u->num, *p, u);
	*p = u;
}

nodo desapilar(nodo** p)
{
	nodo* aux;
    nodo datos;

	datos=**p;

	aux=*p;

	*p=(*p)->siguiente;
	free(aux);

    return datos;
}

int main()
{


   int i,num, primero, pruductoria=1,cont=0;
   nodo* p=NULL;

   for(i=0; i<CANT; i++)
   {
   	printf("Ingrese un numero \n");
   	scanf("%d",&num);
    if(i==0){
    primero=num;
    }

   	apilar(&p, crear_nodo(num));
   }

   printf("\nVamos a desapilar todo\n");
	while(p!=NULL)
   {
    	mostrar(desapilar(&p), primero, &pruductoria, &cont);
   }

    if (cont>0){
        printf("productoria: %d",pruductoria);
    }else{
        printf("No habia numeros multiplos de %d",primero);
    }
   
   //getch();
   return 0;
}
