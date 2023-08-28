enum SETORES {
    A = 1,
    B,
    C,
    D,
    E
};

typedef struct ingresso
{
    int dia;
    int mes;
    int ano;
    int sessao;
    char poltrona[3];
    float valor;
} INGRESSO;

void geraPoltronas();