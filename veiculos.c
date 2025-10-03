#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include "veiculos.h"

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
    printf("Escolha uma das opções acima: \n");
    scanf(" %d", &op);
    while ((c = getchar()) != '\n' && c != EOF)
        ;
    return op;
}

void modulo_cadastrar_veiculo(void)
{
    FILE *arq_veiculo;
    char placa[8];
    char chassi[18];
    char renavam[12];
    char categoria[7];
    char modelo[31];
    char marca[16];
    char ano[5];
    char codigo_interno[7];
    float preco;
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
    printf("|                T ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ T             |\n\n");

    printf("Placa do veículo: ");
    scanf("%7[A-Z0-9]", placa);
    while ((c = getchar()) != '\n' && c != EOF)
        ;

    printf("Chassi do veículo: ");
    scanf("%17[A-HJ-NP-Z0-9]", chassi);
    while ((c = getchar()) != '\n' && c != EOF)
        ;

    printf("Renavam do veículo: ");
    scanf("%11[0-9]", renavam);
    while ((c = getchar()) != '\n' && c != EOF)
        ;

    printf("Categoria do veículo: ");
    scanf("%6[A-Z]", categoria);
    while ((c = getchar()) != '\n' && c != EOF)
        ;

    printf("Modelo do veículo: ");
    scanf("%30[A-Za-z0-9 ]", modelo);
    while ((c = getchar()) != '\n' && c != EOF)
        ;

    printf("Marca do veículo: ");
    scanf("%15[A-Za-z ]", marca);
    while ((c = getchar()) != '\n' && c != EOF)
        ;

    printf("Ano do veículo: ");
    scanf("%4[0-9]", ano);
    while ((c = getchar()) != '\n' && c != EOF)
        ;

    printf("Código do veículo: ");
    scanf("%6[A-Z0-9]", codigo_interno);
    while ((c = getchar()) != '\n' && c != EOF)
        ;

    printf("Preço do veículo: ");
    scanf("%f", &preco);
    while ((c = getchar()) != '\n' && c != EOF)
        ;

    arq_veiculo = fopen("veiculo.csv", "at");

    if (arq_veiculo == NULL)
    {
        printf("Erro na criação do arquivo!");
        printf("Pressione Enter para continuar...");
        getchar();
        exit(1);
    }

    fprintf(arq_veiculo, "%s;", placa);
    fprintf(arq_veiculo, "%s;", chassi);
    fprintf(arq_veiculo, "%s;", renavam);
    fprintf(arq_veiculo, "%s;", categoria);
    fprintf(arq_veiculo, "%s;", modelo);
    fprintf(arq_veiculo, "%s;", marca);
    fprintf(arq_veiculo, "%s;", ano);
    fprintf(arq_veiculo, "%s;", codigo_interno);
    fprintf(arq_veiculo, "%f\n", preco);
    fclose(arq_veiculo);

    printf("Veículo Registrado com Sucesso!\n");
    printf("Pressione Enter para continuar...");
    getchar();
}

void modulo_dados_veiculo(void)
{
    FILE *arq_veiculo;
    arq_veiculo = fopen("veiculo.csv","rt");

    if (arq_veiculo == NULL){
        printf("Erro na criação do arquivo!");
        printf("Pressione Enter para continuar...");
        getchar();
        exit(1);
    }

    char cod_ler[7];
    char placa[8];
    char chassi[18];
    char renavam[12];
    char categoria[7];
    char modelo[31];
    char marca[16];
    char ano[5];
    char codigo_interno[7];
    float preco;
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
    printf("Informe o Código interno para encontrar o veículo desejado: \n");
    scanf("%7s", cod_ler);
    while ((c = getchar()) != '\n' && c != EOF)
        ;
    while (fscanf(arq_veiculo, "%[^;];%[^;];%[^;];%[^;];%[^;];%[^;];%[^;];%[^;];%f\n", placa, chassi, renavam, categoria, modelo, marca, ano, codigo_interno, &preco) == 9) {

        if (strcmp(cod_ler, codigo_interno) == 0) {
            printf("\t\t T ~~~~~~~~~~~~~~~~~~~~~~~~~~~ T\n");
            printf("\t\t < = = Veículo Encontrado! = = >\n");
            printf("\t\t T ~~~~~~~~~~~~~~~~~~~~~~~~~~~ T\n");
            printf("\t\t Placa: %s\n", placa);
            printf("\t\t Chassi: %s\n", chassi);
            printf("\t\t Renavam.: %s\n", renavam);
            printf("\t\t Categoria: %s\n", categoria);
            printf("\t\t Modelo: %s\n", modelo);
            printf("\t\t Marca: %s\n", marca);
            printf("\t\t Ano: %s\n", ano);
            printf("\t\t Código Interno: %s\n", codigo_interno);
            printf("\t\t Preço: %f\n", preco);
            printf("\n");
            printf("\t\t Pressione Enter para continuar...");
            getchar();
            fclose(arq_veiculo);
            return;
        }
    }
    printf("Veículo não encontrado!\n");
    printf("Pressione Enter para continuar...");
    getchar();
    fclose(arq_veiculo);
}

