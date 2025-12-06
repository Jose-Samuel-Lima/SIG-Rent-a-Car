// |=============================================|
// |       SEÇÃO DE INCLUDE DE CLIENTES.C        |
// |=============================================|

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

#include "clientes.h"
#include "validacao.h"
#include "utilidades.h"

// |==================================================|
// |     MÓDULO DE TELA E NAVEGAÇÃO DE CLIENTES.C     |
// |==================================================|

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
            modulo_verificar_cliente();
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
    printf("|                         --------------------                        |\n");
    printf("|                         | SIG - Rent a Car |                        |\n");
    printf("|                         --------------------                        |\n");
    printf("#=====================================================================#\n");
    printf("|                           MÓDULO CLIENTES                           |\n");
    printf("|---------------------------------------------------------------------|\n");
    printf("|                       [1] - Cadastrar Cliente                       |\n");
    printf("|                       [2] - Verificar Cliente                       |\n");
    printf("|                       [3] - Atualizar Cliente                       |\n");
    printf("|                       [4] - Excluir Cliente                         |\n");
    printf("|---------------------------------------------------------------------|\n");
    printf("|                       [0] - Sair                                    |\n");
    printf("#=====================================================================#\n");
    printf("\n");
    printf("[>] - Escolha uma das opções acima: ");
    scanf(" %d", &op);
    while ((c = getchar()) != '\n' && c != EOF)
        ;
    printf("\n");
    printf("Processando...\n");
    return op;
}

// |=============================================|
// |    FUNÇÕES FUNCIONÁRIOS - LISTA DINÂMICA    |
// |=============================================|

// CLIENTE NA LISTA EM ORDEM ALFABÉTICA
void listaOrdenadaClientes(Cliente** lista_cliente, Cliente* novo_cli) 
{ 
    // Caso1: lista vazia - Novo vira o primeiro
    if (*lista_cliente == NULL) {
        novo_cli->prox_cli = NULL;
        *lista_cliente = novo_cli;
        return;
    }

    // Caso2: Novo deve ser inserido antes do primeiro elemento
    if (strcmp(novo_cli->nome_cliente, (*lista_cliente)->nome_cliente) < 0) {
        novo_cli->prox_cli = *lista_cliente;
        *lista_cliente = novo_cli;
        return;
    }

    // Caso3: inserir no meio ou final da lista
    Cliente* anter = *lista_cliente;
    Cliente* atual_cli = (*lista_cliente)->prox_cli;

    while (atual_cli != NULL &&
        strcmp(atual_cli->nome_cliente, novo_cli->nome_cliente) < 0) {

            anter = atual_cli;
            atual_cli = atual_cli->prox_cli;
        }

        anter->prox_cli = novo_cli;
        novo_cli->prox_cli = atual_cli;

}

// LEITURA DO ARQUIVO cliente.dat E MONTA LISTA ORDENADA
Cliente* carregarListaCliente() 
{
    FILE* fp = fopen("cliente.dat", "rb");   // <<< ARQUIVO CORRETO
    if (!fp) return NULL;

    Cliente temp;
    Cliente* lista_cliente = NULL;

    while (fread(&temp, sizeof(Cliente), 1, fp)) {
        if (temp.status == true) {
            Cliente* novo_cli = malloc(sizeof(Cliente));
            *novo_cli = temp;
            novo_cli->prox_cli = NULL;
            listaOrdenadaClientes(&lista_cliente, novo_cli);
        }
    }

    fclose(fp);
    return lista_cliente;
}

// BUSCA CLIENTE NA LISTA USANDO CPF
Cliente* buscarCliente(Cliente* lista_cliente, const char* cpf_cli) {
    Cliente* aux_cli = lista_cliente;
    while (aux_cli) {
        if (aux_cli->status && strcmp(aux_cli->cpf_cliente, cpf_cli) == 0) {
            return aux_cli;
        }
        aux_cli = aux_cli->prox_cli;
    }
    return NULL;
}

// SOBRESCREVE O ARQUIVO cliente.dat COM A LISTA ATUAL
void salvarListaCliente(Cliente* lista_cliente) {
    FILE* fp = fopen("cliente.dat", "wb");
    if (!fp) return;

    Cliente* aux_cli = lista_cliente;

    while (aux_cli != NULL) {
        fwrite(aux_cli, sizeof(Cliente), 1, fp);
        aux_cli = aux_cli->prox_cli;
    }

    fclose(fp);
}

// LIBERA MEMÓRIA ALOCADA PARA A LISTA DINÂMICA
void limparListaCliente(Cliente* lista_cliente) 
{
    Cliente* aux_cli;

    while (lista_cliente != NULL) {
        aux_cli = lista_cliente->prox_cli;
        free(lista_cliente);
        lista_cliente = aux_cli;
    }
}

