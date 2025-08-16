#include <stdio.h>
#include <stdlib.h>



void menu_principal(void);
// void menu_sobre(void);
// void modulo_equipe(void);
// void modulo_cliente(void);
// void modulo_de_veiculos(void);
// void modulo_alugueis(void);
// void modulo_relatorios(void);



int main(void){
    menu_principal();
    // menu_sobre();
    // modulo_equipe();
    // modulo_cliente();
    // modulo_de_veiculos();
    // modulo_alugueis();
    // modulo_relatorios();
    return 0;
}




void menu_principal(void){
    char op;
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
    printf("|                    # 1 # Módulo Clientes                            |\n");
    printf("|                    # 2 # Módulo de Veículos                         |\n");
    printf("|                    # 3 # Módulo de Alugueis                         |\n");
    printf("|                    # 4 # Módulo Relatórios                          |\n");
    printf("|                    # 5 # Informações da Equipe                      |\n");
    printf("|                    # 6 # Sobre o Programa                           |\n");
    printf("|                    # 0 # Finalizar Programa                         |\n");
    printf("|                                                                     |\n");
    printf("|                   Escolha uma das opções...                         |\n");
    printf("|                                                                     |\n");
    printf("#=====================================================================#\n");
    scanf("%c", &op);
    getchar();
    printf("\n");
    printf("\t\t\tTecle *Enter* para continuar..\n");
    printf("\n");
    getchar();
}


