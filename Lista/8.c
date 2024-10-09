#include <stdio.h>

const int max = 150; //tamanho maximo de alunos
const int nn = 3; //número de notas para cada aluno

int main(){
int a; //numero de alunos na sala
int t[max][nn]; //matriz dos alunos e notas 
int media[]; //variável das medias
    printf("Digite o número de alunos: ");
    scanf("%d", &a);
    
    for(int i = 0; i < a; i++){ //o número de notas depende de quantos alunos existem na sala
        printf("Digite as notas do aluno %d: \n", i + 1);
        for(int j = 0; j < nn; j++){ //montando as colunas para guardar as notas
            printf("Digite a nota %d: ", j + 1);
            scanf("%d", &t[i][j]);
        }
        printf("\n");
    }
    for(int i = 0; i < nn; i++){
        
    } 
    
    return 0;
}
