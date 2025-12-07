#ifndef UTILIDADES_H
#define UTILIDADES_H

// Converte uma string para minúsculas
void str_to_lower(char *str);

// Lê uma entrada com tamanho máximo e validação
void lerEntrada(char *destino, int tamanho, const char *mensagem, int (*validador)(const char*));

// Atualiza o valor de uma entrada já existente
void atualizarEntrada(const char *mensagem, char *destino, int tamanho, int (*validador)(const char*));

int diasEntreDatas(const char* data_inicio, const char* data_fim);

void gerarID(char *destino);

#endif
