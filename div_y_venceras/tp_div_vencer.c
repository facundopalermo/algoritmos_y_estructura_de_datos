#include <stdio.h>
#include <stdlib.h>

/*estructura para guardar el valor de m*/
/*de otra forma, el tamaño se reiniciaria
con cada llamada de la recursividad, 
perdiendose el valor del indice*/
typedef struct vec {
    int valor;
    int m;
}Vector;

int buscar (Vector *array, int n);
int contador = 0;

int main(int argc, char const *argv[])
{
    Vector *vector;

    /*vector original*/
    int array[] = {0, 1, 22, 3, 44, 5, 6, 77, 8, 9, 10, 111, 12, 13, 99, 15, 166, 17, 18, 191, 20};
    int n = 21;
    int m = 0;

    vector = (Vector*)malloc(sizeof(Vector)*n);

    /*cargo el vector con los datos del original*/
    for(m=0; m < n; m++) {
        vector[m].m = m;
        vector[m].valor = array[m];
    }

    /*funcion recursiva de divide y venceras*/
    /*DIVIDIR + VENCER + COMBINAR RESULTADOS*/
    printf("\nEn total coinciden %d valores del total (n = %d).\n", buscar(vector, n), n);

    free(vector);
    return 0;
}

int buscar (Vector *array, int n) {
    int d = 0; /*tamaño derecha*/
    int i = 0; /*tamaño izquierda*/
    int j = 0;

    int ri = 0, rd = 0;

    Vector *izq; /*nuevo vector para la izquierda*/
    Vector *der; /*nuevo vector para la derecha*/

    /*caso base, cuando el tamaño del vector (n) = 1*/
    if(n == 1) {
        /*PASO 2 - VENCER*/
        if (array[0].m == array[0].valor){
            /*muestra las coincidencias*/
            printf("vector[%d] = %d\n", array[0].m, array[0].valor);
            /*como coincide, retorna 1*/
            return 1;
        }else{
            /*si no coincide, retorna 0*/
            return 0;
        }
    } else {

        /*PASO 1 - DIVIDIR*/
        i = n / 2; /*tamaño del vector de la izq*/
        if(n % 2 != 0){ /*si es impar, le sumo 1 al tamaño del vector de la izq*/
            i++;
        }

        d = n / 2; /*tamaño del vector de la der*/

        /*dimensiono la memoria dinamica de los vectores izq y derecha*/
        izq = (Vector*)malloc(sizeof(Vector) * i);
        der = (Vector*)malloc(sizeof(Vector) * d);

        /*les cargo los valores*/
        /*a la izquierda*/
        for(j=0; j < i; j++) {
            izq[j].m=array[j].m;
            izq[j].valor=array[j].valor;
        }
        /*y a la derecha*/
        for(j=i; j < n; j++) {
            der[j-i].m=array[j].m;
            der[j-i].valor=array[j].valor;
        }

        /*divide recursivamente a la izquierda y a la derecha*/
        /*1 si hay coincidencia, 0 si no la hay*/
        ri = buscar(izq, i);
        rd = buscar(der, d);

        /*libera las memorias dinamicas*/
        free(izq);
        free(der);
        
        /*PASO 3 - CONBINAR RESULTADOS*/
        /*retorna la suma de los resultados*/
        return ri + rd;
    }
}
