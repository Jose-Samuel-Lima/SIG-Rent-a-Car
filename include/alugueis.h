#ifndef ALUGUEIS_H
#define ALUGUEIS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "clientes.h"
#include "veiculos.h"
#include "utilidades.h"
#include "validacao.h"

// =======================
// Definições Globais
// =======================

#define ARQUIVO_ID "ultimo_id_aluguel.txt"

// =======================
// Estrutura de Aluguel
// =======================

typedef struct Aluguel {
    char id[5];              
    char cpf_cliente[15];
    char placa_veiculo[8];
    char data_inicio[11];
    char data_fim[11];
    float valor_total;
    bool status;
    struct Aluguel* prox_alu;
} Aluguel;

// =======================
// Protótipos de Funções
// =======================

// ---------- Módulos ----------
int modulo_aluguel(void);
int modulo_tela_alugueis(void);
void modulo_cadastrar_aluguel(void);
void modulo_verificar_aluguel(void);
void modulo_atualizar_aluguel(void);
void modulo_excluir_aluguel(void);

// ---------- Lista Dinâmica - Aluguel ----------
void listaOrdenadaAlugueis(Aluguel** lista_aluguel, Aluguel* novo_alu);
Aluguel* carregarListaAlugueis(void);
Aluguel* buscarAluguel(Aluguel* lista_aluguel, const char* cpf_cliente);
void salvarListaAlugueis(Aluguel* lista_aluguel);
void limparListaAlugueis(Aluguel* lista_aluguel);

// ---------- Lista Dinâmica - Cliente e Veículo ---------- 
Cliente* carregarListaCliente(void);
void limparListaCliente(Cliente* lista_cliente);

Veiculo* carregarListaVeiculos(void);
void limparListaVeiculos(Veiculo* lista_veiculo);

// ---------- ID de Aluguel ----------
void gerarID_aluguel(char *destino); 

// ----------- VERIFICAÇÃO DE VEICULO --------------

bool verificarDisponibilidadeVeiculo(Aluguel* lista_aluguel, const char* placa, const char* nova_data_inicio, const char* nova_data_fim, const char* id_atual);

struct tm strParaData(const char* str);

#endif // ALUGUEIS_H

