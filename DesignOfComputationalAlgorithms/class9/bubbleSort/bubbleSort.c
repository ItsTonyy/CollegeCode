#include <stdio.h>

void bubble(int v[], int qt) {
  int last = qt - 1;

  for (int last = qt - 1; last >= 0; last--) {
    int changed = 0 for (int i = 0; i < last; i++) {
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

int main() {
  int v[] = {40, 70, 10, 50, 20, 30, 15};
  bubble(v, 7);

  for (int i = 0; i < 7; i++) {
    printf("%d, ", v[i]);
  }

  printf("/n");

  return 0;
}