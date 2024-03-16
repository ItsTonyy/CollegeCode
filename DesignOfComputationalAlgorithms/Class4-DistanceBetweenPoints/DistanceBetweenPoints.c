#include <stdio.h>
#include <math.h>

float distance(float x1, float y1, float x2, float y2) {
  float powx1y1 = pow((x1 - x2), 2);
  float powx2y2 = pow((y1 - y2), 2);

  float sqrtNumbers = sqrt(powx1y1 + powx2y2);
  return sqrtNumbers;
}

int main() {
  int quantity;
  float x1, y1, x2, y2;

  printf("Quantas duplas de coordenadas voce gostaria de inserir: ");
  scanf("%d", &quantity);
  printf("voce precisara inserir dois pontos distintos (x1, y1, x2, y2) para que a distancia entre eles seja computada.\n\n");
  
  for(int i = 1 ; i < quantity + 1 ; i++) {
    printf("insira a %d coordenada: ", i);
    scanf("%f%f%f%f", &x1, &y1, &x2, &y2);
    float distanceFunction = distance(x1, y1, x2, y2);
    printf("a distancia entre os pontos e de %.2f\n\n", distanceFunction);
  }
  
  return 0;
}