// |===============================|
// |    FUNÇÕES CLIENTES - CRUD    |
// |===============================|

void modulo_cadastrar_cliente(void)
{
    system("clear||cls");

    Cliente *novo_cli = malloc(sizeof(Cliente));
    if (!novo_cli) return;
    
    printf("\n");
    printf("#=====================================================================#\n");
    printf("|                         --------------------                        |\n");
    printf("|                         | SIG - Rent a Car |                        |\n");
    printf("|                         --------------------                        |\n");
    printf("#=====================================================================#\n");
    printf("|                          CADASTRAR CLIENTES                         |\n");
    printf("#=====================================================================#\n");

    lerEntrada(novo_cli->nome_cliente, 100, "[+] - Nome: ", validarNome);
    lerEntrada(novo_cli->cpf_cliente, 15, "[+] - CPF: ", validarCPF);
    lerEntrada(novo_cli->data_cliente, 12, "[+] - Data de Nascimento (DD/MM/AAAA): ", validarData);
    lerEntrada(novo_cli->email_cliente, 100, "[+] - Email: ", validarEmail);
    lerEntrada(novo_cli->cnh_cliente, 19,"[+] - CNH: ", validarCNH);
    
    novo_cli->status = true;
    novo_cli->prox_cli = NULL;

    Cliente* lista_cliente = carregarListaCliente();

    listaOrdenadaClientes(&lista_cliente, novo_cli);

    salvarListaCliente(lista_cliente);

    limparListaCliente(lista_cliente);

    printf("#=====================================================================#\n");
    printf("[o] - Cliente Registrado com Sucesso!\n");
    printf("[>] - Pressione Enter para continuar...");
    getchar();
}

void modulo_verificar_cliente(void)
{
    system("clear||cls");
    
    char cpf_cliente_ler[15];

    printf("\n");
    printf("#=====================================================================#\n");
    printf("|                         --------------------                        |\n");
    printf("|                         | SIG - Rent a Car |                        |\n");
    printf("|                         --------------------                        |\n");
    printf("#=====================================================================#\n");
    printf("|                          VERIFICAR CLIENTE                          |\n");
    printf("#=====================================================================#\n");
    printf("\n");
    printf("[>] - Informe o CPf do funcionário que deseja encontrar: ");
    scanf("%15s", cpf_cliente_ler);
    while (getchar() != '\n');
    
    Cliente* lista_cliente = carregarListaCliente();
    Cliente* aux_cli = lista_cliente;

    while (aux_cli != NULL) {
        if (strcmp(aux_cli->cpf_cliente, cpf_cliente_ler) == 0 && aux_cli->status == true) {
            system("clear||cls");
            printf("#====================================================#\n");
            printf("|             [o] - Cliente encontrado!              |\n");
            printf("#====================================================#\n");
            printf("| > Nome: %s\n", aux_cli->nome_cliente);
            printf("| > CPF: %s\n", aux_cli->cpf_cliente);
            printf("| > Data de Nascimento: %s\n", aux_cli->data_cliente);
            printf("| > Email: %s\n", aux_cli->data_cliente);
            printf("| > CNH: %s\n", aux_cli->cnh_cliente);
            printf("#====================================================#\n");
            printf("[>] - Pressione Enter para continuar...");
            getchar();

            limparListaCliente(lista_cliente);
            return;
        }
        aux_cli = aux_cli->prox_cli;
        
    }

    limparListaCliente(lista_cliente);

    printf("#=====================================================================#\n");
    printf("XXX - Cliente não encontrado!\n");
    printf("[>] - Pressione Enter para continuar...");
    getchar();
}

