#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void searchPattern(FILE *file, char *word) {
  char *line = NULL;
  size_t bufferSize = 0; 

  while(getline(&line, &bufferSize, file) != -1) {
    if(strstr(line, word) != NULL) {
      printf("%s", line);  // Linha já contém '\n'
    }
  }
  free(line);
}

int main(int argc, char *argv[]) {
  if(argc < 2) {
    printf("wgrep: searchterm [file ...]\n");
    return 1;
  }

  if(argc == 2) {
    // Lê da entrada padrão (stdin)
    searchPattern(stdin, argv[1]);
  } else {
    for (int i = 2; i < argc; i++) {
      FILE *fp = fopen(argv[i], "r");

      if(fp == NULL) {
        printf("wgrep: cannot open file\n");
        return 1;
      }

      searchPattern(fp, argv[1]);
      fclose(fp);
    }
  }

  return 0;
}