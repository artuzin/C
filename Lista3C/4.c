#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int imprimir(int *v){
    printf("Valores do vetor: %d\n", *v);
    v = v + 1;
    printf("Valores do vetor: %d\n", *v);
    v = v + 1;
    printf("Valores do vetor: %d\n", *v);
    return 0;
}
int main(){
    int *v = (int*)malloc(3 * sizeof(int));
    int vetor[] = {4, 77, 123};

    memcpy(v, vetor, 3 * sizeof(int));

    imprimir(v);

    return 0;
    
}