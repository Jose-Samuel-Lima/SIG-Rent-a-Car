#ifndef VEICULO_H
#define VEICULO_H
#include <stdbool.h>

typedef struct veiculo {
    char placa[8];
    char chassi[18];
    char renavam[12];
    char categoria[7];
    char modelo[31];
    char marca[16];
    char ano[5];
    char codigo_interno[7];
    float preco;
    bool status;

} Veiculo;

int modulo_veiculo(void);
int modulo_tela_veiculos(void);
void modulo_cadastrar_veiculo(Veiculo* vei);
void modulo_dados_veiculo(Veiculo* vei);
void modulo_atualizar_veiculo(Veiculo* vei);
void modulo_excluir_veiculo(Veiculo* vei);

#endif