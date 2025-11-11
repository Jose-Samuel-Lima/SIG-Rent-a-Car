#ifndef RELATORIOS_H
#define RELATORIOS_H

int modulo_relatorio(void);
int modulo_tela_relatorio(void);

int navegar_relatorio_funcionarios(void);
int navegar_relatorio_clientes(void);
int navegar_relatorio_veiculos(void);
int navegar_relatorio_alugueis(void);

int modulo_relatorio_funcionarios(void);
void funcionarios_ativos(void);
void funcionarios_inativos(void);

int modulo_relatorio_clientes(void);
void clientes_ativos(void);
void clientes_inativos(void);

int modulo_relatorio_veiculos(void);
void veiculos_ativos(void);

int modulo_relatorio_alugueis(void);
void alugueis_ativos(void);

#endif