#ifndef VALIDACAO_H
#define VALIDACAO_H

int ehLetra(char c);
int ehDigito(char c);

int validarNome(const char *nome);
int validarCPF(const char *cpf);
int validarData(const char *data);
int validarEmail(const char *email);
int validarCNH(const char *cnh);
int validarIDaluguel(char *id);

int validarPlaca(const char *placa);
int validarChassi(const char *chassi);
int validarRenavam(const char *renavam);
int validarCategoria(const char *categoria);
int validarModelo(const char *modelo);
int validarMarca(const char *marca);
int validarAno(const char *ano);
int validarCodigoInterno(const char *codigo);
int validarPreco(float preco);

#endif
