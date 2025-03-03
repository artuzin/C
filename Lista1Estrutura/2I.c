#include <stdio.h>
#include <stdlib.h>

void main()
{
    float salario, parcela;
    int opcao;

    printf("Programa de validacao de emprestimo.\n\n");
    
    while(1)
    {
        printf("1-Iniciar programa\n2-Sair\nEscolha uma opcao: ");
        scanf("%i", &opcao);
        switch (opcao)
        {
            case 1:
                while(1)
                {
                    printf("Digite seu salario: \n");
                    int validar_salario = scanf("%f", &salario);
                    if(validar_salario == 1 && salario > 0)
                    {
                        printf("Valor registrado com sucesso!\n");
                        break;
                    }
                    else
                    {
                        printf("Valor invalido de salario, digite novamente.\n\n");

                    }    
                }
                while(1)
                {
                    printf("Digite o valor da parcela: \n");
                    int validar_parcela = scanf("%f", &parcela);
                    if(validar_parcela == 1 && parcela > 0)
                    {
                        printf("Valor registrado com sucesso!\n");
                        break;
                    }
                    else
                    {
                        printf("Valor invalido de parcela, digite novamente.\n\n");
                    }    
                }        
                if(parcela > salario * 0.2){
                    printf("Emprestimo aprovado!\n");
                }
                else
                {
                    printf("Emprestimo reprovado!\n");
                }
        
            case 2:
                printf("Encerrando programa...");
                exit(1);
            default:
                printf("Opcao invalida, insira novamente.\n");
                while(getchar() != '\n');
        }
    }
}