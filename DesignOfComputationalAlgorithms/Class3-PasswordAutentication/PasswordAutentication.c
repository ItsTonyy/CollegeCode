#include <stdio.h>

int main() {
  int userAnakinRegistration = 7892457, userLeiaRegistration = 5425376, userLukeRegistration = 2736252;
  int userAnakinPassword = 123321, userLeiaPassword = 812837, userLukePassword = 273625;
  int userRegistration, userPassword;

  char userAnakin[] = "Anakin Skywalker";
  char userLeia[] = "Leia Organa";
  char userLuke[] = "Luke Skywalker";

  printf("Bem-vindo ao Sistema de Autenticacao!\n\n");

  for (int i = 3; i > 0; i--) { 
  printf("Insira a matricula do usuario: ");
  scanf("%d", &userRegistration);
  printf("Insira a senha: ");
  scanf("%d", &userPassword);
      if(userRegistration == userAnakinRegistration && userPassword == userAnakinPassword) {
      printf("Bem-vindo, %s! Acesso concedido.", userAnakin);
      break;
    } else if(userRegistration == userLeiaRegistration && userPassword == userLeiaPassword) {
      printf("Bem-vindo, %s! Acesso concedido.", userLeia);
      break;
    } else if (userRegistration == userLukeRegistration && userPassword == userLukePassword) {
      printf("Bem-vindo, %s! Acesso concedido.", userLuke);
      break;
    } else {
      printf("Credenciais incorretas. Tente novamente. Tentativas restantes: %d \n", i - 1);
    }
  }

  return 0;
}