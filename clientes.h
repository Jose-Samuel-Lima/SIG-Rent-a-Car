#ifndef CLIENTE_H
#define CLIENTE_H
#include <stdbool.h>

typedef struct cliente {
    char *nome_cliente;
    char *cpf_cliente;
    char *data_nascimento;
    char *email_cliente;
    char *cnh;
    bool status;
    
} Cliente;

int modulo_cliente(void);
int modulo_tela_cliente(void);
void modulo_cadastrar_cliente(void);
void modulo_dados_cliente(void);
void modulo_atualizar_clientes(void);
void modulo_excluir_cliente(void);

#endif