// |==========================================|
// |    SEÇÃO DE INCLUDE DE VEICULOS.C        |
// |==========================================|

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

#include "veiculos.h"
#include "validacao.h"
#include "utilidades.h"

// |====================================================|
// |    MÓDULO DE TELA E NAVEGAÇÃO DE FUNCIONÁRIOS.C    |
// |====================================================|

int modulo_veiculo(void)
{
    int escVeiculo;
    do
    {
        escVeiculo = modulo_tela_veiculos();
        switch (escVeiculo)
        {
        case 1:
            modulo_cadastrar_veiculo();
            break;
        case 2:
            modulo_verificar_veiculo();
            break;
        case 3:
            modulo_atualizar_veiculo();
            break;
        case 4:
            modulo_excluir_veiculo();
            break;
        case 0:
            return -1;
        }

    } while (escVeiculo != 0);
    
    return -1;
}

int modulo_tela_veiculos(void)
{
    int op_veiculo;
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
    printf("|                   < = = = Módulo de Veículos = = = >                |\n");
    printf("|                                                                     |\n");
    printf("|                    # 1 # Cadastrar novo veículo                     |\n");
    printf("|                    # 2 # Dados do veículo                           |\n");
    printf("|                    # 3 # Alterar dados do veículo                   |\n");
    printf("|                    # 4 # Excluir um veículo                         |\n");
    printf("|                    # 0 # Voltar ao menu principal                   |\n");
    printf("|                                                                     |\n");
    printf("#=====================================================================#\n");
    printf("\n");
    printf("[>] - Escolha uma das opções acima: ");
    scanf(" %d", &op_veiculo);
    while ((c = getchar()) != '\n' && c != EOF)
        ;
    return op_veiculo;
}

// |=========================================|
// |   FUNÇÕES VEÍCULOS - LISTA DINÂMICA     |
// |=========================================|

void listaOrdenadaVeiculos(Veiculo** lista_veiculo, Veiculo* novo_vei)
{
    if (*lista_veiculo == NULL) {
        novo_vei->prox_vei = NULL;
        *lista_veiculo = novo_vei;
        return;
    }

    if (strcmp(novo_vei->modelo_veiculo, (*lista_veiculo)->modelo_veiculo) < 0) {
        novo_vei->prox_vei = *lista_veiculo;
        *lista_veiculo = novo_vei;
        return;
    }

    Veiculo* anterior = *lista_veiculo;
    Veiculo* atual = (*lista_veiculo)->prox_vei;

    while (atual != NULL &&
           strcmp(atual->modelo_veiculo, novo_vei->modelo_veiculo) < 0) 
    {
        anterior = atual;
        atual = atual->prox_vei;
    }

    anterior->prox_vei = novo_vei;
    novo_vei->prox_vei = atual;
}

Veiculo* carregarListaVeiculos() 
{
    FILE* fp = fopen("veiculo.dat", "rb");
    if (!fp) return NULL;

    Veiculo temp;
    Veiculo* lista = NULL;

    while (fread(&temp, sizeof(Veiculo), 1, fp)) {
        if (temp.status == true) {
            Veiculo* novo_vei = malloc(sizeof(Veiculo));
            *novo_vei = temp;
            novo_vei->prox_vei = NULL;
            listaOrdenadaVeiculos(&lista, novo_vei);
        }
    }

    fclose(fp);
    return lista;
}

Veiculo* buscarVeiculo(Veiculo* lista_veiculo, const char* placa) {
    Veiculo* aux = lista_veiculo;
    while (aux) {
        if (aux->status && strcmp(aux->placa_veiculo, placa) == 0) {
            return aux;
        }
        aux = aux->prox_vei;
    }
    return NULL;
}

void salvarListaVeiculos(Veiculo* lista_veiculo) 
{
    FILE* fp = fopen("veiculo.dat", "wb");
    if (!fp) return;

    Veiculo* aux = lista_veiculo;
    while (aux != NULL) {
        fwrite(aux, sizeof(Veiculo), 1, fp);
        aux = aux->prox_vei;
    }

    fclose(fp);
}

