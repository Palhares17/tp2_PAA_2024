#include "../headers/includes.h"

void InicializaCaverna(TipoApontadorCaverna *cav, int linha, int coluna, int vida) {
    (*cav)->qtdLinhas = linha;
    (*cav)->qtdColunas = coluna;
    (*cav)->ptsVida = vida;

    (*cav)->caverna = (int **)calloc(((*cav)->qtdLinhas + 1), sizeof(int *));

    for (int i = 0; i < (*cav)->qtdLinhas; i++) {
        (*cav)->caverna[i] = (int *)calloc(((*cav)->qtdColunas + 1), sizeof(int));
    }
}

void inicializaTabela(TipoApontadorCaverna *cav, TipoApontadorTabela *tabela) {
    (*tabela) = (TipoTabela *)malloc(sizeof(TipoTabela));  // Faz a alocação da estrutura

    (*tabela)->qtdLinhas = (*cav)->qtdLinhas;
    (*tabela)->qtdColunas = (*cav)->qtdColunas;

    (*tabela)->tabela = (char **)calloc(((*tabela)->qtdLinhas + 1), sizeof(char *));

    for (int i = 0; i < (*tabela)->qtdLinhas; i++) {
        (*tabela)->tabela[i] = (char *)calloc(((*tabela)->qtdColunas + 1), sizeof(char));
    }
}

int max(int a, int b) {
    return (a > b) ? a : b;  // Retorna o maior valor
}

int verificaPosicao(TipoApontadorCaverna *cav, int x, int y) {
    if (x >= 0 && x < (*cav)->qtdLinhas && y >= 0 && y < (*cav)->qtdColunas) {
        return 1;  // Posição válida
    }
    return 0;  // Posição inválida
}

void movimentaEstudante(TipoApontadorCaverna *cav, TipoApontadorTabela *tabela) {
    int tabelaAux[(*cav)->qtdLinhas][(*cav)->qtdColunas];  // Matriz auxiliar

    // Inicializando a matriz auxiliar com os valores da caverna
    for (int i = 0; i < (*cav)->qtdLinhas; i++) {
        for (int j = 0; j < (*cav)->qtdColunas; j++) {
            tabelaAux[i][j] = (*cav)->caverna[i][j];
        }
    }

    // Percorrendo a matriz de baixo para cima e da direita para a esquerda
    for (int i = (*cav)->qtdLinhas - 1; i >= 0; i--) {
        for (int j = (*cav)->qtdColunas - 1; j >= 0; j--) {
            // Se estamos na posição inicial
            if ((*cav)->caverna[i][j] == -99) {
                (*tabela)->tabela[i][j] = '*';  // Marca como início
            } else {
                int verificaBaixo = verificaPosicao(cav, i + 1, j);
                int verificaDireita = verificaPosicao(cav, i, j + 1);

                if (verificaBaixo && verificaDireita) {
                    if (tabelaAux[i + 1][j] >= tabelaAux[i][j + 1]) {
                        tabelaAux[i][j] += tabelaAux[i + 1][j];
                        (*tabela)->tabela[i][j] = 'b';  // Movimentação para baixo
                    } else {
                        tabelaAux[i][j] += tabelaAux[i][j + 1];
                        (*tabela)->tabela[i][j] = 'd';  // Movimentação para direita
                    }
                } else if (verificaBaixo) {
                    tabelaAux[i][j] += tabelaAux[i + 1][j];
                    (*tabela)->tabela[i][j] = 'b';  // Movimentação para baixo
                } else if (verificaDireita) {
                    tabelaAux[i][j] += tabelaAux[i][j + 1];
                    (*tabela)->tabela[i][j] = 'd';  // Movimentação para direita
                }
            }
        }
    }
}

void MostrarCaverna(TipoApontadorCaverna *cav) {
    for (int i = 0; i < (*cav)->qtdLinhas; i++) {
        for (int j = 0; j < (*cav)->qtdColunas; j++) {
            printf(" %d", (*cav)->caverna[i][j]);
        }
        printf("\n");
    }

    printf("\n");
}
