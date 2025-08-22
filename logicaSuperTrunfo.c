#include <stdio.h>

// Estrutura da carta
struct Carta {
    char nome[30];
    int populacao;
    float area;
    float pib;
    int pontosTuristicos;
    float densidade;
};

// Função para calcular a densidade demográfica
float calcularDensidade(int populacao, float area) {
    return populacao / area;
}

// Função para mostrar o menu de atributos
void mostrarMenu(int excluido) {
    if (excluido != 1) printf("1 - População\n");
    if (excluido != 2) printf("2 - Área\n");
    if (excluido != 3) printf("3 - PIB\n");
    if (excluido != 4) printf("4 - Pontos Turísticos\n");
    if (excluido != 5) printf("5 - Densidade Demográfica\n");
}

// Função para pegar o valor de um atributo
float pegarValor(struct Carta c, int atributo) {
    if (atributo == 1) return c.populacao;
    else if (atributo == 2) return c.area;
    else if (atributo == 3) return c.pib;
    else if (atributo == 4) return c.pontosTuristicos;
    else if (atributo == 5) return c.densidade;
    else return -1;
}

// Função para comparar dois valores
int comparar(float v1, float v2, int atributo) {
    if (atributo == 5) {
        if (v1 < v2) return 1;
        else if (v2 < v1) return 2;
        else return 0;
    } else {
        if (v1 > v2) return 1;
        else if (v2 > v1) return 2;
        else return 0;
    }
}

int main() {
    struct Carta carta1 = {"Brasil", 213000000, 8515767.0, 2200.0, 25, 0};
    struct Carta carta2 = {"Argentina", 45300000, 2780400.0, 500.0, 18, 0};

    carta1.densidade = calcularDensidade(carta1.populacao, carta1.area);
    carta2.densidade = calcularDensidade(carta2.populacao, carta2.area);

    int atributo1, atributo2;

    printf("Escolha o primeiro atributo para comparar:\n");
    mostrarMenu(0);
    scanf("%d", &atributo1);

    printf("Escolha o segundo atributo (diferente do primeiro):\n");
    mostrarMenu(atributo1);
    scanf("%d", &atributo2);

    if (atributo1 < 1 || atributo1 > 5 || atributo2 < 1 || atributo2 > 5 || atributo1 == atributo2) {
        printf("Erro: atributos inválidos.\n");
        return 1;
    }

    float valor1a = pegarValor(carta1, atributo1);
    float valor2a = pegarValor(carta2, atributo1);
    float valor1b = pegarValor(carta1, atributo2);
    float valor2b = pegarValor(carta2, atributo2);

    float soma1 = valor1a + valor1b;
    float soma2 = valor2a + valor2b;

    printf("\nComparando %s e %s\n", carta1.nome, carta2.nome);
    printf("Atributo %d: %.2f vs %.2f\n", atributo1, valor1a, valor2a);
    printf("Atributo %d: %.2f vs %.2f\n", atributo2, valor1b, valor2b);
    printf("Soma dos atributos:\n");
    printf("%s: %.2f\n", carta1.nome, soma1);
    printf("%s: %.2f\n", carta2.nome, soma2);

    if (soma1 > soma2)
        printf("Resultado: %s venceu!\n", carta1.nome);
    else if (soma2 > soma1)
        printf("Resultado: %s venceu!\n", carta2.nome);
    else
        printf("Resultado: Empate!\n");

    return 0;
}
