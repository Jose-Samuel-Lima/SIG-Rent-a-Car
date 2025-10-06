#ifndef ALUGUEL_H
#define ALUGUEL_H

typedef struct aluguel
{
    char nome_cliente[51];
    char cpf_cliente[12];
    char codigo_renavam[12];
    char modelo_veiculo[15];
    char data_aluguel[15];
    char id_aluguel[11];
} Aluguel;

int modulo_aluguel(void);
int modulo_tela_alugueis(void);
void modulo_cadastrar_aluguel(void);
void modulo_dados_aluguel(void);
void modulo_atualizar_aluguel(void);
void modulo_finalizar_aluguel(void);

#endif