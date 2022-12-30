#include <stdio.h>
#include <stdlib.h>

typedef struct vertice {
	int id;
    int visitado;
	struct conexion *subLista;
	struct vertice *sigVertice;
} nodo;

typedef struct conexion {
    int id;
	struct conexion *sigrel;
} nodosec;


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
int dfs(nodo *aux, nodo *p, int *ultimo);
int aristas(nodo *principal);
void visitadosEnCero(nodo *p);
int haybucle(nodo *p);
void Euleriano (nodo *p);
void hayciclo(nodo *p);
void cargarGrafoEjemplo(nodo *p);

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
        printf("3. Agregar/modificar relacion entre vertices\n"); //remplaza
        printf("4. Mostrar vertices\n");
        printf("5. Eliminar vertice\n");
        printf("6. Ver si el grafo tiene ciclos\n");
        printf("7. Determinar si el grafo tiene camino y/o ciclo Euleriano\n");
        printf("8. Generar grafo con camino euleriano pero sin ciclo euleriano\n");
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
                printf("Verificando si hay ciclo...:\n");
                hayciclo(primero);
                
                break;
            case 7:
                Euleriano(primero);
                break;

            case 8:
                cargarGrafoEjemplo(p);
                break;

            case 0:
                printf("\n\nFinalizando programa...");
                exit(0);

            default:
                printf("\n\nOpcion no valida. Ingrese una opcion entre 0 y 8");
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
    int cont_n=0, cont_impar=0;

    while(principal->sigVertice!=NULL){
        vertices++;
        sublista=principal->subLista;

        if(principal->subLista!=NULL){
            
            while(sublista->sigrel!=NULL){
                cont_n++;
                if(principal->id==sublista->id){
                    sumaGrados+=2;
                    aristasx2+=2;
                }else{
                    sumaGrados++;
                    aristasx2++;
                }
                sublista=sublista->sigrel;
            }
            if (cont_n%2!=0){
                cont_impar++;
            }
            cont_n=0;
        }
        principal=principal->sigVertice;
    }

    if(sumaGrados==(aristasx2) || cont_impar!=1){
        return 1;
    }else{
        return 0;
    }
}

