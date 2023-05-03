#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void selectionSort(int v[], int n){
  int i, j, t, a;

  for (i = 0; i < n-1; i++){
    a = i;
    for (j = i+1; j < n; j++){
      if (v[j] < v[a])
        a = j;
      }
      t = v[a];
      v[a] = v[i];
      v[i] = t;
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
  selectionSort(v, n);
  final = clock();
    
  tempo = ((double) (final - inicio)) / CLOCKS_PER_SEC;
  printf("%lf segundos\n", tempo);
    
  return 0;
}
