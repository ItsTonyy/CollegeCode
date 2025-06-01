#include <stdio.h>
#include <stdlib.h>

int main(int quantidade_argumentos, char *argumentos[]) {
    if (quantidade_argumentos < 2) {
        printf("wunzip: file1 [file2 ...]\n");
        return 1;
    }

    for (int i = 1; i < quantidade_argumentos; i++) {
        FILE *arquivo = fopen(argumentos[i], "r");

        if (arquivo == NULL) {
            printf("wunzip: não foi possível abrir o arquivo %s\n", argumentos[i]);
            return 1;
        }

        int repeticoes;
        char caractere;

        while (fread(&repeticoes, sizeof(int), 1, arquivo) == 1 &&
               fread(&caractere, sizeof(char), 1, arquivo) == 1) {
            for (int j = 0; j < repeticoes; j++) {
                fputc(caractere, stdout);
        }

        fclose(arquivo);
    }

    return 0;
}