#include <stdio.h>
#include <stdlib.h>

int imprimir(int *v){
    printf("Valores do vetor: %d\n", *v);
    *v++; //avança uma posição dentro do ponteiro, indo para o proximo elemento do vetor
    printf("Valores do vetor: %d\n", *v);
    *v++;
    printf("Valores do vetor: %d\n", *v);
    return 0;
}
int main(){
    int *v = (int*)malloc(3 * sizeof(int));
    
    int *v_start = v;

    printf("Digite o primeiro valor do array: ");
    scanf("%d", v);
    v++;
    printf("Digite o segundo valor do array: ");
    scanf("%d", v);
    v++;
    printf("Digite o terceiro valor do array: ");
    scanf("%d", v);

    v = v_start;
    
    imprimir(v);

    return 0;
    
}