int dfs(nodo *aux, nodo *p, int *ultimo){

	nodosec *a;
    nodo *aux2;
	aux->visitado=1;
    (*ultimo)=aux->id;

    if(aux->subLista!=NULL){
        a=aux->subLista;
        while(a->sigrel!=NULL){ 
            aux2=buscarVertice(p,a->id);
			if(aux2->visitado==0){
				return 1+dfs(aux2,p, ultimo);
			}
            a=a->sigrel;
        }
    }else{
        return 0;
    }
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

void visitadosEnCero(nodo *p){
    while(p->sigVertice!=NULL){
        p->visitado=0;
        p=p->sigVertice;
    }
}

int haybucle(nodo *p){
    
    nodosec *aux;
    while (p->sigVertice!=NULL){
        aux=p->subLista;
        while (aux->sigrel!=NULL){
            if(aux->id==p->id){
                return 1;
            }
            aux=aux->sigrel;
        }
        p=p->sigVertice;
    }
    return 0;
}

void Euleriano (nodo *p){

    int r=0, grado=0, gr_pares=0, gr_impar=0;
    nodosec *aux;

    while (p->sigVertice!=NULL){
        aux=p->subLista;
        while (aux->sigrel!=NULL){
            if(p->id==aux->id){
                    grado+=2;
            }else{
                grado++;
            }
            
            aux=aux->sigrel;
        }

        if (grado!=0){

            if (grado%2==0){
                gr_pares++;
            }else{
                gr_impar++;
            }
        }else{
            gr_impar=3; //si hay un nodo aislado, subo impar.
        }
        grado=0;
        p=p->sigVertice;    
    }

    if(gr_pares>0 && gr_impar==0){
        printf("El grafo tiene camino y ciclo Euleriano\n");
    }else if(gr_pares>0 && gr_impar==2){
        printf("El grafo tiene camino Euleriano\n");
    }else{
        printf("El grafo no es Euleriano\n");
    }
}

void hayciclo(nodo *primero){
                        
    nodo *q = primero;
    int bandera=0; // para saber si hay algun vertice no visitado
    int bandera2=0; // para saber si el ulimo vertice conecta con el primero
    int bandera3=0; // para saber si hay bucles

    int ultimo;    

    visitadosEnCero(primero);

    int cont=dfs(primero,primero, &ultimo);

    nodo *nodoUltimo = buscarVertice(primero, ultimo);

    while (q->sigVertice!=NULL){
    if(q->visitado==0){
                            
        bandera=1;
    }
        q=q->sigVertice;
    }

    nodosec *sub = nodoUltimo->subLista;
                

    while (sub->sigrel!=NULL){
        if(sub->id==primero->id){
            bandera2=1;
        }
            sub=sub->sigrel;
    }
                
    bandera3=haybucle(primero);
               
    if(((cont<aristas(primero) && bandera==1) || (bandera2==0)) && (bandera3!=1)){
        printf("\nNo hay ciclos entre el primer y ultlimo nodo\n");
    }else{
        printf("\nHay ciclos\n");
    }
}



void cargarGrafoEjemplo(nodo *p){

    nodosec *s_aux;

    for (int i=1; i<6;i++){
        p->id=i;
        p->sigVertice=(nodo *)malloc(sizeof(nodo));

        p->subLista = (nodosec *)malloc(sizeof(nodosec));

        switch (i)
        {
        case 1:
            s_aux=p->subLista;
            s_aux->id=2;
            s_aux->sigrel=(nodosec *)malloc(sizeof(nodosec));
            s_aux=s_aux->sigrel;
            s_aux->id=3;
            s_aux->sigrel=(nodosec *)malloc(sizeof(nodosec));
            s_aux->sigrel->sigrel=NULL;
            break;

        case 2:
            s_aux=p->subLista;
            s_aux->id=1;
            s_aux->sigrel=(nodosec *)malloc(sizeof(nodosec));
            s_aux=s_aux->sigrel;
            s_aux->id=3;
            s_aux->sigrel=(nodosec *)malloc(sizeof(nodosec));
            s_aux=s_aux->sigrel;
            s_aux->id=4;
            s_aux->sigrel=(nodosec *)malloc(sizeof(nodosec));
            s_aux=s_aux->sigrel;
            s_aux->id=5;
            s_aux->sigrel=(nodosec *)malloc(sizeof(nodosec));
            s_aux->sigrel->sigrel=NULL;
            break;

        case 3:
            s_aux=p->subLista;
            s_aux->id=1;
            s_aux->sigrel=(nodosec *)malloc(sizeof(nodosec));
            s_aux=s_aux->sigrel;
            s_aux->id=2;
            s_aux->sigrel=(nodosec *)malloc(sizeof(nodosec));
            s_aux=s_aux->sigrel;
            s_aux->id=4;
            s_aux->sigrel=(nodosec *)malloc(sizeof(nodosec));
            s_aux=s_aux->sigrel;
            s_aux->id=5;
            s_aux->sigrel=(nodosec *)malloc(sizeof(nodosec));
            s_aux->sigrel->sigrel=NULL;
            break;

        case 4:
            s_aux=p->subLista;
            s_aux->id=2;
            s_aux->sigrel=(nodosec *)malloc(sizeof(nodosec));
            s_aux=s_aux->sigrel;
            s_aux->id=3;
            s_aux->sigrel=(nodosec *)malloc(sizeof(nodosec));
            s_aux=s_aux->sigrel;
            s_aux->id=5;
            s_aux->sigrel=(nodosec *)malloc(sizeof(nodosec));
            s_aux->sigrel->sigrel=NULL;
            break;

        case 5:
            s_aux=p->subLista;
            s_aux->id=2;
            s_aux->sigrel=(nodosec *)malloc(sizeof(nodosec));
            s_aux=s_aux->sigrel;
            s_aux->id=3;
            s_aux->sigrel=(nodosec *)malloc(sizeof(nodosec));
            s_aux=s_aux->sigrel;
            s_aux->id=4;
            s_aux->sigrel=(nodosec *)malloc(sizeof(nodosec));
            s_aux->sigrel->sigrel=NULL;
            break;
        
        default:
            break;
        }
        p=p->sigVertice;
    }
    p->sigVertice=NULL;
    printf("Grafo generado ok\n");
}