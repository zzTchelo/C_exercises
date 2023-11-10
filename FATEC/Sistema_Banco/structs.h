#include <stdbool.h>

#ifndef STRUCTS_H
#define STRUCTS_H

#define MAX_LENGHT_NOME 51
#define CHEQUE_ESPECIAL 500.00
#define RENDIMENTO 0.05

typedef struct {
    char nome[MAX_LENGHT_NOME];
    int conta_corrente;
    float chequeEspecial;
    float saldo;
    float debitoPendente;
    bool possuiCartao;
} CLIENTE;


#endif
