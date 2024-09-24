#include <stdio.h>
#include <string.h>

const int max = 50; 
int main(){
    char p[max], pi[max]; //palavra normal e invertida para checagem se é palíndromo
    int x, y; //variaveis de controle da inversao da palavra para conferencia
    int z; //controle do tamanho da string

    printf("Digite uma palavra: ");
    fgets(p, max, stdin);
    
    p[strcspn(p, "\n")] = '\0'; //procura o '\n' na string "p"

    z = strlen(p);
   
    x = z - 1; //elimina o \0 da string e atribui apenas o numero de letras a nova variavel
    y = 0;
    while(y < z){ //enquanto o y for menor que o numero de letras na palavra, as letras serao colocadas de forma inversa
        pi[y] = p[x]; //põe o último valor da string escrita e posiciona na primeira posição da string inversa
        x--;
        y++; //x diminui para a palavra ser lida de tras para frente e y aumenta para haver a troca do inicio ao fim na nova palavra
    }  
    
    pi[y] = '\0';  // finaliza a string invertida
    
    printf("Sua palavra invertida e: %s\n", pi);

    if(strcmp(p, pi) == 0){
        printf("Sua palavra e um palindromo");
    }
    else{
        printf("Sua palavra nao e um palindromo");
    }

return 0;
}