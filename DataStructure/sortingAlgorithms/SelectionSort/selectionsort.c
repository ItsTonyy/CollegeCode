#include <stdio.h>

void selectionSort(int arr[], int qt) {
  for (int i = 0; i < qt - 1; i++) {
    int menor = i;

    for (int j = i + 1; j < qt; j++) {
      if (arr[j] < arr[menor]) {
        menor = j;
      }
    }

    int aux = arr[i];
    arr[i] = arr[menor];
    arr[menor] = aux;
  }
}

int main() {
  int v[] = {40, 70, 10, 50, 20, 30, 15};

  selectionSort(v, 7);

  for (int i = 0; i < 7; i++) {
    printf("%d, ", v[i]);
  }

  return 0;
}
