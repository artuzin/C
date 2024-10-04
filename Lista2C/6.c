#include <stdio.h>

int main() {
int m[3][3]; 
int par[3] = {0};// contador de números pares nas linhas pares 
int imp[3] = {0}; // contador de números ímpares nas linhas ímpares (
int n;
    
    // inicializar valores negativos para marcar espaços vazios
for (int i = 0; i < 3; i++){
    for (int j = 0; j < 3; j++){
        m[i][j] = -1;
    }
}

    // ler numeros, armazenando eles nas linhas certas
for (int k = 0; k < 3 * 3; k++){
    printf("Digite um numero: ");
    scanf("%d", &n);

    if (n % 2 == 0){ // pares
        int cheio = 0;
        for (int i = 0; i < 3; i += 2){ // linhas pares 
            for (int j = 0; j < 3; j++){
                if (m[i][j] == -1) { // verifica se a posição está vazia
                    m[i][j] = n;
                    cheio = 1;
                    par[i]++;
                    break;
                }
            }
            if (cheio) break; //condição para determinar se cabe um valor ali
        }
        if (!cheio){
            printf("Nao tem mais lugar nas linhas pares.\n");
        }
    } else { // impares
        int cheio = 0;
        for (int i = 1; i < 3; i += 2){ // linha ímpar 
            for (int j = 0; j < 3; j++){
                if (m[i][j] == -1){ // verifica se a posição está vazia
                    m[i][j] = n;
                    cheio = 1;
                    imp[i]++;
                    break;
                }
            }
            if (cheio) break;
        }
        if (!cheio){
            printf("Nao tem mais lugar nas linhas ímpares.\n");
        }
    }
}

// Exibir a matriz resultante
printf("\nMatriz final:\n");
for (int i = 0; i < 3; i++){
    for (int j = 0; j < 3; j++){
        if (m[i][j] == -1){
            printf(" _ "); // ocupa todas as posicões
        } else {
            printf(" %d ", m[i][j]);
        }
    }
    printf("\n");
}

return 0;
}