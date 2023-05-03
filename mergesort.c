#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void intercala(int p, int q, int r, int v[]){
  int *w;
  w = malloc ((r-p) * sizeof (int));  
  int i = p, j = q;  
  int k = 0;  
  
  while (i < q && j < r){  
    if (v[i] <= v[j])  w[k++] = v[i++];  
    else  w[k++] = v[j++];  
    }  
    while (i < q)  w[k++] = v[i++];  
    while (j < r)  w[k++] = v[j++];  
    for (i = p; i < r; ++i)  v[i] = w[i-p];  
    free (w);  
}

void mergesort(int p, int r, int v[]){
  if (p < r-1){                
  int q = (p + r)/2;          
  mergesort (p, q, v);       
  mergesort (q, r, v);        
  intercala (p, q, r, v);     
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
  mergesort(v, 0, n - 1);
  final = clock();
    
  tempo = ((double) (final - inicio)) / CLOCKS_PER_SEC;
  printf("%lf segundos\n", tempo);
    
  return 0;
}
