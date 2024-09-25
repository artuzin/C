#include <stdio.h>
#include <stdlib.h> 
#include <time.h>

int main(){
    int v[10000];
    int c[100] = {0}; //contador de quantas vezes cada número aparece

    srand(time (0)); //garante que a randomização sempre será diferente toda vez que o código rodar
    
    for(int i = 0; i < 10000; i++){
        v[i] = rand() % 100; //randomiza os números inseridos no vetor
        c[v[i]]++; //aumenta o contador  
    }

    //printa todas as ocorrências dos números
    printf("Contagem dos número entre 0 e 99: \n");
    for(int i = 0; i < 100; i++){
        printf("%d ocorreu %d vezes.\n", i, c[i]);
    }
    return 0;
}


