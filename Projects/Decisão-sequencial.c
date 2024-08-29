#include <stdio.h>
int main(){
    int n;
        printf("Digite um valor inteiro: ");
        scanf("%d", &n );

        if (n == 1){
            printf("Você entrou o valor 1");
        }
        if (n == 2){
            printf("Você entrou o valor 2");
        }
        if (n < 1 ){
            printf("Você entrou um valor muito baixo");
        }
        if (n > 2){
            printf("Você entrou um valor muito alto");
        }
        return 0;

}