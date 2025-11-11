#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <stdbool.h>
#include "funcionarios.h"
#include "relatorios.h"

int modulo_relatorio(void)
{
    int esc;
    do
    {
        esc = modulo_tela_relatorio();
        switch (esc)
        {
        case 1:
            navegar_relatorio_funcionarios();
            break;
        case 2:
            modulo_relatorio_clientes();
            break;
        case 3:
            modulo_relatorio_veiculos();
            break;
        case 4:
            modulo_relatorio_alugueis();
            break;
        case 0:
            return -1;
        }

    } while (esc != 0);
    return -1;
}

int navegar_relatorio_funcionarios(void)
{ 
    int esc_funcionario;
    do
    {
        esc_funcionario = modulo_relatorio_funcionarios();
        switch(esc_funcionario)
        {
        case 1: 
            funcionarios_ativos();
            break;
        case 0:
            return -1;
        }
    } while (esc_funcionario != 0);
    return -1;
}

int navegar_relatorio_clientes(void)
{ 
    int esc_cliente;
    do
    {
        esc_cliente = modulo_relatorio_funcionarios();
        switch(esc_cliente)
        {
        case 1: 
            funcionarios_ativos();
            break;
        case 0:
            return -1;
        }
    } while (esc_cliente != 0);
    return -1;
}

int modulo_tela_relatorio(void)
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
    printf("|                 < = = = Módulo de Relatórios = = = >                |\n");
    printf("|                                                                     |\n");
    printf("|                    # 1 # Relatório de funcionários                  |\n");
    printf("|                    # 2 # Relatório de clientes                      |\n");
    printf("|                    # 3 # Relatório de veículos                      |\n");
    printf("|                    # 4 # Relatório de aluguéis                      |\n");
    printf("|                    # 0 # Voltar ao menu principal                   |\n");
    printf("|                                                                     |\n");
    printf("#=====================================================================#\n");
    printf("\n");
    printf("Escolha uma das opções acima: \n");
    scanf(" %d", &op);
    while ((c = getchar()) != '\n' && c != EOF)
        ;
    printf("\n");
    printf("Processando...\n");
    // sleep(1);
    return op;
}

int modulo_relatorio_funcionarios(void)
{
    int op;
    int c;

    system("clear||cls");
    printf("\n");
    printf("#=======================================================================#\n");
    printf("|                                                                       |\n");
    printf("|                          --------------------                         |\n");
    printf("|                          | SIG - Rent a Car |                         |\n");
    printf("|                          --------------------                         |\n");
    printf("|                                                                       |\n");
    printf("#=======================================================================#\n");
    printf("|                                                                       |\n");
    printf("|              < = = =  Relatório de Funcionários = = = >               |\n");
    printf("|                                                                       |\n");
    printf("|                       # 1 # Funcionários_Ativos                       |\n");
    printf("|                       # 2 # Funcionários_Inativos                     |\n");
    printf("|                       # 0 # Sair                                      |\n");
    printf("|                                                                       |\n");
    printf("#=======================================================================#\n");
    printf("\n");
    printf("Escolha uma das opções acima: ");
    scanf(" %d", &op);
    while ((c = getchar()) != '\n' && c != EOF)
        ;
    printf("\n");
    printf("Processando...\n");
    return op;
}

void modulo_relatorio_clientes(void)
{
    system("clear||cls");
    printf("\n");
    printf("#=======================================================================#\n");
    printf("|                                                                       |\n");
    printf("|                          --------------------                         |\n");
    printf("|                          | SIG - Rent a Car |                         |\n");
    printf("|                          --------------------                         |\n");
    printf("|                                                                       |\n");
    printf("#=======================================================================#\n");
    printf("|                                                                       |\n");
    printf("|                < = = =  Relatório de Clientes = = = >                 |\n");
    printf("|                                                                       |\n");
    printf("|                       # 1 # Clientes_Ativos                           |\n");
    printf("|                       # 2 # Clientes_Inativos                         |\n");
    printf("|                       # 0 # Sair                                      |\n");
    printf("|                                                                       |\n");
    printf("#=======================================================================#\n");
    printf("\n");
    getchar();
    system("cls||clear");
    printf("Pressione Enter para continuar...");
    getchar();
}

