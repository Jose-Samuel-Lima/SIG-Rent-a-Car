#include <stdlib.h>
#include <stdio.h>
#include "clientes.h"
#include "veiculos.h"
#include "alugueis.h"
#include "funcionarios.h"
#include "relatorios.h"

// Assinatura das funções
void menu_principal(void);
void menu_sobre(void);
void modulo_equipe(void);
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
            int resulFunc;
            resulFunc = modulo_funcionario();
            if (resulFunc == -1)
            {
                op = 'm';
            }
            else
            {
                op = resulFunc;
            }
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
            int resulAluguel;
            resulAluguel = modulo_aluguel();
            if (resulAluguel == -1)
            {
                op = 'm';
            }
            else
            {
                op = resulAluguel;
            }
        }
        else if (op == '5')
        {
            int resulRelat;
            resulRelat = modulo_relatorio();
            if (resulRelat == -1)
            {
                op = 'm';
            }
            else
            {
                op = resulRelat;
            }
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

void mensagem_manutencao(void)
{
    system("cls||clear");
    printf("Essa página não está disponível no momento. Aguarde futuras atualizações.\n");
    printf("Pressione Enter para continuar...");
    getchar();
    getchar();
}
