//Implemente uma fila circular com tamanho fixo (Array Estático).

#include <stdio.h>
#include <locale.h>
#include <stdlib.h>

#define MAX 5  

typedef struct {
    int itens[MAX];
    int frente;
    int tras;
} FilaCircular;


void inicializaFila(FilaCircular *f) {
    f->frente = -1;
    f->tras = -1;
}


int filaVazia(FilaCircular *f) {
    return f->frente == -1;
}


int filaCheia(FilaCircular *f) {
    return (f->tras + 1) % MAX == f->frente;
}


void enfileirar(FilaCircular *f, int elemento) {
    if (filaCheia(f)) {
       
        f->frente = (f->frente + 1) % MAX;  
    }


    if (f->frente == -1) {
       
        f->frente = 0;
    }


    f->tras = (f->tras + 1) % MAX;
    f->itens[f->tras] = elemento;
    printf("Elemento %d enfileirado.\n", elemento);
}


int desenfileirar(FilaCircular *f) {
    if (filaVazia(f)) {
        printf("Fila vazia. Não é possível desenfileirar.\n");
        return -1;  
    }


    int elemento = f->itens[f->frente];
    if (f->frente == f->tras) {
        f->frente = f->tras = -1;
    } else {
        f->frente = (f->frente + 1) % MAX;
    }


    printf("Elemento %d desenfileirado.\n", elemento);
    return elemento;
}


void exibirFila(FilaCircular *f) {
    if (filaVazia(f)) {
        printf("Fila vazia.\n");
        return;
    }


    int i = f->frente;
    printf("Fila atual: [");


    while (i != f->tras) {
        printf("%d, ", f->itens[i]);
        i = (i + 1) % MAX;
    }
    printf("%d]\n", f->itens[f->tras]);  
}


int main() {
    setlocale(LC_ALL, "pt_BR.UTF-8");
    FilaCircular fila;
    inicializaFila(&fila);


    enfileirar(&fila, 10);  
    enfileirar(&fila, 20);  
    enfileirar(&fila, 30);  
    enfileirar(&fila, 40);
    enfileirar(&fila, 50);  
    exibirFila(&fila);      


    enfileirar(&fila, 60);  
    exibirFila(&fila);      


    desenfileirar(&fila);  
    exibirFila(&fila);      


    enfileirar(&fila, 70);  
    exibirFila(&fila);      


    return 0;
}
