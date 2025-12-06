#ifndef UTILIDADES_H
#define UTILIDADES_H

void str_to_lower(char *str);
void lerEntrada(char *destino, int tamanho, const char *mensagem, int (*validador)(const char*));
void lerEntradaCustom(const char *mensagem, const char *formato, void *destino, int (*validador)(const void*));
void atualizarEntrada(const char *mensagem, char *destino, int tamanho, int (*validador)(const char*));

#endif