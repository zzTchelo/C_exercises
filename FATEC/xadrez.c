#include<stdio.h>

const char MAGIC_NUMBER[2] = "P2";
const int WIDTH = 1500;
const int HEIGHT = 1500;

const char GRAY_VALUE[4] = "255";
const char WHITE_VALUE[4] = " 0 ";
const int QUADRANTE_SIZE = 100;

int main(int argc, char const *argv[])
{
    FILE* tab;
    tab = fopen("tabuleiro.pgm", "wb");

    fprintf(tab, "%s\n", MAGIC_NUMBER);
    fprintf(tab, "%d %d\n", WIDTH, HEIGHT);
    fprintf(tab, "%s\n", GRAY_VALUE);

    for (size_t i = 0; i < HEIGHT; i++){
        for (size_t j = 0; j < WIDTH; j++){        
            int color = ((i/QUADRANTE_SIZE) + (j/QUADRANTE_SIZE)) % 2 == 0;
            if (color == 0)
                fprintf(tab, "%s ", GRAY_VALUE);
            if (color == 1)
                fprintf(tab, "%s ", WHITE_VALUE);
        }
        fprintf(tab, "\n ");
    }
    
    

    return 0;
}
