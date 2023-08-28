#include <stdio.h>
#include <math.h>
#include <stdlib.h>

typedef struct coordenadas
{
    int quantidade;
    float* coordenadasX;
    float* coordenadasY;
    float distancia;
} COORDENADAS;

float menor_numero(float *vetor, int len){
    float min = vetor[0];
    for (int i = 1; i < len; i++ ){
        if(vetor[i] < min)
            min = vetor[i];
    }
    return min;
}

float maior_numero(float *vetor, int len){
    float max = vetor[0];
    for (int i = 0; i < len; i++){
        if (vetor[i] > max)
            max = vetor[i];
    }
    return max;    
}

float euclidean(COORDENADAS *coordenadas, int i) {
    float diferencaX = fabs(maior_numero(coordenadas->coordenadasX, i) - menor_numero(coordenadas->coordenadasX, i));
    float diferencaY = fabs(maior_numero(coordenadas->coordenadasY, i) - menor_numero(coordenadas->coordenadasY, i));
    
    if(diferencaX == 0 && diferencaY == 0)
        return 0;

    float sum = diferencaX * diferencaX + diferencaY * diferencaY;
    return sqrt(sum)/2;
}

int main()
{
    COORDENADAS coordenadas;
    float coordenadas_x = 0, coordenadas_y = 0;
    int coordenadasValidas = 1;
    while(1){
        //printf("Digite a quantidade de ladroes: ");
        scanf("%d", &coordenadas.quantidade);

        if ((coordenadas.quantidade <= 0) || (coordenadas.quantidade > 100)) { //Valida Quantidade de Ladrões
            //printf("Quantidade invalida!");
            break;
        }

        coordenadas.coordenadasX = (float*) malloc(coordenadas.quantidade * sizeof(float));
        coordenadas.coordenadasY = (float*) malloc(coordenadas.quantidade * sizeof(float));

        if ((coordenadas.coordenadasX == NULL) || (coordenadas.coordenadasY == NULL)) { //Valida Alocação de Memória
            //printf("Erro de alocacao de memoria!");
            break;
        }
        
        for(int i = 0; i < coordenadas.quantidade; i++){
            //printf("Digite as Coordenadas X e Y do ladrao %d: ", i+1);
            scanf("%f %f", &coordenadas.coordenadasX[i], &coordenadas.coordenadasY[i]);
            if (coordenadas.coordenadasX[i] < -1000 || coordenadas.coordenadasX[i] > 1000 ||
                coordenadas.coordenadasY[i] < -1000 || coordenadas.coordenadasY[i] > 1000) { //Valida Coordenadas
                coordenadasValidas = 0;
                break;
            }
        }

        if (!coordenadasValidas || coordenadas.quantidade == 1) {
            coordenadas.distancia = 0;
        } else {
            coordenadas_x = (maior_numero(coordenadas.coordenadasX, coordenadas.quantidade) + 
                            menor_numero(coordenadas.coordenadasX, coordenadas.quantidade))/2;
            coordenadas_y = (maior_numero(coordenadas.coordenadasY, coordenadas.quantidade) + 
                            menor_numero(coordenadas.coordenadasY, coordenadas.quantidade))/2;
            //coordenadas.distancia = (euclidean(&coordenadas, coordenadas.quantidade));
            coordenadas.distancia = (euclidean(&coordenadas, coordenadas.quantidade));
            if (isnan(coordenadas.distancia)) { //Valida resultado da conta
                coordenadasValidas = 0;
            }
        }

        //Saídas melhor tratadas
        //printf("\n Quantidade: %d", coordenadas.quantidade);
        //printf("\n Coordenadas X: %.2f", coordenadas_x);
        //printf("\n Coordenadas Y: %.2f", coordenadas_y);
        //printf("\n Distancia: %.2f", coordenadas.distancia);
        if (coordenadasValidas)
            printf("%.2f\t%.2f\t%.2f\n", coordenadas_x, coordenadas_y, coordenadas.distancia);

        free(coordenadas.coordenadasX);
        free(coordenadas.coordenadasY);
    }
    return 0;
}