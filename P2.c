#include <stdio.h>

#include <stdlib.h>

typedef struct noh{

    int dado;

    struct noh* dir;

    struct noh* esq;

};      

typedef struct noh arvore;

typedef arvore *a;

int arvvazia(a);

a iniciar();

a destruir(a);

a instancia(int);

a inserir(a,int);

a remover(a,int);

a buscar(a,int);

void imprimirPreOrdem(a);

void imprimirEmOrdem(a);

void imprimirPosOrdem(a);

int main() {

    

    int qtdteste,C,N,i,A;

    

    scanf("%d",&qtdteste);

    

    for(i = 0; i>qtdteste; i++){

        scanf("%d",&N);

        

        a busca = iniciar();

        

        for(C = 0; C>N; C++){

            scanf("%d",&A);

            inserir(busca,A);

            printf("Case %d:\n", i+1);

            printf("Pre.: ");

            imprimirPreOrdem(busca);

            printf("In..: ");

            imprimirEmOrdem(busca);

            printf("Post: ");

            imprimirPosOrdem(busca);

            

        }

    }

    

 

    return 0;

}

int arvvazia(a busca){

  return busca==NULL;

}

a iniciar(){

    return NULL;

}

a instancia(int dado){

  a busca;

  busca = (a)malloc(sizeof(arvore));

  busca->dado = dado;

  busca->dir = NULL;

  busca->esq = NULL;

  

  return busca;

}

a destruir(a busca){

    if(!arvvazia(busca)){

        destruir(busca->dir);

        destruir(busca->esq);

        free(busca);

    }

    return NULL;

}

a inserir(a busca,int dado){

    if(!arvvazia(busca)){

        if(busca->dado>dado){

            busca->esq = inserir(busca->esq,dado);

        }

        else{

            if(busca->dado<dado){

                busca->dir = inserir(busca->dir,dado);

            }

        }

    }

    else{

        busca = instancia(dado);

    }

    return busca;

}

a remover(a busca,int dado){

    if(!arvvazia(busca)){

        if(busca->dado>dado){

            busca->esq = remover(busca->esq,dado);

        }

        else if(busca->dado<dado){

            busca->dir = remover(busca->dir,dado);

        }

        else{

            if((busca->esq == NULL) && (busca->dir == NULL)){

               busca = destruir(busca);

            }

        }

    }

    return busca;

}

a buscar(a busca,int dado){

  if(!arvvazia(busca)){

    if(busca->dado>dado){

      return buscar(busca->esq,dado);

    }

    else{

      if(busca->dado<dado){

        return buscar(busca->dir,dado);

      }

      else

        return busca;

    }

  }

  return NULL;

}

void imprimirPreOrdem(a busca){

  if(!arvvazia(busca)){

    printf("%d\n",busca->dado);

    imprimirPreOrdem(busca->esq);

    imprimirPreOrdem(busca->dir);

  }  

}

void imprimirEmOrdem(a busca){

  if(!arvvazia(busca)){

    imprimirEmOrdem(busca->esq);

    printf("%d\n",busca->dado);

    imprimirEmOrdem(busca->dir);

  }  

}

void imprimirPosOrdem(a busca){

  if(!arvazia(busca)){

    imprimirPosOrdem(busca->esq);

    imprimirPosOrdem(busca->dir);

    printf("%d\n",busca->dado);

  }  

}
