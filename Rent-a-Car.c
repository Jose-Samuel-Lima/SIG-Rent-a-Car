#include <stdlib.h>
#include <stdio.h>
#include "clientes.h"
#include "veiculos.h"

// Assinatura das funções
void menu_principal(void);
void menu_sobre(void);
void modulo_equipe(void);

// Funções Aluguel
void modulo_alugueis(void);
void modulo_cadastrar_aluguel(void);
// void modulo_dados_aluguel(void);
// void modulo_alterar_aluguel(void);
// void modulo_finalizar_aluguel(void);

// Funções Funcionário
void modulo_funcionario(void);
void cadastrar_funcionario(void);
// void modulo_dados_funcionario(void);
void modulo_atualizar_funcionario(void);
// void modulo_excluir_funcionario(void);

// Funções Relatórios
void modulo_relatorios(void);
// void modulo_relatorio_clientes(void);
// void modulo_relatorio_veiculos(void);
// void modulo_relatorio_funcionarios(void);

void mensagem_manutencao(void);

// Programa principal
int main(void)
{
    char op;
    op = 'm';
    int ainda_roda;
    ainda_roda = 1;

    while (ainda_roda == 1)
    {
        if (op == 'm')
        {
            menu_principal();
            scanf("%c", &op);
            getchar();
        }
        else if (op == '1')
        {
            modulo_funcionario();
            scanf(" %c", &op);
            switch (op)
            {
            case '0':
                op = 'm';
                break;
            case '1':
                cadastrar_funcionario();
                break;
            case '2':
                mensagem_manutencao();
                break;
            case '3':
                modulo_atualizar_funcionario();
                break;
            case '4':
                mensagem_manutencao();
                break;
            }
            op = 'm';
        }
        else if (op == '2')
        {
            int resulCliente;
            resulCliente = modulo_cliente();
            if (resulCliente == -1)
            {
                op = 'm';
            }
            else
            {
                op = resulCliente;
            }
        }
        else if (op == '3')
        {
            int resulVeiculo;
            resulVeiculo = modulo_veiculo();
            if (resulVeiculo == -1)
            {
                op = 'm';
            }
            else
            {
                op = resulVeiculo;
            }
        }
        else if (op == '4')
        {
            modulo_alugueis();
            scanf(" %c", &op);
            switch (op)
            {
            case '0':
                op = 'm';
                break;
            case '1':
                modulo_cadastrar_aluguel();
                break;
            case '2':
                mensagem_manutencao();
                break;
            case '3':
                mensagem_manutencao();
                break;
            case '4':
                mensagem_manutencao();
                break;
            }
            op = 'm';
        }
        else if (op == '5')
        {
            modulo_relatorios();
            scanf(" %c", &op);
            switch (op)
            {
            case '0':
                op = 'm';
                break;
            case '1':
                mensagem_manutencao();
                break;
            case '2':
                mensagem_manutencao();
                break;
            case '3':
                mensagem_manutencao();
                break;
            case '4':
                mensagem_manutencao();
                break;
            case '5':
                mensagem_manutencao();
                break;
            }
            op = 'm';
        }
        else if (op == '6')
        {
            modulo_equipe();
            printf("Pressione Enter para voltar ao menu principal...");
            getchar();
            getchar();
            op = 'm';
        }
        else if (op == '7')
        {
            menu_sobre();
            printf("Pressione Enter para voltar ao menu principal...");
            getchar();
            getchar();
            op = 'm';
        }
        else if (op == '0')
        {
            ainda_roda = 0;
        }
    }

    printf("Programa Finalizado com sucesso! Agradecemos o seu tempo.\n\n\n");

    return 0;
}

