#ifndef CAVERNA_H
#define CAVERNA_H

typedef struct TipoCaverna {
    int **caverna;
    int qtdLinhas, qtdColunas, ptsVida;
} TipoCaverna;

typedef TipoCaverna *TipoApontador;

void InicializaCaverna(TipoApontador *cav, int linha, int coluna, int vida);
void MostrarCaverna(TipoApontador *cav);

#endif