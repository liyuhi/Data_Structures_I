/*Implemente uma Lista Encadeada Simples, contendo os seguintes métodos:

● inserir_no_inicio(valor): Adiciona um nó no início da lista.
● inserir_no_fim(valor): Adiciona um nó no final da lista.
● remover(valor): Remove um nó específico.
● buscar(valor): Retorna se o elemento está presente na lista.
● exibir(): Exibe todos os elementos da lista.*/

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
    novo->prox = lista->cabeca;
    lista->cabeca = novo;
}
void fim(encad *lista, int valor) {
    No *novo = (No *)malloc(sizeof(No));
    if (!novo) return;
    novo->valor = valor;
    novo->prox = NULL;
    if (!lista->cabeca) {
        lista->cabeca = novo;
    } else {
        No *aux = lista->cabeca;
        while (aux->prox)
            aux = aux->prox;
        aux->prox = novo;
    }
}
void remover(encad *lista, int valor) {
    No *atual = lista->cabeca, *anterior = NULL;
    while (atual && atual->valor != valor) {
        anterior = atual;
        atual = atual->prox;
    }
    if (!atual) return;
    if (!anterior)
        lista->cabeca = atual->prox;
    else
        anterior->prox = atual->prox;
    free(atual);
}
int buscar(encad *lista, int valor) {
    No *atual = lista->cabeca;
    while(atual){
        if (atual->valor == valor) return 1;
        atual = atual->prox;
    }
    return 0;
}
void exibir(encad *lista) {
    No *atual = lista->cabeca;
    while (atual) {
        printf("%d -> ", atual->valor);
        atual = atual->prox;
    }
    printf("NULL\n");
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
