// first way
#include <stdio.h>

void bubble(int v[], int qt) {
  int last = qt - 1;

  for (last; last >= 0; last--) {
    int changed = 0;
    for (int i = 0; i < last; i++) {
      if (v[i] > v[i + 1]) {
        changed = 1;
        int aux = v[i];
        v[i] = v[i + 1];
        v[i + 1] = aux;
      }
    }
    if (!changed) {
      return;
    }
  }
}

// second way

void betterBubble(int arr[], int qt) {
  for(int i = 0; i < qt - 1; i++) {
    for(int j = i + 1; j < qt; j++) {
      if(arr[i] < arr[j]) {
        int aux = arr[i];
        arr[i] = arr[j];
        arr[j] = aux;
      }
    }
  }
}

int main() {
  int v[] = {40, 70, 10, 50, 20, 30, 15};
  betterBubble(v, 7);

  for (int i = 0; i < 7; i++) {
    printf("%d, ", v[i]);
  }

  return 0;
}