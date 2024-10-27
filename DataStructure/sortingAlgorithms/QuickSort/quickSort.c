#include "stdio.h"

int buscaSequencial(int vetor[], int tamanho, int valor) {
  int i;

  for (i = 0; i < tamanho; i++) {
    if (vetor[i] == valor) {
      printf("Valor encontrado na posição: %d", i);
      return i;
    }
  }
  printf("Valor não encontrado");
  return -1;
}

// -------------------------------------------------- //

void swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}

int partition(int arr[], int low, int high) {

    // Escolha do pivot: o ultimo elemento do array
    int pivot = arr[high];

    // index do menor elemento menos 1 é guardado dentro de I
    // inicialmente não faz sentido pois não aponta pra nada
    // mas depois vai apontar sempre pro elemento antes de J
    int i = low - 1;

    // Traverse arr[low..high] and move all smaller
    // elements to the left side. Elements from low to 
    // i are smaller after every iteration
    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }

    // Move pivot after smaller elements and
    // return its position
    swap(&arr[i + 1], &arr[high]);  
    return i + 1;
}


int buscaBinaria(int vetor[], int tamanho, int valor) {
  
}

int main(void) {
  int arr[] = {10, 2, 8, 7, 15, 20, 3, 35, 40};
  int valor = 15;

  buscaSequencial(arr, 9, valor);

  return 0;
}

// https://www.geeksforgeeks.org/quick-sort-algorithm/