#ifndef CAVERNA_H
#define CAVERNA_H

typedef struct TipoTabela {
    char **tabela;
    int qtdLinhas, qtdColunas;
} TipoTabela;

typedef struct TipoCaverna {
    int **caverna;
    int qtdLinhas, qtdColunas, ptsVida;
} TipoCaverna;

typedef TipoTabela *TipoApontadorTabela;
typedef TipoCaverna *TipoApontadorCaverna;

void InicializaCaverna(TipoApontadorCaverna *cav, int linha, int coluna, int vida);
void inicializaTabela(TipoApontadorCaverna *cav, TipoApontadorTabela *tabela);
void movimentaEstudante(TipoApontadorCaverna *cav, TipoApontadorTabela *tabela);
void MostrarCaverna(TipoApontadorCaverna *cav);

#endif