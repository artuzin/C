#include <stdio.h>
#include <math.h>

float raiz(float a)
{
    float raiz_quadrada = sqrt(a);
    return raiz_quadrada;
}
int main()
{
    float resultado = raiz(4);
    printf("%.2f", resultado);
    return 0;
}