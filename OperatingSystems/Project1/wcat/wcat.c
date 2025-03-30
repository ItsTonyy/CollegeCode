#include <stdio.h>
#include <stdlib.h>

#define BUFFER_SIZE 4096

//argc = número de argumentos passados para o programa na linha de comando (contando o próprio)
//argv = array de strings que contém todos os argumentos passados (incluindo o próprio)
int main(int argc, char *argv[]) {
  for (int i = 1; i < argc; i++) {
    char buffer[BUFFER_SIZE];

    FILE *fp = fopen(argv[i], "r");

    if(argc == 1) {
      exit(0);
    }

    if(fp == NULL) {
      printf("wcat: cannot open file\n");
      exit(1);
    }

    while(fgets(buffer, BUFFER_SIZE, fp)) {
      printf("%s", buffer);
    }

    printf("\n\n");

    fclose(fp);
  }
  return 0;
}