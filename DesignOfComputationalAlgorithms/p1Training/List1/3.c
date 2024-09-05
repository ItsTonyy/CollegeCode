#include <stdio.h>

int twentyPercent(int num) {
  return num * 1.2;
}

int main() {
  int value;
  printf("Insira o valor do produto que deseja dar 20 por cento de aumento: ");
  scanf("%d", &value);
  printf("O novo valor do produto e de %d.\n", twentyPercent(value));

  return 0;
}