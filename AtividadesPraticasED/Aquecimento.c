#include <stdio.h>
#include <stdlib.h>

int opcao = 0;

typedef struct{
    float ap[3];
    float media, np, av;
}b;

typedef struct {
    b bimestre[2];
    int ra;
    float nf;
}aluno;

void limpar(){
    while(getchar() != '\n' && EOF);
}

int main(){
    aluno aluno;
    b b;
    int validar;
    int loop = 1;
    
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
                        printf("RA inserido com sucesso!\n");
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
                        
                        validar = scanf("%f", &b.ap[i]);
                        
                        limpar();

                        if(validar == 1 && b.ap[i] >= 0 && b.ap[i] <= 10){
                            printf("A nota foi inserida com sucesso\n\n");
                            i++;
                        }
                        else{
                            printf("O valor inserido nao corresponde a uma nota, tente novamente!\n");
                        }
                    }
                }

                while(loop == 1){
                    printf("Digite o valor da nota da prova do primeiro bimestre: ");

                    validar = scanf("%f", &b.np);

                    if(validar == 1 && b.np >= 0 && .np <= 0){
                        printf("\nValor da prova inseirdo com sucesso!\n");
                        loop = 0;
                    }
                    else{
                        printf("Valor invalido para a nota da prova");
                    }
                    
                }

                loop = 1;

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