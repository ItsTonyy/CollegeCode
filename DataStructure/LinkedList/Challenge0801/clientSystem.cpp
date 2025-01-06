#include <cstdlib>
#include <iostream>

using namespace std;

struct mainNode {
  int info;
  alternativeNode* p;
  mainNode* ant;
  mainNode* prox;
  
  // constructor
  mainNode(int number): info(number), p(nullptr), ant(nullptr), prox(nullptr) {}
};

struct alternativeNode {
  int cod;
  alternativeNode* pr;

  // constructor
  alternativeNode(int number): cod(number), pr(nullptr) {}
};

void addClient(mainNode *head, int num) {
  mainNode *newNode = new mainNode(num);

  if(head == nullptr) {
    *head = newnode;
  } else {
    mainNode *curr = *head;

    while (curr->prox != nullptr) {
      curr = curr->prox;
    }
  
    curr->info = num;
    curr->prox = newNode;
    newNode->ant = curr;
  }
}

void buyProduct(mainNode *head, int clientCode, int productCode) {
  mainNode *curr = head;

  while (curr != nullptr){
    if(curr->info == clientCode) {
      alternativeNode *newSLINode = new alternativeNode(productCode);
      alternativeNode* sli = curr->p;

      if (sli == nullptr) {
        sli = new alternativeNode(productCode);
        cout << "Pedido realizado com sucesso.";
        return;
      }
      
      while (sli->pr != nullptr) {
        sli = sli->pr;
      }

      sli->pr = newSLINode; 
      return;    
    }

    curr = curr->prox;
  }

  cout << "Pedido nao encontrado." >> endl;
}

void removeClient(mainNode *head, int clientCode) {
  mainNode* curr = head;

  while (curr != nullptr){
    if(curr->info == clientCode) {
      while(curr->p != nullptr) {
        cout << "Codigo: " << curr->p->cod;
        alternativeNode* temp = curr->p;
        curr->p = curr->p->pr;
        delete temp;
      }
    }

    curr = curr->prox;
  }

  cout << "Cliente numero " << clientCode << " liberado.";
}

void fowardTransversal(mainNode* head) {
  mainNode *curr = head;

  while(curr != nullptr) {
    cout << curr->info << endl;

    curr = curr->prox;
  }

  cout << endl;
}

int menu() {
  int numMenu;

  cout << "\n--- Comandos ---\n";
  cout << "[0] Para parar o programa.\n";
  cout << "[1] Inserir um cliente.\n";
  cout << "[2] Remover uma compra .\n";
  cout << "[3] remover um cliente.\n";
  cout << "[4] printar a lista dos clientes.\n";
  cout << "Insira um comando: ";
  cin >> numMenu;

  return numMenu;
}

int main() {
  mainNode *head = nullptr;

  int userChoice;
  cout << "Bem vindo ao sistema de manuntencao de clientes!\n";
  cout << "-----------------------------------------------------\n";
  do {
    int clientCode, productCode;
    userChoice = menu();

    switch (userChoice) {
      case 1:
        int num;

        do {
          cout << "Insira o numero de identificacao (deve ser 100 maior que o cliente anterior): ";
          cin >> num;
        } while (num - curr->info != 100);

        addClient(&head, num);
        break;
      case 2:
        cout << "insira o seu numero de cliente: ";
        cin >> clientCode;
        cout << "insira o numero do seu produto: ";
        cin >> productCode;

        buyProduct(&head, clientCode, productCode);
        break;
      case 3:
        cout << "insira o seu numero de cliente: ";
        cin >> clientCode;

        removeClient(&head, clientCode);
        break;
      case 4: 
        fowardTransversal(&head);
      break;
    }
  } while (userChoice != 0);

  return 0;
}