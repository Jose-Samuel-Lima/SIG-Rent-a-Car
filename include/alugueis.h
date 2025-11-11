#ifndef ALUGUEIS_H
#define ALUGUEIS_H
#include <stdbool.h>

typedef struct aluguel
{
    char nome_cliente[100];
    char cpf_cliente[15];
    char codigo_renavam[12];
    char modelo_veiculo[31];
    char data_aluguel[15];
    char id_aluguel[12];
    bool status;
} Aluguel;

int modulo_aluguel(void);
int modulo_tela_alugueis(void);
void modulo_cadastrar_aluguel(void);
void modulo_dados_aluguel(void);
void modulo_atualizar_aluguel(void);
void modulo_finalizar_aluguel(void);


#endif