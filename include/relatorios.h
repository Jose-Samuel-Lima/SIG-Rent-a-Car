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
void funcionarios_por_cargo(void);
void filtrar_funcionario_cargo(char* cargo_funcionario);

int modulo_relatorio_clientes(void);
void clientes_ativos(void);
void clientes_inativos(void);
void clientes_por_nome(void);
void filtrar_cliente_nome(char* nome_cliente);

int modulo_relatorio_veiculos(void);
void veiculos_ativos(void);
void veiculos_inativos(void);
void veiculos_por_marca(void);
void filtrar_veiculo_marca(char* marca_veiculo);

int modulo_relatorio_alugueis(void);
void alugueis_ativos(void);
void alugueis_inativos(void);
void alugueis_por_cliente(void);
void filtrar_aluguel_cliente(char* cpf_cliente);

void str_to_lower(char *str);

#endif