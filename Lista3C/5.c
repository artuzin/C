#include <stdio.h>
#include <stdlib.h>

int tp = 0;
int ts = 0;

int soma(int *p, int *s, int *r){
    if(tp != ts){
        return 0;
    }
    else{
        for(int i = 0; i < tp; i++){
            *(r + i) = (*(p + i)) + (*(s + i));
        }
        return 1;
    }
}
int main(){
     
    
    printf("Digite o tamanho do primeiro array: ");
    scanf("%d", &tp);
    printf("Digite o tamanho do segundo array: ");
    scanf("%d", &ts);

    int *p = (int*)malloc(tp * sizeof(int));
    int *s = (int*)malloc(ts * sizeof(int));
    int *r = (int*)malloc(tp * sizeof(int));

    for(int i = 0; i < tp; i++){
        printf("Digite o %d valor do primeiro array: ", i + 1);
        scanf("%d", p + i);
    }
    for(int i = 0; i < ts; i++){
        printf("Digite o %d valor do segundo array: ", i + 1);
        scanf("%d", s + i);
    }
    if(soma(p, s, r) == 0){
        printf("Os tamanhos dos arrays sao diferentes. Nao e possivel realizar a soma");
    }
    else{
        printf("A funcao soma retornou %d\n\n", soma(p, s, r));
        for(int i = 0; i < tp; i++){
            printf("O %d valor do array resultado e %d\n", i, *(r + i));
        }
    }    
}