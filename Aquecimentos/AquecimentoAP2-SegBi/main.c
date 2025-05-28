#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

typedef struct Processo{
    int pid;
    int tempo_execucao;
    int tempo_restante;
    struct Processo *prox; //Cria uma ponteiro que estará apontando para o prox elemento da lista,
} Processo;
