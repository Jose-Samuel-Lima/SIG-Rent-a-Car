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
    Aluguel* alg;
    alg = (Aluguel*) malloc(sizeof(Aluguel));
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
    scanf(" %99[^\n]", alg->nome_cliente);
    while ((c = getchar()) != '\n' && c != EOF);

    while (!validarNome(alg->nome_cliente)) {
        printf(" XXX - Nome inválido! Digite novamente: ");
        scanf("%99[^\n]", alg->nome_cliente);
        while ((c = getchar()) != '\n' && c != EOF);
    }

    printf("CPF do cliente: ");
    scanf("%14s", alg->cpf_cliente);
    while ((c = getchar()) != '\n' && c != EOF);

    while (!validarCPF(alg->cpf_cliente)) {
        printf("XXX - CPF inválido! Digite novamente: ");
        scanf("%14s", alg->cpf_cliente);
        while ((c = getchar()) != '\n' && c != EOF);
    }

    printf("Renavam do veículo: ");
    scanf("%11[0-9]", alg->codigo_renavam);
    while ((c = getchar()) != '\n' && c != EOF);
        
    while (!validarRenavam(alg->codigo_renavam)) {
        printf("XXX - Renavam inválido! Digite novamente: ");
        scanf("%11[0-9]", alg->codigo_renavam);
        while ((c = getchar()) != '\n' && c != EOF);
    }

    printf("Modelo do veículo: ");
    scanf("%30[A-Za-z0-9 ]", alg->modelo_veiculo);
    while ((c = getchar()) != '\n' && c != EOF);

    while (!validarModelo(alg->modelo_veiculo)) {
        printf("XXX - Modelo inválido! Digite novamente: ");
        scanf("%30[A-Za-z0-9 ]", alg->modelo_veiculo);
        while ((c = getchar()) != '\n' && c != EOF);
    }

    printf("Data do Fim do aluguel: ");
    scanf("%11s", alg->data_aluguel);
    while ((c = getchar()) != '\n' && c != EOF)

    while (!validarData(alg->data_aluguel)) {
        printf("XXX - Data inválida. Digite novamente (DD/MM/AAAA): ");
        scanf("%11s", alg->data_aluguel);
        while ((c = getchar()) != '\n' && c != EOF);
    }

    printf("ID de identificação do aluguel: ");
    scanf("%11[0-9]", alg->id_aluguel);
    while ((c = getchar()) != '\n' && c != EOF);
    
    while (!validarIDaluguel(alg->id_aluguel)) {
        printf("XXX - ID do aluguel inválido! Digite novamente (11 dígitos): ");
        scanf("%11[0-9]", alg->id_aluguel);
        while ((c = getchar()) != '\n' && c != EOF);
    }

    alg->status = true;

    arq_aluguel = fopen("aluguel.dat","ab");

    if (arq_aluguel == NULL)
    {
        printf("Erro na criação do arquivo!");
        printf("Pressione Enter para continuar...");
        getchar();
        exit(1);
    }
    
    fwrite(alg, sizeof(Aluguel), 1, arq_aluguel);

    fclose(arq_aluguel);
    free(alg);
    printf("Aluguel Registrado com Sucesso!\n");
    printf("Pressione Enter para continuar...");
    getchar();
    
}

void modulo_dados_aluguel(void)
{
    FILE *arq_aluguel;
    Aluguel* alg;
    alg = (Aluguel*) malloc(sizeof(Aluguel));
    arq_aluguel = fopen("aluguel.dat","rb");

    if (arq_aluguel == NULL){
        printf("Erro ao abrir o arquivo!");
        printf("Pressione Enter para continuar...");
        getchar();
        exit(1);
    }

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
    while (fread(alg,sizeof(Aluguel),1,arq_aluguel)) {

        if (strcmp(id_aluguel_ler,alg->id_aluguel) == 0 && alg->status == true) {
            printf("\t\t T ~~~~~~~~~~~~~~~~~~~~~~~~~~~ T\n");
            printf("\t\t < = = Aluguel Encontrado! = = >\n");
            printf("\t\t T ~~~~~~~~~~~~~~~~~~~~~~~~~~~ T\n");
            printf("\t\t Nome: %s\n", alg->nome_cliente);
            printf("\t\t CPF: %s\n", alg->cpf_cliente);
            printf("\t\t Código RENAVAM: %s\n", alg->codigo_renavam);
            printf("\t\t Modelo do Veículo: %s\n", alg->modelo_veiculo);
            printf("\t\t Data de Finalização: %s\n", alg->data_aluguel);
            printf("\t\t ID do Aluguel: %s\n", alg->id_aluguel);
            printf("\n");
            printf("\t\t Pressione Enter para continuar...");
            getchar();
            return;
        }
        
    }
    
    fclose(arq_aluguel);
    free(alg);
    printf("Aluguel não encontrado!\n");
    printf("Pressione Enter para continuar...");
    getchar();
    
}

