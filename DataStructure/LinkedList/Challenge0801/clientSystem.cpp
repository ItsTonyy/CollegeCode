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

int addClient(mainNode *head, int num) {
  mainNode *newNode = new mainNode(num);

  if(head == nullptr) {
    head = newnode;
  } else {
    mainNode *curr = head;

    while (curr->prox != nullptr) {
      curr = curr->prox;
    }

    if(num - curr->info != 100) {
      cout << "O valor tem que ser de 100 em 100. O número do cliente anterior é de: " << curr->info << endl;
      exit;
    }

    curr->next = newNode;
    newNode->ant = curr;
  }

  return head;
}

int buyProduct(mainNode *head, int clientCode, int productCode) {
  mainNode *curr = head;

  while (curr != nullptr){
    if(curr->info == clientCode) {
      curr->p = new alternativeNode(productCode);
      cout >> "Pedido realizado com sucesso.";
      return;
    }

    curr = curr->prox;
  }

  cout >> "Pedido não encontrado.";
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