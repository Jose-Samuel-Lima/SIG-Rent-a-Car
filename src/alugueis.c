#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

#include "alugueis.h"
#include "clientes.h"
#include "veiculos.h"
#include "validacao.h"

// |====================================================|
// |       MODULO DE TELA E NAVEGAÇÃO DE ALUGUEL        |
// |====================================================|

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
            modulo_verificar_aluguel();
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
    printf("[>] - Escolha uma das opções acima: ");
    scanf(" %d", &op);
    while ((c = getchar()) != '\n' && c != EOF);
    printf("Processando...\n");
    return op;
}

// |====================================================|
// |               LISTA DINÂMICA ALUGUEL               |
// |====================================================|

void listaOrdenadaAlugueis(Aluguel** lista_aluguel, Aluguel* novo_alu) 
{ 
    // Caso1: lista vazia - Novo vira o primeiro
    if (*lista_aluguel == NULL) {
        novo_alu->prox_alu = NULL;
        *lista_aluguel = novo_alu;
        return;
    }

    // Caso2: Novo deve ser inserido antes do primeiro elemento
    if (strcmp(novo_alu->cpf_cliente, (*lista_aluguel)->cpf_cliente) < 0) {
        novo_alu->prox_alu = *lista_aluguel;
        *lista_aluguel = novo_alu;
        return;
    }

    // Caso3: inserir no meio ou final da lista
    Aluguel* anter = *lista_aluguel;
    Aluguel* atual_alu = (*lista_aluguel)->prox_alu;

    while (atual_alu != NULL &&
        strcmp(atual_alu->cpf_cliente, novo_alu->cpf_cliente) < 0) {
            anter = atual_alu;
            atual_alu = atual_alu->prox_alu;
        }

    anter->prox_alu = novo_alu;
    novo_alu->prox_alu = atual_alu;
}

Aluguel* carregarListaAlugueis()
{
    FILE* fp = fopen("aluguel.dat", "rb");
    if (!fp) return NULL;

    Aluguel temp;
    Aluguel* lista_aluguel = NULL;

    while (fread(&temp, sizeof(Aluguel), 1, fp)) {
        if (temp.status == true) {
            Aluguel* novo_alu = malloc(sizeof(Aluguel));
            *novo_alu = temp;
            novo_alu->prox_alu = NULL;

            listaOrdenadaAlugueis(&lista_aluguel, novo_alu);
        }
    }

    fclose(fp);
    return lista_aluguel;
}

Aluguel* buscarAluguel(Aluguel* lista_aluguel, const char* cpf_cli)
{
    Aluguel* aux_alu = lista_aluguel;
    while (aux_alu) {
        if (aux_alu->status && strcmp(aux_alu->cpf_cliente, cpf_cli) == 0) {
            return aux_alu;
        }
        aux_alu = aux_alu->prox_alu;
    }

    return NULL;
}

void salvarListaAlugueis(Aluguel* lista_aluguel)
{
    FILE* fp = fopen("aluguel.dat", "wb");
    if (!fp) return;

    Aluguel* aux_alu = lista_aluguel;

    while (aux_alu != NULL) {
        fwrite(aux_alu, sizeof(Aluguel), 1, fp);
        aux_alu = aux_alu->prox_alu;
    }

    fclose(fp);
}

void limparListaAlugueis(Aluguel* lista_aluguel)
{
    Aluguel* aux_alu;

    while (lista_aluguel != NULL) {
        aux_alu = lista_aluguel->prox_alu;
        free(lista_aluguel);
        lista_aluguel = aux_alu;
    }
}

// GERAÇÃO DE ID
void gerarID_aluguel(char *destino) {
    int ultimo_numero = 0;
    FILE *fp;

    // 1. Tenta ler o último número gerado
    fp = fopen(ARQUIVO_ID, "r");
    if (fp != NULL) {
        // Se o arquivo existe, lê o número
        if (fscanf(fp, "%d", &ultimo_numero) != 1) {
            // Se a leitura falhar, reinicia a contagem
            ultimo_numero = 0;
        }
        fclose(fp);
    }

    // 2. Incrementa o número
    ultimo_numero++;

    // 3. Salva o novo último número de volta no arquivo
    fp = fopen(ARQUIVO_ID, "w");
    if (fp != NULL) {
        fprintf(fp, "%d", ultimo_numero);
        fclose(fp);
    } else {
        // Tratar erro: não foi possível abrir/criar o arquivo para escrita
        fprintf(stderr, "ERRO: Não foi possível salvar o novo ID sequencial.\n");
        // Se não puder salvar, o programa pode continuar, mas o ID não será persistido.
    }

    // 4. Formata o ID no padrão desejado (#001, #010, #100)
    // O "%03d" garante que o número terá 3 dígitos, preenchendo com zeros à esquerda.
    // O destino deve ter tamanho suficiente (mínimo de 5 caracteres: # + 3 dígitos + \0)
    sprintf(destino, "#%03d", ultimo_numero);
}

