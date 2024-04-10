#include <stdio.h>

float calculaValor(float valorLitro, float qtdLitros) {
  return valorLitro * qtdLitros;
}

int main() {
  float valorLitro, qtdLitros;
  printf("Insira o valor por litro: ");
  scanf("%f", &valorLitro);
  printf("Insira a quantidade de litros: ");
  scanf("%f", &qtdLitros);
  printf("O total a ser pago e de R$%.2f reais!\n", calculaValor(valorLitro, qtdLitros));

  return 0;
}