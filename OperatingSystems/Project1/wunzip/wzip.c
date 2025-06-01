#include <stdio.h>
#include <stdlib.h>

int main(int quantidade_argumentos, char *argumentos[]) {
    if (quantidade_argumentos < 2) {
        printf("wzip: file1 [file2 ...]\n");
        return 1;
    }

    int caractere_atual;
    int caractere_anterior = EOF;
    int repeticoes = 0;

    for (int i = 1; i < quantidade_argumentos; i++) {
        FILE *arquivo = fopen(argumentos[i], "r");

        if (arquivo == NULL) {
            fprintf(stderr, "wzip: não foi possível abrir o arquivo %s\n", argumentos[i]);
            return 1;
        }

        while ((caractere_atual = fgetc(arquivo)) != EOF) {
            if (caractere_atual == caractere_anterior) {
                repeticoes++;
            } else {
                if (repeticoes > 0) {
                    fwrite(&repeticoes, sizeof(int), 1, stdout);
                    fwrite(&caractere_anterior, sizeof(char), 1, stdout);
                }
                repeticoes = 1;
                caractere_anterior = caractere_atual;
            }
        }

        fclose(arquivo);
    }

    if (repeticoes > 0) {
        fwrite(&repeticoes, sizeof(int), 1, stdout);
        fwrite(&caractere_anterior, sizeof(char), 1, stdout);
    }

    return 0;
}