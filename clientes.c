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
<<<<<<< HEAD
    char cpf_cliente[14];
    char data_nascimento[15];
    char email[52];
    char cnh[14];
    int c;
=======
    char data_nascimento[15];
    char cpf_cliente[14];
    char email[52];
    char CNH[14];
>>>>>>> 4c2dc3ef91cdcfd41ebe880ca2d0eb5d5dc5194e
    
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
<<<<<<< HEAD
    scanf("%[A-ZÁÉÍÓÚÂÊÔÇÀÃÕ a-záéíóúâôêçãõà]", nome_cliente);
    while ((c = getchar()) != '\n' && c != EOF)
        ;
    printf("CPF do cliente: ");
    scanf("%[0-9.-]", cpf_cliente);
    while ((c = getchar()) != '\n' && c != EOF)
        ;
    printf("Data de Nascimento do cliente: ");
    scanf("%[0-9]/", data_nascimento);
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

=======
    scanf("%s[A-ZÁÉÍÓÚÂÊÔÇÀÃÕ a-záéíóúâôêçãõà]", nome_cliente);
    getchar();
    printf("Data de Nascimento do cliente: ");
    scanf("%s0-9/", data_nascimento);
    getchar();
    printf("CPF do cliente: ");
    scanf("%s[0-9.-]", cpf_cliente);
    getchar();
    printf("Email do cliente: ");
    scanf("%s[A-Za-z-z0-9@._]", email);
    getchar();
    printf("CNH do cliente: ");
    scanf("%s0-9", CNH);
    getchar();
    arq_cliente = fopen("cliente.txt","at");

>>>>>>> 4c2dc3ef91cdcfd41ebe880ca2d0eb5d5dc5194e
    if (arq_cliente == NULL){
        printf("Erro na criação do arquivo!");
        printf("Precione Enter para continuar...");
        getchar();
        exit(1);
    }
    fprintf(arq_cliente,"%s;", nome_cliente);
<<<<<<< HEAD
    fprintf(arq_cliente,"%s;", cpf_cliente);
    fprintf(arq_cliente,"%s;", data_nascimento);
    fprintf(arq_cliente,"%s;", email);
    fprintf(arq_cliente,"%s\n", cnh);
=======
    fprintf(arq_cliente,"%s;", data_nascimento);
    fprintf(arq_cliente,"%s;", cpf_cliente);
    fprintf(arq_cliente,"%s;", email);
    fprintf(arq_cliente,"%s\n", CNH);
>>>>>>> 4c2dc3ef91cdcfd41ebe880ca2d0eb5d5dc5194e
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
        printf("Precione Enter para continuar...");
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
<<<<<<< HEAD
    printf("\t\tInforme o CPf do cliente que deseja encontrar: \n");
    scanf("%15s", cpf_cliente);
=======
    printf("Informe o CPf do cliente que deseja encontrar: \n");
    scanf("%15s", cpf);
>>>>>>> 4c2dc3ef91cdcfd41ebe880ca2d0eb5d5dc5194e
    while ((c = getchar()) != '\n' && c != EOF)
        ;
    while (!feof(arq_cliente)) {

        if (fscanf(arq_cliente,"%[^;]", nome_cliente) != 1){
            break;
        }
        fgetc(arq_cliente);

        if (fscanf(arq_cliente,"%[^;]", cpf) != 1) {
            break;
        }
        fgetc(arq_cliente);

        if (fscanf(arq_cliente,"%[^;]", data_nascimento) != 1) {
            break;
        }
        fgetc(arq_cliente);

        if (fscanf(arq_cliente,"%[^;]", email) != 1) {
            break;
        }
        fgetc(arq_cliente);

        if (fscanf(arq_cliente,"%[^\n]", cnh) != 1){
            break;
        }
        fgetc(arq_cliente);

        if (strcmp(cpf,cpf_cliente) == 0) {
            printf("\t\t T ~~~~~~~~~~~~~~~~~~~~~~~~~~~ T\n");
            printf("\t\t < = = Cliente Encontrado! = = >\n");
            printf("\t\t T ~~~~~~~~~~~~~~~~~~~~~~~~~~~ T\n");
            printf("\t\t Nome: %s\n", nome_cliente);
            printf("\t\t CPF: %s\n", cpf);
            printf("\t\t Data Nasci.: %s\n", data_nascimento);
            printf("\t\t Email: %s\n", email);
            printf("\t\t CNH: %s\n", cnh);
            printf("\n");
            printf("\t\t Precione Enter para continuar...");
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
    char cpf_cliente[12];
    char choose;
    char nome_cliente[51];
    char data_nascimento[12];
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
    printf("[2] Nova Data de Nascimento\n");
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
        printf("Informe a nova data de nascimento: ");
        fgets(data_nascimento, sizeof(data_nascimento), stdin);
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