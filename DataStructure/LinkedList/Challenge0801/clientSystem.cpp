#include <cstdlib>
#include <iostream>

using namespace std;

struct mainNode {
  int info;
  alternativeNode* p;
  mainNode* ant;
  mainNode* prox;
  
  // constructor
  mainNode(int number): info(number), p(nullptr,) prox(nullptr), ant(nullptr) {}
};

struct alternativeNode {
  int cod;
  alternativeNode* pr;

  // constructor
  alternativeNode(int number): cod(number), pr(nullptr) {}
};

int addClient(int num) {

}

int buyProduct(int clientCode, int productCode) {

}

int removeClient(int clientCode) {
  
}

void fowardTransversal(Node* head) {
  Node* current = head;

  while(current != nullptr) {
    cout << current->data << " ";

    current = current->next;
  }

  cout << endl;
}

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

int main() {
  
  return 0;
}