#include <stdio.h>
#define TAM_TABULEIRO 10
#define TAM_HABILIDADE 5
#define NAVIO 3
#define AGUA 0
#define HABILIDADE 5

// Exibe o tabuleiro com símbolos claros
void exibirTabuleiro(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO]) {
    for (int i = 0; i < TAM_TABULEIRO; i++) {
        for (int j = 0; j < TAM_TABULEIRO; j++) {
            if (tabuleiro[i][j] == AGUA) {
                printf(". ");
            } else if (tabuleiro[i][j] == NAVIO) {
                printf("N ");
            } else if (tabuleiro[i][j] == HABILIDADE) {
                printf("* ");
            } else {
                printf("? "); // caso inesperado
            }
        }
        printf("\n");
    }
}

// Gera matriz em formato de cone invertido
void gerarCone(int matriz[TAM_HABILIDADE][TAM_HABILIDADE]) {
    for (int i = 0; i < TAM_HABILIDADE; i++) {
        for (int j = 0; j < TAM_HABILIDADE; j++) {
            if (j >= TAM_HABILIDADE/2 - i && j <= TAM_HABILIDADE/2 + i) {
                matriz[i][j] = 1;
            } else {
                matriz[i][j] = 0;
            }
        }
    }
}

// Gera matriz em formato de cruz
void gerarCruz(int matriz[TAM_HABILIDADE][TAM_HABILIDADE]) {
    for (int i = 0; i < TAM_HABILIDADE; i++) {
        for (int j = 0; j < TAM_HABILIDADE; j++) {
            if (i == TAM_HABILIDADE/2 || j == TAM_HABILIDADE/2) {
                matriz[i][j] = 1;
            } else {
                matriz[i][j] = 0;
            }
        }
    }
}

// Gera matriz em formato de octaedro (losango)
void gerarOctaedro(int matriz[TAM_HABILIDADE][TAM_HABILIDADE]) {
    for (int i = 0; i < TAM_HABILIDADE; i++) {
        for (int j = 0; j < TAM_HABILIDADE; j++) {
            if (abs(i - TAM_HABILIDADE/2) + abs(j - TAM_HABILIDADE/2) <= TAM_HABILIDADE/2) {
                matriz[i][j] = 1;
            } else {
                matriz[i][j] = 0;
            }
        }
    }
}

// Aplica a habilidade ao tabuleiro no ponto central indicado
void aplicarHabilidade(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO], int habilidade[TAM_HABILIDADE][TAM_HABILIDADE], int origemLinha, int origemColuna) {
    int offset = TAM_HABILIDADE / 2;

    for (int i = 0; i < TAM_HABILIDADE; i++) {
        for (int j = 0; j < TAM_HABILIDADE; j++) {
            int linhaTabuleiro = origemLinha + i - offset;
            int colunaTabuleiro = origemColuna + j - offset;

            if (linhaTabuleiro >= 0 && linhaTabuleiro < TAM_TABULEIRO &&
                colunaTabuleiro >= 0 && colunaTabuleiro < TAM_TABULEIRO) {

                if (habilidade[i][j] == 1 && tabuleiro[linhaTabuleiro][colunaTabuleiro] != NAVIO) {
                    tabuleiro[linhaTabuleiro][colunaTabuleiro] = HABILIDADE;
                }
            }
        }
    }
}

int main() {
    int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO] = {0};

    // Inserção manual de alguns navios
    tabuleiro[3][4] = NAVIO;
    tabuleiro[4][4] = NAVIO;
    tabuleiro[5][4] = NAVIO;

    // Matrizes de habilidades
    int cone[TAM_HABILIDADE][TAM_HABILIDADE];
    int cruz[TAM_HABILIDADE][TAM_HABILIDADE];
    int octaedro[TAM_HABILIDADE][TAM_HABILIDADE];

    // Geração das formas
    gerarCone(cone);
    gerarCruz(cruz);
    gerarOctaedro(octaedro);

    // Aplicação das habilidades
    aplicarHabilidade(tabuleiro, cone, 2, 2);
    aplicarHabilidade(tabuleiro, cruz, 5, 5);
    aplicarHabilidade(tabuleiro, octaedro, 7, 7);

    // Exibição final
    printf("\nTABULEIRO COM HABILIDADES:\n");
    exibirTabuleiro(tabuleiro);

    return 0;
}
