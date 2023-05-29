//2651 - Link Bolado
#include <stdio.h>
#include <strings.h>

int main(){
  int contador = 0, i = 0; 
  char nome[100001];
  fgets(nome, 100001, stdin);

  while(nome[i] != '\0'){
    if(nome[i+0] == 'z' || nome[i+0] == 'Z'){
      if(nome[i+1] == 'e' || nome[i+1] == 'E'){
        if(nome[i+2] == 'l' || nome[i+2] == 'L'){
          if(nome[i+3] == 'd' || nome[i+3] == 'D'){
            if(nome[i+4] == 'a' || nome[i+4] == 'A'){
              contador = 1;
              break;
            }
          }
        }
      }
    }
              
    i++;
  }

  if(contador == 1){
    printf("Link Bolado\n");
  }
  else {
    printf("Link Tranquilo\n");
  }

  return 0;
  
}