void menu_principal(void)
{
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
    printf("|             Universidade Federal do Rio Grande do Norte             |\n");
    printf("|                 Centro de Ensino Superior do Seridó                 |\n");
    printf("|               Departamento de Computação e Tecnologia               |\n");
    printf("|                 Disciplina DCT1106 -- Programação                   |\n");
    printf("|        Projeto Sistema de Gestão para uma Locadora de Veículos      |\n");
    printf("|          Developed by @José-Samuel-Lima -- since Aug, 2025          |\n");
    printf("|                                                                     |\n");
    printf("#=====================================================================#\n");
    printf("|                                                                     |\n");
    printf("|                   < = = = Gestão Locadora = = = >                   |\n");
    printf("|                                                                     |\n");
    printf("|                    # 1 # Módulo Funcionários                        |\n");
    printf("|                    # 2 # Módulo Clientes                            |\n");
    printf("|                    # 3 # Módulo de Veículos                         |\n");
    printf("|                    # 4 # Módulo de Alugueis                         |\n");
    printf("|                    # 5 # Módulo Relatórios                          |\n");
    printf("|                    # 6 # Informações da Equipe                      |\n");
    printf("|                    # 7 # Sobre o Programa                           |\n");
    printf("|                    # 0 # Finalizar Programa                         |\n");
    printf("|                                                                     |\n");
    printf("|                   Escolha uma das opções...                         |\n");
    printf("|                                                                     |\n");
    printf("#=====================================================================#\n");
    printf("\n");
}

void menu_sobre(void)
{
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
    printf("|             Universidade Federal do Rio Grande do Norte             |\n");
    printf("|                 Centro de Ensino Superior do Seridó                 |\n");
    printf("|               Departamento de Computação e Tecnologia               |\n");
    printf("|                 Disciplina DCT1106 -- Programação                   |\n");
    printf("|        Projeto Sistema de Gestão para uma Locadora de Veículos      |\n");
    printf("|          Developed by @José-Samuel-Lima -- since Aug, 2025          |\n");
    printf("|                                                                     |\n");
    printf("#=====================================================================#\n");
    printf("|                                                                     |\n");
    printf("|       O sistema de gestão da locadora de veículos Rent a Car        |\n");
    printf("|   é um ferramenta desenvolvida para organizar e automatizar        |\n");
    printf("|   os processos administrativos e operacionais da empresa.           |\n");
    printf("|   Seu principal objetivo é facilitar o controle das atividades      |\n");
    printf("|   relacionadas à frota de veículos, aos clientes e às locações      |\n");
    printf("|   realizadas, garantindo maior eficiência, segurança e              |\n");
    printf("|   agilidade no atendimento.    a                                     |\n");
    printf("|                                                                     |\n");
    printf("#=====================================================================#\n");
    printf("\n");
}

void modulo_equipe(void)
{
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
    printf("|             Universidade Federal do Rio Grande do Norte             |\n");
    printf("|                 Centro de Ensino Superior do Seridó                 |\n");
    printf("|               Departamento de Computação e Tecnologia               |\n");
    printf("|                 Disciplina DCT1106 -- Programação                   |\n");
    printf("|        Projeto Sistema de Gestão para uma Locadora de Veículos      |\n");
    printf("|          Developed by @José-Samuel-Lima -- since Aug, 2025          |\n");
    printf("|                                                                     |\n");
    printf("#=====================================================================#\n");
    printf("|                                                                     |\n");
    printf("|        < = = = Sistema de Gestão Locadora de Veículos = = = >       |\n");
    printf("|                                                                     |\n");
    printf("|      Projeto de sistema de gestão para uma locadora de veículos     |\n");
    printf("|                                                                     |\n");
    printf("| Desenvolvedor(es): José Samuel Silva Lima & Icaro Nonato de Freitas |\n");
    printf("|      Email: jose.lima.146@ufrn.edu.br                               |\n");
    printf("|      Email: icaro.freitas.113@ufrn.edu.br                           |\n");
    printf("|      Git: https://github.com/Jose-Samuel-Lima/SIG-Rent-a-Car.git    |\n");
    printf("|                                                                     |\n");
    printf("#=====================================================================#\n");
    printf("\n");
}

void modulo_alugueis(void)
{
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
    printf("|                   Escolha uma das opções...                         |\n");
    printf("|                                                                     |\n");
    printf("#=====================================================================#\n");
    printf("\n");
}

void modulo_cadastrar_aluguel(void)
{
    char nome_cliente[51];
    char cpf_cliente[12];
    char codigo_renavam[12];
    // int id_aluguel;

    printf("Nome do cliente: ");
    getchar();
    fgets(nome_cliente, sizeof(nome_cliente), stdin);
    printf("CPF do cliente: ");
    getchar();
    fgets(cpf_cliente, sizeof(cpf_cliente), stdin);
    printf("Código RENAVAM do veículo alugado: ");
    getchar();
    fgets(codigo_renavam, sizeof(codigo_renavam), stdin);
    system("cls||clear");
    printf("Aluguel Registrado com Sucesso!\n");
    printf("Pressione Enter para continuar...");
    getchar();
}

