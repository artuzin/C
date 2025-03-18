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
                printf("xereca!!!!!!!!!!!!!");
                for(int i = 0; i < 3;){
                    while(i < 3){
                        
                    }
                }
            break;
        case 2:
        
            break;
        case 3:
            printf("\nSaindo do programa...\n\n");
            exit(1);
        default:
            break;
        }

    }
}