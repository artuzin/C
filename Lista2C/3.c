#include <stdio.h>

const int m = 5;
const int n = 5;

int main(){

int par[n], imp[n];
int x, numero; //auxiliador de organização e atrbuidor de par ou ímpar
int cp = 0, ci = 0; //contador de quantos números pares e ímpares existem

for(int i = 0; i < 10; i++){
    printf("Digite o %d° valor: ", i + 1);
    scanf("%d", &numero);
    //atribui os números nos seus respectivos vetores e contam quantos tem
    if(numero % 2 == 0){
        par[cp++] = numero;
    }
    else{
        imp[ci++] = numero;
    }
}

//organizando os pares em crescente
for(int i = 0; i < cp; i++){
    for(int o = i + 1; o < cp; o++){
        if(par[i] > par[o]){
            x = par[i];
            par[i] = par[o];
            par[o] = x;
        }
    }
}

//organizando os ímpares em decrescente
for(int i = 0; i < ci; i ++){
    for(int o = i + 1; o < ci; o++){
        if(imp[i] < imp[o]){
            x = imp[i];
            imp[i] = imp[o];
            imp[o] = x;
        }
    }
}

//printando os numeros organizados
printf("Numeros pares: \n");
for(int i = 0; i < cp; i++){
    printf("%d ", par[i]);
}
printf("\nNumeros impares: \n");
for(int i = 0; i < ci; i++){
    printf("%d ", imp[i]);
}
   
return 0;
    
}    