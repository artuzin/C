#include <stdio.h>
#include <stdlib.h>

int tp = 0; //variavel do tamanho do primeiro e segundo arrays
int ts = 0;

int soma(int *p, int *s, int *r){ //recebe como parametro os ponteiros do primeiro e segundo array, e tambem do resultado
    if(tp != ts){
        return 0; //retorna 0 se o tamanho dos dois arrays for diferente
    }
    else{
        for(int i = 0; i < tp; i++){
            *(r + i) = (*(p + i)) + (*(s + i)); //somatorio dos valores do array por aritmetica
        }
        return 1;
    }
}
int main(){
     
    // definindo o tamanho dos arrays
    printf("Digite o tamanho do primeiro array: ");
    scanf("%d", &tp);
    printf("Digite o tamanho do segundo array: ");
    scanf("%d", &ts);

    int *p = (int*)malloc(tp * sizeof(int)); //reservando espaço na memoria para os dois arrays
    int *s = (int*)malloc(ts * sizeof(int));
    int *r = (int*)malloc(tp * sizeof(int));

    //atribui os valores nas duas arrays, respeitando o tamanho definido antes
    for(int i = 0; i < tp; i++){
        printf("Digite o %d valor do primeiro array: ", i + 1);
        scanf("%d", p + i);
    }
    for(int i = 0; i < ts; i++){
        printf("Digite o %d valor do segundo array: ", i + 1);
        scanf("%d", s + i);
    }
    if(soma(p, s, r) == 0){ //chama a função com seus parametros e ja confere seus retornos
        printf("A funcao retornou %d e os tamanhos dos arrays sao diferentes. Nao e possivel realizar a soma", soma(p, s, r));
    }
    else{
        printf("A funcao soma retornou %d\n\n", soma(p, s, r));
        for(int i = 0; i < tp; i++){
            printf("O %d valor do array resultado ficou %d\n", i, *(r + i));
        }
    }    
}