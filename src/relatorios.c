// =============================================|
// SEÇÃO DE INCLUDE DE RELATÓRIOS.C             |
// =============================================|

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

#include "funcionarios.h"
#include "clientes.h"
#include "veiculos.h"
#include "relatorios.h"
#include "alugueis.h"

// =============================================|
// MÓDULO DE TELA E NAVEGAÇÃO DE RELATÓRIOS.C   |
// =============================================|

int modulo_relatorio(void)
{
    int esc;
    do
    {
        esc = modulo_tela_relatorio();
        switch (esc)
        {
        case 1:
            navegar_relatorio_funcionarios();
            break;
        case 2:
            navegar_relatorio_clientes();
            break;
        case 3:
            navegar_relatorio_veiculos();
            break;
        case 4:
            navegar_relatorio_alugueis();
            break;
        case 0:
            return -1;
        }

    } while (esc != 0);
    return -1;
}

int navegar_relatorio_funcionarios(void)
{ 
    int esc_funcionario;
    do
    {
        esc_funcionario = modulo_relatorio_funcionarios();
        switch(esc_funcionario)
        {
        case 1: 
            funcionarios_ativos();
            break;
        case 2:
            funcionarios_inativos();
            break;
        case 3:
            funcionarios_por_cargo();
            break;
        case 0:
            return -1;
        }
    } while (esc_funcionario != 0);
    return -1;
}

int navegar_relatorio_clientes(void)
{ 
    int esc_cliente;
    do
    {
        esc_cliente = modulo_relatorio_clientes();
        switch(esc_cliente)
        {
        case 1: 
            clientes_ativos();
            break;
        case 2:
            clientes_inativos();
            break;
        case 3:
            clientes_por_nome();
            break;
        case 0:
            return -1;
        }
    } while (esc_cliente != 0);
    return -1;
}

int navegar_relatorio_veiculos(void)
{ 
    int esc_veiculos;
    do
    {
        esc_veiculos = modulo_relatorio_veiculos();
        switch(esc_veiculos)
        {
        case 1: 
            veiculos_ativos();
            break;
        case 2: 
            veiculos_inativos();
            break;
        case 3: 
            veiculos_por_marca();
            break;
        case 0:
            return -1;
        }
    } while (esc_veiculos != 0);
    return -1;
}

int navegar_relatorio_alugueis(void)
{ 
    int esc_alugueis;
    do
    {
        esc_alugueis = modulo_relatorio_alugueis();
        switch(esc_alugueis)
        {
        case 1: 
            alugueis_ativos();
            break;
        case 2: 
            alugueis_inativos();
            break;
        case 3: 
            alugueis_por_cliente();
            break;
        case 0:
            return -1;
        }
    } while (esc_alugueis != 0);
    return -1;
}


int modulo_tela_relatorio(void)
{
    int op;
    int c;

    system("clear||cls");
    printf("\n");
    printf("#=====================================================================#\n");
    printf("|                        --------------------                         |\n");
    printf("|                        | SIG - Rent a Car |                         |\n");
    printf("|                        --------------------                         |\n");
    printf("#=====================================================================#\n");
    printf("|                         MÓDULO RELATÓRIOS                           |\n");
    printf("|---------------------------------------------------------------------|\n");
    printf("|                   [1] - Relatório de funcionários                   |\n");
    printf("|                   [2] - Relatório de clientes                       |\n");
    printf("|                   [3] - Relatório de veículos                       |\n");
    printf("|                   [4] - Relatório de aluguéis                       |\n");
    printf("|---------------------------------------------------------------------|\n");
    printf("|                   [0] - Sair                                        |\n");
    printf("#=====================================================================#\n");
    printf("\n");
    printf("Escolha uma das opções acima: \n");
    scanf(" %d", &op);
    while ((c = getchar()) != '\n' && c != EOF)
        ;
    printf("\n");
    printf("Processando...\n");
    return op;
}

int modulo_relatorio_funcionarios(void)
{
    int op;
    int c;

    system("clear||cls");
    printf("\n");
    printf("#=====================================================================#\n");
    printf("|                        --------------------                         |\n");
    printf("|                        | SIG - Rent a Car |                         |\n");
    printf("|                        --------------------                         |\n");
    printf("#=====================================================================#\n");
    printf("|                      RELATÓRIO DE FUNCIONÁRIOS                      |\n");
    printf("|---------------------------------------------------------------------|\n");
    printf("|                   [1] - Listar Funcionários Ativos                  |\n");
    printf("|                   [2] - Listar Funcionários Inativos                |\n");
    printf("|                   [3] - Filtrar Funcionários por Cargo              |\n");
    printf("|---------------------------------------------------------------------|\n");
    printf("|                   [0] - Sair                                        |\n");
    printf("#=====================================================================#\n");

    printf("\n");
    printf("Escolha uma das opções acima: ");
    scanf(" %d", &op);
    while ((c = getchar()) != '\n' && c != EOF)
        ;
    printf("\n");
    printf("Processando...\n");
    return op;
}

