#include <stdio.h>
#include <string.h>

#define NUM_CARGOS 2
#define NUM_CANDIDATOS 3

typedef struct _Candidato Candidato;
typedef struct _Cargo Cargo;

void leDadosCargos(char nomeCargo[][30], float notasMinimas[][2]) {
  for (int i = 0; i < NUM_CARGOS; i++) {
    scanf(" %s", nomeCargo[i]);
    scanf("%f%f", &notasMinimas[i][0], &notasMinimas[i][1]);
  }
}

int calculaNotaFinal(float *notaFinal, float notaMinimaTitulo,
                     float notaMinimaEspecifica) {
  float nota;
  int abaixoMedia = 0;
  int qtZeros = 0;
  float soma = 0;

  for (int i = 0; i < 5; i++) {
    scanf("%f", &nota);

    if (nota == 0) {
      qtZeros++;
    }

    if (i == 0 && nota < notaMinimaTitulo) {
      abaixoMedia = 1;
    }

    if (i > 0 && nota < notaMinimaTitulo) {
      abaixoMedia = 1;
    }
    
    soma += nota;
  }
  
  if(abaixoMedia || qtZeros > 0) {
    *notaFinal = 0;
  } else {
    *notaFinal = soma / 5;
  }

  return qtZeros;
}

int busca(char nomeCargo[][30], char cargoProcurado[]) {
  for(int i = 0; i<NUM_CARGOS; i++) {
    if(strcmp(nomeCargo[i], cargoProcurado) == 0) {
      return i;
    }
  }
  return -1;
}

int main() { 
  char nomeCandidato[30];
  char cargoPretendido[30];
  char nomeCargo[NUM_CARGOS][30];
  float notasMinimas[NUM_CARGOS][2];

  leDadosCargos(nomeCargo, notasMinimas);

  for(int i=0; i<NUM_CANDIDATOS; i++) {
    scanf(" %s", nomeCandidato);
    scanf(" %s", cargoPretendido);
    
    int j = busca(nomeCargo, cargoPretendido); // verifica se o cargo existe

    if(j == -1) {
      printf("Cargo %s inexistente.\n", cargoPretendido);
    } else {
      float notaFinal;
      
      int qtdZeros = calculaNotaFinal(&notaFinal, notasMinimas[j][0], notasMinimas[j][1]);
      
      if(qtdZeros > 0) {
        printf("Zerou em alguma prova. Reprovado./n");
      } else if (notaFinal == 0) {
        printf("Não atingiu o mínimo. Reprovado./n");
      } else {
        printf(" %s %f", nomeCargo[j], notaFinal);
      }
      
    }
  }

  return 0; 
}