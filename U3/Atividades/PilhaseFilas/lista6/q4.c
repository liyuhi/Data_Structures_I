//Com base no programa anterior, implemente um programa que solucione, por meio de estrutura de pilha, expressões fornecidas em notação pós-fixa.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <locale.h>


#define MAX 10


int main(){
    setlocale(LC_ALL, "Portuguese");
    char exp[] = "3 4 + 2 *";
    int pilha[MAX], topo = -1;
    int a = 0;
    int b = 0;


    char *token = strtok(exp, " ");
   
    while (token != NULL) {
        if (isdigit(token[0])) {
            pilha[++topo] = atoi(token);
        } else {
            b = pilha[topo--];
            a = pilha[topo--];  
            if (token[0] == '+') {
                pilha[++topo] = a + b;
            } else if (token[0] == '-') {
                pilha[++topo] = a - b;
            } else if (token[0] == '*') {
                pilha[++topo] = a * b;
            } else if (token[0] == '/') {
                pilha[++topo] = a / b;
            }
        }
        token = strtok(NULL, " ");
    }
    printf("Resultado: %d\n", pilha[topo]);
    return 0;
}
