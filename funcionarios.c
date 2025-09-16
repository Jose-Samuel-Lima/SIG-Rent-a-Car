#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "funcionarios.h"

int modulo_funcionario(void)
{
    int escFunc;
    do
    {
        escFunc = modulo_tela_funcionario();
        switch (escFunc)
        {
        case 1:
            modulo_cadastrar_funcionario();
            break;
        case 2:
            modulo_dados_funcionario();
            break;
        case 3:
            modulo_atualizar_funcionario();
            break;
        case 4:
            modulo_excluir_funcionario();
            break;
        case 0:
            return -1;
        }

    } while (escFunc != 0);
    return -1;
}

int modulo_tela_funcionario(void)
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
    printf("|                 < = = = Módulo de Funcionários = = = >              |\n");
    printf("|                                                                     |\n");
    printf("|                    # 1 # Cadastrar novo funcionário                 |\n");
    printf("|                    # 2 # Dados do funcionário                       |\n");
    printf("|                    # 3 # Alterar dados do funcionário               |\n");
    printf("|                    # 4 # Excluir um funcionário                     |\n");
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

void modulo_cadastrar_funcionario(void)
{
    char nome_funcionario[51];
    int idade_funcionario;
    char cpf_funcionario[12];
    char cargo[22];
    char email[30];
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
    printf("|               T ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ T           |\n");
    printf("|               | < = = =  Cadastrar Funcionário  = = = > |           |\n");
    printf("|               T ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ T           |\n");
    printf("|                                                                     |\n");
    printf("#=====================================================================#\n");
    printf("\n");

    printf("Nome do funcionário: ");
    fgets(nome_funcionario, sizeof(nome_funcionario), stdin);

    printf("Idade do funcionário: ");
    scanf("%d", &idade_funcionario);

    printf("CPF do funcionário: ");
    fgets(cpf_funcionario, sizeof(cpf_funcionario), stdin);

    printf("Cargo do funcionário: ");
    fgets(cargo, sizeof(cargo), stdin);

    printf("Email do funcionário: ");
    fgets(email, sizeof(email), stdin);

    while ((c = getchar()) != '\n' && c != EOF)
    system("cls||clear");
    printf("Funcionário Registrado com Sucesso!\n");
    printf("Pressione Enter para continuar...");
    getchar();
}

void modulo_dados_funcionario(void)
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
    printf("|               T ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ T            |\n");
    printf("|               | < = = =  Dados do Funcionário  = = = > |            |\n");
    printf("|               T ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ T            |\n");
    printf("|                                                                     |\n");
    printf("#=====================================================================#\n");
    printf("\n");
    printf("Informe o CPf do funcionário que deseja encontrar: \n");
    scanf("%14s", cpf);
    while ((c = getchar()) != '\n' && c != EOF)
        ;
    system("cls||clear");
    printf("Pressione Enter para continuar...");
    getchar();
}

void modulo_atualizar_funcionario(void)
{
    char cpf[12];
    char choose;
    char nome_funcionario[51];
    char novo_cpf[12];
    char cargo[22];
    char email[30];
    int idade;
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
    printf("|           T ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ T          |\n");
    printf("|           | < = = =  Alterar dados do Funcionário  = = = >          |\n");
    printf("|           T ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ T          |\n");
    printf("|                                                                     |\n");
    printf("#=====================================================================#\n");
    printf("\n");
    printf("Informe o CPf do funcionário para alterar os dados: \n");
    scanf("%14s", cpf);
    while ((c = getchar()) != '\n' && c != EOF)
        ;

    // fazer verificação quando fazer o armazenamento de dados

    system("clear||cls");
    printf("[1] Novo Nome\n");
    printf("[2] Nova Idade\n");
    printf("[3] Novo Cpf\n");
    printf("[4] Novo Cargo\n");
    printf("[5] Novo E-mail\n");
    printf("[0] Cancelar\n");
    printf("-----------------------\n");
    scanf(" %c", &choose);
    system("clear||cls");
    if (choose == '1')
    {
        printf("Selecione o novo nome do funcionário: ");
        fgets(nome_funcionario, sizeof(nome_funcionario), stdin);
    }
    else if (choose == '2')
    {
        printf("Selecione a nova idade do funcionário: ");
        scanf(" %d", &idade);
        while ((c = getchar()) != '\n' && c != EOF)
        ;
    }
    else if (choose == '3')
    {
        printf("Selecione o novo CPF do funcionário: ");
        fgets(novo_cpf,sizeof(novo_cpf), stdin);
    }
    else if (choose == '4')
    {
        printf("Selecione o novo cargo do funcionário: ");
        fgets(cargo, sizeof(cargo), stdin);
    }
    else if (choose == '5')
    {
        printf("Selecione o novo E-mail do funcionário: ");
        fgets(email, sizeof(email), stdin);
        
    }
    printf("Pressione enter para continuar...");
    getchar();
}

void modulo_excluir_funcionario(void)
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
    printf("|           T ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ T        |\n");
    printf("|           | < = = =  Excluir dados do Funcionário  = = = > |        |\n");
    printf("|           T ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ T        |\n");
    printf("|                                                                     |\n");
    printf("#=====================================================================#\n");
    printf("\n");
    printf("Informe o CPf do funcionário que deseja excluir: \n");
    scanf("%14s", cpf);
    while ((c = getchar()) != '\n' && c != EOF)
        ;
    system("cls||clear");
    printf("Pressione Enter para continuar...");
    getchar();
}