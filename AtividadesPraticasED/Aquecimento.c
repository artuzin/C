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
    aluno aluno;;
    int validar;
    int loop = 1;
    int opcao = 0;
    
    while(1){
        printf("\n\n--------Programa de registro de notas--------\n\n");

        printf("1-Iniciar programa\n2-Consultar notas\n3-Sair\nEscolha uma opcao: ");
        scanf("%d", &opcao);
        limpar();

        switch (opcao)
        {
        case 1:
                while(loop == 1){
                    printf("Insira o RA do aluno: ");
                    
                    validar = scanf("%d", &aluno.ra);
                    
                    limpar();

                    if(validar == 1 && aluno.ra > 10000000 && aluno.ra < 99999999){
                        printf("\nRA inserido com sucesso!\n");
                        loop = 0;
                    }
                    else{
                        printf("Valor inserido nao corresponde a um RA, tente novamente!\n");
                    }
                    
                }

                loop = 1;

                for(int i = 0; i < 3;){
                    while(i < 3){
                        printf("Digite a nota de numero %d do primeiro bimestre: ", i + 1);
                        
                        validar = scanf("%f", &aluno.b[0].ap[i]);
                        
                        limpar();

                        if(validar == 1 && aluno.b[0].ap[i] >= 0 && aluno.b[0].ap[i] <= 10){
                            printf("\nA nota foi inserida com sucesso\n\n");
                            i++;
                        }
                        else{
                            printf("O valor inserido nao corresponde a uma nota, tente novamente!\n");
                        }
                    }
                }

                while(loop == 1){
                    printf("Digite o valor da nota da prova do primeiro bimestre: ");

                    validar = scanf("%f", &aluno.b[0].np);

                    if(validar == 1 && aluno.b[0].np >= 0 && aluno.b[0].np <= 10){
                        printf("\nValor da prova inseirdo com sucesso!\n");
                        loop = 0;

                        aluno.b[0].np = aluno.b[0].np * 0.7;

                    }
                    else{
                        printf("Valor invalido para a nota da prova");
                    }
                    
                }

                loop = 1;

                for(int i = 0; i < 3;){
                    while(i < 3){
                        printf("Digite a nota de numero %d do segundo bimestre: ", i + 1);
                        
                        validar = scanf("%f", &aluno.b[1].ap[i]);
                        
                        limpar();

                        if(validar == 1 && aluno.b[1].ap[i] >= 0 && aluno.b[1].ap[i] <= 10){
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

                    validar = scanf("%f", &aluno.b[1].np);

                    if(validar == 1 && aluno.b[1].np >= 0 && aluno.b[1].np <= 10){
                        printf("\nValor da prova inseirdo com sucesso!\n");
                        loop = 0;

                        aluno.b[1].np = aluno.b[1].np * 0.7;

                    }
                    else{
                        printf("Valor invalido para a nota da prova");
                    }
                    
                }

                aluno.b[0].media_ap = ((aluno.b[0].ap[0] + aluno.b[0].ap[1] + aluno.b[0].ap[2]) / 3);
                aluno.b[0].av = (aluno.b[0].media_ap * 0.3) + aluno.b[0].np;

                aluno.b[1].media_ap = ((aluno.b[1].ap[0] + aluno.b[1].ap[1] + aluno.b[1].ap[2]) / 3);
                aluno.b[1].av = (aluno.b[1].media_ap * 0.3) + aluno.b[1].np;

                aluno.nf = (aluno.b[0].av + aluno.b[1].av) / 2;

                if(aluno.nf >= 6){
                    printf("Aprovado!");
                }
                else{
                    printf("Reprovado!");
                }

            break;
        case 2:
        
            break;
        case 3:
            printf("\nSaindo do programa...\n\n");
            return 0;
        default:
            printf("Opcao invalida, insira um valor valido.");
        }

    }
}