void limparListaVeiculos(Veiculo* lista_veiculo) 
{
    Veiculo* aux;
    while (lista_veiculo != NULL) {
        aux = lista_veiculo->prox_vei;
        free(lista_veiculo);
        lista_veiculo = aux;
    }
}

// |===================================|
// |    FUNÇÕES VEÍCULOS - CRUD        |
// |===================================|

void modulo_cadastrar_veiculo(void) {
    system("clear||cls");

    Veiculo *novo_vei = malloc(sizeof(Veiculo));
    if (!novo_vei) return;

    printf("#=====================================================================#\n");
    printf("|                         --------------------                        |\n");
    printf("|                         | SIG - Rent a Car |                        |\n");
    printf("|                         --------------------                        |\n");
    printf("#=====================================================================#\n");
    printf("|                        CADASTRAR VEÍCULOS                           |\n");
    printf("#=====================================================================#\n");

    lerEntrada(novo_vei->placa_veiculo, 8, "[+] - Placa: ", validarPlaca);
    lerEntrada(novo_vei->chassi_veiculo, 18, "[+] - Chassi: ", validarChassi);
    lerEntrada(novo_vei->renavam_veiculo, 12, "[+] - Renavam: ", validarRenavam);
    lerEntrada(novo_vei->categoria_veiculo, 7, "[+] - Categoria: ", validarCategoria);
    lerEntrada(novo_vei->modelo_veiculo, 31, "[+] - Modelo: ", validarModelo);
    lerEntrada(novo_vei->marca_veiculo, 16, "[+] - Marca: ", validarMarca);
    lerEntrada(novo_vei->ano_veiculo, 5, "[+] - Ano: ", validarAno);
    lerEntrada(novo_vei->codigo_interno_veiculo, 7, "[+] - Código interno: ", validarCodigoInterno);

    printf("[+] - Preço: ");
    scanf("%f", &novo_vei->preco_veiculo);
    getchar();

    novo_vei->status = true;
    novo_vei->prox_vei = NULL;

    Veiculo* lista = carregarListaVeiculos();

    listaOrdenadaVeiculos(&lista, novo_vei);

    salvarListaVeiculos(lista);

    limparListaVeiculos(lista);

    printf("#=====================================================================#\n");
    printf("[o] - Veículo Registrado com Sucesso!\n");
    printf("[>] - Pressione Enter para continuar...");
    getchar();
}

void modulo_verificar_veiculo(void)
{
    system("clear||cls");

    char codigo_ler[7];

    printf("#=====================================================================#\n");
    printf("|                         --------------------                        |\n");
    printf("|                         | SIG - Rent a Car |                        |\n");
    printf("|                         --------------------                        |\n");
    printf("#=====================================================================#\n");
    printf("|                          VERIFICAR VEÍCULO                          |\n");
    printf("#=====================================================================#\n");

    printf("[>] - Informe o Código interno do veículo: ");
    scanf("%6s", codigo_ler);
    while (getchar() != '\n');

    Veiculo* lista = carregarListaVeiculos();
    Veiculo* aux_vei = lista;

    while (aux_vei != NULL) {
        if (aux_vei->status == true && strcmp(aux_vei->codigo_interno_veiculo, codigo_ler) == 0) {
            system("clear||cls");

            printf("#====================================================#\n");
            printf("|                [o] - Veículo encontrado!           |\n");
            printf("#====================================================#\n");
            printf("| > Placa: %s\n", aux_vei->placa_veiculo);
            printf("| > Chassi: %s\n", aux_vei->chassi_veiculo);
            printf("| > Renavam: %s\n", aux_vei->renavam_veiculo);
            printf("| > Categoria: %s\n", aux_vei->categoria_veiculo);
            printf("| > Modelo: %s\n", aux_vei->modelo_veiculo);
            printf("| > Marca: %s\n", aux_vei->marca_veiculo);
            printf("| > Ano: %s\n", aux_vei->ano_veiculo);
            printf("| > Código Interno: %s\n", aux_vei->codigo_interno_veiculo);
            printf("| > Preço: %.2f\n", aux_vei->preco_veiculo);
            printf("#====================================================#\n");
            printf("[>] - Pressione Enter para continuar...");
            getchar();

            limparListaVeiculos(lista);
            return;
        }
        aux_vei = aux_vei->prox_vei;
    }

    limparListaVeiculos(lista);

    printf("#=====================================================================#\n");
    printf("\nXXX - Veículo não encontrado!\n");
    printf("[>] - Pressione Enter para continuar...");
    getchar();
}

