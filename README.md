# # Desafio Mestre

## Documentação do Projeto 📄

Este projeto consiste em um sistema de cadastro de cidades para um jogo de cartas no estilo Super Trunfo. O objetivo principal é registrar informações de duas cidades e calcular indicadores relevantes para comparação. O sistema realiza a verificação da entrada de dados, utiliza arte ASCII, exibe linhas e caracteres coloridos, além de implementar práticas para limpeza do terminal.

---

# Guia de Arquivos 🔍

- `mestre.c` — Código-fonte do programa.
- `mestre.exe` — Executável do programa.

---

## Tecnologias Utilizadas 📚

### Bibliotecas 🧩

- `<stdio.h>` — Entrada e saída de dados.
- `<stdlib.h>` — Incrementação de funções para tornar o código mais fluido.
- `<locale.h>` — Suporte a caracteres especiais em português.
- `<string.h>` — Manipulação de strings.

### Tipos de Variáveis 🧠

- `int` — Números inteiros.
- `unsigned long int` — Números inteiros longos sem sinal.
- `float` — Números decimais.
- `char[]` — Strings (vetores de caracteres).

### Funções Principais 🛠️

*stdio.h*
- `printf()` — Exibe informações no terminal.
- `scanf()` — Lê dados do usuário.
- `getchar()` — Lê um caractere do teclado.
- `fgets()` — Lê uma linha de texto.

*stdlib.h*
- `system()` — Executa comandos do sistema, como limpar o terminal.

*locale.h*
- `setlocale()` — Define a localização para suportar caracteres especiais.

*string.h*
- `strcpy()` — Copia strings.
- `strcspn()` — Localiza caracteres em strings.

### Funções Personalizadas 🔧 

- `carta()` — Cria e inicializa uma carta com os dados de uma cidade.
- `preencher_dados()` — Solicita e armazena os dados das cidades informados pelo usuário.
- `calculo()` — Realiza cálculos de indicadores relevantes para as cidades.
- `calc_super_poder()` — Calcula o valor do "super poder" de cada carta com base nos indicadores.
- `mostrar_carta()` — Exibe as informações de uma carta formatada no terminal.
- `comparar_cartas()` — Compara os indicadores das cartas para determinar a vencedora.
- `apresentar()` — Apresenta o resultado final e informações adicionais ao usuário.

### Definições de Cores 🎨

- `RED` — Exibe texto em vermelho para destacar informações importantes ou alertas.
- `BLUE` — Exibe texto em azul para títulos ou destaques.
- `GREEN` — Exibe texto em verde para indicar sucesso ou informações positivas.
- `PURPLE` — Exibe texto em roxo para elementos decorativos ou diferenciação.
- `RESET` — Restaura a cor padrão do terminal após o uso de cores.

## Estrutura do Código 💾

### Declaração das Variáveis 📦
```c
char estado[20], card_id[4], city[20], estado1[20], card_id1[4], city1[20];
strcpy(card_id, "A01");
strcpy(card_id1, "B01");
```

```c
int ponto_turistico, ponto_turistico1;
unsigned long int populacao, populacao1;
float area, pib, area1, pib1;
float DP, DP1, PC, PC1;
```

```c
int resultado;
float new_dp;
float super, super1;
```

#### Strings (char[]) 🧵

| Variável | Descrição                              |
|----------|----------------------------------------|
| estado   | Estado da primeira carta               |
| estado1  | Estado da segunda carta                |
| city     | Cidade da primeira carta               |
| city1    | Cidade da segunda carta                |
| card_id  | Código da primeira carta (ex: A01)     |
| card_id1 | Código da segunda carta (ex: B01)      |
*As variáveis `card_id` e `card_id1` recebem valores via `strcpy()`.*

#### Inteiros (int) 🧮

| Variável         | Descrição                                         |
|------------------|--------------------------------------------------|
| ponto_turistico  | Pontos turísticos da primeira cidade              |
| ponto_turistico1 | Pontos turísticos da segunda cidade               |

#### unsigned long int (Número inteiro maior e sem sinal) 〽️

| Variável   | Descrição                                 |
|------------|-------------------------------------------|
| populacao  | População da primeira cidade              |
| populacao1 | População da segunda cidade               |

#### float (Números decimais) 🔢

| Variável | Descrição                                         |
|----------|---------------------------------------------------|
| area     | Área da primeira cidade                           |
| area1    | Área da segunda cidade                            |
| pib      | PIB da primeira cidade                            |
| pib1     | PIB da segunda cidade                             |
| DP       | Densidade populacional da primeira cidade         |
| DP1      | Densidade populacional da segunda cidade          |
| PC       | PIB per capita da primeira cidade                 |
| PC1      | PIB per capita da segunda cidade                  |
| new_dp   | inverso da densidade populacional calculada             |
| super    | Super poder da primeira carta                     |
| super1   | Super poder da segunda carta                      |

#### Outros

| Variável  | Descrição                                         |
|-----------|---------------------------------------------------|
| resultado | Verificar se o número inserido é valido           |

---

## Passo a Passo do Programa 🚦

### o oque acontece antes da main 💡

