#ifndef FUNCTIONS_H
#define FUNCTIONS_H
#include "structures.h"
//Constantes
#define TOP 'w'
#define DOWN 's'
#define LEFT 'a'
#define RIGHT 'd'
//Cria o Mapa
void liberaMemoria(MAPA* m);
void alocaMemoria(MAPA* m);
void leituraArquivo(MAPA* m);
void copiaArquivo(MAPA* origem, MAPA* destino);
void imprimeArquivo(MAPA* m);
//Jogabilidade
int verificaParede(MAPA* m, int x, int y);
int verificaPersonagem(MAPA* m, int x, int y);
int validaAndarFantasma(int x_atual, int y_atual, int* x_destino, int* y_destino);
int encontraAvatar(MAPA* m, POSICAO* p, char avatar);
void walkFantasma(MAPA* m, FANTASMA* p, int x, int y);
void walk(MAPA* m, POSICAO* p, int x, int y);
int podeMovimentarFantasma(MAPA* m, int x, int y);
int podeMovimentarAvatar(MAPA* m, int x, int y);
int limitesMapa(MAPA* m, int x, int y);
void movimentacao(char tecla);
void fantasma();
int acabou();

#endif // FUNCTIONS_H