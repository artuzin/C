#include <stdio.h>
const int tm = 4;
    int main(){
        int vetor[4]; //vetor
        int mv; //maior valor

        //Atribuindo os valores no vetor
        for(int i = 0; i < tm; i++){
            printf("Digite um valor entre 0 e 100: ");
            scanf("%d", &vetor[i]);
        }

        mv = vetor[0]; //Atribuindo na variável o primeiro valor do vetor
        
        //Procurar o maior valor dentro do vetor
        for(int i = 0; i < tm; i++){
            if(vetor[i] > mv){
                mv = vetor[i]; //Troca o valor se for maior
            }
        }
        printf("O maior valor presente no vetor vale %d\n", mv);
        return 0;
    }