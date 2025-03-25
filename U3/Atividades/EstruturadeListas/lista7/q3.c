//Baseado na 1º questão, adapte o código para transformá-lo em uma Lista Circular.

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

typedef struct No {
    int valor;
    struct No *prox;
} No;

typedef struct {
    No *cabeca;
} encad;

void inicializar(encad *lista) {
    lista->cabeca = NULL;
}

void inicio(encad *lista, int valor) {
    No *novo = (No *)malloc(sizeof(No));
    if (!novo) return;
    novo->valor = valor;

    if (!lista->cabeca) {
        novo->prox = novo; // O novo nó aponta para ele mesmo
        lista->cabeca = novo;
    } else {
        No *aux = lista->cabeca;
        while (aux->prox != lista->cabeca) {
            aux = aux->prox;
        }
        novo->prox = lista->cabeca; // O novo nó aponta para o primeiro nó
        aux->prox = novo; // O último nó aponta para o novo nó
        lista->cabeca = novo; // Atualiza a cabeça para o novo nó
    }
}

void fim(encad *lista, int valor) {
    No *novo = (No *)malloc(sizeof(No));
    if (!novo) return;
    novo->valor = valor;

    if (!lista->cabeca) {
        novo->prox = novo; // O novo nó aponta para ele mesmo
        lista->cabeca = novo;
    } else {
        No *aux = lista->cabeca;
        while (aux->prox != lista->cabeca) {
            aux = aux->prox;
        }
        aux->prox = novo; // O último nó aponta para o novo nó
        novo->prox = lista->cabeca; // O novo nó aponta para a cabeça
    }
}

void remover(encad *lista, int valor) {
    if (!lista->cabeca) return; // Lista vazia

    No *atual = lista->cabeca, *anterior = NULL;

    do {
        if (atual->valor == valor) {
            if (anterior) {
                anterior->prox = atual->prox;
                if (atual == lista->cabeca) {
                    lista->cabeca = atual->prox; // Atualiza a cabeça se necessário
                }
            } else {
                // Removendo o nó cabeça
                No *aux = lista->cabeca;
                while (aux->prox != lista->cabeca) {
                    aux = aux->prox;
                }
                aux->prox = atual->prox; // O último nó aponta para o próximo do atual
                lista->cabeca = atual->prox; // Atualiza a cabeça
            }
            free(atual);
            return;
        }
        anterior = atual;
        atual = atual->prox;
    } while (atual != lista->cabeca);
}

int buscar(encad *lista, int valor) {
    if (!lista->cabeca) return 0; // Lista vazia

    No *atual = lista->cabeca;
    do {
        if (atual->valor == valor) return 1;
        atual = atual->prox;
    } while (atual != lista->cabeca);
    return 0;
}

void exibir(encad *lista) {
    if (!lista->cabeca) {
        printf("Lista vazia\n");
        return;
    }

    No *atual = lista->cabeca;
    do {
        printf("%d -> ", atual->valor);
        atual = atual->prox;
    } while (atual != lista->cabeca);
    printf("(cabeça: %d)\n", lista->cabeca->valor);
}

int main() {
    setlocale(LC_ALL, "Portuguese");
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
   
    return 0;
}