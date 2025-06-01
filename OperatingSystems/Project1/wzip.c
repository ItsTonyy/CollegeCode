#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Uso: %s arquivo1 [arquivo2 ...]\n", argv[0]);
        return 1;
    }

    for (int i = 1; i < argc; i++) {
        FILE *arquivo = fopen(argv[i], "r");

        if (arquivo == NULL) {
            printf("Erro ao abrir o arquivo: %s\n", argv[i]);
            return 1;
        }

        int caractereAtual, caractereAnterior = EOF;
        int repeticoes = 0;

        while ((caractereAtual = fgetc(arquivo)) != EOF) {
            if (caractereAtual == '\n') {
                continue; // Ignora quebras de linha
            }

            if (caractereAtual == caractereAnterior) {
                repeticoes++;
            } else {
                if (caractereAnterior != EOF) {
                    printf("%d%c", repeticoes, caractereAnterior);
                }
                caractereAnterior = caractereAtual;
                repeticoes = 1;
            }
        }

        if (caractereAnterior != EOF) {
            printf("%d%c", repeticoes, caractereAnterior);
        }

        fclose(arquivo);
    }

    return 0;
}
