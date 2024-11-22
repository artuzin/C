#include <stdio.h>

int main()
{
    float n1, n2, n3, n4, ne, md1, md2;
    //lê as notas
    printf("Digite a primeira nota: ");
    scanf("%f", &n1);
    printf("Digite a segunda nota: ");
    scanf("%f", &n2);
    printf("Digite a terceira nota: ");
    scanf("%f", &n3);
    printf("Digite a quarta nota: ");
    scanf("%f", &n4);
    //faz a media
    md1 = (n1 + n2 + n3 + n4)/4; 
    //confere a media e solicita mais uma nota se necessario
    if(md1 >= 7)
    {
        printf("Aprovado! Sua media foi %.2f", md1);
    }
    else
    {
        printf("Reprovado, digite a nota do exame: ");
        scanf("%f", &ne);
        //confere se com a nota extra o aluno passou
        md2 =  (md1 + ne)/2;
        if(md2 >= 5)
        {
            printf("Aprovado no exame! Sua media foi de %.2f", md2);
        }
        else
        {
            printf("Reprovado no exame! Sua media foi de %.2f", md2);
        }
    }
    return 0;
}