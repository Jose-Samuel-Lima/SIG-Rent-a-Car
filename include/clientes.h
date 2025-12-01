#ifndef CLIENTES_H
#define CLIENTES_H
#include <stdbool.h>

typedef struct cliente {
    char nome_cliente[100];
    char cpf_cliente[15];
    char data_cliente[12];
    char email_cliente[100];
    char cnh_cliente[20];
    bool status;
    
} Cliente;

int modulo_cliente(void);
int modulo_tela_cliente(void);
void modulo_cadastrar_cliente(void);
void modulo_verificar_cliente(void);
void modulo_atualizar_clientes(void);
void modulo_excluir_cliente(void);

#endif