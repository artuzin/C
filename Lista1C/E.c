#include <stdio.h>
#include <math.h>

void bhaskara () //procedimento de bhaskara
{
    float a, b, c, delta, x1, x2;
    //lê os valores para A, B e C
    printf("Digite um valor para A: ");
    scanf("%f", &a);
    //confere se o valor de A = 0, o que não seria permitido
    while(a == 0)
    {
        printf("Valor invalido, digite um valor diferente de 0 para A: ");
        scanf("%f", &a);
    }

    printf("Digite um valor para B: ");
    scanf("%f", &b);

    printf("Digite um valor para C: ");
    scanf("%f", &c);
    //calcula delta e ja checa suas condições, calculando tambem asraizes
    delta = pow(b, 2) - (4 * a * c);

    if(delta == 0)
    {
        x1 = -b / (2 * a);
        printf("Delta tem valor 0, possuindo apenas uma raiz.\n x = %.1f", x1);
    }
    else if(delta < 0)
    {
        printf("Delta tem valor negativo, nao existem raizes reais para essa equacao.");
    }
    else
    {
        x1 = (-b + sqrt(delta)) / (2 * a);
        x2 = (-b - sqrt(delta)) / (2 * a);

        printf("Delta tem valor positivo e diferente de 0, possuindo duas raizes reais.\n x1 = %.2f e x2 = %.2f", x1, x2);
    }
}
//função principal que chama o procedimento bhaskara
int main()
{
    printf("Programa de resolucao de equacoes!\n");
    printf("Chamado o programa...\n\n");
    bhaskara ( );

    return 0;
}