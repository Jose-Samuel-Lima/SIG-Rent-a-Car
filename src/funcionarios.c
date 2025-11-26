#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

#include "funcionarios.h"
#include "validacao.h"
#include "utilidades.h"

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
            modulo_verificar_funcionario();
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
    printf("|                         --------------------                        |\n");
    printf("|                         | SIG - Rent a Car |                        |\n");
    printf("|                         --------------------                        |\n");
    printf("#=====================================================================#\n");
    printf("|                          MÓDULO FUNCIONÁRIOS                        |\n");
    printf("|---------------------------------------------------------------------|\n");
    printf("|                     [1] - Cadastrar Funcionário                     |\n");
    printf("|                     [2] - Verificar Funcionário                     |\n");
    printf("|                     [3] - Atualizar Funcionário                     |\n");
    printf("|                     [4] - Excluir Funcionário                       |\n");
    printf("|---------------------------------------------------------------------|\n");
    printf("|                     [0] - Sair                                      |\n");
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
    system("clear||cls");

    Funcionario *fun = malloc(sizeof(Funcionario));
    if (!fun) return;

    printf("#=====================================================================#\n");
    printf("|                         --------------------                        |\n");
    printf("|                         | SIG - Rent a Car |                        |\n");
    printf("|                         --------------------                        |\n");
    printf("#=====================================================================#\n");
    printf("|                        CADASTRAR FUNCIONÁRIOS                       |\n");
    printf("#=====================================================================#\n");

    lerEntrada(fun->nome_funcionario, 100, "[+] - Nome: ", validarNome);
    lerEntrada(fun->cpf_funcionario, 15, "[+] - CPF: ", validarCPF);
    lerEntrada(fun->dt_nascimento_fun, 12, "[+] - Data (DD/MM/AAAA): ", validarData);
    lerEntrada(fun->email_funcionario, 100, "[+] - Email: ", validarEmail);
    lerEntrada(fun->cargo, 51, "[+] - Cargo: ", validarNome);

    fun->status = true;
    
    FILE *arq_funcionario = fopen("funcionario.dat","ab");

    if (arq_funcionario == NULL){
        printf("XXX - Erro na criação do arquivo!");
        printf("[>] - Pressione Enter para continuar...");
        getchar();
        free(fun);
        exit(1);
    }

    fwrite(fun, sizeof(Funcionario), 1, arq_funcionario);
    fclose(arq_funcionario);
    free(fun);

    printf("#=====================================================================#\n");
    printf("[o] - Funcionário Registrado com Sucesso!\n");
    printf("[>] - Pressione Enter para continuar...");
    getchar();
}

void modulo_verificar_funcionario(void)
{
    FILE *arq_funcionario;
    Funcionario* fun;
    fun = (Funcionario*) malloc(sizeof(Funcionario));
    arq_funcionario = fopen("funcionario.dat","rb");

    if (arq_funcionario == NULL){
        printf("XXX - Erro na criação do arquivo!\n");
        printf("[>] - Pressione Enter para continuar...");
        getchar();
        exit(1);
    }

    char cpf_funcionario_ler[15];
    int c;

    system("clear||cls");
    printf("\n");
    printf("#=====================================================================#\n");
    printf("|                         --------------------                        |\n");
    printf("|                         | SIG - Rent a Car |                        |\n");
    printf("|                         --------------------                        |\n");
    printf("#=====================================================================#\n");
    printf("|                        VERIFICAR FUNCIONÁRIOS                       |\n");
    printf("#=====================================================================#\n");
    printf("\n");
    printf("[>] - Informe o CPf do funcionário que deseja encontrar: ");
    scanf("%15s", cpf_funcionario_ler);
    while ((c = getchar()) != '\n' && c != EOF)
        ;
    while (fread(fun,sizeof(Funcionario),1,arq_funcionario)){

        if (strcmp(cpf_funcionario_ler,fun->cpf_funcionario) == 0 && fun->status == true) {
            system("clear||cls");
            printf("#====================================================#\n");
            printf("|            [o] - Funcionário encontrado!           |\n");
            printf("#====================================================#\n");
            printf("| > Nome: %s\n", fun->nome_funcionario);
            printf("| > CPF: %s\n", fun->cpf_funcionario);
            printf("| > Data de Nascimento: %s\n", fun->dt_nascimento_fun);
            printf("| > Email: %s\n", fun->email_funcionario);
            printf("| > Cargo: %s\n", fun->cargo);
            printf("#====================================================#\n");
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
    printf("|                         --------------------                        |\n");
    printf("|                         | SIG - Rent a Car |                        |\n");
    printf("|                         --------------------                        |\n");
    printf("#=====================================================================#\n");
    printf("|                        ATUALIZAR FUNCIONÁRIOS                       |\n");
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
            printf("#====================================================#\n");
            printf("|            [o] - Funcionário encontrado!           |\n");
            printf("#====================================================#\n");
            printf("|            [1] - Nome                              |\n");
            printf("|            [2] - CPF                               |\n");
            printf("|            [3] - Data de Nascimento                |\n");
            printf("|            [4] - E-mail                            |\n");
            printf("|            [5] - Cargo                             |\n");
            printf("|----------------------------------------------------|\n");
            printf("|            [0] - Cancelar                          |\n");
            printf("#====================================================#\n");
            printf("[>] - Informe qual informação deseja alterar: ");
            scanf(" %c", &op_funcionario);
            while ((c = getchar()) != '\n' && c != EOF)
                ;
            
            int alt = 0; 

            switch(op_funcionario){
                case '1':
                    atualizarEntrada("[+] - Novo nome do Funcionário: ", fun->nome_funcionario, 100, validarNome);

                    alt = 1;
                    break;

                case '2':
                    atualizarEntrada("[+] - Novo CPF do Funcionário: ", fun->cpf_funcionario, 15, validarCPF);

                    alt = 1;
                    break;
                    
                case '3':
                    atualizarEntrada("[+] - Nova data de nascimento (DD/MM/AAAA): ", fun->dt_nascimento_fun, 12, validarData);

                    alt = 1;
                    break;

                case '4':
                    atualizarEntrada("[+] - Novo e-mail: ", fun->email_funcionario, 100, validarEmail);

                    alt = 1;
                    break;


                case '5':
                    atualizarEntrada("[+] - Novo cargo: ", fun->cargo, 51, validarNome);
        
                    alt = 1;
                    break;

                case '0':
                    printf("Voltando ao menu...\n");
                    break;

                default:
                    printf("XXX - Opção inválida. Nenhum dado alterado.\n");
                    break;

            }
            if (alt){
                fseek(arq_funcionario, -sizeof(Funcionario), SEEK_CUR);
                fwrite(fun, sizeof(Funcionario), 1,arq_funcionario);
                fflush(arq_funcionario);
                printf("#====================================================#\n");
                printf("[o] - Dado(s) alterado(s) com sucesso!\n");
            }

            break;
        }
    }

    if (!func_encontrado){
        printf("XXX - Funcionário não encontrado!\n"); 
    }

    fclose(arq_funcionario);
    free(fun);
    printf("[>] - Pressione Enter para continuar...");
    getchar();
}

