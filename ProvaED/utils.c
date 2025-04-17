#include "utils.h"

// Função para calcular as notas finais do aluno{
    void calcular_notas(Aluno *aluno) {
        float ap1 = aluno->avaliacoes[0].ap1;
        float ap2 = aluno->avaliacoes[0].ap2;
        float ap3 = aluno->avaliacoes[0].ap3;
        float np1 = aluno->avaliacoes[0].np;
    
        float ap4 = aluno->avaliacoes[1].ap1;
        float ap5 = aluno->avaliacoes[1].ap2;
        float ap6 = aluno->avaliacoes[1].ap3;
        float np2 = aluno->avaliacoes[1].np;
    
        float notas[8] = {ap1, ap2, ap3, np1, ap4, ap5, ap6, np2};
        for (int i = 0; i < 8; i++) {
            if (notas[i] < 0) notas[i] = 0;
            if (notas[i] > 10) notas[i] = 10;
        }
    
        float AV1 = (((notas[0] + notas[1] + notas[2]) / 3) * 0.3) + (notas[3] * 0.7);
        float AV2 = (((notas[4] + notas[5] + notas[6]) / 3) * 0.3) + (notas[7] * 0.7);
        float nf = (AV1 + AV2) / 2;
    
        aluno->nf = nf;
        aluno->status = (nf >= 6.0) ? 1 : 0;
    }

// Função para alocar ou realocar memória para o array de alunos
Aluno* realocar_memoria_aluno(Aluno *alunos, int novo_tamanho) {
    //Realoca memória para o array de alunos
    Aluno *temp = realloc(alunos, novo_tamanho * sizeof(Aluno));
    if(temp == NULL){
        printf("Erro na realocacao de memoria para o aluno.\n");//Trata o erro caso o ponteiro nao seja direcionado a lugar nenhum
        free(alunos);
        exit(1);
    }
    return temp; 
}

// Função para alocar ou realocar memória para o array de avaliacoes
Avaliacao* realocar_memoria_avaliacao(Avaliacao *avaliacoes, int novo_tamanho) {
    //Realoca memoria para o array de avaliações
    Avaliacao *temp = realloc(avaliacoes, novo_tamanho * sizeof(Avaliacao));
    if(temp == NULL){
        printf("Erro na realocacao de memoria para a avaliacao.\n");//Trata o erro caso o ponteiro nao seja direcionado a lugar nenhum
        free(avaliacoes);
        exit(1);
    }
    return temp;
}

// Função para liberar a memória alocada para os alunos
void liberar_memoria(Aluno *alunos, int num_alunos) {
    if(alunos){
        for(int i = 0; i < num_alunos; i++){
            free(alunos[i].avaliacoes);  //Libera a memoria das avaliaçoes de todos os alunos
        }
        free(alunos); //Libera a memoria dos alunos
    }
}
 
// Função para adicionar uma nova avaliação ao histórico de avaliações do aluno
void adicionar_avaliacoes(Aluno *aluno, Avaliacao avaliacao) {
    aluno->avaliacoes = realocar_memoria_avaliacao(aluno->avaliacoes, aluno->num_avaliacoes + 1);
    aluno->avaliacoes[aluno->num_avaliacoes] = avaliacao;
    aluno->num_avaliacoes++;
}


