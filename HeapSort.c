#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void constroiHeap(int v[], int n, int i){
    int a = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < n && v[l] > v[a])
        a = l;

    if (r < n && v[r] > v[a])
        a = r;

    if(a != i){
        int temp = v[i];
        v[i] = v[a];
        v[a] = temp;
        constroiHeap(v, n, a);
    }
}

void heapSort(int v[], int n){
    for (int i = n / 2 - 1; i >= 0; i--)
        constroiHeap(v, n, i);

    for (int i = n - 1; i >= 0; i--){
        int temp = v[0];
        v[0] = v[i];
        v[i] = temp;

        constroiHeap(v, i, 0);
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
  heapSort(v, n);
  final = clock();
    
  tempo = ((double) (final - inicio)) / CLOCKS_PER_SEC;
  printf("%lf segundos\n", tempo);
    
  return 0;
}
