#include <stdio.h>

const int m = 6;
const int n = 6;

int main(){
int v[m];
int p[n], i[n];
int a;

    for(int i = 0; i < m; i++){
        for(int j = 0; j < 6; j++){
            printf("Digite numero para integrarem a matriz: ");
            scanf("%d", &a);
            if(a % 2 == 0){
            p[j] = a;
            }
        }

    }
}    