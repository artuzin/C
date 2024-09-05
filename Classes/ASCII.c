#include <stdio.h>

int main(){
    int i;
    printf("Tabela ASCII: \n");
    printf("Dec Char\n");

    for(i=32; i<127; i++){
        printf("%3d %c\n", i, i);
    }
    return 0;
}