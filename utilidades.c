#include <ctype.h>
#include <stdio.h>

#include "utilidades.h"

void str_to_lower(char *str) {
    for (int i = 0; str[i] != '\0'; i++) {
        str[i] = tolower((unsigned char)str[i]);
    }
}

void lerEntrada(char *destino, int tamanho, const char *mensagem, int (*validador)(const char*)) {
    int c;
    char formato[20];

    sprintf(formato, "%%%d[^\n]", tamanho - 1);

    printf("%s", mensagem);
    scanf(formato, destino);
    while ((c = getchar()) != '\n' && c != EOF);

    while (!validador(destino)) {
        printf("XXX - Entrada inválida! Digite novamente: ");
        scanf(formato, destino);
        while ((c = getchar()) != '\n' && c != EOF);
    }
}

void atualizarEntrada(const char *mensagem, char *destino, int tamanho, int (*validador)(const char*)) {
    lerEntrada(destino, tamanho, mensagem, validador);
}
