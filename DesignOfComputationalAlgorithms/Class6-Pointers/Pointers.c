#include <stdio.h>

// # tipos de ponteiros --

// int x = 10;

// ## multiplicação
// 2 * 2 = 4

// ## ponteiro
//int *p; (declarando que o inteiro p é um ponteiro)
// p = &x; (p, que é um ponteiro, está apontando para o valor na memória de X)

// ## mudando o valor da memória por ponteiro
// *p = 20; (equivalente a x = 20;, ou seja, eu estou mudando o valor de X na memória para 20)


// # Exemplo de função com efeito colateral --

int f(int *x) {
    (*x)++; // aumentando o valor em 1 do lugar da memória pra onde x foi apontado
    return *x;
}

int g() {
    int z = 10; // z sofre efeito colateral e seu numero agora é 11
    int w = f(&z);  // w chama a função f e muda o valor de z pra 11, mudando então seu próprio valor pra 11
    printf("%d%d", z, w);
}