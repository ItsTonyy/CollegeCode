#include <stdio.h>

int main(int argc, char** argv) {
  FILE *entrada;
  int numeroLinhas = 0, caractere;

  if(argc < 2) {
    fprintf(stderr, "erro na chamada de comando");
    return 1;
  }

  entrada = fopen(argv[1], "r");

  if(!entrada) {
		fprintf(stderr,"Arquivo %s não pode ser aberto para leitura\n", argv[1]);
		return 1;
	}

  while((caractere = fgetc(entrada)) != EOF) {
    if(caractere == 10) {
      numeroLinhas++;
    }
  }

  // incrementando o numero de linhas por 1 pois a ultima linha nunca conterá o caractere de quebra de linha
  printf("o arquivo tem exatamente %d linhas", numeroLinhas + 1);

  fclose(entrada);

  return 0;
}