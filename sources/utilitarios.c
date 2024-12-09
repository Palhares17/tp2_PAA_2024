#include "../headers/includes.h"

int leituraArquivo(TipoApontador *cav) {
    FILE *arq;

    arq = fopen("../cavernas/caverna1.txt", "r");

    if (arq == NULL) {
        printf("Deu merda na leitura");
        return 0;
    }

    int linhas, colunas, vidas;

    fscanf(arq, "%d %d %d", &linhas, &colunas, &vidas);

    InicializaCaverna(cav, linhas, colunas, vidas);

    char entrada[(*cav)->qtdColunas + 1];

    for (int i = 0; i < (*cav)->qtdLinhas; i++) {
        if (fscanf(arq, "%s", entrada) != 1) {
            printf("Erro ao ler a linha %d do caverna\n", i);
            fclose(arq);
        }

        // Converte os caracteres da string para inteiros
        for (int j = 0; j < (*cav)->qtdColunas; j++) {
            (*cav)->caverna[i][j] = entrada[j] - '0';
        }
    }

    fclose(arq);

    return 1;
}