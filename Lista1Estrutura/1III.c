#include <stdio.h>

void main(){
    float ap1[3], ap2[3], np1, np2, av1, av2, nf;
    int opcao = 0;
    
    while(1){
        printf("Programa de registro e calculo de notas.\n");
        printf("Escolha um opcao:\n1-Iniciar programa\n2-Encerrar\n");
        scanf("%i", &opcao);
        
        
        
        switch (opcao) {
            case 1:
                for(int i = 0; i < 3;){
                    while(i < 3){
                        printf("Digite a nota da atividade pratica de numero %i do primeiro bimestre:(O valor deve ser positivo e entre 0-10)\n", i+1);
                        int validar = scanf("%f", &ap1[i]);
                        if(validar == 1 && 10 >= ap1[i] && ap1[i] > 0){
                            printf("Valor inserido com sucesso.\n");
                            i++;
                        }
                        else{
                            printf("O valor digitado nao pode ser inserido, tente novamente.\n\n");
                            while(getchar() != '\n');
                        }
                    }
                }
                while(1){
                    printf("Digite o valor da prova do primeiro bimestre:(O valor deve ser positivo e entre 0-10)\n");
                    int validarprova1 = scanf("%f", &np1);
                    if(validarprova1 == 1 && 10 >= np1 && np1 > 0){
                        printf("Valor da prova do primeiro bimestre inserido com sucesso!\n\n");
                        break;
                    }
                    else{
                        printf("Valor inserido nao esta no formato adequado, tente novamente.\n");
                        while(getchar() != '\n');
                    }
                }
                for(int i = 0; i < 3;){
                    while(i < 3){
                        printf("Digite o valor de numero %i do segundo bimestre:(O valor deve ser positivo e entre 0-10)\n", i+1);
                        int validar = scanf("%f", &ap2[i]);
                        if(validar == 1 && 10 >= ap2[i] && ap2[i] > 0){
                            printf("Valor inserido com sucesso.\n");
                            i++;
                        }
                        else{
                            printf("O valor digitado nao pode ser inserido, tente novamente.\n");
                            while(getchar() != '\n');
                        }
                    }
                }

            case 2:
                printf("Encerrando programa...");
                return 0;
            default:
                printf("Opcao invalida, tente novamente.\n");
        }
    }
}