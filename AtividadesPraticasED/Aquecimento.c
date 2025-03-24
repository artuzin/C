#include <stdio.h>
#include <stdlib.h>

typedef struct{
    float ap[3], media_ap, np, av;
}b;

typedef struct {
    b b[2];
    int ra;
    float nf;
}aluno;

void limpar(){
    while(getchar() != '\n' && EOF);
}

int main(){
    int validar, loop = 1, opcao = 0, n_alunos;
    
    printf("\n\n--------Programa de registro de notas--------\n\n");

    while(loop == 1){
        printf("Digite quantos alunos deseja cadastrar (INSIRA UM VALOR INTEIRO):");

        if(scanf("%i", &n_alunos) == 1 && n_alunos > 0){
            printf("\n===Prosseguindo com o cadastro de %d aluno(s)===\n\n", n_alunos);
            loop = 0;
            limpar();
        }
        else{
            printf("Valor invalido para o numero de alunos, insira outro.\n");
            limpar();
        }
    }

    aluno aluno[n_alunos];
    int situacao[n_alunos];
    int dados_inseridos = 0;

    loop = 1;

    while(1){

        printf("1-Iniciar programa\n2-Consultar notas\n3-Sair\nEscolha uma opcao: \n");
        scanf("%d", &opcao);
        limpar();

        switch (opcao)
        {
        case 1:
                for(int j = 0; j < n_alunos; j++){
                    
                    printf("\n>>>>>>DADOS DO ALUNO %d<<<<<<\n", j + 1);
                    
                    while(loop == 1){
                        printf("Insira o RA do aluno : ");
                        
                        validar = scanf("%d", &aluno[j].ra);
                        
                        limpar();

                        if(validar == 1 && aluno[j].ra > 10000000 && aluno[j].ra < 99999999){
                            printf("RA inserido com sucesso!\n");
                            loop = 0;
                        }
                        else{
                            printf("Valor inserido nao corresponde a um RA, tente novamente!\n");
                        }
                        
                    }

                    loop = 1;

                    printf("---PRIMEIRO SEMESTRE---");

                    for(int i = 0; i < 3;){
                        while(i < 3){
                            printf("\nDigite a nota da atividade pratica %d: ", i + 1);
                            
                            validar = scanf("%f", &aluno[j].b[0].ap[i]);
                            
                            limpar();

                            if(validar == 1 && aluno[j].b[0].ap[i] >= 0 && aluno[j].b[0].ap[i] <= 10){
                                printf("\nA nota foi inserida com sucesso\n");
                                i++;
                            }
                            else{
                                printf("O valor inserido nao corresponde a uma nota, tente novamente!\n");
                            }
                        }
                    }

                    while(loop == 1){
                        printf("Digite o valor da nota da prova do primeiro bimestre: ");

                        validar = scanf("%f", &aluno[j].b[0].np);

                        if(validar == 1 && aluno[j].b[0].np >= 0 && aluno[j].b[0].np <= 10){
                            printf("\nValor da prova inserido com sucesso!\n");
                            loop = 0;

                            aluno[j].b[0].np = aluno[j].b[0].np * 0.7;

                        }
                        else{
                            printf("Valor invalido para a nota da prova");
                        }
                        
                    }

                    loop = 1;

                    printf("---SEGUNDO SEMESTRE---\n");

                    for(int i = 0; i < 3;){
                        while(i < 3){
                            printf("Digite a nota da atividade pratica %d: ", i + 1);
                            
                            validar = scanf("%f", &aluno[j].b[1].ap[i]);
                            
                            limpar();

                            if(validar == 1 && aluno[j].b[1].ap[i] >= 0 && aluno[j].b[1].ap[i] <= 10){
                                printf("\nA nota foi inserida com sucesso\n\n");
                                i++;
                            }
                            else{
                                printf("O valor inserido nao corresponde a uma nota, tente novamente!\n");
                            }
                        }
                    }

                    while(loop == 1){
                        printf("Digite o valor da nota da prova do segundo bimestre: ");

                        validar = scanf("%f", &aluno[j].b[1].np);

                        if(validar == 1 && aluno[j].b[1].np >= 0 && aluno[j].b[1].np <= 10){
                            printf("\nValor da prova inseirdo com sucesso!\n");
                            loop = 0;

                            aluno[j].b[1].np = aluno[j].b[1].np * 0.7;

                        }
                        else{
                            printf("Valor invalido para a nota da prova");
                        }
                        
                    }

                    loop = 1;

                    aluno[j].b[0].media_ap = ((aluno[j].b[0].ap[0] + aluno[j].b[0].ap[1] + aluno[j].b[0].ap[2]) / 3);
                    aluno[j].b[0].av = (aluno[j].b[0].media_ap * 0.3) + aluno[j].b[0].np;

                    aluno[j].b[1].media_ap = ((aluno[j].b[1].ap[0] + aluno[j].b[1].ap[1] + aluno[j].b[1].ap[2]) / 3);
                    aluno[j].b[1].av = (aluno[j].b[1].media_ap * 0.3) + aluno[j].b[1].np;

                    aluno[j].nf = (aluno[j].b[0].av + aluno[j].b[1].av) / 2;

                    if(aluno[j].nf >= 6){
                        situacao[j] = 1;
                    }
                    else{
                        situacao[j] = 0;
                    }
                }

                dados_inseridos = 1;

            break;
        case 2:
                if(dados_inseridos == 0){
                    printf("\n|||Nao ha dados para serem exibidos, va ate a opcao 1 no menu para inseri-los.|||\n\n");
                }
                else{
                    for(int j = 0; j < n_alunos; j++){
                        
                        printf("\n>>>>DADOS DO ALUNO %d<<<<\n", j + 1);
                        printf("RA: %d\n", aluno[j].ra);
                        printf("Nota final: %.2f\n", aluno[j].nf);
                        
                        if(situacao[j] == 1){
                            printf("Situacao: Aprovado!\n\n");
                        }
                        else{
                            printf("Situacao: Reprovado!\n\n");
                        }
                    }
                }
                limpar();
            break;
        case 3:
            printf("\nSaindo do programa...\n\n");
            return 0;
        default:
            printf("Opcao invalida, insira um valor valido.");
        }

    }
}