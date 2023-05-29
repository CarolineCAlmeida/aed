//1855 - Mapa do Meistre
#include <stdio.h>
#include <stdlib.h>

#define ALTMAX 100
#define LARGMAX 100

int verificarMapa(char mapa[ALTMAX][LARGMAX], int largura, int altura){
    int i, j;
    int posX = 0;
    int posY = 0; 
    
    if(mapa[posY][posX] != '*'){
        return 0; // Mapa ERRO
    }
   
    while(1){
        char simbolo = mapa[posY][posX];

        if(simbolo == '>'){ //Uma flecha para a direita: >
            posX++;
        } 
        else if(simbolo == '<'){ //Uma flecha para a esquerda: <
            posX--;
        }
        else if (simbolo == 'v'){ //Uma flecha para baixo: v
            posY++;
        } 
        else if (simbolo == '^'){ //Uma flecha para cima: ^
            posY--;
        } 
        else{
            break; // Mapa ERRO
        }
        if(posX < 0 || posX >= largura || posY < 0 || posY >= altura){
            return 0; // Mapa ERRO
        }
        if (mapa[posY][posX] == '*'){ //Um baú: *
            return 1; // Mapa OK
        }
    }
    return 0; // Mapa ERRO
}

int main() {

    char mapa[ALTMAX][LARGMAX];
    int largura, altura;
    
    scanf("%d", &largura);
    scanf("%d", &altura);
    
    for(int i = 0; i < altura; i++){
        scanf(" %s", mapa[i]);
    }

    if(verificarMapa(mapa, largura, altura)){
        printf("*\n");
    } 
    else{
        printf("!\n"); //'!' mapa ERRO '*' mapa OK
    }

    return 0;
}