int modulo_relatorio_clientes(void)
{
    int op;
    int c; 

    system("clear||cls");
    printf("\n");
    printf("#=====================================================================#\n");
    printf("|                        --------------------                         |\n");
    printf("|                        | SIG - Rent a Car |                         |\n");
    printf("|                        --------------------                         |\n");
    printf("#=====================================================================#\n");
    printf("|                       RELATÓRIO DE CLIENTES                         |\n");
    printf("|---------------------------------------------------------------------|\n");
    printf("|                   [1] - Listar Clintes Ativos                       |\n");
    printf("|                   [2] - Listar Clientes Inativos                    |\n");
    printf("|                   [3] - Filtrar Clientes por Nome                   |\n");
    printf("|---------------------------------------------------------------------|\n");
    printf("|                   [0] - Sair                                        |\n");
    printf("#=====================================================================#\n");
    printf("\n");
    printf("Escolha uma das opções acima: ");
    scanf(" %d", &op);
    while ((c = getchar()) != '\n' && c != EOF)
        ;
    printf("\n");
    printf("Processando...\n");
    return op;
}

int modulo_relatorio_veiculos(void)
{
    int op; 
    int c;

    system("clear||cls");
    printf("\n");
    printf("#=====================================================================#\n");
    printf("|                        --------------------                         |\n");
    printf("|                        | SIG - Rent a Car |                         |\n");
    printf("|                        --------------------                         |\n");
    printf("#=====================================================================#\n");
    printf("|                        RELATÓRIO DE VEÍCULOS                        |\n");
    printf("|---------------------------------------------------------------------|\n");
    printf("|                   [1] - Listar Veículos Ativos                      |\n");
    printf("|                   [2] - Listar Veículos Inativos                    |\n");
    printf("|                   [3] - Filtrar Veículos por Marca                  |\n");
    printf("|---------------------------------------------------------------------|\n");
    printf("|                   [0] - Sair                                        |\n");
    printf("#=====================================================================#\n");
    printf("\n");
    printf("Escolha uma das opções acima: ");
    scanf(" %d", &op);
    while ((c = getchar()) != '\n' && c != EOF)
        ;
    printf("\n");
    printf("Processando...\n");
    return op;
}

int modulo_relatorio_alugueis(void)
{
    int op; 
    int c;

    system("clear||cls");
    printf("\n");
    printf("#=====================================================================#\n");
    printf("|                        --------------------                         |\n");
    printf("|                        | SIG - Rent a Car |                         |\n");
    printf("|                        --------------------                         |\n");
    printf("#=====================================================================#\n");
    printf("|                        RELATÓRIO DE ALUGUEIS                        |\n");
    printf("|---------------------------------------------------------------------|\n");
    printf("|                   [1] - Listar Alugueis Ativos                      |\n");
    printf("|                   [2] - Listar Alugueis Inativos                    |\n");
    printf("|                   [3] - Filtrar Alugueis por Cliente                |\n");
    printf("|---------------------------------------------------------------------|\n");
    printf("|                   [0] - Sair                                        |\n");
    printf("#=====================================================================#\n");
    printf("\n");
    printf("Escolha uma das opções acima: ");
    scanf(" %d", &op);
    while ((c = getchar()) != '\n' && c != EOF)
        ;
    printf("\n");
    printf("Processando...\n");
    return op;
}

// |======================================|
// |       RELATÓRIO DE FUNCIONÁRIOS      |
// |======================================|

void funcionarios_ativos(void)
{
    Funcionario* fun = (Funcionario*) malloc(sizeof(Funcionario));
    Funcionario* lista_funcionario = NULL;
    Funcionario* ultimo = NULL;

    system("clear||cls");
    printf("\n");
    printf("#=========================================================================================================#\n");
    printf("|                                          FUNCIONÁRIOS ATIVOS                                            |\n");                
    printf("#=========================================================================================================#\n");

    FILE* arq_funcionario = fopen("funcionario.dat", "rb");
    if (!arq_funcionario) {
        printf("XXX - Nenhum arquivo de funcionários encontrado!\n");
        getchar();
        free(fun);
        return;
    }

    int contador = 0;

    // LISTA DINÂMICA DIRETA
    while (fread(fun, sizeof(Funcionario), 1, arq_funcionario)) {
        if (fun->status) {
            Funcionario* novo_func = (Funcionario*) malloc(sizeof(Funcionario));
            *novo_func = *fun;
            novo_func->prox_func = NULL;

            if (contador == 0) {
                lista_funcionario = novo_func;
                ultimo = novo_func;
            } else {
                ultimo->prox_func = novo_func;
                ultimo = novo_func;
            }

            contador++;
        }
    }

    fclose(arq_funcionario);
    free(fun);

    if (contador == 0) {
        printf("XXX - Nenhum funcionário ativo encontrado.\n");
        printf("\n[>] - Pressione ENTER para sair...");
        getchar();
        return;
    }

    // EXIBINDO LISTA EM FORMATO DE TABELA
    printf("+----------------------+----------------+----------------+---------------------------+----------------------+\n");
    printf("| NOME                 | CPF            | TELEFONE       | EMAIL                     | CARGO                |\n");
    printf("+----------------------+----------------+----------------+---------------------------+----------------------+\n");

    Funcionario* atual = lista_funcionario;
    while (atual) {
        printf("| %-20.20s | %-14.14s | %-14.14s | %-25.25s | %-20.20s |\n",
               atual->nome_funcionario,
               atual->cpf_funcionario,
               atual->telefone_funcionario,
               atual->email_funcionario,
               atual->cargo_funcionario);

        atual = atual->prox_func;
    }

    printf("+----------------------+----------------+----------------+---------------------------+----------------------+\n");
    printf("\nTotal de funcionários ativos: %d\n", contador);

    // LIBERANDO MEMÓRIA DA LISTA
    atual = lista_funcionario;
    while (atual) {
        Funcionario* prox_func = atual->prox_func;
        free(atual);
        atual = prox_func;
    }

    printf("\n[>] - Pressione ENTER para continuar...");
    getchar();
}

