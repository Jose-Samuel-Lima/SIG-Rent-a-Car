#ifndef VALIDACAO_H
#define VALIDACAO_H

int ehLetra(char c);
int ehDigito(char c);

int validarNome(char *nome);
int validarCPF(char *cpf);
int validarEmail(char *email);
int validarData(char *data);
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