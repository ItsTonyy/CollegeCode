#include <cstdlib>
#include <iostream>

using namespace std;

struct mainNode {
  int info;
  mainNode *ant;
  mainNode *prox;
  
  // constructor
  mainNode(string text): info(text), ant(nullptr), prox(nullptr) {}
};

void addText(mainNode *&head) {
  string text;

  cout << "Insira o texto a ser adicionado: ";
  cin >> text;

  if(head == nullptr) {
    mainNode *newNode = new mainNode(text);
    head = newNode;
  } else {
    mainNode *newNode = new mainNode(text);
    mainNode *curr = head;

    while(curr->prox != nullptr) {
      curr = curr->prox;
    }

    curr->prox = newNode;
    newNode->ant = curr;
    newNode->info = text;    
  }
}

void removeText(mainNode *&head, int line) {
  mainNode *curr = head;

  for(int i = 1, i < line, i++) {
    curr = curr->prox;
  }

  // ele é o primeiro
  if(curr->ant == nullptr) {
    head = nullptr;
    delete curr;
    cout << "\n Linha número " << line << " removida.\n";
    return;
  }

  // ele é o ultimo
  if(curr->prox == nullptr) {
    curr->ant->prox = nullptr;
    delete curr;
    cout << "\n Linha número " << line << " removida.\n";
    return;
  }

  curr->prox->ant = curr->ant;
  curr->ant->prox = curr->prox;
  cout << "\n Linha número " << line << " removida.\n";

  delete temp2;
}

void fowardTransversal(mainNode *&head) {
  mainNode *curr = head;
  cout << "\n";

  if(curr == nullptr) {
    cout << "Lista vazia." << endl;

    return;
  }

  while(curr != nullptr) {
    cout << "'" << curr->info << "'" << endl;

    curr = curr->prox;
  }
}

void MoveLine(int l1, intl2) {
  
}


int menu() {
  int numMenu;

  cout << "\n--- Comandos ---\n";
  cout << "[0] Para parar o programa.\n";
  cout << "[1] Inserir uma nova linha de texto.\n";
  cout << "[2] Remover uma linha.\n";
  cout << "[3] Mostrar todo o texto de trás pra frente.\n";
  cout << "[4] Mover uma linha.\n\n";
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
        
        break;
      case 2:
       
        break;
      case 3:

        break;
      case 4: 
        
      break;
    }
  } while (userChoice != 0);

  return 0;
}