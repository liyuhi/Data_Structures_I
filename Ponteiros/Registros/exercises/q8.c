#include <stdio.h>

//definindo o registro Tigela
struct Tigela {
    char estado[10];  //pode ser "cheia" ou "vazia"
    char tipo[10];    //pode ser "sopa" ou "canja"
};

//função que altera o estado da tigela para "vazia"
void Fome(struct Tigela *t) {
    snprintf(t->estado, sizeof(t->estado), "vazia");
}

int main() {
    struct Tigela aTigela = {"cheia", "sopa"};
    struct Tigela *pTigela = &aTigela;
    printf("Antes da janta: Tigela %s, Tipo: %s\n", pTigela->estado, pTigela->tipo);
    Fome(pTigela);
    printf("Depois da janta: Tigela %s, Tipo: %s\n", pTigela->estado, pTigela->tipo);

    return (0);
}
