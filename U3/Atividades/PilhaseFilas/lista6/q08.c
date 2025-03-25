// Implemente um escalonador de processos baseado no algoritmo Round-Robin utilizando filas.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define max_processos 10

typedef struct {
    char nome[20];
    int tempo_restante;
} Processo;

typedef struct {
    Processo processos[max_processos];
    int frente;
    int tras;
} Fila;

void inicializaFila(Fila *f) {
    f->frente = 0;
    f->tras = 0;
}

int filaVazia(Fila *f) {
    return f->frente == f->tras;
}

int filaCheia(Fila *f) {
    return (f->tras + 1) % max_processos == f->frente;
}

void insereFila(Fila *f, Processo p) {
    if (!filaCheia(f)) {
        f->processos[f->tras] = p;
        f->tras = (f->tras + 1) % max_processos;
    } else {
        printf("Fila está cheia!\n");
    }
}

Processo removeFila(Fila *f) {
    if (!filaVazia(f)) {
        Processo p = f->processos[f->frente];
        f->frente = (f->frente + 1) % max_processos;
        return p;
    } else {
        printf("Fila está vazia!\n");
        Processo vazio = {"", 0};
        return vazio;
    }
}

void roundRobin(Fila *f, int quantum) {
    while (!filaVazia(f)) {
        Processo atual = removeFila(f);
        int tempo_para_executar = (atual.tempo_restante > quantum) ? quantum : atual.tempo_restante;

        printf("Executando %s por %ds", atual.nome, tempo_para_executar);
        atual.tempo_restante -= tempo_para_executar;

        if (atual.tempo_restante > 0) {
            printf("\n");
            insereFila(f, atual);
        } else {
            printf(" (finalizado)\n");
        }
    }
}

int main() {
    Fila f;
    inicializaFila(&f);

    Processo p1 = {"Processo A", 8};
    Processo p2 = {"Processo B", 4};
    Processo p3 = {"Processo C", 6};

    insereFila(&f, p1);
    insereFila(&f, p2);
    insereFila(&f, p3);

    int quantum = 3;

    roundRobin(&f, quantum);

    return 0;
}