void modulo_atualizar_veiculo(void)
{
    FILE *arq_veiculo;
    arq_veiculo = fopen("veiculo.csv","rt");

    if (arq_veiculo == NULL){
        printf("Erro ao entrar no arquivo!");
        printf("Pressione Enter para continuar...");
        getchar();
        exit(1);
    }

    FILE *arq_veiculo_temp;
    arq_veiculo_temp = fopen("veiculo_temp.csv","wt");

    if (arq_veiculo_temp== NULL){
        printf("Erro na criação do arquivo Temporário!\n");
        printf("Pressione Enter para continuar...");
        getchar();
        exit(1);
    }

    char cod_ler[7];
    char placa[8];
    char chassi[18];
    char renavam[12];
    char categoria[7];
    char modelo[31];
    char marca[16];
    char ano[5];
    char codigo_interno[7];
    char op_veiculo;
    float preco;
    int c;
    int veiculo_encontrado = 0;

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
    printf("Informe o Código da RENAVAM para encontrar o veículo e atualizar seus dados: \n");
    scanf("%s", cod_ler);
    while ((c = getchar()) != '\n' && c != EOF)
        ;
    while(fscanf(arq_veiculo, "%[^;];%[^;];%[^;];%[^;];%[^;];%[^;]%[^;]%[^;];%f\n", placa, chassi, renavam, categoria, modelo, marca, ano, codigo_interno, &preco) == 9){
        if (strcmp(cod_ler, codigo_interno) == 0) {
    
            veiculo_encontrado = 1;

            system("clear||cls");
            printf("Veículo encontrado!\n");
            printf("Informe qual informação deseja alterar:\n");
            printf("\n");
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
            printf("-----------------------\n");
            scanf(" %c", &op_veiculo);
            while ((c = getchar()) != '\n' && c != EOF)
                ;
            
            switch(op_veiculo){
                case '1':
                    printf("Nova placa: ");
                    scanf("%7[A-Z0-9]", placa);
                    while ((c = getchar()) != '\n' && c != EOF)
                        ;
                    break;

                case '2':
                    printf("Novo chassi: ");
                    scanf("%17[A-HJ-NP-Z0-9]", chassi);
                    while ((c = getchar()) != '\n' && c != EOF)
                        ;
                    break;

                case '3':
                    printf("Novo Renavam: ");
                    scanf("%11[0-9]", renavam);
                    while ((c = getchar()) != '\n' && c != EOF)
                        ;
                    break;
                
                case '4':
                    printf("Nova categoria: ");
                    scanf("%6[A-Z]", categoria);
                    while ((c = getchar()) != '\n' && c != EOF)
                        ;
                    break;

                case '5':
                    printf("Novo modelo: ");
                    scanf("%30[A-Za-z0-9 ]", modelo);
                    while ((c = getchar()) != '\n' && c != EOF)
                        ;
                    break;

                case '6':
                    printf("Nova marca: ");
                    scanf("%15[A-Za-z ]", marca);
                    while ((c = getchar()) != '\n' && c != EOF)
                        ;
                    break;

                case '7':
                    printf("Novo ano: ");
                    scanf("%4[0-9]", ano);
                    while ((c = getchar()) != '\n' && c != EOF)
                        ;
                    break;

                case '8':
                    printf("Novo código_interno: ");
                    scanf("%6[A-Z0-9]", codigo_interno);
                    while ((c = getchar()) != '\n' && c != EOF)
                        ;
                    break;

                case '9':
                    printf("Novo preço: ");
                    scanf("%f", &preco);
                    while ((c = getchar()) != '\n' && c != EOF)
                        ;
                    break;

                case '0':
                    printf("Voltando ao menu veículos.");
                    break;
                
                default:
                    printf("Opção inválida. Nenhum dado alterado!\n");
                    break;
            }
    
        }

        fprintf(arq_veiculo, "%s;", placa);
        fprintf(arq_veiculo, "%s;", chassi);
        fprintf(arq_veiculo, "%s;", renavam);
        fprintf(arq_veiculo, "%s;", categoria);
        fprintf(arq_veiculo, "%s;", modelo);
        fprintf(arq_veiculo, "%s;", marca);
        fprintf(arq_veiculo, "%s;", ano);
        fprintf(arq_veiculo, "%s;", codigo_interno);
        fprintf(arq_veiculo, "%f\n", preco);

    }

    fclose(arq_veiculo);
    fclose(arq_veiculo_temp);

    if (veiculo_encontrado){
            remove("veiculo.csv");
            rename("veiculo_temp.csv","veiculo.csv");
            printf("Dado(s) do veículo alterado(s) com sucesso!\n");
        }
    else {
        remove("veiculo_temp.csv");
        printf("Veículo não encontrado..\n");
    }

    printf("Pressione Enter para continuar...");
    getchar();
}

