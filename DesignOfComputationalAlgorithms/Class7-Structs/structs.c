#include <stdio.h>

int main() {
  // definição
  struct rectangle {
  int width;
  int height;
  };

  // declaração
  struct rectangle my_rectangle;

  // inicialização
  my_rectangle.height = 10;
  my_rectangle.width = 20;

  printf("Height: %i\n Width:%i\n", my_rectangle.height, my_rectangle.width);

  return 0;
};