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
    Veiculo vcl;
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
    scanf("%7[A-Z0-9]", vcl.placa);
    while ((c = getchar()) != '\n' && c != EOF)
        ;

    printf("Chassi do veículo: ");
    scanf("%17[A-HJ-NP-Z0-9]", vcl.chassi);
    while ((c = getchar()) != '\n' && c != EOF)
        ;

    printf("Renavam do veículo: ");
    scanf("%11[0-9]", vcl.renavam);
    while ((c = getchar()) != '\n' && c != EOF)
        ;

    printf("Categoria do veículo: ");
    scanf("%6[A-Z]", vcl.categoria);
    while ((c = getchar()) != '\n' && c != EOF)
        ;

    printf("Modelo do veículo: ");
    scanf("%30[A-Za-z0-9 ]", vcl.modelo);
    while ((c = getchar()) != '\n' && c != EOF)
        ;

    printf("Marca do veículo: ");
    scanf("%15[A-Za-z ]", vcl.marca);
    while ((c = getchar()) != '\n' && c != EOF)
        ;

    printf("Ano do veículo: ");
    scanf("%4[0-9]", vcl.ano);
    while ((c = getchar()) != '\n' && c != EOF)
        ;

    printf("Código do veículo: ");
    scanf("%6[A-Z0-9]", vcl.codigo_interno);
    while ((c = getchar()) != '\n' && c != EOF)
        ;

    printf("Preço do veículo: ");
    scanf("%f", &vcl.preco);
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

    fprintf(arq_veiculo, "%s;", vcl.placa);
    fprintf(arq_veiculo, "%s;", vcl.chassi);
    fprintf(arq_veiculo, "%s;", vcl.renavam);
    fprintf(arq_veiculo, "%s;", vcl.categoria);
    fprintf(arq_veiculo, "%s;", vcl.modelo);
    fprintf(arq_veiculo, "%s;", vcl.marca);
    fprintf(arq_veiculo, "%s;", vcl.ano);
    fprintf(arq_veiculo, "%s;", vcl.codigo_interno);
    fprintf(arq_veiculo, "%f\n", vcl.preco);
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
        printf("Erro ao abrir o arquivo!");
        printf("Pressione Enter para continuar...");
        getchar();
        exit(1);
    }

    char cod_ler[7];
    Veiculo vcl;
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
    while (fscanf(arq_veiculo, "%[^;];%[^;];%[^;];%[^;];%[^;];%[^;];%[^;];%[^;];%f\n", vcl.placa, vcl.chassi, vcl.renavam, vcl.categoria, vcl.modelo, vcl.marca, vcl.ano, vcl.codigo_interno, &vcl.preco) == 9) {

        if (strcmp(cod_ler, vcl.codigo_interno) == 0) {
            printf("\t\t T ~~~~~~~~~~~~~~~~~~~~~~~~~~~ T\n");
            printf("\t\t < = = Veículo Encontrado! = = >\n");
            printf("\t\t T ~~~~~~~~~~~~~~~~~~~~~~~~~~~ T\n");
            printf("\t\t Placa: %s\n", vcl.placa);
            printf("\t\t Chassi: %s\n", vcl.chassi);
            printf("\t\t Renavam.: %s\n", vcl.renavam);
            printf("\t\t Categoria: %s\n", vcl.categoria);
            printf("\t\t Modelo: %s\n", vcl.modelo);
            printf("\t\t Marca: %s\n", vcl.marca);
            printf("\t\t Ano: %s\n", vcl.ano);
            printf("\t\t Código Interno: %s\n", vcl.codigo_interno);
            printf("\t\t Preço: %f\n", vcl.preco);
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
        printf("Erro ao abrir o arquivo!");
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
    Veiculo vcl;
    char op_veiculo;
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
    printf("Informe o Código Interno para encontrar o veículo e atualizar seus dados: \n");
    scanf("%7s", cod_ler);
    while ((c = getchar()) != '\n' && c != EOF)
        ;
    while(fscanf(arq_veiculo, "%[^;];%[^;];%[^;];%[^;];%[^;];%[^;];%[^;];%[^;];%f\n", vcl.placa, vcl.chassi, vcl.renavam, vcl.categoria, vcl.modelo, vcl.marca, vcl.ano, vcl.codigo_interno, &vcl.preco) == 9){
        if (strcmp(vcl.codigo_interno, cod_ler) == 0) {
    
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
                    scanf("%7[A-Z0-9]", vcl.placa);
                    while ((c = getchar()) != '\n' && c != EOF)
                        ;
                    break;

                case '2':
                    printf("Novo chassi: ");
                    scanf("%17[A-HJ-NP-Z0-9]", vcl.chassi);
                    while ((c = getchar()) != '\n' && c != EOF)
                        ;
                    break;

                case '3':
                    printf("Novo Renavam: ");
                    scanf("%11[0-9]", vcl.renavam);
                    while ((c = getchar()) != '\n' && c != EOF)
                        ;
                    break;
                
                case '4':
                    printf("Nova categoria: ");
                    scanf("%6[A-Z]", vcl.categoria);
                    while ((c = getchar()) != '\n' && c != EOF)
                        ;
                    break;

                case '5':
                    printf("Novo modelo: ");
                    scanf("%30[A-Za-z0-9 ]", vcl.modelo);
                    while ((c = getchar()) != '\n' && c != EOF)
                        ;
                    break;

                case '6':
                    printf("Nova marca: ");
                    scanf("%15[A-Za-z ]", vcl.marca);
                    while ((c = getchar()) != '\n' && c != EOF)
                        ;
                    break;

                case '7':
                    printf("Novo ano: ");
                    scanf("%4[0-9]", vcl.ano);
                    while ((c = getchar()) != '\n' && c != EOF)
                        ;
                    break;

                case '8':
                    printf("Novo código_interno: ");
                    scanf("%6[A-Z0-9]", vcl.codigo_interno);
                    while ((c = getchar()) != '\n' && c != EOF)
                        ;
                    break;

                case '9':
                    printf("Novo preço: ");
                    scanf("%f", &vcl.preco);
                    while ((c = getchar()) != '\n' && c != EOF)
                        ;
                    break;

                case '0':
                    printf("Voltando ao menu veículos.\n");
                    break;
                
                default:
                    printf("Opção inválida. Nenhum dado alterado!\n");
                    break;
            }
    
        }

        fprintf(arq_veiculo_temp, "%s;", vcl.placa);
        fprintf(arq_veiculo_temp, "%s;", vcl.chassi);
        fprintf(arq_veiculo_temp, "%s;", vcl.renavam);
        fprintf(arq_veiculo_temp, "%s;", vcl.categoria);
        fprintf(arq_veiculo_temp, "%s;", vcl.modelo);
        fprintf(arq_veiculo_temp, "%s;", vcl.marca);
        fprintf(arq_veiculo_temp, "%s;", vcl.ano);
        fprintf(arq_veiculo_temp, "%s;", vcl.codigo_interno);
        fprintf(arq_veiculo_temp, "%f\n", vcl.preco);

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
        printf("Erro ao abrir o arquivo!\n");
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
    Veiculo vcl;
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
    while (fscanf(arq_veiculo, "%[^;];%[^;];%[^;];%[^;];%[^;];%[^;];%[^;];%[^;];%f\n", vcl.placa, vcl.chassi, vcl.renavam, vcl.categoria, vcl.modelo, vcl.marca, vcl.ano, vcl.codigo_interno, &vcl.preco) == 9) {
    
        if (strcmp(vcl.codigo_interno, cod_ler) != 0){

            fprintf(arq_veiculo_temp,"%s;", vcl.placa);
            fprintf(arq_veiculo_temp,"%s;", vcl.chassi);
            fprintf(arq_veiculo_temp,"%s;", vcl.renavam);
            fprintf(arq_veiculo_temp,"%s;", vcl.categoria);
            fprintf(arq_veiculo_temp,"%s;", vcl.modelo);
            fprintf(arq_veiculo_temp,"%s;", vcl.marca);
            fprintf(arq_veiculo_temp,"%s;", vcl.ano);
            fprintf(arq_veiculo_temp,"%s;", vcl.codigo_interno);
            fprintf(arq_veiculo_temp,"%f\n", vcl.preco);

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