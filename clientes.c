#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#define True 1
#define False 0
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
        // case 3:
        //     modulo_atualizar_clientes();
        //     break;
        // case 4:
        //     modulo_excluir_cliente();
        //     break;
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
    Cliente * clt;
    clt = (Cliente*)malloc(sizeof(Cliente));
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
    scanf("%s", clt->nome_cliente);
    while ((c = getchar()) != '\n' && c != EOF)
        ;
    printf("CPF do cliente: ");
    scanf("%s", clt->cpf_cliente);
    while ((c = getchar()) != '\n' && c != EOF)
        ;
    printf("Data de Nascimento do cliente: ");
    scanf("%s", clt->data_nascimento);
    while ((c = getchar()) != '\n' && c != EOF)
        ;
    printf("Email do cliente: ");
    scanf("%s", clt->email_cliente);
    while ((c = getchar()) != '\n' && c != EOF)
        ;
    printf("CNH do cliente: ");
    scanf("%s", clt->cnh);
    while ((c = getchar()) != '\n' && c != EOF)
        ;
    clt -> status = True;
    arq_cliente = fopen("cliente.dat","ab");
    
    fwrite(clt,sizeof(Cliente),1,arq_cliente);
    fclose(arq_cliente);
    free(clt);
    printf("Cliente Registrado com Sucesso!\n");
    printf("Pressione Enter para continuar...");
    getchar();
}

void modulo_dados_cliente(void)
{
    FILE *arq_cliente;
    Cliente * clt;
    clt = (Cliente*)malloc(sizeof(Cliente));
    
    char cpf[15];
    int c;
    int enc = 0;

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

    arq_cliente = fopen("cliente.dat","rb");

    while (fread(clt,sizeof(Cliente),1,arq_cliente)){
        if (strcmp(cpf,clt->cpf_cliente) == 0 &&(clt->status) == 1){
            printf("%s\n",clt->nome_cliente);
            printf("%s\n",clt->cpf_cliente);
            printf("%s\n",clt->data_nascimento);
            printf("%s\n",clt->email_cliente);
            printf("%s\n",clt->cnh);
            enc = 1;
        }
    }

    fclose(arq_cliente);
    free(clt);
    
    if (!enc){
        printf("Cliente não encontrado!\n");
    }

    printf("Pressione Enter para continuar...");
    getchar();
    
}

// void modulo_atualizar_clientes(void)
// {
//     FILE *arq_cliente;
//     arq_cliente = fopen("cliente.csv","rt");

//     if (arq_cliente == NULL){
//         printf("Erro ao entrar no arquivo!");
//         printf("Pressione Enter para continuar...");
//         getchar();
//         exit(1);
//     }

//     FILE *arq_temp;
//     arq_temp = fopen("cliente_temp.csv","wt");

//     if (arq_temp== NULL){
//         printf("Erro na criação do arquivo Temporário!\n");
//         printf("Pressione Enter para continuar...");
//         getchar();
//         exit(1);
//     }

//     char cpf[15];
//     Cliente clt;
//     char opcao;
//     int c;
//     int encontrado = 0;

//     system("clear||cls");
//     printf("\n");
//     printf("#=====================================================================#\n");
//     printf("|                                                                     |\n");
//     printf("|                        --------------------                         |\n");
//     printf("|                        | SIG - Rent a Car |                         |\n");
//     printf("|                        --------------------                         |\n");
//     printf("|                                                                     |\n");
//     printf("#=====================================================================#\n");
//     printf("|                                                                     |\n");
//     printf("|             T ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ T          |\n");
//     printf("|             | < = = =  Alterar dados do Cliente  = = = > |          |\n");
//     printf("|             T ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ T          |\n");
//     printf("|                                                                     |\n");
//     printf("#=====================================================================#\n");
//     printf("\n");
//     printf("Informe o CPf do cliente para alterar os dados: \n");
//     scanf("%15s", cpf);
//     while ((c = getchar()) != '\n' && c != EOF)
//         ;

//     while (fscanf(arq_cliente, "%[^;];%[^;];%[^;];%[^;];%[^\n]\n", clt.nome_cliente, clt.cpf_cliente, clt.data_nascimento, clt.email_cliente, clt.cnh) == 5) {
//         if (strcmp(cpf, clt.cpf_cliente) == 0) {
            
//             encontrado = 1;

//             system("clear||cls");
//             printf("Cliente encontrado!\n");
//             printf("Informe qual informação deseja alterar:\n");
//             printf("\n");
//             printf("---------------------------\n");
//             printf("[1] Novo Nome\n");
//             printf("[2] Novo Cpf\n");
//             printf("[3] Nova Data de Nascimento\n");
//             printf("[4] Novo E-mail\n");
//             printf("[5] Nova CNH\n");
//             printf("[0] Cancelar\n");
//             printf("---------------------------\n");
//             scanf(" %c", &opcao);
//             while ((c = getchar()) != '\n' && c != EOF)
//                 ;

