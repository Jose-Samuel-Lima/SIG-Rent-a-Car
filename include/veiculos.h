#ifndef VEICULOS_H
#define VEICULOS_H
#include <stdbool.h>

// --------------------------------------------------------------
// ESTRUTURA DO VEÍCULO
// --------------------------------------------------------------

typedef struct veiculo {
    char placa_veiculo[8];        
    char modelo_veiculo[31];       
    char marca_veiculo[16];
    char ano_veiculo[5];           
    float preco_veiculo;
    bool status;
    struct veiculo *prox_vei;        

} Veiculo;

// --------------------------------------------------------------
// LISTA DINÂMICA
// --------------------------------------------------------------

void listaOrdenadaVeiculos(Veiculo** lista_veiculo, Veiculo* novo_vei);

Veiculo* carregarListaVeiculos(void); 

Veiculo* buscarVeiculo(Veiculo* lista_veiculo, const char* placa);

void salvarListaVeiculos(Veiculo* lista_veiculo);

void limparListaVeiculos(Veiculo* lista_veiculo);

// --------------------------------------------------------------
// MÓDULO PRINCIPAL
// --------------------------------------------------------------

int modulo_veiculo(void);
int modulo_tela_veiculos(void);

void modulo_cadastrar_veiculo(void);
void modulo_verificar_veiculo(void);
void modulo_atualizar_veiculo(void);
void modulo_excluir_veiculo(void);

#endif