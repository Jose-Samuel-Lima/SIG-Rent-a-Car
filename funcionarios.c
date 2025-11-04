#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include "funcionarios.h"
#include "validacao.h"

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
    int op_funcionario;
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
    printf("[>] - Escolha uma das opções acima: ");
    scanf(" %d", &op_funcionario);
    while ((c = getchar()) != '\n' && c != EOF)
        ;
    printf("\n");
    printf("Processando...\n");
    return op_funcionario;
}

void modulo_cadastrar_funcionario(void)
{
    FILE *arq_funcionario;
    Funcionario* fun;
    fun = (Funcionario*) malloc(sizeof(Funcionario));
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

    printf("[+] - Nome do funcionário: ");
    scanf("%99[^\n]", fun->nome_funcionario);
    while ((c = getchar()) != '\n' && c != EOF);

    while (!validarNome(fun->nome_funcionario)) {
        printf(" XXX - Nome inválido! Digite novamente: ");
        scanf("%99[^\n]", fun->nome_funcionario);
        while ((c = getchar()) != '\n' && c != EOF);
    }
    
    printf("[+] - CPF do funcionário: ");
    scanf("%14s", fun->cpf_funcionario);
    while ((c = getchar()) != '\n' && c != EOF);

    while (!validarCPF(fun->cpf_funcionario)) {
        printf("XXX - CPF inválido! Digite novamente: ");
        scanf("%14s", fun->cpf_funcionario);
        while ((c = getchar()) != '\n' && c != EOF);
    }
    
    printf("[+] - Data de Nascimento (DD/MM/AAAA): ");
    scanf("%11s", fun->dt_nascimento_fun);
    while ((c = getchar()) != '\n' && c != EOF);

    while (!validarData(fun->dt_nascimento_fun)) {
        printf("XXX - Data inválida. Digite novamente (DD/MM/AAAA): ");
        scanf("%11s", fun->dt_nascimento_fun);
        while ((c = getchar()) != '\n' && c != EOF);
    }
    
    printf("[+] - Email do funcionário: ");
    scanf("%99s", fun->email_funcionario);
    while ((c = getchar()) != '\n' && c != EOF);

    while (!validarEmail(fun->email_funcionario)) {
        printf("XXX - Email inválido. Digite novamente: ");
        scanf("%99s", fun->email_funcionario);
        while ((c = getchar()) != '\n' && c != EOF);
    }

    printf("[+] - Cargo do funcionário: ");
    scanf("%50[^\n]", fun->cargo);
    while ((c = getchar()) != '\n' && c != EOF);

    while (!validarNome(fun->cargo)) {
        printf("XXX - Cargo inválido. Digite novamente: ");
        scanf("%50[^\n]", fun->cargo);
        while ((c = getchar()) != '\n' && c != EOF);
    }

    fun->status = true;
    
    arq_funcionario = fopen("funcionario.dat","ab");

    if (arq_funcionario == NULL){
        printf("XXX - Erro na criação do arquivo!");
        printf("[>] - Pressione Enter para continuar...");
        getchar();
        exit(1);
    }

    fwrite(fun, sizeof(Funcionario), 1, arq_funcionario);

    fclose(arq_funcionario);
    free(fun);

    printf("-----------------------------------------\n");
    printf("[o] - Funcionário Registrado com Sucesso!\n");
    printf("[>] - Pressione Enter para continuar...");
    getchar();
}

