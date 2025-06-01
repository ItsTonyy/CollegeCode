#include <stdio.h>
#include <stdlib.h>

#define BUFFER_SIZE 4096

//argc = número de argumentos passados para o programa na linha de comando (contando a própria função)
//argv = array de strings que contém todos os argumentos passados (incluindo a própria função)

int main(int argc, char *argv[]) {
  if(argc == 1) {
    return 1;
  }

  for (int i = 1; i < argc; i++) {
    char buffer[BUFFER_SIZE];

    FILE *fp = fopen(argv[i], "r");

    if(fp == NULL) {
      printf("wcat: cannot open file\n");
      return 1;
    }

    while(fgets(buffer, BUFFER_SIZE, fp) != NULL) {
      printf("%s", buffer);
    }
    
    fclose(fp);
  }
  return 0;
}