void modulo_relatorio_veiculos(void)
{
    system("clear||cls");
    printf("\n");
    printf("#=======================================================================#\n");
    printf("|                                                                       |\n");
    printf("|                          --------------------                         |\n");
    printf("|                          | SIG - Rent a Car |                         |\n");
    printf("|                          --------------------                         |\n");
    printf("|                                                                       |\n");
    printf("#=======================================================================#\n");
    printf("|                                                                       |\n");
    printf("|                < = = =  Relatório de Veículos = = = >                 |\n");
    printf("|                                                                       |\n");
    printf("|                        # 1 # Relatório_Ativos                         |\n");
    printf("|                        # 2 # Relatório_Geral                          |\n");
    printf("|                                                                       |\n");
    printf("#=======================================================================#\n");
    printf("\n");
    getchar();
    system("cls||clear");
    printf("Pressione Enter para continuar...");
    getchar();
}

void modulo_relatorio_alugueis(void)
{
    system("clear||cls");
    printf("\n");
    printf("#=======================================================================#\n");
    printf("|                                                                       |\n");
    printf("|                          --------------------                         |\n");
    printf("|                          | SIG - Rent a Car |                         |\n");
    printf("|                          --------------------                         |\n");
    printf("|                                                                       |\n");
    printf("#=======================================================================#\n");
    printf("|                                                                       |\n");
    printf("|                 < = = =  Relatório de Alugueis  = = = >               |\n");
    printf("|                                                                       |\n");
    printf("|                        # 1 # Relatório_Ativos                         |\n");
    printf("|                        # 2 # Relatório_Geral                          |\n");
    printf("|                                                                       |\n");
    printf("#=======================================================================#\n");
    printf("\n");
    getchar();
    system("cls||clear");
    printf("Pressione Enter para continuar...");
    getchar();

}

void funcionarios_ativos(void)
{
    FILE *arq_funcionario;
    Funcionario* fun;
    fun = (Funcionario*) malloc(sizeof(Funcionario));
    arq_funcionario = fopen("funcionario.dat","rb");

    system("clear||cls");
    printf("\n");
    printf("#=======================================================================#\n");
    printf("|                                                                       |\n");
    printf("|                 < = = =  Funcionários Ativos = = = >                  |\n");
    printf("|                                                                       |\n");
    printf("#=======================================================================#\n");
    printf("\n");
    
    if (arq_funcionario == NULL) {
        printf("XXX - Nenhum arquivo de funcionários encontrado!\n");
        printf("[>] - Pressione Enter para continuar...");
        getchar();
        exit(1);
    }

    int contador = 0;

    while (fread(fun, sizeof(Funcionario), 1, arq_funcionario)) {
        if (fun->status == true) {
            contador++;
            printf("------------------------------------------------------------\n");
            printf("Funcionário #%d\n", contador);
            printf("Nome: %s\n", fun->nome_funcionario);
            printf("CPF: %s\n", fun->cpf_funcionario);
            printf("Data de Nascimento: %s\n", fun->dt_nascimento_fun);
            printf("Email: %s\n", fun->email_funcionario);
            printf("Cargo: %s\n", fun->cargo);
        }
    }

    if (contador == 0) {
        printf("XXX - Nenhum funcionário ativo encontrado!\n");
    } else {
        printf("------------------------------------------------------------\n");
        printf("Total de funcionários ativos: %d\n", contador);
    }

    fclose(arq_funcionario);
    free(fun);

    printf("\n[>] - Pressione Enter para continuar...");
    getchar();
}

