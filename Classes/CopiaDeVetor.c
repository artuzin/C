#include<stdio.h>
 const int tm = 5;
    int main(){
        int vA[tm];
        int vCopia[tm];
        for(int i = 0; i < tm; i++){
            vA[i] = i + 1;
        }
        for(int i = 0; i < tm; i++){
            vCopia[i] = vA[i];
        }
        for (int i = 0; i < tm; i++){
            printf("O vetor A [%d] = %d\ne o vetor Copia [%d] = %d\n", i, vA[i], i, vCopia[i]);
        }
    }