#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "alugueis.h"

int modulo_aluguel(void)
{
    int escAluguel;
    do
    {
        escAluguel = modulo_tela_alugueis();
        switch (escAluguel)
        {
        case 1:
            modulo_cadastrar_aluguel();
            break;
        case 2:
            modulo_dados_aluguel();
            break;
        case 3:
            modulo_atualizar_aluguel();
            break;
        case 4:
            modulo_finalizar_aluguel();
            break;
        case 0:
            return -1;
        }

    } while (escAluguel != 0);
    return -1;
}

int modulo_tela_alugueis(void)
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
    printf("|                   < = = = Módulo de Aluguéis = = = >                |\n");
    printf("|                                                                     |\n");
    printf("|                    # 1 # Cadastrar novo aluguel                     |\n");
    printf("|                    # 2 # Dados do aluguel                           |\n");
    printf("|                    # 3 # Alterar dados do aluguel                   |\n");
    printf("|                    # 4 # Finalizar aluguel                          |\n");
    printf("|                    # 0 # Voltar ao menu principal                   |\n");
    printf("|                                                                     |\n");
    printf("#=====================================================================#\n");
    printf("\n");
    printf("Escolha uma das opções acima: \n");
    scanf(" %d", &op);
    while ((c = getchar()) != '\n' && c != EOF);
    printf("Processando...\n");
    return op;
}

void modulo_cadastrar_aluguel(void)
{
    char nome_cliente[51];
    char cpf_cliente[12];
    char codigo_renavam[12];
    char modelo_veiculo[15];
    int id_aluguel;
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
    printf("|                | < = = =  Cadastrar  Aluguel  = = = > |             |\n");
    printf("|                T ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ T             |\n");
    printf("|                                                                     |\n");
    printf("#=====================================================================#\n");
    printf("\n");

    printf("Nome do cliente: ");
    fgets(nome_cliente, sizeof(nome_cliente), stdin);

    printf("CPF do cliente: ");
    fgets(cpf_cliente, sizeof(cpf_cliente), stdin);

    printf("Modelo do veículo alugado: ");
    fgets(modelo_veiculo, sizeof(modelo_veiculo), stdin);

    printf("Código RENAVAM do veículo alugado: ");
    fgets(codigo_renavam, sizeof(codigo_renavam), stdin);

    printf("Id do aluguel: ");
    scanf("%d", &id_aluguel);
    while ((c = getchar()) != '\n' && c != EOF);

    system("cls||clear");
    printf("Aluguel Registrado com Sucesso!\n");
    printf("Pressione Enter para continuar...");
    getchar();
}

void modulo_dados_aluguel(void)
{
    int id_aluguel;
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
    printf("|                | < = = =   Dados do Aluguel   = = = > |             |\n");
    printf("|                T ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ T             |\n");
    printf("|                                                                     |\n");
    printf("#=====================================================================#\n");
    printf("\n");
    printf("Informe o Id do aluguel que deseja encontrar: \n");
    scanf("%d", &id_aluguel);
    while ((c = getchar()) != '\n' && c != EOF)
        ;
    system("cls||clear");
    printf("Pressione Enter para continuar...");
    getchar();
}

void modulo_atualizar_aluguel(void)
{
    int id_aluguel;
    char choose;
    char nome_cliente[51];
    char novo_cpf_cliente[12];
    char modelo_veiculo[15];
    char codigo_renavam[12];
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
    printf("|             | < = = =  Alterar dados do Aluguel  = = = > |          |\n");
    printf("|             T ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ T          |\n");
    printf("|                                                                     |\n");
    printf("#=====================================================================#\n");
    printf("\n");
    printf("Informe o Id do aluguel para alterar os dados: \n");
    scanf("%d", &id_aluguel);
    while ((c = getchar()) != '\n' && c != EOF)
        ;

    // fazer verificação quando fazer o armazenamento de dados

    system("clear||cls");
    printf("[1] Novo Nome: \n");
    printf("[2] Novo CPF: \n");
    printf("[3] Novo Modelo: \n");
    printf("[4] Novo Código RENAVAM: \n");
    printf("[0] Cancelar\n");
    printf("-----------------------\n");
    scanf(" %c", &choose);
    while ((c = getchar()) != '\n' && c != EOF)
        ;
    system("clear||cls");
    if (choose == '1')
    {
        printf("Informe o novo nome do cliente: ");
        fgets(nome_cliente, sizeof(nome_cliente), stdin);
    }
    else if (choose == '2')
    {
        printf("Informe o novo CPF do cliente: ");
        scanf(" %s", novo_cpf_cliente);
        while ((c = getchar()) != '\n' && c != EOF)
            ;
    }
    else if (choose == '3')
    {
        printf("Informe o novo modelo do veículo: ");
        fgets(modelo_veiculo, sizeof(modelo_veiculo), stdin);
    }
    else if (choose == '4')
    {
        printf("Informe o novo código RENAVAM do veículo: ");
        fgets(codigo_renavam,sizeof(codigo_renavam), stdin);
    }
    printf("Pressione enter para continuar...");
    getchar();
}

void modulo_finalizar_aluguel(void)
{
    int id_aluguel;
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
    printf("|             | < = = =  Excluir dados do Aluguel  = = = > |          |\n");
    printf("|             T ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ T          |\n");
    printf("|                                                                     |\n");
    printf("#=====================================================================#\n");
    printf("\n");
    printf("Informe o Id do aluguel que deseja excluir: \n");
    scanf("%d", &id_aluguel);
    while ((c = getchar()) != '\n' && c != EOF)
        ;
    system("cls||clear");
    printf("Pressione Enter para continuar...");
    getchar();
}