#include <stdio.h>

int main() {
  int quantity;
  float number, average, sum = 0;

  printf("Bem vindo ao programa que soma e calcula a media de uma quantida de numeros\n\n");
  printf("Digite a quantidade de numeros que voce deseja calcular a media: ");
  scanf("%d", &quantity);

  if (quantity < 1) {
    printf("Por favor, digite uma quantidade de numeros valida.\n");
    return 1;
  }

  for (int i = 1 ; i < quantity + 1 ; i++) {
    printf("digite o %d numero: ", i);
    scanf("%f", &number);
    sum += number;
  }

  average = sum / quantity;
  printf("A media dos %d numeros e: %.2f\n", quantity, average);
  
  return 0;
}