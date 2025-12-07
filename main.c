#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "clientes.h"
#include "veiculos.h"
#include "alugueis.h"
#include "funcionarios.h"
#include "relatorios.h"

// Assinatura das funções
char menu_principal(void);
void menu_sobre(void);
void modulo_equipe(void);
void mensagem_manutencao(void);

// Programa principal

int main(void)
 {
    char op;

    do {
        op = menu_principal();
        switch(op) {
            case '1': modulo_funcionario();
                    break;
            case '2': modulo_cliente();
                    break;
            case '3': modulo_veiculo();
                    break;
            case '4': modulo_aluguel();
                    break;
            case '5': modulo_relatorio();
                    break;
            case '6': modulo_equipe();
                    break;
            case '7': menu_sobre();
                    break;
        }
    } while (op != '0');
 }

char menu_principal(void)
{   
    char op;
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
    printf("|             Universidade Federal do Rio Grande do Norte             |\n");
    printf("|                 Centro de Ensino Superior do Seridó                 |\n");
    printf("|               Departamento de Computação e Tecnologia               |\n");
    printf("|                 Disciplina DCT1106 -- Programação                   |\n");
    printf("|        Projeto Sistema de Gestão para uma Locadora de Veículos      |\n");
    printf("|          Developed by @José-Samuel-Lima -- since Aug, 2025          |\n");
    printf("|                                                                     |\n");
    printf("#=====================================================================#\n");
    printf("|                          MENU PRINCIPAL                             |\n");
    printf("|---------------------------------------------------------------------|\n");
    printf("|                     [1] - Módulo Funcionários                       |\n");
    printf("|                     [2] - Módulo Clientes                           |\n");
    printf("|                     [3] - Módulo de Veículos                        |\n");
    printf("|                     [4] - Módulo de Alugueis                        |\n");
    printf("|                     [5] - Módulo Relatórios                         |\n");
    printf("|---------------------------------------------------------------------|\n");
    printf("|                     [6] - Informações da Equipe                     |\n");
    printf("|                     [7] - Sobre o Programa                          |\n");
    printf("|---------------------------------------------------------------------|\n");
    printf("|                     [0] - Finalizar Programa                        |\n");
    printf("#=====================================================================#\n");
    printf("\n");
    printf("Escolha uma das opções acima:");
    scanf("%c", &op);
    while ((c = getchar()) != '\n' && c != EOF);
    return op;
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
    printf("|   é um ferramenta desenvolvida para organizar e automatizar         |\n");
    printf("|   os processos administrativos e operacionais da empresa.           |\n");
    printf("|   Seu principal objetivo é facilitar o controle das atividades      |\n");
    printf("|   relacionadas à frota de veículos, aos clientes e às locações      |\n");
    printf("|   realizadas, garantindo maior eficiência, segurança e              |\n");
    printf("|   agilidade no atendimento.                                         |\n");
    printf("|                                                                     |\n");
    printf("#=====================================================================#\n");
    printf("\n");
    printf("Precione Enter para continuar..");
    getchar();
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
    printf("| Desenvolvedor(es): José Samuel Silva Lima, Icaro Nonato de Freitas, |\n");
    printf("| Gleydson Henrique Dantas da Silva e Pedro Henrique da Silva         |\n");
    printf("|      Email: jose.lima.146@ufrn.edu.br                               |\n");
    printf("|      Email: icaro.freitas.113@ufrn.edu.br                           |\n");
    printf("|      Email: gleydson.silva.716@ufrn.edu.br                          |\n");
    printf("|      Git: https://github.com/Jose-Samuel-Lima/SIG-Rent-a-Car.git    |\n");
    printf("|                                                                     |\n");
    printf("#=====================================================================#\n");
    printf("\n");
    printf("Precione Enter para continuar..");
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
