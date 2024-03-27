#include <stdio.h>

int main() {
    int N, contador = 1;
    int sum = 0;

    printf("insira um numero positivo inteiro qualquer: ");
    scanf("%d", &N);

    while(N < 1) {
        printf("\ninsira um numero inteiro positivo valido");
        scanf("%d", &N);
    }

    while (contador <= N) { 
        sum += contador;
        contador++;
    }
    
    printf("\no resultado da soma é de %Ld\n\n", sum);

    return 0;
}