void funcionarios_inativos(void)
{
    FILE* arq_funcionario = fopen("funcionario.dat", "rb");
    Funcionario* fun;
    Funcionario* lista_funcionario = NULL;

    system("clear||cls");
    printf("\n");
    printf("#=========================================================================================================#\n");
    printf("|                                        FUNCIONÁRIOS INATIVOS                                            |\n");                
    printf("#=========================================================================================================#\n");

    if (!arq_funcionario) {
        printf("XXX - Nenhum arquivo de funcionários encontrado!\n");
        printf("\n[>] - Pressione ENTER para sair...");
        getchar();
        return;
    }

    fun = (Funcionario*) malloc(sizeof(Funcionario));
    int contador = 0;

    // LISTA DINÂMICA INVERSA
    while (fread(fun, sizeof(Funcionario), 1, arq_funcionario)) {
        if (!fun->status) {
            Funcionario* novo_func = (Funcionario*) malloc(sizeof(Funcionario));
            *novo_func = *fun;
            novo_func->prox_func = lista_funcionario;
            lista_funcionario = novo_func;
            contador++;
        }
    }

    fclose(arq_funcionario);
    free(fun);

    if (contador == 0) {
        printf("XXX - Nenhum funcionário inativo encontrado.\n");
        printf("\n[>] - Pressione ENTER para sair...");
        getchar();
        return;
    }

    // EXIBINDO LISTA EM FORMATO DE TABELA
    printf("+----------------------+----------------+----------------+---------------------------+----------------------+\n");
    printf("| NOME                 | CPF            | TELEFONE       | EMAIL                     | CARGO                |\n");
    printf("+----------------------+----------------+----------------+---------------------------+----------------------+\n");

    Funcionario* atual = lista_funcionario;
    while (atual) {
        printf("| %-20.20s | %-14.14s | %-14.14s | %-25.25s | %-20.20s |\n",
               atual->nome_funcionario,
               atual->cpf_funcionario,
               atual->telefone_funcionario,
               atual->email_funcionario,
               atual->cargo_funcionario);

        atual = atual->prox_func;
    }

    printf("+----------------------+----------------+----------------+---------------------------+----------------------+\n");
    printf("\nTotal de funcionários inativos: %d\n", contador);

    // LIBERANDO MEMÓRIA DA LISTA
    atual = lista_funcionario;
    while (atual) {
        Funcionario* prox_func = atual->prox_func;
        free(atual);
        atual = prox_func;
    }

    printf("\n[>] - Pressione ENTER para continuar...");
    getchar();
}

void filtrar_funcionario_cargo(char* cargo_funcionario)
{
    FILE* arq_funcionario = fopen("funcionario.dat", "rb");
    Funcionario* fun;
    int contador = 0;

    system("clear||cls");
    printf("\n");
    printf("#=======================================================================#\n");
    printf("|                  < = = = Funcionários por Cargo = = = >               |\n");
    printf("#=======================================================================#\n");

    if (!arq_funcionario) {
        printf("XXX - Arquivo de funcionários não encontrado!\n");
        printf("\n[>] - Pressione ENTER para continuar...");
        getchar();
        return;
    }

    fun = (Funcionario*) malloc(sizeof(Funcionario));
    printf("\n[>] - Funcionários com o cargo: %s\n\n", cargo_funcionario);

    // Cabeçalho tabela
    printf("+----------------------+----------------+----------------+---------------------------+----------------------+\n");
    printf("| NOME                 | CPF            | TELEFONE       | EMAIL                     | CARGO                |\n");
    printf("+----------------------+----------------+----------------+---------------------------+----------------------+\n");

    while (fread(fun, sizeof(Funcionario), 1, arq_funcionario)) {
        if (fun->status) {
            char cargo_temp[51];
            strcpy(cargo_temp, fun->cargo_funcionario);
            str_to_lower(cargo_temp);

            if (strstr(cargo_temp, cargo_funcionario) != NULL) {
                contador++;
                printf("| %-20.20s | %-14.14s | %-14.14s | %-25.25s | %-20.20s |\n",
                       fun->nome_funcionario,
                       fun->cpf_funcionario,
                       fun->telefone_funcionario,
                       fun->email_funcionario,
                       fun->cargo_funcionario);
            }
        }
    }

    if (contador == 0) {
        printf("|                           Nenhum funcionário encontrado!                           |\n");
    }

    printf("+----------------------+----------------+----------------+---------------------------+----------------------+\n");
    printf("\nTotal de funcionários encontrados: %d\n", contador);

    fclose(arq_funcionario);
    free(fun);

    printf("\n[>] - Pressione ENTER para continuar...");
    getchar();
}

