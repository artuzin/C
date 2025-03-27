#ifndef UTILS_H
#define UTILS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#ifdef _WIN32
    #define LT "cls"
#else
    #define LT "clear"
#endif

typedef struct{
    float ap[3], media_ap, np, av;
}b;

extern int validar, loop, dados_inseridos;

typedef struct {
    b b[2];
    int ra;
    float nf;
}aluno;

void limpar();
void msg_erro(char *msg);
void dados_alunos(aluno *aluno, int *situacao, int n_alunos);
void media_alunos(aluno *aluno, int *situacao, int n_alunos, int *dados_inseridos);

#endif
