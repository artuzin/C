#include <stdio.h>

int main()
{
    int a, b, dif;
    //lê os valores
    printf("Digite o primeiro valor inteiro: ");
    scanf("%i", &a);
    printf("Digite o segundo valor inteiro: ");
    scanf("%i", &b);
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
    printf("A diferenca do maior para o menor valor digitado e de: %i", dif);
    return 0;
}