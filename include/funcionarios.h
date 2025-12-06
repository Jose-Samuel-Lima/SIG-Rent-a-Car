#ifndef FUNCIONARIOS_H
#define FUNCIONARIOS_H
#include <stdbool.h>

// --------------------------------------------------------------
// ESTRUTURA DO FUNCIONÁRIO
// --------------------------------------------------------------

typedef struct funcionario {
    char nome_funcionario[100];
    char dt_nascimento_fun[12];
    char cpf_funcionario[15];
    char email_funcionario[100];
    char cargo[51];
    bool status;
    struct funcionario* prox_func;

} Funcionario;

// --------------------------------------------------------------
// LISTA DINÂMICA
// --------------------------------------------------------------

void listaOrdenadaFuncionarios(Funcionario** lista, Funcionario* novo_func);

Funcionario* carregarListaFuncionarios(void);

Funcionario* buscarFuncionario(Funcionario* lista, const char* cpf_fun);

void salvarListaFuncionarios(Funcionario* lista);

void limparListaFuncionarios(Funcionario* lista);

// --------------------------------------------------------------
// MÓDULO PRINCIPAL
// --------------------------------------------------------------

int modulo_funcionario(void);
int modulo_tela_funcionario(void);

void modulo_cadastrar_funcionario(void);
void modulo_verificar_funcionario(void);
void modulo_atualizar_funcionario(void);
void modulo_excluir_funcionario(void);

#endif