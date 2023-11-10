#include <stdio.h>
#include <string.h>
#include <time.h>
//#include "atividade1.h" 

/*
Queridos alunos, boa tarde!
    - Construa um algoritmo para a compra de ingresso de cinema. 
    Lembre-se que um registro é composto por campos que especificam informações, como: 
        ingresso, 
        poltrona, 
        data, 
        horário, 
        sessão, 
        valor 
    e o que mais a sua imaginação quiser. (Não precisa ser exatamente os campos citados acima.)
    A atividade deverá ser entregue até o dia 2/9. Se atentem ao prazo de entrega. Evitem cópias!
*/
const int COLUNAS_POLTRONA = 5;
const int FILEIRAS_POLTRONA = 5;
const int DIGITOS_POLTRONA = 2;

typedef struct ingresso
{
    char data[10];
    char hora[5];
    char minuto[3];
    int sessao;
    char poltrona[3];
    float valor;
} INGRESSO;

void geraPoltronas();
void ler_ingresso(INGRESSO *ingresso);
void imprimir_ingresso(INGRESSO *ingresso);

int main()
{

    INGRESSO *ingresso;
    
    // Gera as poltronas
    geraPoltronas();

    // Lê o ingresso
    ler_ingresso(&ingresso);

    // Imprime Ingresso
    imprimir_ingresso(&ingresso);

    return 0;
}

void geraPoltronas(){
    printf("Escolha uma das seguintes poltronas:\n\n");
    for (int i = 0; i < COLUNAS_POLTRONA; i++){
        for (int j = 1; j <= FILEIRAS_POLTRONA; j++)
        {
            printf("[ %d%d ]", i, j);
        }
        printf("\n");
    }
    printf("\n");
}

void ler_ingresso(INGRESSO *ingresso) {
    printf("Digite o numero da poltrona: ");
    scanf("%s", &ingresso->poltrona);

    printf("Digite a sessão do ingresso (1 - Manha/ 2- Tarde/ 3- Noite): ");
    scanf("%d", &ingresso->sessao);

    //do{
    printf("Digite a data do ingresso (DD/MM/AAAA): ");
    scanf("%s", &ingresso->data);
    //} while (!validarData(&ingresso->dia, &ingresso->mes, &ingresso->ano));

    //do{
    printf("Digite o horario do ingresso (HH:MM): ");
    scanf("%s", &ingresso->hora);
    //} while (!validarHora(&ingresso->hora, &ingresso->minuto));

    printf("Digite o valor do ingresso: ");
    scanf("%f", &ingresso->valor);
}

void imprimir_ingresso(INGRESSO *ingresso) {
    printf("Numero da poltrona: %s\n", ingresso->poltrona);
    printf("Data do ingresso: %s \n", ingresso->data);
    printf("Horario do ingresso: %s\n", ingresso->hora);
    printf("Valor do ingresso: %.2f\n", ingresso->valor);

    switch (ingresso->sessao)
    {
    case 1:
        printf("Sessao: Manhã\n");
        break;
    case 2:
        printf("Sessao: Tarde\n");
        break;
    case 3:
        printf("Sessao: Noite\n");
        break;
    default:
        printf("Sessao: Invalida\n");
        break;
    }
}

