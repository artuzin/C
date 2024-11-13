#include <stdio.h>

float *v[10] = {1, 4, 79, 13, 67, 555, 78, 312, 50, 9};

int main(){

    for(int i = 0; i < 10; i++){
        printf("O endereco da posicao %d e %p\n", i, v[i]);
    }
    
    return 0; 
}