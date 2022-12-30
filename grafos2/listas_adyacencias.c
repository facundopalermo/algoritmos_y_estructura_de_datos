/*
Crear una lista con los vértices de un grafo,
y una sublista con las conexiones de esos vértices.

Es una multilista donde la lista principal tiene los vertices del grafo 
y la sublista tiene las aristas con los otros vertices.*/

#include <stdio.h>
#include <stdlib.h>

typedef struct vertice {
	int id;
    int visitado;
    int listo;
	struct conexion *subLista;
	struct vertice *sigVertice;
} nodo;

typedef struct conexion {
    int id;
	struct conexion *sigrel;
} nodosec;

typedef struct nodoPila
{
	nodo *nodo;
    struct nodoPila *nodoSig;
}pila;

pila *ini=NULL;
pila *final=NULL; 

void menu(nodo *p);
void crearGrafo(nodo *registro, nodo *primero);
nodo *buscarVertice(nodo *registro, int id);
void mostrarVertice(nodo *registro);
void agregarRelacion(nodosec *registro, nodo *p);
void mostrarRelaciones(nodosec *registro);
void agregarVertice (nodo *registro);
nodo* eliminarPriVertice(nodo* p);
void eliminarVertice(nodo *p, int id);
void limpiarRelaciones(nodosec *registro);
int esGrafo(nodo *principal);
void recorridoProfundidad(nodo *aux, nodo *p);
void insertarPila(nodo* aux);
nodo *desencolar();
int aristas(nodo *principal);

int main(){

    nodo *prim;
    prim=(nodo*)malloc(sizeof(nodo));
    prim->subLista=NULL;

    menu(prim);
}

void menu(nodo *p){
    int opcion=-1;
    int id;
    nodo *primero=p;
    primero->sigVertice=NULL;
    nodo *vertice;

    while(opcion!=0){
        printf("\nSeleccione una opcion del menu\n");
        printf("1. Crear grafo (Agregar vertices)\n");
        printf("2. Agregar mas vertices\n");
        printf("3. Agregar relacion entre vertices\n");
        printf("4. Mostrar vertices\n");
        printf("5. Eliminar vertice\n");
        printf("0. Terminar programa\n");

        if (primero->sigVertice!=NULL && esGrafo(primero)==0){
            printf("ATENCION! la lista actual no representa un Grafo! verifique los datos ingresados\n");
        }

        scanf("%d",&opcion);

        switch (opcion){
            case 1:
                crearGrafo(primero, primero);
                break;

            case 2:
                agregarVertice(primero);
                break;

            case 3:
                printf("\n\nAgregar relacion entre vertices\n");

                printf("Ingrese un numero identificador para el vertice (un negativo para finalizar): \n");
                scanf("%d", &id);
                vertice=buscarVertice(primero, id);

                while (vertice==0){
                    printf("El vector no existe.\n Ingrese un numero identificador para el vertice (un negativo para finalizar): \n");
                    scanf("%d", &id);
                    vertice=buscarVertice(primero, id);
                }
                vertice->subLista=(nodosec *)malloc(sizeof(nodosec));
                agregarRelacion(vertice->subLista, primero);
                break;

            case 4:
                printf("\n\nMostrar vertices\n");
                mostrarVertice(primero);
                break;
            
            case 5:
                    printf("Ingrese el identificador del vertice a eliminar:\n");
	                scanf("%d", &id);
                    if(primero->id==id){
                        primero=eliminarPriVertice(primero);
                    }else{
                        eliminarVertice(primero,id);
                    }
                    
                break;

            case 6:
                printf("Verificando si es ciclo...:\n");
                recorridoProfundidad(primero,primero);
                int cont=0;
                while(ini!=NULL){
                    printf("%d ",desencolar()->id);
                    cont++;
                }
                if(cont<aristas(primero)){
                    printf("\nhay ciclos");
                }
                break;

            case 0:
                printf("\n\nFinalizando programa...");
                exit(0);

            default:
                printf("\n\nOpcion no valida. Ingrese una opcion entre 0 y 4");
        }

    }
}

void crearGrafo(nodo *registro, nodo *primero){
	int id=0;
	printf("Ingrese un numero identificador para el vertice (un negativo para finalizar): \n");
	scanf("%d", &id);
    registro->sigVertice=NULL;
    registro->subLista=NULL;
    while (buscarVertice(primero, id)!=0){
        
        printf("El vector ya existe.\n Ingrese un numero identificador para el vector (un negativo para finalizar): \n");
	    scanf("%d", &id);
    }

	if (id < 0){
        return;
	}else{
        registro->id = id;
        registro->sigVertice=(nodo *)malloc(sizeof(nodo));
		crearGrafo(registro->sigVertice, primero);
    }
}

nodo *buscarVertice(nodo *registro, int id){
	if (registro->sigVertice == NULL){
		return 0;
	}else{
	    if (registro->id == id){
		    return registro;
	    }else{
	        return (buscarVertice(registro->sigVertice, id));
		}
	}
}

