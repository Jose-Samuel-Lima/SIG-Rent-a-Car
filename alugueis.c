#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
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
    FILE *arq_aluguel;
    Aluguel alg;
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
    scanf("%[A-ZÁÉÍÓÚÂÊÔÇÀÃÕ a-záéíóúâôêçãõà]", alg.nome_cliente);
    while ((c = getchar()) != '\n' && c != EOF)
        ;
    printf("CPF do cliente: ");
    scanf("%[0-9.-]", alg.cpf_cliente);
    while ((c = getchar()) != '\n' && c != EOF)
        ;
    printf("Código RENAVAM do veículo: ");
    scanf("%[0-9]", alg.codigo_renavam);
    while ((c = getchar()) != '\n' && c != EOF)
        ;
    printf("Modelo do veículo: ");
    scanf("%[0-9 A-Za-z]", alg.modelo_veiculo);
    while ((c = getchar()) != '\n' && c != EOF)
        ;
    printf("Data do Fim do aluguel: ");
    scanf("%[0-9/]", alg.data_aluguel);
    while ((c = getchar()) != '\n' && c != EOF)
        ;
    printf("ID de identificação do aluguel: ");
    scanf("%[0-9]", alg.id_aluguel);
    while ((c = getchar()) != '\n' && c != EOF)
        ;

    arq_aluguel = fopen("aluguel.csv","at");

    if (arq_aluguel == NULL){
        printf("Erro na criação do arquivo!\n");
        printf("Pressione Enter para continuar...");
        getchar();
        exit(1);
    }
    fprintf(arq_aluguel,"%s;", alg.nome_cliente);
    fprintf(arq_aluguel,"%s;", alg.cpf_cliente);
    fprintf(arq_aluguel,"%s;", alg.codigo_renavam);
    fprintf(arq_aluguel,"%s;", alg.modelo_veiculo);
    fprintf(arq_aluguel,"%s;", alg.data_aluguel);
    fprintf(arq_aluguel,"%s\n", alg.id_aluguel);
    fclose(arq_aluguel);
    printf("Aluguel Registrado com Sucesso!\n");
    printf("Pressione Enter para continuar...");
    getchar();
    
}

void modulo_dados_aluguel(void)
{
    FILE *arq_aluguel;
    arq_aluguel = fopen("aluguel.csv","rt");

    if (arq_aluguel == NULL){
        printf("Erro na criação do arquivo!\n");
        printf("Pressione Enter para continuar...");
        getchar();
        return;
    }

    Aluguel alg;
    char id_aluguel_ler[11];
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
    scanf("%11s", id_aluguel_ler);
    while ((c = getchar()) != '\n' && c != EOF)
        ;
    while (fscanf(arq_aluguel, "%[^;];%[^;];%[^;];%[^;];%[^;];%[^\n]\n", alg.nome_cliente, alg.cpf_cliente, alg.codigo_renavam, alg.modelo_veiculo, alg.data_aluguel, alg.id_aluguel) == 6) {

        if (strcmp(id_aluguel_ler,alg.id_aluguel) == 0) {
            printf("\t\t T ~~~~~~~~~~~~~~~~~~~~~~~~~~~ T\n");
            printf("\t\t < = = Aluguel Encontrado! = = >\n");
            printf("\t\t T ~~~~~~~~~~~~~~~~~~~~~~~~~~~ T\n");
            printf("\t\t Nome: %s\n", alg.nome_cliente);
            printf("\t\t CPF: %s\n", alg.cpf_cliente);
            printf("\t\t Código RENAVAM: %s\n", alg.codigo_renavam);
            printf("\t\t Modelo do Veículo: %s\n", alg.modelo_veiculo);
            printf("\t\t Data de Finalização: %s\n", alg.data_aluguel);
            printf("\t\t ID do Aluguel: %s\n", alg.id_aluguel);
            printf("\n");
            printf("\t\t Pressione Enter para continuar...");
            getchar();
            fclose(arq_aluguel);
            return;
        }
        
    }
    printf("Aluguel não encontrado!\n");
    printf("Pressione Enter para continuar...");
    getchar();
    fclose(arq_aluguel);
}

