#include <stdio.h>

int main(){
    int a; //numero de alunos na sala
    int t[a]; //matriz total de alunos na sala
    printf("Digite o número de alunos: ");
    scanf("%d", &a);
    for(int i = 0; i < a; i++){
        printf("Digite a nota dos alunos: \n");
        scanf("%d", t[i]);
    }   
}