void modulo_excluir_veiculo(void)
{
    FILE *arq_veiculo;
    arq_veiculo = fopen("veiculo.csv","rt");

    if (arq_veiculo== NULL){
        printf("Erro na criação do arquivo Temporário!\n");
        printf("Pressione Enter para continuar...");
        getchar();
        exit(1);
    }

    FILE *arq_veiculo_temp;
    arq_veiculo_temp = fopen("veiculo_temp.csv","wt");

    if (arq_veiculo_temp== NULL){
        printf("Erro na criação do arquivo Temporário!\n");
        printf("Pressione Enter para continuar...");
        getchar();
        exit(1);
    }

    char cod_ler[7];
    char placa[8];
    char chassi[18];
    char renavam[12];
    char categoria[7];
    char modelo[31];
    char marca[16];
    char ano[5];
    char codigo_interno[7];
    float preco;
    int c;
    int veiculo_encontrado = 0;

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
    printf("Informe o Código Interno  para encontrar o veículo que deseja excluir: \n");
    scanf("%7s", cod_ler);
    while ((c = getchar()) != '\n' && c != EOF)
        ;
    while (fscanf(arq_veiculo, "%[^;];%[^;];%[^;];%[^;];%[^;];%[^;];%[^;];%[^;];%f\n", placa, chassi, renavam, categoria, modelo, marca, ano, codigo_interno, &preco) == 9) {
    
        if (strcmp(codigo_interno, cod_ler) == 0){

            fprintf(arq_veiculo_temp,"%s;", placa);
            fprintf(arq_veiculo_temp,"%s;", chassi);
            fprintf(arq_veiculo_temp,"%s;", renavam);
            fprintf(arq_veiculo_temp,"%s;", categoria);
            fprintf(arq_veiculo_temp,"%s;", modelo);
            fprintf(arq_veiculo_temp,"%s;", marca);
            fprintf(arq_veiculo_temp,"%s;", ano);
            fprintf(arq_veiculo_temp,"%s;", codigo_interno);
            fprintf(arq_veiculo_temp,"%f\n", preco);

        }
        else {
            veiculo_encontrado = 1;
        }
    }

    fclose(arq_veiculo);
    fclose(arq_veiculo_temp);

    if (veiculo_encontrado){
            remove("veiculo.csv");
            rename("veiculo_temp.csv","veiculo.csv");
            printf("Veículo excluído com sucesso!\n");
        }
    else {
        remove("veiculo_temp.csv");
        printf("Veículo não encontrado...\n");
    }

    printf("Pressione Enter para continuar...");
    getchar();

}