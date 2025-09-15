#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "clientes.h"
 
char modulo_cliente(void){
    char esc;
    do {
        esc = modulo_tela_cliente();
        switch (esc) {
            case '1': modulo_cadastrar_cliente();
                    break;
            case '2': modulo_dados_cliente();
                    break;
            case '3': modulo_atualizar_clientes();
                    break;
            case '4': modulo_excluir_cliente();
                    break;
        }
    
    }while (esc != '0');
    return esc;
}

char modulo_tela_cliente(void) {

    char op;
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
    printf("|                   Escolha uma das opções...                         |\n");
    printf("|                                                                     |\n");
    printf("#=====================================================================#\n");
    printf("\n");
    scanf(" %c", &op);
    printf("\n");
    printf("\t\t\tProcessando...\n");
    //sleep(1);
    return op;
}

void modulo_cadastrar_cliente(void) {
    char nome_cliente[51];
    int idade_cliente;
    char cpf_cliente[12];
    char email[30];
    char CNH[13];

    printf("Nome do cliente: ");
    getchar();
    fgets(nome_cliente, sizeof(nome_cliente), stdin);
    printf("Idade do cliente: ");
    getchar();
    scanf("%d", &idade_cliente);
    printf("CPF do cliente: ");
    getchar();
    fgets(cpf_cliente, sizeof(cpf_cliente), stdin);
    printf("Email do cliente: ");
    getchar();
    fgets(email, sizeof(email), stdin);
    printf("CNH do cliente: ");
    getchar();
    fgets(CNH, sizeof(CNH), stdin);
    system("cls||clear");
    printf("Cliente Registrado com Sucesso!\n");
    printf("Pressione Enter para continuar...");
    getchar();
}

void modulo_dados_cliente(void)
{
    char cpf[15];

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
    printf("|       Por favor informe o CPf do cliente que deseja encontrar:      |\n");
    printf("|                                                                     |\n");
    printf("|                    + CPF do cliente:                                |\n");
    printf("|                                                                     |\n");
    printf("#=====================================================================#\n");
    printf("\n");
    scanf("%14s", cpf);
    getchar();
    system("cls||clear");
    printf("Pressione Enter para continuar...");
    getchar();
}
  
void modulo_atualizar_clientes(void) {
    char cpf_cliente[12];
    char choose;
    char nome_cliente[51];
    int idade_cliente;
    char novo_cpf_cliente[12];
    char email[30];
    char CNH[13];

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
    printf("|      Por favor informe o CPf do cliente para alterar os dados:      |\n");
    printf("|                                                                     |\n");
    printf("|                    + CPF do cliente:                                |\n");
    printf("|                                                                     |\n");
    printf("#=====================================================================#\n");
    printf("\n");
    scanf("%14s", cpf_cliente);
    getchar();


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
    system("clear||cls");
    if (choose == '1') {
        printf("Informe o novo nome: ");
        getchar();
        fgets(nome_cliente, sizeof(nome_cliente), stdin);
    } else if (choose == '2') {
        printf("Informe a nova idade: ");
        scanf(" %d", &idade_cliente);
        getchar();
    } else if (choose == '3') {
        printf("Informe o novo CPF: ");
        scanf(" %s", novo_cpf_cliente);
        getchar();
    } else if (choose == '4') {
        printf("Informe o novo E-mail: ");
        scanf(" %s", email);
        getchar();
    } else if (choose == '5') {
        printf("Informe o novo número da CNH: ");
        getchar();
        fgets(CNH, sizeof(CNH), stdin);
    }
    printf("Pressione enter para continuar...");
    getchar();
}

void modulo_excluir_cliente(void)
{
    char cpf[15];

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
    printf("|        Por favor informe o CPf do cliente que deseja excluir:       |\n");
    printf("|                                                                     |\n");
    printf("|                    + CPF do cliente:                                |\n");
    printf("|                                                                     |\n");
    printf("#=====================================================================#\n");
    printf("\n");
    scanf("%14s", cpf);
    getchar();
    system("cls||clear");
    printf("Pressione Enter para continuar...");
    getchar();
}