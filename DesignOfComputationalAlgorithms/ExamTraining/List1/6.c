#include <stdio.h>

int diasSemanas(int dias) {
  int qtdSemanas = dias / 7;
  int qtdDias = dias % 7;
  if(qtdDias > 1 && qtdSemanas > 1) { printf("%d semanas e %d dias.\n", qtdSemanas, qtdDias); }
  if(qtdDias == 1 && qtdSemanas > 1) { printf("%d semanas e %d dia.\n", qtdSemanas, qtdDias); }
  if(qtdDias > 1 && qtdSemanas == 1) { printf("%d semana e %d dias.\n", qtdSemanas, qtdDias); }
  if(qtdDias == 1 && qtdSemanas == 1) { printf("%d semana e %d dia.\n", qtdSemanas, qtdDias); }
}

int main() {
  int dias;
  printf("Escreva a quantidade de dias do evento: ");
  scanf("%d", &dias);
  printf("O evento tera ");
  diasSemanas(dias);

  return 0;
}