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
    return op;
}

void modulo_cadastrar_cliente(void)
{
    FILE *arq_cliente;
    char nome_cliente[52];
    char cpf_cliente[14];
    char data_nascimento[15];
    char email[52];
    char cnh[14];
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
    scanf("%[A-ZÁÉÍÓÚÂÊÔÇÀÃÕ a-záéíóúâôêçãõà]", nome_cliente);
    while ((c = getchar()) != '\n' && c != EOF)
        ;
    printf("CPF do cliente: ");
    scanf("%[0-9.-]", cpf_cliente);
    while ((c = getchar()) != '\n' && c != EOF)
        ;
    printf("Data de Nascimento do cliente: ");
    scanf("%[0-9/]", data_nascimento);
    while ((c = getchar()) != '\n' && c != EOF)
        ;
    printf("Email do cliente: ");
    scanf("%[A-Za-z-z0-9@._]", email);
    while ((c = getchar()) != '\n' && c != EOF)
        ;
    printf("CNH do cliente: ");
    scanf("%[0-9]", cnh);
    while ((c = getchar()) != '\n' && c != EOF)
        ;

    arq_cliente = fopen("cliente.csv","at");

    if (arq_cliente == NULL){
        printf("Erro na criação do arquivo!");
        printf("Pressione Enter para continuar...");
        getchar();
        exit(1);
    }
    fprintf(arq_cliente,"%s;", nome_cliente);
    fprintf(arq_cliente,"%s;", cpf_cliente);
    fprintf(arq_cliente,"%s;", data_nascimento);
    fprintf(arq_cliente,"%s;", email);
    fprintf(arq_cliente,"%s\n", cnh);
    fclose(arq_cliente);
    printf("Cliente Registrado com Sucesso!\n");
    printf("Pressione Enter para continuar...");
    getchar();
}

void modulo_dados_cliente(void)
{
    FILE *arq_cliente;
    arq_cliente = fopen("cliente.csv","rt");

    if (arq_cliente == NULL){
        printf("Erro na criação do arquivo!");
        printf("Pressione Enter para continuar...");
        getchar();
        exit(1);
    }

    char cpf[15];
    char nome_cliente[52];
    char cpf_cliente[15];
    char data_nascimento[15];
    char email[52];
    char cnh[14];
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
    scanf("%15s", cpf);
    while ((c = getchar()) != '\n' && c != EOF)
        ;

    while (fscanf(arq_cliente, "%[^;];%[^;];%[^;];%[^;];%[^\n]\n", nome_cliente, cpf_cliente, data_nascimento, email, cnh) == 5) {

        fgetc(arq_cliente);

        if (strcmp(cpf,cpf_cliente) == 0) {
            printf("\t\t T ~~~~~~~~~~~~~~~~~~~~~~~~~~~ T\n");
            printf("\t\t < = = Cliente Encontrado! = = >\n");
            printf("\t\t T ~~~~~~~~~~~~~~~~~~~~~~~~~~~ T\n");
            printf("\t\t Nome: %s\n", nome_cliente);
            printf("\t\t CPF: %s\n", cpf_cliente);
            printf("\t\t Data Nasci.: %s\n", data_nascimento);
            printf("\t\t Email: %s\n", email);
            printf("\t\t CNH: %s\n", cnh);
            printf("\n");
            printf("\t\t Pressione Enter para continuar...");
            getchar();
            fclose(arq_cliente);
            return;
        }
        
    }
    printf("Cliente não encontrado!\n");
    printf("Pressione Enter para continuar...");
    getchar();
    fclose(arq_cliente);
}

