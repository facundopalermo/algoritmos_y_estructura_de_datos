#include <stdio.h>
#include <stdlib.h>

typedef struct lista{
	int num;
	struct lista *sig;
 }nodo;

void crear (nodo *registro,int cont);
void mostrar (nodo *registro);
nodo* eliminar1(nodo* p, int n);
void eliminar2(nodo* p, int n1, int n2);
int contar_nodos(nodo *p);
void insertar2 (nodo *p, int n);

void crear (nodo *registro,int cont)
{
    printf("Ingrese un numero: ");
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
        printf ("[%d]",registro->num);
        mostrar (registro->sig);
	}
	return;
}

nodo* eliminar1(nodo* p, int n)
{
    nodo *aux;
    int i=0;
    while(i<n)//condicion de eliminacion
    {
        aux=p->sig;
        free(p);
        p=aux;
        i++;
    }
    return p;
}

void eliminar2(nodo* p, int n1, int n2)
{
    nodo *aux;
    int i=1,j=0;
    while(p->sig!=NULL&& p->sig->sig!=NULL)
    {
        if(i+1==n1 && j<=(n2-n1))//condicion de eliminacion
        {
            aux=p->sig->sig;
            free(p->sig);
            p->sig=aux;
            j++;
        }
        else
        {
            p=p->sig;
            i++;
        }
    }
}

int contar_nodos(nodo *p){
    int cont=0;
    while (p->sig!=NULL){
        cont++;
        p=p->sig;
    }
    return cont;
}

/*Insertar los valores consecutivos del numero ingresado
void insertar2 (nodo *p, int n)
{
    nodo *aux;
    int j=0,i=1;
    while(p->sig!=NULL)
    {
        if(n<=i && (n-j)>=0) //condicion de insercion
        {
            aux=(nodo *)malloc(sizeof(nodo));
            aux->num=n-j;//valor a insertar
            aux->sig=p->sig;
            p->sig=aux;
            j++;
        }
        p=p->sig;
        i++;
    }
}
*/

//Insertar los valores consecutivos del nodo correspondiente al numero ingresado
void insertar2 (nodo *p, int n)
{
    nodo *aux;
    int j=1,i=1,valor_nodo;
    while(p->sig!=NULL)
    {
        if(n<=i && (valor_nodo-j)>=0) //condicion de insercion
        {
            aux=(nodo *)malloc(sizeof(nodo));
            aux->num=valor_nodo-j;//valor a insertar
            aux->sig=p->sig;
            p->sig=aux;
            j++;
            printf("j=%d",j);
        }
        p=p->sig;
        if(j==1){
            valor_nodo=p->num;
        }
        i++;
        printf("i=%d",i);
    }
}


int main(){
    int i=0,primer_numero=0,seg_numero=0,pos=0,n;
    nodo *prin=NULL;
    prin=(nodo*)malloc(sizeof(nodo));
    crear(prin,i);
    printf("\n\nLista original:\n");
    mostrar(prin);
    printf("\n\n");

    //punto a)
    while (primer_numero<=0){
        printf("Ingrese un numero enteros positivo: ");
        scanf("%d",&primer_numero);
    }
    while (seg_numero<=0 && seg_numero<primer_numero){
        printf("Ingrese otro numero entero positivo y mayor al anterior: ");
        scanf("%d",&seg_numero);
    }

    n=contar_nodos(prin);
    
    if(n>primer_numero && n>seg_numero){
        if (primer_numero==1){
            prin=eliminar1(prin,seg_numero);
        }else{
            eliminar2(prin,primer_numero,seg_numero);
        }
    }else{
        printf("Los numeros ingresados superan el rango de nodos en la lista.\n");
    }

    printf("\nLista segun punto a)\n");
    mostrar(prin);
    printf("\n\n");

    //punto b
    while (pos<=0){
        printf("Ingrese un numero entero positivo: ");
        scanf("%d",&pos);
    }
    /*desarrollé dos funciones insertar 2, una está comentada y corresponde a los conecutivos del numero ingresado.
    la activa es agrega los consecutivos del nodo correspondiente a la posicion del numero ingresado.*/
    insertar2(prin,pos);
    printf("\nLista segun punto b)\n");
    mostrar(prin);
    return 0;
}