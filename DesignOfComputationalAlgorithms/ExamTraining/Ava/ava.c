#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#ifdef _WIN32
    #define CLEAR "cls"
#else
    #define CLEAR "clear"
#endif

int exibirMenu() {
  int escolha;

  system(CLEAR);
  printf("[1] Questao 1\n");
  printf("[2] Questao 2\n");
  printf("[3] Questao 3\n");
  printf("[4] Questao 4\n");
  printf("[5] Questao 5\n");
  printf("[6] Questao 6\n");
  printf("\n( Utilize esse programa para verificar suas respostas )\n\nQual questao deseja resolver? ");
  scanf("%d", &escolha);

  return escolha;
}

void sair() {
  char saida;

  printf("\n\nInsira qualquer caractere para voltar: ");  
  scanf(" %c", &saida);
}

void exibirAviso() {
  printf("--- IMPORTANTE ---\n\nInsira as coordenadas no formato X Y Z\nCaso haja uma fracao, realize a divisao e insira o numero com ponto (ex: 1.5)\nCaso seja uma dízima periodica, insira pelo menos 5 casas decimais para garantir a precisao (ex: 0.13333)\n\n------------------\n\n");
}

float calcularNorma(float ponto[], int tamanho) {
  float soma = 0;
  
  for (int i = 0; i < tamanho; i++) {
    soma += pow(ponto[i], 2);
  }
  
  return sqrt(soma);
}

void calcularProdutoVetorial(float coords1[], float coords2[], float produto_vetorial[]) {
  float i, j, k;  
  i = (coords1[1]*coords2[2])-(coords1[2]*coords2[1]);
  j = (coords1[2]*coords2[0])-(coords1[0]*coords2[2]);
  k = (coords1[0]*coords2[1])-(coords1[1]*coords2[0]);
  
  produto_vetorial[0] = i;
  produto_vetorial[1] = j;
  produto_vetorial[2] = k;
}

float calcularProdutoMisto(float coords1[], float coords2[], float coords3[]) {
  float produto_misto;

  produto_misto = (
    (coords1[1]*coords2[2]*coords3[0]) +
    (coords1[0]*coords2[1]*coords3[2]) +
    (coords1[2]*coords2[0]*coords3[1])
  ) - (
    (coords1[1]*coords2[0]*coords3[2]) +
    (coords1[2]*coords2[1]*coords3[0]) +
    (coords1[0]*coords2[2]*coords3[1])
  );

  return produto_misto;
}

float calcularProdutoInterno(float coords1[], float coords2[], int tamanho) {
  float produto_interno = 0;

  for (int i = 0; i < tamanho; i++) {
    produto_interno += coords1[i] * coords2[i];
  }

  return produto_interno;
}

void calcularProdutoPorUmEscalar(float escalar, float coords[], float resultado[], int tamanho) {
  for (int i = 0; i < tamanho; i++) {
    resultado[i] = coords[i] * escalar;
  }
}

void calcularAB(float coordsA[], float coordsB[], float coordsAB[] , int tamanho) {
  for (int i = 0; i < tamanho; i++) {
      coordsAB[i] = coordsB[i] - coordsA[i];
  }
}

void calcularAmaisB(float coordsA[], float coordsB[], float coordsAmaisB[], int tamanho) {
  for (int i = 0; i < tamanho; i++) {
      coordsAmaisB[i] = coordsA[i] + coordsB[i];
  }
}

void calcularProjecao(float coordsU[], float coordsV[], float projecao[], int tamanho) {
  float produto_intero_UV = calcularProdutoInterno(coordsU, coordsV, tamanho),
        produto_intero_UU = calcularProdutoInterno(coordsU, coordsU, tamanho),
        escalar = produto_intero_UV / produto_intero_UU;

  calcularProdutoPorUmEscalar(escalar, coordsU, projecao, tamanho);
}

float calcularDistanciaPontoAlgo(float N[], float ponto[], int tamanho) {
  float distancia, numerador = 0, denominador = 0;
  
  for (int i = 0; i < tamanho; i++) {
    if (i == tamanho-1) {
      numerador += N[i];
    } else {
      numerador += N[i]*ponto[i];
      denominador += pow(N[i], 2);
    }
  }

  if (numerador < 0) {
    numerador *= -1;
  }

  distancia = numerador/sqrt(denominador);
  return distancia;
}

