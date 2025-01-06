#include <cstdlib>
#include <iostream>

using namespace std;

struct alternativeNode {
  int cod;
  alternativeNode *pr;

  // constructor
  alternativeNode(int number): cod(number), pr(nullptr) {}
};

struct mainNode {
  int info;
  alternativeNode *p;
  mainNode *ant;
  mainNode *prox;
  
  // constructor
  mainNode(int number): info(number), p(nullptr), ant(nullptr), prox(nullptr) {}
};

void addClient(mainNode *&head) {
  int num;

  cout << "Insira o numero de identificacao (deve ser 100 maior que o cliente anterior): ";
  cin >> num;

  if(head == nullptr) {
    mainNode *newNode = new mainNode(num);
    head = newNode;
  } else {
    mainNode *newNode = new mainNode(num);
    mainNode *curr = head;

    while(curr->prox != nullptr) {
      curr = curr->prox;
    }

    if(num - curr->info != 100) {
      cout << endl << "O numero tem que ser 100 maior que o cliente anterior.\n";
      exit(0);
    }

    curr->prox = newNode;
    newNode->ant = curr;
    newNode->info = num;    
  }
}

void buyProduct(mainNode *&head, int clientCode, int productCode) {
  mainNode *curr = head;

  while (curr != nullptr){
    if(curr->info == clientCode) {
      alternativeNode *newSLINode = new alternativeNode(productCode);

      if (curr->p == nullptr) {
        curr->p = newSLINode;
        cout << "Pedido realizado com sucesso.\n";
        return;
      }
      
      while (curr->p->pr != nullptr) {
        curr->p = curr->p->pr;
      }

      curr->p->pr = newSLINode; 
      cout << endl << "Pedido realizado com sucesso.\n";
      return;    
    }

    curr = curr->prox;
  }

  cout << "Pedido nao encontrado." << endl;
}

void removeClient(mainNode *&head, int clientCode) {
  mainNode *curr = head;

  while (curr != nullptr){
    if(curr->info == clientCode) {
      while(curr->p != nullptr) {
        cout << "Codigo de compra: " << curr->p->cod << "\n";
        alternativeNode* temp = curr->p;
        curr->p = curr->p->pr;
        delete temp;
      }

      mainNode* temp2 = curr;
      
      // ele é o primeiro
      if(curr->ant == nullptr) {
        head = nullptr;
        delete curr;
        return;
      }

      // ele é o ultimo
      if(curr->prox == nullptr) {
        curr->ant->prox = nullptr;
        delete curr;
        return;
      }

      curr->prox->ant = curr->ant;
      curr->ant->prox = curr->prox;

      delete temp2;
    }

    curr = curr->prox;
  } 
  cout << "\nCliente numero " << clientCode << " liberado.\n";
}

void fowardTransversal(mainNode *&head) {
  mainNode *curr = head;
  cout << "\n";

  if(curr == nullptr) {
    cout << "Lista vazia." << endl;

    return;
  }

  while(curr != nullptr) {
    cout << "Cliente: " << curr->info << endl;

    curr = curr->prox;
  }
}

int menu() {
  int numMenu;

  cout << "\n--- Comandos ---\n";
  cout << "[0] Para parar o programa.\n";
  cout << "[1] Inserir um cliente.\n";
  cout << "[2] Adicionar uma compra.\n";
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
        addClient(head);
        break;
      case 2:
        cout << "insira o seu numero de cliente: ";
        cin >> clientCode;
        cout << "insira o numero do seu produto: ";
        cin >> productCode;

        buyProduct(head, clientCode, productCode);
        break;
      case 3:
        cout << "insira o seu numero de cliente: ";
        cin >> clientCode;

        removeClient(head, clientCode);
        break;
      case 4: 
        fowardTransversal(head);
      break;
    }
  } while (userChoice != 0);

  return 0;
}