#include <stdio.h>
#include <locale.h>
#include <stdlib.h>

typedef struct no {
    int data;
    struct no *prox;
} no;

typedef struct Pilha {
    no *topo;
} Pilha;

void inipilha(Pilha *pilha) {
    pilha->topo = NULL;
}

int isEmpty(Pilha *pilha) {
    return pilha->topo == NULL;
}

void push(Pilha *pilha, int data) {
    no *novono = (no*)malloc(sizeof(no));
    if (novono == NULL) {
        printf("Erro ao alocar memória.\n");
        return;
    }

    novono->data = data;
    novono->prox = pilha->topo;
    pilha->topo = novono;
}

int peek(Pilha *pilha) {
    if (isEmpty(pilha)) { 
        printf("Erro: Pilha vazia.\n");
        return -1;
    }
    return pilha->topo->data;
}

void display(Pilha *pilha) {
    if (isEmpty(pilha)) {
        printf("Pilha vazia.\n");
        return;
    }
    no *current = pilha->topo;
    printf("Pilha: ");
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->prox;
    }
    printf("NULL\n");
}

int main() {
    setlocale(LC_ALL, "portuguese");

    Pilha pilha;
    inipilha(&pilha);

    push(&pilha, 10);
    push(&pilha, 20);
    push(&pilha, 30);
    display(&pilha);

    printf("Elemento no topo: %d\n", peek(&pilha));
    display(&pilha);

    return 0;
}
