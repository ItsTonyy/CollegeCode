#include <stdio.h>
#include <stdlib.h>

int main() {
  int num;
  int multiplo;

  printf("Insira um numero: ");
  scanf("%i", &num);
  printf("Quantas vezes quer multiplicar ele: ");
  scanf("%i", &multiplo);

  int aux = num;

  if(multiplo == 0 || num == 0) {
    printf("\nResultado: 0");
    return 1;
  }

  for(int i = multiplo - 1; i > 0; i--) {
    num = aux + num;
  }

  printf("\nResultado: %i", num);

  return 0;
}