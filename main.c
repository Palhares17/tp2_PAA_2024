#include "headers/includes.h"

int main() {
    TipoApontadorCaverna caverna;
    TipoApontadorTabela tabela;

    int leitura = leituraArquivo(&caverna);

    if (leitura) {
        inicializaTabela(&caverna, &tabela);
        movimentaEstudante(&caverna, &tabela);
        MostrarCaverna(&caverna);
    }

    return 0;
}