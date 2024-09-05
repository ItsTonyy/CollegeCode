#include <stdio.h>

int menu() {
    int opcaoEscolhida;

    printf("1 - Quadrado (Dado a ser lido: lado. Área: lado x lado).\n2 - Retângulo(Dados a serem lidos: base e altura. Área: Base x Altura)\n3 - Triângulo (Dados a serem lidos: Base e Altura. Área: (base x altura)/2)\n4 - Trapézio (Dados a serem lidos: Base maior, Base menor e Altura. Área: ((base maior + base menor) x altura)/2)\n5 - Fim.\n\n");
    printf("Escolha uma das operações acima: ");
    scanf("%d", &opcaoEscolhida);

    while (opcaoEscolhida > 5 || opcaoEscolhida < 1) {
      opcaoEscolhida = menu();
    }

    return opcaoEscolhida;
}

float quadrado() {
    float lado;
    printf("Insira o valor do lado: ");
    scanf("%f", &lado);

    return lado*lado;
}

float retangulo() {
    float base, altura;
    printf("Insira o valor da base: ");
    scanf("%f", &base);
    printf("Insira o valor da altura: ");
    scanf("%f", &altura);

    return base*altura;
}

float triangulo() {
    float base, altura;
    printf("Insira o valor da base: ");
    scanf("%f", &base);
    printf("Insira o valor da altura: ");
    scanf("%f", &altura);

    return (base*altura)/2;
}

float trapezio() {
    float baseMaior, baseMenor, altura;
    printf("Insira o valor da base maior: ");
    scanf("%f", &baseMaior);
    printf("Insira o valor da base menor ");
    scanf("%f", &baseMenor);
    printf("Insira o valor da altura: ");
    scanf("%f", &altura);

    return ((baseMaior*baseMenor)*altura)/2;
}

int main() {
    int escolha;

    do {
        escolha = menu();

        if(escolha == 1) {
            printf("O valor da area do quadrado e de: %f\n\n", quadrado());
        } else if (escolha == 2) {
            printf("O valor da area do retangulo e de: %f\n\n", retangulo());
        } else if (escolha == 3) {
            printf("O valor da area do triangulo e de: %f\n\n", triangulo());
        } else if (escolha == 4){
            printf("O Valor da area do trapezio e de: %f\n\n", trapezio());
        }
    } while (escolha != 5);
}