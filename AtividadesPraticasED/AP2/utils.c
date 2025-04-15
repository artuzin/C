#include "utils.h"

int validar_nome(char *nome){
    for(size_t i = 0; i < strlen(nome); i++){
        if(!isalpha(nome[i]) && nome[i] != ' '){
            return 0;
        }
    }
    return 1;
}

void limpar(){
    char c;
    while((c = getchar()) != '\n' && c != EOF);
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

void calculo_parcela(cliente *cliente, int n_clientes){
    for(int j = 0; j < n_clientes;){
        cliente[j].emprestimo.parcela = cliente[j].emprestimo.valor / cliente[j].emprestimo.meses;
        j++;
    }
}

void dados_emprestimo(cliente *cliente, int *situacao, int n_clientes){
    for(int j = 0; j < n_clientes; j++){
        
        printf("Nome do cliente: %s\n", cliente[j].nome);
        printf("Salario: %.2f\n", cliente[j].salario);
        printf("Parcelas: %.2f\n", cliente[j].emprestimo.parcela);
        
        if(situacao[j] == 1){
            printf("Situacao: Emprestimo aprovado!\n\n");
        }
        else{
            printf("Situacao: Emprestimo reprovado!\n\n");
        }
        
    }
}
