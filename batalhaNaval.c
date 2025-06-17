#include <stdio.h>

int main(){

#define TAM 10
#define TAM_NAVIO 3

int main() {
    int tabuleiro[TAM][TAM];

    // Preenche o tabuleiro com água (0)
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            tabuleiro[i][j] = 0;
        }
    }

    // Define as posições iniciais dos navios
    int linhanavioh = 1;
    int colunanavioh = 1;

    int linhanaviov = 6;
    int colunanaviov = 8;

    // Posiciona navio horizontal
    for (int i = 0; i < TAM_NAVIO; i++) {
        if (colunanavioh + i < TAM) {
            tabuleiro[linhanavioh][colunanavioh + i] = 3;
        }
    }

    // Posiciona navio vertical
    for (int i = 0; i < TAM_NAVIO; i++) {
        int l = linhanaviov + i;
        if (l < TAM) {
            if (tabuleiro[l][colunanaviov] == 0) {
                tabuleiro[l][colunanaviov] = 3;
            } else {
                printf("Erro: um navio está sobrepondo o outro.\n");
                return 1;
            }
        }
    }

    // Exibe o tabuleiro com uma linha embaixo da outra
    printf("Tabuleiro final:\n");
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            printf("%d ", tabuleiro[i][j]);  // espaço simples entre os números
        }
        printf("\n");  // cada linha bem colada na outra
    }

    return 0;
}