void modulo_atualizar_aluguel(void)
{
    FILE *arq_aluguel;
    arq_aluguel = fopen("aluguel.csv","rt");

    if (arq_aluguel == NULL){
        printf("Erro ao entrar no arquivo!");
        printf("Pressione Enter para continuar...");
        getchar();
        exit(1);
    }

    FILE *arq_aluguel_temp;
    arq_aluguel_temp = fopen("aluguel_temp.csv","wt");

    if (arq_aluguel_temp== NULL){
        printf("Erro na criação do arquivo temporário!\n");
        printf("Pressione Enter para continuar...");
        getchar();
        exit(1);
    }

    Aluguel alg;
    char id_ler[11];
    char op_aluguel;
    int c; 
    int aluguel_encontrado = 0;

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
    scanf("%11s", id_ler);
    while ((c = getchar()) != '\n' && c != EOF)
        ;
    while (fscanf(arq_aluguel, "%[^;];%[^;];%[^;];%[^;];%[^;];%[^\n]\n", alg.nome_cliente, alg.cpf_cliente, alg.codigo_renavam, alg.modelo_veiculo, alg.data_aluguel, alg.id_aluguel) == 6) {
        if (strcmp(id_ler, alg.id_aluguel) == 0) {

            aluguel_encontrado = 1;

            system("clear||cls");
            printf("Aluguel encontrado!\n");
            printf("Informe qual informação deseja alterar:\n");
            printf("\n");
            printf("---------------------------\n");
            printf("[1] Novo Nome: \n");
            printf("[2] Novo CPF: \n");
            printf("[3] Novo Modelo: \n");
            printf("[4] Novo Código RENAVAM: \n");
            printf("[5] Nova Data Final: \n");
            printf("[6] Novo Id: \n");
            printf("[0] Cancelar\n");
            printf("---------------------------\n");
            scanf(" %c", &op_aluguel);
            while ((c = getchar()) != '\n' && c != EOF)
                ;
            switch (op_aluguel){
                case '1':
                    printf("Novo nome do cliente: ");
                    scanf("%[A-ZÁÉÍÓÚÂÊÔÇÀÃÕ a-záéíóúâôêçãõà]", alg.nome_cliente);
                    while ((c = getchar()) != '\n' && c != EOF)
                        ;
                    break;

                case '2':
                    printf("Novo CPF do cliente: ");
                    scanf("%[0-9.-]", alg.cpf_cliente);
                    while ((c = getchar()) != '\n' && c != EOF)
                        ;
                    break;
                
                case '3':
                    printf("Novo Renavam: ");
                    scanf("%11[0-9]", alg.codigo_renavam);
                    while ((c = getchar()) != '\n' && c != EOF)
                    ;
                    break;
                
                case '4':
                    printf("Novo Modelo: ");
                    scanf("%[0-9 A-Za-z]", alg.modelo_veiculo);
                    while ((c = getchar()) != '\n' && c != EOF)
                    ;
                    break;

                case '5':
                    printf("Novo data final: ");
                    scanf("%[0-9/]", alg.data_aluguel);
                    while ((c = getchar()) != '\n' && c != EOF)
                    ;
                    break;

                case '6':
                    printf("Novo ID de identificação do aluguel: ");
                    scanf("%[0-9]", alg.id_aluguel);
                    while ((c = getchar()) != '\n' && c != EOF)
                    ;
                    break;

                case '0':
                    printf("Voltando ao menu alugueis.\n");
                    break;
                
                default:
                    printf("Opção inválida. Nenhum dado alterado.\n");
                    break;
            }
        
        }
            
        fprintf(arq_aluguel_temp,"%s;", alg.nome_cliente);
        fprintf(arq_aluguel_temp,"%s;", alg.cpf_cliente);
        fprintf(arq_aluguel_temp,"%s;", alg.codigo_renavam);
        fprintf(arq_aluguel_temp,"%s;", alg.modelo_veiculo);
        fprintf(arq_aluguel_temp,"%s;", alg.data_aluguel);
        fprintf(arq_aluguel_temp,"%s\n", alg.id_aluguel);

    }

    fclose(arq_aluguel);
    fclose(arq_aluguel_temp);

    if (aluguel_encontrado){
            remove("aluguel.csv");
            rename("aluguel_temp.csv","aluguel.csv");
        }
    else {
        remove("aluguel_temp.csv");
        printf("Aluguel não encontrado...\n");
    }

    printf("Pressione Enter para continuar...");
    getchar();
}

void modulo_finalizar_aluguel(void)
{
    FILE *arq_aluguel;
    arq_aluguel = fopen("aluguel.csv","rt");

    if (arq_aluguel == NULL){
        printf("Erro ao abrir o arquivo!\n");
        printf("Pressione Enter para continuar...");
        getchar();
        exit(1);
    }

    FILE *arq_aluguel_temp;
    arq_aluguel_temp = fopen("aluguel_temp.csv","wt");

    if (arq_aluguel_temp== NULL){
        printf("Erro na criação do arquivo Temporário!\n");
        printf("Pressione Enter para continuar...");
        getchar();
        exit(1);
    }

    Aluguel alg;
    char id_ler[11];
    int c; 
    int aluguel_encontrado = 0;

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
    scanf("%11s", id_ler);
    while ((c = getchar()) != '\n' && c != EOF)
        ;
    while (fscanf(arq_aluguel, "%[^;];%[^;];%[^;];%[^;];%[^;];%[^\n]\n", alg.nome_cliente, alg.cpf_cliente, alg.codigo_renavam, alg.modelo_veiculo, alg.data_aluguel, alg.id_aluguel) == 6) {

        if (strcmp(alg.id_aluguel, id_ler) != 0){

            fprintf(arq_aluguel_temp, "%s;", alg.nome_cliente);
            fprintf(arq_aluguel_temp, "%s;", alg.cpf_cliente);
            fprintf(arq_aluguel_temp, "%s;", alg.codigo_renavam);
            fprintf(arq_aluguel_temp, "%s;", alg.modelo_veiculo);
            fprintf(arq_aluguel_temp, "%s;", alg.data_aluguel);
            fprintf(arq_aluguel_temp, "%s\n", alg.id_aluguel);

        }
        else {
            aluguel_encontrado = 1;
        }
    }

    fclose(arq_aluguel);
    fclose(arq_aluguel_temp);

    if (aluguel_encontrado){
            remove("aluguel.csv");
            rename("aluguel_temp.csv","aluguel.csv");
            printf("Aluguel finalizado com sucesso!\n");
        }
    else {
        remove("aluguel_temp.csv");
        printf("Aluguel não encontrado...\n");
    }

    printf("Pressione Enter para continuar...");
    getchar();
}