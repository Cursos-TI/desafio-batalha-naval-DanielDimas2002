#include <stdio.h>

#define TAMANHO_TABULEIRO 10
#define TAMANHO_NAVIO 3
#define AGUA 0
#define NAVIO 3

// Função que imprime o tabuleiro
void exibir_tabuleiro(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]) {
    printf("   ");
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        printf("%d ", i);  // Cabeçalho de colunas
    }
    printf("\n");

    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        printf("%2d ", i);  // Cabeçalho de linhas
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            printf("%d ", tabuleiro[i][j]);  // Imprime valor da célula
        }
        printf("\n");
    }
}

// Função que verifica se é possível posicionar o navio sem ultrapassar limites ou sobrepor
int pode_posicionar_navio(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO],
                          int linha_inicial, int coluna_inicial,
                          int orientacao) { // 0 = horizontal, 1 = vertical, 2 = diagonal crescente, 3 = diagonal decrescente

    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        int linha = linha_inicial;
        int coluna = coluna_inicial;

        if (orientacao == 0) {  // horizontal
            coluna += i;
        } else if (orientacao == 1) {  // vertical
            linha += i;
        } else if (orientacao == 2) {  // diagonal crescente (↘)
            linha += i;
            coluna += i;
        } else if (orientacao == 3) {  // diagonal decrescente (↙)
            linha += i;
            coluna -= i;
        }

        if (linha < 0 || linha >= TAMANHO_TABULEIRO || coluna < 0 || coluna >= TAMANHO_TABULEIRO) {
            return 0; // Fora dos limites do tabuleiro
        }

        if (tabuleiro[linha][coluna] != AGUA) {
            return 0; // Já existe navio na posição
        }
    }

    return 1; // Pode posicionar
}

// Função que posiciona o navio
void posicionar_navio(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO],
                      int linha_inicial, int coluna_inicial,
                      int orientacao) {
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        int linha = linha_inicial;
        int coluna = coluna_inicial;

        if (orientacao == 0) {
            coluna += i;
        } else if (orientacao == 1) {
            linha += i;
        } else if (orientacao == 2) {
            linha += i;
            coluna += i;
        } else if (orientacao == 3) {
            linha += i;
            coluna -= i;
        }

        tabuleiro[linha][coluna] = NAVIO;
    }
}

int main() {
    // Declaração do tabuleiro 10x10 inicializado com 0 (água)
    int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO] = {0};

    // Coordenadas dos navios definidos diretamente
    int linha_navio_horizontal = 2;
    int coluna_navio_horizontal = 4;
    int linha_navio_vertical = 5;
    int coluna_navio_vertical = 7;
    int linha_navio_diagonal1 = 0;
    int coluna_navio_diagonal1 = 0;
    int linha_navio_diagonal2 = 0;
    int coluna_navio_diagonal2 = 9;

    // Posicionamento horizontal (orientação 0)
    if (pode_posicionar_navio(tabuleiro, linha_navio_horizontal, coluna_navio_horizontal, 0)) {
        posicionar_navio(tabuleiro, linha_navio_horizontal, coluna_navio_horizontal, 0);
    } else {
        printf("Não foi possível posicionar o navio horizontal.\n");
    }

    // Posicionamento vertical (orientação 1)
    if (pode_posicionar_navio(tabuleiro, linha_navio_vertical, coluna_navio_vertical, 1)) {
        posicionar_navio(tabuleiro, linha_navio_vertical, coluna_navio_vertical, 1);
    } else {
        printf("Não foi possível posicionar o navio vertical.\n");
    }

    // Posicionamento diagonal crescente (↘) (orientação 2)
    if (pode_posicionar_navio(tabuleiro, linha_navio_diagonal1, coluna_navio_diagonal1, 2)) {
        posicionar_navio(tabuleiro, linha_navio_diagonal1, coluna_navio_diagonal1, 2);
    } else {
        printf("Não foi possível posicionar o navio diagonal crescente.\n");
    }

    // Posicionamento diagonal decrescente (↙) (orientação 3)
    if (pode_posicionar_navio(tabuleiro, linha_navio_diagonal2, coluna_navio_diagonal2, 3)) {
        posicionar_navio(tabuleiro, linha_navio_diagonal2, coluna_navio_diagonal2, 3);
    } else {
        printf("Não foi possível posicionar o navio diagonal decrescente.\n");
    }

    // Exibe o tabuleiro final com os navios posicionados
    exibir_tabuleiro(tabuleiro);

    return 0;
}
