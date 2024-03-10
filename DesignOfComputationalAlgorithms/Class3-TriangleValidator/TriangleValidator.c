#include <stdio.h>

int main() { 
  int lado1, lado2, lado3;

  printf("Bem vindo ao programa validador e caracterizador de triangulos\n\n");
  printf("Insira o comprimento do 1 lado:");
  scanf("%d", &lado1);
  printf("Insira o comprimento do 2 lado:");
  scanf("%d", &lado2);
  printf("Insira o comprimento do 3 lado:");
  scanf("%d", &lado3);

  // validação do triangulo
  if((lado1 + lado2 < lado3) || (lado1 + lado3 < lado2) || (lado2 + lado3 < lado1)) {
    printf("\nSeu triangulo nao e valido.");
    return 1;
  }

  printf("\nSeu triangulo foi validado com sucesso.\n");

  // caracterizacao do triangulo

  if(lado1 != lado2 && lado2 != lado3 && lado1 != lado3) {
    printf("Triangulo caracterizado como: Escaleno");
  } else if (lado1 == lado2 && lado1 == lado3 && lado2 == lado3) {
    printf("Triangulo caracterizado como: Equilatero.");
  } else {
    printf("Triangulo caracterizado como: Isosceles.");
  }

  return 0;
}