//             switch(opcao){
//                 case '1':
//                     printf("Novo nome do cliente: ");
//                     scanf("%[A-ZÁÉÍÓÚÂÊÔÇÀÃÕ a-záéíóúâôêçãõà]", clt.nome_cliente);
//                     while ((c = getchar()) != '\n' && c != EOF)
//                         ;
//                     break;

//                 case '2':
//                     printf("Novo CPF do cliente: ");
//                     scanf("%[0-9.-]", clt.cpf_cliente);
//                     while ((c = getchar()) != '\n' && c != EOF)
//                         ;
//                     break;

//                 case '3':
//                     printf("Nova Data de Nasc. do cliente: ");
//                     scanf("%[0-9/]", clt.data_nascimento);
//                     while ((c = getchar()) != '\n' && c != EOF)
//                         ;
//                     break;

//                 case '4':
//                     printf("Novo email do cliente: ");
//                     scanf("%[A-Za-z-z0-9@._]", clt.email_cliente);
//                     while ((c = getchar()) != '\n' && c != EOF)
//                         ;
//                     break;

//                 case '5':
//                     printf("Nova CNH do cliente: ");
//                     scanf("%[0-9]", clt.cnh);
//                     while ((c = getchar()) != '\n' && c != EOF)
//                         ;
//                     break;

//                 case '0':
//                     printf("Voltando ao menu clientes.");
//                     break;

//                 default:
//                     printf("Opção inválida. Nenhum dado alterado.\n");
//                     break;

//             }

//         }

//         fprintf(arq_temp,"%s;", clt.nome_cliente);
//         fprintf(arq_temp,"%s;", clt.cpf_cliente);
//         fprintf(arq_temp,"%s;", clt.data_nascimento);
//         fprintf(arq_temp,"%s;", clt.email_cliente);
//         fprintf(arq_temp,"%s\n", clt.cnh);

//     }

//     fclose(arq_cliente);
//     fclose(arq_temp);

//     if (encontrado){
//             remove("cliente.csv");
//             rename("cliente_temp.csv","cliente.csv");
//             printf("Dado(s) do cliente alterado(s) com sucesso!\n");
//         }
//     else {
//         remove("cliente_temp.csv");
//         printf("Cliente não encontrado..\n");
//     }

//     printf("Pressione Enter para continuar...");
//     getchar();
// }

// void modulo_excluir_cliente(void)
// {
//     FILE *arq_cliente;
//     arq_cliente = fopen("cliente.csv","rt");

//     if (arq_cliente == NULL){
//         printf("Erro ao entrar no arquivo!");
//         printf("Pressione Enter para continuar...");
//         getchar();
//         exit(1);
//     }

//     FILE *arq_temp;
//     arq_temp = fopen("cliente_temp.csv","wt");

//     if (arq_temp== NULL){
//         printf("Erro na criação do arquivo Temporário!\n");
//         printf("Pressione Enter para continuar...");
//         getchar();
//         exit(1);
//     }

//     char cpf[15];
//     Cliente clt;
//     int c;
//     int encontrado = 0;

//     system("clear||cls");
//     printf("\n");
//     printf("#=====================================================================#\n");
//     printf("|                                                                     |\n");
//     printf("|                        --------------------                         |\n");
//     printf("|                        | SIG - Rent a Car |                         |\n");
//     printf("|                        --------------------                         |\n");
//     printf("|                                                                     |\n");
//     printf("#=====================================================================#\n");
//     printf("|                                                                     |\n");
//     printf("|             T ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ T          |\n");
//     printf("|             | < = = =  Excluir dados do Cliente  = = = > |          |\n");
//     printf("|             T ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ T          |\n");
//     printf("|                                                                     |\n");
//     printf("#=====================================================================#\n");
//     printf("\n");
//     printf("Informe o CPf do cliente que deseja excluir: \n");
//     scanf("%15s", cpf);
//     while ((c = getchar()) != '\n' && c != EOF)
//         ;
//     while (fscanf(arq_cliente, "%[^;];%[^;];%[^;];%[^;];%[^\n]\n", clt.nome_cliente, clt.cpf_cliente, clt.data_nascimento, clt.email_cliente, clt.cnh) == 5) {

//         if (strcmp(clt.cpf_cliente,cpf) != 0){

//             fprintf(arq_temp,"%s;", clt.nome_cliente);
//             fprintf(arq_temp,"%s;", clt.cpf_cliente);
//             fprintf(arq_temp,"%s;", clt.data_nascimento);
//             fprintf(arq_temp,"%s;", clt.email_cliente);
//             fprintf(arq_temp,"%s\n", clt.cnh);

//         }
//         else {
//             encontrado = 1;
//         }
//     }

//     fclose(arq_cliente);
//     fclose(arq_temp);

//     if (encontrado){
//             remove("cliente.csv");
//             rename("cliente_temp.csv","cliente.csv");
//             printf("Cliente excluído com sucesso!\n");
//         }
//     else {
//         remove("cliente_temp.csv");
//         printf("Cliente não encontrado..\n");
//     }

//     printf("Pressione Enter para continuar...");
//     getchar();
    
// }