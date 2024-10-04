#include <stdio.h>


int main(){
//declaração de variáveis    
int a[3][2];
int b[3][2];
int c[3][2]; 
//atribuição de valores nas matrizes
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 2; j++){
            printf("Digite valores para estarem na matriz A: ");
            scanf("%d", &a[i][j]);
        }
    }
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 2; j++){
            printf("Digite valores para estarem na matriz B: ");
            scanf("%d", &b[i][j]);
        }
    }
//compara as duas matrizes e atrbui 1 se for verdadeiro e 0 se for falso    
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 2; j++){
            if(a[i][j] == b[i][j]){
                c[i][j] = 1;
            }
            else{
                c[i][j] = 0;
            }
        }
    }
//printa os valores das matrizes
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 2; j++){
            printf("Matriz A: %d\n", a[i][j]);
        }
    }
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 2; j++){
            printf("Matriz B: %d\n", b[i][j]);
        }
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 2; j++){
            printf("Matriz C: %d\n", c[i][j]);
        }
    }
    return 0;
    }
}