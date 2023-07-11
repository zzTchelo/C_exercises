#ifndef MAPA_H
#define MAPA_H

typedef struct mapa 
{
    char** map;
    int linhas;
    int colunas;
} MAPA;

typedef struct posicao 
{
    int x;
    int y;
} POSICAO;

typedef struct posicaoFantasma 
{
    int x;
    int y;
} FANTASMA;

#endif // MAPA_H
