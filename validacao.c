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

// ==============================
//       DADOS ESPECÍFICOS
// ==============================

int validarNome(char *nome) {
    for (int i = 0; nome[i] != '\0'; i++) {
        if (!(ehLetra(nome[i]) || nome[i] == ' ')) {
            return 0;
        }
    }
    return 1;
}

int validarCPF(char *cpf) {
    int cont = 0;
    for (int i = 0; cpf[i] != '\0'; i++) {
        if (ehDigito(cpf[i])) cont++;
        else if (cpf[i] != '.' && cpf[i] != '-') return 0;
    }
    return (cont == 11);
}

int validarEmail(char *email) {
    return (strchr(email, '@') != NULL & strchr(email, '.') != NULL);
}

int validarData(char *data) {
    if (strlen(data) != 10) return 0;
    if (!(ehDigito(data[0]) && ehDigito(data[1]) && 
          data[2] == '/' &&
          ehDigito(data[3]) && ehDigito(data[4]) && 
          data[5] == '/' &&
          ehDigito(data[6]) && ehDigito(data[7]) && 
          ehDigito(data[8]) && ehDigito(data[9]))) {
        return 0;
    }
    return 1;

}
