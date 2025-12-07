#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <time.h>

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
        case 3:
            modulo_atualizar_aluguel();
            break;
        case 4:
            modulo_excluir_aluguel();
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
    printf("|                         --------------------                        |\n");
    printf("|                         | SIG - Rent a Car |                        |\n");
    printf("|                         --------------------                        |\n");
    printf("#=====================================================================#\n");
    printf("|                            MÓDULO ALUGUEIS                          |\n");
    printf("|---------------------------------------------------------------------|\n");
    printf("|                       [1] - Cadastrar Aluguel                       |\n");
    printf("|                       [2] - Verificar Aluguel                       |\n");
    printf("|                       [3] - Atualizar Aluguel                       |\n");
    printf("|                       [4] - Excluir Aluguel                         |\n");
    printf("|---------------------------------------------------------------------|\n");
    printf("|                       [0] - Sair                                    |\n");
    printf("#=====================================================================#\n");
    printf("\n");
    printf("[>] - Escolha uma das opções acima: ");
    scanf(" %d", &op);
    while ((c = getchar()) != '\n' && c != EOF);
    printf("Processando...\n");
    return op;
}

// |====================================================|
// |                 FUNÇÕES AUXILIARES                 |
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

Aluguel* buscarAluguelID(Aluguel* lista_aluguel, const char* id)
{
    Aluguel* aux_alu = lista_aluguel;
    while (aux_alu) {
        if (aux_alu->status && strcmp(aux_alu->id, id) == 0) { 
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

float calcular_valor_total(int dias, float preco_veiculo) {
    return (float)dias * preco_veiculo;
}

struct tm strParaData(const char* str) {
    struct tm data = {0};
    sscanf(str, "%2d/%2d/%4d", &data.tm_mday, &data.tm_mon, &data.tm_year);
    data.tm_mon -= 1;       // tm_mon vai de 0 a 11
    data.tm_year -= 1900;   // tm_year é ano desde 1900
    return data;
}

bool verificarDisponibilidadeVeiculo(Aluguel* lista_aluguel, const char* placa, const char* novo_inicio, const char* novo_fim, const char* id_atual) {
    struct tm novoIni = strParaData(novo_inicio);
    struct tm novoFim = strParaData(novo_fim);
    time_t tNovoIni = mktime(&novoIni);
    time_t tNovoFim = mktime(&novoFim);

    Aluguel* aux = lista_aluguel;
    while (aux) {
        if (aux->status && strcmp(aux->placa_veiculo, placa) == 0 && strcmp(aux->id, id_atual) != 0) {
            struct tm existIni = strParaData(aux->data_inicio);
            struct tm existFim = strParaData(aux->data_fim);
            time_t tExistIni = mktime(&existIni);
            time_t tExistFim = mktime(&existFim);

            if (!(tNovoFim < tExistIni || tNovoIni > tExistFim)) {
                return false;
            }
        }
        aux = aux->prox_alu;
    }
    return true;
}


// |====================================================|
// |                    CRUD ALUGUEL                    |
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
    printf("|                          CADASTRAR ALUGUEIS                         |\n");
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
        printf("XXX - Veículo não encontrado ou não está disponível!\n");
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

    // ===================== VERIFICAR DISPONIBILIDADE =====================
    Aluguel *lista_aluguel = carregarListaAlugueis();

    if (!verificarDisponibilidadeVeiculo(lista_aluguel, veiculo_encontrado->placa_veiculo,
                                         novo_aluguel->data_inicio, novo_aluguel->data_fim, ""))
    {
        printf("XXX - ERRO: Veículo PLACA %s já está alugado ou indisponível no período solicitado!\n", veiculo_encontrado->placa_veiculo);
        free(novo_aluguel);
        limparListaAlugueis(lista_aluguel);
        printf("[>] - Pressione Enter para voltar...");
        getchar();
        return;
    }

    // ===================== FINALIZAR CADASTRO =====================
    novo_aluguel->status = true;
    novo_aluguel->prox_alu = NULL;

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
    system("clear||cls");
    char id_busca[5];
    
    // Variáveis auxiliares para buscar e calcular
    int dias;
    float preco_veiculo;
    float valor_total;

    // Ponteiros para as listas
    Aluguel *lista_aluguel = NULL;
    Cliente *lista_cliente = NULL;
    Veiculo *lista_veiculo = NULL;
    
    // Ponteiros para os registros encontrados
    Aluguel *aluguel_encontrado = NULL;
    Cliente *cliente_encontrado = NULL;
    Veiculo *veiculo_encontrado = NULL;

    printf("#=====================================================================#\n");
    printf("|                         --------------------                        |\n");
    printf("|                         | SIG - Rent a Car |                        |\n");
    printf("|                         --------------------                        |\n");
    printf("#=====================================================================#\n");
    printf("|                          VERIFICAR ALUGUEIS                         |\n");
    printf("#=====================================================================#\n");

    // --- 1. BUSCA INICIAL PELO ID DO ALUGUEL ---
    printf("[>] - Informe o ID do Aluguel (Ex: #001): ");
    scanf("%4s", id_busca);
    while (getchar() != '\n');

    lista_aluguel = carregarListaAlugueis();
    aluguel_encontrado = buscarAluguelID(lista_aluguel, id_busca);

    if (!aluguel_encontrado) {
        printf("XXX - Aluguel com ID '%s' não encontrado, inativo ou finalizado!\n", id_busca);
        limparListaAlugueis(lista_aluguel);
        printf("[>] - Pressione Enter para voltar...");
        getchar();
        return; // Sai da função
    }

    // --- 2. BUSCAR CLIENTE E VEÍCULO (Por Referência) ---
    lista_cliente = carregarListaCliente();
    lista_veiculo = carregarListaVeiculos();

    cliente_encontrado = buscarCliente(lista_cliente, aluguel_encontrado->cpf_cliente);
    veiculo_encontrado = buscarVeiculo(lista_veiculo, aluguel_encontrado->placa_veiculo);
    
    // Verificação de integridade
    if (!cliente_encontrado || !veiculo_encontrado) {
        printf("XXX - Erro de integridade: Cliente ou Veículo referenciado não encontrado nos cadastros.\n");
        // Limpa todas as listas antes de sair
        limparListaAlugueis(lista_aluguel);
        limparListaCliente(lista_cliente);
        limparListaVeiculos(lista_veiculo);
        printf("[>] - Pressione Enter para voltar...");
        getchar();
        return; // Sai da função
    }

    // --- 3. CÁLCULOS FINAIS ---
    preco_veiculo = veiculo_encontrado->preco_veiculo; 
    dias = diasEntreDatas(aluguel_encontrado->data_inicio, aluguel_encontrado->data_fim);
    valor_total = calcular_valor_total(dias, preco_veiculo);

    // --- 4. EXIBIÇÃO DOS DETALHES ---
    printf("\n#======================= DETALHES DO ALUGUEL (ID: %s) =========================#\n", aluguel_encontrado->id);
    printf("CLIENTE:\n");
    printf("  Nome: %s\n", cliente_encontrado->nome_cliente);
    printf("  CPF: %s\n", cliente_encontrado->cpf_cliente);
    printf("  -----------------------------------------------------------------------\n");
    printf("\nVEÍCULO:\n");
    printf("  Placa: %s\n", veiculo_encontrado->placa_veiculo);
    printf("  Modelo: %s\n", veiculo_encontrado->modelo_veiculo);
    printf("  Preço Diário: R$ %.2f\n", preco_veiculo);
    printf("  -----------------------------------------------------------------------\n");
    printf("\nPERÍODO E VALOR:\n");
    printf("  Início: %s\n", aluguel_encontrado->data_inicio);
    printf("  Término: %s\n", aluguel_encontrado->data_fim);
    printf("  Dias Alugados: %d dias\n", dias);
    printf("  -----------------------------------------------------------------------\n");
    printf("  VALOR TOTAL (R$ %.2f x %d dias): R$ %.2f\n", preco_veiculo, dias, valor_total);
    printf("  -----------------------------------------------------------------------\n");

    // --- 5. LIMPEZA FINAL (ALCANCE BEM-SUCEDIDO) ---
    // Limpa as listas após a exibição bem-sucedida
    limparListaAlugueis(lista_aluguel);
    limparListaCliente(lista_cliente);
    limparListaVeiculos(lista_veiculo);

    printf("\n[>] - Pressione Enter para continuar...");
    getchar();
}

void modulo_atualizar_aluguel(void) 
{
    system("clear||cls");
    char id_busca[5];
    
    Aluguel *lista_aluguel = NULL;
    Veiculo *lista_veiculo = NULL; 
    
    Aluguel *aluguel_atualizar = NULL;
    Veiculo *veiculo_encontrado = NULL;
    
    int dias;
    float valor_total;

    printf("#=====================================================================#\n");
    printf("|                         --------------------                        |\n");
    printf("|                         | SIG - Rent a Car |                        |\n");
    printf("|                         --------------------                        |\n");
    printf("#=====================================================================#\n");
    printf("|                        ATUALIZAR FUNCIONÁRIOS                       |\n");
    printf("#=====================================================================#\n");

    
    printf("[>] - Informe o ID do Aluguel a ser atualizado (Ex: #001): ");
    scanf("%4s", id_busca);
    while (getchar() != '\n');

    lista_aluguel = carregarListaAlugueis();
    aluguel_atualizar = buscarAluguelID(lista_aluguel, id_busca);

    if (!aluguel_atualizar) {
        printf("XXX - Aluguel com ID '%s' não encontrado ou não está ativo!\n", id_busca);
        limparListaAlugueis(lista_aluguel);
        printf("[>] - Pressione Enter para voltar...");
        getchar();
        return;
    }
    
    char data_inicio_antiga[11];
    char data_fim_antiga[11];
    strcpy(data_inicio_antiga, aluguel_atualizar->data_inicio);
    strcpy(data_fim_antiga, aluguel_atualizar->data_fim);

    printf("\n[o] - Datas Atuais: Início (%s) | Término (%s)\n", data_inicio_antiga, data_fim_antiga);
    printf("-----------------------------------------------------------------------\n");
    
    printf("[>] - Informe a NOVA data de Início (dd/mm/aaaa): ");
    scanf("%10s", aluguel_atualizar->data_inicio);
    while (getchar() != '\n');

    printf("[>] - Informe a NOVA data de Término (dd/mm/aaaa): ");
    scanf("%10s", aluguel_atualizar->data_fim);
    while (getchar() != '\n');
    
    // ===================== VERIFICAR DISPONIBILIDADE =====================
    if (!verificarDisponibilidadeVeiculo(lista_aluguel, aluguel_atualizar->placa_veiculo,
                                         aluguel_atualizar->data_inicio, aluguel_atualizar->data_fim,
                                         aluguel_atualizar->id))
    {
        printf("XXX - ERRO: Veículo PLACA %s já está alugado ou indisponível no período solicitado!\n", aluguel_atualizar->placa_veiculo);
        // Reverte para datas antigas
        strcpy(aluguel_atualizar->data_inicio, data_inicio_antiga);
        strcpy(aluguel_atualizar->data_fim, data_fim_antiga);
        limparListaAlugueis(lista_aluguel);
        printf("[>] - Pressione Enter para voltar...");
        getchar();
        return;
    }

    // ===================== RECALCULAR VALOR =====================
    lista_veiculo = carregarListaVeiculos();
    veiculo_encontrado = buscarVeiculo(lista_veiculo, aluguel_atualizar->placa_veiculo);

    if (veiculo_encontrado) {
        dias = diasEntreDatas(aluguel_atualizar->data_inicio, aluguel_atualizar->data_fim);
        float preco_veiculo = veiculo_encontrado->preco_veiculo;
        valor_total = calcular_valor_total(dias, preco_veiculo);

        printf("\n[o] - Aluguel atualizado com sucesso!\n");
        printf("  - Novo Período de %d dias\n", dias);
        printf("  - Novo Valor: R$ %.2f\n", valor_total);

        limparListaVeiculos(lista_veiculo);
    } else {
        printf("XXX - Aviso: Veículo referenciado não encontrado. Não foi possível recalcular o novo valor.\n");
    }

    // ===================== SALVAR LISTA =====================
    salvarListaAlugueis(lista_aluguel);
    limparListaAlugueis(lista_aluguel);

    printf("\n[>] - Pressione Enter para continuar...");
    getchar();
}

void modulo_excluir_aluguel(void) 
{
    system("clear||cls");
    char id_busca[5];
    char confirmacao;
    
    Aluguel *lista_aluguel = NULL;
    Veiculo *lista_veiculo = NULL; 
    
    Aluguel *aluguel_excluir = NULL;
    Veiculo *veiculo_encontrado = NULL;
    
    int dias;
    float valor_total;

    printf("#=====================================================================#\n");
    printf("|                         --------------------                        |\n");
    printf("|                         | SIG - Rent a Car |                        |\n");
    printf("|                         --------------------                        |\n");
    printf("#=====================================================================#\n");
    printf("|                           EXCLUIR ALUGUEIS                          |\n");
    printf("#=====================================================================#\n");

    
    // --- 1. BUSCA ---
    printf("[>] - Informe o ID do Aluguel a ser finalizado (Ex: #001): ");
    scanf("%4s", id_busca);
    while (getchar() != '\n');

    lista_aluguel = carregarListaAlugueis();
    aluguel_excluir = buscarAluguelID(lista_aluguel, id_busca);

    if (!aluguel_excluir) {
        printf("XXX - Aluguel com ID '%s' não encontrado ou já está finalizado!\n", id_busca);
        limparListaAlugueis(lista_aluguel);
        printf("[>] - Pressione Enter para voltar...");
        getchar();
        return;
    }
    
    // --- 2. RECUPERAÇÃO DE DADOS (Para Exibição) ---
    lista_veiculo = carregarListaVeiculos();
    veiculo_encontrado = buscarVeiculo(lista_veiculo, aluguel_excluir->placa_veiculo);
    
    if (!veiculo_encontrado) {
        printf("XXX - Erro: Veículo referenciado não encontrado. Não é possível calcular o valor.\n");
        limparListaAlugueis(lista_aluguel);
        limparListaVeiculos(lista_veiculo);
        printf("[>] - Pressione Enter para voltar...");
        getchar();
        return;
    }
    
    // Cálculo do valor com as datas REGISTRADAS (data_inicio e data_fim original)
    dias = diasEntreDatas(aluguel_excluir->data_inicio, aluguel_excluir->data_fim);
    valor_total = calcular_valor_total(dias, veiculo_encontrado->preco_veiculo);

    // --- 3. EXIBIÇÃO E CONFIRMAÇÃO ---
    printf("\n#======================= DETALHES DO ALUGUEL (ID: %s) =========================#\n", aluguel_excluir->id);
    printf("  - CPF Cliente: %s\n", aluguel_excluir->cpf_cliente);
    printf("  - Placa Veículo: %s\n", aluguel_excluir->placa_veiculo);
    printf("  - Período: %s até %s (%d dias)\n", aluguel_excluir->data_inicio, aluguel_excluir->data_fim, dias);
    printf("  - VALOR TOTAL ESTIMADO: R$ %.2f\n", valor_total);
    printf("#==============================================================================#\n");

    printf("\n[>] - Tem certeza que deseja FINALIZAR este aluguel? (S/N): ");
    scanf(" %c", &confirmacao); // O espaço antes de %c evita quebra de linha do buffer
    while (getchar() != '\n');

    if (confirmacao == 's' || confirmacao == 'S') {
        // --- 4. EXCLUSÃO/FINALIZAÇÃO ---
        aluguel_excluir->status = false; // Desativa o aluguel
        
        // Libera o Veículo
        veiculo_encontrado->status = true; // Veículo agora está disponível
        salvarListaVeiculos(lista_veiculo);

        // Salva o Aluguel finalizado
        salvarListaAlugueis(lista_aluguel);
        
        printf("\n[o] - Aluguel ID %s FINALIZADO e Veículo liberado com sucesso!\n", id_busca);

    } else {
        printf("\n[o] - Operação cancelada. O aluguel permanece ATIVO.\n");
    }

    // --- 5. LIMPEZA FINAL ---
    limparListaAlugueis(lista_aluguel);
    limparListaVeiculos(lista_veiculo);
    
    printf("\n[>] - Pressione Enter para continuar...");
    getchar();
}