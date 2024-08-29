#include <stdio.h> 
int main(){
    float s, ns;

    printf("Digite seu salario: \n");
    scanf("%f",&s);
    if (s < 500){
        ns = s * 1.15;
    }
    else{
        if (s <= 1000){
            ns = s *1.1;
        }
        else {
            ns = s * 1.05;
    }
    }
    printf("Seu novo salario e: %.2f",ns);
}