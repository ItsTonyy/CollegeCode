#include <iostream>

using namespace std;

struct no {
  int num;
  struct no * prox;
}

typedef struct no * noPtr;

noPtr topo = null;

void menu() {
  do {
    cout << "--- Comandos ---\n";
    cout << "[0] Para parar o programa\n";
    cout << "[1] Inserir um no\n";
    cout << "[2] Remover um no\n";
    cout << "[3] Listar a lista encadeada\n";
    cout << "Insira um comando: ";
    cin >> numMenu; // can i access numMenu from here?
  } while (numMenu != 0);
}

void push(int value) {

}

void pop() {

}

int main() {
  int numMenu;

  cout << "Bem vindo ao criador de lista simplesmente encadeada!\n";
  cout << "-----------------------------------------------------\n";
  menu();

  return 0;
}

