#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

//Faça uma narração/fluxo que simula a solicitação de 10 empréstimos utilizando o algoritmo 2.II acima. No final, imprima a quantidade de empréstimos concedidos e a quantidade de empréstimos não concedidos.

 
int validar_nome(const char *nome){
    for(size_t i = 0; i < strlen(nome); i++) { //size_t é um tipo de dado que é usado para representar indices ou tamanhos
        if(!isalpha(nome[i]) && nome[i] != ' '){ //confere se so existe letras e espaços dentro da array de nome
            return 0;
        }
    }
    return 1;
}

void main()
{
    float salario, emprestimo, parcela;
    int opcao, meses, c, eA, eR;
    char nome[50];

    printf("Programa de validacao de emprestimo.\n\n");
    
        while(1)
        {
            printf("1-Iniciar programa\n2-Sair\nEscolha uma opcao: ");
            scanf("%i", &opcao);
            while(getchar() != '\n');
            switch (opcao){
                case 1:
                    c = 0;
                    eA = 0;
                    eR = 0;
                    
                    while(c < 10){
                        while(1){
                            printf("Digite seu nome: \n");
                            if(fgets(nome, 50, stdin) != NULL) //o fgets dispensa a limpeza de buffer, pois ele ja consome o dado inserido
                            {
                                size_t len = strlen(nome);
                                if(len > 0 && nome[len - 1] == '\n'){
                                    nome[len - 1] = '\0';
                                }
                                if(validar_nome(nome) == 1){    
                                    printf("Nome registrado com sucesso!\n");
                                    break;
                                }
                                else{
                                    printf("Nome invalido. Utilize apenas letras e espacos.\n");
                                }
                            }
                            else{
                                printf("Erro ao ler nome. Tente novamente.\n");
                            }    
                        }
                        while(1){
                            printf("Digite seu salario: \n");
                            int validar_salario = scanf("%f", &salario);
                            while(getchar() != '\n');
                            if(validar_salario == 1 && salario > 0){
                                printf("Valor registrado com sucesso!\n");
                                break;
                            }
                            else{
                                printf("Valor invalido de salario, digite novamente.\n\n");

                            }    
                        }
                        while(1){
                            printf("Digite o valor da emprestimo: \n");
                            int validar_emprestimo = scanf("%f", &emprestimo);
                            while(getchar() != '\n');
                            if(validar_emprestimo == 1 && emprestimo > 0){
                                printf("Valor registrado com sucesso!\n");
                                break;
                            }
                            else{
                                printf("Valor invalido de emprestimo, digite novamente.\n\n");
                            }    
                        }
                        while(1){
                            printf("Digite em quantos meses deseja quitar o emprestimo.(ATENCAO, USE VALORES INTEIROS):\n");
                            int validar_meses = scanf("%i", &meses);
                            while(getchar() != '\n');
                            if(validar_meses == 1 && meses > 0){
                                printf("Meses registrados!\n");
                                break;
                            }
                            else{
                                printf("Valor invalido para meses, digite outro.\n\n");
                            }
                        }        
                        
                        parcela = emprestimo / meses;

                        if(parcela > salario * 0.2){
                            c++;
                            eR++;

                        }
                        else{
                            c++;
                            eA++;
                        }
                    }
                    printf("Emprestimos aprovados: %i\n\n", eA);
                    printf("Emprestimos reprovados: %i\n\n", eR);
                    break;
                case 2:
                    printf("Encerrando programa...");
                    exit(1);
                default:
                    printf("Opcao invalida, insira novamente.\n");
                    while(getchar() != '\n');
            }
        }
}