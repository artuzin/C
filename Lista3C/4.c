#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int imprimir(int *v){
    printf("Valores do vetor: %d\n", *v);
    v = v + 1; //avaça uma posição dentro do ponteiro, indo para o proximo elemento do vetor
    printf("Valores do vetor: %d\n", *v);
    v = v + 1;
    printf("Valores do vetor: %d\n", *v);
    return 0;
}
int main(){
    int *v = (int*)malloc(3 * sizeof(int));
    int vetor[] = {4, 77, 123};

    memcpy(v, vetor, 3 * sizeof(int)); //copia o numero de bytes declarados no terceiro parametro do segundo parametro ao primeiro (do array ate o ponteiro)
    
    imprimir(v);

    return 0;
    
}