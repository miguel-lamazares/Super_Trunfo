#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

#define RED "\033[1;31m"
#define BLUE "\033[1;34m"
#define GREEN "\033[1;92m"
#define RESET "\033[0m"
#define PURPLE "\033[1;35m"

void mostrar_carta(char *estado, char *city, char *card_id, float *area, float *pib, unsigned long int *populacao, int *ponto_turistico, float *DP, float *PC, float *super)
{
    printf(BLUE "-----------------------------------------------------\n");
    printf(RESET);
    printf("\n");
    printf("Estado: %s\n", estado);
    printf("Cidade: %s\n", city);
    printf("ID do cartão: %s\n", card_id);
    printf("Área: %.2f km²\n", *area);
    printf("PIB: R$ %.2f\n", *pib);
    printf("População: %lu\n", *populacao);
    printf("Pontos turísticos: %d\n", *ponto_turistico);
    printf("Densidade Populacional: %.2f habitantes/km²\n", *DP);
    printf("PIB por Capita: R$ %.2f\n", *PC);
    printf("\n");
    printf(RED "SUPER PODER: %.2f\n", *super);
    printf("\n");
    printf(BLUE "-----------------------------------------------------\n");
}
void calc_super_poder(int *ponto_turistico, unsigned long int *populacao, float *area, float *pib, float *DP, float *PC, float *super)
{
    float new_dp;
    new_dp = *populacao / *area;
    *super = *ponto_turistico + *populacao + *area + *pib + *PC + new_dp;
}
void carta()
{
    printf(GREEN "--------------------" RESET "X0NNNNNNNNNNNNNNNNNNNNNNX" GREEN "-----------------------------" RESET "X0NNNNNNNNNNNNNNNNNNNNNNX" GREEN "--------------------\n");
    printf(GREEN "--------------------" RESET "NlNX.cMMMMMMMMMMMMMMMMMMW" GREEN "-----------------------------" RESET "NlNX.cMMMMMMMMMMMMMMMMMMW" GREEN "--------------------\n");
    printf(GREEN "--------------------" RESET "KNKNOKMMMMMMMMMMMMMMMMMMW" GREEN "-----------------------------" RESET "KNKNOKMMMMMMMMMMMMMMMMMMW" GREEN "--------------------\n");
    printf(GREEN "--------------------" RESET "NMMMMMXXXXXXXXXXXXXMMMMMW" GREEN "-----------------------------" RESET "NMMMMMXXXXXXXXXXXXXMMMMMW" GREEN "--------------------\n");
    printf(GREEN "--------------------" RESET "NMMMMMOMMMMMMMMMMMOMMMMMW" GREEN "------" RED "JOGO" GREEN "-" RED "SUPER" GREEN "-" RED "TRUNFO" GREEN "------" RESET "NMMMMMOMMMMMMMMMMMOMMMMMW" GREEN "--------------------\n");
    printf(GREEN "--------------------" RESET "NMMMMMOMMMMK'xMMMMOMMMMMW" GREEN "-----------------------------" RESET "NMMMMMOMMMMK'xMMMMOMMMMMW" GREEN "--------------------\n");
    printf(GREEN "--------------------" RESET "NMMMMMOMMMl   ,NMMOMMMMMW" GREEN "-----------------------------" RESET "NMMMMMOMMMl   ,NMMOMMMMMW" GREEN "--------------------\n");
    printf(GREEN "--------------------" RESET "NMMMMMOMK.      OMOMMMMMW" GREEN "-----------------------------" RESET "NMMMMMOMK.      OMOMMMMMW" GREEN "--------------------\n");
    printf(GREEN "--------------------" RESET "NMMMMMON         MOMMMMMW" GREEN "---" RED "SEJA" GREEN "-" RED "BEM" GREEN "-" RED "VINDO" GREEN "-" RED "AO" GREEN "-" RED "JOGO!" GREEN "---" RESET "NMMMMMON         MOMMMMMW" GREEN "--------------------\n");
    printf(GREEN "--------------------" RESET "NMMMMMOMXk0: dOOWMOMMMMMW" GREEN "-----------------------------" RESET "NMMMMMOMXk0: dOOWMOMMMMMW" GREEN "--------------------\n");
    printf(GREEN "--------------------" RESET "NMMMMMOMMMMK0XMMMMOMMMMMW" GREEN "-----------------------------" RESET "NMMMMMOMMMMK0XMMMMOMMMMMW" GREEN "--------------------\n");
    printf(GREEN "--------------------" RESET "NMMMMMOMMMMMMMMMMMOMMMMMW" GREEN "-----------------------------" RESET "NMMMMMOMMMMMMMMMMMOMMMMMW" GREEN "--------------------\n");
    printf(GREEN "--------------------" RESET "NMMMMMXXXXXXXXXXXXXMMMMMW" GREEN "-----------------------------" RESET "NMMMMMXXXXXXXXXXXXXMMMMMW" GREEN "--------------------\n");
    printf(GREEN "--------------------" RESET "NMMMMMMMMMMMMMMMMMMXkXNKX" GREEN "-----------------------------" RESET "NMMMMMMMMMMMMMMMMMMXkXNKX" GREEN "--------------------\n");
    printf(GREEN "--------------------" RESET "NMMMMMMMMMMMMMMMMMMd.0McX" GREEN "-----------------------------" RESET "NMMMMMMMMMMMMMMMMMMd.0McX" GREEN "--------------------\n");
    printf(GREEN "--------------------" RESET "XNNNNNNNNNNNNNNNNNNNNNN0X" GREEN "-----------------------------" RESET "XNNNNNNNNNNNNNNNNNNNNNN0X" GREEN "--------------------\n");
    printf(RESET "");
}

