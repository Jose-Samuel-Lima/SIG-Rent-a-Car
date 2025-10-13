#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include "clientes.h"

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
            modulo_dados_cliente();
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
    printf("#=====================================================================#\n");
    printf("|                                                                     |\n");
    printf("|                        --------------------                         |\n");
    printf("|                        | SIG - Rent a Car |                         |\n");
    printf("|                        --------------------                         |\n");
    printf("|                                                                     |\n");
    printf("#=====================================================================#\n");
    printf("|                                                                     |\n");
    printf("|                   < = = = Módulo Cliente = = = >                    |\n");
    printf("|                                                                     |\n");
    printf("|                    # 1 # Cadastrar novo cliente                     |\n");
    printf("|                    # 2 # Dados do cliente                           |\n");
    printf("|                    # 3 # Alterar dados do cliente                   |\n");
    printf("|                    # 4 # Excluir um cliente                         |\n");
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

void modulo_cadastrar_cliente(void)
{
    FILE *arq_cliente;
    Cliente* cli;
    cli = (Cliente*) malloc(sizeof(Cliente));
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
    printf("|                T ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ T             |\n");
    printf("|                | < = = =  Cadastrar Clientes  = = = > |             |\n");
    printf("|                T ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ T             |\n");
    printf("|                                                                     |\n");
    printf("#=====================================================================#\n");
    printf("\n");

    printf("Nome do cliente: ");
    scanf(" %99[^\n]", cli->nome_cliente);
    while ((c = getchar()) != '\n' && c != EOF)
        ;
    printf("CPF do cliente: ");
    scanf("%14s", cli->cpf_cliente);
    while ((c = getchar()) != '\n' && c != EOF)
        ;
    printf("Data de Nascimento do cliente: ");
    scanf("%10s", cli->data_nascimento);
    while ((c = getchar()) != '\n' && c != EOF)
        ;
    printf("Email do cliente: ");
    scanf("%99s", cli->email_cliente);
    while ((c = getchar()) != '\n' && c != EOF)
        ;
    printf("CNH do cliente: ");
    scanf("%19s", cli->cnh);
    while ((c = getchar()) != '\n' && c != EOF)
        ;
    
    cli->status = true;

    arq_cliente = fopen("cliente.dat","ab");

    if (arq_cliente == NULL){
        printf("Erro ao abrir o arquivo!");
        printf("Pressione Enter para continuar...");
        getchar();
        exit(1);
    }

    fwrite(cli, sizeof(Cliente), 1, arq_cliente);

    fclose(arq_cliente);
    free(cli);

    printf("Cliente Registrado com Sucesso!\n");
    printf("Pressione Enter para continuar...");
    getchar();
}

void modulo_dados_cliente(void)
{
    FILE *arq_cliente;
    Cliente* cli;
    cli = (Cliente*) malloc(sizeof(Cliente));
    arq_cliente = fopen("cliente.dat","rb");

    if (arq_cliente == NULL){
        printf("Erro ao abrir o arquivo!");
        printf("Pressione Enter para continuar...");
        getchar();
        exit(1);
    }

    char cpf_ler[15];
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
    printf("|                T ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ T             |\n");
    printf("|                | < = = =  Dados dos Clientes  = = = > |             |\n");
    printf("|                T ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ T             |\n");
    printf("|                                                                     |\n");
    printf("#=====================================================================#\n");
    printf("\n");
    printf("\t\tInforme o CPf do cliente que deseja encontrar: \n");
    scanf("%15s", cpf_ler);
    while ((c = getchar()) != '\n' && c != EOF)
        ;

    while (fread(cli,sizeof(Cliente),1,arq_cliente)) {

        if (strcmp(cpf_ler,cli->cpf_cliente) == 0 && cli->status == true) {
            printf("\t\t T ~~~~~~~~~~~~~~~~~~~~~~~~~~~ T\n");
            printf("\t\t < = = Cliente Encontrado! = = >\n");
            printf("\t\t T ~~~~~~~~~~~~~~~~~~~~~~~~~~~ T\n");
            printf("\t\t Nome: %s\n", cli->nome_cliente);
            printf("\t\t CPF: %s\n", cli->cpf_cliente);
            printf("\t\t Data Nasci.: %s\n", cli->data_nascimento);
            printf("\t\t Email: %s\n", cli->email_cliente);
            printf("\t\t CNH: %s\n", cli->cnh);
            printf("\n");
            printf("\t\t Pressione Enter para continuar...");
            getchar();
            return;
        }
        
    }

    fclose(arq_cliente);
    free(cli);
    printf("Cliente não encontrado!\n");
    printf("Pressione Enter para continuar...");
    getchar();
}

