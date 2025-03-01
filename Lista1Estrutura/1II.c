#include <stdio.h>

void main(){
    float salario, nsalario = 0;
    int opcao;

    do{
        printf("Programa de reajuste salarial\n");
        printf("Deseja continuar?\n1-Continuar\n2-Sair\n");
        scanf("%i", &opcao);
        
        if(opcao == 1){
            printf("Insira seu salario: ");
            int conferir_tipo = scanf("%f", &salario); //conferir_tipo tera valor 1 se um float foi associado a variavel salario e valor 0 se outro tipo for associado, pois scanf retorna 1 se conseguir associar corretamente

            if(conferir_tipo == 1 && salario >= 0){
                nsalario = salario * 1.25;
                printf("Seu novo salario apos o reajuste e de: %.2f\n", nsalario);
                break;
            }
            else{
                printf("Valor invalido para o salario, tente novamente.");
            }

        }
        else if(opcao != 2){
            printf("Opcao invalida! Tente novamente.\n");
        }
    }while(opcao != 2);
    printf("Encerrando programa...");
}

    
    

