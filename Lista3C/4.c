#include <stdio.h>
#include <stdlib.h>

int imprimir(int *v){
    printf("Primeiro valor: %d\n", *v);
    v++; //avança uma posição dentro do ponteiro, indo para o proximo elemento do vetor
    printf("Segundo valor: %d\n", *v);
    v++;
    printf("Terceiro valor: %d\n", *v);
    return 0;
}
int main(){
    int *v = (int*)malloc(3 * sizeof(int));
    
    int *v_start = v; //guarda a posição inicial do ponteiro em outro ponteiro

    printf("Digite o primeiro valor do array: ");
    scanf("%d", v);
    v++;
    printf("Digite o segundo valor do array: ");
    scanf("%d", v);
    v++;
    printf("Digite o terceiro valor do array: ");
    scanf("%d", v);

    v = v_start; //retoma o ponteiro a sua primeira posição
    
    imprimir(v);

    return 0;
    
}