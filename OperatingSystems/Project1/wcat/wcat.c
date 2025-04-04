#include <stdio.h>
#include <stdlib.h>

#define BUFFER_SIZE 4096

//argc = número de argumentos passados para o programa na linha de comando (contando a própria função)
//argv = array de strings que contém todos os argumentos passados (incluindo a própria função)

int main(int argc, char *argv[]) {
  for (int i = 1; i < argc; i++) {
    char buffer[BUFFER_SIZE];

    if(argc == 1) {
      return 1;
    }

    FILE *fp = fopen(argv[i], "r");

    if(fp == NULL) {
      printf("wcat: cannot open file\n");
      return 1;
    }

    while((buffer, BUFFER_SIZE, fp)) {
      printf("%s", buffer);
    }

    printf("\n\n");

    fclose(fp);
  }
  return 0;
}