void funcionarios_por_cargo(void)
{
    char cargo_busca[51];
    int c;

    system("clear||cls");
    printf("\n");
    printf("#=======================================================================#\n");
    printf("|                           FILTRAGEM POR CARGO                         |\n");
    printf("#=======================================================================#\n");

    printf("\nDigite o cargo que deseja buscar: ");
    scanf("%50[^\n]", cargo_busca);
    while ((c = getchar()) != '\n' && c != EOF);

    str_to_lower(cargo_busca);
    filtrar_funcionario_cargo(cargo_busca);
}

// |======================================|
// |        RELATÓRIO DE CLIENTES         |
// |======================================|

void clientes_ativos(void)
{
    Cliente* cli = (Cliente*) malloc(sizeof(Cliente));
    Cliente* lista_cliente = NULL;
    Cliente* ultimo = NULL;

    system("clear||cls");
    printf("\n");
    printf("#=========================================================================================================#\n");
    printf("|                                          CLIENTES ATIVOS                                                |\n");                
    printf("#=========================================================================================================#\n");
    printf("\n");
    
    FILE* arq_cliente = fopen("cliente.dat","rb");
    if (!arq_cliente) {
        printf("XXX - Nenhum arquivo de clientes encontrado!\n");
        getchar();
        free(cli);
        return;
    }

    int contador = 0;

    // LISTA DINÂMICA DIRETA
    while (fread(cli, sizeof(Cliente), 1, arq_cliente)) {
        if (cli->status) {
            Cliente* novo_cli = (Cliente*) malloc(sizeof(Cliente));
            *novo_cli = *cli;
            novo_cli->prox_cli = NULL;

            if (contador == 0) {
                lista_cliente = novo_cli;
                ultimo = novo_cli;
            } else {
                ultimo->prox_cli = novo_cli;
                ultimo = novo_cli;
            }

            contador++;
        }
    }

    fclose(arq_cliente);
    free(cli);

    if (contador == 0) {
        printf("XXX - Nenhum cliente ativo encontrado.\n");
        printf("\nPressione ENTER para continuar...");
        getchar();
        return;
    }

    // EXIBINDO LISTA EM FORMATO DE TABELA
    printf("+----------------------+----------------+----------------+---------------------------+-----------------+\n");
    printf("| NOME                 | CPF            | TELEFONE       | EMAIL                     | CNH             |\n");
    printf("+----------------------+----------------+----------------+---------------------------+-----------------+\n");

    Cliente* atual = lista_cliente;
    while (atual) {
        printf("| %-20.20s | %-14.14s | %-14.14s | %-25.25s | %-15.15s |\n",
               atual->nome_cliente,
               atual->cpf_cliente,
               atual->telefone_cliente,
               atual->email_cliente,
               atual->cnh_cliente);

        atual = atual->prox_cli;
    }

    printf("+----------------------+----------------+----------------+---------------------------+-----------------+\n");
    printf("\nTotal de clientes ativos: %d\n", contador);

    // LIBERANDO MEMÓRIA DA LISTA
    atual = lista_cliente;
    while (atual) {
        Cliente* prox_cli = atual->prox_cli;
        free(atual);
        atual = prox_cli;
    }

    printf("\nPressione ENTER para continuar...");
    getchar();
}

