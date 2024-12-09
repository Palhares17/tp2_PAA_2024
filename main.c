#include "headers/includes.h"

int main() {
    TipoApontador caverna;

    int leitura = leituraArquivo(&caverna);

    if (leitura) {
		MostrarCaverna(&caverna);
	}	

    return 0;
}