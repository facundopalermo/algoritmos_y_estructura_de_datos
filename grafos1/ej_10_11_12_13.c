#include <stdio.h>
#include <stdlib.h>

void cargarMatriz(int matriz[][100],int n_vertices);
void mostrarMatriz(int matriz[][100], int n_vertices);
int cantidadAristas(int matriz[][100], int n_vertices); //ejercicio 10
void gradoVertices(int matriz[][100], int n_vertices); //ejercicio 11
void menu(int matriz[][100],int n_vertices); //para opciones ejercios 12, 13
void consultaAristaEntreVertices(int matriz[][100],int n_vertices); //ejercios 12
void matrizTraspuesta(int matriz[][100], int n_vertices); //ejercicio 13

int main (){

    int matriz[100][100];
    int n_vertices = 0;

    printf("Ingrese la cantidad de vertices:");
    scanf("%d",&n_vertices);
    while(n_vertices<1 || n_vertices>100){
            printf("Ingrese un valor entre 1 y 100:");
            scanf("%d",&n_vertices);
    }

    cargarMatriz(matriz,n_vertices);
    printf("\nMatriz de adyacencia:\n");
    mostrarMatriz(matriz,n_vertices);
    printf("N%cmero de vertices: %d\n",163, n_vertices);
    printf("N%cmero de ar%cstas: %d\n",163, 161, cantidadAristas(matriz, n_vertices));
    gradoVertices(matriz,n_vertices);
    menu(matriz,n_vertices);

    return 0;
}

void cargarMatriz(int matriz[][100],int n_vertices){
    
    int fila,col;
    printf("Deber%c completar la matriz de adyacencia:\n",160);

    for (fila=0;fila<n_vertices;fila++){
        for (col=0;col<n_vertices;col++){
            printf("Ingrese la cantidad de aristas adyacentes para la relaci%cn vector %d - vector %d: ",162,fila+1,col+1);
            scanf("%d",&matriz[fila][col]);
            while(matriz[fila][col]<0){
                printf("Ingrese un entero positivo:");
                scanf("%d",&matriz[fila][col]);
            }
        }
    }
}

void mostrarMatriz(int matriz[][100], int n_vertices){
    int fila,col;
    for (fila=0;fila<n_vertices;fila++){
        for (col=0;col<n_vertices;col++){
            printf("[%d]",matriz[fila][col]);
        }
        printf("\n");
    }
}

int cantidadAristas(int matriz[][100], int n_vertices){
    int fila, col, aristas_acum=0;

    for (fila=0;fila<n_vertices;fila++){
        for (col=0;col<n_vertices;col++){
            aristas_acum+=matriz[fila][col];
            //suponiendo que en el caso de lazos se ponga 1 y no 2
            //(para el segundo caso, requeriria un if a pasarpor la diagnal y dividir por 2 antes de sumar)
        }
    }
    return aristas_acum/2;
}

void gradoVertices(int matriz[][100], int n_vertices){

    int fila, col, gradoAcum=0;

    for (fila=0;fila<n_vertices;fila++){
        for (col=0;col<n_vertices;col++){
            gradoAcum+=matriz[fila][col];
            //suponiendo que en el caso de lazos se ponga 1 y no 2
            //(para el segundo caso, requeriria un if a pasarpor la diagnal y dividir por 2 antes de sumar)
        }
        printf("Gr(%d) = %d\n", fila+1, gradoAcum);
        gradoAcum=0;
    }
}

void menu(int matriz[][100],int n_vertices){
    int opcion;

    while(opcion!=0){
        printf("\nSeleccione una opcion del menu\n");
        printf("1. consultaAristaEntreVertices (ejercicio 12)\n");
        printf("2. matrizTraspuesta (ejercicio 13)\n");
        printf("0. terminar programa\n");

        scanf("%d",&opcion);

        switch (opcion){
            case 1:
                consultaAristaEntreVertices(matriz,n_vertices);
                break;

            case 2:
                matrizTraspuesta(matriz,n_vertices);
                break;
            
            case 0:
                printf("Finalizando programa...");
                exit(0);

            default:
                printf("Opcion no valida. Ingrese una opcion entre 0 y 1");
        }

    }
}

void consultaAristaEntreVertices(int matriz[][100],int n_vertices){

    int fila, col, v1, v2;
    printf("Ingrese el primer vertice: ");
    scanf("%d",&v1);
    while(v1<1 || v1>n_vertices){
        printf("El valor para el primer vertice debe ser entre 1 y %d: ",n_vertices);
        scanf("%d",&v1);
    }
    printf("Ingrese el segundo vertice: ");
    scanf("%d",&v2);
    while(v2<1 || v2>n_vertices){
        printf("El valor para el segundo vertice debe ser entre 1 y %d: ",n_vertices);
        scanf("%d",&v1);
    }

    if(matriz[v1-1][v2-1]!=0){
        printf("\nEntre los vertices %d y %d hay aristas\n",v1,v2);
    }else{
        printf("\nEntre los vertices %d y %d no hay aristas\n",v1,v2);
    }
}

void matrizTraspuesta(int matriz[][100], int n_vertices){

    int matriz_traspuesta[100][100];
    int i,j;

    for (i=0;i<n_vertices;i++){
        for (j=0;j<n_vertices;j++){
            matriz_traspuesta[j][i]=matriz[i][j];
        }
    }

    printf("\nMatriz traspuesta a la matriz de adyacencia:\n");
    mostrarMatriz(matriz_traspuesta,n_vertices);
    printf("La traspuesta brinda la misma informacion\n");
}