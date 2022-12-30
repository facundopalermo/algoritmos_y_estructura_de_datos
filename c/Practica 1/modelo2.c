#include <stdio.h>
#include <stdlib.h>

typedef struct lista{
	int num;
	struct lista *sig;
}nodo;

void crear (nodo *registro,int cont);
void mostrar (nodo *registro);
void lista_mult_tres(nodo *original, nodo *copia);
nodo *sumo_agrego_elimino(nodo *registro);
void eliminar2(nodo* p);
nodo* insertar1(nodo *p);
void insertar2 (nodo *p);


void crear (nodo *registro,int cont)
{
    printf("Ingrese un numero entero: ");
    scanf("%d",&registro->num);

    if (registro->num==1000)
        registro->sig=NULL;
    else
	{
        registro->sig=(nodo*)malloc(sizeof(nodo));
        crear (registro->sig,cont);
	}
	return;
}

void mostrar (nodo *registro)
{
    if (registro->sig !=NULL)
	{
        printf ("%d\n",registro->num);
        mostrar (registro->sig);
	}
	return;
}

nodo *sumo_agrego_elimino(nodo *registro){
    nodo *prim=registro;
    if (registro->num+registro->sig->num > 20){
        prim=insertar1(registro);
    }

    while(registro->sig!=NULL && registro->sig->sig!=NULL && registro->sig->sig->sig!=NULL){
        if(registro->sig->num+registro->sig->sig->num > 20){
            insertar2(registro);
            registro=registro->sig;
        }else if(registro->sig->num+registro->sig->sig->num < 10){
            eliminar2(registro->sig);
        }
        registro=registro->sig;
    }
    return prim;
}

void eliminar2(nodo* p)
{
    nodo *aux;
    aux=p->sig->sig;
    free(p->sig);
    p->sig=aux;
}

nodo* insertar1(nodo *p)
{
    nodo *aux;
    if(1==1)//condicion de insercion
    {
        aux=(nodo *)malloc(sizeof(nodo));
        aux->num=0;//valor a insertar
        aux->sig=p;
        p=aux;
    }
    return p;
}

void insertar2 (nodo *p)
{
    nodo *aux;
    aux=(nodo *)malloc(sizeof(nodo));
    aux->num=0;//valor a insertar
    aux->sig=p->sig;
    p->sig=aux;
}

void lista_mult_tres(nodo *original, nodo *copia){
    while (original->sig!=NULL){
        if (original->num%3==0){
            copia->num=original->num;
            copia->sig=(nodo*)malloc(sizeof(nodo));
            copia=copia->sig;
        }
        original=original->sig;
    }
    copia->num=1000;
    copia->sig=NULL;
}

int main(){
    int i=0;
    nodo *prin=NULL;
    prin=(nodo*)malloc(sizeof(nodo));
    nodo *copia=NULL;
    copia=(nodo*)malloc(sizeof(nodo));

    crear(prin,i);
    printf("Muestro lista orignal:\n");
    mostrar(prin);
    lista_mult_tres(prin,copia);
    printf("Muestro lista copia con multiplos de 3:\n");
    mostrar(copia);
    prin=sumo_agrego_elimino(prin);
    printf("Muesto lista punto c):\n");
    mostrar(prin);
    return 1;
}