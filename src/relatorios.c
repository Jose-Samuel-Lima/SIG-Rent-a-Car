#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <stdbool.h>
#include "funcionarios.h"
#include "clientes.h"
#include "veiculos.h"
#include "relatorios.h"
#include "alugueis.h"

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
    printf("|                       # 1 # Funcionários_Ativos                       |\n");
    printf("|                       # 2 # Funcionários_Inativos                     |\n");
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

void funcionarios_ativos(void)
{
    FILE *arq_funcionario;
    Funcionario* fun;
    arq_funcionario = fopen("funcionario.dat","rb");

    system("clear||cls");
    printf("\n");
    printf("#=======================================================================#\n");
    printf("|                                                                       |\n");
    printf("|                 < = = =  Funcionários Ativos = = = >                  |\n");
    printf("|                                                                       |\n");
    printf("#=======================================================================#\n");
    printf("\n");
    
    if (arq_funcionario == NULL) {
        printf("XXX - Nenhum arquivo de funcionários encontrado!\n");
        printf("[>] - Pressione Enter para continuar...");
        getchar();
        return;
    }

    fun = (Funcionario*) malloc(sizeof(Funcionario));

    int contador = 0;

    while (fread(fun, sizeof(Funcionario), 1, arq_funcionario)) {
        if (fun->status == true) {
            contador++;
            printf("------------------------------------------------------------\n");
            printf("Funcionário #%d\n", contador);
            printf("Nome: %s\n", fun->nome_funcionario);
            printf("CPF: %s\n", fun->cpf_funcionario);
            printf("Data de Nascimento: %s\n", fun->dt_nascimento_fun);
            printf("Email: %s\n", fun->email_funcionario);
            printf("Cargo: %s\n", fun->cargo);
        }
    }

    if (contador == 0) {
        printf("XXX - Nenhum funcionário ativo encontrado!\n");
    } else {
        printf("------------------------------------------------------------\n");
        printf("Total de funcionários ativos: %d\n", contador);
    }

    fclose(arq_funcionario);
    free(fun);

    printf("\n[>] - Pressione Enter para sair...");
    getchar();
}

void funcionarios_inativos(void)
{
    FILE *arq_funcionario;
    Funcionario* fun;
    arq_funcionario = fopen("funcionario.dat","rb");

    system("clear||cls");
    printf("\n");
    printf("#=======================================================================#\n");
    printf("|                                                                       |\n");
    printf("|               < = = =  Funcionários Inativos = = = >                  |\n");
    printf("|                                                                       |\n");
    printf("#=======================================================================#\n");
    printf("\n");
    
    if (arq_funcionario == NULL) {
        printf("XXX - Nenhum arquivo de funcionários encontrado!\n");
        printf("[>] - Pressione Enter para continuar...");
        getchar();
        return;
    }

    fun = (Funcionario*) malloc(sizeof(Funcionario));

    int contador = 0;

    while (fread(fun, sizeof(Funcionario), 1, arq_funcionario)) {
        if (fun->status == false) {
            contador++;
            printf("------------------------------------------------------------\n");
            printf("Funcionário #%d\n", contador);
            printf("Nome: %s\n", fun->nome_funcionario);
            printf("CPF: %s\n", fun->cpf_funcionario);
            printf("Data de Nascimento: %s\n", fun->dt_nascimento_fun);
            printf("Email: %s\n", fun->email_funcionario);
            printf("Cargo: %s\n", fun->cargo);
        }
    }

    if (contador == 0) {
        printf("XXX - Nenhum funcionário inativo encontrado!\n");
    } else {
        printf("------------------------------------------------------------\n");
        printf("Total de funcionários inativos: %d\n", contador);
    }

    fclose(arq_funcionario);
    free(fun);

    printf("\n[>] - Pressione Enter para sair...");
    getchar();
}

