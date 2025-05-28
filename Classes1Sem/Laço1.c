#include <stdio.h>
int i, n, r;
int main(){
    i = 1;
    while(i <= 5){
        printf("Digite um numero: ");
        scanf("%d", &n);
        r = n * 3;
        printf("%d \n",r );
        i = i + 1;
    }
}
