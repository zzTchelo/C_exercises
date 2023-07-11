#include<stdio.h>

void preencherBuffer(int n, int Z, int F) {
    int start, end;
    
    start = F - Z;
    end = F + Z;

    for (int i = start; i <= end; i++){
        // Verifica se o frame atual é o primeiro do arquivo de vídeo
        if (i == 0) {
            printf("[BOV]");
            if (i != end)
                printf("-");
        }

        // Preenche o buffer com os frames anteriores a F
        if (i < F) {
            if (i >= 1) {
                printf("[%d]", i);
                if (i != end)
                    printf("-");
            } else {
                printf("[]");
                if (i != end)
                    printf("-");
            }
            continue;
        }

        // Exibe o frame atual
        if (i == F){
            printf("{%d}", F);
            if (i != end)
                    printf("-");
            continue;    
        }
        
        // Preenche o buffer com os frames posteriores a F
        if (i > F) {
            if (i <= n) {
                printf("[%d]", i);
                if (i != end)
                    printf("-");
                // Verifica se o frame atual é o último do arquivo de vídeo
                if ((i == n) && (i != end) ) {
                    printf("[EOV]");
                    i++;
                }
            } else {
                printf("[]");
            }
            continue;
        }
    }
}

int main()
{
    // Z = Z * 2 + 1
    int n, Z, F;

    //printf("Digite os numeros de N, Z e F:");
    scanf("%d %d %d", &n, &Z, &F);

	if (n < 3 || n > 100 || Z < 1 || Z > 100 || F < 1 || F > 100)
		return 0;

    preencherBuffer(n, Z, F);
    
    return 0;
}
