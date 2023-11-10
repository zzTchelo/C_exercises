typedef struct ingresso
{
    char data[11];
    char hora[6];
    int sessao;
    char poltrona[3];
    float valor;
} INGRESSO;

void geraPoltronas();
void ler_ingresso(INGRESSO *ingresso);
void imprimir_ingresso(INGRESSO *ingresso);

int validar_data(char *year, char *month, char *day);
int isDateValid(int year, int month, int day);

int validarHora(char *hour, char *minute);
int isTimeValid(int hour, int minute);