#### importação de bibliotecas 🗂️
```c
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
```
- Essas bibliotecas são essenciais para o funcionamento do programa, pois fornecem funções para entrada/saída de dados, manipulação de strings, suporte a caracteres especiais e execução de comandos do sistema operacional. São frequentemente usadas em aplicações C para garantir robustez e portabilidade. 

#### Definicoes de cores 🖼️
```c
#define RED "\033[1;31m"
#define BLUE "\033[1;34m"
#define GREEN "\033[1;92m"
#define RESET "\033[0m"
#define PURPLE "\033[1;35m"
```
##### Cores para o Terminal 🖌️

As definições de cores utilizam códigos ANSI para modificar a cor do texto exibido no terminal. Isso permite destacar informações importantes, títulos ou resultados de forma visualmente agradável. Cada cor é definida por uma macro, facilitando seu uso ao longo do código:

- `RED` — Vermelho: usado para destaques importantes.
- `BLUE` — Azul: utilizado em seções.
- `GREEN` — Verde: usado na arte inicial e em linhas.
- `PURPLE` — Roxo: usado para elementos decorativos ou diferenciação.
- `RESET` — Restaura a cor padrão do terminal após o uso de cores.

Essas macros tornam o código mais legível e facilitam a manutenção do estilo visual do programa.

### Void 🌌
* Lembrando que o `*` é utilizado para indicar ponteiros em C, permitindo que as funções modifiquem diretamente o valor das variáveis passadas como argumento.

#### carta() - Arte ASCII da Carta 🃏

```ansi
X0NNNNNNNNNNNNNNNNNNNNNNX
NlNX.cMMMMMMMMMMMMMMMMMMW
KNKNOKMMMMMMMMMMMMMMMMMMW
NMMMMMXXXXXXXXXXXXXMMMMMW
NMMMMMOMMMMMMMMMMMOMMMMMW
NMMMMMOMMMMK'xMMMMOMMMMMW
NMMMMMOMMMl   ,NMMOMMMMMW
NMMMMMOMK.      OMOMMMMMW
NMMMMMON         MOMMMMMW
NMMMMMOMXk0: dOOWMOMMMMMW
NMMMMMOMMMMK0XMMMMOMMMMMW
NMMMMMOMMMMMMMMMMMOMMMMMW
NMMMMMXXXXXXXXXXXXXMMMMMW
NMMMMMMMMMMMMMMMMMMXkXNKX
NMMMMMMMMMMMMMMMMMMd.0McX
XNNNNNNNNNNNNNNNNNNNNNN0X
```

- As linhas da carta são exibidas em verde (`\033[1;92m`).
- O nome do jogo e a mensagem de boas-vindas aparecem em vermelho (`\033[1;31m`).

#### preencher_dados() - Colhe os dados para confeccionar as cartas 📋

```c
int resultado;
```
- esta variavel é usada para conferir se os dados inseridos sao validos

```c
 printf("Digite o nome do estado: ");
    fgets(estado, 20, stdin);
    estado[strcspn(estado, "\n")] = 0;

    printf("Digite o nome da cidade: ");
    fgets(city, 20, stdin);
    city[strcspn(city, "\n")] = 0;

    printf("Digite o ID do carta: ");
    fgets(card_id, 4, stdin);
    card_id[strcspn(card_id, "\n")] = 0;
```
- o usuario insere o nome do estado, cidade e ID da carta, podendo nomear com varios tipos de caracteres e espacos. A `fgets` recebe a linha inteira, com no maximo 20 caracteres, com entrada do teclado, `strcspn` remove o quebra linha armazenado no `fgets`, sendo subtituido pelo `\0` que finaliza a string. 

```c
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
```
- Todos os outros elementos da carta recebem o mesmo tratamento de dados. O bloco `do { ... } while (resultado != 1 || *area <= 0);` tem a função de executar o código pelo menos uma vez e continua repetindo até o usuário inserir um número válido. A linha `resultado = scanf("%f", area);` armazena o número inserido na variável `resultado` e no ponteiro `area`. O comando `while (getchar() != '\n')` limpa o buffer do teclado, evitando problemas de leitura e entradas incorretas que possam ficar presas. Caso o número inserido não atenda à condição de ser um número e maior que 0, uma mensagem de erro é exibida e o usuário deve inserir novamente um valor válido.

#### calculo() - Calcula a Densidade Populacional e PIB per Capita 📊
```c
DP = populacao / area;
PC = (pib * 1000000) / populacao;
- Realiza o cálculo com os dados coletados anteriormente: densidade populacional = divisão da população pela área; PIB per capita = PIB multiplicado por 1 milhão (pois os dados são fornecidos em milhões) e, em seguida, dividido pela população.
```
#### calc_super_poder() - Calcula o super poder da carta 📈

```c 
    float new_dp;
    new_dp = *area / *populacao;
    *super = *ponto_turistico + *populacao + *area + *pib + *PC + new_dp;
```
- A variável `new_dp` representa o inverso da densidade populacional. A variável `super` é a soma de todas as variáveis coletadas, substituindo apenas a variável `DP` por `new_dp`.

