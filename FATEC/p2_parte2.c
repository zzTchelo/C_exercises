#include <stdio.h>
#include <string.h>

int isSubsequenceRepeated(char dna[], char subsequence[]) {
    int count = 0;
    char *position = dna;

    while ((position = strstr(position, subsequence)) != NULL) {
        count++;
        position += strlen(subsequence);
    }

    return count > 1;
}

int countRepeatingSubsequences(char dna1[], char dna2[], char dna3[], int t) {
    int count = 0;
    char countedSubsequences[100][16] = {0}; 

    for (int i = 0; i <= strlen(dna1) - t; i++) {
        // Extrair a subsequência de dna1
        char subsequence[t + 1];
        strncpy(subsequence, dna1 + i, t);
        subsequence[t] = '\0';

        int isRepeated = 0;
        for (int j = 0; j < count; j++) {
            if (strcmp(countedSubsequences[j], subsequence) == 0) {
                isRepeated = 1;
                break;
            }
        }

        if (isRepeated) {
            continue;
        }

        if (strstr(dna2, subsequence) != NULL && strstr(dna3, subsequence) != NULL &&
            !isSubsequenceRepeated(dna2, subsequence) &&
            !isSubsequenceRepeated(dna3, subsequence)) {
            count++;

            strcpy(countedSubsequences[count - 1], subsequence);
        }
    }

    return count;
}

int main() {
    char dna1[16], dna2[16], dna3[16];
    int t;

    while (scanf("%15s %15s %15s %d", dna1, dna2, dna3, &t) == 4) {
        if (strlen(dna1) < 4 || strlen(dna1) > 15 ||
            strlen(dna2) < 4 || strlen(dna2) > 15 ||
            strlen(dna3) < 4 || strlen(dna3) > 15 ||
            t < 2 || t > 15) {
            continue; 
        }

        
        if (strlen(dna1) < t || strlen(dna2) < t || strlen(dna3) < t) {
            continue; 
        }

        int result = countRepeatingSubsequences(dna1, dna2, dna3, t);
        printf("%d\n", result);
    }

    return 0;
}
