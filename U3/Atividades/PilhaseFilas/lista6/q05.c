//Crie um programa que simule um sistema de desfazer e refazer utilizando duas pilhas.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define max 100

typedef struct {
    char itens[max][max];
    int topo;
} Pilha;

void inicializaPilha(Pilha *p) {
    p->topo = -1;
}

int pilhaVazia(Pilha *p) {
    return p->topo == -1;
}

int pilhaCheia(Pilha *p) {
    return p->topo == max - 1;
}

void empilha(Pilha *p, const char *item) {
    if (!pilhaCheia(p)) {
        strcpy(p->itens[++(p->topo)], item);
    }
}

int desempilha(Pilha *p, char *saida) {
    if (!pilhaVazia(p)) {
        strcpy(saida, p->itens[p->topo--]);
        return 1;
    }
    return 0;
}

int main() {
    Pilha pilhaAcoes, pilhaDesfazer;
    inicializaPilha(&pilhaAcoes);
    inicializaPilha(&pilhaDesfazer);

    char comando[max];
    char buffer[max];

    while (1) {
        printf("Digite um comando (ou 'sair' para encerrar): ");
        fgets(comando, max, stdin);
        comando[strcspn(comando, "\n")] = 0;  

        if (strcmp(comando, "sair") == 0) {
            break;
        } else if (strcmp(comando, "desfazer") == 0) {
            if (desempilha(&pilhaAcoes, buffer)) {
                empilha(&pilhaDesfazer, buffer);
                printf("Ação desfeita: \"%s\"\n", buffer);
            } else {
                printf("Nenhuma ação para desfazer.\n");
            }
        } else if (strcmp(comando, "refazer") == 0) {
            if (desempilha(&pilhaDesfazer, buffer)) {
                empilha(&pilhaAcoes, buffer);
                printf("Ação refeita: \"%s\"\n", buffer);
            } else {
                printf("Nenhuma ação para refazer.\n");
            }
        } else {
            empilha(&pilhaAcoes, comando);
            printf("Ação realizada: \"%s\"\n", comando);
        }
    }

    return 0;
}
