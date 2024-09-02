#include <stdio.h>
int n;
int main(){
    printf("Digite um numero entre 0 e 50: ");
    scanf("%d", &n);
    if(n>=0 && n<=50){
        printf("Voce digitou %d, valido \n", n);
    }
    else{
        printf("Voce digitou %d, invalido \n", n);
    }
return 0;
}
