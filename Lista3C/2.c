#include <stdio.h>

int v[5] = {0, 0, 0, 0, 0};

int main(){

    for(int i = 0; i < 5; i++){
        printf("Digite um numero inteiro para compor o vetor: ");
        scanf("%d", &v[i]);
    }

    for(int i = 0; i < 5; i++){

        int *p = &v[i];

        if(*p % 2 == 0){
            printf("O valor %d e par e seu endereco e %p\n", *p, p);
        }
        else{
            printf("O valor %d e impar, portanto nao tera seu endereco impresso\n", *p);
        }
    }

    return 0;
}