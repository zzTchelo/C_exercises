#include<stdio.h>
#include<stdlib.h>

const char MAGIC_NUMBER[2] = "P2";
const int WIDTH = 1500;
const int HEIGHT = 1500;
const char GRAY_VALUE[4] = "255";
const char WHITE_VALUE[4] = " 0 ";
const int NUM_QUADRANTE = 12;

void desenhaQuadrado(FILE* pgmimg){
    int quadrante = HEIGHT / NUM_QUADRANTE;
    int i = 0, j = 0, k = 0;

    while (i < quadrante){ // PRIMEIRA LINHA DE QUADRANTE
        for (k = 0; k < WIDTH; k++){
            if(i <= quadrante){
                fprintf(pgmimg, "%s ", GRAY_VALUE);
            }else{
                if((k > quadrante) && (k <= quadrante * 10)){
                    fprintf(pgmimg, "%s ", WHITE_VALUE);
                }else{
                    fprintf(pgmimg, "%s ", GRAY_VALUE);
                } 
            }
        }
        fprintf(pgmimg, "\n");
        i++;
    }

    while ((i >= quadrante) && (i < quadrante * 4)){ // SEGUNDA LINHA DE QUADRANTE
        for (k = 0; k < WIDTH; k++){
            if((i >= quadrante * 2) && (i < quadrante * 3)){
                if((k < quadrante) || (k >= quadrante * 11)){
                    fprintf(pgmimg, "%s ", GRAY_VALUE);
                }else if((k >= quadrante * 2) && (k < quadrante * 10)){
                    fprintf(pgmimg, "%s ", GRAY_VALUE);
                }else{
                    fprintf(pgmimg, "%s ", WHITE_VALUE);
                }
            }else if((k >= quadrante) && (k < quadrante * 11)){
                if((k >= quadrante * 2) && (k < quadrante * 3) && (i > quadrante * 2)){
                    fprintf(pgmimg, "%s ", GRAY_VALUE);
                }else if((k >= quadrante * 9) && (k < quadrante * 10) && (i > quadrante * 2)){
                    fprintf(pgmimg, "%s ", GRAY_VALUE);
                }else{
                    fprintf(pgmimg, "%s ", WHITE_VALUE);
                }
            }else{
                fprintf(pgmimg, "%s ", GRAY_VALUE);
            }                            
        }
        fprintf(pgmimg, "\n");
        i++;
    }

    while ((i >= quadrante * 4) && (i < quadrante * 6)){ // TERCEIRA LINHA DE QUADRANTE
        for (k = 0; k < WIDTH; k++){
            if((k >= quadrante * 4) && (k < quadrante * 8) && (i > quadrante * 3)){
                if((k >= quadrante * 4) && (k < quadrante * 5) && (i > quadrante * 3)){
                    fprintf(pgmimg, "%s ", GRAY_VALUE);
                }else if((k >= quadrante * 7) && (k <= quadrante * 8) && (i > quadrante * 3)){
                    fprintf(pgmimg, "%s ", GRAY_VALUE);
                }else if((k >= quadrante * 4) && (k <= quadrante * 7) && (i < quadrante * 5)){
                    fprintf(pgmimg, "%s ", GRAY_VALUE);
                }else{
                    fprintf(pgmimg, "%s ", WHITE_VALUE);
                }
            }else if((k >= quadrante) && (k < quadrante * 11)){
                if((k >= quadrante * 2) && (k < quadrante * 3) && (i > quadrante * 2)){
                    fprintf(pgmimg, "%s ", GRAY_VALUE);
                }else if((k >= quadrante * 9) && (k < quadrante * 10) && (i > quadrante * 2)){
                    fprintf(pgmimg, "%s ", GRAY_VALUE);
                }else{
                    fprintf(pgmimg, "%s ", WHITE_VALUE);
                }
            }else{
                fprintf(pgmimg, "%s ", GRAY_VALUE);
            }                            
        }
        fprintf(pgmimg, "\n");
        i++;
    }

    while ((i >= quadrante * 6) && (i < quadrante * 8)){ // QUARTA LINHA DE QUADRANTE
        for (k = 0; k < WIDTH; k++){
            if((k >= quadrante * 4) && (k <= quadrante * 8) && (i > quadrante * 4)){
                if((k >= quadrante * 4) && (k < quadrante * 5) && (i > quadrante * 4)){
                    fprintf(pgmimg, "%s ", GRAY_VALUE);
                }else if((k >= quadrante * 7) && (k < quadrante * 8) && (i > quadrante * 4)){
                    fprintf(pgmimg, "%s ", GRAY_VALUE);
                }else if((k >= quadrante * 4) && (k < quadrante * 8) && (i >= quadrante * 7)){
                    fprintf(pgmimg, "%s ", GRAY_VALUE);
                }else{
                    fprintf(pgmimg, "%s ", WHITE_VALUE);
                }
            }else if((k >= quadrante) && (k < quadrante * 11)){
                if((k >= quadrante * 2) && (k < quadrante * 3) && (i > quadrante * 4)){
                    fprintf(pgmimg, "%s ", GRAY_VALUE);
                }else if((k >= quadrante * 9) && (k < quadrante * 10) && (i > quadrante * 4)){
                    fprintf(pgmimg, "%s ", GRAY_VALUE);
                }else{
                    fprintf(pgmimg, "%s ", WHITE_VALUE);
                }
            }else{
                fprintf(pgmimg, "%s ", GRAY_VALUE);
            }                            
        }
        fprintf(pgmimg, "\n");
        i++;
    }

    while ((i >= quadrante * 8) && (i < quadrante * 10)){ // QUINTA LINHA DE QUADRANTE
        for (k = 0; k < WIDTH; k++){
            if((i >= quadrante * 8) && (i < quadrante * 9)){
                if((k < quadrante) || (k >= quadrante * 11)){
                    fprintf(pgmimg, "%s ", GRAY_VALUE);
                } else if((k >= quadrante * 2) && (k < quadrante * 3) && (i >= quadrante * 8)){
                    fprintf(pgmimg, "%s ", GRAY_VALUE);
                } else if((k >= quadrante * 9) && (k < quadrante * 10) && (i >= quadrante * 8)){
                    fprintf(pgmimg, "%s ", GRAY_VALUE);
                } else{
                    fprintf(pgmimg, "%s ", WHITE_VALUE);
                }
            }else if((i >= quadrante * 9) && (i < quadrante * 10)){
                if(((k < quadrante) || (k >= quadrante * 11)) && (i >= quadrante * 9)){
                    fprintf(pgmimg, "%s ", GRAY_VALUE);
                }else if((k >= quadrante * 2) && (k < quadrante * 10) && (i <= quadrante * 10)){
                    fprintf(pgmimg, "%s ", GRAY_VALUE);
                }else{
                    fprintf(pgmimg, "%s ", WHITE_VALUE);
                }
            }else{
                fprintf(pgmimg, "%s ", WHITE_VALUE);
            }   
        }
        fprintf(pgmimg, "\n");
        i++;
    }

    while ((i >= quadrante * 10) && (i < quadrante * 12)){ // ÚLTIMA LINHA DE QUADRANTE
        for (k = 0; k < WIDTH; k++){
            if(i >= quadrante * 11){
                fprintf(pgmimg, "%s ", GRAY_VALUE);
            }else{
                if((k >= quadrante) && (k < quadrante * 11)){
                    fprintf(pgmimg, "%s ", WHITE_VALUE);
                }else{
                    fprintf(pgmimg, "%s ", GRAY_VALUE);
                } 
            }
        }
        fprintf(pgmimg, "\n");
        i++;
    }
};

int main(int argc, char const *argv[])
{
    int soma = 0;

    FILE* pgmimg;
    pgmimg = fopen("pgmimg.pgm", "wb");

    fprintf(pgmimg, "%s\n", MAGIC_NUMBER); 
    fprintf(pgmimg, "%d %d\n", WIDTH, HEIGHT); 
    fprintf(pgmimg, "%s\n\n", GRAY_VALUE);

    desenhaQuadrado(pgmimg);

    fclose(pgmimg);

    return 0;
}