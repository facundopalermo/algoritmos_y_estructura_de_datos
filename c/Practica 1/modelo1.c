#include <stdio.h>
#include <stdlib.h>

typedef struct lista{
	int num;
	struct lista *sig;
 }nodo;

void crear (nodo *registro,int cont);
void mostrar (nodo *registro);
void crear_impares (nodo *registro,nodo *nueva, int cont);
void elimina_menores_promedio(nodo *registro, nodo *nueva, int cont);
float promedio (nodo *registro);
nodo* eliminar1(nodo* p,float prom);
void eliminar2(nodo* p,float prom);

//Modelo original
void crear (nodo *registro,int cont)
{
    printf("Ingrese un numero entero: ");
    scanf("%d",&registro->num);

    if (registro->num==-2)
        registro->sig=NULL;
    else
	{
        registro->sig=(nodo*)malloc(sizeof(nodo));
        crear (registro->sig,cont);
	}
	return;
}

void crear_impares (nodo *registro,nodo *nueva, int cont)
{
    if(registro->sig!=NULL){
        if(registro->num%2!=0){
            nueva->num=registro->num;
            nueva->sig=(nodo*)malloc(sizeof(nodo));
            cont++;
            crear_impares(registro->sig,nueva->sig,cont);
        }else{
            crear_impares(registro->sig,nueva,cont);
        }
    }else{
        //si hay impares, agrego nodo final, si no le doy valor al unico
        if (cont!=0){
            nueva->sig=(nodo*)malloc(sizeof(nodo));
            nueva->sig=NULL;
            nueva->num=-2;
        }else{
            //para que al mostrar no entre en un bucle infinito por no exitir sig==null
            nueva->sig=NULL;
            nueva->num=-2;
        }
    }
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

float promedio (nodo *registro)
{
    int suma=0,cont=0;
    while (registro->sig!=NULL){
        suma+=registro->num;
        cont++;
        registro=registro->sig;
    }
    return suma/cont;
}

nodo* eliminar1(nodo* p,float prom)
{
    nodo *aux;
    while(p->num<prom)//condicion de eliminacion
    {
        aux=p->sig;
        free(p);
        p=aux;

    }
    return p;
}

void eliminar2(nodo* p,float prom)
{nodo *aux;
    while(p->sig != NULL && p->sig->sig != NULL)
    {
        if(p->sig->num<prom)//condicion de eliminacion
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

int main()
{
    int i=0;
    float prom;

    nodo *prin=NULL;
    nodo *prin2=NULL;

    prin=(nodo*)malloc(sizeof(nodo));
    prin2=(nodo*)malloc(sizeof(nodo)); // nueva lista para impares

    crear(prin,i);
    printf("Lista Original:\n");
    mostrar (prin);
    printf("Lista con impares:\n");
    crear_impares(prin,prin2,i);
    mostrar(prin2);
    
    prom=promedio(prin);
    prin2=eliminar1(prin2,prom);
    eliminar2(prin2,prom);
    printf("Lista con impares sin menores a %f:\n",prom);
    mostrar(prin2);
    return 0;
}