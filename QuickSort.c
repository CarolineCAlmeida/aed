#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void quickSort(int v[], int b, int a){
    if (b < a) {
        int p = v[a];
        int i = b - 1;

        for (int j = b; j <= a - 1; j++) {
            if (v[j] < p) {
                i++;
                int temp = v[i];
                v[i] = v[j];
                v[j] = temp;
            }
        }

        int temp = v[i + 1];
        v[i + 1] = v[a];
        v[a] = temp;

        int x = i + 1;

        quickSort(v, b, x - 1);
        quickSort(v, x + 1, a);
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
  quickSort(v, 0, n-1);
  final = clock();
    
  tempo = ((double) (final - inicio)) / CLOCKS_PER_SEC;
  printf("%lf segundos\n", tempo);
    
  return 0;
}

