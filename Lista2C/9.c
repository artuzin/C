#include <stdio.h>

#define N 3 // Tamanho do tabuleiro (3x3)

// Função para imprimir o tabuleiro
void imprimirTabuleiro(char tabuleiro[N][N]) {
    printf("\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf(" %c ", tabuleiro[i][j]);
            if (j < N - 1) printf("|");
        }
        printf("\n");
        if (i < N - 1) printf("---|---|---\n");
    }
    printf("\n");
}

// Função para verificar se há um ganhador
int verificarGanhador(char tabuleiro[N][N], char jogador) {
    // Verificar linhas
    for (int i = 0; i < N; i++) {
        if (tabuleiro[i][0] == jogador && tabuleiro[i][1] == jogador && tabuleiro[i][2] == jogador) {
            return 1;
        }
    }

    // Verificar colunas
    for (int i = 0; i < N; i++) {
        if (tabuleiro[0][i] == jogador && tabuleiro[1][i] == jogador && tabuleiro[2][i] == jogador) {
            return 1;
        }
    }

    // Verificar diagonais
    if (tabuleiro[0][0] == jogador && tabuleiro[1][1] == jogador && tabuleiro[2][2] == jogador) {
        return 1;
    }
    if (tabuleiro[0][2] == jogador && tabuleiro[1][1] == jogador && tabuleiro[2][0] == jogador) {
        return 1;
    }

    return 0;
}

// Função principal
int main() {
    char tabuleiro[N][N] = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}}; // Tabuleiro 3x3
    int jogada, linha, coluna, jogadas = 0;
    char jogadorAtual = 'X'; // Jogador X começa

    while (1) {
        imprimirTabuleiro(tabuleiro);

        // Entrada do jogador
        printf("Jogador %c, escolha uma posição (1-9): ", jogadorAtual);
        scanf("%d", &jogada);

        // Determinar a linha e coluna com base na jogada (1-9)
        linha = (jogada - 1) / N;
        coluna = (jogada - 1) % N;

        // Verificar se a posição já está ocupada
        if (tabuleiro[linha][coluna] == 'X' || tabuleiro[linha][coluna] == 'O') {
            printf("Posição já ocupada! Tente novamente.\n");
            continue;
        }

        // Marcar a jogada no tabuleiro
        tabuleiro[linha][coluna] = jogadorAtual;
        jogadas++;

        // Verificar se o jogador atual venceu
        if (verificarGanhador(tabuleiro, jogadorAtual)) {
            imprimirTabuleiro(tabuleiro);
            printf("Jogador %c venceu!\n", jogadorAtual);
            break;
        }

        // Verificar se houve empate
        if (jogadas == 9) {
            imprimirTabuleiro(tabuleiro);
            printf("O jogo empatou!\n");
            break;
        }

        // Alternar entre os jogadores
        jogadorAtual = (jogadorAtual == 'X') ? 'O' : 'X';
    }

    return 0;
}