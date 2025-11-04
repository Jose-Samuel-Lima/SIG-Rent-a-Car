#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include "veiculos.h"
#include "validacao.h"

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
            modulo_dados_veiculo();
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

void modulo_cadastrar_veiculo(void)
{
    FILE *arq_veiculo;
    Veiculo* vei;
    vei = (Veiculo*) malloc(sizeof(Veiculo));
    int c;

    system("clear||cls");
    printf("\n");
    printf("#=====================================================================#\n");
    printf("|                        --------------------                         |\n");
    printf("|                        | SIG - Rent a Car |                         |\n");
    printf("|                        --------------------                         |\n");
    printf("#=====================================================================#\n");
    printf("|                T ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ T             |\n");
    printf("|                | < = = =  Cadastrar Veículos  = = = > |             |\n");
    printf("|                T ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ T             |\n");
    printf("#=====================================================================#\n\n");

    // EXEMPLO DE DADOS: ABC1234
    printf("[+] - Placa do veículo: ");
    scanf("%7[A-Z0-9]", vei->placa);
    while ((c = getchar()) != '\n' && c != EOF);
    
    while (!validarPlaca(vei->placa)) {
        printf("XXX - Placa inválida! Digite novamente: ");
        scanf("%7[A-Z0-9]", vei->placa);
        while ((c = getchar()) != '\n' && c != EOF);
    }

    // EXEMPLO DE DADOS: 9BWZZZ377VT004251
    printf("[+] - Chassi do veículo: ");
    scanf("%17[A-HJ-NP-Z0-9]", vei->chassi);
    while ((c = getchar()) != '\n' && c != EOF);

    while (!validarChassi(vei->chassi)) {
        printf("XXX - Chassi inválido! Digite novamente: ");
        scanf("%17[A-HJ-NP-Z0-9]", vei->chassi);
        while ((c = getchar()) != '\n' && c != EOF);
    }

    // EXEMPLO DE DADOS: 12345678901
    printf("[+] - Renavam do veículo: ");
    scanf("%11[0-9]", vei->renavam);
    while ((c = getchar()) != '\n' && c != EOF);

    while (!validarRenavam(vei->renavam)) {
        printf("XXX - Renavam inválido! Digite novamente: ");
        scanf("%11[0-9]", vei->renavam);
        while ((c = getchar()) != '\n' && c != EOF);
    }
    
    // EXEMPLO DE DADOS: SUV, SEDAN, HATCH, PICAPE
    printf("[+] - Categoria do veículo: ");
    scanf("%6[A-Z]", vei->categoria);
    while ((c = getchar()) != '\n' && c != EOF);

    while (!validarCategoria(vei->categoria)) {
        printf("XXX - Categoria inválida! Digite novamente: ");
        scanf("%6[A-Z]", vei->categoria);
        while ((c = getchar()) != '\n' && c != EOF);
    }
    
    // EXEMPLO DE DADOS: Onix LTZ 1.0 Turbo, Corolla XEi, HB20 Comfort
    printf("[+] - Modelo do veículo: ");
    scanf("%30[A-Za-z0-9 ]", vei->modelo);
    while ((c = getchar()) != '\n' && c != EOF);

    while (!validarModelo(vei->modelo)) {
        printf("XXX - Modelo inválido! Digite novamente: ");
        scanf("%30[A-Za-z0-9 ]", vei->modelo);
        while ((c = getchar()) != '\n' && c != EOF);
    }

    // EXEMPLO DE DADOS: Chevrolet, Toyota, Hyundai, Honda
    printf("[+] - Marca do veículo: ");
    scanf("%15[A-Za-z ]", vei->marca);
    while ((c = getchar()) != '\n' && c != EOF);

    while (!validarMarca(vei->marca)) {
        printf("XXX - Marca inválida! Digite novamente: ");
        scanf("%15[A-Za-z ]", vei->marca);
        while ((c = getchar()) != '\n' && c != EOF);
    }

    // EXEMPLO DE DADOS: 2020, 2024, 2015
    printf("[+] - Ano do veículo: ");
    scanf("%4[0-9]", vei->ano);
    while ((c = getchar()) != '\n' && c != EOF);

    while (!validarAno(vei->ano)) {
        printf("XXX - Ano inválido! Digite novamente (ex: 2024): ");
        scanf("%4[0-9]", vei->ano);
        while ((c = getchar()) != '\n' && c != EOF);
    }

    // EXEMPLO DE DADOS: CAR001, ABC123, VEI007
    printf("[+] - Código do veículo: ");
    scanf("%6[A-Z0-9]", vei->codigo_interno);
    while ((c = getchar()) != '\n' && c != EOF);
    
    while (!validarCodigoInterno(vei->codigo_interno)) {
        printf("XXX - Código inválido! Digite novamente: ");
        scanf("%6[A-Z0-9]", vei->codigo_interno);
        while ((c = getchar()) != '\n' && c != EOF);
    }

    // EXEMPLO DE DADOS: 98500.50, 75499.99, 120000
    printf("[+] - Preço do veículo: ");
    scanf("%f", &vei->preco);
    while ((c = getchar()) != '\n' && c != EOF);
    
    while (!validarPreco(vei->preco)) {
        printf("XXX - Preço inválido! Digite novamente: ");
        scanf("%f", &vei->preco);
        while ((c = getchar()) != '\n' && c != EOF);
    }

    vei->status = true;

    arq_veiculo = fopen("veiculo.dat", "ab");

    if (arq_veiculo == NULL)
    {
        printf("XXX - Erro na criação do arquivo!");
        printf("[>] - Pressione Enter para continuar...");
        getchar();
        exit(1);
    }

    fwrite(vei, sizeof(Veiculo), 1, arq_veiculo);

    fclose(arq_veiculo);
    free(vei);
    printf("----------------------------------------\n");
    printf("[o] - Veículo Registrado com Sucesso!\n");
    printf("[>] - Pressione Enter para continuar...");
    getchar();
}