void clientes_inativos(void)
{
    FILE *arq_cliente = fopen("cliente.dat","rb");
    Cliente* cli;
    Cliente* lista_cliente = NULL;

    system("clear||cls");
    printf("\n");
    printf("#=========================================================================================================#\n");
    printf("|                                        CLIENTES INATIVOS                                               |\n");                
    printf("#=========================================================================================================#\n");
    printf("\n");
    
    if (!arq_cliente) {
        printf("XXX - Nenhum arquivo de clientes encontrado!\n");
        printf("[>] - Pressione Enter para continuar...");
        getchar();
        return;
    }

    cli = (Cliente*) malloc(sizeof(Cliente));
    int contador = 0;

    // LISTA DINÂMICA INVERSA
    while (fread(cli, sizeof(Cliente), 1, arq_cliente)) {
        if (!cli->status) {
            Cliente* novo_cli = (Cliente*) malloc(sizeof(Cliente));
            *novo_cli = *cli;
            novo_cli->prox_cli = lista_cliente;
            lista_cliente = novo_cli;
            contador++;
        }
    }

    fclose(arq_cliente);
    free(cli);

    if (contador == 0) {
        printf("XXX - Nenhum cliente inativo encontrado!\n");
        printf("\n[>] - Pressione Enter para sair...");
        getchar();
        return;
    }

    // EXIBINDO LISTA EM FORMATO DE TABELA
    printf("+----------------------+----------------+----------------+---------------------------+-----------------+\n");
    printf("| NOME                 | CPF            | TELEFONE       | EMAIL                     | CNH             |\n");
    printf("+----------------------+----------------+----------------+---------------------------+-----------------+\n");

    Cliente* atual = lista_cliente;
    while (atual) {
        printf("| %-20.20s | %-14.14s | %-14.14s | %-25.25s | %-15.15s |\n",
               atual->nome_cliente,
               atual->cpf_cliente,
               atual->telefone_cliente,
               atual->email_cliente,
               atual->cnh_cliente);

        atual = atual->prox_cli;
    }

    printf("+----------------------+----------------+----------------+---------------------------+-----------------+\n");
    printf("\nTotal de clientes inativos: %d\n", contador);

    // LIBERANDO MEMÓRIA DA LISTA
    atual = lista_cliente;
    while (atual) {
        Cliente* prox_cli = atual->prox_cli;
        free(atual);
        atual = prox_cli;
    }

    printf("\n[>] - Pressione Enter para sair...");
    getchar();
}

void filtrar_cliente_nome(char* nome_cliente)
{
    FILE *arq_cliente = fopen("cliente.dat","rb");
    Cliente* cli;
    int contador = 0;

    system("clear||cls");
    printf("\n");
    printf("#=======================================================================#\n");
    printf("|                           FILTRAGEM POR NOME                          |\n");
    printf("#=======================================================================#\n");

    if (!arq_cliente) {
        printf("XXX - Arquivo de Clientes não encontrado!\n");
        printf("[>] - Pressione Enter para continuar...");
        getchar();
        return;
    }

    cli = (Cliente*) malloc(sizeof(Cliente));
    printf("\n[>] - Clientes com o nome: %s\n\n", nome_cliente);

    // Cabeçalho tabela
    printf("+----------------------+----------------+----------------+---------------------------+-----------------+\n");
    printf("| NOME                 | CPF            | TELEFONE       | EMAIL                     | CNH             |\n");
    printf("+----------------------+----------------+----------------+---------------------------+-----------------+\n");

    while (fread(cli, sizeof(Cliente), 1, arq_cliente)) {
        if (cli->status) {
            char nome_temp[51];
            strcpy(nome_temp, cli->nome_cliente);
            str_to_lower(nome_temp);

            if (strstr(nome_temp, nome_cliente) != NULL) {
                contador++;
                printf("| %-20.20s | %-14.14s | %-14.14s | %-25.25s | %-15.15s |\n",
                       cli->nome_cliente,
                       cli->cpf_cliente,
                       cli->telefone_cliente,
                       cli->email_cliente,
                       cli->cnh_cliente);
            }
        }
    }

    if (contador == 0) {
        printf("|                           Nenhum cliente encontrado!                           |\n");
    }

    printf("+----------------------+----------------+----------------+---------------------------+-----------------+\n");
    printf("\nTotal de clientes encontrados: %d\n", contador);

    fclose(arq_cliente);
    free(cli);

    printf("\n[>] - Pressione Enter para sair...");
    getchar();
}

void clientes_por_nome(void)
{
    char nome_busca[51];
    int c;

    system("clear||cls");
    printf("\n");
    printf("#=======================================================================#\n");
    printf("|                           FILTRAGEM POR NOME                          |\n");
    printf("#=======================================================================#\n");
    printf("\n");

    printf("Digite o nome que deseja buscar: ");
    scanf("%50[^\n]", nome_busca); 
    while ((c = getchar()) != '\n' && c != EOF);

    str_to_lower(nome_busca);

    filtrar_cliente_nome(nome_busca);
}

// |======================================|
// |        RELATÓRIO DE VEÍCULOS         |
// |======================================|

