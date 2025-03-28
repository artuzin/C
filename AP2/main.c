#include "utils.c"

//Artur Boudens e Giulia Biacchi

int validar, opcao, n_clientes, l1 = 1, l2 = 1, c = 0, i = 0, eA = 0, eR = 0;

int main(){
    while(l1){
        printf("\n\n--------Programa de Simulacao de Emprestimo--------\n\n");

        while(l2){
            printf("Digite quantos clientes deseja registrar o emprestimo:");
            validar = scanf("%d", &n_clientes);

            if(validar == 1){
                if(n_clientes > 0){
                    printf("Prosseguindo com o cadastro de %d cliente(s).\n\n", n_clientes);
                    limpar();
                    l2 = 0;
                    
                }
                else{
                    msg_erro("O numero deve ser positvo.");
                }
            }
            else{
                msg_erro("Valor invalido para o numero de clientes.");
            }
        }
        int situacao[n_clientes];
        cliente cliente[n_clientes];
        l2 = 1;

        printf("1- Iniciar programa\n2-Sair\nEscolha uma opcao: ");

        scanf("%i", &opcao);
        limpar();

        switch (opcao){
        case 1:
            for(i = 0; i < n_clientes;){
                printf("Cliente numero %d.\n\n", i + 1);
                while(l2){
                    printf("Insira o nome do cliente %d: \n", i + 1);
                    
                    if(fgets(cliente[i].nome, 100, stdin) != NULL){
                        
                        cliente[i].nome[strcspn(cliente[i].nome, "\n")] = '\0';
                        
                        if(validar_nome(cliente[i].nome) == 1){
                            printf("Nome registrado com sucesso!\n");
                            l2 = 0;
                        }
                        else{
                            printf("Nome invalido. Utilize apenas letras e espacos\n");
                        }
                    }
                    else{
                        printf("Erro ao ler o nome, insira novamente\n");
                    }
                }

                l2 = 1;
        
                while(l2 == 1){
                    printf("Digite seu salario: \n");
                    int validar_salario = scanf("%f", &cliente[i].salario);

                    if(validar_salario == 1){
                        if(cliente[i].salario >= 0){
                            printf("Valor registrado com sucesso!\n");
                            limpar();
                            l2 = 0;
                        }
                        else{
                            msg_erro("O valor do salario deve ser positivo.");
                        }
                    }
                    else{
                        msg_erro("Valor invalido de salario, digite novamente.\n\n");

                    }    
                }

                l2 = 1;
                
                while(l2 == 1){
                    printf("Digite o valor da emprestimo: \n");
                    int validar_emprestimo = scanf("%f", &cliente[i].emprestimo.valor);

                    if(validar_emprestimo == 1){
                        if(cliente[i].emprestimo.valor > 0){
                            printf("Valor registrado com sucesso!\n");                    
                            limpar();
                            l2 = 0;
                            
                        }
                        else{
                            msg_erro("O valor do emprestimo deve ser positivo");
                        }
                    }
                    else{
                        msg_erro("Valor invalido de emprestimo, digite novamente.\n\n");
                    }    
                }

                l2 = 1;

                while(l2 == 1){
                    printf("Digite em quantos meses deseja quitar o emprestimo.(ATENCAO, USE VALORES INTEIROS):\n");
                    
                    int validar_meses = scanf("%i", &cliente[i].emprestimo.meses);

                    if(validar_meses == 1){
                        if(cliente[i].emprestimo.meses > 0){
                            printf("Meses registrados!\n");
                            limpar();
                            l2 = 0;
                        }
                        else{
                            msg_erro("O numero de meses deve ser positivo e diferente de 0.");
                        }
                    }
                    else{
                        printf("Valor invalido para meses, digite outro.\n\n");
                    }
                }

                l2 = 1;

                calculo_parcela(cliente, n_clientes);

                printf("Valor da parcela = %.2f\n", cliente[i].emprestimo.parcela);

                if(cliente[i].emprestimo.parcela > cliente[i].salario * 0.2){
                    situacao[i] = 0;
                    i++;
                    eR++;
                }
                else{
                    situacao[i] = 1;
                    i++;
                    eA++;
                }
            }
            
            printf("Emprestimos Aprovados: %d\n", eA);
            printf("Emprestimos Reprovados: %d\n\n", eR);
            printf("---------------Dados dos Clientes---------------");
        
            dados_emprestimo(cliente, situacao, n_clientes);

            l1 = 0;
        
        case 2:
            printf("Saindo do programa...\n");
            exit(1);
        default:
            break;
        }
    }
}