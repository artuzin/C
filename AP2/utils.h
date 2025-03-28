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

extern int validar, c, eA, eR, l2, i;

typedef struct {
    float valor, parcela;
    int meses;
}emprestimo;

typedef struct{
    char nome[100];
    float salario;
    emprestimo emprestimo;
}cliente;

int validar_nome(char *nome);

void limpar();

void msg_erro(char *msg);

void calculo_parcela(cliente *cliente, int n_clientes);

void dados_emprestimo(cliente *cliente, int *situacao, int n_clientes);

#endif