#include "utils.h"

int validar_nome(char *nome){
    for(size_t i = 0; i < strlen(nome); i++){
        if(!isalpha(nome[i]) && nome[i] != '\n'){
            return 0;
        }
    }
    return 1;
}

void limpar(){
    while(getchar() != '\n' && EOF);
}

void msg_erro(char *msg){
    system(LT);
    printf("\n========Erro========\n");
    printf("%s", msg);
    printf("\n====================\n");
    printf("\nAperte <ENTER> para retornar.\n");
    limpar();
    getchar();
}

void dados_emprestimo(){}
