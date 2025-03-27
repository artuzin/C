#ifndef UTILS.H
#define UTILS.H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#ifdef _WIN32
    #define LT "cls"
#else
    #define LT "clear"
#endif

extern int validar, c, eA, eR, l2;

typedef struct {
    float valor, parcela;
    int meses;
}emprestimo;

typedef struct{
    char nome[100];
    float salario;
    emprestimo emprestimo;
}cliente;

int validar_nome(const char *nome);
void limpar();
void msg_erro(char *msg);
void dados_emprestimo();

#endif