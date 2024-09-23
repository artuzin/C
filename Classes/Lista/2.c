#include <stdio.h>
const int max = 10;
int main(){
    int v[max];
    int ref;
    printf("Digite um valor de referência inteiro: ");
    scanf(%d, &ref); 
     for(int i = 0 ; i < max; i++){
        printf("Digite um valor inteiro: ");
        scanf(%d, &v[i]);
     }
}