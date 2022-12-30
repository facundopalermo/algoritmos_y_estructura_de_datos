#include <stdio.h>
#include <stdlib.h>


typedef struct lista{
	int anio, peso;
    float altura;

	struct lista *sig;
 }nodo;


typedef struct lista2{
	int anio, indice;

	struct lista2 *sig;
 }nodo2;

typedef struct lista3{
	int anio, peso, indice;
    float altura;

	struct lista3 *sig;
 }nodo3;

void crear (nodo *p);
void mostrar(nodo *p);
nodo* insertar1(nodo* );
nodo* eliminar1(nodo* );
void insertar2 (nodo2* p2);
void eliminar2(nodo* );
void crear2( nodo *p,nodo2 *p2);
void crear3(nodo *p,nodo3 *p3);
void mostrar2 (nodo2 *registro);
void mostrar3 (nodo3 *registro);


int main()
{

    nodo *prin=NULL;
    prin=(nodo*)malloc(sizeof(nodo));
    nodo2 *p2=NULL;
    p2=(nodo2*)malloc(sizeof(nodo2));
    nodo3 *p3=NULL;
    p3=(nodo3*)malloc(sizeof(nodo3));
    crear(prin);
    mostrar (prin);
    crear2(prin,p2);
    mostrar2(p2);
    insertar2(p2);
    mostrar2(p2);
    crear3(prin,p3);
    mostrar3(p3);
    prin=eliminar1(prin);
    eliminar2(prin);
    mostrar(prin);

    return 0;
}


void crear3(nodo *p,nodo3 *p3){
    int ind;
    while(p->sig!=NULL){
        ind=p->peso/(p->altura*p->altura);
        if(ind>25){
            p3->altura=p->altura;
            p3->anio=p->anio;
            p3->indice=ind;
            p3->peso=p->peso;

            p3->sig=(nodo3*)malloc(sizeof(nodo3));
            p3=p3->sig;
            p=p->sig;
        }
    }
    p3->sig=NULL;


}

void crear2(nodo *p,nodo2 *p2){
    int ind;
    while(p->sig!=NULL){
        ind=p->peso/(p->altura*p->altura);
        p2->indice=ind;
        p2->anio=p->anio;
        p2->sig=(nodo2*)malloc(sizeof(nodo2));
        p2=p2->sig;
        p=p->sig;
    }
    p2->sig=NULL;
}

void crear (nodo *registro)
{
    
    printf("Anio: \n");
    scanf("%d",&registro->anio);
    printf("Peso: \n");
    scanf("%d",&registro->peso);
    printf("Altura: \n");
    scanf("%f",&registro->altura);

    if (registro->anio==0)
        registro->sig=NULL;
    else
	{
        registro->sig=(nodo*)malloc(sizeof(nodo));
        crear (registro->sig);

	}
	return;
}

void mostrar (nodo *registro)
{
    if (registro->sig !=NULL)
	{
        printf ("[%d]",registro->anio);
        printf ("[%d]",registro->peso);
        printf ("[%f]",registro->altura);
        mostrar (registro->sig);
	}
    printf("\n");
	return;
}

void mostrar2 (nodo2 *registro)
{
    if (registro->sig !=NULL)
	{
        printf ("[%d]",registro->anio);
        printf ("[%d]",registro->indice);
        mostrar2(registro->sig);
	}
    printf("\n");
	return;
}

void mostrar3 (nodo3 *registro)
{
    if (registro->sig !=NULL)
	{
        printf ("[%d]",registro->anio);
        printf ("[%d]",registro->peso);
        printf ("[%f]",registro->altura);
        printf ("[%d]",registro->indice);
        mostrar3(registro->sig);
	}
    printf("\n");
	return;
}


void insertar2(nodo2 *p2)
{nodo2 *aux;
    while(p2->sig!=NULL)
    {
        if(p2->indice<24) //condicion de insercion
        {
            aux=(nodo2 *)malloc(sizeof(nodo2));
            aux->indice=1;//valor a insertar
            aux->anio=p2->anio;
            aux->sig=p2->sig;
            p2->sig=aux;
            printf("voy bien\n");

        }
        p2=p2->sig->sig;
    }
}

nodo* eliminar1(nodo* p)
{nodo *aux;

    while(p->anio>1960 && p->anio<1970 && p->peso/(p->altura*p->altura<25))//condicion de eliminacion
    {
        
        aux=p->sig;
        free(p);
        p=aux;

    }
    return p;
}

void eliminar2(nodo* p)
{nodo *aux;
    while(p->sig!=NULL&& p->sig->sig!=NULL)
    {
        if(p->anio>1960 && p->anio<1970 && p->peso/(p->altura*p->altura<25))//condicion de eliminacion
        {
            aux=p->sig->sig;
            free(p->sig);
            p->sig=aux;
        }
        else
        {
            p=p->sig;
        }
    }

}
