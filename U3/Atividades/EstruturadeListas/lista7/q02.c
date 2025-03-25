//Baseado na questão anterior, implemente uma lista duplamente encadeada com as mesma funções da questão anterior.

#include <stdio.h>
#include <locale.h>
#include <stdlib.h>

typedef struct No {
    int valor;
    struct No *prox;
    struct No *ant;
} No;

typedef struct {
    No *cabeca;
    No *cauda;
} encad;

void inicializar(encad *lista) {
    lista->cabeca = NULL;
    lista->cauda = NULL;
}

void inicio(encad *lista, int valor) {
    No *novo = (No *)malloc(sizeof(No));
    if (!novo) return;
    novo->valor = valor;
    novo->prox = lista->cabeca;
    novo->ant = NULL;
   
    if (lista->cabeca != NULL) {
        lista->cabeca->ant = novo;
    }
    lista->cabeca = novo;

    if (lista->cauda == NULL) {
        lista->cauda = novo;
    }
}

void fim(encad *lista, int valor) {
    No *novo = (No *)malloc(sizeof(No));
    if (!novo) return;
    novo->valor = valor;
    novo->prox = NULL;
    novo->ant = lista->cauda;

    if (lista->cauda != NULL) {
        lista->cauda->prox = novo;
    }
    lista->cauda = novo;

    if (lista->cabeca == NULL) {
        lista->cabeca = novo;
    }
}

void remover(encad *lista, int valor) {
    No *atual = lista->cabeca;

    while (atual != NULL && atual->valor != valor) {
        atual = atual->prox;
    }

    if (atual == NULL) return;  

    if (atual == lista->cabeca) {
        lista->cabeca = atual->prox;
        if (lista->cabeca != NULL) {
            lista->cabeca->ant = NULL;
        }
    }
    else if (atual == lista->cauda) {
        lista->cauda = atual->ant;
        if (lista->cauda != NULL) {
            lista->cauda->prox = NULL;
        }
    }
    else {
        atual->ant->prox = atual->prox;
        if (atual->prox != NULL) {
            atual->prox->ant = atual->ant;
        }
    }

    free(atual);
}

int buscar(encad *lista, int valor) {
    No *atual = lista->cabeca;
    while (atual) {
        if (atual->valor == valor) return 1;
        atual = atual->prox;
    }
    return 0;
}

void exibir(encad *lista) {
    No *atual = lista->cabeca;
    while (atual) {
        printf("%d <-> ", atual->valor);
        atual = atual->prox;
    }
    printf("NULL\n");
}

void exibirReverso(encad *lista) {
    No *atual = lista->cauda;
    while (atual) {
        printf("%d <-> ", atual->valor);
        atual = atual->ant;
    }
    printf("NULL\n");
}

int main() {
    setlocale(LC_ALL, "pt_BR.UTF-8");
    encad lista;
    inicializar(&lista);
    inicio(&lista, 10);  
    inicio(&lista, 20);
    fim(&lista, 30);    
    fim(&lista, 40);    
    remover(&lista, 20);
    exibir(&lista);      

    printf("Buscar 30: %s\n", buscar(&lista, 30) ? "Encontrado" : "Não encontrado");
    printf("Buscar 50: %s\n", buscar(&lista, 50) ? "Encontrado" : "Não encontrado");

    printf("Exibindo lista reversa: \n");
    exibirReverso(&lista);  

    return 0;
}
