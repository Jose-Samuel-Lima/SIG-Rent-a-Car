#ifndef VALIDACAO_H
#define VALIDACAO_H

int ehLetra(char c);
int ehDigito(char c);

int validarNome(char *nome);
int validarCPF(char *cpf);
int validarEmail(char *email);
int validarData(char *data);

#endif