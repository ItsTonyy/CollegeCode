#include <stdio.h>

int leValidaTipo() {
  int tipo;
  while(1) {
    printf("Escolha o tipo do produto:\n");
    printf("1-fruta\n2-legume\n3-verdura\n---------------\n");

    scanf("%d", &tipo);

    if(tipo < 1 || tipo > 3) {
      continue;
    }

    return tipo;
  }
}

int contadorProdutos(int qtd, int *tipo1, int *tipo2, int *tipo3) {
  for(int i = 0; i < qtd; i++) {
    int codigo;
    printf("insira o codigo do produto numero %d: ", i + 1);
    scanf("%d", &codigo);
    int tipo = leValidaTipo();
    if(tipo == 1) {
      (*tipo1)++;
    } else if(tipo == 2) {
      (*tipo2)++;
    } else {
      (*tipo3)++;
    }
  }
}

int main() {
  int qtd;
  int tipo1 = 0, tipo2 = 0, tipo3 = 0;
  printf("Insira a quantidade de produtos que quer catalogar: ");
  scanf("%d", &qtd);
  contadorProdutos(qtd, &tipo1, &tipo2, &tipo3);
  printf("Quantidade de produtos do tipo 1: %d\n", tipo1);
  printf("Quantidade de produtos do tipo 2: %d\n", tipo2);
  printf("Quantidade de produtos do tipo 3: %d\n", tipo3);

  return 0;
}