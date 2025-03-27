#include "utils.c"

int validar, opcao, n_clientes;

while(l1){
    printf("\n\n--------Programa de Simulacao de Emprestimo--------\n\n");

    printf("Digite quantos clientes deseja registrar o emprestimo:");
    scanf("%d", &n_clientes);

    printf("1- Iniciar programa\n2-Sair\nEscolha uma opcao: ");

    validar = scanf("%d", &opcao);
    limpar();

    switch (opcao){
    case 1:
        
        break;
    
    case 2:
        dados_emprestimo();
    case 3:
        printf("Saindo do programa...\n");
        exit(1);
    default:
        break;
    }
}