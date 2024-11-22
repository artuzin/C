#include <stdio.h>

int main()
{
    int a, b, dif;
    //lê os valores
    printf("Digite o primeiro valor inteiro: ");
    scanf("%d", &a);
    printf("Digite o segundo valor inteiro: ");
    scanf("%d", &b);
    //confere qual o valor é o maior e faz a diferença
    if(a > b)
    {
        dif = a - b;
    }
    else
    {
        dif = b - a;
    }
    //imprime a diferença
    printf("A diferenca do maior para o menor valor digitado e de: %d", dif);
    return 0;
}