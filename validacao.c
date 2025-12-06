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

int validarNome(const char *nome) {
    if (nome == NULL) return 0;
    for (int i = 0; nome[i] != '\0'; i++) {
        if (!(ehLetra(nome[i]) || nome[i] == ' ')) {
            return 0;
        }
    }
    return 1;
}

int validarCPF(const char *cpf) {
    int cont = 0;
    for (int i = 0; cpf[i] != '\0'; i++) {
        if (ehDigito(cpf[i])) cont++;
        else if (cpf[i] != '.' && cpf[i] != '-') return 0;
    }
    return (cont == 11);
}

int validarEmail(const char *email) {
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

int verificarNumero(const char *entrada) {
    for (int i = 0; entrada[i] != '\0'; i++) {
        if (entrada[i] != '/' && !ehDigito(entrada[i])) {
            return 0;
        }
    }
    return 1;
}

// https://pt.stackoverflow.com/questions/213423/verificar-se-uma-data-é-válida-ou-não-em-c
// Código original que foi utilizado para complementar validarData.
// Autor: Mercador; Perfil: https://pt.stackoverflow.com/users/17607/mercador

int validarData(const char *data) {
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

int validarCNH(const char *cnh) {
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

int validarPlaca(const char *placa_veiculo) {
    if (placa_veiculo == NULL) return 0;
    int len = strlen(placa_veiculo);
    if (len != 7) return 0;

    if (ehLetra(placa_veiculo[0]) && ehLetra(placa_veiculo[1]) && ehLetra(placa_veiculo[2]) &&
        ehDigito(placa_veiculo[3]) && ehDigito(placa_veiculo[4]) && ehDigito(placa_veiculo[5]) && ehDigito(placa_veiculo[6]))
        return 1;

    return 0;
}

int validarChassi(const char *chassi_veiculo) {
    if (strlen(chassi_veiculo) != 17) return 0;

    for (int i = 0; i < 17; i++) {
        char c = chassi_veiculo[i];
        if (!(ehLetra(c) || ehDigito(c))) return 0;
        if (c == 'I' || c == 'O' || c == 'Q') return 0;
    }
    return 1;
}

int validarRenavam(const char *renavam_veiculo) {
    if (strlen(renavam_veiculo) != 11) return 0;

    for (int i = 0; i < 11; i++) {
        if (!ehDigito(renavam_veiculo[i])) return 0;
    }
    return 1;
}

int validarCategoria(const char *categoria_veiculo) {
    int len = strlen(categoria_veiculo);
    if (len == 0 || len > 6) return 0;

    for (int i = 0; i < len; i++) {
        if (!(categoria_veiculo[i] >= 'A' && categoria_veiculo[i] <= 'Z')) return 0;
    }
    return 1;
}

int validarModelo(const char *modelo_veiculo) {
    int len = strlen(modelo_veiculo);
    if (len == 0 || len > 30) return 0;

    for (int i = 0; i < len; i++) {
        if (!(ehLetra(modelo_veiculo[i]) || ehDigito(modelo_veiculo[i]) || modelo_veiculo[i] == ' '))
            return 0;
    }
    return 1;
}

int validarMarca(const char *marca_veiculo) {
    int len = strlen(marca_veiculo);
    if (len == 0 || len > 15) return 0;

    for (int i = 0; i < len; i++) {
        if (!(ehLetra(marca_veiculo[i]) || marca_veiculo[i] == ' '))
            return 0;
    }
    return 1;
}

int validarAno(const char *ano_veiculo) {
    if (strlen(ano_veiculo) != 4) return 0;

    for (int i = 0; i < 4; i++) {
        if (!ehDigito(ano_veiculo[i])) return 0;
    }

    int valor = atoi(ano_veiculo);
    return (valor >= 1900 && valor <= 2025);
}

int validarCodigoInterno(const char *codigo_interno_veiculo) {
    int len = strlen(codigo_interno_veiculo);
    if (len == 0 || len > 6) return 0;

    for (int i = 0; i < len; i++) {
        if (!(ehLetra(codigo_interno_veiculo[i]) || ehDigito(codigo_interno_veiculo[i])))
            return 0;
    }
    return 1;
}

int validarPreco(float preco_veiculo) {
    return preco_veiculo > 0;
}
