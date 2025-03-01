#include <stdio.h>

int main()
{
    int x;
    //le o valor
    printf("Digite um valor inteiro negativo ou positivo: ");
    scanf("%d", &x);
    //se for negativo transforma em positivo
    if(x < 0)
    {
        x = x * -1;
    }
    //imprime o valor
    printf("O modulo do valor digitado e: %d", x);

    return 0;
}