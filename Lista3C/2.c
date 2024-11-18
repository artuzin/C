#include <stdio.h>

int v[5] = {0, 0, 0, 0, 0};


int main(){
 //atribui valores à um vetor de inteiros
    for(int i = 0; i < 5; i++){
        printf("Digite um numero inteiro para compor o vetor: ");
        scanf("%d", &v[i]);
    }

    for(int i = 0; i < 5; i++){

        int *p = &v[i]; //atribui o endereço do valor do vetor à um ponteiro

        //compara os valores atribuidos ao ponteiro a cada iteração do for, checando se eles são pares e ímpares
        if(*p % 2 == 0){ //desreferencia o ponteiro e pega o valor dele para ser comparado
            printf("O valor %d e par e seu endereco e %p\n", *p, p);
        }
        else{
            printf("O valor %d e impar, portanto nao tera seu endereco impresso\n", *p);
        }
    }

    return 0;
}