#ifndef VEICULOS_H
#define VEICULOS_H
#include <stdbool.h>

typedef struct veiculo {
    int id;
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
void modulo_cadastrar_veiculo(void);
void modulo_dados_veiculo(void);
void modulo_atualizar_veiculo(void);
void modulo_excluir_veiculo(void);

#endif