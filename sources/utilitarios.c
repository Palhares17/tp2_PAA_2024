#include "../headers/includes.h"

int leituraArquivo(TipoApontadorCaverna *cav) {
    FILE *arq;

    // Abrindo o arquivo
    arq = fopen("./cavernas/caverna1.txt", "r");
    if (arq == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return 0;
    }

    int linhas, colunas, vidas;

    // Lendo as dimensões e os pontos de vida iniciais
    if (fscanf(arq, "%d %d %d", &linhas, &colunas, &vidas) != 3) {
        printf("Erro ao ler as dimensões ou os pontos de vida.\n");
        fclose(arq);
        return 0;
    }

    // Aloca memória para a estrutura TipoCaverna
    *cav = (TipoApontadorCaverna)malloc(sizeof(TipoCaverna));
    if (*cav == NULL) {
        perror("Erro ao alocar memória para caverna");
        fclose(arq);
        return 0;
    }

    // Inicializando a caverna
    InicializaCaverna(cav, linhas, colunas, vidas);

    char entrada[10];  // Buffer para leitura de cada célula

    // Lendo os valores da matriz
    for (int i = 0; i < (*cav)->qtdLinhas; i++) {
        for (int j = 0; j < (*cav)->qtdColunas; j++) {
            if (fscanf(arq, "%s", entrada) != 1) {
                printf("Erro ao ler a célula [%d][%d].\n", i, j);
                fclose(arq);
                return 0;
            }

            // Processando valores especiais ou numéricos
            if (strcmp(entrada, "F") == 0) {
                (*cav)->caverna[i][j] = 99;  // Representa a saída
            } else if (strcmp(entrada, "I") == 0) {
                (*cav)->caverna[i][j] = -99;  // Representa o início
            } else {
                // Convertendo a string numérica para inteiro
                (*cav)->caverna[i][j] = atoi(entrada);
            }
        }
    }

    fclose(arq);
    return 1;
}
