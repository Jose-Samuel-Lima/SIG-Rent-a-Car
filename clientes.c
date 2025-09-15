#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
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
    printf("\n");
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
    // sleep(1);
    return op;
}

void modulo_cadastrar_cliente(void)
{
    char nome_cliente[51];
    int idade_cliente;
    char cpf_cliente[12];
    char email[30];
    char CNH[13];
    int c;

    printf("Nome do cliente: ");
    fgets(nome_cliente, sizeof(nome_cliente), stdin);

    printf("Idade do cliente: ");
    scanf("%d", &idade_cliente);
    while ((c = getchar()) != '\n' && c != EOF)
        ;
    printf("CPF do cliente: ");
    fgets(cpf_cliente, sizeof(cpf_cliente), stdin);

    printf("Email do cliente: ");
    fgets(email, sizeof(email), stdin);

    printf("CNH do cliente: ");
    fgets(CNH, sizeof(CNH), stdin);

    system("cls||clear");
    printf("Cliente Registrado com Sucesso!\n");
    printf("Pressione Enter para continuar...");
    getchar();
}

void modulo_dados_cliente(void)
{
    char cpf[15];
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
    printf("Informe o CPf do cliente que deseja encontrar: \n");
    scanf("%14s", cpf);
    while ((c = getchar()) != '\n' && c != EOF)
        ;
    system("cls||clear");
    printf("Pressione Enter para continuar...");
    getchar();
}

void modulo_atualizar_clientes(void)
{
    char cpf_cliente[12];
    char choose;
    char nome_cliente[51];
    int idade_cliente;
    char novo_cpf_cliente[12];
    char email[30];
    char CNH[13];
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
    printf("|             T ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ T          |\n");
    printf("|             | < = = =  Alterar dados do Cliente  = = = > |          |\n");
    printf("|             T ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ T          |\n");
    printf("|                                                                     |\n");
    printf("#=====================================================================#\n");
    printf("\n");
    printf("Informe o CPf do cliente para alterar os dados: \n");
    scanf("%14s", cpf_cliente);
    while ((c = getchar()) != '\n' && c != EOF)
        ;

    // fazer verificação quando fazer o armazenamento de dados

    system("clear||cls");
    printf("[1] Novo Nome\n");
    printf("[2] Nova Idade\n");
    printf("[3] Novo Cpf\n");
    printf("[4] Novo E-mail\n");
    printf("[5] Novo nº CNH\n");
    printf("[0] Cancelar\n");
    printf("-----------------------\n");
    scanf(" %c", &choose);
    while ((c = getchar()) != '\n' && c != EOF)
        ;
    system("clear||cls");
    if (choose == '1')
    {
        printf("Informe o novo nome: ");
        fgets(nome_cliente, sizeof(nome_cliente), stdin);
    }
    else if (choose == '2')
    {
        printf("Informe a nova idade: ");
        scanf(" %d", &idade_cliente);
        while ((c = getchar()) != '\n' && c != EOF)
            ;
    }
    else if (choose == '3')
    {
        printf("Informe o novo CPF: ");
        scanf(" %s", novo_cpf_cliente);
        while ((c = getchar()) != '\n' && c != EOF)
            ;
    }
    else if (choose == '4')
    {
        printf("Informe o novo E-mail: ");
        scanf(" %s", email);
        while ((c = getchar()) != '\n' && c != EOF)
            ;
    }
    else if (choose == '5')
    {
        printf("Informe o novo número da CNH: ");
        fgets(CNH, sizeof(CNH), stdin);
    }
    printf("Pressione enter para continuar...");
    getchar();
}

void modulo_excluir_cliente(void)
{
    char cpf[15];
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
    printf("|             T ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ T          |\n");
    printf("|             | < = = =  Excluir dados do Cliente  = = = > |          |\n");
    printf("|             T ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ T          |\n");
    printf("|                                                                     |\n");
    printf("#=====================================================================#\n");
    printf("\n");
    printf("Informe o CPf do cliente que deseja excluir: \n");
    scanf("%14s", cpf);
    while ((c = getchar()) != '\n' && c != EOF)
        ;
    system("cls||clear");
    printf("Pressione Enter para continuar...");
    getchar();
}