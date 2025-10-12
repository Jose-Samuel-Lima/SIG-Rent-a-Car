#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdbool.h>
#include "veiculos.h"

int modulo_veiculo(void)
{
    Veiculo* vei;
    vei = (Veiculo*) malloc(sizeof(Veiculo));
    int escVeiculo;
    do
    {
        escVeiculo = modulo_tela_veiculos();
        switch (escVeiculo)
        {
        case 1:
            modulo_cadastrar_veiculo(vei);
            break;
        case 2:
            modulo_dados_veiculo(vei);
            break;
        case 3:
            modulo_atualizar_veiculo(vei);
            break;
        case 4:
            modulo_excluir_veiculo(vei);
            break;
        case 0:
            return -1;
        }

    } while (escVeiculo != 0);
    
    free(vei);
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
    printf("Escolha uma das opções acima: \n");
    scanf(" %d", &op_veiculo);
    while ((c = getchar()) != '\n' && c != EOF)
        ;
    return op_veiculo;
}

void modulo_cadastrar_veiculo(Veiculo* vei)
{
    FILE *arq_veiculo;
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

    printf("Placa do veículo: ");
    scanf("%7[A-Z0-9]", vei->placa);
    while ((c = getchar()) != '\n' && c != EOF)
        ;

    printf("Chassi do veículo: ");
    scanf("%17[A-HJ-NP-Z0-9]", vei->chassi);
    while ((c = getchar()) != '\n' && c != EOF)
        ;

    printf("Renavam do veículo: ");
    scanf("%11[0-9]", vei->renavam);
    while ((c = getchar()) != '\n' && c != EOF)
        ;

    printf("Categoria do veículo: ");
    scanf("%6[A-Z]", vei->categoria);
    while ((c = getchar()) != '\n' && c != EOF)
        ;

    printf("Modelo do veículo: ");
    scanf("%30[A-Za-z0-9 ]", vei->modelo);
    while ((c = getchar()) != '\n' && c != EOF)
        ;

    printf("Marca do veículo: ");
    scanf("%15[A-Za-z ]", vei->marca);
    while ((c = getchar()) != '\n' && c != EOF)
        ;

    printf("Ano do veículo: ");
    scanf("%4[0-9]", vei->ano);
    while ((c = getchar()) != '\n' && c != EOF)
        ;

    printf("Código do veículo: ");
    scanf("%6[A-Z0-9]", vei->codigo_interno);
    while ((c = getchar()) != '\n' && c != EOF)
        ;

    printf("Preço do veículo: ");
    scanf("%f", &vei->preco);
    while ((c = getchar()) != '\n' && c != EOF)
        ;

    vei->status = true;

    arq_veiculo = fopen("veiculo.dat", "ab");

    if (arq_veiculo == NULL)
    {
        printf("Erro na criação do arquivo!");
        printf("Pressione Enter para continuar...");
        getchar();
        exit(1);
    }

    fwrite(vei, sizeof(Veiculo), 1, arq_veiculo);

    fclose(arq_veiculo);

    printf("Veículo Registrado com Sucesso!\n");
    printf("Pressione Enter para continuar...");
    getchar();
}

