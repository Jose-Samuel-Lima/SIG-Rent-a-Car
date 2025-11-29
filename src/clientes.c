#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

#include "clientes.h"
#include "validacao.h"
#include "utilidades.h"

int modulo_cliente(void)
{
    int esc;
    do
    {
        esc = modulo_tela_cliente();
        switch (esc)
        {
        case 1:
            modulo_cadastrar_cliente();
            break;
        case 2:
            modulo_verificar_cliente();
            break;
        case 3:
            modulo_atualizar_clientes();
            break;
        case 4:
            modulo_excluir_cliente();
            break;
        case 0:
            return -1;
        }

    } while (esc != 0);
    return -1;
}

int modulo_tela_cliente(void)
{

    int op;
    int c;

    system("clear||cls");
    printf("\n");
    printf("#=====================================================================#\n");
    printf("|                         --------------------                        |\n");
    printf("|                         | SIG - Rent a Car |                        |\n");
    printf("|                         --------------------                        |\n");
    printf("#=====================================================================#\n");
    printf("|                           MÓDULO CLIENTES                           |\n");
    printf("|---------------------------------------------------------------------|\n");
    printf("|                       [1] - Cadastrar Cliente                       |\n");
    printf("|                       [2] - Verificar Cliente                       |\n");
    printf("|                       [3] - Atualizar Cliente                       |\n");
    printf("|                       [4] - Excluir Cliente                         |\n");
    printf("|---------------------------------------------------------------------|\n");
    printf("|                       [0] - Sair                                    |\n");
    printf("#=====================================================================#\n");
    printf("\n");
    printf("[>] - Escolha uma das opções acima: ");
    scanf(" %d", &op);
    while ((c = getchar()) != '\n' && c != EOF)
        ;
    printf("\n");
    printf("Processando...\n");
    return op;
}

void modulo_cadastrar_cliente(void)
{
    system("clear||cls");

    Cliente *cli = malloc(sizeof(Cliente));
    if (!cli) return;
    
    printf("\n");
    printf("#=====================================================================#\n");
    printf("|                         --------------------                        |\n");
    printf("|                         | SIG - Rent a Car |                        |\n");
    printf("|                         --------------------                        |\n");
    printf("#=====================================================================#\n");
    printf("|                          CADASTRAR CLIENTES                         |\n");
    printf("#=====================================================================#\n");
    printf("\n");

    lerEntrada(cli->nome_cliente, 100, "[+] - Nome: ", validarNome);
    lerEntrada(cli->cpf_cliente, 15, "[+] - CPF: ", validarCPF);
    lerEntrada(cli->data_cliente, 12, "[+] - Data de Nascimento (DD/MM/AAAA): ", validarData);
    lerEntrada(cli->email_cliente, 100, "[+] - Email: ", validarEmail);
    lerEntrada(cli->cnh_cliente, 19,"[+] - CNH: ", validarCNH);
    
    cli->status = true;

    FILE *arq_cliente = fopen("cliente.dat","ab");

    if (arq_cliente == NULL){
        printf("XXX - Erro ao abrir o arquivo!");
        printf("[>] - Pressione Enter para continuar...");
        getchar();
        exit(1);
    }

    fwrite(cli, sizeof(Cliente), 1, arq_cliente);
    fclose(arq_cliente);
    free(cli);

    printf("#=====================================================================#\n");
    printf("[o] - Cliente Registrado com Sucesso!\n");
    printf("[>] - Pressione Enter para continuar...");
    getchar();
}

