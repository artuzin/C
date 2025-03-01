#include <stdio.h>

void main(){
    float ap11, ap12, ap13, ap21, ap22, ap23, av1, av2, np1, np2, nf;
    int opcao = 0;
    
    while(1){
        printf("Programa de registro e calculo de notas.\n");
        printf("Escolha um opcao:\n1-Iniciar programa\n2-Encerrar\n");
        scanf("%i", &opcao);
        
        
        
        switch (opcao) {
            case 1:
                for(int i = 0; i < 3;){
                    printf("Digite a nota de numero %i do primeiro bimestre: ", i);
                    int validar = scanf("%f", &ap1[i]);
                    
                    if(validar == 1){
                        i++;
                    }
                    else{
                        i = 0;
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