void calculo(float area, float pib, unsigned long int populacao, float *DP, float *PC)
{
    *DP = populacao / area;
    *PC = pib * 1000000 / populacao;
}

void preencher_dados(char *estado, char *city, char *card_id, float *area, float *pib, unsigned long int *populacao, int *ponto_turistico)
{
    int resultado;
    printf("Digite o nome do estado: ");
    fgets(estado, 20, stdin);
    estado[strcspn(estado, "\n")] = 0;

    printf("Digite o nome da cidade: ");
    fgets(city, 20, stdin);
    city[strcspn(city, "\n")] = 0;

    printf("Digite o ID do cartão: ");
    fgets(card_id, 4, stdin);
    card_id[strcspn(card_id, "\n")] = 0;

    do
    {
        printf("Digite a área do estado (em km²): ");
        resultado = scanf("%f", area);
        while (getchar() != '\n')
            ;

        if (resultado != 1)
        {
            printf("Entrada inválida! Por favor, insira um número.\n");
        }
        else if (*area <= 0)
        {
            printf("Área inválida! Por favor, insira um valor valido.\n");
        }
    } while (resultado != 1 || *area <= 0);

    do
    {

        printf("Digite o PIB do estado (em Milhoes de R$): ");
        resultado = scanf("%f", pib);
        while (getchar() != '\n')
            ;
        if (resultado != 1)
        {
            printf("Entrada inválida! Por favor, insira um número.\n");
        }
        else if (*pib <= 0)
        {
            printf("PIB inválido! Por favor, insira um valor valido.\n");
        }
    } while (resultado != 1 || *pib <= 0);

    do
    {

        printf("Digite a população do estado: ");
        resultado = scanf("%lu", populacao);
        while (getchar() != '\n')
            ;
        if (resultado != 1)
        {
            printf("Entrada inválida! Por favor, insira um número.\n");
        }
        else if (*populacao <= 0)
        {
            printf("População inválida! Por favor, insira um valor valido.\n");
        }
    } while (resultado != 1 || *populacao <= 0);
    do
    {
        printf("Digite o número de pontos turísticos: ");
        resultado = scanf("%d", ponto_turistico);
        while (getchar() != '\n')
            ;
        if (resultado != 1)
        {
            printf("Entrada inválida! Por favor, insira um número.\n");
        }
        else if (*ponto_turistico <= 0)
        {
            printf("Número de pontos turísticos inválido! Por favor, insira um valor valido.\n");
        }
    } while (resultado != 1 || *ponto_turistico <= 0);
}
void comparar_cartas(float *super, float *super1)
{
    if (*super > *super1)
    {
        printf("A primeira carta é mais forte!\n");
    }
    else if (*super < *super1)
    {
        printf("A segunda carta é mais forte!\n");
    }
    else
    {
        printf("As cartas são iguais!\n");
    }
}

