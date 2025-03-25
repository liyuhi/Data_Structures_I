//Crie um programa que simule o atendimento de clientes em um banco. Utilize uma fila para armazenar os clientes que aguardam atendimento.

#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <string.h>

#define MAX 5  

typedef struct {
    char* clientes[MAX];
    int frente;
    int tras;
} Fila;


void inicializaFila(Fila* f) {
    f->frente = 0;
    f->tras = 0;
}


int filaVazia(Fila* f) {
    return f->frente == f->tras;
}


int filaCheia(Fila* f) {
    return f->tras == MAX;
}


void adicionarCliente(Fila* f, char* cliente) {
    if (filaCheia(f)) {
        printf("Fila cheia! Não é possível adicionar mais clientes.\n");
    } else {
        f->clientes[f->tras] = malloc(strlen(cliente) + 1);
        strcpy(f->clientes[f->tras], cliente);
        f->tras++;
        printf("Cliente %s adicionado à fila.\n", cliente);
    }
}


void atenderCliente(Fila* f) {
    if (filaVazia(f)) {
        printf("Não há clientes na fila para atender.\n");
    } else {
        printf("Atendendo %s\n", f->clientes[f->frente]);
        free(f->clientes[f->frente]);  // Liberando a memória alocada
        f->frente++;


        if (f->frente == f->tras) {
            inicializaFila(f);
        }
    }
}


void exibirFila(Fila* f) {
    if (filaVazia(f)) {
        printf("A fila está vazia.\n");
    } else {
        printf("Fila atual: [");
        for (int i = f->frente; i < f->tras; i++) {
            printf("'%s'", f->clientes[i]);
            if (i < f->tras - 1) {
                printf(", ");
            }
        }
        printf("]\n");
    }
}


int main() {
    setlocale(LC_ALL, "pt_BR.UTF-8");
    Fila fila;
    inicializaFila(&fila);
   
    int opcao;
    char nome[50];
   
    do {
        printf("\n=============== MENU ===============\n\n");
        printf("1. Adicionar cliente\n");
        printf("2. Atender cliente\n");
        printf("3. Exibir fila atual\n");
        printf("4. Sair\n");
        printf("\nEscolha uma opção: ");
        scanf("%d", &opcao);
        getchar();  


        switch (opcao) {
            case 1:
                printf("Digite o nome do cliente: ");
                fgets(nome, 50, stdin);
                nome[strcspn(nome, "\n")] = 0;  
                adicionarCliente(&fila, nome);
                break;
           
            case 2:
                atenderCliente(&fila);
                break;
           
            case 3:
                exibirFila(&fila);
                break;
           
            case 4:
                printf("Sistema finalizado.\n");
                break;
           
            default:
                printf("Opção inválida. Por favor, tente novamente.\n");
        }
    } while (opcao != 4);


    for (int i = fila.frente; i < fila.tras; i++) {
        free(fila.clientes[i]);
    }


    return 0;
}
