#include <stdio.h> 
 const int tm = 5;
     int main(){
        int vetor[tm];
        for(int i = 0; i < tm; i++){
            vetor[i] = pow(i, 2);
        }
        for(int i = 0; i < tm; i++){
            printf("Meu vetor[%d] = %d\n", i, vetor[i]);        

     }
     return 0;
     }