void modulo_dados_veiculo(void)
{
    FILE *arq_veiculo;
    Veiculo* vei;
    vei = (Veiculo*) malloc(sizeof(Veiculo));
    arq_veiculo = fopen("veiculo.dat","rb");

    if (arq_veiculo == NULL){
        printf("XXX - Erro ao abrir o arquivo!");
        printf("[>] - Pressione Enter para continuar...");
        getchar();
        exit(1);
    }

    char cod_veiculo_ler[7];
    int c;

    system("cls||clear");
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
    printf("|                | < = = =  Dados dos Veículos  = = = > |             |\n");
    printf("|                T ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ T             |\n");
    printf("|                                                                     |\n");
    printf("#=====================================================================#\n");
    printf("\n");
    printf("[>] - Informe o Código interno para encontrar o veículo desejado: ");
    scanf("%7s", cod_veiculo_ler);
    while ((c = getchar()) != '\n' && c != EOF)
        ;
     while (fread(vei,sizeof(Veiculo),1,arq_veiculo)){

        if (strcmp(cod_veiculo_ler, vei->codigo_interno) == 0 && vei->status == true) {
            printf("--------------------------------\n");
            printf("T ~~~~~~~~~~~~~~~~~~~~~~~~~~~ T\n");
            printf("< = = Veículo Encontrado! = = >\n");
            printf("T ~~~~~~~~~~~~~~~~~~~~~~~~~~~ T\n");
            printf("Placa: %s\n", vei->placa);
            printf("Chassi: %s\n", vei->chassi);
            printf("Renavam.: %s\n", vei->renavam);
            printf("Categoria: %s\n", vei->categoria);
            printf("Modelo: %s\n", vei->modelo);
            printf("Marca: %s\n", vei->marca);
            printf("Ano: %s\n", vei->ano);
            printf("Código Interno: %s\n", vei->codigo_interno);
            printf("Preço: %f\n", vei->preco);
            printf("--------------------------------\n");
            printf("[>] - Pressione Enter para continuar...");
            getchar();
            return;
        }
    }

    fclose(arq_veiculo);
    free(vei);
    printf("XXX - Veículo não encontrado!\n");
    printf("[>] - Pressione Enter para continuar...");
    getchar();
}

