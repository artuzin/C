#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

//Artur Boudens e Giulia Biacchi

typedef struct {
    float valor, parcela;
    int meses;
}emprestimo;

typedef struct{
    char nome[100];
    float salario;
    emprestimo emprestimo;
}cliente;

int validar_nome(const char *nome){
    for(size_t i = 0; i < strlen(nome); i++){
        if(!isalpha(nome[i]) && nome[i] != ' '){
            return 0;
        }
    }
    return 1;
}

void limpar(){
    while(getchar() != '\n' && EOF);
}

int main(){
    cliente cliente;
    emprestimo emprestimo;
    int l1 = 1, l2= 1;
    int validar, opcao, c, eA, eR;

    while(l1 == 1){
        printf("\n\n--------Programa de Simulacao de Emprestimo--------\n\n");

        printf("1- Iniciar programa\n2-Sair\nEscolha uma opcao: ");

        validar = scanf("%d", &opcao);
        limpar();

        switch (opcao)
        {
        case 1:
            while(l2 == 1){
                printf("Insira o seu nome: ");
                if(fgets(cliente.nome, 50, stdin) != NULL){
                    
                    size_t len = strlen(cliente.nome);
                    if(len > 0 && cliente.nome[len - 1] == '\n'){
                        cliente.nome[len - 1] = '\0';
                    }
                        if(validar_nome(cliente.nome) == 1){    
                            printf("Nome registrado com sucesso!\n");
                            l2 = 0;
                        }
                    
                        else{
                            printf("Nome invalido. Utilize apenas letras e espacos.\n");
                        }
                    }
                else{
                    printf("Erro ao ler nome, tente novamente!");
                }   
            }

            l2 = 1;

            while(l2 == 1){
                printf("Digite seu salario: \n");
                int validar_salario = scanf("%f", &cliente.salario);
                
                limpar();

                if(validar_salario == 1 && cliente.salario > 0){
                    printf("Valor registrado com sucesso!\n");
                    l2 = 0;
                }
                else{
                    printf("Valor invalido de salario, digite novamente.\n\n");

                }    
            }

            l2 = 1;
            
            while(l2 == 1){
                printf("Digite o valor da emprestimo: \n");
                int validar_emprestimo = scanf("%f", &cliente.emprestimo.valor);
                
                limpar();

                if(validar_emprestimo == 1 && cliente.emprestimo.valor > 0){
                    printf("Valor registrado com sucesso!\n");
                    l2 = 0;
                }
                else{
                    printf("Valor invalido de emprestimo, digite novamente.\n\n");
                }    
            }

            l2 = 1;

            while(l2 == 1){
                printf("Digite em quantos meses deseja quitar o emprestimo.(ATENCAO, USE VALORES INTEIROS):\n");
                int validar_meses = scanf("%i", &cliente.emprestimo.meses);
                
                limpar();

                if(validar_meses == 1 && cliente.emprestimo.meses > 0){
                    printf("Meses registrados!\n");
                    l2 = 0;
                }
                else{
                    printf("Valor invalido para meses, digite outro.\n\n");
                }
            }
            
            cliente.emprestimo.parcela = cliente.emprestimo.valor / cliente.emprestimo.meses;

            if(cliente.emprestimo.parcela > cliente.salario * 0.2){
                printf("Emprestimo reprovado!\n");
                printf("Nome do cliente: %s\n", cliente.nome);
                printf("Valor das parcelas: %2.f\n", cliente.emprestimo.parcela);
            }
            else{
                printf("Emprestimo aprovado!\n");
                printf("Nome do cliente: %s\n", cliente.nome);
                printf("Valor das parcelas: %.2f\n", cliente.emprestimo.parcela);
            }
        
        case 2:
            printf("Saindo do programa...");
            return 0;
        default:
            printf("Opcao invalida, insira novamente!");
        }
    }

}

