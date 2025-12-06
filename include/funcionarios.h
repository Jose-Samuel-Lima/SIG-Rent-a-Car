#ifndef FUNCIONARIOS_H
#define FUNCIONARIOS_H
#include <stdbool.h>

// --------------------------------------------------------------
// ESTRUTURA DO FUNCIONÁRIO
// --------------------------------------------------------------

typedef struct funcionario {
    char nome_funcionario[100];
    char cpf_funcionario[15];
    char email_funcionario[100];
    char telefone_funcionario[15];
    char cargo_funcionario[51];
    bool status;
    struct funcionario* prox_func;

} Funcionario;

// --------------------------------------------------------------
// LISTA DINÂMICA
// --------------------------------------------------------------

void listaOrdenadaFuncionarios(Funcionario** lista_funcionario, Funcionario* novo_func);

Funcionario* carregarListaFuncionarios(void);

Funcionario* buscarFuncionario(Funcionario* lista_funcionario, const char* cpf_fun);

void salvarListaFuncionarios(Funcionario* lista_funcionario);

void limparListaFuncionarios(Funcionario* lista_funcionario);

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