void veiculos_ativos(void)
{
    Veiculo* vei = (Veiculo*) malloc(sizeof(Veiculo));
    Veiculo* lista_veiculo = NULL;
    Veiculo* ultimo = NULL;

    system("clear||cls");
    printf("\n");
    printf("#=======================================================================#\n");
    printf("|                            VEÍCULOS ATIVOS                             |\n");
    printf("#=======================================================================#\n\n");

    FILE* arq_veiculo = fopen("veiculo.dat", "rb");
    if (!arq_veiculo) {
        printf("XXX - Nenhum arquivo de veículos encontrado!\n");
        printf("\n[>] - Pressione Enter para continuar...");
        free(vei);
        getchar();
        return;
    }

    int contador = 0;

    // Criando lista dinâmica de veículos ativos
    while (fread(vei, sizeof(Veiculo), 1, arq_veiculo)) {
        if (vei->status) {
            Veiculo* novo_vei = (Veiculo*) malloc(sizeof(Veiculo));
            *novo_vei = *vei;
            novo_vei->prox_vei = NULL;

            if (contador == 0) {
                lista_veiculo = novo_vei;
                ultimo = novo_vei;
            } else {
                ultimo->prox_vei = novo_vei;
                ultimo = novo_vei;
            }
            contador++;
        }
    }

    fclose(arq_veiculo);
    free(vei);

    if (contador == 0) {
        printf("XXX - Nenhum veículo ativo encontrado!\n");
        printf("\n[>] - Pressione Enter para continuar...");
        getchar();
        return;
    }

    // EXIBINDO LISTA EM FORMATO DE TABELA
    printf("+------------+-----------------+-----------------+--------+------------+\n");
    printf("| PLACA      | MODELO          | MARCA           | ANO    | PREÇO      |\n");
    printf("+------------+-----------------+-----------------+--------+------------+\n");

    Veiculo* atual = lista_veiculo;
    while (atual) {
        printf("| %-10.10s | %-15.15s | %-15.15s | %-6.6s | R$ %-9.2f |\n",
               atual->placa_veiculo,
               atual->modelo_veiculo,
               atual->marca_veiculo,
               atual->ano_veiculo,
               atual->preco_veiculo);

        atual = atual->prox_vei;
    }

    printf("+------------+-----------------+-----------------+--------+------------+\n");
    printf("\nTotal de veículos ativos: %d\n", contador);

    // LIBERANDO MEMÓRIA
    atual = lista_veiculo;
    while (atual) {
        Veiculo* prox = atual->prox_vei;
        free(atual);
        atual = prox;
    }

    printf("\n[>] - Pressione Enter para continuar...");
    getchar();
}

void veiculos_inativos(void)
{
    Veiculo* vei = (Veiculo*) malloc(sizeof(Veiculo));
    Veiculo* lista_veiculo = NULL;
    Veiculo* ultimo = NULL;

    system("clear||cls");
    printf("\n");
    printf("#=======================================================================#\n");
    printf("|                          VEÍCULOS INATIVOS                             |\n");
    printf("#=======================================================================#\n\n");

    FILE* arq_veiculo = fopen("veiculo.dat", "rb");
    if (!arq_veiculo) {
        printf("XXX - Nenhum arquivo de veículos encontrado!\n");
        printf("\n[>] - Pressione Enter para continuar...");
        free(vei);
        getchar();
        return;
    }

    int contador = 0;

    while (fread(vei, sizeof(Veiculo), 1, arq_veiculo)) {
        if (!vei->status) {
            Veiculo* novo_vei = (Veiculo*) malloc(sizeof(Veiculo));
            *novo_vei = *vei;
            novo_vei->prox_vei = NULL;

            if (contador == 0) {
                lista_veiculo = novo_vei;
                ultimo = novo_vei;
            } else {
                ultimo->prox_vei = novo_vei;
                ultimo = novo_vei;
            }
            contador++;
        }
    }

    fclose(arq_veiculo);
    free(vei);

    if (contador == 0) {
        printf("XXX - Nenhum veículo inativo encontrado!\n");
        printf("\n[>] - Pressione Enter para continuar...");
        getchar();
        return;
    }

    printf("+------------+-----------------+-----------------+--------+------------+\n");
    printf("| PLACA      | MODELO          | MARCA           | ANO    | PREÇO      |\n");
    printf("+------------+-----------------+-----------------+--------+------------+\n");

    Veiculo* atual = lista_veiculo;
    while (atual) {
        printf("| %-10.10s | %-15.15s | %-15.15s | %-6.6s | R$ %-9.2f |\n",
               atual->placa_veiculo,
               atual->modelo_veiculo,
               atual->marca_veiculo,
               atual->ano_veiculo,
               atual->preco_veiculo);
        atual = atual->prox_vei;
    }

    printf("+------------+-----------------+-----------------+--------+------------+\n");
    printf("\nTotal de veículos inativos: %d\n", contador);

    // LIBERANDO MEMÓRIA
    atual = lista_veiculo;
    while (atual) {
        Veiculo* prox = atual->prox_vei;
        free(atual);
        atual = prox;
    }

    printf("\n[>] - Pressione Enter para continuar...");
    getchar();
}

