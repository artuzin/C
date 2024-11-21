#include <stdio.h>
#include <stdlib.h>

int ord(int *a,int *b, int *c){
    if(*a == *b && *b == *c){
        return 1;
    }
    else{
        if(*a > *b){
            *a = *a + *b;
            *b = *a - *b;
            *a = *a - *b;
        }
        if(*a > *c){
            *a = *a + *c;
            *c = *a - *c;
            *a = *a - *c;
        }
        if(*b > *c){
            *b = *b + *c;
            *c = *b - *c;
            *b = *b - *c;
        }
            return *a, *b, *c;
    }
}

int main(){
    //a função malloc reserva espaço de memoria para o ponteiro guardar um valor inteiro
    int *a = (int*) malloc(sizeof(int));
    int *b = (int*) malloc(sizeof(int));
    int *c = (int*) malloc(sizeof(int));

    printf("Digite um valor para A: ");
    scanf("%d", a);
    printf("Digite um valor para B: ");
    scanf("%d", b);
    printf("Digite um valor para C: ");
    scanf("%d", c);

    if(ord(a, b, c) == 1){
        printf("Os valores de A, B e C sao o mesmo");
    }
    else{
        printf("Os valores em ordem crescente sao: %d, %d e %d", *a, *b, *c);
    }

}