#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

//Artur Boudens, Luan Borges, Felipe Raffael

typedef struct Processo{
    int pid;
    int tempo_exec;
    int tempo_rest;
    int prioridade;
} Processo;

typedef struct No{
    Processo *processo;
    struct No *proximo;
} No;

typedef struct Fila{
    No *inicio;
    No *fim;
} Fila;

Fila* CriarFila(){
    Fila *fila = (Fila*) malloc(sizeof(Fila));

    fila->inicio = NULL;
    fila->fim = NULL;
    return fila;
}

int FilaVazia(Fila *fila){
    return fila->inicio == NULL;
}

void enfileirar(Fila *fila, Processo *p){
    No* novoNo = (No*)malloc(sizeof(No));
    novoNo->processo = p;
    novoNo->proximo = NULL;
    
    if(FilaVazia(fila)){
        fila->inicio = novoNo;
        fila->fim = novoNo;
    }
    else{
        fila->fim->proximo = novoNo;
        fila->fim = novoNo;
    }
}

Processo* desenfileirar(Fila* fila){
    if(FilaVazia(fila)){
        return NULL;
    }

    No* noTemp = fila->inicio;
    Processo* processo = noTemp->processo;

    fila->inicio = fila->inicio->proximo;

    if(fila->inicio == NULL){
        fila->fim = NULL;
    }

    free(noTemp);
    return processo;
}

const char* pegarNome(int prioridade){
    switch (prioridade){
        case 0: return "Alta";
        case 1: return "Normal";
        case 2: return "Baixa";
        default: return "Desconhecida";
    }
}

int main(){
    srand(time(NULL));

    Fila* fila_alta = CriarFila();
    Fila* fila_normal = CriarFila();
    Fila* fila_baixa = CriarFila();

    int total_processos = 20;
    printf("Iniciando %d processos...\n\n", total_processos);

    for(int i = 0; i < total_processos; i++){
        Processo* p = (Processo*)malloc(sizeof(Processo));
        p->pid = i + 1;
        p->prioridade = rand() % 3;
        p->tempo_exec = (rand() % 11) + 10;
        p->tempo_rest = p->tempo_exec;
    
        switch(p->prioridade){
            case 0:
                enfileirar(fila_alta, p);
                break;
            case 1: 
                enfileirar(fila_normal, p);
                break;
            case 2:
                enfileirar(fila_baixa, p);
                break;
        }
    }

    int processos_concluidos = 0;
    int tempo_total_decorrido = 0;

    printf("---- Iniciando a Simulacao do Escalonador ----\n");

    while (processos_concluidos < total_processos){
        int proporcao[] = {3, 2, 1};
        Fila* filas[] = {fila_alta, fila_normal, fila_baixa};

        for(int i = 0; i < 3; i++){
            for(int j = 0; j < proporcao[i]; j++){
                if (!FilaVazia(filas[i])){
                    Processo* p = desenfileirar(filas[i]);

                    int fatia_tempo = 0;
                    switch (p->prioridade){
                        case 0:
                            fatia_tempo = (rand() % 3) + 8;
                            break;
                        case 1:
                            fatia_tempo = (rand() % 4) + 5;
                            break;
                        case 2:
                        fatia_tempo = (rand() % 4) + 2;
                        break;
                    }

                    printf("\n[Tempo : %dseg] -> Executando PID: %d\n", tempo_total_decorrido, p->pid);
                    printf(" Prioridade: %s | Fatia de tempo : %dseg | Tempo restante anteriro: %dseg\n", pegarNome(p->prioridade), fatia_tempo, p->tempo_rest);

                    sleep(1);

                    tempo_total_decorrido += fatia_tempo;

                    p->tempo_rest -= fatia_tempo;

                    if (p->tempo_rest < 0) {
                        p->tempo_rest = 0;
                    }

                    printf("Tempo restante atual: %dseg\n", p->tempo_rest);

                    if(p->tempo_rest == 0){
                        printf("> > PROCESSO %d CONCLUIDO E REMOVIDO < <\n", p->pid);
                        free(p);
                        processos_concluidos++;
                    }
                    else{
                        printf("Processo %d nao concluido, retornando para a fila.\n", p->pid);
                        enfileirar(filas[i], p);
                    }
                }
            }
        }
    }

    printf("\n--------------------------------------------------\n");
    printf("Todos os processos foram concluidos!\n");
    printf("Tempo total da simulacao: %d segundos.\n", tempo_total_decorrido);
    printf("--------------------------------------------------\n");

    free(fila_alta);
    free(fila_normal);
    free(fila_baixa);

    return 0;
}


