#include<stdio.h>
int main(){
    float x;
    float total=0;
    float media;
    float cont=0;
    char letra;

do{
    printf("Digite sua nota: \n");
    scanf("%f", &x);
    cont++;
    total += x;
    printf("Digite q para sair ou outra letra para continuar a colocar suas notas: ");
    scanf(" %c", &letra);
} while(letra!='q');
media = total/cont;
printf("Sua media foi: %.2f \n", media);

return 0;

}