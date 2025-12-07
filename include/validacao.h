#ifndef VALIDACAO_H
#define VALIDACAO_H

int ehLetra(char c);
int ehDigito(char c);

int validarNome(const char *nome);
int validarCPF(const char *cpf);
int validarEmail(const char *email);
int validarTelefone(const char *telefone);
int validarCNH(const char *cnh);

int validarPlaca(const char *placa);
int validarModelo(const char *modelo);
int validarMarca(const char *marca);
int validarAno(const char *ano);
int validarPreco(float preco);

int validarData(const char *data);
int verificarNumero(const char *str);

#endif
