#ifndef CLIENTE_H
#define CLIENTE_H

typedef struct cliente {
    char nome_cliente[52];
    char cpf_cliente[15];
    char data_nascimento[15];
    char email_cliente[52];
    char cnh[14];
} Cliente;

int modulo_cliente(void);
int modulo_tela_cliente(void);
void modulo_cadastrar_cliente(void);
void modulo_dados_cliente(void);
void modulo_atualizar_clientes(void);
void modulo_excluir_cliente(void);

#endif