float calcularDistanciaEntrePontos(float P1[], float P2[], int tamanho) {
  float distancia, coordsDistanciaP1P2[tamanho];

  calcularAB(P1, P2, coordsDistanciaP1P2, 3);
  distancia = calcularNorma(coordsDistanciaP1P2, tamanho);

  return distancia;
}

float converterRadParaGraus(float rad) {
  float graus;
  graus = rad * (180/3.14159);
  return graus;
}

void resolverQuestao1() {
  float n;
  
  system(CLEAR);
  printf("Na questao esta escrito que:\nAX = N.XB\n\nInsira o valor de \"N\": ");
  scanf("%f", &n);

  printf("\n\nResposta: %.3f", 1/(1+n));
  
  sair();
}

void resolverQuestao2() {
  float pontoA[3] = {}, pontoB[3] = {}, pontoC[3] = {},
        pontoAlinha[3] = {}, pontoBlinha[3] = {},
        produto_vetorial[3] = {},
        area_do_triangulo;

  system(CLEAR);
  exibirAviso();
  printf("Coordenadas do Ponto A: ");
  scanf("%f %f %f", &pontoA[0], &pontoA[1], &pontoA[2]);
  printf("Coordenadas do Ponto B: ");
  scanf("%f %f %f", &pontoB[0], &pontoB[1], &pontoB[2]);
  printf("Coordenadas do Ponto C: ");
  scanf("%f %f %f", &pontoC[0], &pontoC[1], &pontoC[2]);

  calcularAmaisB(pontoA, pontoB, pontoAlinha, 3);
  calcularAmaisB(pontoB, pontoC, pontoBlinha, 3);

  calcularProdutoVetorial(pontoAlinha, pontoBlinha, produto_vetorial);

  area_do_triangulo = calcularNorma(produto_vetorial, 3)/2;
  
  printf("\n\nResposta: %.3f", area_do_triangulo*2);

  sair();
}

void resolverQuestao3() {
  int tamanho;
  float pontoA[3] = {}, pontoB[3] = {}, pontoC[3] = {},
        pontoAlinha[3] = {}, pontoBlinha[3] = {}, pontoClinha[3] = {},
        pontoN[3] = {}, pontoNcomD[4] = {},
        distancia, volume;

  system(CLEAR);
  exibirAviso();
  printf("Coordenadas do Ponto A: ");
  scanf("%f %f %f", &pontoA[0], &pontoA[1], &pontoA[2]);
  printf("Coordenadas do Ponto B: ");
  scanf("%f %f %f", &pontoB[0], &pontoB[1], &pontoB[2]);
  printf("Coordenadas do Ponto C: ");
  scanf("%f %f %f", &pontoC[0], &pontoC[1], &pontoC[2]);

  calcularAmaisB(pontoA, pontoB, pontoAlinha, 3);
  calcularAmaisB(pontoB, pontoC, pontoBlinha, 3);
  calcularAmaisB(pontoA, pontoC, pontoClinha, 3);

  calcularProdutoVetorial(pontoAlinha, pontoBlinha, pontoN);

  pontoNcomD[0] = pontoN[0];
  pontoNcomD[1] = pontoN[1];
  pontoNcomD[2] = pontoN[2];
  pontoNcomD[3] = pontoN[0]*pontoAlinha[0] + pontoN[1]*pontoAlinha[1] + pontoN[2]*pontoAlinha[2];

  distancia = calcularDistanciaPontoAlgo(pontoNcomD, pontoClinha, 4);
  
  printf("\n\nResposta da letra A: %.2f", distancia);
  
  volume = calcularProdutoMisto(pontoA, pontoB, pontoC);
  if (volume < 0) {
    volume *= -1;
  }
  printf("\n\nResposta da letra B: %.2f", volume);

  sair();
}

void resolverQuestao4() {
  float pontoA[4] = {}, pontoB[4] = {},
        normaB, normaA, X, Y, a;

  system(CLEAR);
  exibirAviso();
  printf("Coordenadas do Ponto A: ");
  scanf("%f %f %f %f", &pontoA[0], &pontoA[1], &pontoA[2], &pontoA[3]);
  printf("Coordenadas do Ponto B: ");
  scanf("%f %f %f %f", &pontoB[0], &pontoB[1], &pontoB[2], &pontoB[3]);

  if(pontoA[0] != 1 || pontoA[1] != -1 || pontoB[0] != -1 || pontoB[1] != 3) {
    printf("\nVerifique os valores inseridos. Caso estejam todos certos, infelizmente esse programa nao sera capaz de resolver a questao.");
    sair();
    return;
  }

  normaA = calcularNorma(pontoA, 4);
  normaB = calcularNorma(pontoB, 4);
  X = (normaB-normaA)/(normaB+normaA);
  Y = ((3*normaA)-normaB)/(normaB+normaA);
  a = ((X+Y)/2)+X;

  printf("\n\nResposta: %.3f", a);

  sair();
}

