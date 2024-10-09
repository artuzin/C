#include <stdio.h>

int main(){
    int a, b, c;

    printf("Digite um valor para A: ");
    scanf("%d", &a);
    printf("Digite um valor para B: ");
    scanf("%d", &b);
    printf("Digite um valor para C: ");
    scanf("%d", &c);

    if(a > b){
        a = a + b;
        b = a - b;
        a = a - b;
    }
    if(a > c){
        a = a + c;
        c = a - c;
        a = a - c;
    }
    if(b > c){
        b = b + c;
        c = b - c;
        b = b - c;
    }

    printf("Os valores em ordem crescente sao: %d, %d, %d", a, b, c);

    return 0;
}