void mostrarVertice(nodo *registro){
    if (registro->sigVertice != NULL){
        printf("( %d )\t", registro->id);
        if(registro->subLista!=NULL){
            mostrarRelaciones(registro->subLista);
        }
        printf("\n");
        mostrarVertice(registro->sigVertice);
    }
}

void agregarRelacion(nodosec *registro, nodo *p){
	int id;
	nodosec *nuevo;

	printf("Ingrese el identificador del nodo a relacionar (negativo para finalizar):\n");
	scanf("%d", &id);

    while ((buscarVertice(p, id)==0) && (id>0)){
        
        printf("El vertice a relacionar no existe.\n Ingrese el identificador del nodo a relacionar (negativo para finalizar): \n");
	    scanf("%d", &id);
    }

	if (id < 0){
		registro->sigrel=NULL;
		return;
	}else{
		registro->id=id;
		registro->sigrel=(nodosec *)malloc(sizeof(nodosec));
		agregarRelacion(registro->sigrel,p);
	}
}

void mostrarRelaciones(nodosec *registro){
    if (registro->sigrel!= NULL){
        printf(" ->[%d]",registro->id);
        mostrarRelaciones(registro->sigrel);
	}
    return;
}

void agregarVertice (nodo *registro){
    nodo *grafo = registro;

    while(registro->sigVertice!=NULL)
    {
        registro=registro->sigVertice;
    }

    crearGrafo(registro,grafo);
}

void eliminarVertice(nodo *p, int id){
    nodo *aux;

    while(p->sigVertice!=NULL&& p->sigVertice->sigVertice!=NULL)
    {
        if(p->sigVertice->id == id){
            limpiarRelaciones(p->sigVertice->subLista);
            aux=p->sigVertice->sigVertice;
            free(p->sigVertice);
            p->sigVertice=aux;

            printf ("Vertice eliminado");
        }else{
            p=p->sigVertice;
        }
    }
}

void limpiarRelaciones(nodosec *registro){
    nodosec *nodosig;

    if (registro->sigrel!= NULL){
        nodosig=registro->sigrel;
        free(registro);
        limpiarRelaciones(nodosig);
	}
    return;
}

nodo* eliminarPriVertice(nodo* p){
    nodo *aux;
    limpiarRelaciones(p->subLista);
    aux=p->sigVertice;
    free(p);
    p=aux;
    printf ("Vertice eliminado");
    return p;
}

int esGrafo(nodo *principal){

    nodosec *sublista;
    int vertices=0;
    int aristasx2=0;
    int sumaGrados=0;

    while(principal->sigVertice!=NULL){
        vertices++;
        sublista=principal->subLista;

        if(principal->subLista!=NULL){
            
            while(sublista->sigrel!=NULL){
                if(principal->id==sublista->id){
                    sumaGrados+=2;
                    aristasx2+=2;
                }else{
                    sumaGrados++;
                    aristasx2++;
                }
                sublista=sublista->sigrel;
            }
        }
        principal=principal->sigVertice;
    }

    if(sumaGrados==(aristasx2)){
        return 1;
    }else{
        return 0;
    }
}

void recorridoProfundidad(nodo *aux, nodo *p){

	nodosec *a;
    nodo *aux2;
	aux->visitado=1;
    if(aux->subLista!=NULL){
        a=aux->subLista;
        while(a!=NULL){ 
            aux2=buscarVertice(p,a->id);
			if(aux2->visitado==0){
				recorridoProfundidad(aux2,p);
			}
            a=a->sigrel;
        }
    }
    aux->listo=1;
    insertarPila(aux);

}

void insertarPila(nodo* aux){
	pila *nuevo=(pila*)malloc(sizeof(pila));
	nuevo->nodo=aux;
	nuevo->nodoSig=NULL;
	if(ini==NULL){
		ini=nuevo;
		final=nuevo;
	}else{
	   nuevo->nodoSig=ini;
	   ini=nuevo;    	
	}
}

nodo *desencolar(){
	pila *aux;
	if(ini==NULL){
		return NULL;
	}else{
		aux=ini;
		ini=ini->nodoSig;
		aux->nodoSig=NULL;
		if(ini==NULL)
		final=NULL;
	}
	nodo *resultado=aux->nodo;
	free(aux);
	return resultado;
}

int aristas(nodo *principal){

    nodosec *sublista;
    int aristasx2=0;

    while(principal->sigVertice!=NULL){
        sublista=principal->subLista;

        if(principal->subLista!=NULL){
            
            while(sublista->sigrel!=NULL){
                if(principal->id==sublista->id){
                    aristasx2+=2;
                }else{
                    aristasx2++;
                }
                sublista=sublista->sigrel;
            }
        }
        principal=principal->sigVertice;
    }
    return aristasx2/2;
}

/*
void reiniciar(){
	Nodo*aux=inicio;
		while(aux!=NULL){
			aux->visitado=aux->terminado=0;
		    aux=aux->siguiente;
		}
	}
}*/

