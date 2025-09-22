# SIG-Rent-a-Car 

Projeto de locadora de veículos Universidade do Rio Grande do Norte \ 
Centro de Ensino Superior do Seridó \ 
Departamento de Computação e Tecnologia \ 
Bacharelado em Sistemas de Informação Disciplina DCT1106 - Programação \ 
Developed by @j.samuel007 & @icarononato23 - since Aug/2025

## Sobre o Projeto

Programa para fins didáticos, feito por Ícaro Nonato e José Samuel durante a disciplina DCT1106 - Programação do curso de Bacharelado em Sistemas de Informação da Universidade Federal do Rio Grande do Norte.
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