void modulo_atualizar_veiculo(void)
{
    Veiculo* lista = carregarListaVeiculos();
    if (!lista) {
        printf("XXX - Nenhum veículo cadastrado!\n");
        printf("[>] - Pressione Enter para continuar...");
        getchar();
        return;
    }

    char cod_veiculo_ler[7];
    char op_veiculo;
    int c;

    system("clear||cls");
    printf("\n");
    printf("#=====================================================================#\n");
    printf("|                         --------------------                        |\n");
    printf("|                         | SIG - Rent a Car |                        |\n");
    printf("|                         --------------------                        |\n");
    printf("#=====================================================================#\n");
    printf("|                         ATUALIZAR VEÍCULOS                          |\n");
    printf("#=====================================================================#\n");
    printf("[>] - Informe o código interno do veículo: ");
    scanf("%7s", cod_veiculo_ler);
    while ((c = getchar()) != '\n' && c != EOF);

    Veiculo* vei = buscarVeiculo(lista, cod_veiculo_ler);

    if (!vei) {
        printf("XXX - Veículo não encontrado!\n");
        printf("[>] - Pressione Enter para continuar...");
        getchar();
        limparListaVeiculos(lista);
        return;
    }

    system("clear||cls");
    printf("#====================================================#\n");
    printf("|               [o] - Veículo encontrado!            |\n");
    printf("#====================================================#\n");
    printf("|               [1] - Placa                          |\n");
    printf("|               [2] - Chassi                         |\n");
    printf("|               [3] - Renavam                        |\n");
    printf("|               [4] - Categoria                      |\n");
    printf("|               [5] - Modelo                         |\n");
    printf("|               [6] - Marca                          |\n");
    printf("|               [7] - Ano                            |\n");
    printf("|               [8] - Código Interno                 |\n");
    printf("|               [9] - Preço                          |\n");
    printf("|----------------------------------------------------|\n");
    printf("|               [0] - Cancelar                       |\n");
    printf("#====================================================#\n");
    printf("[>] - Informe qual informação deseja alterar: ");
    scanf(" %c", &op_veiculo);
    while ((c = getchar()) != '\n' && c != EOF);

    int alt = 0;

    switch(op_veiculo) {

        case '1':
            atualizarEntrada("[+] - Nova placa: ", vei->placa_veiculo, 8, validarPlaca);
            alt = 1;
            break;

        case '2':
            atualizarEntrada("[+] - Novo número de chassi: ", vei->chassi_veiculo, 18, validarChassi);
            alt = 1;
            break;

        case '3':
            atualizarEntrada("[+] - Novo Renavam: ", vei->renavam_veiculo, 12, validarRenavam);
            alt = 1;
            break;

        case '4':
            atualizarEntrada("[+] - Nova categoria: ", vei->categoria_veiculo, 7, validarCategoria);
            alt = 1;
            break;

        case '5':
            atualizarEntrada("[+] - Novo modelo: ", vei->modelo_veiculo, 31, validarModelo);
            alt = 1;
            break;

        case '6':
            atualizarEntrada("[+] - Nova marca: ", vei->marca_veiculo, 16, validarMarca);
            alt = 1;
            break;

        case '7':
            atualizarEntrada("[+] - Novo ano (AAAA): ", vei->ano_veiculo, 5, validarAno);
            alt = 1;
            break;

        case '8':
            atualizarEntrada("[+] - Novo código interno: ", vei->codigo_interno_veiculo, 7, validarCodigoInterno);
            alt = 1;
            break;

        case '9': {
            float preco;
            printf("[+] - Novo preço: ");
            scanf("%f", &preco);
            vei->preco_veiculo = preco;
            getchar();
            alt = 1;
            break;
        }

        case '0':
            printf("Voltando ao menu...\n");
            break;

        default:
            printf("XXX - Opção inválida!\n");
            break;
    }

    if (alt) {
        salvarListaVeiculos(lista);
        printf("#====================================================#\n");
        printf("[o] - Dado(s) alterado(s) com sucesso!\n");
    }

    limparListaVeiculos(lista);
    printf("[>] - Pressione Enter para continuar...");
    getchar();
}

