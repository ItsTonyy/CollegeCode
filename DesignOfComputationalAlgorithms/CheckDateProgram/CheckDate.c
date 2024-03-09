#include <stdio.h>

int anoBissexto(int ano) {
    return (ano % 4 == 0 && (ano % 100 != 0 || ano % 400 == 0));
}

int main() {
    int dia, mes, ano;
    printf("Bem-vindo ao Verificador de Data!\n\n");
    printf("Por favor insira a data que voce deseja verificar no formato 'dia mes ano' : ");
    scanf("%d%d%d", &dia, &mes, &ano);

    // checar se a data e invalida nos padroes de calendario
    if ((dia < 1 || dia > 31) || (mes < 1 || mes > 12) || (ano < 1)) {
        printf("Erro: A data inserida e invalida. Certifique-se de inserir uma data existente.\n");
        return 1;
    }

    // checar se a quantidade de dias em determinado mes esta correta
    if (mes == 2) {
        if (dia > 29 || (dia == 29 && !anoBissexto(ano))) {
            printf("Erro: Fevereiro nao pode ter %d dias em %d.\n", dia, ano);
            return 1;
        }
    } else if ((mes == 4 || mes == 6 || mes == 9 || mes == 11) && dia > 30) {
            printf("Erro: O mes %d não pode ter mais de 30 dias.\n", mes);
            return 1;
    }

    // caso nada esteja errado, retorno uma mensagem de ok
    printf("A data inserida e valida!\n");

    return 0;
}