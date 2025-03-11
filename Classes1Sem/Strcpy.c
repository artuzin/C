#include <stdio.h>
#include <string.h>

int main(){
    char str1[20];
    char str2[20];

    printf("Digite uma frase: ");
    fgets(str1, 20, stdin);

    strcpy(str2, str1);

    printf("str1: %s\n", str1);
    printf("str2: %s\n", str2);

    return 0;
}