void filtrar_veiculo_marca(char* marca_veiculo)
{
    Veiculo* vei = (Veiculo*) malloc(sizeof(Veiculo));
    int contador = 0;

    FILE* arq_veiculo = fopen("veiculo.dat", "rb");
    if (!arq_veiculo) {
        printf("XXX - Arquivo de veículos não encontrado!\n");
        printf("\n[>] - Pressione Enter para continuar...");
        free(vei);
        getchar();
        return;
    }

    system("clear||cls");
    printf("\n");
    printf("#=======================================================================#\n");
    printf("|                  < = = = Veículos por Marca = = = >                   |\n");
    printf("#=======================================================================#\n\n");

    printf("[>] - Veículos da marca: %s\n\n", marca_veiculo);

    printf("+------------+-----------------+-----------------+--------+------------+\n");
    printf("| PLACA      | MODELO          | MARCA           | ANO    | PREÇO      |\n");
    printf("+------------+-----------------+-----------------+--------+------------+\n");

    while (fread(vei, sizeof(Veiculo), 1, arq_veiculo)) {
        if (vei->status) {
            char marca_temp[16];
            strcpy(marca_temp, vei->marca_veiculo);
            str_to_lower(marca_temp);

            if (strstr(marca_temp, marca_veiculo) != NULL) {
                contador++;
                printf("| %-10.10s | %-15.15s | %-15.15s | %-6.6s | R$ %-9.2f |\n",
                       vei->placa_veiculo,
                       vei->modelo_veiculo,
                       vei->marca_veiculo,
                       vei->ano_veiculo,
                       vei->preco_veiculo);
            }
        }
    }

    if (contador == 0) {
        printf("|                     Nenhum veículo encontrado!                        |\n");
    }

    printf("+------------+-----------------+-----------------+--------+------------+\n");
    printf("\nTotal de veículos encontrados: %d\n", contador);

    fclose(arq_veiculo);
    free(vei);

    printf("\n[>] - Pressione Enter para continuar...");
    getchar();
}

void veiculos_por_marca(void)
{
    char marca_busca[16];
    int c;

    system("clear||cls");
    printf("\n");
    printf("#=======================================================================#\n");
    printf("|                           FILTRAGEM POR MARCA                          |\n");
    printf("#=======================================================================#\n\n");

    printf("Digite a marca que deseja buscar: ");
    scanf("%15[^\n]", marca_busca);
    while ((c = getchar()) != '\n' && c != EOF);

    str_to_lower(marca_busca);
    filtrar_veiculo_marca(marca_busca);
}

// |======================================|
// |        RELATÓRIO DE ALUGUEIS         |
// |======================================|

void alugueis_ativos(void)
{
    Aluguel* al = (Aluguel*) malloc(sizeof(Aluguel));
    Aluguel* lista_aluguel = NULL;
    Aluguel* ultimo = NULL;

    system("clear||cls");
    printf("\n");
    printf("#=======================================================================#\n");
    printf("|                            ALUGUÉIS ATIVOS                             |\n");
    printf("#=======================================================================#\n\n");

    FILE* arq_aluguel = fopen("aluguel.dat", "rb");
    if (!arq_aluguel) {
        printf("XXX - Nenhum arquivo de aluguéis encontrado!\n");
        printf("\n[>] - Pressione Enter para continuar...");
        free(al);
        getchar();
        return;
    }

    int contador = 0;

    // Criando lista dinâmica de aluguéis ativos
    while (fread(al, sizeof(Aluguel), 1, arq_aluguel)) {
        if (al->status) {
            Aluguel* novo_al = (Aluguel*) malloc(sizeof(Aluguel));
            *novo_al = *al;
            novo_al->prox_alu = NULL;

            if (contador == 0) {
                lista_aluguel = novo_al;
                ultimo = novo_al;
            } else {
                ultimo->prox_alu = novo_al;
                ultimo = novo_al;
            }

            contador++;
        }
    }

    fclose(arq_aluguel);
    free(al);

    if (contador == 0) {
        printf("XXX - Nenhum aluguel ativo encontrado!\n");
        printf("\n[>] - Pressione Enter para continuar...");
        getchar();
        return;
    }

    // EXIBINDO TABELA
    printf("+------------+-----------------+-----------------+------------+------------+------------+\n");
    printf("| ID         | CPF CLIENTE     | PLACA VEÍCULO   | DATA INÍC. | DATA FIM   | VALOR R$   |\n");
    printf("+------------+-----------------+-----------------+------------+------------+------------+\n");

    Aluguel* atual = lista_aluguel;
    while (atual) {
        printf("| %-10.10s | %-15.15s | %-15.15s | %-10.10s | %-10.10s | R$ %-9.2f |\n",
               atual->id,
               atual->cpf_cliente,
               atual->placa_veiculo,
               atual->data_inicio,
               atual->data_fim,
               atual->valor_total);

        atual = atual->prox_alu;
    }

    printf("+------------+-----------------+-----------------+------------+------------+------------+\n");
    printf("\nTotal de aluguéis ativos: %d\n", contador);

    // LIBERANDO MEMÓRIA
    atual = lista_aluguel;
    while (atual) {
        Aluguel* prox = atual->prox_alu;
        free(atual);
        atual = prox;
    }

    printf("\n[>] - Pressione Enter para continuar...");
    getchar();
}

