#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "relatorios.h"

int modulo_relatorio(void)
{
    int esc;
    do
    {
        esc = modulo_tela_relatorio();
        switch (esc)
        {
        case 1:
            modulo_relatorio_funcionarios();
            break;
        case 2:
            modulo_relatorio_clientes();
            break;
        case 3:
            modulo_relatorio_veiculos();
            break;
        case 4:
            modulo_relatorio_alugueis_ativos();
            break;
        case 5:
            modulo_relatorio_alugueis_finalizados();
            break;
        case 0:
            return -1;
        }

    } while (esc != 0);
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
    printf("|                    # 4 # Relatório de aluguéis ativos               |\n");
    printf("|                    # 5 # Relatório de aluguéis finalizados          |\n");
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

void modulo_relatorio_funcionarios(void)
{
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
    printf("|              T ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ T           |\n");
    printf("|              | < = = =  Dados dos Funcionários  = = = > |           |\n");
    printf("|              T ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ T           |\n");
    printf("|                                                                     |\n");
    printf("#=====================================================================#\n");
    printf("\n");
    getchar();
    system("cls||clear");
    printf("Pressione Enter para continuar...");
    getchar();
}

void modulo_relatorio_clientes(void)
{
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
    getchar();
    system("cls||clear");
    printf("Pressione Enter para continuar...");
    getchar();
}

void modulo_relatorio_veiculos(void)
{
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
    printf("|                | < = = =  Dados dos Veículos  = = = > |             |\n");
    printf("|                T ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ T             |\n");
    printf("|                                                                     |\n");
    printf("#=====================================================================#\n");
    printf("\n");
    getchar();
    system("cls||clear");
    printf("Pressione Enter para continuar...");
    getchar();
}

void modulo_relatorio_alugueis_ativos(void)
{
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
    printf("|                 T ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ T              |\n");
    printf("|                 | < = = =  Aluguéis  Ativos  = = = > |              |\n");
    printf("|                 T ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ T              |\n");
    printf("|                                                                     |\n");
    printf("#=====================================================================#\n");
    printf("\n");
    getchar();
    system("cls||clear");
    printf("Pressione Enter para continuar...");
    getchar();
}

void modulo_relatorio_alugueis_finalizados(void)
{
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
    printf("|               T ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ T              |\n");
    printf("|               | < = = =  Aluguéis  Inativos  = = = > |              |\n");
    printf("|               T ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ T              |\n");
    printf("|                                                                     |\n");
    printf("#=====================================================================#\n");
    printf("\n");
    getchar();
    system("cls||clear");
    printf("Pressione Enter para continuar...");
    getchar();
}