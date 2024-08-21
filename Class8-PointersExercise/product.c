#include <stdio.h>
#include <string.h>

typedef struct _Produto Produto;

struct _Produto {
    int codigo;
    int quantidade;
    char descricao[100];
    float preco;
};

int leProduto(Produto * p) { // passagem de parâmetro por referência
    int cod;
    scanf("%d", &cod);
    
    if(cod > 0) {
        p->codigo = cod;
        scanf(" %[^\t]s", p->descricao); // Espaço antes do % para ignorar os espaços e depois começar a leitura (botar na cola)
        scanf("%d", &p->quantidade);
        scanf("%f", &p->preco);
        return 1;
    }
    
    return 0;
};

void imprimeProduto(const Produto * p) {
    printf("Codigo: %d\n", p->codigo);
    printf("Descrição: %s\n", p->descricao);
    printf("Quantidade: %d\n", p->quantidade);
    printf("Preço: %f\n", p->preco);
}

int main() {
    Produto p;
    
    if(leProduto(&p)) {
        imprimeProduto(&p);
    }
    
    return 0;
}