void modulo_atualizar_clientes(void)
{
    Cliente* lista_cliente = carregarListaCliente();
    if (!lista_cliente) {
        printf("XXX - Nenhum cliente cadastrado!\n");
        printf("[>] - Pressione Enter para continuar...");
        getchar();
        return;
    }

    char cpf_cliente_ler[15];
    char op_cliente;
    int c;

    system("clear||cls");
    printf("\n");
    printf("#=====================================================================#\n");
    printf("|                         --------------------                        |\n");
    printf("|                         | SIG - Rent a Car |                        |\n");
    printf("|                         --------------------                        |\n");
    printf("#=====================================================================#\n");
    printf("|                          ATUALIZAR CLIENTE                          |\n");
    printf("#=====================================================================#\n");
    printf("[>] - Informe o CPf do funcionário para alterar os dados: ");
    scanf("%15s", cpf_cliente_ler);
    while ((c = getchar()) != '\n' && c != EOF);
    
    Cliente* cli = buscarCliente(lista_cliente, cpf_cliente_ler);
    
    if (!cli) {
        printf("XXX - Cliente não encontrado!\n");
        printf("[>] - Pressione Enter para continuar...");
        getchar();
        limparListaCliente(lista_cliente);
        return;
    }
            system("clear||cls");
            printf("#====================================================#\n");
            printf("|            [o] - Cliente encontrado!               |\n");
            printf("#====================================================#\n");
            printf("|            [1] - Nome                              |\n");
            printf("|            [2] - CPF                               |\n");
            printf("|            [3] - Data de Nascimento                |\n");
            printf("|            [4] - E-mail                            |\n");
            printf("|            [5] - CNH                               |\n");
            printf("|----------------------------------------------------|\n");
            printf("|            [0] - Cancelar                          |\n");
            printf("#====================================================#\n");
            printf("[>] - Informe qual informação deseja alterar: ");
            scanf(" %c", &op_cliente);
            while ((c = getchar()) != '\n' && c != EOF)
                ;
            
            int alt = 0; 

            switch(op_cliente){
                case '1':
                    atualizarEntrada("[+] - Novo nome do Cliente: ", cli->nome_cliente, 100, validarNome);
                    alt = 1;
                    break;

                case '2':
                    atualizarEntrada("[+] - Novo CPF do Cliente: ", cli->cpf_cliente, 15, validarCPF);
                    alt = 1;
                    break;
                    
                case '3':
                    atualizarEntrada("[+] - Nova data de nascimento (DD/MM/AAAA): ", cli->data_cliente, 12, validarData);
                    alt = 1;
                    break;

                case '4':
                    atualizarEntrada("[+] - Novo e-mail: ", cli->email_cliente, 100, validarEmail);
                    alt = 1;
                    break;


                case '5':
                    atualizarEntrada("[+] - Nova CNH: ", cli->cnh_cliente, 20, validarNome);
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
                salvarListaCliente(lista_cliente);
                printf("#====================================================#\n");
                printf("[o] - Dado(s) alterado(s) com sucesso!\n");
            }

            limparListaCliente(lista_cliente);
            printf("[>] - Pressione Enter para continuar...");
            getchar();
        
}

void modulo_excluir_cliente(void)
{
    Cliente* lista_cliente = carregarListaCliente();
    if (!lista_cliente) {
        printf("XXX - Nenhum cliente cadastrado!\n");
        printf("[>] - Pressione ENTER para continuar...");
        getchar();
        return;
    }

    char cpf_cliente_ler[15];
    int c;
    bool cli_encontrado = false;
    char confirmar;

    system("clear||cls");
    printf("\n");
    printf("#=====================================================================#\n");
    printf("|                         --------------------                        |\n");
    printf("|                         | SIG - Rent a Car |                        |\n");
    printf("|                         --------------------                        |\n");
    printf("#=====================================================================#\n");
    printf("|                           EXCLUIR CLIENTES                          |\n");
    printf("#=====================================================================#\n");
    printf("\n");

    printf("[>] - Informe o CPF do funcionário que deseja excluir: ");
    scanf("%14s", cpf_cliente_ler);
    while ((c = getchar()) != '\n' && c != EOF);

    Cliente* atual_cli = lista_cliente;

    while (atual_cli) {
        if (strcmp(atual_cli->cpf_cliente, cpf_cliente_ler) == 0 && atual_cli->status) {
            cli_encontrado = true;

            system("clear||cls");
            printf("#====================================================#\n");
            printf("|            [o] - Cliente encontrado!               |\n");
            printf("#====================================================#\n");
            printf("| > Nome: %s\n", atual_cli->nome_cliente);
            printf("| > CPF: %s\n", atual_cli->cpf_cliente);
            printf("| > Data de Nascimento: %s\n", atual_cli->data_cliente);
            printf("| > Email: %s\n", atual_cli->email_cliente);
            printf("| > CNH: %s\n", atual_cli->cnh_cliente);
            printf("#====================================================#");
            printf("\n[?] - Deseja excluir o cliente? (S/N): ");
            scanf(" %c", &confirmar);
            while ((c = getchar()) != '\n' && c != EOF);

            if (confirmar == 'S' || confirmar == 's') {
                atual_cli->status = false;
                salvarListaCliente(lista_cliente);
                printf("#================================================#");
                printf("\n[o] - Cliente excluído com sucesso!");
            }
            else {
                printf("\n[o] - Exclusão cancelada.\n");
            }

            break;
        }
        atual_cli = atual_cli->prox_cli;
    }

    if (!cli_encontrado){
        printf("XXX - Cliente não encontrado...\n");
    }

    limparListaCliente(lista_cliente);

    printf("\n[>] - Pressione Enter para continuar...");
    getchar();
}