// |====================================================|
// |                  CADASTRAR ALUGUEL                 |
// |====================================================|

void modulo_cadastrar_aluguel(void)
{
    system("clear||cls");

    char buscar_cpf_cliente[15];
    char buscar_placa_veiculo[10];

    printf("#=====================================================================#\n");
    printf("|                         --------------------                        |\n");
    printf("|                         | SIG - Rent a Car |                        |\n");
    printf("|                         --------------------                        |\n");
    printf("#=====================================================================#\n");
    printf("|                          CADASTRAR ALUGUEL                          |\n");
    printf("#=====================================================================#\n");

    // ===================== BUSCAR CLIENTE =====================
    printf("[>] - Informe o CPF do Cliente: ");
    scanf("%14s", buscar_cpf_cliente);
    while (getchar() != '\n');

    Cliente *lista_cliente = carregarListaCliente();
    Cliente *aux_cli = lista_cliente;
    Cliente *cliente_encontrado = NULL;

    while (aux_cli) {
        if (strcmp(aux_cli->cpf_cliente, buscar_cpf_cliente) == 0 &&
            aux_cli->status == true)
        {
            cliente_encontrado = aux_cli;
            break;
        }
        aux_cli = aux_cli->prox_cli;
    }

    if (!cliente_encontrado) {
        printf("XXX - Cliente não encontrado!\n");
        printf("[>] - Pressione Enter para voltar...");
        getchar();
        limparListaCliente(lista_cliente);
        return;
    }

    limparListaCliente(lista_cliente);

    // ===================== BUSCAR VEÍCULO =====================
    printf("[>] - Informe a placa do veículo: ");
    scanf("%9s", buscar_placa_veiculo);
    while (getchar() != '\n');

    Veiculo *lista_veiculo = carregarListaVeiculos();
    Veiculo *aux_vei = lista_veiculo;
    Veiculo *veiculo_encontrado = NULL;

    while (aux_vei) {
        if (strcmp(aux_vei->placa_veiculo, buscar_placa_veiculo) == 0 &&
            aux_vei->status == true)
        {
            veiculo_encontrado = aux_vei;
            break;
        }
        aux_vei = aux_vei->prox_vei;
    }

    if (!veiculo_encontrado) {
        printf("XXX - Veículo não encontrado!\n");
        printf("[>] - Pressione Enter para voltar...");
        getchar();
        limparListaVeiculos(lista_veiculo);
        return;
    }

    limparListaVeiculos(lista_veiculo);

    // ===================== CRIAR NOVO ALUGUEL =====================
    Aluguel *novo_aluguel = malloc(sizeof(Aluguel));
    if (!novo_aluguel) {
        printf("Erro ao alocar memória!\n");
        return;
    }

    
    gerarID_aluguel(novo_aluguel->id); 
    
    strcpy(novo_aluguel->cpf_cliente, buscar_cpf_cliente);
    strcpy(novo_aluguel->placa_veiculo, buscar_placa_veiculo);

    printf("#=====================================================================#\n");
    printf("[o] - Novo ID de Aluguel Gerado: %s\n", novo_aluguel->id); 
    printf("#=====================================================================#\n");


    printf("[>] - Informe data de início (dd/mm/aaaa): ");
    scanf("%10s", novo_aluguel->data_inicio);
    while (getchar() != '\n');

    printf("[>] - Informe data de término (dd/mm/aaaa): ");
    scanf("%10s", novo_aluguel->data_fim);
    while (getchar() != '\n');

    novo_aluguel->status = true;
    novo_aluguel->prox_alu = NULL;

    // ===================== SALVAR ALUGUEL =====================
    Aluguel *lista_aluguel = carregarListaAlugueis();
    listaOrdenadaAlugueis(&lista_aluguel, novo_aluguel);
    salvarListaAlugueis(lista_aluguel);
    limparListaAlugueis(lista_aluguel);

    printf("#=====================================================================#\n");
    printf("[o] - Aluguel cadastrado com sucesso!\n");
    printf("[>] - Pressione Enter para continuar...");
    getchar();
}

void modulo_verificar_aluguel(void)
{

}