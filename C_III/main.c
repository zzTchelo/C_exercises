#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "functions.h"
#include "structures.h"
#include "mapa.c"

MAPA m; 
POSICAO p;
FANTASMA f;

int acabou(){ //Indica o fim do jogo
    POSICAO pos;
    //return encontraAvatar(&m, &pos, AVATAR);
    int perdeu = !encontraAvatar(&m, &pos, AVATAR);
    int ganhou = !encontraAvatar(&m, &pos, FANTASMAS);

    return ganhou || perdeu;
}

int validaAndarFantasma(int x_atual, int y_atual, int* x_destino, int* y_destino){
    int opcoes[4][2] = {
        {x_atual, y_atual + 1}, //Direita
        {x_atual + 1, y_atual}, //Baixo
        {x_atual, y_atual - 1}, //Esquerda
        {x_atual - 1, y_atual}  //Cima 
    };

    srand(time(0));
    //int achou = 0;
    //while (!achou){
    for (int i = 0; i < 10; i++){
        int posicao = rand() % 4;
        if(podeMovimentarFantasma(&m, opcoes[posicao][0], opcoes[posicao][1])){
            *x_destino = opcoes[posicao][0];
            *y_destino = opcoes[posicao][1];
            //achou = 1;
            return 1;
        }
    }
    return 0;
}

void fantasma(){
    MAPA cp;
    copiaArquivo(&cp, &m);
    for (int i = 0; i < m.linhas; i++){
        for (int j = 0; j < m.colunas; j++){
            if(m.map[i][j] == FANTASMAS){
                if(podeMovimentarFantasma(&m, i, j + 1) && limitesMapa(&m, i, j+1)){
                    f.x = i;
                    f.y = j;

                    int x, y;
                    if(validaAndarFantasma(i, j, &x, &y)) {
                        // walkFantasma(&m, &f, i, j + 1);
                        walkFantasma(&m, &f, x, y);
                    break;

                    }
                }
            }
        }
    }
    liberaMemoria(&cp);    
}

void movimentacao(char tecla){ //Movimenta o avatar
    int next_x = p.x;
    int next_y = p.y;

    switch (tecla) //Move o avatar -> @
    {
    case LEFT: //Move Esquerda
        next_y--;
        break;
    case TOP: //Move Cima
        next_x--;
        break;
    case DOWN: //Move Baixo
        next_x++;
        break;
    case RIGHT: //Move Direita
        next_y++;
        break;
    default:
        return;
    }

    if(!limitesMapa(&m, next_x, next_y))
        return;
    if(!podeMovimentarAvatar(&m, next_x, next_y))
        return;

    walk(&m, &p, next_x, next_y);
}

int main(){ //Main

    leituraArquivo(&m);
    encontraAvatar(&m, &p, AVATAR);

    do{ 
        imprimeArquivo(&m); 
        char tecla;
        scanf(" %c", &tecla);
        movimentacao(tecla);
        fantasma();
    } while (!acabou());
    
    liberaMemoria(&m);
}