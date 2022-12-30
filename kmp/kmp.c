#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void kmp (const char * texto, const char * patron);

int main(int argc, char const *argv[]) {
    
    char * texto1 = "TEDTHRETETERTERFTERFTERFTERA";
    char * patron1 = "TERFTERA";

    kmp(texto1, patron1);

    char * texto2 = "AACCIIAACIACIEACIECIACIEN";
    char * patron2 = "ACIECIACIEN";

    kmp(texto2, patron2);

    char * texto3 = "KGRHKGRHRHKGKGRHRHKGH";
    char * patron3 = "KGRHRHKGH";
    kmp(texto3, patron3);
    
    return 0;

}

void kmp (const char * texto, const char * patron) {

    int i = 0, j = 0;

    int tam_texto = 0;
    int tam_patron = 0;
    int *sig_mejor_match;

    /* obtengo el largo de cada cadena */
    tam_texto = strlen(texto);
    tam_patron = strlen(patron);

    /* si el primer caracter de la cadena a buscar es nulo o el tamaño es 0 */
    if(*patron == '\0' || tam_patron == 0) {
        printf("El texto está vacio o es nulo.\n");
    }

    /* si el primer caracter de la cadena a buscar es nulo o el tamaño es 0 */
    if(*texto == '\0' || tam_patron > tam_texto) {
        printf("El texto no puede ser nulo o ser menor al patron.\n");
    }

    /*dimensiono una variable para guardar *** del tamaño del patron +1
    y la inicializo en 0 */
    sig_mejor_match = malloc (sizeof(int) * (tam_patron + 1));
    for(i = 0; i < (tam_patron + 1); i++) {
        sig_mejor_match[i] = 0;
    }

    /* busca el siguiente mejor match */
    for(i = 1; i < tam_patron; i++) {

        j = sig_mejor_match[i + 1];

        while(j > 0 && patron[j] != patron[i]) {
            j = sig_mejor_match[j];
        }

        if(j > 0 || patron[j] == patron[i]) {
            sig_mejor_match[i + 1] = j + 1;
        }
    }
    
    /* busca el patron en el texto y retorna el indice donde empieza */
    for(i = 0, j = 0; i < tam_texto; i++) {

        if( *(texto + i) == *(patron + j) ) {
            if (++j == tam_patron) {
                printf("El patron '%s' se ha encontrado en en el indice %d del texto '%s'\n", patron, i - j + 1, texto);
            }
        } else if(j > 0) {
            j = sig_mejor_match[j];
            i--;
        }
    }

    free(sig_mejor_match);
}

