#ifndef VALIDACAO_H
#define VALIDACAO_H

int ehLetra(char c);
int ehDigito(char c);

int validarNome(const char *str);
int validarCPF(const char *str);
int validarData(const char *str);
int validarEmail(const char *str);
int validarCNH(char *cnh);
int validarIDaluguel(char *id);

int validarPlaca(char *placa);
int validarChassi(char *chassi);
int validarRenavam(char *renavam);
int validarCategoria(char *categoria);
int validarModelo(char *modelo);
int validarMarca(char *marca);
int validarAno(char *ano);
int validarCodigoInterno(char *codigo);
int validarPreco(float preco);

#endif