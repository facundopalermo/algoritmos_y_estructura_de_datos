#include <stdio.h>
#include <stdlib.h>

void f (int num, int div);
void g (int num, int div);

void f (int num, int div){
    if( num>1 ) {
        if (( num % div ) == 0){
            printf("r: %d\n", div);
            f (num / div, div);
        }else{
            f (num, div + 1);
        }
    }
}

void g (int num, int div){

    int a = num;
    int b = div;

    while ( a > 1){
        if ( ( a % b ) == 0){
            printf("i: %d\n", b);
            a = a / b;
        }else{
            b++;
        }
    }
}


int main (){
    f(6,2);
    printf("****\n");
    g(6,2);
}