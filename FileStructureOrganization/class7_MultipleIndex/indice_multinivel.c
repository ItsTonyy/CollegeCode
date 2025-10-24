// cria_indice: Cria um arquivo indice_ceps.dat com base num arquivo desordenado cep.dat contendo informações de vários endereços com base em seus respectivos CEPs
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "endereco.h"

// compara: função que compara dois endereços
int compara(const void *i1, const void *i2) {
    return strncmp(((EnderecoIndice*)i1)->cep, ((EnderecoIndice*)i2)->cep, 8);
}

int main() {
    FILE *f, *saida;
    EnderecoIndice buffer; 
    EnderecoIndice* indices;
    long qtdEnderecos;

    f = fopen("indice_ceps.dat", "rb");
    if(!f) {
        fprintf(stderr, "ERRO: Arquivo cep.dat inexistente\n");
    }
    saida = fopen("indice_multinivel_ceps.dat", "w+b");

    fseek(f, 0, SEEK_END);
    qtdEnderecos = ftell(f) / sizeof(EnderecoIndice);
    rewind(f);

    int intervalo = qtdEnderecos/1000;
    printf("%d\n", intervalo);

    // indices: array de estruturas EnderecoIndice para armazenar cada entrada do índice
    indices = (EnderecoIndice*) malloc(1000 * sizeof(EnderecoIndice));

    printf("Lendo enderecos de indice_ceps.dat e criando indices...\n");
    long i = 0, contador = 0;
    fread(&buffer, sizeof(EnderecoIndice), 1, f);
    while(!feof(f) && i < 1000) { // armazena CEP e posição de cada endereço numa entrada do 
        strcpy(indices[i].cep, buffer.cep);
        printf("contador igual: %d\n", contador);
        indices[i].pos = contador;
        fseek(f, (intervalo - 1)*sizeof(EnderecoIndice), SEEK_CUR);
        fread(&buffer, sizeof(EnderecoIndice), 1, f);
        i++;
        contador += intervalo;
    }
    qsort(indices, 1000, sizeof(EnderecoIndice), compara); // ordena o array com base na função compara

    fwrite(indices, sizeof(EnderecoIndice), 1000, saida); // escreve o array de registros ordenado no arquivo de saída
    free(indices); // libera a memória alocada para os índices

    printf("Finalizado!\n");
    fclose(saida);
    fclose(f);
    return 0;
}