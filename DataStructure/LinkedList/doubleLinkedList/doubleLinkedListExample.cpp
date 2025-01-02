#include <iostream>

using namespace std;

struct Node {
  int data;
  Node* next;
  Node* prev;

  // constructor to initialize the node with data
  Node(int data): data(data), next(nullptr), prev(nullptr) {}
};

void fowardTransversal(Node* head) {
  Node* current = head;

  while(current != nullptr) {
    cout << current->data << " ";

    current = current->next;
  }

  cout << endl;
}

void backwardTransversal(Node* tail) {
  Node* current = tail;

  while(current->next != nullptr) {
    cout << current->data << " ";

    current = current -> prev;
  }

  cout << endl;
}

int main() {
  Node* head = new Node(1);
  Node* second = new Node(2);
  Node* third = new Node(3);

  head->next = second;
  second->prev = head;
  second->next = third;
  third->prev = second;

  cout << "Foward Transversal: ";
  fowardTransversal(head);

  cout << "Backward Transversal: ";
  backwardTransversal(third);

  return 0;
}