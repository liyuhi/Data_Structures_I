//Crie um programa que use uma pilha para inverter uma string. O usuário deve inserir uma palavra ou frase, e o programa deve exibir o texto invertido.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define max 100

typedef struct {
    char itens[max];
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

void empilha(Pilha *p, char item) {
    if (!pilhaCheia(p)) {
        p->itens[++(p->topo)] = item;
    }
}

char desempilha(Pilha *p) {
    if (!pilhaVazia(p)) {
        return p->itens[(p->topo)--];
    }
    return '\0'; 
}

int main() {
    Pilha pilha;
    inicializaPilha(&pilha);

    char str[max];
    printf("Digite uma palavra ou frase: ");
    fgets(str, max, stdin);
    
    str[strcspn(str, "\n")] = 0;

    for (int i = 0; i < strlen(str); i++) {
        empilha(&pilha, str[i]);
    }

    printf("Texto invertido: ");
    while (!pilhaVazia(&pilha)) {
        printf("%c", desempilha(&pilha));
    }
    printf("\n");

    return 0;
}