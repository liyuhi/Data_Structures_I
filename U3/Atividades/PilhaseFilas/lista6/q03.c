//Implemente um algoritmo que, utilizando as estruturas de pilha, converta expressões matemáticas na notação infixa (exemplo: 3 + 4 * 2) para a notação pós-fixa (exemplo: 3 4 2 * +).

#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX 100

int precedencia(char op) {
    if (op == '+' || op == '-') {
        return 1;
    }
    if (op == '*' || op == '/') {
        return 2;
    }
    return 0;
}


void infixaParaPosfixa(char* expressao) {
    char pilha[MAX];
    int topo = -1;
    int i = 0;


    while (expressao[i]) {
        char c = expressao[i];


        if (isdigit(c)) {
            printf("%c ", c);
        }
        else if (c == '(') {
            pilha[++topo] = c;
        }
        else if (c == ')') {
            while (topo >= 0 && pilha[topo] != '(') {
                printf("%c ", pilha[topo--]);
            }
            topo--;         }
        else if (c == '+' || c == '-' || c == '*' || c == '/') {
            while (topo >= 0 && precedencia(pilha[topo]) >= precedencia(c)) {
                printf("%c ", pilha[topo--]);
            }
            pilha[++topo] = c;
        }
        i++;
    }


    while (topo >= 0) {
        printf("%c ", pilha[topo--]);
    }
}


int main() {
    setlocale(LC_ALL, "pt_BR.UTF-8");
    char expressao[MAX];
   
    printf("Digite a expressão infixa: ");
    fgets(expressao, MAX, stdin);
   
    printf("Expressão pós-fixa: ");
    infixaParaPosfixa(expressao);
    printf("\n");


    return 0;
}