void modulo_atualizar_clientes(void)
{
    FILE *arq_cliente;
    Cliente* cli;
    cli = (Cliente*) malloc(sizeof(Cliente));
    arq_cliente = fopen("cliente.dat","r+b");

    if (arq_cliente == NULL){
        printf("Erro ao abrir o arquivo!");
        printf("Pressione Enter para continuar...");
        getchar();
        exit(1);
    }

    char cpf_ler[15];
    char opcao;
    int c;
    int encontrado = false;

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
    printf("|             T ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ T          |\n");
    printf("|             | < = = =  Alterar dados do Cliente  = = = > |          |\n");
    printf("|             T ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ T          |\n");
    printf("|                                                                     |\n");
    printf("#=====================================================================#\n");
    printf("\n");
    printf("Informe o CPf do cliente para alterar os dados: \n");
    scanf("%15s", cpf_ler);
    while ((c = getchar()) != '\n' && c != EOF)
        ;

    while ((fread(cli,sizeof(Cliente),1,arq_cliente) == 1)) {
        if (strcmp(cli->cpf_cliente,cpf_ler) == 0 && cli->status) {
            
            encontrado = true;

            system("clear||cls");
            printf("Cliente encontrado!\n");
            printf("Informe qual informação deseja alterar:\n");
            printf("\n");
            printf("---------------------------\n");
            printf("[1] Novo Nome\n");
            printf("[2] Novo Cpf\n");
            printf("[3] Nova Data de Nascimento\n");
            printf("[4] Novo E-mail\n");
            printf("[5] Nova CNH\n");
            printf("[0] Cancelar\n");
            printf("---------------------------\n");
            scanf(" %c", &opcao);
            while ((c = getchar()) != '\n' && c != EOF)
                ;

            int alt = 0;

            switch(opcao){
                case '1':
                    printf("Novo nome do cliente: ");
                    scanf(" %99[^\n]", cli->nome_cliente);
                    while ((c = getchar()) != '\n' && c != EOF)
                        ;
                    alt = 1;
                    break;

                case '2':
                    printf("Novo CPF do cliente: ");
                    scanf("%14s", cli->cpf_cliente);
                    while ((c = getchar()) != '\n' && c != EOF)
                        ;
                    alt = 1;
                    break;

                case '3':
                    printf("Nova Data de Nasc. do cliente: ");
                    scanf("%10s", cli->data_nascimento);
                    while ((c = getchar()) != '\n' && c != EOF)
                        ;
                    alt = 1;
                    break;

                case '4':
                    printf("Novo email do cliente: ");
                    scanf("%99s", cli->email_cliente);
                    while ((c = getchar()) != '\n' && c != EOF)
                        ;
                    alt = 1;
                    break;

                case '5':
                    printf("Nova CNH do cliente: ");
                    scanf("%19s", cli->cnh);
                    while ((c = getchar()) != '\n' && c != EOF)
                        ;
                    alt = 1;
                    break;

                case '0':
                    printf("Voltando ao menu clientes.");
                    break;

                default:
                    printf("Opção inválida. Nenhum dado alterado.\n");
                    break;

            }
            if (alt){

                fseek(arq_cliente, -sizeof(Cliente), SEEK_CUR);
                fwrite(cli, sizeof(Cliente), 1, arq_cliente);
                fflush(arq_cliente);
                printf("Dado(s) alterado(s) com sucesso!\n");

            }
            
            break;
        }
    }

    if (!encontrado){
        printf("Cliente não encontrado!\n");
    }

    fclose(arq_cliente);
    free(cli);
    printf("Pressione Enter para continuar...");
    getchar();
}

void modulo_excluir_cliente(void)
{
    FILE *arq_cliente;
    Cliente* cli;
    cli = (Cliente*) malloc(sizeof(Cliente));
    char cpf_ler[15];
    int c;
    bool encontrado;

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
    printf("|             T ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ T          |\n");
    printf("|             | < = = =  Excluir dados do Cliente  = = = > |          |\n");
    printf("|             T ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ T          |\n");
    printf("|                                                                     |\n");
    printf("#=====================================================================#\n");
    printf("\n");
    printf("Informe o CPf do cliente que deseja excluir:\n");
    scanf("%15s", cpf_ler);
    while ((c = getchar()) != '\n' && c != EOF)
        ;
        
    encontrado = false;

    arq_cliente = fopen("cliente.dat","r+b");

    if (arq_cliente == NULL){
        printf("Erro ao entrar no arquivo!");
        printf("Pressione Enter para continuar...");
        getchar();
        exit(1);
    }

    while ((fread(cli,sizeof(Cliente),1,arq_cliente) == 1) && (!encontrado)) {

        if (strcmp(cli->cpf_cliente,cpf_ler) == 0){

            cli->status = false;
            fseek(arq_cliente,(-1)*sizeof(Cliente),SEEK_CUR);
            fwrite(cli, sizeof(Cliente), 1, arq_cliente);
            encontrado = true;

            printf("Cliente excluido com sucesso!\n");
            break;
            }
        }

    fclose(arq_cliente);
    free(cli);
    if (!encontrado){
            printf("Cliente não encontrado..\n");
        }

    printf("Pressione Enter para continuar...");
    getchar();
    
}