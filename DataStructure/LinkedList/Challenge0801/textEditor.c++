#include <cstdlib>
#include <iostream>

using namespace std;

struct mainNode {
  string info;
  mainNode *ant;
  mainNode *prox;

  // constructor
  mainNode(string text) : info(text), ant(nullptr), prox(nullptr) {}
};

typedef struct mainNode *mainNodePtr;

void addText(mainNode *&head) {
  string text;

  cout << "Insira o texto a ser adicionado: ";
  cin.ignore();
  getline(cin, text);

  if (head == nullptr) {
    mainNode *newNode = new mainNode(text);
    head = newNode;

    cout << "\n Texto adicionado com sucesso.\n";
  } else {
    mainNode *newNode = new mainNode(text);
    mainNode *curr = head;

    while (curr->prox != nullptr) {
      curr = curr->prox;
    }

    curr->prox = newNode;
    newNode->ant = curr;
    newNode->info = text;

    cout << "\n Texto adicionado com sucesso.\n";
  }
}

void removeText(mainNode *&head, int line) {
  mainNode *curr = head;

  if (curr == nullptr) {
    cout << "Nenhum texto adicionado.\n";
    return;
  }

  for (int i = 1; i < line; i++) {
    curr = curr->prox;
  }

  // ele é o primeiro
  if (curr->ant == nullptr) {
    head = curr->prox;
    if (head != nullptr) {
      head->ant = nullptr;
    }
    delete curr;
    cout << "\n Linha número " << line << " removida.\n";
    return;
  }

  // ele é o ultimo
  if (curr->prox == nullptr) {
    curr->ant->prox = nullptr;
    delete curr;
    cout << "\n Linha número " << line << " removida.\n";
    return;
  }

  curr->prox->ant = curr->ant;
  curr->ant->prox = curr->prox;
  cout << "\n Linha numero " << line << " removida.\n";
}

void backwardTransversal(mainNode *&head) {
  mainNode *curr = head;

  if (curr == nullptr) {
    cout << "\nLista vazia." << endl;

    return;
  }

  while(curr->prox != nullptr) {
    curr = curr->prox;
  }

  while (curr != nullptr) {
    cout << "'" << curr->info << "'" << endl;

    curr = curr->ant;
  }
}

void MoveLine(mainNode *&head, int l1, int l2) {
    if (head == nullptr) {
      cout << "Lista vazia.\n";
      return;
    }

    int numberOfLines = 0;
    mainNode *temp = head;
    mainNode *L1 = nullptr;
    mainNode *L2 = nullptr;

    for (int i = 1; temp != nullptr; i++) {
      if (i == l1) L1 = temp;
      if (i == l2) L2 = temp;
      numberOfLines++;
      temp = temp->prox;
    }

    if (l2 > numberOfLines || L2 == nullptr) {
      cout << "L2 ultrapassa o número de linhas. L1 movido para o final.\n";


      if (L1->ant != nullptr) L1->ant->prox = L1->prox;
      if (L1->prox != nullptr) L1->prox->ant = L1->ant;


      if (L1 == head) head = L1->prox;


      temp = head;
      while (temp->prox != nullptr) {
          temp = temp->prox;
      }
      temp->prox = L1;
      L1->ant = temp;
      L1->prox = nullptr;

      return;
    }

    if (L1 == nullptr || l1 > numberOfLines) {
      cout << "Numero de linha L1 excedido.\n";
      return;
    }

    if (L1 == L2) {
        cout << "L1 e L2 sao iguais. sem movimentações.\n";
        return;
    }

    if (L1->ant != nullptr) L1->ant->prox = L1->prox;
    if (L1->prox != nullptr) L1->prox->ant = L1->ant;

    
    if (L1 == head) head = L1->prox;

    if (L2 == head) {
      head = L1; 
    }

    if (L2->ant != nullptr) L2->ant->prox = L1;
    L1->ant = L2->ant;
    L1->prox = L2;
    L2->ant = L1;

    cout << "Linha movida com sucesso.\n";
}


int menu() {
  int numMenu;

  cout << "\n--- Comandos ---\n";
  cout << "[0] Para parar o programa.\n";
  cout << "[1] Inserir uma nova linha de texto.\n";
  cout << "[2] Remover uma linha.\n";
  cout << "[3] Mostrar todo o texto de tras pra frente.\n";
  cout << "[4] Mover uma linha.\n\n";
  cout << "Insira um comando: ";
  cin >> numMenu;

  return numMenu;
}

int main() {
  mainNode *head = nullptr;

  int userChoice;
  cout << "Bem vindo ao sistema de manuntencao de textos!\n";
  cout << "-----------------------------------------------------\n";
  do {
    userChoice = menu();

    switch (userChoice) {
    case 1:
      addText(head);
      break;
    case 2:
      int line;

      cout << "Insira a linha que deseja remover: ";
      cin >> line;
      cout << "\n";

      removeText(head, line);
      break;
    case 3:
      backwardTransversal(head);
      break;
    case 4:
      int l1, l2;
      cout << "\nQual linha deseja mover: ";
      cin >> l1;
      cout << "\nPara qual linha deseja botar a linha escolhida no passo anterior: ";
      cin >> l2;

      MoveLine(head, l1, l2);
      break;
    }
  } while (userChoice != 0);

  return 0;
}