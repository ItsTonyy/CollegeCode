#include <stdio.h>

int leValidaTipo(int i) {
    int tipo = 0;
    printf("1-fruta, 2-legume, 3-verdura\n\n");
    printf("Insira o tipo do %d produto: ", i);
    scanf("%d", &tipo);

    while (tipo < 1 || tipo > 3) {
        printf("Insira o tipo VÁLIDO do %d produto: ", i);
        scanf("%d", &tipo);
    }
    
    return tipo;
}

void produtos(int qtdProdutos, int *f, int *l, int *v) {
    for (int i = 1; i <=qtdProdutos; i++) {
        int tipo = leValidaTipo(i);
        if(tipo == 1) {
            (*f)++;
        } else if (tipo == 2) {
            (*l)++;
        } else if (tipo == 3){
            (*v)++;
        }
    }
}

int main() {
    int qtdFrutas = 0;
    int qtdLegumes = 0;
    int qtdVerduras = 0;

    int qtdProdutos = 0;

    printf("insira a quantidade de produtos comercializados: ");
    scanf("%d", &qtdProdutos);

    produtos(qtdProdutos, &qtdFrutas, &qtdLegumes, &qtdVerduras);
    printf("\nA quantidad de frutas é de: %d\n", qtdFrutas);
    printf("A quantidad de legumes é de: %d\n", qtdLegumes);
    printf("A quantidad de verduras é de: %d\n\n", qtdVerduras);

    return 0;
}