void resolverQuestao5() {
  float pontoA[4] = {}, pontoB[4] = {}, pontoP[4] = {},
        pontoAB[4] = {}, pontoAP[4] = {}, pontoAQ[4] = {},
        pontoQ[4] = {};

  system(CLEAR);
  exibirAviso();
  printf("Coordenadas do Ponto A: ");
  scanf("%f %f %f %f", &pontoA[0], &pontoA[1], &pontoA[2], &pontoA[3]);
  printf("Coordenadas do Ponto B: ");
  scanf("%f %f %f %f", &pontoB[0], &pontoB[1], &pontoB[2], &pontoB[3]);
  printf("Coordenadas do Ponto P: ");
  scanf("%f %f %f %f", &pontoP[0], &pontoP[1], &pontoP[2], &pontoP[3]);  

  calcularAB(pontoA, pontoB, pontoAB, 4);
  calcularAB(pontoA, pontoP, pontoAP, 4);
  
  calcularProjecao(pontoAB, pontoAP, pontoAQ, 4);
  
  calcularAmaisB(pontoAQ, pontoA, pontoQ, 4);

  printf("\n\nResposta:\nQ(%.3f, %.3f, %.3f, %.3f)", pontoQ[0], pontoQ[1], pontoQ[2], pontoQ[3]);

  sair();
}

void resolverQuestao6() {
  float vetorV[3] = {}, vetorK[3] = {0, 0, 1},
        coeficientesEq1[3] = {}, coeficientesEq2[3] = {},
        anguloRetasEmRad, anguloRetasEmGraus,
        anguloPlanosEmRad, anguloPlanosEmGraus,
        razaoX, x, y;

  system(CLEAR);
  exibirAviso();
  
  printf("Insira os coeficientes de X Y Z:\n\n");
  printf("Na primeira equacao: ");
  scanf("%f %f %f", &coeficientesEq1[0], &coeficientesEq1[1], &coeficientesEq1[2]);
  printf("Na segunda equacao: ");
  scanf("%f %f %f", &coeficientesEq2[0], &coeficientesEq2[1], &coeficientesEq2[2]);

  // Calculando Letra B
  anguloPlanosEmRad = acosf(
      calcularProdutoInterno(coeficientesEq1, coeficientesEq2, 3) /
      (calcularNorma(coeficientesEq1, 3)*calcularNorma(coeficientesEq2, 3))
  );
  anguloPlanosEmGraus = converterRadParaGraus(anguloPlanosEmRad);
  
  // Calculando Letra A
  razaoX = coeficientesEq2[0]/coeficientesEq1[0];
  y = -((coeficientesEq1[2]*razaoX)-coeficientesEq2[2]) / ((coeficientesEq1[1]*razaoX)-coeficientesEq2[1]);
  x = (-(coeficientesEq1[1]*y)-(coeficientesEq1[2])) / coeficientesEq1[0];

  vetorV[0] = x;
  vetorV[1] = y;
  vetorV[2] = 1;
  
  anguloRetasEmRad = acosf(
      calcularProdutoInterno(vetorV, vetorK, 3) /
      (calcularNorma(vetorV, 3)*calcularNorma(vetorK, 3))
  );
  anguloRetasEmGraus = converterRadParaGraus(anguloRetasEmRad);

  // Printando respostas
  printf("\n\nResposta da letra A: %.2f\n", anguloRetasEmGraus);
  printf("Resposta da letra B: %.2f", anguloPlanosEmGraus);

  sair();
}

int main() {
  int escolha;

  do {
    escolha = exibirMenu();

    switch (escolha) {
      case 1:
        resolverQuestao1();
        break;
      case 2:
        resolverQuestao2();
        break;
      case 3:
        resolverQuestao3();
        break;
      case 4:
        resolverQuestao4();
        break;
      case 5:
        resolverQuestao5();
        break;
      case 6:
        resolverQuestao6();
        break;
      default:
        break;
    }
  } while (escolha >= 1 && escolha <= 6);
  
  return 0;
}