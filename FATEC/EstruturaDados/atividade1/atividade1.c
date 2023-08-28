#include <stdio.h>
#include <string.h>
#include "atividade1.h" 

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

int main()
{
    enum SETORES setores;
    INGRESSO ingresso; 
    printf("Escolha uma das seguintes poltronas:\n\n");
    geraPoltronas();
    printf("Poltrona escolhida: ");
    scanf("%s", ingresso.poltrona);

    return 0;
}

void geraPoltronas(){
    for (int i = A; i <= E; i++){
        for (int j = A; j <= E; j++)
        {
            switch (i)
            {
            case A:
                printf("A%d ", j);
                break;
            case B:
                printf("B%d ", j);
                break;
            case C:
                printf("C%d ", j);
                break;
            case D:
                printf("D%d ", j);
                break;
            case E:
                printf("E%d ", j);
                break;
            default:
                break;
            }
        }
        printf("\n");
    }
    printf("\n");
}