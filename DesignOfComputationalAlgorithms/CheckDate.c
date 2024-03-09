#include <stdio.h>

int anoBissexto(int ano) {
    return (ano % 4 == 0 && (ano % 100 != 0 || ano % 400 == 0));
}

int main() {
    int dia, mes, ano, valido, checarAnoBissexto;
    printf("Bem vindo ao programa que calcula se uma data é valida ou não\n\nPor favor insira a data que você deseja verificar no formato dia/mês/ano: ");
    scanf("%d%d%d", &dia, &mes, &ano);

    valido = 0;

    // checar se o ano é bissexto e guardar essa informação
    checarAnoBissexto = anoBissexto(ano) ? 1 : 0;

    // checar se o mês está correto
    if (mes < 1 || mes > 12) {
        return;
    } else {
        valido = 1;
    }

    // checar se a quantidade de dias em cada mês está correto
    if (mes == 2) {
        if (checarAnoBissexto) {
            dia == 29 ? valido = 1 : 0;
        }
    } else if (mes == 4 || mes == 6 || mes == 9 || mes == 11) {
        dia == 30 ? valido = 1 : 0;
    } else {
        dia == 31 ? valido = 1 : 0;
    }

    return 0;
}

// meses com 31 dias: 1, 3, 5, 7, 8, 10, 12
// meses com 30 dias: 4, 6, 9, 11
// meses com 28 ou 29 dias: 2