#include <stdio.h>

  int BitchBetterHaveMyMoney(int moneyWithdrawn) {
    int MoneyToBeDivided = moneyWithdrawn;
    int oneHundredNotes = 0;
    int fiftyNotes = 0;
    int twentyNotes = 0;
    int tenNotes = 0;
    int fiveNotes = 0;
    int twoNotes = 0;
    int oneNotes = 0;

    oneHundredNotes = MoneyToBeDivided / 100; // quantidade de notas a serem dadas
    MoneyToBeDivided %= 100; // resto do dinheiro a ser passado pra baixo (caso tenha)
  
    fiftyNotes = MoneyToBeDivided / 50;
    MoneyToBeDivided %= 50;
  
    twentyNotes = MoneyToBeDivided / 20;
    MoneyToBeDivided %= 20;
  
    tenNotes = MoneyToBeDivided / 10;
    MoneyToBeDivided %= 10;
  
    fiveNotes = MoneyToBeDivided / 5;
    MoneyToBeDivided %= 5;
  
    twoNotes = MoneyToBeDivided / 2;
    MoneyToBeDivided %= 2;
  
    oneNotes = MoneyToBeDivided / 1;
    MoneyToBeDivided %= 1;

    printf("\nO valor, em reais, a ser sacado sera dado em %d nota(s) de 100, %d nota(s) de 50, %d nota(s) de 20, %d nota(s) de 10, %d nota(s) de 5, %d nota(s) de 2, %d nota(s) de 1.\n", oneHundredNotes, fiftyNotes, twentyNotes, tenNotes, fiveNotes, twoNotes, oneNotes);
}

int main() {
  int moneyWithdrawn = 0;
  
  do {
    printf("Escreva o valor a ser sacado: ");
    scanf("%d", &moneyWithdrawn);
  } while(moneyWithdrawn < 1);

  BitchBetterHaveMyMoney(moneyWithdrawn);

  return 0;
}