#### mostrar_carta() - Exibe a carta com todas os dados preenchidos e calculados 🂡
```c
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
```
- Exibe a carta para o usuário com todos os dados organizados, utilizando linhas coloridas em azul e destacando o super poder em vermelho.



#### comparar_cartas() - Compara as cartas com base na soma dos atributos ⚽

```c
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
```

- Com base na soma dos atributos das cartas, é decidido qual carta é mais forte.


#### apresentar() - Compara os atributos e exibe os resultados ⚖️
```c
 printf(GREEN "______________________\n\n" RESET);
    printf("Comparação dos atributos:\n\n");
    printf("Área: %s\n", (*area > *area1) ? "Carta 1 vence" : (*area < *area1) ? "Carta 2 vence"
                                                                               : "Empate");
    printf(GREEN "\n______________________\n" RESET);
```
- Todos os dados recebem o mesmo tratamento de validação e exibição, garantindo consistência na entrada e saída das informações. Para fins estéticos, são utilizadas linhas verdes para separar visualmente as seções durante a comparação dos atributos das cartas. O comando `printf("Área: %s\n", ...)` imprime qual carta possui o atributo mais forte, utilizando o operador ternário (`? :`) para realizar uma decisão simples: avalia se um valor é maior, menor ou igual ao outro e, conforme o resultado, exibe a mensagem correspondente ao usuário.

### Main - o começo do programa 🎯
```bash
    setlocale(LC_ALL, "Portuguese_Brazil");
```
- `setlocale` é usada para permitir a exibição de caracteres especiais que não existem em inglês, como acentos. Isso garante que os caracteres e a formatação do português sejam exibidos corretamente na aplicação com a `ISO 8859-1`.

*A declaração de variáveis citada anteriormente*

```bash
    carta();
    system("pause");
    system("cls");
```
- `carta()` exibe a apresentação inicial do programa.
- `system("pause")` faz o programa aguardar até que o usuário pressione uma tecla para continuar.
- `system("cls")` limpa o terminal antes de prosseguir para a próxima etapa do programa.

```bash
    preencher_dados(estado, city, card_id, &area, &pib, &populacao, &ponto_turistico);
    calculo(area, pib, populacao, &DP, &PC);
    calc_super_poder(&ponto_turistico, &populacao, &area, &pib, &DP, &PC, &super);
```
- Chama as três funções do tipo `void`, passando as variáveis da primeira carta. Assim, o usuário insere os dados da primeira carta e, em seguida, o programa realiza os cálculos necessários para exibi-los posteriormente.

```bash
     printf("\nA primeira carta foi criada com sucesso!\n\n");
    printf(BLUE "-----------------------------------------------------\n");
    printf(RESET);
    printf("Pressione Enter para visualizar a primeira carta\n");
    getchar();
    system("cls");
```
- Exibe ao usuário a mensagem de que a primeira carta foi criada. Em seguida, uma linha azul é impressa, solicitando que o usuário pressione Enter para visualizar a carta. Após pressionar, o terminal é limpo.

```bash
     mostrar_carta(estado, city, card_id, &area, &pib, &populacao, &ponto_turistico, &DP, &PC, &super);

    printf(RESET "pressione Enter para criar a segunda carta\n");
    getchar();
    system("cls");
```
- Exibe para o usuário a primeira carta. Logo abaixo, solicita que o usuário pressione Enter para confeccionar a segunda carta. Após pressionar Enter, o terminal é limpo.

*A segunda carta é criada de forma similar a primeira*

```bash
    printf(RESET "pressione Enter para comparar as cartas\n");
    getchar();
    system("cls");
``` 
- Solicita ao usuário pressionar Enter para iniciar a comparação das cartas. Após pressionar, o terminal é limpo.

```bash
    printf(BLUE "-----------------------------------------------------\n\n");
    printf(RESET "Comparando as cartas...\n\n");
    printf(BLUE "-----------------------------------------------------\n" RESET "");
    system("pause");
    system("cls");
    comparar_cartas(&super, &super1);
    apresentar(&area, &pib, &populacao, &ponto_turistico, &DP, &PC, &super,
               &area1, &pib1, &populacao1, &ponto_turistico1, &DP1, &PC1, &super1);
    printf("\n");
    printf(BLUE "-----------------------------------------------------\n");
    printf(RESET "\nPressione Enter para encerrar o jogo\n");
    system("pause");
    system("cls");
```
- Apresenta uma mensagem entre linhas azuis para o usuário que está comparando as cartas; para continuar, deve pressionar uma tecla e o terminal é limpo. Logo em seguida, é apresentado qual carta é mais forte e a comparação de atributos entre linhas azuis. Embaixo, há a mensagem de que, para encerrar o jogo, o usuário deve apertar alguma tecla, e depois o terminal é limpo.

```bash
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
```
- É exibida ao usuário uma mensagem em roxo agradecendo por jogar e perguntando se deseja jogar novamente. Se o usuário pressionar 's', o terminal é limpo e o jogo recomeça. Se pressionar 'n' ou qualquer outro caractere inválido, o jogo é encerrado com uma mensagem de finalização.

## Aluno

Miguel Lamazares
