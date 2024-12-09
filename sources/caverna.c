#include "../headers/includes.h"

void InicializaCaverna(TipoApontador *cav, int linha, int coluna, int vida) {
    (*cav)->qtdLinhas = linha;
    (*cav)->qtdColunas = coluna;
    (*cav)->ptsVida = vida;

    (*cav)->caverna = (int **)calloc(((*cav)->qtdLinhas + 1), sizeof(int *));

    for (int i = 0; i < (*cav)->qtdLinhas; i++) {
        (*cav)->caverna[i] = (int *)calloc(((*cav)->qtdColunas + 1), sizeof(int));
    }
}

void MostrarCaverna(TipoApontador *cav) {
    for (int i = 0; i < (*cav)->qtdLinhas; i++) {
        for (int j = 0; j < (*cav)->qtdColunas; j++) {
            printf("%d", (*cav)->caverna[i][j]);
        }
        printf("\n");
    }

    printf("\n");
}