void modulo_atualizar_veiculo(void)
{
    FILE *arq_veiculo;
    Veiculo* vei;
    vei = (Veiculo*) malloc(sizeof(Veiculo));
    arq_veiculo = fopen("veiculo.dat","r+b");

    if (arq_veiculo == NULL){
        printf("XXX - Erro ao abrir o arquivo!");
        printf("[>] - Pressione Enter para continuar...");
        getchar();
        exit(1);
    }

    char cod_veiculo_ler[7];
    char op_veiculo;
    int c;
    int veiculo_encontrado = false;

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
    printf("|                | < = = =  Atualizar os Dados  = = = > |             |\n");
    printf("|                | < = = =     dos Veículos     = = = > |             |\n");
    printf("|                T ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ T             |\n");
    printf("|                                                                     |\n");
    printf("#=====================================================================#\n");
    printf("\n");
    printf("[>] - Informe o Código Interno para encontrar o veículo e atualizar seus dados: ");
    scanf("%7s", cod_veiculo_ler);
    while ((c = getchar()) != '\n' && c != EOF)
        ;
    while ((fread(vei,sizeof(Veiculo),1,arq_veiculo) == 1)) {
        if (strcmp(vei->codigo_interno,cod_veiculo_ler) == 0 && vei->status) {
            
            veiculo_encontrado = true;
        
            system("clear||cls");
            printf("---------------------------\n");
            printf("[o] - Veículo encontrado!\n");
            printf("---------------------------\n");
            printf("[1] Nova Placa\n");
            printf("[2] Nova Chassi\n");
            printf("[3] Novo Código Renavam\n");
            printf("[4] Nova categoria\n");
            printf("[5] Novo modelo\n");
            printf("[6] Nova marca\n");
            printf("[7] Novo ano\n");
            printf("[8] Novo código_interno\n");
            printf("[9] Novo preço\n");
            printf("[0] Cancelar\n");
            printf("---------------------------\n");
            printf("[>] - Informe qual informação deseja alterar: ");
            scanf(" %c", &op_veiculo);
            while ((c = getchar()) != '\n' && c != EOF)
                ;

            int alt = 0;

            switch(op_veiculo){
                case '1':
                    printf("---------------------------\n");
                    printf("[+] - Nova placa: ");
                    scanf("%7[A-Z0-9]", vei->placa);
                    while ((c = getchar()) != '\n' && c != EOF);

                    while (!validarPlaca(vei->placa)) {
                        printf("XXX - Placa inválida! Digite novamente: ");
                        scanf("%7[A-Z0-9]", vei->placa);
                        while ((c = getchar()) != '\n' && c != EOF);
                    }
                    alt = 1;
                    break;

                case '2':
                    printf("---------------------------\n");
                    printf("[+] - Novo chassi: ");
                    scanf("%17[A-HJ-NP-Z0-9]", vei->chassi);
                    while ((c = getchar()) != '\n' && c != EOF);
                    
                    while (!validarChassi(vei->chassi)) {
                        printf("XXX - Chassi inválido! Digite novamente: ");
                        scanf("%17[A-HJ-NP-Z0-9]", vei->chassi);
                        while ((c = getchar()) != '\n' && c != EOF);
                    }
                    alt = 1;
                    break;

                case '3':
                    printf("---------------------------\n");
                    printf("[+] - Novo Renavam: ");
                    scanf("%11[0-9]", vei->renavam);
                    while ((c = getchar()) != '\n' && c != EOF);

                    while (!validarRenavam(vei->renavam)) {
                        printf("XXX - Renavam inválido! Digite novamente: ");
                        scanf("%11[0-9]", vei->renavam);
                        while ((c = getchar()) != '\n' && c != EOF);
                    }
                    alt = 1;
                    break;
                
                case '4':
                    printf("---------------------------\n");
                    printf("Nova categoria: ");
                    scanf("%6[A-Z]", vei->categoria);
                    while ((c = getchar()) != '\n' && c != EOF);
                    
                    while (!validarCategoria(vei->categoria)) {
                        printf("XXX - Categoria inválida! Digite novamente: ");
                        scanf("%6[A-Z]", vei->categoria);
                        while ((c = getchar()) != '\n' && c != EOF);
                    }
                    alt = 1;
                    break;

                case '5':  
                    printf("---------------------------\n");
                    printf("[+] - Novo modelo: ");
                    scanf("%30[A-Za-z0-9 ]", vei->modelo);
                    while ((c = getchar()) != '\n' && c != EOF);
                    
                    while (!validarModelo(vei->modelo)) {
                        printf("XXX - Modelo inválido! Digite novamente: ");
                        scanf("%30[A-Za-z0-9 ]", vei->modelo);
                        while ((c = getchar()) != '\n' && c != EOF);
                    }
                    alt = 1;
                    break;

                case '6':
                    printf("---------------------------\n");
                    printf("[+] - Nova marca: ");
                    scanf("%15[A-Za-z ]", vei->marca);
                    while ((c = getchar()) != '\n' && c != EOF);
                    
                    while (!validarMarca(vei->marca)) {
                        printf("XXX - Marca inválida! Digite novamente: ");
                        scanf("%15[A-Za-z ]", vei->marca);
                        while ((c = getchar()) != '\n' && c != EOF);
                    }
                    alt = 1;
                    break;

                case '7':
                    printf("---------------------------\n");
                    printf("[+] - Novo ano: ");
                    scanf("%4[0-9]", vei->ano);
                    while ((c = getchar()) != '\n' && c != EOF);
                    
                    while (!validarMarca(vei->marca)) {
                        printf("XXX - Marca inválida! Digite novamente: ");
                        scanf("%15[A-Za-z ]", vei->marca);
                        while ((c = getchar()) != '\n' && c != EOF);
                    }
                    alt = 1;
                    break;

                case '8':
                    printf("---------------------------\n");
                    printf("[+] - Novo código_interno: ");
                    scanf("%6[A-Z0-9]", vei->codigo_interno);
                    while ((c = getchar()) != '\n' && c != EOF);
                    
                    while (!validarCodigoInterno(vei->codigo_interno)) {
                        printf("XXX - Código inválido! Digite novamente: ");
                        scanf("%6[A-Z0-9]", vei->codigo_interno);
                        while ((c = getchar()) != '\n' && c != EOF);
                    }
                    alt = 1;
                    break;

                case '9':
                    printf("---------------------------\n");
                    printf("[+] - Novo preço: ");
                    scanf("%f", &vei->preco);
                    while ((c = getchar()) != '\n' && c != EOF);
                    
                    while (!validarPreco(vei->preco)) {
                        printf("XXX - Preço inválido! Digite novamente: ");
                        scanf("%f", &vei->preco);
                        while ((c = getchar()) != '\n' && c != EOF);
                    }
                    alt = 1;
                    break;

                case '0':
                    printf("Voltando ao menu veículos.\n");
                    break;
                
                default:
                    printf("XXX - Opção inválida. Nenhum dado alterado!\n");
                    break;
            }
            if (alt){
                fseek(arq_veiculo, -sizeof(Veiculo), SEEK_CUR);
                fwrite(vei, sizeof(Veiculo), 1,arq_veiculo);
                fflush(arq_veiculo);
                printf("[o] - Dado(s) alterado(s) com sucesso!\n");
            }

            break;
        }
    }

    if (!veiculo_encontrado){
        printf("XXX - Veículo não encontrado!\n"); 
    }

    fclose(arq_veiculo);
    free(vei);
    printf("[>] - Pressione Enter para continuar...");
    getchar();
}

