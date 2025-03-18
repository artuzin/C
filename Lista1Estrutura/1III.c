#include <stdio.h>

//Faça uma narração/fluxo que represente o cadastro de notas de alunos de determinada disciplina a partir das seguintes fórmulas expressas pelas Equações abaixo:


//O algoritmo deve ler as notas das atividades práticas (AP1, AP2 e AP3) e a nota da prova (NP) considerando as duas avaliações (AV1 e AV2) e, em seguida, calcular a nota final (NF) de cada aluno.

void main(){
    float ap1[3], ap2[3], np1, np2, av1, av2, nf;
    int opcao = 0;
    
    while(1){
        printf("Programa de registro e calculo de notas.\n");
        
        printf("Escolha um opcao:\n1-Iniciar programa\n2-Encerrar\n");
        
        scanf("%i", &opcao);
        
        while(getchar() != '\n');
        
        switch (opcao) {
            case 1:
                for(int i = 0; i < 3;){
                    while(i < 3){
                        printf("Digite a nota da atividade pratica de numero %i do primeiro bimestre:(O valor deve ser positivo e entre 0-10)\n", i+1);
                        
                        int validar = scanf("%f", &ap1[i]);
                        
                        while(getchar() != '\n'); //limpa o dado previamente associado pelo scanf, nao permitindo um loop infinito
                        
                        if(validar == 1 && 10 >= ap1[i] && ap1[i] >= 0){
                            printf("Valor inserido com sucesso.\n");
                            i++;
                        }
                        else{
                            printf("O valor digitado nao pode ser inserido, tente novamente.\n\n");
                        }
                    }
                }
                while(1){ //loop com o while, tornando possivel a repeticao ate que um valor que satisfaca as condicoes do if seja inserido
                    printf("Digite o valor da prova do primeiro bimestre:(O valor deve ser positivo e entre 0-10)\n");
                    
                    int validarprova1 = scanf("%f", &np1);
                    
                    while(getchar() != '\n' && EOF);
                    
                    if(validarprova1 == 1 && 10 >= np1 && np1 >= 0){
                        printf("Valor da prova do primeiro bimestre inserido com sucesso!\n\n");
                        np1 = np1 * 0.7;
                        break;
                    }
                    else{
                        printf("Valor inserido nao esta no formato adequado, tente novamente.\n");
                    }
                }
                for(int i = 0; i < 3;){
                    while(i < 3){
                        printf("Digite o valor de numero %i do segundo bimestre:(O valor deve ser positivo e entre 0-10)\n", i+1);
                        
                        int validar = scanf("%f", &ap2[i]);
                        
                        while(getchar() != '\n');
                        
                        if(validar == 1 && 10 >= ap2[i] && ap2[i] >= 0){
                            printf("Valor inserido com sucesso.\n");
                            i++;
                        }
                        else{
                            printf("O valor digitado nao pode ser inserido, tente novamente.\n");
                        }
                    }
                }
                while(1){
                    printf("Digite o valor da prova do segundo bimestre:(O valor deve ser positivo e entre 0-10)\n");
                    
                    int validarprova2 = scanf("%f", &np2);
                    
                    while(getchar() != '\n');
                    
                    if(validarprova2 == 1 && 10 >= np2 && np2 >= 0){
                        printf("Valor da prova do segundo bimestre inserido com sucesso!\n\n");
                        np2 = np2 * 0.7;
                        break;
                    }
                    
                    else{
                        printf("Valor inserido nao esta no formato adequado, tente novamente.\n");
                    }
                }
    
                av1 = ((ap1[0] + ap1[1] + ap1[2])/3) * 0.3 + np1;
    av2 = ((ap2[0] + ap2[1] + ap2[2])/3) * 0.3 + np2;

    nf = (av1 + av2)/2;

    printf("A nota final do aluno foi de %.2f\n", nf);


            case 2:
                printf("Encerrando programa...");
                return 0;
            
                default:
                printf("Opcao invalida, tente novamente.\n");
        }
    }
}