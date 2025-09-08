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
void cadastrar_funcionario(void);
// void modulo_dados_funcionario(void);
// void modulo_atualizar_funcionario(void);
// void modulo_excluir_funcionario (void);

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

    while (ainda_roda == 1) {
        if (op == 'm') {
            menu_principal();
            scanf(" %c", &op);
        } else if (op == '1') {
            modulo_funcionario();
            scanf(" %c", &op);
            switch (op) {
                case '0': op = 'm';
                        break;
                case '1': cadastrar_funcionario();
                        break;
                case '2': mensagem_manutencao();
                        break;
                case '3': mensagem_manutencao();
                        break;
                case '4': mensagem_manutencao();
                        break;
            }
            op = 'm';
        } else if (op == '2') {
            modulo_cliente();
            scanf(" %c", &op);
            switch (op) {
                case '0': op = 'm';
                        break;
                case '1': modulo_cadastrar_cliente();
                        break;
                case '2': modulo_dados_cliente();
                        break;
                case '3': modulo_atualizar_cliente();
                        break;
                case '4': modulo_excluir_cliente();
                        break;
            }
            op = 'm';
        } else if (op == '3') {
            modulo_de_veiculos();
            scanf(" %c", &op);
            switch (op) {
                case '0': op = 'm';
                        break;
                case '1': modulo_cadastrar_veiculo();
                        break;
                case '2': mensagem_manutencao();
                        break;
                case '3': mensagem_manutencao();
                        break;
                case '4': mensagem_manutencao();
                        break;
            }
            op = 'm';
        } else if (op == '4') {
            modulo_alugueis();
            scanf(" %c", &op);
            switch (op) {
                case '0': op = 'm';
                        break;
                case '1': modulo_cadastrar_aluguel();
                        break;
                case '2': mensagem_manutencao();
                        break;
                case '3': mensagem_manutencao();
                        break;
                case '4': mensagem_manutencao();
                        break;
            }
            op = 'm';
        } else if (op == '5') {
            modulo_relatorios();
            scanf(" %c", &op);
            switch (op) {
                case '0': op = 'm';
                        break;
                case '1': mensagem_manutencao();
                        break;
                case '2': mensagem_manutencao();
                        break;
                case '3': mensagem_manutencao();
                        break;
                case '4': mensagem_manutencao();
                        break;
                case '5': mensagem_manutencao();
                        break;
            }
            op ='m';
        } else if (op == '6') {
            modulo_equipe();
            printf("Pressione Enter para voltar ao menu principal...");
            getchar();
            getchar();
            op = 'm';
        } else if (op == '7') {
            menu_sobre();
            printf("Pressione Enter para voltar ao menu principal...");
            getchar();
            getchar();
            op = 'm';
        } else if (op == '0') {
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

void modulo_cadastrar_cliente(void) {
    char nome_cliente[51];
    int idade_cliente;
    char cpf_cliente[12];
    char email[30];
    char CNH[13];

    printf("Nome do cliente: ");
    getchar();
    fgets(nome_cliente, sizeof(nome_cliente), stdin);
    printf("Idade do cliente: ");
    getchar();
    scanf("%d", &idade_cliente);
    printf("CPF do cliente: ");
    getchar();
    fgets(cpf_cliente, sizeof(cpf_cliente), stdin);
    printf("Email do cliente: ");
    getchar();
    fgets(email, sizeof(email), stdin);
    printf("CNH do cliente: ");
    getchar();
    fgets(CNH, sizeof(CNH), stdin);
    system("cls||clear");
    printf("Cliente Registrado com Sucesso!\n");
    printf("Pressione Enter para continuar...");
    getchar();
}

void modulo_dados_cliente(void)
{
    char cpf[15];

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
    scanf("%14s", cpf);
    getchar();
    system("cls||clear");
    printf("Pressione Enter para continuar...");
    getchar();
}

void modulo_atualizar_cliente(void) {
    char cpf_cliente[12];
    char choose;
    char nome_cliente[51];
    int idade_cliente;
    char novo_cpf_cliente[12];
    char email[30];
    char CNH[13];

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
    scanf("%14s", cpf_cliente);
    getchar();


    // fazer verificação quando fazer o armazenamento de dados

    system("clear||cls");
    printf("[1] Novo Nome do Cliente\n");
    printf("[2] Nova Idade do Cliente\n");
    printf("[3] Novo Cpf do Cliente\n");
    printf("[4] Novo E-mail do Cliente\n");
    printf("[5] Novo nº CNH do Cliente\n");
    printf("[0] Cancelar\n");
    printf("-----------------------\n");
    scanf(" %c", &choose);
    system("clear||cls");
    if (choose == '1') {
        printf("Informe o novo nome: ");
        getchar();
        fgets(nome_cliente, sizeof(nome_cliente), stdin);
    } else if (choose == '2') {
        printf("Informe a nova idade: ");
        scanf(" %d", &idade_cliente);
        getchar();
    } else if (choose == '3') {
        printf("Informe o novo CPF: ");
        scanf(" %s", novo_cpf_cliente);
        getchar();
    } else if (choose == '4') {
        printf("Informe o novo E-mail: ");
        scanf(" %s", email);
        getchar();
    } else if (choose == '5') {
        printf("Informe o novo número da CNH: ");
        getchar();
        fgets(CNH, sizeof(CNH), stdin);
    }
    printf("Pressione enter para continuar...");
    getchar();
}

void modulo_excluir_cliente(void)
{
    char cpf[15];

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
    scanf("%14s", cpf);
    getchar();
    system("cls||clear");
    printf("Pressione Enter para continuar...");
    getchar();
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

void modulo_cadastrar_veiculo(void) {
    char nome_veiculo[51];
    float preco_veiculo;
    char placa_veiculo[8];
    char marca[15];
    char modelo[13];
    char codigo_renavam[12];

    printf("Nome do veículo: ");
    getchar();
    fgets(nome_veiculo, sizeof(nome_veiculo), stdin);
    printf("Preço do veículo: ");
    getchar();
    scanf("%f", &preco_veiculo);
    printf("Placa do veículo: ");
    getchar();
    fgets(placa_veiculo, sizeof(placa_veiculo), stdin);
    printf("Marca do veículo: ");
    getchar();
    fgets(marca, sizeof(marca), stdin);
    printf("Modelo do veículo: ");
    getchar();
    fgets(modelo, sizeof(modelo), stdin);
    printf("Código RENAVAM do veículo: ");
    getchar();
    fgets(codigo_renavam, sizeof(codigo_renavam), stdin);
    system("cls||clear");
    printf("Veículo Registrado com Sucesso!\n");
    printf("Pressione Enter para continuar...");
    getchar();
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

void cadastrar_funcionario(void) {
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

void mensagem_manutencao(void) {
    system("cls||clear");
    printf("Essa página não está disponível no momento. Aguarde futuras atualizações.\n");
    printf("Pressione Enter para continuar...");
    getchar();
    getchar();

}