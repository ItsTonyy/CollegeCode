#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void searchPattern(FILE *file, char *word) {
  //getline ajustará automaticamente
  char *line = NULL;
  size_t bufferSize = 0; 

  while(getline(&line, &bufferSize, file) != -1) {
    char *stringFilter = strstr(line, word);

    if(stringFilter != NULL) {
      printf("%s\n", stringFilter);
      return;
    }
  }
  free(line);
}

int main(int argc, char *argv[]) {
  if(argc == 1) {
    printf("wgrep: searchterm [file ...]\n");
    return 1;
  }

  for (int i = 1; i < argc - 1; i++) {
    FILE *fp = fopen(argv[i + 1], "r");

    if(fp == NULL) {
      printf("wgrep: cannot open file\n");
      return 1;
    }

    searchPattern(fp, argv[1]);

    fclose(fp);
  }

  return 0;
}