void clientes_ativos(void)
{
    FILE *arq_cliente;
    Cliente* cli;
    arq_cliente = fopen("cliente.dat","rb");

    system("clear||cls");
    printf("\n");
    printf("#=======================================================================#\n");
    printf("|                                                                       |\n");
    printf("|                   < = = =  Clientes Ativos = = = >                    |\n");
    printf("|                                                                       |\n");
    printf("#=======================================================================#\n");
    printf("\n");
    
    if (arq_cliente == NULL) {
        printf("XXX - Nenhum arquivo de clientes encontrado!\n");
        printf("[>] - Pressione Enter para continuar...");
        getchar();
        return;
    }

    cli = (Cliente*) malloc(sizeof(Cliente));

    int contador = 0;

    while (fread(cli, sizeof(Cliente), 1, arq_cliente)) {
        if (cli->status == true) {
            contador++;
            printf("------------------------------------------------------------\n");
            printf("Cliente #%d\n", contador);
            printf("Nome: %s\n", cli->nome_cliente);
            printf("CPF: %s\n", cli->cpf_cliente);
            printf("Data Nasci.: %s\n", cli->data_nascimento);
            printf("Email: %s\n", cli->email_cliente);
            printf("CNH: %s\n", cli->cnh);
        }
    }

    if (contador == 0) {
        printf("XXX - Nenhum cliente ativo encontrado!\n");
    } else {
        printf("------------------------------------------------------------\n");
        printf("Total de clientes ativos: %d\n", contador);
    }

    fclose(arq_cliente);
    free(cli);

    printf("\n[>] - Pressione Enter para sair...");
    getchar();
}

void clientes_inativos(void)
{
    FILE *arq_cliente;
    Cliente* cli;
    arq_cliente = fopen("cliente.dat","rb");

    system("clear||cls");
    printf("\n");
    printf("#=======================================================================#\n");
    printf("|                                                                       |\n");
    printf("|                 < = = =  Clientes Inativos = = = >                    |\n");
    printf("|                                                                       |\n");
    printf("#=======================================================================#\n");
    printf("\n");
    
    if (arq_cliente == NULL) {
        printf("XXX - Nenhum arquivo de clientes encontrado!\n");
        printf("[>] - Pressione Enter para continuar...");
        getchar();
        return;
    }

    cli = (Cliente*) malloc(sizeof(Cliente));

    int contador = 0;

    while (fread(cli, sizeof(Cliente), 1, arq_cliente)) {
        if (cli->status == false) {
            contador++;
            printf("------------------------------------------------------------\n");
            printf("Cliente #%d\n", contador);
            printf("Nome: %s\n", cli->nome_cliente);
            printf("CPF: %s\n", cli->cpf_cliente);
            printf("Data Nasci.: %s\n", cli->data_nascimento);
            printf("Email: %s\n", cli->email_cliente);
            printf("CNH: %s\n", cli->cnh);
        }
    }

    if (contador == 0) {
        printf("XXX - Nenhum cliente inativo encontrado!\n");
    } else {
        printf("------------------------------------------------------------\n");
        printf("Total de clientes inativos: %d\n", contador);
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
            printf("Placa: %s\n", vei->placa);
            printf("Chassi: %s\n", vei->chassi);
            printf("Renavam.: %s\n", vei->renavam);
            printf("Categoria: %s\n", vei->categoria);
            printf("Modelo: %s\n", vei->modelo);
            printf("Marca: %s\n", vei->marca);
            printf("Ano: %s\n", vei->ano);
            printf("Código Interno: %s\n", vei->codigo_interno);
            printf("Preço: %f\n", vei->preco);
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
            printf("Placa: %s\n", vei->placa);
            printf("Chassi: %s\n", vei->chassi);
            printf("Renavam.: %s\n", vei->renavam);
            printf("Categoria: %s\n", vei->categoria);
            printf("Modelo: %s\n", vei->modelo);
            printf("Marca: %s\n", vei->marca);
            printf("Ano: %s\n", vei->ano);
            printf("Código Interno: %s\n", vei->codigo_interno);
            printf("Preço: %f\n", vei->preco);
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