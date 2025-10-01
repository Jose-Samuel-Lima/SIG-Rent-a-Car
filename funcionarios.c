#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
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
    return op;
}

void modulo_cadastrar_funcionario(void)
{
    FILE *arq_funcionario;
    char nome_funcionario[51];
    char dt_nascimento_fun[12];
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
    scanf("%[A-ZÁÉÍÓÚÂÊÔÇÀÃÕ a-záéíóúâôêçãõà]", nome_funcionario);
    while ((c = getchar()) != '\n' && c != EOF)
        ;
    printf("CPF do funcionário: ");
    scanf("%[0-9.-]", cpf_funcionario);
    while ((c = getchar()) != '\n' && c != EOF)
        ;
    printf("Data de Nascimento do funcionário: ");
    scanf("%[0-9/]", dt_nascimento_fun);
    while ((c = getchar()) != '\n' && c != EOF)
        ;
    printf("Email do funcionário: ");
    scanf("%[A-Za-z-z0-9@._]", email);
    while ((c = getchar()) != '\n' && c != EOF)
        ;
    printf("Cargo do funcionário: ");
    scanf("%[A-ZÁÉÍÓÚÂÊÔÇÀÃÕ a-záéíóúâôêçãõà]", cargo);
    while ((c = getchar()) != '\n' && c != EOF)
        ;

    arq_funcionario = fopen("funcionario.csv","at");

    if (arq_funcionario == NULL){
        printf("Erro na criação do arquivo!");
        printf("Pressione Enter para continuar...");
        getchar();
        exit(1);
    }

    fprintf(arq_funcionario,"%s;", nome_funcionario);
    fprintf(arq_funcionario,"%s;", cpf_funcionario);
    fprintf(arq_funcionario,"%s;", dt_nascimento_fun);
    fprintf(arq_funcionario,"%s;", email);
    fprintf(arq_funcionario,"%s\n", cargo);
    fclose(arq_funcionario);
    printf("Funcionário Registrado com Sucesso!\n");
    printf("Pressione Enter para continuar...");
    getchar();
}

void modulo_dados_funcionario(void)
{
    FILE *arq_funcionario;
    char cpf[15];
    char nome_funcionario[51];
    char dt_nascimento_fun[12];
    char cpf_funcionario[12];
    char cargo[30];
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
    printf("|               T ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ T            |\n");
    printf("|               | < = = =  Dados do Funcionário  = = = > |            |\n");
    printf("|               T ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ T            |\n");
    printf("|                                                                     |\n");
    printf("#=====================================================================#\n");
    printf("\n");
    printf("Informe o CPf do funcionário que deseja encontrar: \n");
    scanf("%15s", cpf);
    while ((c = getchar()) != '\n' && c != EOF)
        ;

    arq_funcionario = fopen("funcionario.csv","rt");

    if (arq_funcionario == NULL){
        printf("Erro na criação do arquivo!");
        printf("Pressione Enter para continuar...");
        getchar();
        exit(1);
    }
    while (!feof(arq_funcionario)) {

        if (fscanf(arq_funcionario,"%[^;]", nome_funcionario) != 1){
            break;
        }
        fgetc(arq_funcionario);

        if (fscanf(arq_funcionario,"%[^;]", cpf_funcionario) != 1) {
            break;
        }
        fgetc(arq_funcionario);

        if (fscanf(arq_funcionario,"%[^;]", dt_nascimento_fun) != 1) {
            break;
        }
        fgetc(arq_funcionario);

        if (fscanf(arq_funcionario,"%[^;]", email) != 1) {
            break;
        }
        fgetc(arq_funcionario);

        if (fscanf(arq_funcionario,"%[^\n]", cargo) != 1) {
            break;
        }
        fgetc(arq_funcionario);

        if (strcmp(cpf,cpf_funcionario) == 0) {
            printf("\t\t T ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ T\n");
            printf("\t\t < = = Funcionário Encontrado! = = >\n");
            printf("\t\t T ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ T\n");
            printf("\t\t Nome: %s\n", nome_funcionario);
            printf("\t\t CPF: %s\n", cpf_funcionario);
            printf("\t\t Data Nasci.: %s\n", dt_nascimento_fun);
            printf("\t\t Email: %s\n", email);
            printf("\t\t CNH: %s\n", cargo);
            printf("\n");
            printf("\t\t Pressione Enter para continuar...");
            getchar();
            fclose(arq_funcionario);
            return;
        }
        
    }
    printf("Funcionário não encontrado!\n");
    printf("Pressione Enter para continuar...");
    getchar();
    fclose(arq_funcionario);
}

void modulo_atualizar_funcionario(void)
{
    char cpf[12];
    char choose;
    char nome_funcionario[51];
    char dt_nascimento_fun[12];
    char novo_cpf[12];
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
    printf("[2] Nova Data de Nascimento\n");
    printf("[3] Novo Cpf\n");
    printf("[4] Novo Cargo\n");
    printf("[5] Novo E-mail\n");
    printf("[0] Cancelar\n");
    printf("-----------------------\n");
    scanf(" %c", &choose);
    while ((c = getchar()) != '\n' && c != EOF)
        ;
    system("clear||cls");

    if (choose == '1')
    {
        printf("Selecione o novo nome do funcionário: ");
        fgets(nome_funcionario, sizeof(nome_funcionario), stdin);
    }
    else if (choose == '2')
    {
        printf("Selecione a nova data de nascimento do funcionário: ");
        fgets(dt_nascimento_fun, sizeof(dt_nascimento_fun), stdin);
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
    printf("Pressione Enter para continuar...");
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