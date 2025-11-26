#ifndef FUNCIONARIOS_H
#define FUNCIONARIOS_H
#include <stdbool.h>

typedef struct funcionario {
    char nome_funcionario[100];
    char dt_nascimento_fun[12];
    char cpf_funcionario[15];
    char cargo[51];
    char email_funcionario[100];
    bool status;

} Funcionario;

int modulo_funcionario(void);
int modulo_tela_funcionario(void);
void modulo_cadastrar_funcionario(void);
void modulo_verificar_funcionario(void);
void modulo_atualizar_funcionario(void);
void modulo_excluir_funcionario(void);

#endif