void apresentar(float *area, float *pib, unsigned long int *populacao, int *ponto_turistico, float *DP, float *PC, float *super,
                float *area1, float *pib1, unsigned long int *populacao1, int *ponto_turistico1, float *DP1, float *PC1, float *super1)
{
    printf(GREEN "______________________\n" RESET);
    printf("Comparação dos atributos:\n");

    printf("Área: %s\n", (*area > *area1) ? "Carta 1 vence" : (*area < *area1) ? "Carta 2 vence"
                                                                               : "Empate");
    printf("PIB: %s\n", (*pib > *pib1) ? "Carta 1 vence" : (*pib < *pib1) ? "Carta 2 vence"
                                                                          : "Empate");
    printf("População: %s\n", (*populacao > *populacao1) ? "Carta 1 vence" : (*populacao < *populacao1) ? "Carta 2 vence"
                                                                                                        : "Empate");
    printf("Pontos Turísticos: %s\n", (*ponto_turistico > *ponto_turistico1) ? "Carta 1 vence" : (*ponto_turistico < *ponto_turistico1) ? "Carta 2 vence"
                                                                                                                                        : "Empate");
    printf("PIB per Capita: %s\n", (*PC > *PC1) ? "Carta 1 vence" : (*PC < *PC1) ? "Carta 2 vence"
                                                                                 : "Empate");
    printf("Densidade Populacional: %s\n", (*DP > *DP1) ? "Carta 1 vence" : (*DP < *DP1) ? "Carta 2 vence"
                                                                                         : "Empate");
    printf("Super Poder: %s\n", (*super > *super1) ? "Carta 1 vence" : (*super < *super1) ? "Carta 2 vence"
                                                                                          : "Empate");
    printf(GREEN "______________________\n" RESET);
}

int main()
{
    setlocale(LC_ALL, "Portuguese_Brazil");

    char estado[20], card_id[4], city[20], estado1[20], card_id1[4], city1[20];
    strcpy(card_id, "A01");
    strcpy(card_id1, "B01");

    int ponto_turistico, ponto_turistico1;
    unsigned long int populacao, populacao1;
    float area, pib, area1, pib1;
    float DP, DP1, PC, PC1;

    int resultado;
    float new_dp;
    float super, super1;

    carta();
    system("pause");
    system("cls");

    preencher_dados(estado, city, card_id, &area, &pib, &populacao, &ponto_turistico);
    calculo(area, pib, populacao, &DP, &PC);
    calc_super_poder(&ponto_turistico, &populacao, &area, &pib, &DP, &PC, &super);

    printf("\nA primeira carta foi criada com sucesso!\n\n");
    printf(BLUE "-----------------------------------------------------\n");
    printf(RESET);
    printf("Pressione Enter para visualizar a primeira carta\n");
    getchar();
    system("cls");
    mostrar_carta(estado, city, card_id, &area, &pib, &populacao, &ponto_turistico, &DP, &PC, &super);

    printf(RESET "pressione Enter para criar a segunda carta\n");
    getchar();
    system("cls");

    preencher_dados(estado1, city1, card_id1, &area1, &pib1, &populacao1, &ponto_turistico1);
    calculo(area1, pib1, populacao1, &DP1, &PC1);
    calc_super_poder(&ponto_turistico1, &populacao1, &area1, &pib1, &DP1, &PC1, &super1);

    printf("\nA segunda carta foi criada com sucesso!\n");
    printf(BLUE "\n-----------------------------------------------------\n");
    printf(RESET "Pressione Enter para visualizar a segunda carta\n");
    getchar();
    system("cls");

    mostrar_carta(estado1, city1, card_id1, &area1, &pib1, &populacao1, &ponto_turistico1, &DP1, &PC1, &super1);

    printf(RESET "pressione Enter para comparar as cartas\n");
    getchar();
    system("cls");

    printf(BLUE "-----------------------------------------------------\n\n");
    printf(RESET "Comparando as cartas...\n\n");
    printf(BLUE "-----------------------------------------------------\n" RESET "");
    system("pause");
    system("cls");
    comparar_cartas(&super, &super1);
    apresentar(&area, &pib, &populacao, &ponto_turistico, &DP, &PC, &super,
               &area1, &pib1, &populacao1, &ponto_turistico1, &DP1, &PC1, &super1);
    printf("\n");
    printf(BLUE "-----------------------------------------------------\n" RESET "");

    system("pause");
    system("cls");

    printf(PURPLE "OBRIGADO POR JOGAR!\nDeseja jogar novamente? (s/n)\n" RESET "");
    if (getchar() == 's')
    {
        system("cls");
        main();
    }
    else if (getchar() == 'n')
    {
        printf("Obrigado por jogar!\n\nPressione Enter para sair...\n");
        system("pause");
        return 0;
    }
    else
    {
        printf("Opção inválida! Saindo do jogo...\n");
        system("pause");
        return 0;
    }
}
