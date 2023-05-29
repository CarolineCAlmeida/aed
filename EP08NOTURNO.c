//1200 - Operações em ABP I
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Arvore{
    int dado;
    struct Arvore*esq;
    struct Arvore*dir;
} Arvore;

Arvore*cria(int dado){
    Arvore*ArvNovo = (Arvore*)malloc(sizeof(Arvore));
    if(ArvNovo == NULL) {
        printf("Erro ao alocar memória para o nó.\n");
        exit(1);
    }
    ArvNovo->dado = dado;
    ArvNovo->esq = ArvNovo->dir = NULL;
    return ;
}

Arvore*insere(Arvore*raiz, int dado){
    if(raiz == NULL){
        return cria(dado);
    }
    if(dado < raiz->dado){
        raiz->esq = insere(raiz->esq, dado);
    } else if (dado> raiz->dado){
        raiz->dir = insere(raiz->dir, dado);
    }
    return raiz;
}

void INFIXA(Arvore*raiz){
    if(raiz != NULL){
        INFIXA(raiz->esq);
        printf("%d ", raiz->dado);
        INFIXA(raiz->dir);
    }
}

void PREFIXA(Arvore*raiz){
    if(raiz != NULL){
        printf("%d ", raiz->dado);
        PREFIXA(raiz->esq);
        PREFIXA(raiz->dir);
    }
}

void POSFIXA(Arvore*raiz){
    if(raiz!= NULL){
        POSFIXA(raiz->esq);
        POSFIXA(raiz->dir);
        printf("%d ", raiz->dado);
    }
}

int PESQUISA(Arvore*raiz, int dado){
    if(raiz == NULL){
        return 0;
    }
    if(dado == raiz->dado){
        return 1;
    } else if(dado < raiz->dado){
        return PESQUISA(raiz->esq, dado);
    } else{
        return PESQUISA(raiz->dir, dado);
    }
}

int main() {
    Arvore*raiz = NULL;
    char operacao[10];
    int elemento;

    while(scanf("%s", operacao) != EOF){
        
        if(strcmp(operacao, "I") == 0){
            scanf("%d", &elemento);
            raiz = insere(raiz, elemento);
        } 
        else if(strcmp(operacao, "INFIXA") == 0){
            INFIXA(raiz);
            printf("\n");
        } 
        else if(strcmp(operacao, "PREFIXA") == 0){
            PREFIXA(raiz);
            printf("\n");
        }
        else if(strcmp(operacao, "POSFIXA") == 0){
            POSFIXA(raiz);
            printf("\n");
        } 
        else if(strcmp(operacao, "P") == 0){
            scanf("%d", &elemento);
            if (PESQUISA(raiz, elemento)){
                printf("%d existe\n", elemento);
            } 
            else{
                printf("%d nao existe\n", elemento);
            }
        }
    }
    
    return 0;
}
