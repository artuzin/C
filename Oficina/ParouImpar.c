#include <stdio.h>

int x;

int ParOuImpar(){
    printf("Digite um valor inteiro: ");
    scanf("%d", &x);

    if(x % 2 == 0){
        return 1;
    }
    else{
        return 0;
    }
}
void imprimir(){
    if(ParOuImpar() == 1){
        printf("Seu valor %d e par.", x);
    }
    else{
        printf("Seu valor %d e impar.", x);
    }
}
int main(){
    imprimir();
    return 0;
}