void mensagem_manutencao(void)
{
    system("cls||clear");
    printf("Essa página não está disponível no momento. Aguarde futuras atualizações.\n");
    printf("Pressione Enter para continuar...");
    getchar();
    getchar();
}

void modulo_funcionario(void)
{
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
    printf("|                 < = = = Módulo de Funcionários = = = >              |\n");
    printf("|                                                                     |\n");
    printf("|                    # 1 # Cadastrar novo funcionário                 |\n");
    printf("|                    # 2 # Dados do funcionário                       |\n");
    printf("|                    # 3 # Alterar dados do funcionário               |\n");
    printf("|                    # 4 # Excluir um funcionário                     |\n");
    printf("|                    # 0 # Voltar ao menu principal                   |\n");
    printf("|                                                                     |\n");
    printf("|                   Escolha uma das opções...                         |\n");
    printf("|                                                                     |\n");
    printf("#=====================================================================#\n");
    printf("\n");
}

void cadastrar_funcionario(void)
{
    char nome_funcionario[51];
    int idade_funcionario;
    char cpf_funcionario[12];
    char cargo[22];
    char email[30];

    printf("Nome do funcionário: ");
    getchar();
    fgets(nome_funcionario, sizeof(nome_funcionario), stdin);
    printf("Idade do funcionário: ");
    getchar();
    scanf("%d", &idade_funcionario);
    printf("CPF do funcionário: ");
    getchar();
    fgets(cpf_funcionario, sizeof(cpf_funcionario), stdin);
    printf("Cargo do funcionário: ");
    getchar();
    fgets(cargo, sizeof(cargo), stdin);
    printf("Email do funcionário: ");
    getchar();
    fgets(email, sizeof(email), stdin);
    system("cls||clear");
    printf("Funcionário Registrado com Sucesso!\n");
    printf("Pressione Enter para continuar...");
    getchar();
}

void modulo_atualizar_funcionario(void)
{
    char cpf[12];
    char choose;
    char nome_funcionario[51];
    char novo_cpf[12];
    char cargo[22];
    char email[30];
    int idade;

    printf("Digite o CPF do funcionário que deseja atualizar os dados: ");
    getchar();
    scanf(" %s", cpf);

    // fazer verificação quando fazer o armazenamento de dados

    system("clear||cls");
    printf("[1] Nome\n");
    printf("[2] Idade\n");
    printf("[3] Cpf\n");
    printf("[4] Cargo\n");
    printf("[5] E-mail\n");
    printf("[0] Cancelar\n");
    printf("-----------------------\n");
    scanf(" %c", &choose);
    system("clear||cls");
    if (choose == '1')
    {
        printf("Selecione o novo nome: ");
        getchar();
        fgets(nome_funcionario, sizeof(nome_funcionario), stdin);
    }
    else if (choose == '2')
    {
        printf("Selecione a nova idade: ");
        scanf(" %d", &idade);
        getchar();
    }
    else if (choose == '3')
    {
        printf("Selecione o novo CPF: ");
        scanf(" %s", novo_cpf);
        getchar();
    }
    else if (choose == '4')
    {
        printf("Selecione o novo cargo: ");
        getchar();
        fgets(cargo, sizeof(cargo), stdin);
    }
    else if (choose == '5')
    {
        printf("Selecione o novo E-mail: ");
        scanf(" %s", email);
        getchar();
    }
    printf("Pressione enter para continuar...");
    getchar();
}

void modulo_relatorios(void)
{
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
    printf("|                    # 1 # Relatório de clientes                      |\n");
    printf("|                    # 2 # Relatório de veículos                      |\n");
    printf("|                    # 3 # Relatório de aluguéis ativos               |\n");
    printf("|                    # 4 # Relatório de aluguéis finalizados          |\n");
    printf("|                    # 5 # Relatório de funcionários                  |\n");
    printf("|                    # 0 # Voltar ao menu principal                   |\n");
    printf("|                                                                     |\n");
    printf("|                   Escolha uma das opções...                         |\n");
    printf("|                                                                     |\n");
    printf("#=====================================================================#\n");
    printf("\n");
}