#include <stdio.h>

//declaração do tamanho do vetor
const int max = 10;

int main(){
    
    int v[max], ref, f[max], j = 0; //contador do vetor dos valores maiores começa em 0
    int z = 0; //contador de valores menores
    int y = 0; //contador de valores iguais à referência


    printf("Digite um valor de referencia inteiro: "); //cria a referência
    scanf("%d", &ref); 
    
    for(int i = 0 ; i < max; i++){
        printf("Digite um valor inteiro: ");
        scanf("%d", &v[i]); //atribui cada valor ao vetor
        }
    for(int i = 0; i < max; i++){  //verifica se os valores de v são maiores que a referência
            if(v[i] > ref){
                f[j] = v[i]; //atribui cada valor do vetor a um novo vetor, se for maior
                j++; //adiciona 1 ao contador apenas se o valor do vetor for maior que a referência
            }
            else if(v[i] < ref){ 
                z++; //soma ao contador se for menor
            }
            else{
                y++; //soma se for igual a referencia
            }
        }    
    
    printf("Valores maiores que %d: \n", ref); 
    
    for(int i = 0; i < j; i++){ //confere os valores até o máximo do contador J
     printf("%d\n", f[i]);  //printa todos os valores maiores que a referência
     }
    printf("O numero de valores menores que a referencia e: %d\n", z);
    printf("O numero de vezes que a referencia aparece no vetor e de: %d", y); 
     return 0;
}