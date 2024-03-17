#include <stdio.h>

int main() {
  int registration, salary, quantity, biggestSalary = 0, workersWithBiggestSalary;
  printf("Bem vindo ao programa que calcula o maior salario de sua empresa e a quantidade de funcionarios que o recebem.\n\n");
  printf("Insira a quantidade de funcionarios de sua empresa: ");
  scanf("%d", &quantity);

  if(quantity < 1) {
    printf("insira uma quantidade de trabalhadores valida.");
    return 1;
  }

  for (int i = 1; i < quantity + 1; i++) { 
    printf("Insira a matricula e o salario do %d trabalhador: ", i);
    scanf("%d%d", &registration, &salary);

    if(salary < 0) {
      printf("insira um salario valido.");
      return 1;
    }

    if(salary > biggestSalary) {
      biggestSalary = salary;
      workersWithBiggestSalary = 1;
    } else if (salary == biggestSalary) {
      workersWithBiggestSalary++;
    }
  }

  printf("O maior salario e de R$%d\n.", salary);
  printf("A quantidade de trabalhadores com o maior salario e de: %d", workersWithBiggestSalary);
  
  return 0;
}