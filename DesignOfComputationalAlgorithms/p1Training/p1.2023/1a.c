#include <stdio.h>

int leDadosResidencia(int qtdMoradores) {
  int QtdComodos = 0;
  int menoresIdade = 0;
  int idadeMoradorVelho = 0, idadeMoradorVelhoLocal = 0, idade;
 
  for(int i = 0; i < qtdMoradores; i++) {
    printf("escreva a idade do morador %d: ", i + 1);
    scanf("%d", &idade);

    if(idade < 18) {
      menoresIdade++;
    }

    if(idade > idadeMoradorVelho) {
      idadeMoradorVelho = idade;
    }
  }

  printf("Escreva a quantidade de comodos da sua casa: ");
  scanf("%d", &QtdComodos);

  printf("\n\nA quantidade de pessoas menores de idade e de %d.\n", menoresIdade);
  printf("\nA idade do morador mais velho e de %d.\n", idadeMoradorVelho);

  return QtdComodos;
}

int main() {
  int qtdMoradores;
  int totalResidencias = 0;
  int residenciasMaisTresComodos;

  while(1) {
    printf("Quantos moradores residem na sua casa incluido voce: ");
    scanf("%d", &qtdMoradores);

    if (qtdMoradores == 0) {
      break;
    }

    int qtdComodos = leDadosResidencia(qtdMoradores);

    if(qtdComodos > 3) {
      residenciasMaisTresComodos++;
    }

    totalResidencias++;

    printf("\nNumero total de residencias visitadas: %d\n", totalResidencias);
    printf("\nNumero total de residencias com mais de tres comodos: %d\n\n", residenciasMaisTresComodos);
  }

  return 0;
}