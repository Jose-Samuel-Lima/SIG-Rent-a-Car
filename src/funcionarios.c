// |==========================================|
// |    SEÇÃO DE INCLUDE DE FUNCIONÁRIOS.C    |
// |==========================================|

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

#include "funcionarios.h"
#include "validacao.h"
#include "utilidades.h"

// |====================================================|
// |    MÓDULO DE TELA E NAVEGAÇÃO DE FUNCIONÁRIOS.C    |
// |====================================================|

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

// |=============================================|
// |    FUNÇÕES FUNCIONÁRIOS - LISTA DINÂMICA    |
// |=============================================|

// FUNCIONÁRIO NA LISTA EM ORDEM ALFABÉTICA
void listaOrdenadaFuncionarios(Funcionario** lista, Funcionario* novo_func) 
{ 
    // Caso1: lista vazia - Novo vira o primeiro
    if (*lista == NULL) {
        novo_func->prox_func = NULL;
        *lista = novo_func;
        return;
    }

    // Caso2: Novo deve ser inserido antes do primeiro elemento
    if (strcmp(novo_func->nome_funcionario, (*lista)->nome_funcionario) < 0) {
        novo_func->prox_func = *lista;
        *lista = novo_func;
        return;
    }

    // Caso3: inserir no meio ou final da lista
    Funcionario* anter = *lista;
    Funcionario* atual_func = (*lista)->prox_func;

    while (atual_func != NULL &&
        strcmp(atual_func->nome_funcionario, novo_func->nome_funcionario) < 0) {

            anter = atual_func;
            atual_func = atual_func->prox_func;
        }

        anter->prox_func = novo_func;
        novo_func->prox_func = atual_func;

}

// LEITURA DO ARQUIVO funcionario.dat E MONTA LISTA ORDENADA
Funcionario* carregarListaFuncionarios() 
{
    FILE* fp = fopen("funcionario.dat", "rb");
    if (!fp) return NULL;

    Funcionario temp;
    Funcionario* lista = NULL;

    while (fread(&temp, sizeof(Funcionario), 1, fp)) {
        if (temp.status == true) {
            Funcionario* novo_func = malloc(sizeof(Funcionario));
            *novo_func = temp;
            novo_func->prox_func = NULL;
            listaOrdenadaFuncionarios(&lista, novo_func);
        }
    }

    fclose(fp);
    return lista;
}

// BUSCA FUNCIONÁRIO NA LISTA USANDO CPF
Funcionario* buscarFuncionario(Funcionario* lista, const char* cpf_fun) {
    Funcionario* aux_func = lista;
    while (aux_func) {
        if (aux_func->status && strcmp(aux_func->cpf_funcionario, cpf_fun) == 0) {
            return aux_func;
        }
        aux_func = aux_func->prox_func;
    }
    return NULL;
}

// SOBRESCREVE O ARQUIVO funcionario.dat COM A LISTA ATUAL
void salvarListaFuncionarios(Funcionario* lista) {
    FILE* fp = fopen("funcionario.dat", "wb");
    if (!fp) return;

    Funcionario* aux_func = lista;

    while (aux_func != NULL) {
        fwrite(aux_func, sizeof(Funcionario), 1, fp);
        aux_func = aux_func->prox_func;
    }

    fclose(fp);
}

// LIBERA MEMÓRIA ALOCADA PARA A LISTA DINÂMICA
void limparListaFuncionarios(Funcionario* lista) 
{
    Funcionario* aux_func;

    while (lista != NULL) {
        aux_func = lista->prox_func;
        free(lista);
        lista = aux_func;
    }
}

// |===================================|
// |    FUNÇÕES FUNCIONÁRIOS - CRUD    |
// |===================================|

void modulo_cadastrar_funcionario(void)
{
    system("clear||cls");

    Funcionario *novo_func = malloc(sizeof(Funcionario));
    if (!novo_func) return;

    printf("#=====================================================================#\n");
    printf("|                         --------------------                        |\n");
    printf("|                         | SIG - Rent a Car |                        |\n");
    printf("|                         --------------------                        |\n");
    printf("#=====================================================================#\n");
    printf("|                        CADASTRAR FUNCIONÁRIOS                       |\n");
    printf("#=====================================================================#\n");

    lerEntrada(novo_func->nome_funcionario, 100, "[+] - Nome: ", validarNome);
    lerEntrada(novo_func->cpf_funcionario, 15, "[+] - CPF: ", validarCPF);
    lerEntrada(novo_func->dt_nascimento_fun, 12, "[+] - Data (DD/MM/AAAA): ", validarData);
    lerEntrada(novo_func->email_funcionario, 100, "[+] - Email: ", validarEmail);
    lerEntrada(novo_func->cargo, 51, "[+] - Cargo: ", validarNome);

    novo_func->status = true;
    novo_func->prox_func = NULL;
    
    Funcionario* lista = carregarListaFuncionarios();

    listaOrdenadaFuncionarios(&lista, novo_func);

    salvarListaFuncionarios(lista);

    limparListaFuncionarios(lista);

    printf("#=====================================================================#\n");
    printf("[o] - Funcionário Registrado com Sucesso!\n");
    printf("[>] - Pressione Enter para continuar...");
    getchar();
}

