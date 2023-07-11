#include <stdio.h>
#include <stdlib.h>
#include "functions.h"
#include "structures.h"

#define AVATAR '@'
#define FANTASMAS 'F'
#define VAZIO '.'
#define P_VERTICAL '|'
#define P_HORIZONTAL '-'

int verificaParede(MAPA* m, int x, int y){
    return m->map[x][y] == P_VERTICAL || m->map[x][y] == P_HORIZONTAL;
}

int verificaPersonagem(MAPA* m, int x, int y){
    return !m->map[x][y] == FANTASMAS;
}

void walkFantasma(MAPA* m, FANTASMA* f, int x, int y){ // Movimenta o Fantasma no Mapa
    m->map[x][y] = FANTASMAS;
    m->map[f->x][f->y] = VAZIO;

    f->x = x;
    f->y = y;
}

void walk(MAPA* m, POSICAO* p, int x, int y){ // Movimenta o Avatar no Mapa
    m->map[x][y] = AVATAR;
    m->map[p->x][p->y] = VAZIO;

    p->x = x;
    p->y = y;
}

int podeMovimentarAvatar(MAPA* m, int x, int y){ //Valida o espaço para movimentar o Avatar
    return m->map[x][y] == VAZIO;
}

int podeMovimentarFantasma(MAPA* m, int x, int y){ //Valida o espaço para movimentar o Fantasma
    return !verificaParede(m, x, y) && !verificaPersonagem(m, x, y);
}

int limitesMapa(MAPA* m, int x, int y){ //Define Limites do Mapa
    if(x >= m->linhas)
        return 0;
    if(y >= m->colunas)
        return 0;

    return 1;
}

int encontraAvatar(MAPA* m, POSICAO* p, char avatar){ //Acha a posição do avatar -> @
    for(int i = 0; i < m->linhas; i++){
        for(int j = 0; j < m->colunas; j++){
            if(m->map[i][j] == avatar){
                p->x = i;
                p->y = j;
                return 1;
            }
        }
    }
    return 0;
}

void liberaMemoria(MAPA* m){ //Liberação de memória
    for(int i = 0; i < m->linhas; i++){
        free(m->map[i]);
    }
    free(m->map);
}

void alocaMemoria(MAPA* m){ //Alocação de Memória
    m->map = malloc(sizeof(char*) * m->linhas);
    for(int i = 0; i < m->linhas; i++){
        m->map[i] = malloc(sizeof(char*) * (m->colunas + 1));
    }
}

void copiaArquivo(MAPA* destino, MAPA* origem){
    destino->linhas = origem->linhas;
    destino->colunas = origem-> colunas;

    alocaMemoria(destino);

    for (int i = 0; i < origem->linhas; i++){
        strcpy(destino->map[i], origem->map[i]);
    }
}

void leituraArquivo(MAPA* m){ //Leitura do arquivo TXT
    FILE* f;
    f = fopen("map.txt", "r");
    if (f == 0){
        printf("Nao foi possivel carregar o mapa!!!\n\n");
        exit(1);
    }
    
    fscanf(f, "%d %d", &m->linhas, &m->colunas);
    printf("m->linhas: %d \nm->colunas: %d\n\n", m->linhas, m->colunas);
    
    alocaMemoria(m);
    
    for (int i = 0; i < m->linhas; i++){
        fscanf(f, "%s", m->map[i]);
    }

    fclose(f);
}

void imprimeArquivo(MAPA* m){ //Imprime Arquivo
    for (int i = 0; i < m->linhas; i++){
        printf("%s\n", m->map[i]);
    }
}