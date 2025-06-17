#include <stdio.h>

// Define o tamanho do tabuleiro e dos navios
#define TAM 10
#define TAM_NAVIO 3

int main() {
    // Declara o tabuleiro (10x10) e inicializa com 0 (água)
    int tabuleiro[TAM][TAM];
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            tabuleiro[i][j] = 0;
        }
    }

    // Coordenadas iniciais do navio horizontal
    int linhanavioh = 1;
    int colunanavioh = 1;

    // Coordenadas iniciais do navio vertical
    int linhanaviov = 6;
    int colunanaviov = 8;

    // Posiciona o navio horizontal (tamanho 3)
    for (int i = 0; i < TAM_NAVIO; i++) {
        if (colunanavioh + i < TAM) {
            tabuleiro[linhanavioh][colunanavioh + i] = 3;
        }
    }

    // Posiciona o navio vertical (tamanho 3), checando sobreposição
    for (int i = 0; i < TAM_NAVIO; i++) {
        int l = linhanaviov + i;
        if (l < TAM) {
            if (tabuleiro[l][colunanaviov] == 0) {
                tabuleiro[l][colunanaviov] = 3;
            } else {
                // Se já tiver navio nessa posição, dá erro
                printf("Erro: um navio está sobrepondo o outro.\n");
                return 1;
            }
        }
    }

    // Exibe o tabuleiro no terminal
    printf("Tabuleiro final:\n");
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            printf("%d ", tabuleiro[i][j]);  // Mostra 0 para água e 3 para navio
        }
        printf("\n");  // Vai para a próxima linha
    }

    return 0;
}
