#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "structs.h"
#include "functions.h"
#include <stdbool.h>
#include <windows.h>

// [1]
void addCliente(CLIENTE *cliente) {
    fflush(stdin);
    printf("CADASTRO DE UM NOVO CLIENTE \n");
    printf("Nome: ");
    fgets(cliente->nome, MAX_LENGHT_NOME, stdin);
    int length = strlen(cliente->nome);
    if (length > 0 && cliente->nome[length - 1] == '\n') {
        cliente->nome[length - 1] = '\0';
    }

    printf("Conta Corrente: ");
    scanf("%d", &cliente->conta_corrente);
    printf("Saldo: ");
    scanf("%f", &cliente->saldo);
    printf("\nCLIENTE CADASTRADO COM SUCESSO!\n");
    Sleep(2000);
}
// [2]
void mostrarSaldo(CLIENTE *cliente) {
    if (verificaCliente(cliente)) {
        //printf("Saldo do Cliente: %.2f\n", cliente->saldo);
        printf("Saldo do Cliente: %.2f\n", (cliente->saldo - cliente->debitoPendente));
        printf("Cheque Especial: %.2f\n", cliente->chequeEspecial);
        //printf("Debitos pendentes: %.2f\n", cliente->debitoPendente);
        printf("Saldo para saque: %.2f", (cliente->saldo + cliente->chequeEspecial - cliente->debitoPendente));
        Sleep(2000);
    }
}
// [3]
void chequeEspecial(CLIENTE *cliente) {
    if (verificaCliente(cliente)) {
        int SN;
        printf("Deseja adicionar o valor de %.2f ao cheque especial do cliente %s? (Sim: 1/ Nao: 0)", CHEQUE_ESPECIAL, cliente->nome);
        scanf("%d", &SN);
        if (SN == 1) {
            cliente->chequeEspecial += CHEQUE_ESPECIAL;
            printf("Valor atual do Cheque Especial: %.2f\n", cliente->chequeEspecial);
            Sleep(2000);
        }
    }
}
// [4]
void realizarSaque(CLIENTE *cliente) {
    if (verificaCliente(cliente)) {
        float valor;
        printf("Digite o valor do saque: ");
        scanf("%f", &valor);

        if (valor > 0 && valor <= cliente->saldo + cliente->chequeEspecial) {
            cliente->saldo -= valor;
            printf("Saque de %.2f realizado com sucesso. Novo saldo: %.2f\n", valor, cliente->saldo);
            Sleep(2000);
        } else {
            printf("Saldo insuficiente.\n");
            Sleep(2000);
        }
    }
}
// [5]
void realizarDeposito(CLIENTE *cliente) {
    if (verificaCliente(cliente)) {
        float valor;
        printf("Digite o valor do deposito: ");
        scanf("%f", &valor);
        cliente->saldo += valor;
        printf("Deposito de %.2f realizado com sucesso. Novo saldo: %.2f\n", valor, cliente->saldo);
        Sleep(2000);
    }
}
// [6]
void realizarAplicacao(CLIENTE *cliente) {
    if (verificaCliente(cliente)) {
    float valor;
    printf("Digite o valor da aplicacao: ");
    scanf("%f", &valor);

        if (valor > 0 && valor <= cliente->saldo) {
            cliente->saldo -= valor;
            float rendimento = valor * RENDIMENTO;
            cliente->saldo += rendimento;
            printf("Aplicacao de %.2f realizada com sucesso. Rendimento: %.2f. Novo saldo: %.2f\n", valor, rendimento, cliente->saldo);
            Sleep(2000);
        } else {
            printf("Saldo insuficiente para realizar a aplicacao.\n");
            Sleep(2000);
        }
    }
}
// [7]
void adquirirCartaoCredito(CLIENTE *cliente) {
    if(verificaCliente(cliente)){
        printf("Cliente %s, Conta: %d, possui direito ao cartao de credito. \n", cliente->nome, cliente->conta_corrente);
        cliente->possuiCartao = true;
        Sleep(2000);
    }
}
// [8]
void pagarCartaoCredito(CLIENTE *cliente) {
    if (!cliente->possuiCartao) {
        printf("Cliente ainda nao adquiriu o Cartao de Credito.\n");
        return;
    }

    float valorPagamento;
    printf("Digite o valor a ser pago no cartao de credito: ");
    scanf("%f", &valorPagamento);

    if (valorPagamento >= 0) {
            if (valorPagamento <= cliente->saldo) {
                cliente->saldo -= valorPagamento;
            } else {
                cliente->debitoPendente += (valorPagamento - cliente->saldo);
                cliente->saldo = 0;
            }

            printf("Pagamento de %.2f realizado com sucesso.\n", valorPagamento);
            printf("Novo Saldo: %.2f\n", cliente->saldo);
            if(cliente->debitoPendente > 0)
                printf("Debito pendente: %.2f\n", cliente->debitoPendente);
            Sleep(2000);
    } else {
        printf("Valor de pagamento invalido.\n");
    }
}

int geraMenu() {
    int opcao = 0;
    printf(" [1] Dados do Cliente\n");
    printf(" [2] Saldo\n");
    printf(" [3] Cheque Especial\n");
    printf(" [4] Saque\n");
    printf(" [5] Deposito\n");
    printf(" [6] Aplicacao Financeira\n");
    printf(" [7] Aquisicao Cartao de Credito\n");
    printf(" [8] Pagamento Cartao de Credito\n");
    printf(" [9] Sair\n");
    printf(" \n  Opcao: ");
    scanf("%d", &opcao);
    printf(" \n");
    if (opcao > 0 && opcao < 10)
        return opcao;

    return 0;
}

bool verificaCliente(CLIENTE *cliente) {
    if (cliente->conta_corrente == 0) {
        printf("Cliente nao cadastrado.\n");
        Sleep(2000);
        return false;
    }
    return true;
}

void zeraCliente(CLIENTE *cliente) {
    strcpy(cliente->nome, "");
    cliente->conta_corrente = 0;
    cliente->chequeEspecial = 0.0;
    cliente->saldo = 0.0;
}

int main() {
    CLIENTE cliente;
    
    strcpy(cliente.nome, "");
    cliente.conta_corrente = 0;
    cliente.saldo = 0;
    cliente.chequeEspecial = 0;
    cliente.debitoPendente = 0;
    cliente.possuiCartao = false;

    while (true) {
        int opcao;
        opcao = geraMenu();

        switch (opcao) {
            case 1:
                addCliente(&cliente);
                break;
            case 2:
                mostrarSaldo(&cliente);
                break;
            case 3:
                chequeEspecial(&cliente);
                break;
            case 4:
                realizarSaque(&cliente);
                break;
            case 5:
                realizarDeposito(&cliente);
                break;
            case 6:
                realizarAplicacao(&cliente);
                break;
            case 7:
                adquirirCartaoCredito(&cliente);
                break;
            case 8:
                pagarCartaoCredito(&cliente);
                break;
            case 9:
                exit(0);
                break;
            default:
                printf("Digite uma opcao valida!!!\n");
                break;
        }

        while (getchar() != '\n');
    }
    return 0;
}