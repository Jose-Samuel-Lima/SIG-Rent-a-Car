#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
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
    while ((c = getchar()) != '\n' && c != EOF)
        ;
    return op;
}

void modulo_cadastrar_veiculo(void)
{
    FILE *arq_veiculo;
    char placa[8];
    char chassi[18];
    char renavam[12];
    char categoria[7];
    char modelo[31];
    char marca[16];
    char ano[5];
    char codigo_interno[7];
    float preco;
    int c;

    system("clear||cls");
    printf("\n");
    printf("#=====================================================================#\n");
    printf("|                        --------------------                         |\n");
    printf("|                        | SIG - Rent a Car |                         |\n");
    printf("|                        --------------------                         |\n");
    printf("#=====================================================================#\n");
    printf("|                T ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ T             |\n");
    printf("|                | < = = =  Cadastrar Veículos  = = = > |             |\n");
    printf("|                T ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ T             |\n\n");

    printf("Placa do veículo: ");
    scanf("%7[A-Z0-9]", placa);
    while ((c = getchar()) != '\n' && c != EOF)
        ;

    printf("Chassi do veículo: ");
    scanf("%17[A-HJ-NP-Z0-9]", chassi);
    while ((c = getchar()) != '\n' && c != EOF)
        ;

    printf("Renavam do veículo: ");
    scanf("%11[0-9]", renavam);
    while ((c = getchar()) != '\n' && c != EOF)
        ;

    printf("Categoria do veículo: ");
    scanf("%6[A-Z]", categoria);
    while ((c = getchar()) != '\n' && c != EOF)
        ;

    printf("Modelo do veículo: ");
    scanf("%30[A-Za-z0-9 ]", modelo);
    while ((c = getchar()) != '\n' && c != EOF)
        ;

    printf("Marca do veículo: ");
    scanf("%15[A-Za-z ]", marca);
    while ((c = getchar()) != '\n' && c != EOF)
        ;

    printf("Ano do veículo: ");
    scanf("%4[0-9]", ano);
    while ((c = getchar()) != '\n' && c != EOF)
        ;

    printf("Código do veículo: ");
    scanf("%6[A-Z0-9]", codigo_interno);
    while ((c = getchar()) != '\n' && c != EOF)
        ;

    printf("Preço do veículo: ");
    scanf("%f", &preco);
    while ((c = getchar()) != '\n' && c != EOF)
        ;

    arq_veiculo = fopen("veiculo.csv", "at");
    if (arq_veiculo == NULL)
    {
        printf("Erro na criação do arquivo!");
        printf("Pressione Enter para continuar...");
        getchar();
        exit(1);
    }

    fprintf(arq_veiculo, "%s;", placa);
    fprintf(arq_veiculo, "%s;", chassi);
    fprintf(arq_veiculo, "%s;", renavam);
    fprintf(arq_veiculo, "%s;", categoria);
    fprintf(arq_veiculo, "%s;", modelo);
    fprintf(arq_veiculo, "%s;", marca);
    fprintf(arq_veiculo, "%s;", ano);
    fprintf(arq_veiculo, "%s;", codigo_interno);
    fprintf(arq_veiculo, "%f\n", preco);
    fclose(arq_veiculo);

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
    while ((c = getchar()) != '\n' && c != EOF)
        ;
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
    while ((c = getchar()) != '\n' && c != EOF)
        ;

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
    while ((c = getchar()) != '\n' && c != EOF)
        ;
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
        while ((c = getchar()) != '\n' && c != EOF)
            ;
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
        fgets(modelo_veiculo, sizeof(modelo_veiculo), stdin);
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
    while ((c = getchar()) != '\n' && c != EOF)
        ;
    system("cls||clear");
    printf("Pressione Enter para continuar...");
    getchar();
}