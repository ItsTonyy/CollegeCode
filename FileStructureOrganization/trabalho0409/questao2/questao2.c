#include <stdio.h>

int main(int argc, char** argv) {
  FILE *entrada;
  int numeroLinhas = 0, byte_lido;
  int contadores[256] = {0};

  if(argc < 2) {
    fprintf(stderr, "erro na chamada de comando");
    return 1;
  }

  entrada = fopen(argv[1], "rb");

  if(!entrada) {
		fprintf(stderr,"Arquivo %s não pode ser aberto para leitura\n", argv[1]);
		return 1;
	}

  while ((byte_lido = fgetc(entrada)) != EOF) {
    contadores[byte_lido]++;
  }

 printf("Frequencia de cada letra no arquivo '%s':\n", argv[1]);

  for (int i = 0; i < 256; i++) {
    if ((i >= 'a' && i <= 'z') || (i >= 'A' && i <= 'Z')) {
      if (contadores[i] > 0) {
        printf("Letra '%c': %d vezes\n", (char)i, contadores[i]);
      }
    }
  }

  fclose(entrada);

  return 0;
}