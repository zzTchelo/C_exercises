#include "structs.h"
#include <stdbool.h>

int geraMenu();

void addCliente(CLIENTE *cliente);
void mostrarSaldo(CLIENTE *cliente);
void chequeEspecial(CLIENTE *cliente);
void realizarSaque(CLIENTE *cliente);
void realizarDeposito(CLIENTE *cliente);
void realizarAplicacao(CLIENTE *cliente);
void adquirirCartaoCredito(CLIENTE *cliente);
void pagarCartaoCredito(CLIENTE *cliente);

int geraMenu();
bool verificaCliente(CLIENTE *cliente);
void zeraCliente(CLIENTE *cliente);