//Escreva um programa que utilize uma pilha para verificar se uma sequência de parênteses está corretamente balanceada. Seu código deve considerar os símbolos: {}, (), [].

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>


#define max 10


void verifica(const char *str){
    char pilha[max];
    int topo = 0;
    int tam = strlen(str);
    char c;
    for(int x = 0; x < tam; x++){
        c = str[x];
        if(c == '(' || c == '{' || c == '['){
            pilha[topo] = c;
            topo++;
        }else{
            if(topo == 0){
                printf("Entrada não balanceada.\n");
                return;
            }
            topo--;
            char fim = pilha[topo];
            if ((c == ')' && fim != '(') || (c == ']' && fim != '[') || (c == '}' && fim != '{')) {
                printf("Entrada não balanceada.\n");
                return;
            }
        }
    }
    printf("Entrada balanceada");
}
int main(){
    setlocale(LC_ALL, "Portuguese");
    char ent[10];
    printf("Digite a ent: ");
    fgets(ent, max, stdin);
    ent[strcspn(ent, "\n")] = 0;
    verifica(ent);
    return 0;
}
