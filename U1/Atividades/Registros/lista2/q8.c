/*Declare um registro "Tigela" com os campos estado (cheia ou vazia) e tipo de alimento (sopa ou canja). Crie uma função "Fome" que recebe um ponteiro para uma Tigela e altera o seu estado para "vazia". Na função principal crie uma tigela cheia, crie um ponteiro que aponta para essa tigela e então mostre como a tigela estava antes da janta.
Depois chame a função Fome com o ponteiro que aponta para a tigela e ao fim mostre a tigela depois da janta.*/

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
