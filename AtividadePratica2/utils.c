#include "utils.h"

void limpar(){
    char c;
    while((c = getchar()) != '\n' && c != EOF);
}

void msg_erro(char *msg){
    system(LT);
    printf("\n========Erro========\n");
    printf("%s", msg);
    printf("\n====================\n");
    printf("\nAperte <ENTER> para inserir novamente o valor,\n");
    limpar();
    getchar();
}

void dados_alunos(aluno *aluno, int *situacao, int n_alunos){
    system(LT);
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

void media_alunos(aluno *aluno, int *situacao ,int n_alunos, int *dados_inseridos){
    for(int j = 0; j < n_alunos; j++){
                    
        printf("\n>>>>>>DADOS DO ALUNO %d<<<<<<\n", j + 1);
        
        while(loop == 1){
            printf("Insira o RA do aluno : ");
            
            validar = scanf("%d", &aluno[j].ra);

            if(validar == 1 && aluno[j].ra > 10000000 && aluno[j].ra < 99999999){
                printf("RA inserido com sucesso!\n");
                loop = 0;
                limpar();
            }
            else{
                msg_erro("Valor inserido nao corresponde a um RA, tente novamente!");
            }
            
        }

        loop = 1;

        printf("---PRIMEIRO SEMESTRE---");

        for(int i = 0; i < 3;){
            while(i < 3){
                printf("\nDigite a nota da atividade pratica %d: ", i + 1);
                
                validar = scanf("%f", &aluno[j].b[0].ap[i]);

                if(validar == 1){
                    if(aluno[j].b[0].ap[i] >= 0 && aluno[j].b[0].ap[i] <= 10){
                        printf("\nA nota foi inserida com sucesso\n");
                        i++;
                        limpar();
                    }
                    else{
                        msg_erro("O valor da nota deve ser entre 0 e 10.");
                    }
                }   
                else{
                    msg_erro("Valor invalido para a nota da atividade pratica.");
                }
            }
        }

        while(loop == 1){
            printf("Digite o valor da nota da prova do primeiro bimestre: ");

            validar = scanf("%f", &aluno[j].b[0].np);

            if(validar == 1){
                if(aluno[j].b[0].np >= 0 && aluno[j].b[0].np <= 10){
                    printf("\nValor da prova inserido com sucesso!\n");
                    limpar();
                    aluno[j].b[0].np = aluno[j].b[0].np * 0.7;
                    loop = 0;
                }
                else{
                    msg_erro("A nota deve ser entre 0 e 10.");
                }
            }
            else{
                msg_erro("Valor invalido para a nota da prova");
            }
            
        }

        loop = 1;

        printf("---SEGUNDO SEMESTRE---\n");

        for(int i = 0; i < 3;){
            while(i < 3){
                printf("Digite a nota da atividade pratica %d: ", i + 1);
                
                validar = scanf("%f", &aluno[j].b[1].ap[i]);

                if(validar == 1){
                    if(aluno[j].b[1].ap[i] >= 0 && aluno[j].b[1].ap[i] <= 10){
                        printf("\nA nota foi inserida com sucesso\n\n");
                        i++;
                        limpar();
                    }
                    else{
                        msg_erro("A nota deve ser entre 0 e 10.");
                    }
                }
                else{
                    msg_erro("Valor invalido para a nota da atividade pratica.");
                }
            }
        }

        while(loop == 1){
            printf("Digite o valor da nota da prova do segundo bimestre: ");

            validar = scanf("%f", &aluno[j].b[1].np);

            if(validar == 1){
                if(aluno[j].b[1].np >= 0 && aluno[j].b[1].np <= 10){
                    printf("\nValor da prova inseirdo com sucesso!\n");
                    limpar();
                    aluno[j].b[1].np = aluno[j].b[1].np * 0.7;
                    loop = 0;
                }
                else{
                    msg_erro("A nota deve ser entre 0 e 10.");
                }
            }
            else{
                msg_erro("Valor invalido para a nota da prova");
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

    *dados_inseridos = 1;

}