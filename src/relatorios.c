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
    printf("|                                                                     |\n");
    printf("|                        --------------------                         |\n");
    printf("|                        | SIG - Rent a Car |                         |\n");
    printf("|                        --------------------                         |\n");
    printf("|                                                                     |\n");
    printf("#=====================================================================#\n");
    printf("|                                                                     |\n");
    printf("|                 < = = = Módulo de Relatórios = = = >                |\n");
    printf("|                                                                     |\n");
    printf("|                    # 1 # Relatório de funcionários                  |\n");
    printf("|                    # 2 # Relatório de clientes                      |\n");
    printf("|                    # 3 # Relatório de veículos                      |\n");
    printf("|                    # 4 # Relatório de aluguéis                      |\n");
    printf("|                    # 0 # Voltar ao menu principal                   |\n");
    printf("|                                                                     |\n");
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
    printf("#=======================================================================#\n");
    printf("|                                                                       |\n");
    printf("|                          --------------------                         |\n");
    printf("|                          | SIG - Rent a Car |                         |\n");
    printf("|                          --------------------                         |\n");
    printf("|                                                                       |\n");
    printf("#=======================================================================#\n");
    printf("|                                                                       |\n");
    printf("|              < = = =  Relatório de Funcionários = = = >               |\n");
    printf("|                                                                       |\n");
    printf("|                   # 1 # Listar Funcionários Ativos                    |\n");
    printf("|                   # 2 # Listar Funcionários Inativos                  |\n");
    printf("|                   # 3 # Filtrar Funcionários por Cargo                |\n");
    printf("|                   # 0 # Sair                                          |\n");
    printf("|                                                                       |\n");
    printf("#=======================================================================#\n");
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
    printf("#=======================================================================#\n");
    printf("|                                                                       |\n");
    printf("|                          --------------------                         |\n");
    printf("|                          | SIG - Rent a Car |                         |\n");
    printf("|                          --------------------                         |\n");
    printf("|                                                                       |\n");
    printf("#=======================================================================#\n");
    printf("|                                                                       |\n");
    printf("|                < = = =  Relatório de Clientes = = = >                 |\n");
    printf("|                                                                       |\n");
    printf("|                       # 1 # Clientes_Ativos                           |\n");
    printf("|                       # 2 # Clientes_Inativos                         |\n");
    printf("|                       # 3 # Filtrar por nome                          |\n");
    printf("|                       # 0 # Sair                                      |\n");
    printf("|                                                                       |\n");
    printf("#=======================================================================#\n");
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
    printf("#=======================================================================#\n");
    printf("|                                                                       |\n");
    printf("|                          --------------------                         |\n");
    printf("|                          | SIG - Rent a Car |                         |\n");
    printf("|                          --------------------                         |\n");
    printf("|                                                                       |\n");
    printf("#=======================================================================#\n");
    printf("|                                                                       |\n");
    printf("|                < = = =  Relatório de Veículos = = = >                 |\n");
    printf("|                                                                       |\n");
    printf("|                        # 1 # Veículos Ativos                          |\n");
    printf("|                        # 2 # Veículos Inativos                        |\n");
    printf("|                        # 3 # Filtragem por Marca                      |\n");
    printf("|                        # 0 # Sair                                     |\n");
    printf("|                                                                       |\n");
    printf("#=======================================================================#\n");
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
    printf("#=======================================================================#\n");
    printf("|                                                                       |\n");
    printf("|                          --------------------                         |\n");
    printf("|                          | SIG - Rent a Car |                         |\n");
    printf("|                          --------------------                         |\n");
    printf("|                                                                       |\n");
    printf("#=======================================================================#\n");
    printf("|                                                                       |\n");
    printf("|                 < = = =  Relatório de Alugueis  = = = >               |\n");
    printf("|                                                                       |\n");
    printf("|                        # 1 # Alugueis Ativos                          |\n");
    printf("|                        # 2 # Alugueis Inativos                        |\n");
    printf("|                        # 0 # Sair                                     |\n");
    printf("|                                                                       |\n");
    printf("#=======================================================================#\n");
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
    Funcionario* lista = NULL;
    Funcionario* ultimo = NULL;

    system("clear||cls");
    printf("\n");
    printf("#=========================================================================================================#\n");
    printf("|                                          FUNCIONÁRIOS ATIVOS                                            |\n");                
    printf("#=========================================================================================================#\n");

    FILE* arq_funcionario = fopen("funcionario.dat", "rb");
    if (arq_funcionario == NULL) {
        printf("XXX - Nenhum arquivo de funcionários encontrado!\n");
        getchar();
        free(fun);
        return;
    }

    int contador = 0;

    // LISTA DINÂMICA DIRETA
    while (fread(fun, sizeof(Funcionario), 1, arq_funcionario)) {
        if (fun->status == true) {

            Funcionario* novo_func = (Funcionario*) malloc(sizeof(Funcionario));
            *novo_func = *fun;
            novo_func->prox_func = NULL;

            if (contador == 0) {
                lista = novo_func;
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
        printf("\n[>] - Pressione ENTER para sai...");
        getchar();
        return;
    }

    // EXIBINDO LISTA EM FORMATO DE TABELA
    printf("| %-20s | %-14s | %-12s | %-25s | %-20s |\n",
           "NOME", "CPF", "NASCIMENTO", "EMAIL", "CARGO");

    Funcionario* atual = lista;
    while (atual != NULL) {
        printf("| %-20.20s | %-14.14s | %-12.12s | %-25.25s | %-20.20s |\n",
               atual->nome_funcionario,
               atual->cpf_funcionario,
               atual->dt_nascimento_fun,
               atual->email_funcionario,
               atual->cargo);

        atual = atual->prox_func;
    }

    // LIBERANDO MEMÓRIA DA LISTA
    atual = lista;
    while (atual != NULL) {
        Funcionario* prox_func = atual->prox_func;
        free(atual);
        atual = prox_func;
    }
    printf("#=========================================================================================================#");
    printf("\n[>] - Pressione ENTER para continuar...");
    getchar();
}

void funcionarios_inativos(void)
{
    FILE *arq_funcionario;
    Funcionario* fun;
    Funcionario* lista = NULL;
    arq_funcionario = fopen("funcionario.dat","rb");

    system("clear||cls");
    printf("\n");
    printf("#=========================================================================================================#\n");
    printf("|                                        FUNCIONÁRIOS INATIVOS                                            |\n");                
    printf("#=========================================================================================================#\n");
    
    if (arq_funcionario == NULL) {
        printf("XXX - Nenhum arquivo de funcionários encontrado!\n");
        printf("[>] - Pressione Enter para continuar...");
        getchar();
        return;
    }

    fun = (Funcionario*) malloc(sizeof(Funcionario));

    int contador = 0;

    // LISTA DINÂMICA INVERSA
    while (fread(fun, sizeof(Funcionario), 1, arq_funcionario)) {

        if (fun->status == false) {
            Funcionario* novo_func = (Funcionario*) malloc(sizeof(Funcionario));
            *novo_func = *fun;         
            novo_func->prox_func = lista; 
            lista = novo_func;
            contador++;
        }
    }
    
    fclose(arq_funcionario);
    free(fun);

    if (contador == 0) {
        printf("XXX - Nenhum funcionário inativo encontrado!\n");
        printf("\n[>] - Pressione Enter para sair...");
        getchar();
        return;
    }

    // EXIBINDO LISTA EM FORMATO DE TABELA
    printf("| %-20s | %-14s | %-12s | %-25s | %-20s |\n",
           "NOME", "CPF", "NASCIMENTO", "EMAIL", "CARGO");

    Funcionario* atual = lista;
    while (atual != NULL) {
        printf("| %-20.20s | %-14.14s | %-12.12s | %-25.25s | %-20.20s |\n",
               atual->nome_funcionario,
               atual->cpf_funcionario,
               atual->dt_nascimento_fun,
               atual->email_funcionario,
               atual->cargo);

        atual = atual->prox_func;
    }

    // LIBERANDO MEMÓRIA DA LISTA
    atual = lista;
    while (atual != NULL) {
        Funcionario* prox_func = atual->prox_func;
        free(atual);
        atual = prox_func;
    }

    printf("\nTotal de funcionários inativos: %d\n", contador);

    printf("#=========================================================================================================#");
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
    printf("|                                                                       |\n");
    printf("|                < = = =  Filtragem por Cargos = = = >                  |\n");
    printf("|                                                                       |\n");
    printf("#=======================================================================#\n");
    printf("\n");

    printf("Digite o cargo que deseja buscar: ");
    scanf("%50s", cargo_busca); 
    while ((c = getchar()) != '\n' && c != EOF);

    str_to_lower(cargo_busca);

    filtrar_funcionario_cargo(cargo_busca);
}

void filtrar_funcionario_cargo(char* cargo) {
    FILE *arq_funcionario;
    Funcionario* fun;
    int contador = 0;

    arq_funcionario = fopen("funcionario.dat", "rb");

    system("clear||cls");
    printf("\n");
    printf("#=======================================================================#\n");
    printf("|                  < = = = Funcionários por Cargo = = = >               |\n");
    printf("#=======================================================================#\n\n");

    if (arq_funcionario == NULL) {
        printf("XXX - Arquivo de funcionários não encontrado!\n");
        printf("[>] - Pressione Enter para continuar...");
        getchar();
        return;
    }

    fun = (Funcionario*) malloc(sizeof(Funcionario));

    printf("\n [>] - Funcionários com o cargo: %s\n\n", cargo);

    while (fread(fun, sizeof(Funcionario), 1, arq_funcionario)) {
        if (fun->status == true){ 

            char cargo_temp[51];
            strcpy(cargo_temp, fun->cargo);

            str_to_lower(cargo_temp);

            if(strstr(cargo_temp, cargo) != NULL) {
                if (contador == 0) {
                    printf("| %-20s | %-14s | %-12s | %-25s | %-20s |\n",
                           "NOME", "CPF", "NASCIMENTO", "EMAIL", "CARGO");
                }

                contador++;
                printf("| %-20.20s | %-14.14s | %-12.12s | %-25.25s | %-20.20s |\n",
                       fun->nome_funcionario,
                       fun->cpf_funcionario,
                       fun->dt_nascimento_fun,
                       fun->email_funcionario,
                       fun->cargo);
            }
        }
    }

    if (contador == 0) {
        printf("XXX - Nenhum funcionário com esse cargo encontrado!\n");
    } else {
        printf("----------------------------------------------\n");
        printf("\nTotal: %d funcionário(s)\n", contador);
    }

    fclose(arq_funcionario);
    free(fun);

    printf("\n[>] - Pressione Enter para sair...");
    getchar();
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
    if (arq_cliente == NULL) {
        printf("XXX - Nenhum arquivo de clientes encontrado!\n");
        getchar();
        free(cli);
        return;
    }

    int contador = 0;

    // LISTA DINÂMICA DIRETA
    while (fread(cli, sizeof(Cliente), 1, arq_cliente)) {
        if (cli->status == true) {
            
            Cliente* novo_cli = (Cliente*) malloc(sizeof(Funcionario));
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
    printf("\nNenhum cliente ativo encontrado.\n");
    printf("\nPressione ENTER para continuar...");
    getchar();
    return;
}

// EXIBINDO LISTA EM FORMATO DE TABELA
printf("| %-20s | %-14s | %-12s | %-25s | %-15s |\n",
       "NOME", "CPF", "NASCIMENTO", "EMAIL", "CNH");

Cliente* atual = lista_cliente;
while (atual != NULL) {
    printf("| %-20.20s | %-14.14s | %-12.12s | %-25.25s | %-15.15s |\n",
           atual->nome_cliente,
           atual->cpf_cliente,
           atual->data_cliente,
           atual->email_cliente,
           atual->cnh_cliente);

    atual = atual->prox_cli;
}

// LIBERANDO MEMÓRIA DA LISTA
atual = lista_cliente;
while (atual != NULL) {
    Cliente* prox_cli = atual->prox_cli;
    free(atual);
    atual = prox_cli;
}
printf("#=========================================================================================================#");
printf("\nTotal de clientes ativos: %d\n", contador);
printf("Pressione ENTER para continuar...");
getchar();
}

void clientes_inativos(void)
{
    FILE *arq_cliente;
    Cliente* cli;
    Cliente* lista_cliente = NULL;
    arq_cliente = fopen("cliente.dat","rb");

    system("clear||cls");
    printf("\n");
    printf("#=========================================================================================================#\n");
    printf("|                                           CLIENTES INATIVOS                                             |\n");                
    printf("#=========================================================================================================#\n");
    printf("\n");
    
    if (arq_cliente == NULL) {
        printf("XXX - Nenhum arquivo de clientes encontrado!\n");
        printf("[>] - Pressione Enter para continuar...");
        getchar();
        return;
    }

    cli = (Cliente*) malloc(sizeof(Cliente));

    int contador = 0;

    // LISTA DINÂMICA INVERSA
    while (fread(cli, sizeof(Cliente), 1, arq_cliente)) {
        if (cli->status == false) {
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
    printf("| %-20s | %-14s | %-12s | %-25s | %-15s |\n",
           "NOME", "CPF", "NASCIMENTO", "EMAIL", "CNH");

    Cliente* atual = lista_cliente;
    while (atual != NULL) {
        printf("| %-20.20s | %-14.14s | %-12.12s | %-25.25s | %-15.15s |\n",
               atual->nome_cliente,
               atual->cpf_cliente,
               atual->data_cliente,
               atual->email_cliente,
               atual->cnh_cliente);

        atual = atual->prox_cli;
    }

    // LIBERANDO MEMÓRIA DA LISTA
    atual = lista_cliente;
    while (atual != NULL) {
        Cliente* prox_cli = atual->prox_cli;
        free(atual);
        atual = prox_cli;
    }

    printf("#=========================================================================================================#\n");
    printf("\nTotal de clientes inativos: %d\n", contador);
    printf("-----------------------------------------------------------------------------------------------------------\n");
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
    printf("|                                                                       |\n");
    printf("|                < = = =  Filtragem por Nome = = = >                    |\n");
    printf("|                                                                       |\n");
    printf("#=======================================================================#\n");
    printf("\n");

    printf("Digite o nome que deseja buscar: ");
    scanf("%50s", nome_busca); 
    while ((c = getchar()) != '\n' && c != EOF);

    str_to_lower(nome_busca);

    filtrar_cliente_nome(nome_busca);
}

void filtrar_cliente_nome(char* nome_cliente) {
    FILE *arq_cliente;
    Cliente* cli;
    int contador = 0;

    arq_cliente = fopen("cliente.dat", "rb");

    system("clear||cls");
    printf("\n");
    printf("#=======================================================================#\n");
    printf("|                  < = = = Clientes por Nome = = = >                    |\n");
    printf("#=======================================================================#\n\n");

    if (arq_cliente == NULL) {
        printf("XXX - Arquivo de Clientes não encontrado!\n");
        printf("[>] - Pressione Enter para continuar...");
        getchar();
        return;
    }

    cli = (Cliente*) malloc(sizeof(Cliente));

    printf("\n [>] - Clientes com o nome: %s\n\n", nome_cliente);

    while (fread(cli, sizeof(Cliente), 1, arq_cliente)) {
        if (cli->status == true){ 

            char nome_temp[51];
            strcpy(nome_temp, cli->nome_cliente);

            str_to_lower(nome_temp);

            if (strstr(nome_temp, nome_cliente) != NULL) {
                if (contador == 0) {
                    printf("| %-20s | %-14s | %-12s | %-25s | %-15s |\n",
                           "NOME", "CPF", "NASCIMENTO", "EMAIL", "CNH");
                }

                contador++;
                printf("| %-20.20s | %-14.14s | %-12.12s | %-25.25s | %-15.15s |\n",
                       cli->nome_cliente,
                       cli->cpf_cliente,
                       cli->data_cliente,
                       cli->email_cliente,
                       cli->cnh_cliente);
            }
        }
    }

    if (contador == 0) {
        printf("XXX - Nenhum cliente encontrado!\n");
    } else {
        printf("----------------------------------------------\n");
        printf("\nTotal: %d cliente(s)\n", contador);
    }

    fclose(arq_cliente);
    free(cli);

    printf("\n[>] - Pressione Enter para sair...");
    getchar();
}

void veiculos_ativos(void)
{
    FILE *arq_veiculo;
    Veiculo* vei;
    arq_veiculo = fopen("veiculo.dat","rb");

    system("clear||cls");
    printf("\n");
    printf("#=======================================================================#\n");
    printf("|                                                                       |\n");
    printf("|                   < = = =  Veículos Ativos = = = >                    |\n");
    printf("|                                                                       |\n");
    printf("#=======================================================================#\n");
    printf("\n");
    
    if (arq_veiculo == NULL) {
        printf("XXX - Nenhum arquivo de veículos encontrado!\n");
        printf("[>] - Pressione Enter para continuar...");
        getchar();
        return;
    }

    vei = (Veiculo*) malloc(sizeof(Veiculo));

    int contador = 0;

    while (fread(vei, sizeof(Veiculo), 1, arq_veiculo)) {
        if (vei->status == true) {
            contador++;
            printf("------------------------------------------------------------\n");
            printf("Placa: %s\n", vei->placa_veiculo);
            printf("Chassi: %s\n", vei->chassi_veiculo);
            printf("Renavam.: %s\n", vei->renavam_veiculo);
            printf("Categoria: %s\n", vei->categoria_veiculo);
            printf("Modelo: %s\n", vei->modelo_veiculo);
            printf("Marca: %s\n", vei->marca_veiculo);
            printf("Ano: %s\n", vei->ano_veiculo);
            printf("Código Interno: %s\n", vei->codigo_interno_veiculo);
            printf("Preço: %f\n", vei->preco_veiculo);
        }
    }

    if (contador == 0) {
        printf("XXX - Nenhum veículo ativo encontrado!\n");
    } else {
        printf("------------------------------------------------------------\n");
        printf("Total de veículos ativos: %d\n", contador);
    }

    fclose(arq_veiculo);
    free(vei);

    printf("\n[>] - Pressione Enter para sair...");
    getchar();
}

void veiculos_inativos(void)
{
    FILE *arq_veiculo;
    Veiculo* vei;
    arq_veiculo = fopen("veiculo.dat","rb");

    system("clear||cls");
    printf("\n");
    printf("#=======================================================================#\n");
    printf("|                                                                       |\n");
    printf("|                   < = = =  Veículos Inativos = = = >                  |\n");
    printf("|                                                                       |\n");
    printf("#=======================================================================#\n");
    printf("\n");
    
    if (arq_veiculo == NULL) {
        printf("XXX - Nenhum arquivo de veículos encontrado!\n");
        printf("[>] - Pressione Enter para continuar...");
        getchar();
        return;
    }
    
    vei = (Veiculo*) malloc(sizeof(Veiculo));

    int contador = 0;

    while (fread(vei, sizeof(Veiculo), 1, arq_veiculo)) {
        if (vei->status == false) {
            contador++;
            printf("------------------------------------------------------------\n");
            printf("Placa: %s\n", vei->placa_veiculo);
            printf("Chassi: %s\n", vei->chassi_veiculo);
            printf("Renavam.: %s\n", vei->renavam_veiculo);
            printf("Categoria: %s\n", vei->categoria_veiculo);
            printf("Modelo: %s\n", vei->modelo_veiculo);
            printf("Marca: %s\n", vei->marca_veiculo);
            printf("Ano: %s\n", vei->ano_veiculo);
            printf("Código Interno: %s\n", vei->codigo_interno_veiculo);
            printf("Preço: %f\n", vei->preco_veiculo);
        }
    }

    if (contador == 0) {
        printf("XXX - Nenhum veículo inativo encontrado!\n");
    } else {
        printf("------------------------------------------------------------\n");
        printf("Total de veículos inativos: %d\n", contador);
    }

    fclose(arq_veiculo);
    free(vei);

    printf("\n[>] - Pressione Enter para sair...");
    getchar();
}

void veiculos_por_marca(void)
{ 
    char marca_busca[16];
    int c;

    system("clear||cls");
    printf("\n");
    printf("#=======================================================================#\n");
    printf("|                                                                       |\n");
    printf("|                < = = =  Filtragem por Marca = = = >                   |\n");
    printf("|                                                                       |\n");
    printf("#=======================================================================#\n");
    printf("\n");

    printf("Digite o cargo que deseja buscar: ");
    scanf("%15s", marca_busca); 
    while ((c = getchar()) != '\n' && c != EOF);

    str_to_lower(marca_busca);

    filtrar_veiculo_marca(marca_busca);
}

void filtrar_veiculo_marca(char* marca_veiculo) {
    FILE *arq_veiculo;
    Veiculo* vei;
    int contador = 0;

    arq_veiculo = fopen("veiculo.dat", "rb");

    system("clear||cls");
    printf("\n");
    printf("#=======================================================================#\n");
    printf("|                  < = = = Veiculos por Marca = = = >                   |\n");
    printf("#=======================================================================#\n\n");

    if (arq_veiculo == NULL) {
        printf("XXX - Arquivo não encontrado!\n");
        printf("[>] - Pressione Enter para continuar...");
        getchar();
        return;
    }

    vei = (Veiculo*) malloc(sizeof(Veiculo));

    printf("\n [>] - Veículos com o cargo: %s\n\n", marca_veiculo);

    while (fread(vei, sizeof(Veiculo), 1, arq_veiculo)) {
        if (vei->status == true){ 

            char marca_temp[16];
            strcpy(marca_temp, vei->marca_veiculo);

            str_to_lower(marca_temp);

            if(strstr(marca_temp, marca_veiculo) != NULL) {
                contador++;
                printf("----------------------------------------------\n");
                printf("Placa: %s\n", vei->placa_veiculo);
                printf("Chassi: %s\n", vei->chassi_veiculo);
                printf("Renavam.: %s\n", vei->renavam_veiculo);
                printf("Categoria: %s\n", vei->categoria_veiculo);
                printf("Modelo: %s\n", vei->modelo_veiculo);
                printf("Marca: %s\n", vei->marca_veiculo);
                printf("Ano: %s\n", vei->ano_veiculo);
                printf("Código Interno: %s\n", vei->codigo_interno_veiculo);
                printf("Preço: %f\n", vei->preco_veiculo);
        }
        }
    }

    if (contador == 0) {
        printf("XXX - Nenhum veículo encontrado!\n");
    } else {
        printf("----------------------------------------------\n");
        printf("\nTotal: %d veículo (s)\n", contador);
    }

    fclose(arq_veiculo);
    free(vei);

    printf("\n[>] - Pressione Enter para sair...");
    getchar();
}

void alugueis_ativos(void)
{
    FILE *arq_aluguel;
    Aluguel* alg;
    arq_aluguel = fopen("aluguel.dat","rb");

    system("clear||cls");
    printf("\n");
    printf("#=======================================================================#\n");
    printf("|                                                                       |\n");
    printf("|                   < = = =  Alugueis Ativos = = = >                    |\n");
    printf("|                                                                       |\n");
    printf("#=======================================================================#\n");
    printf("\n");

    if (arq_aluguel == NULL) {
        printf("XXX - Nenhum arquivo de alugueis encontrado!\n");
        printf("[>] - Pressione Enter para continuar...");
        getchar();
        return;
    }

    alg = (Aluguel*) malloc(sizeof(Aluguel));

    int contador = 0;

    while (fread(alg, sizeof(Aluguel), 1, arq_aluguel)) {
        if (alg->status == true) {
            contador++;
            printf("------------------------------------------------------------\n");
            printf("Nome: %s\n", alg->nome_cliente);
            printf("CPF: %s\n", alg->cpf_cliente);
            printf("Código RENAVAM: %s\n", alg->codigo_renavam);
            printf("Modelo do Veículo: %s\n", alg->modelo_veiculo);
            printf("Data de Finalização: %s\n", alg->data_aluguel);
            printf("ID do Aluguel: %s\n", alg->id_aluguel);
            }
    }

    if (contador == 0) {
        printf("XXX - Nenhum aluguel ativo encontrado!\n");
    } else {
        printf("------------------------------------------------------------\n");
        printf("Total de alugueis ativos: %d\n", contador);
    }

    fclose(arq_aluguel);
    free(alg);

    printf("\n[>] - Pressione Enter para sair...");
    getchar();
}

void alugueis_inativos(void)
{
    FILE *arq_aluguel;
    Aluguel* alg;
    arq_aluguel = fopen("aluguel.dat","rb");

    system("clear||cls");
    printf("\n");
    printf("#=======================================================================#\n");
    printf("|                                                                       |\n");
    printf("|                   < = = =  Alugueis Inativos = = = >                  |\n");
    printf("|                                                                       |\n");
    printf("#=======================================================================#\n");
    printf("\n");

    if (arq_aluguel == NULL) {
        printf("XXX - Nenhum arquivo de alugueis encontrado!\n");
        printf("[>] - Pressione Enter para continuar...");
        getchar();
        return;
    }

    alg = (Aluguel*) malloc(sizeof(Aluguel));

    int contador = 0;

    while (fread(alg, sizeof(Aluguel), 1, arq_aluguel)) {
        if (alg->status == false) {
            contador++;
            printf("------------------------------------------------------------\n");
            printf("Nome: %s\n", alg->nome_cliente);
            printf("CPF: %s\n", alg->cpf_cliente);
            printf("Código RENAVAM: %s\n", alg->codigo_renavam);
            printf("Modelo do Veículo: %s\n", alg->modelo_veiculo);
            printf("Data de Finalização: %s\n", alg->data_aluguel);
            printf("ID do Aluguel: %s\n", alg->id_aluguel);
            }
    }

    if (contador == 0) {
        printf("XXX - Nenhum aluguel inativo encontrado!\n");
    } else {
        printf("------------------------------------------------------------\n");
        printf("Total de alugueis inativos: %d\n", contador);
    }

    fclose(arq_aluguel);
    free(alg);

    printf("\n[>] - Pressione Enter para sair...");
    getchar();
}

void alugueis_por_data(void)
{
    char data_busca[15];
    int c;

    system("clear||cls");
    printf("\n");
    printf("#=======================================================================#\n");
    printf("|                                                                       |\n");
    printf("|                < = = =  Filtragem por Nome = = = >                    |\n");
    printf("|                                                                       |\n");
    printf("#=======================================================================#\n");
    printf("\n");

    printf("Digite o nome que deseja buscar: ");
    scanf("%14s", data_busca); 
    while ((c = getchar()) != '\n' && c != EOF);

    str_to_lower(data_busca);

    filtrar_aluguel_data(data_busca);
}

void filtrar_aluguel_data(char* data_aluguel) {
FILE *arq_aluguel;
    Aluguel* alg;
    int contador = 0;

    arq_aluguel = fopen("aluguel.dat", "rb");

    system("clear||cls");
    printf("\n");
    printf("#=======================================================================#\n");
    printf("|                  < = = = Filtrar por Data   = = = >                   |\n");
    printf("#=======================================================================#\n\n");

    if (arq_aluguel == NULL) {
        printf("XXX - Arquivo não encontrado!\n");
        printf("[>] - Pressione Enter para continuar...");
        getchar();
        return;
    }

    alg = (Aluguel*) malloc(sizeof(Aluguel));

    printf("\n [>] - Aluguéis com a data: %s\n\n", data_aluguel);

    while (fread(alg, sizeof(Aluguel), 1, arq_aluguel)) {
        if (alg->status == true){ 

            char data_temp[15];
            strcpy(data_temp, alg->data_aluguel);

            str_to_lower(data_temp);

            if(strstr(data_temp, data_aluguel) != NULL) {
                contador++;
                printf("----------------------------------------------\n");
                printf("Nome: %s\n", alg->nome_cliente);
                printf("CPF: %s\n", alg->cpf_cliente);
                printf("Código RENAVAM: %s\n", alg->codigo_renavam);
                printf("Modelo do Veículo: %s\n", alg->modelo_veiculo);
                printf("Data de Finalização: %s\n", alg->data_aluguel);
                printf("ID do Aluguel: %s\n", alg->id_aluguel);
            }
        }
    }

    if (contador == 0) {
        printf("XXX - Nenhum aluguel encontrado!\n");
    } else {
        printf("----------------------------------------------\n");
        printf("\nTotal: %d aluguel(is)\n", contador);
    }

    fclose(arq_aluguel);
    free(alg);

    printf("\n[>] - Pressione Enter para sair...");
    getchar();
}