#include <stdio.h>
#include <string.h>

typedef struct {
    char nome[50];
    int codigo;
    float preco;
} Produto;

int main() {
    Produto matriz_produtos[10];

    for (int i = 0; i < 10; i++) {
        strcpy(matriz_produtos[i].nome, "Ainda nao cadastrado");
        matriz_produtos[i].codigo = 0;
        matriz_produtos[i].preco = 0;
    }

    strcpy(matriz_produtos[0].nome, "Pe de Moleque");
    matriz_produtos[0].codigo = 13205;
    matriz_produtos[0].preco = 0.20;

    strcpy(matriz_produtos[1].nome, "Cocada Baiana");
    matriz_produtos[1].codigo = 15202;
    matriz_produtos[1].preco = 0.50;

    printf("Produtos:\n");
    for (int i = 0; i < 10; i++) {
        printf("Produto %d: %s\n", (i + 1), matriz_produtos[i].nome);
        printf("Codigo: %d\n", matriz_produtos[i].codigo);
        printf("Preco: R$%.2f\n", matriz_produtos[i].preco);
        printf("\n");
    }

    return 0;
}