void modulo_atualizar_clientes(void)
{
    FILE *arq_cliente;
    arq_cliente = fopen("cliente.csv","rt");

    if (arq_cliente == NULL){
        printf("Erro ao entrar no arquivo!");
        printf("Pressione Enter para continuar...");
        getchar();
        exit(1);
    }

    FILE *arq_temp;
    arq_temp = fopen("cliente_temp.csv","wt");

    if (arq_temp== NULL){
        printf("Erro na criação do arquivo Temporário!\n");
        printf("Pressione Enter para continuar...");
        getchar();
        exit(1);
    }

    char cpf[15];
    char nome_cliente[52];
    char cpf_cliente[15];
    char data_nascimento[15];
    char email[52];
    char cnh[14];
    char opcao;
    int c;
    int encontrado = 0;

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
    scanf("%15s", cpf);
    while ((c = getchar()) != '\n' && c != EOF)
        ;

    while (fscanf(arq_cliente, "%[^;];%[^;];%[^;];%[^;];%[^\n]\n", nome_cliente, cpf_cliente, data_nascimento, email, cnh) == 5) {
        if (strcmp(cpf, cpf_cliente) == 0) {
            
            encontrado = 1;

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

            switch(opcao){
                case '1':
                    printf("Novo nome do cliente: ");
                    scanf("%[A-ZÁÉÍÓÚÂÊÔÇÀÃÕ a-záéíóúâôêçãõà]", nome_cliente);
                    while ((c = getchar()) != '\n' && c != EOF)
                        ;
                    break;

                case '2':
                    printf("Novo CPF do cliente: ");
                    scanf("%[0-9.-]", cpf_cliente);
                    while ((c = getchar()) != '\n' && c != EOF)
                        ;
                    break;

                case '3':
                    printf("Nova Data de Nasc. do cliente: ");
                    scanf("%[0-9/]", data_nascimento);
                    while ((c = getchar()) != '\n' && c != EOF)
                        ;
                    break;

                case '4':
                    printf("Novo email do cliente: ");
                    scanf("%[A-Za-z-z0-9@._]", email);
                    while ((c = getchar()) != '\n' && c != EOF)
                        ;
                    break;

                case '5':
                    printf("Nova CNH do cliente: ");
                    scanf("%[0-9]", cnh);
                    while ((c = getchar()) != '\n' && c != EOF)
                        ;
                    break;

                case '0':
                    printf("Voltando ao menu clientes.");
                    break;

                default:
                    printf("Opção inválida. Nenhum dado alterado.\n");
                    break;

            }

        }

        fprintf(arq_temp,"%s;", nome_cliente);
        fprintf(arq_temp,"%s;", cpf_cliente);
        fprintf(arq_temp,"%s;", data_nascimento);
        fprintf(arq_temp,"%s;", email);
        fprintf(arq_temp,"%s\n", cnh);

    }

    fclose(arq_cliente);
    fclose(arq_temp);

    if (encontrado){
            remove("cliente.csv");
            rename("cliente_temp.csv","cliente.csv");
            printf("Dado(s) do cliente alterado(s) com sucesso!\n");
        }
    else {
        remove("cliente_temp.csv");
        printf("Cliente não encontrado..\n");
    }

    printf("Pressione Enter para continuar...");
    getchar();
}

void modulo_excluir_cliente(void)
{
    FILE *arq_cliente;
    arq_cliente = fopen("cliente.csv","rt");

    if (arq_cliente == NULL){
        printf("Erro ao entrar no arquivo!");
        printf("Pressione Enter para continuar...");
        getchar();
        exit(1);
    }

    FILE *arq_temp;
    arq_temp = fopen("cliente_temp.csv","wt");

    if (arq_temp== NULL){
        printf("Erro na criação do arquivo Temporário!\n");
        printf("Pressione Enter para continuar...");
        getchar();
        exit(1);
    }

    char cpf[15];
    char nome_cliente[52];
    char cpf_cliente[15];
    char data_nascimento[15];
    char email[52];
    char cnh[14];
    int c;
    int encontrado = 0;

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
    scanf("%15s", cpf);
    while ((c = getchar()) != '\n' && c != EOF)
        ;
    while (fscanf(arq_cliente, "%[^;];%[^;];%[^;];%[^;];%[^\n]\n", nome_cliente, cpf_cliente, data_nascimento, email, cnh) == 5) {

        if (strcmp(cpf_cliente,cpf) != 0){

            fprintf(arq_temp,"%s;", nome_cliente);
            fprintf(arq_temp,"%s;", cpf_cliente);
            fprintf(arq_temp,"%s;", data_nascimento);
            fprintf(arq_temp,"%s;", email);
            fprintf(arq_temp,"%s\n", cnh);

        }
        else {
            encontrado = 1;
        }
    }

    fclose(arq_cliente);
    fclose(arq_temp);

    if (encontrado){
            remove("cliente.csv");
            rename("cliente_temp.csv","cliente.csv");
            printf("Cliente excluído com sucesso!\n");
        }
    else {
        remove("cliente_temp.csv");
        printf("Cliente não encontrado..\n");
    }

    printf("Pressione Enter para continuar...");
    getchar();
    
}