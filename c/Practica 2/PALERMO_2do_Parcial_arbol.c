#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

typedef struct arbol
{
    int dato;
    struct arbol *izq;
    struct arbol *der;
}treenode;

void crear (treenode **hoja);
void insertar(treenode **hoja, int elem);
void mostrar (treenode *hoja,int raiz,int *mayor, int *impares, int *pares);

int main ()
{
    int mayor, impares=0, pares=0;
    printf ("arboles\n");
    treenode* arbol=NULL;

    crear (&arbol);
    printf ("**************\n");
    //printf ("mostrar arbol\n");
    printf ("resultado\n");
    printf ("***************\n");
    mayor=arbol->dato;
    mostrar (arbol,arbol->dato,&mayor,&impares,&pares);

    printf("\nElemento mayor multiplo de la raiz: %d\n", mayor);
    printf("nodos hojas impares: %d\n",impares);
    printf("nodos hojas pares: %d\n",pares);
    return 0;
}

void crear (treenode **hoja)
{
    int numero;

    printf ("ingrese numero\n");
    scanf ("%d",&numero);
    while (numero!=-1)
    {
        insertar(&(*hoja),numero);
        printf ("ingrese numero\n");
        scanf ("%d",&numero);
    }
}

void insertar (treenode **hoja,int elem)
{
    int numero=elem;
    if (elem==-1)
        return;

    if (*hoja==NULL)
    {
        //creo la hoja vacia
        (*hoja)=(treenode*)malloc(sizeof(treenode));
        (*hoja)->dato=elem;
        (*hoja)->der=NULL;
        (*hoja)->izq=NULL;
    }else{
        if (numero>(*hoja)->dato)
        {

            insertar (&(*hoja)->der,elem);

        }
        else
        {

            insertar (&(*hoja)->izq,elem);
        }
    }
return;
}

void mostrar (treenode *hoja,int raiz,int *mayor, int *impares, int *pares)
{
    if (hoja!=NULL)
    {
        mostrar(hoja->izq, raiz, mayor, impares, pares);
        //printf("%d ",hoja->dato);
        if (hoja->dato%raiz==0 && hoja->dato>*mayor){
            *mayor=hoja->dato;
        }

        if(hoja->izq==NULL && hoja->der==NULL && hoja->dato%2!=0){
                (*impares)++;
        }

        if (hoja->dato%2==0){
            (*pares)++;
        }
        mostrar(hoja->der,raiz, mayor, impares, pares);
    }
    return;
}