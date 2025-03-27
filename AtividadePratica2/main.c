#include "utils.c"

int validar, loop = 1, opcao = 0, n_alunos;

int main(){
    
    printf("\n\n--------Programa de registro de notas--------\n\n");

    while(loop == 1){
        printf("Digite quantos alunos deseja cadastrar (INSIRA UM VALOR INTEIRO):");

        if(scanf("%i", &n_alunos) == 1 && n_alunos > 0){
            printf("\n===Prosseguindo com o cadastro de %d aluno(s)===\n\n", n_alunos);
            loop = 0;
            limpar();
        }
        else{
            msg_erro("Valor invalido para o numero de alunos, insira outro.");
        }
    }
    
    aluno aluno[n_alunos];
    int situacao[n_alunos];
    int dados_inseridos = 0;
    loop = 1;

    while(1){

        printf("1-Iniciar programa\n2-Consultar notas\n3-Sair\nEscolha uma opcao: \n");
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
            media_alunos(aluno, situacao, n_alunos, &dados_inseridos);
            break;
        case 2:
                if(dados_inseridos == 0){
                    msg_erro("\n|||Nao ha dados para serem exibidos, va ate a opcao 1 no menu para inseri-los.|||\n\n");
                }
                else{
                    dados_alunos(aluno, situacao, n_alunos);
                    printf("Pressione <ENTER> para voltar ao menu...");
                    getchar();  
                }
            break;
        case 3:
            printf("\nSaindo do programa...\n\n");
            return 0;
        default:
            printf("Opcao invalida, insira um valor valido.\n");
        }

    }
}