void modulo_atualizar_aluguel(void)
{
    FILE *arq_aluguel;
    Aluguel* alg;
    alg = (Aluguel*) malloc(sizeof(Aluguel));

    arq_aluguel = fopen("aluguel.dat","r+b");

    if (arq_aluguel == NULL){
        printf("Erro ao entrar no arquivo!");
        printf("Pressione Enter para continuar...");
        getchar();
        exit(1);
    }

    char id_ler[11];
    char op_aluguel;
    int c; 
    bool aluguel_encontrado = false;

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
    while ((fread(alg,sizeof(Aluguel),1,arq_aluguel) == 1)) {
        if (strcmp(alg->id_aluguel,id_ler) == 0 && alg->status) {

            aluguel_encontrado = true;

            system("clear||cls");
            printf("Aluguel encontrado!\n");
            printf("Informe qual informação deseja alterar:\n");
            printf("\n");
            printf("---------------------------\n");
            printf("[1] Novo Nome: \n");
            printf("[2] Novo CPF: \n");
            printf("[3] Novo Código RENAVAM: \n");
            printf("[4] Novo Modelo: \n");
            printf("[5] Nova Data Final: \n");
            printf("[6] Novo Id: \n");
            printf("[0] Cancelar\n");
            printf("---------------------------\n");
            scanf(" %c", &op_aluguel);
            while ((c = getchar()) != '\n' && c != EOF)
                ;

            int alt = 0;

            switch (op_aluguel){
                case '1':
                    printf("Novo nome do cliente: ");
                    scanf(" %99[^\n]", alg->nome_cliente);
                    while ((c = getchar()) != '\n' && c != EOF)
                        ;
                    alt = 1;
                    break;

                case '2':
                    printf("Novo CPF do cliente: ");
                    scanf("%14s", alg->cpf_cliente);
                    while ((c = getchar()) != '\n' && c != EOF)
                        ;
                    alt = 1;
                    break;
                
                case '3':
                    printf("Novo Renavam: ");
                    scanf("%11[0-9]", alg->codigo_renavam);
                    while ((c = getchar()) != '\n' && c != EOF)
                        ;
                    alt = 1;
                    break;
                
                case '4':
                    printf("Novo Modelo: ");
                    scanf("%30[A-Za-z0-9 ]", alg->modelo_veiculo);
                    while ((c = getchar()) != '\n' && c != EOF)
                        ;
                    alt = 1;
                    break;

                case '5':
                    printf("Novo data final: ");
                    scanf("%[0-9/]", alg->data_aluguel);
                    while ((c = getchar()) != '\n' && c != EOF)
                        ;
                    alt = 1;
                    break;

                case '6':
                    printf("Novo ID de identificação do aluguel: ");
                    scanf("%[0-9]", alg->id_aluguel);
                    while ((c = getchar()) != '\n' && c != EOF)
                        ;
                    alt = 1;
                    break;

                case '0':
                    printf("Voltando ao menu alugueis.\n");
                    break;
                
                default:
                    printf("Opção inválida. Nenhum dado alterado.\n");
                    break;
            }

            if (alt){

            fseek(arq_aluguel, -sizeof(Aluguel), SEEK_CUR);
            fwrite(alg, sizeof(Aluguel), 1, arq_aluguel);
            fflush(arq_aluguel);
            printf("Dado(s) alterado(s) com sucesso!\n");

            }
            break;
        } 
    }

    if (!aluguel_encontrado){
        printf("Aluguel não encontrado!\n");
    }

    fclose(arq_aluguel);
    free(alg);
    printf("Pressione Enter para continuar...");
    getchar();
}

void modulo_finalizar_aluguel(void)
{
    FILE *arq_aluguel;
    Aluguel* alg;
    alg = (Aluguel*) malloc(sizeof(Aluguel));

    arq_aluguel = fopen("aluguel.dat","r+b");

    if (arq_aluguel == NULL){
        printf("Erro ao abrir o arquivo!\n");
        printf("Pressione Enter para continuar...");
        getchar();
        exit(1);
    }

    char id_ler[11];
    int c; 
    bool aluguel_encontrado = false;

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

    while ((fread(alg,sizeof(Aluguel),1,arq_aluguel) == 1) && (!aluguel_encontrado)) {

        if (strcmp(alg->id_aluguel,id_ler) == 0){

            alg->status = false;
            fseek(arq_aluguel,(-1)*sizeof(Aluguel),SEEK_CUR);
            fwrite(alg, sizeof(Aluguel), 1, arq_aluguel);
            aluguel_encontrado = true;

            printf("Aluguel excluido com sucesso!\n");
            break;
            }
        }

    fclose(arq_aluguel);
    free(alg);
    if (!aluguel_encontrado){
        printf("Aluguel não encontrado!\n");
    }

    printf("Pressione Enter para continuar...");
    getchar();
}