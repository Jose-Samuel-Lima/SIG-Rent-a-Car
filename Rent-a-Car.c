#include <stdlib.h>
#include <stdio.h>

// Assinatura das funções
void menu_principal(void);
void menu_sobre(void);
void modulo_equipe(void);

// Funções Cliente
void modulo_cliente(void);
void modulo_cadastrar_cliente(void);
void modulo_dados_cliente(void);
void modulo_atualizar_cliente(void);
void modulo_excluir_cliente(void);

// Funções Veículo
void modulo_de_veiculos(void);
void modulo_cadastrar_veiculo(void);
void modulo_dados_veiculo(void);
void modulo_atualizar_veiculo(void);
void modulo_excluir_veiculo(void);

// Funções Aluguel
void modulo_alugueis(void);
void modulo_cadastrar_aluguel(void);
// void modulo_dados_aluguel(void);
// void modulo_alterar_aluguel(void);
// void modulo_finalizar_aluguel(void);

// Funções Funcionário
void modulo_funcionario(void);
// void modulo_cadastrar_funcionario(void);
// void modulo_dados_funcionario(void);
// void modulo_atualizar_funcionario(void);
// void modulo_excluir_funcionario (void);

// Funções Relatórios
void modulo_relatorios(void);
// void modulo_relatorio_clientes(void);
// void modulo_relatorio_veiculos(void);

// void modulo_relatorio_funcionarios(void);

// Programa principal
int main(void)
{
    char op;
    op = 'm';
    int ainda_roda;
    ainda_roda = 1;

    while (ainda_roda == 1) {
        if (op == 'm') {
            menu_principal();
            scanf(" %c", &op);
        } else if (op == '1') {
            modulo_funcionario();
            scanf(" %c", &op);
            if (op == '0') {
                op = 'm';
            }
        } else if (op == '1') {
            modulo_cliente();
            scanf(" %c", &op);
            if (op == '0') {
                op = 'm';
            }
        } else if (op == '2') {
            modulo_de_veiculos();
            scanf(" %c", &op);
            if (op == '0') {
                op = 'm';
            }
        } else if (op == '3') {
            modulo_alugueis();
            scanf(" %c", &op);
            if (op == '0') {
                op = 'm';
            }
        } else if (op == '4') {
            modulo_relatorios();
            scanf(" %c", &op);
            if (op == '0') {
                op = 'm';
            }
        } else if (op == '5') {
            modulo_equipe();
            printf("Pressione Enter para voltar ao menu principal...");
            getchar();
            getchar();
            op = 'm';
        } else if (op == '6') {
            menu_sobre();
            printf("Pressione Enter para voltar ao menu principal...");
            getchar();
            getchar();
            op = 'm';
        } else if (op == '0') {
            ainda_roda = 0;
        }
    }

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

void modulo_cliente(void)
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
    printf("|                   < = = = Módulo Cliente = = = >                    |\n");
    printf("|                                                                     |\n");
    printf("|                    # 1 # Cadastrar novo cliente                     |\n");
    printf("|                    # 2 # Dados do cliente                           |\n");
    printf("|                    # 3 # Alterar dados do cliente                   |\n");
    printf("|                    # 4 # Excluir um cliente                         |\n");
    printf("|                    # 0 # Voltar ao menu principal                   |\n");
    printf("|                                                                     |\n");
    printf("|                   Escolha uma das opções...                         |\n");
    printf("|                                                                     |\n");
    printf("#=====================================================================#\n");
    printf("\n");
}

void modulo_de_veiculos(void)
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
    printf("|                   < = = = Módulo de Veículos = = = >                |\n");
    printf("|                                                                     |\n");
    printf("|                    # 1 # Cadastrar novo veículo                     |\n");
    printf("|                    # 2 # Dados do veículo                           |\n");
    printf("|                    # 3 # Alterar dados do veículo                   |\n");
    printf("|                    # 4 # Excluir um veículo                         |\n");
    printf("|                    # 0 # Voltar ao menu principal                   |\n");
    printf("|                                                                     |\n");
    printf("|                   Escolha uma das opções...                         |\n");
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

void modulo_cadastrar_cliente(void)
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
    printf("|                T ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ T             |\n");
    printf("|                | < = = = Cadastro de Clientes = = = > |             |\n");
    printf("|                T ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ T             |\n");
    printf("|                                                                     |\n");
    printf("|                    + Nome do cliente:                               |\n");
    printf("|                    + CPF do cliente:                                |\n");
    printf("|                    + CNH do cliente:                                |\n");
    printf("|                    + Data de Nascimento do cliente:                 |\n");
    printf("|                    + Endereço do cliente:                           |\n");
    printf("|                    + Telefone do cliente:                           |\n");
    printf("|                    + Email do cliente:                              |\n");
    printf("|                                                                     |\n");
    printf("|                   Escolha uma das opções...                         |\n");
    printf("|                                                                     |\n");
    printf("#=====================================================================#\n");
    printf("\n");
}

