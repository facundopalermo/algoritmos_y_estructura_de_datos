// Diseñar un algoritmo recursivo e iterativo que devuelva la suma de los primeros N enteros
#include <stdio.h>
#include <stdlib.h>

int suma_rec(int n)
{
    if (n == 0)
    {
        return 0;
    }
    else
    {
        return n + suma_rec(n - 1);
    }
}

int suma_ite(int n)
{
    int r = 0;
    for (int i = 1; i <= n; i++)
    {
        r = r + i;
    }
    return r;
}

int main()
{
    printf("%d", suma_rec(10));
    printf("\n");
    printf("%d", suma_ite(10));
}