#include<stdio.h>
int main(){
    char letra; 
    int cont=0;
    int total=0;
    int x;

    do{
        printf("Digite um numero: \n");
        scanf("%d", &x);
        cont++;
        total += x;
        printf("Digite q para sair ou outra letra para continuar: \n");
        scanf(" %c", &letra);
    } while(letra != 'q');
    printf("O valor do contador e: %d \n", cont);
    printf("O valor dos valores acumulados ficou: %d \n", total);

    return 0;
}  