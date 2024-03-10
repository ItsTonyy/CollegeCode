#include <stdio.h> 
#include <math.h>

int main() {
  float a, b, c, delta, x, x1, x2;
  
  printf("por favor entre com os valores de a,b,c: ");

  scanf("%f%f%f", &a,&b,&c); 
  
  delta = b*b-4*a*c;

  if(delta > 0) {
    x1 = (-b + sqrt(delta)) / (2 * a);
    x2 = (-b - sqrt(delta)) / (2 * a);

    printf("Raizes são: %f e %f", x1, x2);
  }

  if(delta < 0) {
    printf("Não existe raiz real.");
  }

  if(delta == 0) {
    x = -b/(2*a);
    printf("Existe apenas uma raiz: %f", x);
  }

  return 0;

}