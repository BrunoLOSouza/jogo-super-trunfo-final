#include <stdio.h>
#include <string.h>

// -------------------------------
// Estrutura das Cartas
// -------------------------------
typedef struct {
    char nome[50];
    float populacao;
    float area;
    float pib;
    float densidade;
    float pibPerCapita;
    float superPoder;
} Carta;

// -------------------------------
// Função para remover o '\n' deixado pelo fgets
// -------------------------------
void limparEnter(char *str) {
    size_t len = strlen(str);
    if (len > 0 && str[len - 1] == '\n') {
        str[len - 1] = '\0';
    }
}

// -------------------------------
// Função para calcular atributos derivados
// -------------------------------
void calcularAtributos(Carta *c) {
    c->densidade = c->populacao / c->area;
    c->pibPerCapita = c->pib / c->populacao;
    c->superPoder = (c->pibPerCapita * 0.4) + (c->area * 0.3) - (c->densidade * 0.3);
}

// -------------------------------
// Função para limpar o buffer do teclado
// -------------------------------
void limparBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {}
}

// -------------------------------
// Função para cadastrar uma carta
// -------------------------------
void cadastrarCarta(Carta *c, int numero) {
    printf("\n=== Cadastro da Carta %d ===\n", numero);

    printf("Nome do país: ");
    fgets(c->nome, sizeof(c->nome), stdin);
    limparEnter(c->nome);

    printf("População (em milhões): ");
    scanf("%f", &c->populacao);

    printf("Área (em km²): ");
    scanf("%f", &c->area);

    printf("PIB (em bilhões): ");
    scanf("%f", &c->pib);

    limparBuffer(); // limpa o buffer antes da próxima leitura com fgets()

    calcularAtributos(c);
}

// -------------------------------
// Função para exibir uma carta
// -------------------------------
void exibirCarta(Carta c) {
    printf("\n--- Carta: %s ---\n", c.nome);
    printf("População: %.2f milhões\n", c.populacao);
    printf("Área: %.2f km²\n", c.area);
    printf("PIB: %.2f bilhões\n", c.pib);
    printf("Densidade demográfica: %.2f hab/km²\n", c.densidade);
    printf("PIB per capita: %.2f\n", c.pibPerCapita);
    printf("Super Poder: %.2f\n", c.superPoder);
}

// -------------------------------
// Função que retorna o valor de um atributo
// -------------------------------
float obterValor(Carta c, int atributo) {
    switch (atributo) {
        case 1: return c.populacao;
        case 2: return c.area;
        case 3: return c.pib;
        case 4: return c.pibPerCapita;
        case 5: return c.densidade;
        case 6: return c.superPoder;
        default: return 0;
    }
}

// -------------------------------
// Função para obter o nome textual de um atributo
// -------------------------------
const char* nomeAtributo(int atributo) {
    switch (atributo) {
        case 1: return "População";
        case 2: return "Área";
        case 3: return "PIB";
        case 4: return "PIB per capita";
        case 5: return "Densidade demográfica";
        case 6: return "Super Poder";
        default: return "Desconhecido";
    }
}

// -------------------------------
// Função principal
// -------------------------------
int main() {
    Carta carta1, carta2;

    printf("=== SUPER TRUNFO - DESAFIO FINAL ===\n");

    cadastrarCarta(&carta1, 1);
    cadastrarCarta(&carta2, 2);

    exibirCarta(carta1);
    exibirCarta(carta2);

    int atributo1, atributo2;

    // Escolha do primeiro atributo
    printf("\nEscolha o primeiro atributo para comparar:\n");
    printf("1 - População\n2 - Área\n3 - PIB\n4 - PIB per capita\n5 - Densidade demográfica\n6 - Super Poder\n");
    printf("Opção: ");
    scanf("%d", &atributo1);

    // Menu dinâmico para o segundo atributo
    printf("\nEscolha o segundo atributo (diferente do primeiro):\n");
    for (int i = 1; i <= 6; i++) {
        if (i != atributo1) {
            printf("%d - %s\n", i, nomeAtributo(i));
        }
    }
    printf("Opção: ");
    scanf("%d", &atributo2);

    if (atributo1 == atributo2) {
        printf("\nErro: os atributos devem ser diferentes!\n");
        return 1;
    }

    // Comparação
    float valor1A = obterValor(carta1, atributo1);
    float valor2A = obterValor(carta2, atributo1);
    float valor1B = obterValor(carta1, atributo2);
    float valor2B = obterValor(carta2, atributo2);

    int vencedorA1 = (atributo1 == 5)
                     ? (valor1A < valor2A ? 1 : 2)
                     : (valor1A > valor2A ? 1 : 2);

    int vencedorA2 = (atributo2 == 5)
                     ? (valor1B < valor2B ? 1 : 2)
                     : (valor1B > valor2B ? 1 : 2);

    float soma1 = valor1A + valor1B;
    float soma2 = valor2A + valor2B;

    // Exibição dos resultados
    printf("\n===== RESULTADO DA COMPARAÇÃO =====\n");
    printf("Carta 1: %s\n", carta1.nome);
    printf("Carta 2: %s\n\n", carta2.nome);

    printf("%s:\n", nomeAtributo(atributo1));
    printf("  %s: %.2f\n", carta1.nome, valor1A);
    printf("  %s: %.2f\n", carta2.nome, valor2A);
    printf("  Vencedor: %s\n\n", vencedorA1 == 1 ? carta1.nome : carta2.nome);

    printf("%s:\n", nomeAtributo(atributo2));
    printf("  %s: %.2f\n", carta1.nome, valor1B);
    printf("  %s: %.2f\n", carta2.nome, valor2B);
    printf("  Vencedor: %s\n\n", vencedorA2 == 1 ? carta1.nome : carta2.nome);

    printf("Soma dos atributos:\n");
    printf("  %s: %.2f\n", carta1.nome, soma1);
    printf("  %s: %.2f\n", carta2.nome, soma2);

    if (soma1 == soma2)
        printf("\nResultado final: Empate!\n");
    else
        printf("\nVencedor final: %s 🏆\n", (soma1 > soma2) ? carta1.nome : carta2.nome);

    printf("===================================\n");

    return 0;
}
