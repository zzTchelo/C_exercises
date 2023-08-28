#include <stdio.h>
#include <string.h>

void cifrar(char palavra[], int chave) {
    int i;
    char ch;
    for(i = 0; i < strlen(palavra); i++) {
        ch = palavra[i];
        if(ch >= 'a' && ch <= 'z') {
            ch = ch + chave;
            if(ch > 'z') {
                ch = ch - 'z' + 'a' - 1;
            }
            palavra[i] = ch;
        }
        else if(ch >= 'A' && ch <= 'Z') {
            ch = ch + chave;
            if(ch > 'Z') {
                ch = ch - 'Z' + 'A' - 1;
            }
            palavra[i] = ch;
        }
    }
}

int main() {
    char palavra[100];
    int chave;

    printf("Digite uma mensagem para encriptar: ");
    fgets(palavra, sizeof(palavra), stdin);

    printf("Entre com a chave de encriptacao: ");
    scanf("%d", &chave);

    cifrar(palavra, chave);
    printf("Mensagem Encriptada: %s", palavra);

    return 0;
}