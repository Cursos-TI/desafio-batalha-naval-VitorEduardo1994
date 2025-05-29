#include <stdio.h>

#define LINHA 10 // Número de linhas do tabuleiro
#define COLUNA 10 // Número de colunas do tabuleiro

// Função para exibir o tabuleiro no console
void exibirTabuleiro(int tabuleiro[LINHA][COLUNA]) {
    printf("   "); // Espaço para alinhar as colunas
    for (int j = 0; j < COLUNA; j++) {
        printf("%c ", 'A' + j); // Imprime as letras das colunas (A a J)
    }
    printf("\n");

    for (int i = 0; i < LINHA; i++) {
        printf("%2d ", i + 1); // Imprime os números das linhas (1 a 10)
        for (int j = 0; j < COLUNA; j++) {
            printf("%d ", tabuleiro[i][j]); // Imprime os valores numéricos (0, 3, 5)
        }
        printf("\n");
    }
}

// Função para aplicar habilidades no tabuleiro
void aplicarHabilidade(int tabuleiro[LINHA][COLUNA], int habilidade[5][5], int origemX, int origemY) {
    for (int i = 0; i < 5; i++) { // Itera na matriz da habilidade (5x5)
        for (int j = 0; j < 5; j++) {
            int x = origemX + i - 2; // Calcula a linha no tabuleiro
            int y = origemY + j - 2; // Calcula a coluna no tabuleiro

            if (x >= 0 && x < LINHA && y >= 0 && y < COLUNA && habilidade[i][j] == 1) {
                tabuleiro[x][y] = 5; // Marca a área como afetada (5)
            }
        }
    }
}

int main() {
    int tabuleiro[LINHA][COLUNA] = {0}; // Inicializa todas as posições com 0 (Água)

    // Posiciona navios no tabuleiro
    tabuleiro[2][3] = 3; // Linha 3, Coluna D (Navio horizontal)
    tabuleiro[2][4] = 3;
    tabuleiro[2][5] = 3;

    tabuleiro[5][7] = 3; // Linha 6, Coluna H (Navio vertical)
    tabuleiro[6][7] = 3;
    tabuleiro[7][7] = 3;

    // Matrizes para as habilidades
    int cone[5][5] = {
        {0, 0, 1, 0, 0},
        {0, 1, 1, 1, 0},
        {1, 1, 1, 1, 1},
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0},
    };

    int cruz[5][5] = {
        {0, 0, 1, 0, 0},
        {0, 0, 1, 0, 0},
        {1, 1, 1, 1, 1},
        {0, 0, 1, 0, 0},
        {0, 0, 1, 0, 0},
    };

    int octaedro[5][5] = {
        {0, 0, 1, 0, 0},
        {0, 1, 1, 1, 0},
        {1, 1, 1, 1, 1},
        {0, 1, 1, 1, 0},
        {0, 0, 1, 0, 0},
    };

    // Aplica habilidades no tabuleiro
    aplicarHabilidade(tabuleiro, cone, 3, 4);    // Aplica cone na posição (linha 4, coluna E)
    aplicarHabilidade(tabuleiro, cruz, 5, 7);   // Aplica cruz na posição (linha 6, coluna H)
    aplicarHabilidade(tabuleiro, octaedro, 7, 2); // Aplica octaedro na posição (linha 8, coluna C)

    // Exibe o tabuleiro
    exibirTabuleiro(tabuleiro);

    return 0;
}