void modulo_excluir_funcionario(void)
{
    FILE *arq_funcionario; 
    Funcionario* fun;
    fun = (Funcionario*) malloc(sizeof(Funcionario));
    char cpf_funcionario_ler[15];
    int c;
    bool func_encontrado = false;
    char confirmar;

    system("clear||cls");
    printf("\n");
    printf("#=====================================================================#\n");
    printf("|                         --------------------                        |\n");
    printf("|                         | SIG - Rent a Car |                        |\n");
    printf("|                         --------------------                        |\n");
    printf("#=====================================================================#\n");
    printf("|                         EXCLUIR FUNCIONÁRIOS                        |\n");
    printf("#=====================================================================#\n");
    printf("\n");

    printf("[>] - Informe o CPF do funcionário que deseja excluir: ");
    scanf("%14s", cpf_funcionario_ler);
    while ((c = getchar()) != '\n' && c != EOF);

    arq_funcionario = fopen("funcionario.dat","r+b");

    if (arq_funcionario == NULL){
        printf("XXX - Erro ao abrir o arquivo!\n");
        printf("[>] - Pressione Enter para continuar...");
        getchar();
        exit(1);
    }

    while (fread(fun, sizeof(Funcionario), 1, arq_funcionario) == 1) {

        if (strcmp(fun->cpf_funcionario, cpf_funcionario_ler) == 0 && fun->status) {

            func_encontrado = true;

            system("clear||cls");
            printf("#====================================================#\n");
            printf("|            [o] - Funcionário encontrado!           |\n");
            printf("#====================================================#\n");
            printf("| > Nome: %s\n", fun->nome_funcionario);
            printf("| > CPF: %s\n", fun->cpf_funcionario);
            printf("| > Data de Nascimento: %s\n", fun->dt_nascimento_fun);
            printf("| > Email: %s\n", fun->email_funcionario);
            printf("| > Cargo: %s\n", fun->cargo);
            printf("#====================================================#");

            printf("\n[?] - Deseja excluir o funcionário? (S/N): ");
            scanf(" %c", &confirmar);
            while ((c = getchar()) != '\n' && c != EOF);

            if (confirmar == 'S' || confirmar == 's') {

                fun->status = false;

                fseek(arq_funcionario, -sizeof(Funcionario), SEEK_CUR);
                fwrite(fun, sizeof(Funcionario), 1, arq_funcionario);
                fflush(arq_funcionario);

                printf("\n[o] - Funcionário excluído com sucesso!\n");
            }
            else {
                printf("\n[o] - Exclusão cancelada.\n");
            }

            break;
        }
    }

    fclose(arq_funcionario);
    free(fun);

    if (!func_encontrado){
        printf("XXX - Funcionário não encontrado...\n");
    }

    printf("\n[>] - Pressione Enter para continuar...");
    getchar();
}
