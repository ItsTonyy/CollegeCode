#include <stdio.h>

struct produtos {
  int codigo;
  int codigo_fornecedor;
  int tipo_produto;
  float preco_atual;
};

void preenchePercentualAumentoPorFornecedor(float percentualAumento[], int codigo_fornecedor) {
  printf("diga o código do fornecedor: ");
  scanf("%d", &codigo_fornecedor);

  for(int i = 0; i < 10; i++) {
    printf("insira o percentual de aumento do %d fornecedor", i + 1);
    scanf("%f", percentualAumento[i]);
  }
}

int main() {



  return 0;
}