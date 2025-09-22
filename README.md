Claro! Vou deixar o README mais compacto, direto ao ponto, mas mantendo as informações essenciais e explicativas. Aqui está uma versão mais enxuta e objetiva:

---

# SIG-Rent-a-Car

**Projeto de locadora de veículos desenvolvido para fins didáticos**
Universidade Federal do Rio Grande do Norte – Curso de Sistemas de Informação
Disciplina DCT1106 - Programação
Autores: Ícaro Nonato (@icarononato23) & José Samuel (@j.samuel007) — desde Ago/2025

---

## Sobre o Projeto

SIG-Rent-a-Car é um sistema simples, desenvolvido em **C**, que simula o gerenciamento de uma locadora de veículos. O projeto inclui os principais módulos para controlar clientes, funcionários, veículos, aluguéis e relatórios, com foco em operações básicas de cadastro, pesquisa, alteração e exclusão de dados.

**Atenção:**
Este sistema é didático, não comercial, e não garante funcionamento em ambientes reais. Os autores não se responsabilizam por quaisquer danos decorrentes do uso do código.

---

## Módulos e Funcionalidades

* **Cliente, Funcionário, Veículo e Aluguéis:**
  Cada módulo permite:

  * Cadastrar novos registros
  * Pesquisar dados existentes
  * Alterar informações
  * Excluir registros

* **Relatórios:**
  Geração de relatórios resumidos sobre veículos, aluguéis e faturamento.

---

## Estrutura do Código

* Código modular em C, organizado em arquivos específicos para cada módulo (ex: clientes.c, veiculos.c).
* Estruturas definidas em structs.h.
* Manipulação de dados via arquivos texto para persistência.
* Funções auxiliares em utils.c.

---

## Como Compilar e Executar

O projeto inclui um **Makefile** para facilitar:

1. No terminal, dentro da pasta do projeto, compile com:

   ```bash
   make
   ```

2. Execute o programa:

   ```bash
   ./sig-rentacar
   ```

3. Para limpar arquivos objeto e binários gerados:

   ```bash
   make clean
   ```

---

## Futuras Melhorias

* Integração com banco de dados real (MySQL, SQLite).
* Interface gráfica (GTK, ncurses).
* Sistema de autenticação e permissões.
* Relatórios mais detalhados (manutenção, histórico).

---

## Licença

Projeto sob **Licença MIT**. Consulte o arquivo `LICENSE` para detalhes.

---

Qualquer dúvida ou sugestão, estamos à disposição!

---

Quer que eu ajude a montar o conteúdo do Makefile também? Ou algum outro ajuste?
