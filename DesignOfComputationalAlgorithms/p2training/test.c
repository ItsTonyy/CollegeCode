int buscaLinear(int arr[], int n, int chave) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == chave) {
            return i; // Retorna o índice da chave encontrada
        }
    }
    return -1; // Retorna -1 se a chave não for encontrada
}