void modulo_excluir_veiculo(void)
{
    FILE *arq_veiculo;
    Veiculo* vei;
    vei = (Veiculo*) malloc(sizeof(Veiculo));
    
    char cod_veiculo_ler[7];
    int c;
    bool veiculo_encontrado;

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
    printf("|             | < = = =  Excluir dados do Veículo  = = = > |          |\n");
    printf("|             T ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ T          |\n");
    printf("|                                                                     |\n");
    printf("#=====================================================================#\n");
    printf("\n");
    printf("[>] - Informe o Código Interno  para encontrar o veículo que deseja excluir: ");
    scanf("%7s", cod_veiculo_ler);
    while ((c = getchar()) != '\n' && c != EOF)
        ;
    
    veiculo_encontrado = false;

    arq_veiculo = fopen("veiculo.dat","r+b");

    if (arq_veiculo == NULL){
        printf("XXX - Erro ao entrar no arquivo!");
        printf("[>] - Pressione Enter para continuar...");
        getchar();
        exit(1);
    }

    while ((fread(vei,sizeof(Veiculo),1,arq_veiculo) == 1) && (!veiculo_encontrado)) {

        if (strcmp(vei->codigo_interno,cod_veiculo_ler) == 0){

            vei->status = false;
            fseek(arq_veiculo,(-1)*sizeof(Veiculo),SEEK_CUR);
            fwrite(vei, sizeof(Veiculo),1, arq_veiculo);
            veiculo_encontrado = true;

            printf("-----------------------------------\n");
            printf("[o] - Veículo excluído com sucesso!\n");
            break;
            }
        }
    fclose(arq_veiculo);
    free(vei);

    if (!veiculo_encontrado){
            printf("XXX - Veículo não encontrado...\n");
        }

    printf("[>] - Pressione Enter para continuar...");
    getchar();
    
}