#ifndef UTILIDADES_H
#define UTILIDADES_H

void str_to_lower(char *str);
void lerEntrada(char *destino, int tamanho, const char *mensagem, int (*validador)(const char*));

#endif