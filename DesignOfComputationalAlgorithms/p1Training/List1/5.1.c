#include <stdio.h>

int horasMinutos(int horas, int minutos) {
  int qtdMinutos = minutos;
  int horasPraMinutos = horas * 60;
  qtdMinutos += horasPraMinutos;

  return qtdMinutos;
}

int main() {
  int horas, minutos;
  printf("Insira a quantidade de horas: ");
  scanf("%d", &horas);
  printf("Insira a quantidade de minutos: ");
  scanf("%d", &minutos);

  printf("A quantidade de minutos e de: %d\n", horasMinutos(horas, minutos));

  return 0;
}