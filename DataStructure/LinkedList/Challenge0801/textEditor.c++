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
  cin >> text;

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
  cout << "\n Linha número " << line << " removida.\n";
}

void fowardTransversal(mainNode *&head) {
  mainNode *curr = head;
  cout << "\n";

  if (curr == nullptr) {
    cout << "Lista vazia." << endl;

    return;
  }

  while (curr != nullptr) {
    cout << "'" << curr->info << "'" << endl;

    curr = curr->prox;
  }
}

void MoveLine(mainNode *&head, int l1, int l2) {
  int numberOfLines = 0;
  mainNode *temp = head;
  mainNode *L1 = head;
  mainNode *L2 = head;

  for (int i = 1; i != l1; i++) {
    L1 = L1->prox;
  }

  for (int i = 1; i != l2; i++) {
    L2 = L2->prox;
  }

  while (temp != nullptr) {
    numberOfLines++;
    temp = temp->prox;
  }

  cout << "Numero de linhas: " << numberOfLines;

  if (l1 > numberOfLines) {
    cout << "Numero de linha excedidas.";
    exit(0);
  }

  if (l2 > numberOfLines) {
    mainNode *lastText = head;
    while (lastText->prox != nullptr) {
      lastText = lastText->prox;
    }
    lastText->prox = L2;
    L2->ant = lastText;
    return;
  }

  // l1 está logo após l2
  if (L2->prox == L1) {
    L2->prox = L1->prox;
    L1->prox = L2;
    L1->ant = L2->ant;
    L2->ant = L1;

    return;
  }

  // l1 está antes de l2
  if (L2->ant == L1) {
    L1->prox = L2->prox;
    L2->ant = L1->ant;
    L1->ant = L2;
    L2->prox = L1;

    return;
  }

  mainNodePtr L1Prox = L1->prox;
  mainNodePtr L1Ant = L1->ant;

  L1->ant = L2->ant;
  L1->prox = L2->prox;
  L2->prox = L1Prox;
  L2->ant = L1Ant;
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
    int clientCode, productCode;
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
      fowardTransversal(head);
      break;
    case 4:
      int l1, l2;
      cout << "\nQual linha deseja mover: ";
      cin >> l1;
      cout << "\nPara qual linha deseja botar a linha escolhida no passo "
              "anterior: ";
      cin >> l2;

      MoveLine(head, l1, l2);
      break;
    }
  } while (userChoice != 0);

  return 0;
}