#include<stdio.h>
int main(){
   float a, b, c, x;
    printf("Digite um valor: ");
    scanf("%f", &a);
    printf("Digite um valor: ");
    scanf("%f", &b);
    printf("Digite um valor: ");
    scanf("%f", &c);
    
    x = a;

    if(x < b){
        x = b;
    }
    if(x < c){
        x = c;
    }
    printf("O maior valor é: %f", x);
}

