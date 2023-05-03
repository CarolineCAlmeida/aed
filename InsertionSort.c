#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void insertionSort(int v[], int n){
  int i, j, chave;
  for (i = 1; i < n; i++) {
    chave = v[i];
    j = i - 1;
    while (j >= 0 && v[j] > chave){
      v[j + 1] = v[j];
      j = j - 1;
    }
    v[j + 1] = chave;
    }
}

int main() {
  int i, n;
  double tempo;
  clock_t inicio, final;
  scanf("%d", &n);
    
  int v[n];
  srand(time(NULL));
    
  for (i = 0; i < n; i++) {
    v[i] = rand() % 100;
  }
  inicio  = clock();
  insertionSort(v, n);
  final = clock();
    
  tempo = ((double) (final - inicio)) / CLOCKS_PER_SEC;
  printf("%lf segundos\n", tempo);
    
  return 0;
}
