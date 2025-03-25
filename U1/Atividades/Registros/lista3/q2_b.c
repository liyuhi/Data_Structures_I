//Como alocar dinamicamente um registro de tipo peixe.

#include<stdio.h>
#include<stdlib.h>
#include<locale.h>

struct peixe {
    char tipo[20];
    float peso;
    int comprimento;
};

int main() {
    setlocale(LC_ALL, "portuguese");

    struct peixe *ptrpeixe = (struct peixe *)malloc(sizeof(struct peixe));

    if (ptrpeixe == NULL) {
        printf("Erro ao alocar memória.\n");
        return 1;
    }

    printf("---- Informações do peixe ----\n");
    printf("Digite o tipo do peixe: ");
    scanf("%s", ptrpeixe->tipo);
    printf("Digite o peso do peixe (em kg): ");
    scanf("%f", &ptrpeixe->peso);
    printf("Digite o comprimento do peixe (em cm): ");
    scanf("%d", &ptrpeixe->comprimento);

    printf("Tipo: %s\n", ptrpeixe->tipo);
    printf("Peso: %.1f kg\n", ptrpeixe->peso);
    printf("Comprimento: %d cm\n", ptrpeixe->comprimento);

    free(ptrpeixe);

    return 0;
}
