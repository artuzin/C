#include <stdio.h>

const int max = 10;
int i, z;

int main(){
    int v[max], ref, f[max]; 
    
    printf("Digite um valor de referência inteiro: ");
    scanf("%d", &ref); 
    
    for(i = 0 ; i < max; i++){
        printf("Digite um valor inteiro: ");
        scanf("%d", &v[i]);
        }
    for(i = 0; i < max; i++){
            if(v[i] > ref){
                f[i] = v[i];
            }
        }
    for(i = 0; i < max; i++){ 
     printf("%d", f[i]);}
     return 0;
}