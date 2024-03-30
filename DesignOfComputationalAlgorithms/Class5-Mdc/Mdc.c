#include <stdio.h>

int CalcularMDC(int a, int b) {
  int temp;

  if (a < b) {
    a = b;
    b = a;
  }

  while(b != 0) {
    temp = b; // 13 2
    b = a % b; // 2 
    a = temp; // 13
  }

  return a;
}


int main() {
  int num1, num2;
  printf("Bem vindo ao Programa calculador de MDC (de 2 numeros inteiros) \n\n");
  printf("Insira o primeiro numero: ");
  scanf("%d", &num1);
  printf("Insira o segundo numero: ");
  scanf("%d", &num2);

  int mdc = CalcularMDC(num1, num2);

  printf("O MDC de %d e %d e de: %d", num1, num2, mdc);

  return 0;
}