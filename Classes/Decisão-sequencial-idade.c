#include<stdio.h> //else if serve como um "mas se"
int main(){
    int i;
    printf("Digite sua idade: ");
    scanf("%d", &i);
        if(i>=18){
            printf("Voce e maior de idade, e pode votar.\n");
        }
        else if(i>=16){
            printf("Voce e menor de idade, mas pode votar.\n");
        }
        else{
            printf("Voce e menor de idade e nao pode votar.\n");
        }
    return 0;
}