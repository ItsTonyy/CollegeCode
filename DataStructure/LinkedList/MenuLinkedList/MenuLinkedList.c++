#include <cstdlib>
#include <iostream>

using namespace std;

struct no {
  int num;
  struct no *prox;
};

typedef struct no *noPtr;

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

void push(noPtr *topo, int value) {
  noPtr p = new no;
  p->num = value;
  p->prox = *topo; // Novo nó aponta para o nó atual do topo
  *topo = p;       // Atualiza o topo para o novo nó
  cout << "\n~ Elemento adicionado na pilha.\n";
}

void pop(noPtr *topo) {
  if (*topo == nullptr) {
    cout << "\n~ Lista vazia.\n";
    return;
  }
  noPtr aux = *topo; // Nó a ser removido
  *topo = (*topo)->prox; // Atualiza o topo para o próximo nó
  delete aux; // Libera memória do nó removido
  cout << "\n~ O ultimo elemento da pilha foi removido.\n";
}

void printList(noPtr topo) {
  if (topo == nullptr) {
    cout << "\n~ Lista vazia.\n";
    return;
  }
  cout << "\n~ Lista: ";
  while (topo != nullptr) {
    cout << topo->num << " "; // Imprime o número de cada nó
    topo = topo->prox;        // Avança para o próximo nó
  }
  cout << "\n";
}

int main() {
  noPtr topo = nullptr;

  int userChoice;
  cout << "Bem-vindo ao criador de lista simplesmente encadeada!\n";
  cout << "-----------------------------------------------------\n";
  do {
    userChoice = menu();
    switch (userChoice) {
      case 1: {
        int value;
        cout << "Insira o valor a ser adicionado dentro do no: ";
        cin >> value;
        push(&topo, value);
        break;
      }
      case 2:
        pop(&topo);
        break;
      case 3:
        printList(topo);
        break;
      case 0:
        cout << "Encerrando o programa.\n";
        break;
      default:
        cout << "Comando invalido.\n";
    }
  } while (userChoice != 0);

  return 0;
}