// Carrega os alunos do arquivo CSV e retorna um array de alunos
// O número de alunos é retornado através do ponteiro num_alunos
Aluno *carregar_alunos(const char *nome_arquivo, int *num_alunos) {
    // Abre o arquivo para leitura
    FILE *arquivo = fopen(nome_arquivo, "r"); 
    // Verifica se o arquivo foi aberto corretamente
    // Se não, imprime uma mensagem de erro e retorna NULL    
    if (!arquivo) { 
        perror("Erro ao abrir arquivo de alunos");
        return NULL;
    }

    Aluno *alunos   = NULL;                 // Inicializa o ponteiro para alunos
    char linha[256];                        // Buffer para ler cada linha do arquivo
    fgets(linha, sizeof(linha), arquivo);   // Ler e descartar o cabeçalho

    while (fgets(linha, sizeof(linha), arquivo)) { // Lê cada linha do arquivo
        Aluno novo_aluno;       // Inicializa um novo aluno
        Avaliacao avaliacao1;   // Inicializa a avaliação 1
        Avaliacao avaliacao2;   // Inicializa a avaliação 2
        // Lê os dados do aluno da linha e armazena em novo_aluno
        // O sscanf retorna o número de itens lidos com sucesso
        float av1ap1, av1ap2, av1ap3, np1, av2ap1, av2ap2, av2ap3, np2;
        if (sscanf(linha, "%d,%[^,],%f,%f,%f,%f,%f,%f,%f,%f", &novo_aluno.matricula, novo_aluno.nome, &avaliacao1.ap1,&avaliacao1.ap2, &avaliacao1.ap3, &avaliacao1.np, &avaliacao2.ap1, &avaliacao2.ap2,&avaliacao2.ap3, &avaliacao2.np) == 10) {

            /* 
                ATENÇÃO: Essa função deve ser implementada
            */             
            // Realoca memória para mais um aluno
            alunos = realocar_memoria_aluno(alunos, (*num_alunos + 1));

            // Verifica se a realocação foi bem-sucedida
            if (!alunos) {
                perror("Erro ao alocar memória para alunos");
                fclose(arquivo);
                return NULL;
            }

            // Adiciona o novo aluno ao array
            novo_aluno.avaliacoes = NULL; // Inicializa o histórico de avaliações
            novo_aluno.num_avaliacoes = 0; // Inicializa o número de avaliacoes

            /* 
                ATENÇÃO: Essa função deve ser implementada
            */             
            adicionar_avaliacoes(&novo_aluno, avaliacao1); // Adiciona a primeira avaliação
            adicionar_avaliacoes(&novo_aluno, avaliacao2); // Adiciona a segunda avaliação

            /* 
                ATENÇÃO: Essa função deve ser implementada
            */ 
            calcular_notas(&novo_aluno); // Calcula as notas do aluno

            // Adiciona o novo aluno ao array de alunos
            // O ponteiro alunos é atualizado para apontar para o novo array
            alunos[*num_alunos] = novo_aluno;
            (*num_alunos)++; // Incrementa o número de alunos

        } else { // Se a leitura falhar, imprime uma mensagem de erro
            fprintf(stderr, "Erro ao ler linha do arquivo de alunos: %s", linha);
        }
    }

    fclose(arquivo);
    return alunos;
}

// Função para ordenar os alunos por nota final (NF)
void ordenar_alunos(Aluno *alunos, int num_alunos) {
    for (int i = 0; i < num_alunos - 1; i++) {
        for (int j = 0; j < num_alunos - i - 1; j++) {
            if (alunos[j].nf < alunos[j + 1].nf) {
                Aluno temp = alunos[j];
                alunos[j] = alunos[j + 1];
                alunos[j + 1] = temp;
            }
        }
    }
}

void listar_alunos(const Aluno *alunos, int num_alunos) {
    if (num_alunos == 0) {
        printf("Nenhum aluno cadastrado.\n");
        return;
    }

    printf("\n");
    printf("%-10s | %-30s | %-8s | %-8s | %-8s | %-8s | %-8s | %-8s | %-8s | %-8s | %-8s | %-10s\n",
           " Matrícula", "Nome", "AV1:AP1", "AV1:AP2", "AV1:AP3", "NP1", "AV2:AP1", "AV2:AP2", "AV2:AP3", "NP2", "NF", "Status");
    printf("-----------|--------------------------------|----------|----------|----------|----------|----------|----------|----------|----------|----------|------------\n");

    for (int i = 0; i < num_alunos; i++) {
        if (alunos[i].status == 0) { // Reprovado
            printf(RED_TEXT);
        }
        printf("%-10d | %-30s | %-8.2f | %-8.2f | %-8.2f | %-8.2f | %-8.2f | %-8.2f | %-8.2f | %-8.2f | %-8.2f | %-10s",
                alunos[i].matricula,
                alunos[i].nome,
                alunos[i].avaliacoes[0].ap1,
                alunos[i].avaliacoes[0].ap2,
                alunos[i].avaliacoes[0].ap3,
                alunos[i].avaliacoes[0].np,
                alunos[i].avaliacoes[1].ap1,
                alunos[i].avaliacoes[1].ap2,
                alunos[i].avaliacoes[1].ap3,
                alunos[i].avaliacoes[1].np,
                alunos[i].nf,
                alunos[i].status == 1 ? "Aprovado" : "Reprovado");
        if (alunos[i].status == 0) {
            printf(RESET_TEXT);
        }
        printf("\n");
    }
    printf("\n");
}