void modulo_dados_cliente(void)
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
    printf("|                T ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ T             |\n");
    printf("|                | < = = =  Dados dos Clientes  = = = > |             |\n");
    printf("|                T ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ T             |\n");
    printf("|                                                                     |\n");
    printf("|       Por favor informe o CPf do cliente que deseja encontrar:      |\n");
    printf("|                                                                     |\n");
    printf("|                    + CPF do cliente:                                |\n");
    printf("|                                                                     |\n");
    printf("#=====================================================================#\n");
    printf("\n");
}

void modulo_atualizar_cliente(void)
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
    printf("|             T ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ T          |\n");
    printf("|             | < = = =  Alterar dados do Cliente  = = = > |          |\n");
    printf("|             T ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ T          |\n");
    printf("|                                                                     |\n");
    printf("|      Por favor informe o CPf do cliente para alterar os dados:      |\n");
    printf("|                                                                     |\n");
    printf("|                    + CPF do cliente:                                |\n");
    printf("|                                                                     |\n");
    printf("#=====================================================================#\n");
    printf("\n");
}

void modulo_excluir_cliente(void)
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
    printf("|             T ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ T          |\n");
    printf("|             | < = = =  Excluir dados do Cliente  = = = > |          |\n");
    printf("|             T ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ T          |\n");
    printf("|                                                                     |\n");
    printf("|        Por favor informe o CPf do cliente que deseja excluir:       |\n");
    printf("|                                                                     |\n");
    printf("|                    + CPF do cliente:                                |\n");
    printf("|                                                                     |\n");
    printf("#=====================================================================#\n");
    printf("\n");
}

void modulo_cadastrar_veiculo(void)
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
    printf("|                T ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ T             |\n");
    printf("|                | < = = = Cadastro de Veículos = = = > |             |\n");
    printf("|                T ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ T             |\n");
    printf("|                                                                     |\n");
    printf("|                    + Nome do veículo:                               |\n");
    printf("|                    + Modelo do veículo:                             |\n");
    printf("|                    + Placa do veículo:                              |\n");
    printf("|                    + Data de fabricação do veículo:                 |\n");
    printf("|                    + Número do chassi:                              |\n");
    printf("|                    + Código da RENAVAM:                             |\n");
    printf("|                                                                     |\n");
    printf("|                   Escolha uma das opções...                         |\n");
    printf("|                                                                     |\n");
    printf("#=====================================================================#\n");
    printf("\n");
}

void modulo_dados_veiculo(void)
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
    printf("|                T ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ T             |\n");
    printf("|                | < = = =  Dados dos Veículos  = = = > |             |\n");
    printf("|                T ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ T             |\n");
    printf("|                                                                     |\n");
    printf("|           Por favor informe o Código da RENAVAM  para encontrar     |\n");
    printf("|       o veículo que deseja:                                         |\n");
    printf("|                                                                     |\n");
    printf("|                    + Código da RENAVAM do veículo:                  |\n");
    printf("|                                                                     |\n");
    printf("#=====================================================================#\n");
    printf("\n");
}

void modulo_atualizar_veiculo(void)
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
    printf("|             T ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ T          |\n");
    printf("|             | < = = =  Alterar dados do Veículo  = = = > |          |\n");
    printf("|             T ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ T          |\n");
    printf("|                                                                     |\n");
    printf("|           Por favor informe o Código da RENAVAM  para encontrar     |\n");
    printf("|       o veículo que deseja alterar:                                 |\n");
    printf("|                                                                     |\n");
    printf("|                    + Código da RENAVAM do veículo:                  |\n");
    printf("|                                                                     |\n");
    printf("#=====================================================================#\n");
    printf("\n");
}

void modulo_excluir_veiculo(void)
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
    printf("|             T ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ T          |\n");
    printf("|             | < = = =  Excluir dados do Veículo  = = = > |          |\n");
    printf("|             T ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ T          |\n");
    printf("|                                                                     |\n");
    printf("|           Por favor informe o Código da RENAVAM  para encontrar     |\n");
    printf("|       o veículo que deseja excluir:                                 |\n");
    printf("|                                                                     |\n");
    printf("|                    + Código da RENAVAM do veículo:                  |\n");
    printf("|                                                                     |\n");
    printf("#=====================================================================#\n");
    printf("\n");
}

void modulo_cadastrar_aluguel(void)
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
    printf("|                T ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ T             |\n");
    printf("|                | < = = = Cadastro de Aluguéis = = = > |             |\n");
    printf("|                T ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ T             |\n");
    printf("|                                                                     |\n");
    printf("|                    + Nome do cliente:                               |\n");
    printf("|                    + CPF do cliente:                                |\n");
    printf("|                    + Placa do veículo:                              |\n");
    printf("|                    + Código da RENAVAM:                             |\n");
    printf("|                    + Código do Aluguel:                             |\n");
    printf("|                                                                     |\n");
    printf("|                   Escolha uma das opções...                         |\n");
    printf("|                                                                     |\n");
    printf("#=====================================================================#\n");
    printf("\n");
}