/*7. Un programa en C contiene la siguiente declaración:
int x[8]={10,20,30,40,50,60,70,80,80};
    a) ¿Cuál es el significado de x? 
    b) ¿Cuál es el significado de (x+2)? 
    c) ¿Cuál es el valor de *x? 
    d) ¿Cuál es el valor de (*x+2)? 
    e) ¿Cuál es el valor de *(x+2)?

7)
a) suponiendo que la cantidad de elementos es 8 (y que el doble 80 es un error), x es un arreglo de dimensión 8.
b) dado que x ademas de ser un arreglo es tambien el nombre del puntero, x+2 es el valor del puntero ubicado en 0 mas dos posiciones, o sea x[2]=30
c) el valor de *x es 10.
d) el valor de (*x+2) es 12
e) el valor de *(x+2) es 30*/
