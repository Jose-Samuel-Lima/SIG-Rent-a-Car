#ifndef CLIENTE_H
#define CLIENTE_H
#include <stdbool.h>

typedef struct cliente {
    char nome_cliente[100];
    char cpf_cliente[15];
    char data_nascimento[11];
    char email_cliente[100];
    char cnh[20];
    bool status;
    
} Cliente;

int modulo_cliente(void);
int modulo_tela_cliente(void);
void modulo_cadastrar_cliente(Cliente* cli);
void modulo_dados_cliente(Cliente* cli);
void modulo_atualizar_clientes(void);
void modulo_excluir_cliente(Cliente* cli);

#endif