void modulo_verificar_funcionario(void)
{
    system("clear||cls");

    char cpf_funcionario_ler[15];

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
    while (getchar() != '\n');
        
    Funcionario* lista = carregarListaFuncionarios();
    Funcionario* aux_func = lista;
    
    while (aux_func != NULL) {
        if (strcmp(aux_func->cpf_funcionario, cpf_funcionario_ler) == 0 && aux_func->status == true) {
            system("clear||cls");
            printf("#====================================================#\n");
            printf("|            [o] - Funcionário encontrado!           |\n");
            printf("#====================================================#\n");
            printf("| > Nome: %s\n", aux_func->nome_funcionario);
            printf("| > CPF: %s\n", aux_func->cpf_funcionario);
            printf("| > Data de Nascimento: %s\n", aux_func->dt_nascimento_fun);
            printf("| > Email: %s\n", aux_func->email_funcionario);
            printf("| > Cargo: %s\n", aux_func->cargo);
            printf("#====================================================#\n");
            printf("[>] - Pressione Enter para continuar...");
            getchar();

            limparListaFuncionarios(lista);
            return;
        }
        aux_func = aux_func->prox_func;
        
    }

    limparListaFuncionarios(lista);

    printf("#=====================================================================#\n");
    printf("XXX - Funcionário não encontrado!\n");
    printf("[>] - Pressione Enter para continuar...");
    getchar();
}

void modulo_atualizar_funcionario(void)
{
    Funcionario* lista = carregarListaFuncionarios();
    if (!lista) {
        printf("XXX - Nenhum funcionário cadastrado!\n");
        printf("[>] - Pressione Enter para continuar...");
        getchar();
        return;
    }

    char cpf_funcionario_ler[15];
    char op_funcionario;
    int c;

    system("clear||cls");
    printf("\n");
    printf("#=====================================================================#\n");
    printf("|                         --------------------                        |\n");
    printf("|                         | SIG - Rent a Car |                        |\n");
    printf("|                         --------------------                        |\n");
    printf("#=====================================================================#\n");
    printf("|                        ATUALIZAR FUNCIONÁRIOS                       |\n");
    printf("#=====================================================================#\n");
    printf("[>] - Informe o CPf do funcionário para alterar os dados: ");
    scanf("%15s", cpf_funcionario_ler);
    while ((c = getchar()) != '\n' && c != EOF);
    
    Funcionario* fun = buscarFuncionario(lista, cpf_funcionario_ler);

    if (!fun) {
        printf("XXX - Funcionário não encontrado!\n");
        printf("[>] - Pressione Enter para continuar...");
        getchar();
        limparListaFuncionarios(lista);
        return;
    }
    
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
                    atualizarEntrada("[+] - novo_fun nome do Funcionário: ", fun->nome_funcionario, 100, validarNome);
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
            if (alt) {
                salvarListaFuncionarios(lista);
                printf("#====================================================#\n");
                printf("[o] - Dado(s) alterado(s) com sucesso!\n");
            }

            limparListaFuncionarios(lista);
            printf("[>] - Pressione Enter para continuar...");
            getchar();
}

void modulo_excluir_funcionario(void)
{   
    Funcionario* lista = carregarListaFuncionarios();
    if (!lista) {
        printf("XXX - Nenhum funcionário cadastrado!\n");
        printf("[>] - Pressione ENTER para continuar...");
        getchar();
        return;
    }

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

    Funcionario* atual_func = lista;

    while (atual_func) {
        if (strcmp(atual_func->cpf_funcionario, cpf_funcionario_ler) == 0 && atual_func->status) {
            func_encontrado = true;

            system("clear||cls");
            printf("#====================================================#\n");
            printf("|            [o] - Funcionário encontrado!           |\n");
            printf("#====================================================#\n");
            printf("| > Nome: %s\n", atual_func->nome_funcionario);
            printf("| > CPF: %s\n", atual_func->cpf_funcionario);
            printf("| > Data de Nascimento: %s\n", atual_func->dt_nascimento_fun);
            printf("| > Email: %s\n", atual_func->email_funcionario);
            printf("| > Cargo: %s\n", atual_func->cargo);
            printf("#====================================================#");
            printf("[?] - Deseja excluir o funcionário? (S/N): ");
            scanf(" %c", &confirmar);
            while ((c = getchar()) != '\n' && c != EOF);

            if (confirmar == 'S' || confirmar == 's') {
                atual_func->status = false;
                salvarListaFuncionarios(lista);
                printf("#====================================================#");
                printf("\n[o] - Funcionário excluído com sucesso!");
            }
            else {
                printf("\n[o] - Exclusão cancelada.\n");
            }

            break;
        }
        atual_func = atual_func->prox_func;
    }

    if (!func_encontrado){
        printf("XXX - Funcionário não encontrado...\n");
    }

    limparListaFuncionarios(lista);

    printf("\n[>] - Pressione Enter para continuar...");
    getchar();
}