void modulo_verificar_cliente(void)
{
    FILE *arq_cliente;
    Cliente* cli;
    cli = (Cliente*) malloc(sizeof(Cliente));
    arq_cliente = fopen("cliente.dat","rb");

    if (arq_cliente == NULL){
        printf("XXX - Erro na criação do arquivo!\n");
        printf("[>] - Pressione Enter para continuar...");
        getchar();
        exit(1);
    }

    char cpf_cliente_ler[15];
    int c;

    system("clear||cls");
    printf("\n");
    printf("#=====================================================================#\n");
    printf("|                         --------------------                        |\n");
    printf("|                         | SIG - Rent a Car |                        |\n");
    printf("|                         --------------------                        |\n");
    printf("#=====================================================================#\n");
    printf("|                          VERIFICAR CLIENTE                          |\n");
    printf("#=====================================================================#\n");
    printf("\n");
    printf("[>] - Informe o CPf do funcionário que deseja encontrar: ");
    scanf("%15s", cpf_cliente_ler);
    while ((c = getchar()) != '\n' && c != EOF)
        ;
    while (fread(cli,sizeof(Cliente),1,arq_cliente)){

        if (strcmp(cpf_cliente_ler,cli->cpf_cliente) == 0 && cli->status == true) {
            system("clear||cls");
            printf("#====================================================#\n");
            printf("|             [o] - Cliente encontrado!              |\n");
            printf("#====================================================#\n");
            printf("| > Nome: %s\n", cli->nome_cliente);
            printf("| > CPF: %s\n", cli->cpf_cliente);
            printf("| > Data de Nascimento: %s\n", cli->data_cliente);
            printf("| > Email: %s\n", cli->data_cliente);
            printf("| > CNH: %s\n", cli->cnh_cliente);
            printf("#====================================================#\n");
            printf("[>] - Pressione Enter para continuar...");
            getchar();
            return;
        }
        
    }

    fclose(arq_cliente);
    free(cli);
    printf("XXX - Cliente não encontrado!\n");
    printf("[>] - Pressione Enter para continuar...");
    getchar();
}

void modulo_atualizar_clientes(void)
{
    FILE *arq_cliente;
    Cliente* cli;
    cli = (Cliente*) malloc(sizeof(Cliente));
    arq_cliente = fopen("cliente.dat", "r+b");

    if (arq_cliente == NULL){
        printf("XXX - Erro ao entrar no arquivo!");
        printf("[>] - Pressione Enter para continuar...");
        getchar();
        exit(1);
    }

    char cpf_cliente_ler[15];
    char op_cliente;
    int c;
    int cli_encontrado = false;

    system("clear||cls");
    printf("\n");
    printf("#=====================================================================#\n");
    printf("|                         --------------------                        |\n");
    printf("|                         | SIG - Rent a Car |                        |\n");
    printf("|                         --------------------                        |\n");
    printf("#=====================================================================#\n");
    printf("|                          ATUALIZAR CLIENTE                          |\n");
    printf("#=====================================================================#\n");
    printf("\n");
    printf("[>] - Informe o CPf do funcionário para alterar os dados: ");
    scanf("%15s", cpf_cliente_ler);
    while ((c = getchar()) != '\n' && c != EOF)
        ;
    
    while ((fread(cli,sizeof(Cliente),1,arq_cliente) == 1)) {
        if (strcmp(cli->cpf_cliente,cpf_cliente_ler) == 0 && cli->status) {
            
            cli_encontrado = true;
        
            system("clear||cls");
            printf("#====================================================#\n");
            printf("|            [o] - Cliente encontrado!               |\n");
            printf("#====================================================#\n");
            printf("|            [1] - Nome                              |\n");
            printf("|            [2] - CPF                               |\n");
            printf("|            [3] - Data de Nascimento                |\n");
            printf("|            [4] - E-mail                            |\n");
            printf("|            [5] - CNH                               |\n");
            printf("|----------------------------------------------------|\n");
            printf("|            [0] - Cancelar                          |\n");
            printf("#====================================================#\n");
            printf("[>] - Informe qual informação deseja alterar: ");
            scanf(" %c", &op_cliente);
            while ((c = getchar()) != '\n' && c != EOF)
                ;
            
            int alt = 0; 

            switch(op_cliente){
                case '1':
                    atualizarEntrada("[+] - Novo nome do Cliente: ", cli->nome_cliente, 100, validarNome);

                    alt = 1;
                    break;

                case '2':
                    atualizarEntrada("[+] - Novo CPF do Cliente: ", cli->cpf_cliente, 15, validarCPF);

                    alt = 1;
                    break;
                    
                case '3':
                    atualizarEntrada("[+] - Nova data de nascimento (DD/MM/AAAA): ", cli->data_cliente, 12, validarData);

                    alt = 1;
                    break;

                case '4':
                    atualizarEntrada("[+] - Novo e-mail: ", cli->email_cliente, 100, validarEmail);

                    alt = 1;
                    break;


                case '5':
                    atualizarEntrada("[+] - Nova CNH: ", cli->cnh_cliente, 20, validarNome);
        
                    alt = 1;
                    break;

                case '0':
                    printf("Voltando ao menu...\n");
                    break;

                default:
                    printf("XXX - Opção inválida. Nenhum dado alterado.\n");
                    break;

            }
            if (alt){
                fseek(arq_cliente, -sizeof(Cliente), SEEK_CUR);
                fwrite(cli, sizeof(Cliente), 1,arq_cliente);
                fflush(arq_cliente);
                printf("#====================================================#\n");
                printf("[o] - Dado(s) alterado(s) com sucesso!\n");
            }

            break;
        }
    }

    if (!cli_encontrado){
        printf("XXX - Cliente não encontrado!\n"); 
    }

    fclose(arq_cliente);
    free(cli);
    printf("[>] - Pressione Enter para continuar...");
    getchar();
}

