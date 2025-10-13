#ifndef FUNCIONARIO_H
#define FUNCIONARIO_H
#include <stdbool.h>

typedef struct funcionario {
    char nome_funcionario[51];
    char dt_nascimento_fun[12];
    char cpf_funcionario[12];
    char cargo[22];
    char email_funcionario[30];
    bool status;

} Funcionario;

int modulo_funcionario(void);
int modulo_tela_funcionario(void);
void modulo_cadastrar_funcionario(void);
void modulo_dados_funcionario(void);
void modulo_atualizar_funcionario(void);
void modulo_excluir_funcionario(void);

#endif