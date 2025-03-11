#include <stdio.h>
char n;
int main(){
    printf("Escolha entre 0 ou 1: \n");
    scanf("%c", &n);
    if(n == '0' || n == '1'){
        printf("Valido! \n :]");
    }
    else{
        printf("Invalido! \n :/");
    }
}