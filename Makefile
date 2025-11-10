# Variáveis
CC = gcc
CFLAGS = -Iinclude -Wall -Wextra

# Arquivos do projeto
SRC = $(wildcard *.c) $(wildcard include/*.h) $(wildcard src/*.c)
OUT = test.exe

# Regra padrão
all:
	$(CC) $(SRC) -o $(OUT) $(CFLAGS)

# Atalho para compilar e rodar
run: all
	./$(OUT)

# Limpa o executável
clean:
	rm -f $(OUT)
