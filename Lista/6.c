#include <stdio.h>

int main(){
    int m[3][3];
    int a;

    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            printf("Digite um valor para ser armazenado no matriz [3x3]: ");
            scanf("%d", &a);
            if(a % 2 == 0){
                m[i%2==0][j] = a;
            }
            else{
                m[i%2!=0][j] = a;
            }
        }
    }
   for(int i = 0; i < 3; i++){
      for(int j = 0; j < 3; j++){
           printf("%d", m[i][j]);
        printf("\n");
       }
   }
    
    return 0;
}