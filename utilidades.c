#include <ctype.h>
#include <stdio.h>
#include <time.h>

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

int diasEntreDatas(const char* data_inicio, const char* data_fim) {

    struct tm tm_inicio = {0}, tm_fim = {0};
    int dia, mes, ano;

    sscanf(data_inicio, "%d/%d/%d", &dia, &mes, &ano);
    tm_inicio.tm_mday = dia;
    tm_inicio.tm_mon  = mes - 1;
    tm_inicio.tm_year = ano - 1900;

    sscanf(data_fim, "%d/%d/%d", &dia, &mes, &ano);
    tm_fim.tm_mday = dia;
    tm_fim.tm_mon  = mes - 1;
    tm_fim.tm_year = ano - 1900;

    time_t t_inicio = mktime(&tm_inicio);
    time_t t_fim = mktime(&tm_fim);

    if (t_inicio == -1 || t_fim == -1) return 0;

    double segundos = difftime(t_fim, t_inicio);
    int dias = (int)(segundos / (60 * 60 * 24));
    if (dias <= 0) dias = 1; // mínimo 1 dia
    return dias;
}
