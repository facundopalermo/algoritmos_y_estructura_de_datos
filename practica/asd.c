#include <stdio.h>
#include <stdlib.h>


void fun (int val)
{ 
    if (val> 1)
        fun(val/2);
    
    printf ("%d-", val%2);
}





int main() {

 fun(10);

 return 0;

}