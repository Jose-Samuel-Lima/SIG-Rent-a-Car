#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "validacao.h"

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
    if (!email || !email[0] || email[0] == '@' || email[0] == '.') return 0;

    int temArroba = 0;
    int temPontoDepois = 0;

    for (int i = 0; email[i]; i++) {
        char c = email[i];
        if (c == '@') {
            if (temArroba) return 0;
            temArroba = 1;
        } else if (c == '.' && temArroba) {
            temPontoDepois = 1;
        } else if (!((c >= 'a' && c <= 'z') ||
                     (c >= 'A' && c <= 'Z') ||
                     (c >= '0' && c <= '9') ||
                     c == '_' || c == '-' || c == '+')) {
            return 0;
        }
    }

    return (temArroba && temPontoDepois);
}

int verificarNumero(char *entrada) {
    for (int i = 0; entrada[i] != '\0'; i++) {
        if (entrada[i] != '/' && !ehDigito(entrada[i])) {
            return 0;
        }
    }
    return 1;
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
    
    if (strstr(data, "//") != NULL) {
        return 0;
    }
    
    if (!verificarNumero(data)) {
        return 0;
    }
    
    int dia, mes, ano;
    char data_copia[11];
    strcpy(data_copia, data);
    
    char *token = strtok(data_copia, "/");
    dia = strtol(token, NULL, 10);
    
    token = strtok(NULL, "/");
    mes = strtol(token, NULL, 10);
    
    token = strtok(NULL, "/");
    ano = strtol(token, NULL, 10);
    
    
    if (mes < 1 || mes > 12) return 0;
    if (ano < 0000 || ano > 2900) return 0;
    
    int dias_no_mes;
    switch (mes) {
        case 2:
            if ((ano % 4 == 0 && ano % 100 != 0) || (ano % 400 == 0)) {
                dias_no_mes = 29;
            } else {
                dias_no_mes = 28;
            }
            break;
        case 4:
            dias_no_mes = 30;
            break;

        case 6:
            dias_no_mes = 30;
            break;
        case 9:

            dias_no_mes = 30;
            break;

        case 11:
            dias_no_mes = 30;
            break;

        default:
            dias_no_mes = 31;
            break;
    }
    
    if (dia < 1 || dia > dias_no_mes) return 0;
    
    return 1;
}

int validarCNH(char *cnh) {
    if (cnh == NULL) {
        return 0;
    }

    int len = strlen(cnh);
    if (len != 11) {
        return 0;
    }

    for (int i = 0; i < len; i++) {
        if (!ehDigito(cnh[i])) {
            return 0;
        }
    }

    int todos_iguais = 1;
    for (int i = 1; i < len; i++) {
        if (cnh[i] != cnh[0]) {
            todos_iguais = 0;
            break;
        }
    }
    if (todos_iguais) {
        return 0;
    }

    return 1;
}

int validarIDaluguel(char *id) {
    if (strlen(id) != 11) return 0;
    for (int i = 0; i < 11; i++) {
        if (!ehDigito(id[i])) return 0;
    }
    return 1;
}

// ==============================
//    VALIDAÇÕES DE VEÍCULOS
// ==============================

int validarPlaca(char *placa) {
    int len = strlen(placa);
    if (len != 7) return 0;

    if (ehLetra(placa[0]) && ehLetra(placa[1]) && ehLetra(placa[2]) &&
        ehDigito(placa[3]) && ehDigito(placa[4]) && ehDigito(placa[5]) && ehDigito(placa[6]))
        return 1;

    return 0;
}

int validarChassi(char *chassi) {
    if (strlen(chassi) != 17) return 0;
    for (int i = 0; i < 17; i++) {
        char c = chassi[i];
        if (!(ehLetra(c) || ehDigito(c))) return 0;
        if (c == 'I' || c == 'O' || c == 'Q') return 0;
    }
    return 1;
}

int validarRenavam(char *renavam) {

    if (strlen(renavam) != 11) return 0;
    for (int i = 0; i < 11; i++) {
        if (!ehDigito(renavam[i])) return 0;
    }
    return 1;
}

int validarCategoria(char *categoria) {
    int len = strlen(categoria);
    if (len == 0 || len > 6) return 0;
    for (int i = 0; i < len; i++) {
        if (!(categoria[i] >= 'A' && categoria[i] <= 'Z')) return 0;
    }
    return 1;
}

int validarModelo(char *modelo) {
    int len = strlen(modelo);
    if (len == 0 || len > 30) return 0;
    for (int i = 0; i < len; i++) {
        if (!(ehLetra(modelo[i]) || ehDigito(modelo[i]) || modelo[i] == ' ')) return 0;
    }
    return 1;
}

int validarMarca(char *marca) {
    int len = strlen(marca);
    if (len == 0 || len > 15) return 0;
    for (int i = 0; i < len; i++) {
        if (!(ehLetra(marca[i]) || marca[i] == ' ')) return 0;
    }
    return 1;
}

int validarAno(char *ano) {
    if (strlen(ano) != 4) return 0;
    for (int i = 0; i < 4; i++) {
        if (!ehDigito(ano[i])) return 0;
    }
    int valor = atoi(ano);
    return (valor >= 1900 && valor <= 2025);
}

int validarCodigoInterno(char *codigo) {
    int len = strlen(codigo);
    if (len == 0 || len > 6) return 0;
    for (int i = 0; i < len; i++) {
        if (!(ehLetra(codigo[i]) || ehDigito(codigo[i]))) return 0;
    }
    return 1;
}

int validarPreco(float preco) {
    return (preco > 0);
}

