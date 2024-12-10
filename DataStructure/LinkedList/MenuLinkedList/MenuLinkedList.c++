#include <cstdlib>
#include <iostream>

using namespace std;

struct no {
  int num;
  struct no *prox;
};

typedef struct no *noPtr;

noPtr topo = nullptr;

int menu() {
  int numMenu;
  cout << "\n--- Comandos ---\n";
  cout << "[0] Para parar o programa.\n";
  cout << "[1] Inserir um no.\n";
  cout << "[2] Remover um no.\n";
  cout << "[3] Printar a lista encadeada.\n";
  cout << "Insira um comando: ";
  cin >> numMenu;
  if (numMenu == 0) {
    exit(0);
  }
  return numMenu;
}

void push(int value) {
  noPtr p;
  p = new no;
  p->num = value;
  p->prox = topo; // novo no tem o prox pro no anterior
  topo = p;       // topo agora aponta pro ultimo no adicionado
  cout << "\n~ Elemento adicionado na pilha.\n";
}

void pop() {
  if (topo == nullptr) {
    cout << "\n~ Lista vazia.\n";
    return;
  }
  noPtr aux = topo->prox;
  free(topo);
  topo = aux;
  cout << "\n~ O ultimo elemento da pilha foi removido.\n";
}

void printList() {
  if (topo == nullptr) {
    cout << "\n~ Lista Vazia.\n";
    return;
  }

  while (topo != nullptr) {
    cout << topo->num << " "; // printando o número de cada no
    topo = topo->prox;        // topo aponta para o proximo no
  }
}

int main() {
  int userChoice;
  cout << "Bem vindo ao criador de lista simplesmente encadeada!\n";
  cout << "-----------------------------------------------------\n";
  do {
    userChoice = menu();
    switch (userChoice) {
      case 1:
        int value;
        cout << "Insira o valor a ser adicionado dentro do no: ";
        cin >> value;
        push(value);
        break;
      case 2:
        pop();
        break;
      case 3:
        cout << "\n";
        printList();
        cout << "\n";
        break;
    }
  } while (userChoice != 0);

  return 0;
}
