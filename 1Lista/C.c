#include <stdio.h>

int main()
{
    float n1, n2, n3, n4, md;
    //lê todas as notas
    printf("Digite a primeira nota: ");
    scanf("%f", &n1);
    printf("Digite a segunda nota: ");
    scanf("%f", &n2);
    printf("Digite a terceira nota: ");
    scanf("%f", &n3);
    printf("Digite a quarta nota: ");
    scanf("%f", &n4);
    //faz a média
    md = (n1 + n2 + n3 + n4)/4;
    //confere o valor da média, mostrando ela e o resultado final
    if(md >= 5)
    {
        printf("Aprovado, sua media foi: %.2f", md);
    }
    else
    {
        printf("Reprovado, sua media foi: %.2f", md);
    }

    return 0;

}