void alugueis_inativos(void)
{
    Aluguel* al = (Aluguel*) malloc(sizeof(Aluguel));
    Aluguel* lista_aluguel = NULL;
    Aluguel* ultimo = NULL;

    system("clear||cls");
    printf("\n");
    printf("#=======================================================================#\n");
    printf("|                          ALUGUÉIS INATIVOS                             |\n");
    printf("#=======================================================================#\n\n");

    FILE* arq_aluguel = fopen("aluguel.dat", "rb");
    if (!arq_aluguel) {
        printf("XXX - Nenhum arquivo de aluguéis encontrado!\n");
        printf("\n[>] - Pressione Enter para continuar...");
        free(al);
        getchar();
        return;
    }

    int contador = 0;

    while (fread(al, sizeof(Aluguel), 1, arq_aluguel)) {
        if (!al->status) {
            Aluguel* novo_al = (Aluguel*) malloc(sizeof(Aluguel));
            *novo_al = *al;
            novo_al->prox_alu = NULL;

            if (contador == 0) {
                lista_aluguel = novo_al;
                ultimo = novo_al;
            } else {
                ultimo->prox_alu = novo_al;
                ultimo = novo_al;
            }

            contador++;
        }
    }

    fclose(arq_aluguel);
    free(al);

    if (contador == 0) {
        printf("XXX - Nenhum aluguel inativo encontrado!\n");
        printf("\n[>] - Pressione Enter para continuar...");
        getchar();
        return;
    }

    printf("+------------+-----------------+-----------------+------------+------------+------------+\n");
    printf("| ID         | CPF CLIENTE     | PLACA VEÍCULO   | DATA INÍC. | DATA FIM   | VALOR R$   |\n");
    printf("+------------+-----------------+-----------------+------------+------------+------------+\n");

    Aluguel* atual = lista_aluguel;
    while (atual) {
        printf("| %-10.10s | %-15.15s | %-15.15s | %-10.10s | %-10.10s | R$ %-9.2f |\n",
               atual->id,
               atual->cpf_cliente,
               atual->placa_veiculo,
               atual->data_inicio,
               atual->data_fim,
               atual->valor_total);
        atual = atual->prox_alu;
    }

    printf("+------------+-----------------+-----------------+------------+------------+------------+\n");
    printf("\nTotal de aluguéis inativos: %d\n", contador);

    atual = lista_aluguel;
    while (atual) {
        Aluguel* prox = atual->prox_alu;
        free(atual);
        atual = prox;
    }

    printf("\n[>] - Pressione Enter para continuar...");
    getchar();
}

void filtrar_aluguel_cliente(char* cpf_cliente)
{
    Aluguel* al = (Aluguel*) malloc(sizeof(Aluguel));
    int contador = 0;

    FILE* arq_aluguel = fopen("aluguel.dat", "rb");
    if (!arq_aluguel) {
        printf("XXX - Arquivo de aluguéis não encontrado!\n");
        printf("\n[>] - Pressione Enter para continuar...");
        free(al);
        getchar();
        return;
    }

    system("clear||cls");
    printf("\n");
    printf("#=======================================================================#\n");
    printf("|                  < = = = Aluguéis por Cliente = = = >                 |\n");
    printf("#=======================================================================#\n\n");

    printf("[>] - Aluguéis do CPF: %s\n\n", cpf_cliente);

    printf("+------------+-----------------+-----------------+------------+------------+------------+\n");
    printf("| ID         | CPF CLIENTE     | PLACA VEÍCULO   | DATA INÍC. | DATA FIM   | VALOR R$   |\n");
    printf("+------------+-----------------+-----------------+------------+------------+------------+\n");

    while (fread(al, sizeof(Aluguel), 1, arq_aluguel)) {
        if (al->status && strstr(al->cpf_cliente, cpf_cliente) != NULL) {
            contador++;
            printf("| %-10.10s | %-15.15s | %-15.15s | %-10.10s | %-10.10s | R$ %-9.2f |\n",
                   al->id,
                   al->cpf_cliente,
                   al->placa_veiculo,
                   al->data_inicio,
                   al->data_fim,
                   al->valor_total);
        }
    }

    if (contador == 0)
        printf("|                  Nenhum aluguel encontrado!                            |\n");

    printf("+------------+-----------------+-----------------+------------+------------+------------+\n");
    printf("\nTotal de aluguéis encontrados: %d\n", contador);

    fclose(arq_aluguel);
    free(al);

    printf("\n[>] - Pressione Enter para continuar...");
    getchar();
}

void alugueis_por_cliente(void)
{
    char cpf_busca[15];
    int c;

    system("clear||cls");
    printf("\n");
    printf("#=======================================================================#\n");
    printf("|                         FILTRAGEM POR CLIENTE                          |\n");
    printf("#=======================================================================#\n\n");

    printf("Digite o CPF do cliente: ");
    scanf("%14[^\n]", cpf_busca);
    while ((c = getchar()) != '\n' && c != EOF);

    filtrar_aluguel_cliente(cpf_busca);
}