#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "veiculos.h"

int modulo_veiculo(void)
{
    int escVeiculo;
    do
    {
        escVeiculo = modulo_tela_veiculos();
        switch (escVeiculo)
        {
        case 1:
            modulo_cadastrar_veiculo();
            break;
        case 2:
            modulo_dados_veiculo();
            break;
        case 3:
            modulo_atualizar_veiculo();
            break;
        case 4:
            modulo_excluir_veiculo();
            break;
        case 0:
            return -1;
        }

    } while (escVeiculo != 0);
    return -1;
}

int modulo_tela_veiculos(void)
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
    printf("|                   < = = = Módulo de Veículos = = = >                |\n");
    printf("|                                                                     |\n");
    printf("|                    # 1 # Cadastrar novo veículo                     |\n");
    printf("|                    # 2 # Dados do veículo                           |\n");
    printf("|                    # 3 # Alterar dados do veículo                   |\n");
    printf("|                    # 4 # Excluir um veículo                         |\n");
    printf("|                    # 0 # Voltar ao menu principal                   |\n");
    printf("|                                                                     |\n");
    printf("#=====================================================================#\n");
    printf("\n");
    printf("Escolha uma das opções acima: \n");
    scanf(" %d", &op);
    while ((c = getchar()) != '\n' && c != EOF);
    return op;
}

void modulo_cadastrar_veiculo(void)
{
    char nome_veiculo[51];
    float preco_veiculo;
    char placa_veiculo[8];
    char marca[15];
    char modelo[13];
    char codigo_renavam[12];
    int c;

    printf("Nome do veículo: ");
    fgets(nome_veiculo, sizeof(nome_veiculo), stdin);

    printf("Preço do veículo: ");
    scanf("%f", &preco_veiculo);
    while ((c = getchar()) != '\n' && c != EOF);

    printf("Placa do veículo: ");
    fgets(placa_veiculo, sizeof(placa_veiculo), stdin);

    printf("Marca do veículo: ");
    fgets(marca, sizeof(marca), stdin);

    printf("Modelo do veículo: ");
    fgets(modelo, sizeof(modelo), stdin);

    printf("Código RENAVAM do veículo: ");
    fgets(codigo_renavam, sizeof(codigo_renavam), stdin);

    system("cls||clear");
    printf("Veículo Registrado com Sucesso!\n");
    printf("Pressione Enter para continuar...");
    getchar();
}

void modulo_dados_veiculo(void)
{
    int codigo_renavam[12];
    int c;

    system("cls||clear");
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
    printf("|                | < = = =  Dados dos Veículos  = = = > |             |\n");
    printf("|                T ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ T             |\n");
    printf("|                                                                     |\n");
    printf("#=====================================================================#\n");
    printf("\n");
    printf("Informe o Código da RENAVAM  para encontrar o veículo desejado: \n");
    scanf("%d", codigo_renavam);
    while ((c = getchar()) != '\n' && c != EOF);
    system("cls||clear");
    printf("Pressione Enter para continuar...");
    getchar();
}

void modulo_atualizar_veiculo(void)
{
    char codigo_renavam[13];
    char choose;
    char nome_veiculo[51];
    float preco_veiculo;
    char placa_veiculo[10];
    char marca[20];
    char modelo_veiculo[15];
    char novo_codigo_renavam[13];
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
    printf("|                | < = = =  Atualizar os Dados  = = = > |             |\n");
    printf("|                | < = = =     dos Veículos     = = = > |             |\n");
    printf("|                T ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ T             |\n");
    printf("|                                                                     |\n");
    printf("#=====================================================================#\n");
    printf("\n");
    printf("Informe o Código da RENAVAM para encontrar o veículo e atualizar seus dados: \n");
    scanf("%s", codigo_renavam);
    while ((c = getchar()) != '\n' && c != EOF);

    // fazer verificação quando fazer o armazenamento de dados

    system("clear||cls");
    printf("[1] Novo Nome\n");
    printf("[2] Nova Valor\n");
    printf("[3] Nova Placa\n");
    printf("[4] Nova Marca\n");
    printf("[5] Novo Modelo\n");
    printf("[6] Novo Código RENAVAM\n");
    printf("[0] Cancelar\n");
    printf("-----------------------\n");
    scanf(" %c", &choose);
    while ((c = getchar()) != '\n' && c != EOF);
    system("clear||cls");
    if (choose == '1')
    {
        printf("Informe o novo do veículo: ");
        fgets(nome_veiculo, sizeof(nome_veiculo), stdin);
    }
    else if (choose == '2')
    {
        printf("Informe o novo valor do veículo: ");
        scanf(" %f", &preco_veiculo);
        while ((c = getchar()) != '\n' && c != EOF);
    }
    else if (choose == '3')
    {
        printf("Informe a nova placa do veículo:");
        fgets(placa_veiculo, sizeof(placa_veiculo), stdin);
    }
    else if (choose == '4')
    {
        printf("Informe a nova marca do veículo: ");
        fgets(marca, sizeof(marca), stdin);
    }
    else if (choose == '5')
    {
        printf("Informe o novo modelo do veículo: ");
        fgets(modelo_veiculo,sizeof(modelo_veiculo), stdin);
    }
    else if (choose == '6')
    {
        printf("Informe o novo código RENAVAM do veículo: ");
        fgets(novo_codigo_renavam, sizeof(novo_codigo_renavam), stdin);
    }
    printf("Pressione enter para continuar...");
    getchar();
}

void modulo_excluir_veiculo(void)
{
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
    printf("|             | < = = =  Excluir dados do Veículo  = = = > |          |\n");
    printf("|             T ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ T          |\n");
    printf("|                                                                     |\n");
    printf("#=====================================================================#\n");
    printf("\n");
    printf("Informe o Código da RENAVAM  para encontrar o veículo que deseja excluir: \n");
    scanf("%c", codigo_renavam);
    while ((c = getchar()) != '\n' && c != EOF);
    system("cls||clear");
    printf("Pressione Enter para continuar...");
    getchar();
}