// =============================================|
// SEÇÃO DE INCLUDE DE FUNCIONARIOS.C           |
// =============================================|

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

#include "funcionarios.h"
#include "validacao.h"
#include "utilidades.h"

// =============================================|
// MÓDULO DE TELA E NAVEGAÇÃO DE FUNCIONARIOS.C |
// =============================================|

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

// =============================================|
// FUNÇÕES FUNCIONÁRIOS - LISTA DINÂMICA        |
// =============================================|

// FUNCIONÁRIO NA LISTA EM ORDEM ALFABÉTICA
void listaOrdenada(Funcionario** lista, Funcionario* novo) 
{ 
    // Caso1: lista vazia - Novo vira o primeiro
    if (*lista == NULL) {
        novo->prox = NULL;
        *lista = novo;
        return;
    }

    // Caso2: Novo deve ser inserido antes do primeiro elemento
    if (strcmp(novo->nome_funcionario, (*lista)->nome_funcionario) < 0) {
        novo->prox = *lista;
        *lista = novo;
        return;
    }

    // Caso3: inserir no meio ou final da lista
    Funcionario* anter = *lista;
    Funcionario* atual = (*lista)->prox;

    while (atual != NULL &&
        strcmp(atual->nome_funcionario, novo->nome_funcionario) < 0) {

            anter = atual;
            atual = atual->prox;
        }

        anter->prox = novo;
        novo->prox = atual;

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
            Funcionario* novo = malloc(sizeof(Funcionario));
            *novo = temp;
            novo->prox = NULL;
            listaOrdenada(&lista, novo);
        }
    }

    fclose(fp);
    return lista;
}

// BUSCA FUNCIONÁRIO NA LISTA USANDO CPF
Funcionario* buscarFuncionario(Funcionario* lista, const char* cpf) {
    Funcionario* aux = lista;
    while (aux) {
        if (aux->status && strcmp(aux->cpf_funcionario, cpf) == 0) {
            return aux;
        }
        aux = aux->prox;
    }
    return NULL;
}

// SOBRESCREVE O ARQUIVO funcionario.dat COM A LISTA ATUAL
void salvarListaFuncionarios(Funcionario* lista) {
    FILE* fp = fopen("funcionario.dat", "wb");
    if (!fp) return;

    Funcionario* aux = lista;

    while (aux != NULL) {
        fwrite(aux, sizeof(Funcionario), 1, fp);
        aux = aux->prox;
    }

    fclose(fp);
}

// LIBERA MEMÓRIA ALOCADA PARA A LISTA DINÂMICA
void limparListaFuncionarios(Funcionario* lista) 
{
    Funcionario* aux;

    while (lista != NULL) {
        aux = lista->prox;
        free(lista);
        lista = aux;
    }
}

// =============================================|
// MÓDULOS DE CRUD DE FUNCIONARIOS.C            |
// =============================================|

void modulo_cadastrar_funcionario(void)
{
    system("clear||cls");

    Funcionario *novo = malloc(sizeof(Funcionario));
    if (!novo) return;

    printf("#=====================================================================#\n");
    printf("|                         --------------------                        |\n");
    printf("|                         | SIG - Rent a Car |                        |\n");
    printf("|                         --------------------                        |\n");
    printf("#=====================================================================#\n");
    printf("|                        CADASTRAR FUNCIONÁRIOS                       |\n");
    printf("#=====================================================================#\n");

    lerEntrada(novo->nome_funcionario, 100, "[+] - Nome: ", validarNome);
    lerEntrada(novo->cpf_funcionario, 15, "[+] - CPF: ", validarCPF);
    lerEntrada(novo->dt_nascimento_fun, 12, "[+] - Data (DD/MM/AAAA): ", validarData);
    lerEntrada(novo->email_funcionario, 100, "[+] - Email: ", validarEmail);
    lerEntrada(novo->cargo, 51, "[+] - Cargo: ", validarNome);

    novo->status = true;
    novo->prox = NULL;
    
    Funcionario* lista = carregarListaFuncionarios();

    listaOrdenada(&lista, novo);

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
    Funcionario* aux = lista;
    
    while (aux != NULL) {
        if (strcmp(aux->cpf_funcionario, cpf_funcionario_ler) == 0 && aux->status == true) {
            system("clear||cls");
            printf("#====================================================#\n");
            printf("|            [o] - Funcionário encontrado!           |\n");
            printf("#====================================================#\n");
            printf("| > Nome: %s\n", aux->nome_funcionario);
            printf("| > CPF: %s\n", aux->cpf_funcionario);
            printf("| > Data de Nascimento: %s\n", aux->dt_nascimento_fun);
            printf("| > Email: %s\n", aux->email_funcionario);
            printf("| > Cargo: %s\n", aux->cargo);
            printf("#====================================================#\n");
            printf("[>] - Pressione Enter para continuar...");
            getchar();

            limparListaFuncionarios(lista);
            return;
        }
        aux = aux->prox;
        
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
    printf("\n");

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

    Funcionario* atual = lista;

    while (atual) {
        if (strcmp(atual->cpf_funcionario, cpf_funcionario_ler) == 0 && atual->status) {
            func_encontrado = true;

            system("clear||cls");
            printf("#====================================================#\n");
            printf("|            [o] - Funcionário encontrado!           |\n");
            printf("#====================================================#\n");
            printf("| > Nome: %s\n", atual->nome_funcionario);
            printf("| > CPF: %s\n", atual->cpf_funcionario);
            printf("| > Data de Nascimento: %s\n", atual->dt_nascimento_fun);
            printf("| > Email: %s\n", atual->email_funcionario);
            printf("| > Cargo: %s\n", atual->cargo);
            printf("#====================================================#");
            printf("[?] - Deseja excluir o funcionário? (S/N): ");
            scanf(" %c", &confirmar);
            while ((c = getchar()) != '\n' && c != EOF);

            if (confirmar == 'S' || confirmar == 's') {
                atual->status = false;
                salvarListaFuncionarios(lista);
                printf("#====================================================#");
                printf("\n[o] - Funcionário excluído com sucesso!");
            }
            else {
                printf("\n[o] - Exclusão cancelada.\n");
            }

            break;
        }
        atual = atual->prox;
    }

    if (!func_encontrado){
        printf("XXX - Funcionário não encontrado...\n");
    }

    limparListaFuncionarios(lista);

    printf("\n[>] - Pressione Enter para continuar...");
    getchar();
}