void modulo_dados_veiculo(Veiculo* vei)
{
    FILE *arq_veiculo;
    arq_veiculo = fopen("veiculo.dat","rb");

    if (arq_veiculo == NULL){
        printf("Erro ao abrir o arquivo!");
        printf("Pressione Enter para continuar...");
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
    printf("Informe o Código interno para encontrar o veículo desejado: \n");
    scanf("%7s", cod_veiculo_ler);
    while ((c = getchar()) != '\n' && c != EOF)
        ;
     while (fread(vei,sizeof(Veiculo),1,arq_veiculo)){

        if (strcmp(cod_veiculo_ler, vei->codigo_interno) == 0 && vei->status == true) {
            printf("\t\t T ~~~~~~~~~~~~~~~~~~~~~~~~~~~ T\n");
            printf("\t\t < = = Veículo Encontrado! = = >\n");
            printf("\t\t T ~~~~~~~~~~~~~~~~~~~~~~~~~~~ T\n");
            printf("\t\t Placa: %s\n", vei->placa);
            printf("\t\t Chassi: %s\n", vei->chassi);
            printf("\t\t Renavam.: %s\n", vei->renavam);
            printf("\t\t Categoria: %s\n", vei->categoria);
            printf("\t\t Modelo: %s\n", vei->modelo);
            printf("\t\t Marca: %s\n", vei->marca);
            printf("\t\t Ano: %s\n", vei->ano);
            printf("\t\t Código Interno: %s\n", vei->codigo_interno);
            printf("\t\t Preço: %f\n", vei->preco);
            printf("\n");
            printf("\t\t Pressione Enter para continuar...");
            getchar();
            return;
        }
    }

    fclose(arq_veiculo);
    printf("Veículo não encontrado!\n");
    printf("Pressione Enter para continuar...");
    getchar();
}

void modulo_atualizar_veiculo(Veiculo* vei)
{
    FILE *arq_veiculo;
    arq_veiculo = fopen("veiculo.dat","r+b");

    if (arq_veiculo == NULL){
        printf("Erro ao abrir o arquivo!");
        printf("Pressione Enter para continuar...");
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
    printf("Informe o Código Interno para encontrar o veículo e atualizar seus dados: \n");
    scanf("%7s", cod_veiculo_ler);
    while ((c = getchar()) != '\n' && c != EOF)
        ;
    while ((fread(vei,sizeof(Veiculo),1,arq_veiculo) == 1)) {
        if (strcmp(vei->codigo_interno,cod_veiculo_ler) == 0 && vei->status) {
            
            veiculo_encontrado = true;
        
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

            int alt = 0;

            switch(op_veiculo){
                case '1':
                    printf("Nova placa: ");
                    scanf("%7[A-Z0-9]", vei->placa);
                    while ((c = getchar()) != '\n' && c != EOF)
                        ;
                    alt = 1;
                    break;

                case '2':
                    printf("Novo chassi: ");
                    scanf("%17[A-HJ-NP-Z0-9]", vei->chassi);
                    while ((c = getchar()) != '\n' && c != EOF)
                        ;
                    alt = 1;
                    break;

                case '3':
                    printf("Novo Renavam: ");
                    scanf("%11[0-9]", vei->renavam);
                    while ((c = getchar()) != '\n' && c != EOF)
                        ;
                    alt = 1;
                    break;
                
                case '4':
                    printf("Nova categoria: ");
                    scanf("%6[A-Z]", vei->categoria);
                    while ((c = getchar()) != '\n' && c != EOF)
                        ;
                    alt = 1;
                    break;

                case '5':
                    printf("Novo modelo: ");
                    scanf("%30[A-Za-z0-9 ]", vei->modelo);
                    while ((c = getchar()) != '\n' && c != EOF)
                        ;
                    alt = 1;
                    break;

                case '6':
                    printf("Nova marca: ");
                    scanf("%15[A-Za-z ]", vei->marca);
                    while ((c = getchar()) != '\n' && c != EOF)
                        ;
                    alt = 1;
                    break;

                case '7':
                    printf("Novo ano: ");
                    scanf("%4[0-9]", vei->ano);
                    while ((c = getchar()) != '\n' && c != EOF)
                        ;
                    alt = 1;
                    break;

                case '8':
                    printf("Novo código_interno: ");
                    scanf("%6[A-Z0-9]", vei->codigo_interno);
                    while ((c = getchar()) != '\n' && c != EOF)
                        ;
                    alt = 1;
                    break;

                case '9':
                    printf("Novo preço: ");
                    scanf("%f", &vei->preco);
                    while ((c = getchar()) != '\n' && c != EOF)
                        ;
                    alt = 1;
                    break;

                case '0':
                    printf("Voltando ao menu veículos.\n");
                    break;
                
                default:
                    printf("Opção inválida. Nenhum dado alterado!\n");
                    break;
            }
            if (alt){
                fseek(arq_veiculo, -sizeof(Veiculo), SEEK_CUR);
                fwrite(vei, sizeof(Veiculo), 1,arq_veiculo);
                fflush(arq_veiculo);
                printf("Dado(s) alterado(s) com sucesso!\n");
            }

            break;
        }
    }

    if (!veiculo_encontrado){
        printf("Veículo não encontrado!\n"); 
    }

    fclose(arq_veiculo);
    printf("Pressione <Enter> para continuar...");
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