void modulo_excluir_veiculo(void)
{
    Veiculo* lista_veiculo = carregarListaVeiculos();
    if (!lista_veiculo) {
        printf("XXX - Nenhum veículo cadastrado!\n");
        printf("[>] - Pressione ENTER para continuar...");
        getchar();
        return;
    }

    char codinterno_ler[7];
    int c;
    bool vei_encontrado = false;
    char confirmar;

    system("clear||cls");
    printf("\n");
    printf("#=====================================================================#\n");
    printf("|                        --------------------                         |\n");
    printf("|                        | SIG - Rent a Car |                         |\n");
    printf("|                        --------------------                         |\n");
    printf("#=====================================================================#\n");
    printf("|                          EXCLUIR VEÍCULOS                           |\n");
    printf("#=====================================================================#\n");
    printf("\n");

    printf("[>] - Informe o Código Interno do veículo que deseja excluir: ");
    scanf("%6s", codinterno_ler);
    while ((c = getchar()) != '\n' && c != EOF);

    Veiculo* atual_vei = lista_veiculo;

    while (atual_vei) {
        if (strcmp(atual_vei->codigo_interno_veiculo, codinterno_ler) == 0 && atual_vei->status) {
            vei_encontrado = true;

            system("clear||cls");
            printf("#====================================================#\n");
            printf("|               [o] - Veículo encontrado!            |\n");
            printf("#====================================================#\n");
            printf("| > Placa: %s\n", atual_vei->placa_veiculo);
            printf("| > Chassi: %s\n", atual_vei->chassi_veiculo);
            printf("| > Renavam: %s\n", atual_vei->renavam_veiculo);
            printf("| > Modelo: %s\n", atual_vei->modelo_veiculo);
            printf("| > Marca: %s\n", atual_vei->marca_veiculo);
            printf("| > Categoria: %s\n", atual_vei->categoria_veiculo);
            printf("| > Ano: %s\n", atual_vei->ano_veiculo);
            printf("| > Código Interno: %s\n", atual_vei->codigo_interno_veiculo);
            printf("| > Preço: %.2f\n", atual_vei->preco_veiculo);
            printf("#====================================================#\n");
            printf("[?] - Deseja realmente excluir este veículo? (S/N): ");
            scanf(" %c", &confirmar);
            while ((c = getchar()) != '\n' && c != EOF);

            if (confirmar == 'S' || confirmar == 's') {
                atual_vei->status = false;
                salvarListaVeiculos(lista_veiculo);
                printf("#====================================================#\n");
                printf("[o] - Veículo excluído com sucesso!\n");
            } 
            else {
                printf("\n[o] - Exclusão cancelada.\n");
            }

            break;
        }
        atual_vei = atual_vei->prox_vei;
    }

    if (!vei_encontrado) {
        printf("XXX - Veículo não encontrado...\n");
    }

    limparListaVeiculos(lista_veiculo);

    printf("\n[>] - Pressione Enter para continuar...");
    getchar();
}
