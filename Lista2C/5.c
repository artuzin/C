#include <stdio.h>

int dur, hr, resto, min, seg; //declaração de variáveis 

int main(){
    printf("Digite um valor em segundos: ");
    scanf("%d", &dur); //duração total do tempo

    //operações necessárias para encontrar as diferentes partes da hora

    hr = dur / 3600;    //parte inteira das horas
    resto = dur % 3600; //segundos que não completam 1 hora

    min = resto / 60;   //minutos inteiros
    seg = resto % 60;   //segundos restantes

    printf("O tempo fornecido em segundos equivale a: %d hora(s), %d minuto(s) e %d segundo(s).", hr, min, seg);
}