void modulo_excluir_cliente(void)
{
    FILE *arq_cliente; 
    Cliente* cli;
    cli = (Cliente*) malloc(sizeof(Cliente));
    char cpf_cliente_ler[15];
    int c;
    bool cli_encontrado = false;
    char confirmar;

    system("clear||cls");
    printf("\n");
    printf("#=====================================================================#\n");
    printf("|                         --------------------                        |\n");
    printf("|                         | SIG - Rent a Car |                        |\n");
    printf("|                         --------------------                        |\n");
    printf("#=====================================================================#\n");
    printf("|                           EXCLUIR CLIENTES                          |\n");
    printf("#=====================================================================#\n");
    printf("\n");

    printf("[>] - Informe o CPF do funcionário que deseja excluir: ");
    scanf("%14s", cpf_cliente_ler);
    while ((c = getchar()) != '\n' && c != EOF);

    arq_cliente = fopen("cliente.dat","r+b");

    if (arq_cliente == NULL){
        printf("XXX - Erro ao abrir o arquivo!\n");
        printf("[>] - Pressione Enter para continuar...");
        getchar();
        exit(1);
    }

    while (fread(cli, sizeof(Cliente), 1, arq_cliente) == 1) {

        if (strcmp(cli->cpf_cliente, cpf_cliente_ler) == 0 && cli->status) {

            cli_encontrado = true;

            system("clear||cls");
            printf("#====================================================#\n");
            printf("|            [o] - Cliente encontrado!               |\n");
            printf("#====================================================#\n");
            printf("| > Nome: %s\n", cli->nome_cliente);
            printf("| > CPF: %s\n", cli->cpf_cliente);
            printf("| > Data de Nascimento: %s\n", cli->data_cliente);
            printf("| > Email: %s\n", cli->email_cliente);
            printf("| > CNH: %s\n", cli->cnh_cliente);
            printf("#====================================================#");

            printf("\n[?] - Deseja excluir o cliente? (S/N): ");
            scanf(" %c", &confirmar);
            while ((c = getchar()) != '\n' && c != EOF);

            if (confirmar == 'S' || confirmar == 's') {

                cli->status = false;

                fseek(arq_cliente, -sizeof(Cliente), SEEK_CUR);
                fwrite(cli, sizeof(Cliente), 1, arq_cliente);
                fflush(arq_cliente);

                printf("\n[o] - Cliente excluído com sucesso!\n");
            }
            else {
                printf("\n[o] - Exclusão cancelada.\n");
            }

            break;
        }
    }

    fclose(arq_cliente);
    free(cli);

    if (!cli_encontrado){
        printf("XXX - Cliente não encontrado...\n");
    }

    printf("\n[>] - Pressione Enter para continuar...");
    getchar();
}