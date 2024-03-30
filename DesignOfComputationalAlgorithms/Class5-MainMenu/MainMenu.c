#include <stdio.h>

void menuPrincipal() {
   int numeroEscolhido = 1;

    printf("Menu Principal:\n1. Incluir\n2. Excluir\n3. Alterar\n4. Consultar\n5. Relatorio\n6. Fim\n\n");
    printf("Escolha uma opcao: ");
    scanf("%d", &numeroEscolhido);

    while (numeroEscolhido < 1 || numeroEscolhido > 6)
    {
      printf("Escolha uma opcao valida: ");
      scanf("%d", &numeroEscolhido);
    }
    

    if(numeroEscolhido == 1) {
      printf("\n 1. Incluir");
    }

    if(numeroEscolhido == 2) {
      printf("\n 2. Excluir");
    }

    if(numeroEscolhido == 3) {
      printf("\n 3. Alterar");
    }

    if(numeroEscolhido == 4) {
      printf("\n 4. Consultar");
    }

    if(numeroEscolhido == 5) {
      printf("\n 5. Relatorio");
    }

    if(numeroEscolhido == 6) {
      printf("\n 6. fim");
    }
}

int main() {
  printf("Bem vindo ao menu principal, escolha uma das opcoes abaixo: \n");
  menuPrincipal();
  return 0;
}