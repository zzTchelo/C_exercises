#include <stdio.h>

int main()
{
    int n, count = 0;
    printf("Digite um numero inteiro: ");
    scanf("%d", &n);
    for (int i = 1; i <= n; i+=2){
        count += i;
    }
    printf("Soma: %d", count);
}