void modulo_dados_funcionario(void)
{
    FILE *arq_funcionario;
    Funcionario* fun;
    fun = (Funcionario*) malloc(sizeof(Funcionario));
    arq_funcionario = fopen("funcionario.dat","rb");

    if (arq_funcionario == NULL){
        printf("XXX - Erro na criação do arquivo!");
        printf("[>] - Pressione Enter para continuar...");
        getchar();
        exit(1);
    }

    char cpf_funcionario_ler[15];
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
    printf("[>] - Informe o CPf do funcionário que deseja encontrar: ");
    scanf("%15s", cpf_funcionario_ler);
    while ((c = getchar()) != '\n' && c != EOF)
        ;
    while (fread(fun,sizeof(Funcionario),1,arq_funcionario)){

        if (strcmp(cpf_funcionario_ler,fun->cpf_funcionario) == 0 && fun->status == true) {
            printf("------------------------------------\n");
            printf("T ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ T\n");
            printf("< = = Funcionário Encontrado! = = >\n");
            printf("T ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ T\n");
            printf("Nome: %s\n", fun->nome_funcionario);
            printf("CPF: %s\n", fun->cpf_funcionario);
            printf("Data Nasci.: %s\n", fun->dt_nascimento_fun);
            printf("Email: %s\n", fun->email_funcionario);
            printf("CNH: %s\n", fun->cargo);
            printf("-----------------------------------\n");
            printf("[>] - Pressione Enter para continuar...");
            getchar();
            return;
        }
        
    }

    fclose(arq_funcionario);
    free(fun);
    printf("XXX - Funcionário não encontrado!\n");
    printf("[>] - Pressione Enter para continuar...");
    getchar();
}

void modulo_atualizar_funcionario(void)
{
    FILE *arq_funcionario;
    Funcionario* fun;
    fun = (Funcionario*) malloc(sizeof(Funcionario));
    arq_funcionario = fopen("funcionario.dat", "r+b");

    if (arq_funcionario == NULL){
        printf("XXX - Erro ao entrar no arquivo!");
        printf("[>] - Pressione Enter para continuar...");
        getchar();
        exit(1);
    }

    char cpf_funcionario_ler[15];
    char op_funcionario;
    int c;
    int func_encontrado = false;

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
    printf("[>] - Informe o CPf do funcionário para alterar os dados: ");
    scanf("%15s", cpf_funcionario_ler);
    while ((c = getchar()) != '\n' && c != EOF)
        ;
    
    while ((fread(fun,sizeof(Funcionario),1,arq_funcionario) == 1)) {
        if (strcmp(fun->cpf_funcionario,cpf_funcionario_ler) == 0 && fun->status) {
            
            func_encontrado = true;
        
            system("clear||cls");
            printf("------------------------------\n");
            printf("[o] - Funcionário encontrado!\n");
            printf("------------------------------\n");
            printf("[1] Novo Nome\n");
            printf("[2] Novo Cpf\n");
            printf("[3] Nova Data de Nascimento\n");
            printf("[4] Novo E-mail\n");
            printf("[5] Novo cargo\n");
            printf("[0] Cancelar\n");
            printf("------------------------------\n");
            printf("[>] - Informe qual informação deseja alterar: ");
            scanf(" %c", &op_funcionario);
            while ((c = getchar()) != '\n' && c != EOF)
                ;
            
            int alt = 0; 

            switch(op_funcionario){
                case '1':
                    printf("---------------------------\n");
                    printf("[+] - Novo nome do funcionário: ");
                    scanf("%99[^\n]", fun->nome_funcionario);
                    while ((c = getchar()) != '\n' && c != EOF);

                    while (!validarNome(fun->nome_funcionario)) {
                        printf(" XXX - Nome inválido! Digite novamente: ");
                        scanf("%99[^\n]", fun->nome_funcionario);
                        while ((c = getchar()) != '\n' && c != EOF);
                    }
                    alt = 1;
                    break;

                case '2':
                    printf("---------------------------\n");
                    printf("[+] - Novo CPF do funcionário: ");
                    scanf("%14s", fun->cpf_funcionario);
                    while ((c = getchar()) != '\n' && c != EOF);

                    while (!validarCPF(fun->cpf_funcionario)) {
                        printf("XXX - CPF inválido! Digite novamente: ");
                        scanf("%14s", fun->cpf_funcionario);
                        while ((c = getchar()) != '\n' && c != EOF);
                    }
                    alt = 1;
                    break;
                    
                case '3':
                    printf("---------------------------\n");
                    printf("[+] - Nova Data de Nasc. do funcionário: ");
                    scanf("%11s", fun->dt_nascimento_fun);
                    while ((c = getchar()) != '\n' && c != EOF);

                    while (!validarData(fun->dt_nascimento_fun)) {
                        printf("XXX - Data inválida. Digite novamente (DD/MM/AAAA): ");
                        scanf("%11s", fun->dt_nascimento_fun);
                        while ((c = getchar()) != '\n' && c != EOF);
                    }
                    alt = 1;
                    break;

                case '4':
                    printf("---------------------------\n");
                    printf("[+] - Novo email do funcionário: ");
                    scanf("%99s", fun->email_funcionario);
                    while ((c = getchar()) != '\n' && c != EOF);

                    while (!validarEmail(fun->email_funcionario)) {
                        printf("XXX - Email inválido. Digite novamente: ");
                        scanf("%99s", fun->email_funcionario);
                        while ((c = getchar()) != '\n' && c != EOF);
                    }
                    alt =1;
                    break;

                case '5':
                    printf("---------------------------\n");
                    printf("[+] - Novo cargo do funcionário: ");
                    scanf("%50[^\n]", fun->cargo);
                    while ((c = getchar()) != '\n' && c != EOF);

                    while (!validarNome(fun->cargo)) {
                        printf("XXX - Cargo inválido. Digite novamente: ");
                        scanf("%50[^\n]", fun->cargo);
                        while ((c = getchar()) != '\n' && c != EOF);
                    }
                    alt = 1;
                    break;

                case '0':
                    printf("Voltando ao menu funcionários.\n");
                    break;

                default:
                    printf("XXX - Opção inválida. Nenhum dado alterado.\n");
                    break;

            }
            if (alt){
                fseek(arq_funcionario, -sizeof(Funcionario), SEEK_CUR);
                fwrite(fun, sizeof(Funcionario), 1,arq_funcionario);
                fflush(arq_funcionario);
                printf("[o] - Dado(s) alterado(s) com sucesso!\n");
            }

            break;
        }
    }

    if (!func_encontrado){
        printf("Funcionário não encontrado!\n"); 
    }

    fclose(arq_funcionario);
    free(fun);
    printf("Pressione <Enter> para continuar...");
    getchar();
}

