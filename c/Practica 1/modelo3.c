#include <stdio.h>
#include <stdlib.h>

typedef struct lista{
    int coef;
    int pot;
    struct lista *sig;
}nodo;

void crear (nodo *registro,int cont);
void mostrar (nodo *registro);
void completar(nodo *p);
void insertar2 (nodo *p,int pot);
void suma_listas(nodo *lista1, nodo *lista2, nodo *suma);

void crear (nodo *registro,int cont)
{
    printf("Ingreso polinomio n%d (potencias de mayor a menor)\n",cont);
    printf("Ingrese el coeficiente: ");
    scanf("%d",&registro->coef);
    printf("Ingrese la potencia: ");
    scanf("%d",&registro->pot);

    if (registro->pot==-1)
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
        printf ("%d^%d\t",registro->coef,registro->pot);
        mostrar (registro->sig);
	}
	return;
}

void completar(nodo *p){
    while (p->sig!=NULL){
        if(p->pot-1==p->sig->pot){
        }else{
            insertar2(p,p->pot-1);
        }
        p=p->sig;
    }
}

void insertar2 (nodo *p,int pot)
{
    nodo *aux;
    aux=(nodo *)malloc(sizeof(nodo));
    aux->coef=0;//valor a insertar
    aux->pot=pot;
    aux->sig=p->sig;
    p->sig=aux;
}

void suma_listas(nodo *lista1, nodo *lista2, nodo *suma){
    while (lista1->sig!=NULL && lista2->sig!=NULL){
        if (lista1->pot>lista2->pot){
            suma->coef=lista1->coef;
            suma->pot=lista1->pot;
            suma->sig=(nodo*)malloc(sizeof(nodo));
            lista1=lista1->sig;

        }else if (lista1->pot<lista2->pot){
            suma->coef=lista2->coef;
            suma->pot=lista2->pot;

            suma->sig=(nodo*)malloc(sizeof(nodo));
            lista2=lista2->sig;

        }else if (lista1->pot==lista2->pot){
            suma->coef=lista1->coef+lista2->coef;
            suma->pot=lista2->pot;
            suma->sig=(nodo*)malloc(sizeof(nodo));
            lista2=lista2->sig;
            lista1=lista1->sig;
        }
    }
    suma->sig=NULL;
    suma->coef=-1;
    suma->pot=-1;
}

int contar_nodos(nodo *p){
    int cont=0;
    while (p->sig!=NULL){
        cont++;
        p=p->sig;
    }
    return cont;
}

int main(){
    int i=0;

    nodo *lista1=NULL; //polinomio 1
    lista1=(nodo*)malloc(sizeof(nodo));

    nodo *lista2=NULL; //polinomio 2
    lista2=(nodo*)malloc(sizeof(nodo));

    nodo *lista3=NULL; //suma de polinomios
    lista3=(nodo*)malloc(sizeof(nodo));

    crear(lista1,1);
    crear(lista2,2);
    printf("\nPolinomio 1 sin procesar:\n");
    mostrar (lista1);
    printf("\nPolinomio 2 sin procesar:\n");
    mostrar (lista2);
    completar(lista1);
    completar(lista2);
    printf("\nPolinomio 1 procesado:\n");
    mostrar(lista1);
    printf("\nPolinomio 2 procesado:\n");
    mostrar(lista2);
    suma_listas(lista1,lista2,lista3);
    printf("\nSuma de las listas:\n");
    mostrar(lista3);


    return 0;
}
