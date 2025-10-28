#include <stdlib.h>
#include <stdio.h>
#include <string.h>

// ==============================
//       CARACTERES PADRÃO
// ==============================

int ehLetra(char c) {
    return ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'));
}

int ehDigito(char c) {
    return (c >= '0' && c <= '9');
}