void modulo_excluir_funcionario(void)
{
    FILE *arq_funcionario; 
    Funcionario* fun;
    fun = (Funcionario*) malloc(sizeof(Funcionario));
    char cpf_funcionario_ler[15];
    int c;
    bool func_encontrado;

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
    printf("[>] - Informe o CPf do funcionário que deseja excluir: ");
    scanf("%14s", cpf_funcionario_ler);
    while ((c = getchar()) != '\n' && c != EOF)
        ;

    func_encontrado = false;

    arq_funcionario = fopen("funcionario.dat","r+b");

    if (arq_funcionario == NULL){
        printf("XXX - Erro ao entrar no arquivo!");
        printf("[>] - Pressione Enter para continuar...");
        getchar();
        exit(1);
    }

    while ((fread(fun,sizeof(Funcionario),1,arq_funcionario) == 1) && (!func_encontrado)) {

        if (strcmp(fun->cpf_funcionario,cpf_funcionario_ler) == 0){

            fun->status = false;
            fseek(arq_funcionario,(-1)*sizeof(Funcionario),SEEK_CUR);
            fwrite(fun, sizeof(Funcionario),1, arq_funcionario);
            func_encontrado = true;

            printf("---------------------------------------\n");
            printf("[o] - Funcionário excluído com sucesso!\n");
            break;
            }
        }
    fclose(arq_funcionario);
    free(fun);

    if (!func_encontrado){
            printf("XXX - Funcionário não encontrado...\n");
        }

    printf("[>] - Pressione Enter para continuar...");
    getchar();
    
}