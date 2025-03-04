#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

//Faça uma narração/fluxo que leia o salário de um trabalhador e o valor da parcela de um empréstimo. Se a parcela for maior que 20% do salário, imprima: “Empréstimo aprovado”. Caso contrário, imprima “Empréstimo reprovado”.
int validar_nome(const char *nome){
    for(size_t i = 0; i < strlen(nome); i++) {
        if(!isalpha(nome[i]) && nome[i] != ' '){
            return 0;
        }
    }
    return 1;
}

void main()
{
    float salario, emprestimo, parcela;
    int opcao, meses;
    char nome[50];

    printf("Programa de validacao de emprestimo.\n\n");
    
    while(1)
    {
        printf("1-Iniciar programa\n2-Sair\nEscolha uma opcao: ");
        scanf("%i", &opcao);
        while(getchar() != '\n');
        switch (opcao)
        {
            case 1:
                while(1)
                {
                    printf("Digite seu nome: \n");
                    if(fgets(nome, 50, stdin) != NULL)
                    {
                        size_t len = strlen(nome);
                        if(len > 0 && nome[len - 1] == '\n')
                        {
                            nome[len - 1] = '\0';
                        }
                        if(validar_nome(nome) == 1){    
                            printf("Nome registrado com sucesso!\n");
                            break;
                        }
                        else
                        {
                            printf("Nome invalido. Utilize apenas letras e espacos.\n");
                        }
                    }
                    else
                    {
                        printf("Erro ao ler nome. Tente novamente.\n");
                        while(getchar() != '\n');
                    }    
                }
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
                        while(getchar() != '\n');

                    }    
                }
                while(1)
                {
                    printf("Digite o valor da emprestimo: \n");
                    int validar_emprestimo = scanf("%f", &emprestimo);
                    if(validar_emprestimo == 1 && emprestimo > 0)
                    {
                        printf("Valor registrado com sucesso!\n");
                        break;
                    }
                    else
                    {
                        printf("Valor invalido de emprestimo, digite novamente.\n\n");
                        while(getchar() != '\n');
                    }    
                }
                while(1)
                {
                    printf("Digite em quantos meses deseja quitar o emprestimo.(ATENCAO, USE VALORES INTEIROS)");
                    int validar_meses = scanf("%i", &meses);
                    if(validar_meses == 1 && meses > 0)
                    {
                        printf("Meses registrados!\n");
                        break;
                    }
                    else
                    {
                        printf("Valor invalido para meses, digite outro.\n\n");
                        while(getchar() != '\n');
                    }
                }        
                
                parcela = emprestimo / meses;

                if(parcela > salario * 0.2){
                    printf("Emprestimo reprovado!\n");
                    printf("Nome do cliente: %s\n", nome);
                    printf("Valor das parcelas: %2.f\n", parcela);
                }
                else
                {
                    printf("Emprestimo aprovado!\n");
                    printf("Nome do cliente: %s\n", nome);
                    printf("Valor das parcelas: %.2f\n", parcela);
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